#include <windows.h>
#include <cstdio>

#include "resource.h"

#include <CommCtrl.h>
#pragma command(lib, "commctl32")

// Global variables

// button
HWND hBtnStart, hBtnStop, hBtnReset;

// static
HWND hStaticPercent;

// progress bar
HWND hProgressBar;

BOOL CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInst,
	LPSTR lpszCmdLine,
	int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	const int BUF_SIZE = 1024;
	TCHAR buf[BUF_SIZE]{ 0 };

	switch (message)
	{
	case WM_INITDIALOG:
		// handles
		hBtnStart = GetDlgItem(hDlg, IDC_BTN_START);
		hBtnStop = GetDlgItem(hDlg, IDC_BTN_STOP);
		hBtnReset = GetDlgItem(hDlg, IDC_BTN_RESET);
		hStaticPercent = GetDlgItem(hDlg, IDC_STATIC_PERCENT);
		hProgressBar = GetDlgItem(hDlg, IDC_PROGRESS);

		// enable window
		EnableWindow(hBtnStop, FALSE);
		EnableWindow(hBtnReset, FALSE);

		// set color to progress bar
		SendMessage(hProgressBar, PBM_SETBKCOLOR, 0, (LPARAM)RGB(60, 27, 226));
		SendMessage(hProgressBar, PBM_SETBARCOLOR, 0, (LPARAM)RGB(255, 221, 0));
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_BTN_START:
			EnableWindow(hBtnStop, TRUE);
			EnableWindow(hBtnReset, FALSE);
			break;
		case IDC_BTN_STOP:
			EnableWindow(hBtnReset, TRUE);
			break;
		case IDC_BTN_RESET:
			EnableWindow(hBtnReset, FALSE);
			EnableWindow(hBtnStop, FALSE);
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
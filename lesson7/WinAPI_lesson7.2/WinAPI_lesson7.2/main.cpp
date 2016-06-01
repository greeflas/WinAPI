#include <windows.h>
#include <cstdio>

#include "resource.h"

#include <CommCtrl.h>
#pragma command(lib, "commctl32")

// Global variables

// slider
HWND hSliderR, hSliderG, hSliderB;

// progress bar
HWND hProgressBar;

// edit
HWND hEditRGB;

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

	static int r(0);
	static int g(0);
	static int b(0);

	switch (message)
	{
	case WM_INITDIALOG:
		// handlers
		hSliderR = GetDlgItem(hDlg, IDC_SLIDER_R);
		hSliderG = GetDlgItem(hDlg, IDC_SLIDER_G);
		hSliderB = GetDlgItem(hDlg, IDC_SLIDER_B);
		hProgressBar = GetDlgItem(hDlg, IDC_PROGRESS);
		hEditRGB = GetDlgItem(hDlg, IDC_EDIT_RGB);

		// set range
		SendMessage(hSliderR, TBM_SETRANGE, TRUE, MAKELPARAM(0, 255));
		SendMessage(hSliderG, TBM_SETRANGE, TRUE, MAKELPARAM(0, 255));
		SendMessage(hSliderB, TBM_SETRANGE, TRUE, MAKELPARAM(0, 255));

		// set default pos
		SendMessage(hSliderR, TBM_SETPOS, TRUE, 150);
		SendMessage(hSliderG, TBM_SETPOS, TRUE, 150);
		SendMessage(hSliderB, TBM_SETPOS, TRUE, 150);

		// set step
		SendMessage(hSliderR, TBM_SETTICFREQ, 10, 0);
		SendMessage(hSliderG, TBM_SETTICFREQ, 10, 0);
		SendMessage(hSliderB, TBM_SETTICFREQ, 10, 0);
		break;
	case WM_HSCROLL:
		r = SendMessage(hSliderR, TBM_GETPOS, 0, 0);
		g = SendMessage(hSliderG, TBM_GETPOS, 0, 0);
		b = SendMessage(hSliderB, TBM_GETPOS, 0, 0);

		swprintf_s(buf, L"%d, %d, %d", r, g, b);
		SetWindowText(hEditRGB, buf);

		SendMessage(hProgressBar, PBM_SETBKCOLOR, 0,  (LPARAM)RGB(r, g, b));
		break;
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
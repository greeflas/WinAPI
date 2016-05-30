#include <windows.h>
#include <cstdio>

#include "resource.h"

// Global variables

// image
const int IMG_NUM = 6;
HBITMAP hBmp[IMG_NUM];

// list
HWND hList;

// static
HWND hStaticBmp;

// button
HWND hBtnStart, hBtnStop, hBtnPrev, hBtnNext;

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
	switch (message)
	{
	case WM_INITDIALOG:
		hList = GetDlgItem(hDlg, IDC_LIST_IMAGES);
		hStaticBmp = GetDlgItem(hDlg, IDC_IMAGE);
		hBtnStart = GetDlgItem(hDlg, IDC_BTN_START);
		hBtnStop = GetDlgItem(hDlg, IDC_BTN_STOP);
		hBtnPrev = GetDlgItem(hDlg, IDC_BTN_PREV);
		hBtnNext = GetDlgItem(hDlg, IDC_BTN_NEXT);

		for (size_t i = 0; i < IMG_NUM; ++i)
		{
			hBmp[i] = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP1 + i));
		}

		SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)L"1.jpg");
		SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)L"2.jpg");
		SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)L"3.jpg");
		SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)L"4.jpg");
		SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)L"5.jpg");
		SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)L"6.jpg");
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		}
		break;
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
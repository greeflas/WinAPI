#include <windows.h>
#include <cstdio>

#include "resource.h"

// Global variables
HWND hEditAdd, hEditResult;
HWND hList;
HWND hBtnAdd, hBtnDelete, hBtnClear, hBtnCalc;

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
	TCHAR buf[BUF_SIZE];

	int index(-1);

	switch (message)
	{
	case WM_INITDIALOG:
		hEditAdd = GetDlgItem(hDlg, IDC_EDIT_ADD);
		hEditResult = GetDlgItem(hDlg, IDC_EDIT_RESULT);
		hList = GetDlgItem(hDlg, IDC_LIST);
		hBtnAdd = GetDlgItem(hDlg, IDC_BTN_ADD);
		hBtnDelete = GetDlgItem(hDlg, IDC_BTN_DELETE);
		hBtnClear = GetDlgItem(hDlg, IDC_BTN_CLEAR);
		hBtnCalc = GetDlgItem(hDlg, IDC_BTN_CALC);
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_BTN_ADD:
			GetWindowText(hEditAdd, buf, BUF_SIZE);
			if (lstrlen(buf) != 0)
				SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)buf);
			else
				MessageBox(hDlg, L"Field cannot be blank!", L"Error", MB_OK | MB_ICONERROR);
			break;
		case IDC_BTN_DELETE:
			index = SendMessage(hList, LB_GETCURSEL, 0, 0);
			if (index != -1)
				SendMessage(hList, LB_DELETESTRING, index, 0);
			else
				MessageBox(hDlg, L"List item not selected!", L"Error", MB_OK | MB_ICONERROR);
			break;
		case IDC_BTN_CLEAR:
			break;
		case IDC_BTN_CALC:
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
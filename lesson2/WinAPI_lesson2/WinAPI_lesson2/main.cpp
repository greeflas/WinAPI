#include <windows.h>
#include <cstdio>

#include "resource.h"

// Global variables
HWND hStartBtn, hStopBtn;

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
	static int x = 0;

	switch (message)
	{
	case WM_INITDIALOG:
		//SetTimer(hDlg, 1, 2000, NULL); // Example 1
		hStartBtn = GetDlgItem(hDlg, IDC_BUTTON1);
		hStopBtn = GetDlgItem(hDlg, IDC_BUTTON2);
		break;
	case WM_TIMER:
		//MessageBox(hDlg, L"ku-ku", L"Information", MB_OK | MB_ICONINFORMATION); // Example 1
		MoveWindow(hDlg, 0 + x, 100, 250, 130, TRUE);
		x += 10;
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_BUTTON1:
			SetTimer(hDlg, 1, 20, NULL);
			break;
		case IDC_BUTTON2:
			KillTimer(hDlg, 1);
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
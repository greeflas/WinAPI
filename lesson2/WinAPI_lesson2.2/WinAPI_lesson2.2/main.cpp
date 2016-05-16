#include <windows.h>
#include <cstdio>

#include "resource.h"

// Global variables
HWND hMinEdit, hSecEdit, hHundEdit;
HWND hStartBtn, hStopBtn, hResetBtn;

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
	static int m(0);
	static int s(0);
	static int h(0);

	switch (message)
	{
	case WM_INITDIALOG:
		// Get descriptors
		hMinEdit = GetDlgItem(hDlg, IDC_EDIT1);
		hSecEdit = GetDlgItem(hDlg, IDC_EDIT2);
		hHundEdit = GetDlgItem(hDlg, IDC_EDIT3);
		hStartBtn = GetDlgItem(hDlg, IDC_BUTTON1);
		hStopBtn = GetDlgItem(hDlg, IDC_BUTTON2);
		hResetBtn = GetDlgItem(hDlg, IDC_BUTTON3);

		// Disable edit and buttons
		EnableWindow(hMinEdit, FALSE);
		EnableWindow(hSecEdit, FALSE);
		EnableWindow(hHundEdit, FALSE);
		EnableWindow(hStopBtn, FALSE);
		EnableWindow(hResetBtn, FALSE);
		break;
	case WM_TIMER:
		if (h < 100)
			++h;
		else
		{
			h = 0;
			if (s < 59)
				++s;
			else
			{
				s = 0;
				++m;
			}
		}

		TCHAR buf1[4], buf2[4], buf3[4];

		if (m < 10)
			swprintf_s(buf1, L"0%d", m);
		else
			swprintf_s(buf1, L"%d", m);

		if (s < 10)
			swprintf_s(buf2, L"0%d", s);
		else
			swprintf_s(buf2, L"%d", s);

		if (h < 10)
			swprintf_s(buf3, L"0%d", h);
		else
			swprintf_s(buf3, L"%d", h);

		SetWindowText(hMinEdit, buf1);
		SetWindowText(hSecEdit, buf2);
		SetWindowText(hHundEdit, buf3);
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_BUTTON1:
			EnableWindow(hStartBtn, FALSE);
			EnableWindow(hStopBtn, TRUE);
			EnableWindow(hResetBtn, FALSE);

			SetTimer(hDlg, 1, 10, NULL);
			break;
		case IDC_BUTTON2:
			EnableWindow(hStartBtn, TRUE);
			EnableWindow(hStopBtn, FALSE);
			EnableWindow(hResetBtn, TRUE);

			KillTimer(hDlg, 1);
			break;
		case IDC_BUTTON3:
			EnableWindow(hResetBtn, FALSE);

			m = s = h = 0;

			TCHAR buf1[4], buf2[4], buf3[4];

			swprintf_s(buf1, L"%d", m);
			swprintf_s(buf2, L"%d", s);
			swprintf_s(buf3, L"%d", h);

			SetWindowText(hMinEdit, buf1);
			SetWindowText(hSecEdit, buf2);
			SetWindowText(hHundEdit, buf3);
			break;
		}
		break;
	case WM_CLOSE:
			EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
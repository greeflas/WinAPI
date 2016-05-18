#include <windows.h>
#include <cstdio>

#include "resource.h"

// Global variables
HWND hEditSum, hEditResult;
HWND hRadioUSD, hRadioEUR, hRadioRUB, hRadioBuy, hRadioSale;
HWND hCheckPrint, hCheckSave;
HWND hBtnCalc, hBtnReset;

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
	TCHAR buf[512] {0};
	int flag(0);

	switch (message)
	{
	case WM_INITDIALOG:
		// Handlers
		hEditSum = GetDlgItem(hDlg, IDC_EDIT1);
		hEditResult = GetDlgItem(hDlg, IDC_EDIT2);
		hRadioUSD = GetDlgItem(hDlg, IDC_RADIO1);
		hRadioEUR = GetDlgItem(hDlg, IDC_RADIO2);
		hRadioRUB = GetDlgItem(hDlg, IDC_RADIO3);
		hRadioBuy = GetDlgItem(hDlg, IDC_RADIO4);
		hRadioSale = GetDlgItem(hDlg, IDC_RADIO5);
		hCheckPrint = GetDlgItem(hDlg, IDC_CHECK1);
		hCheckSave = GetDlgItem(hDlg, IDC_CHECK2);
		hBtnCalc = GetDlgItem(hDlg, IDC_BUTTON1);
		hBtnReset = GetDlgItem(hDlg, IDC_BUTTON2);

		// Disable windows
		EnableWindow(hEditResult, FALSE);
		EnableWindow(hBtnReset, FALSE);

		// Set default values
		SendMessage(hRadioUSD, BM_SETCHECK, (WPARAM)BST_CHECKED, 0);
		SendMessage(hRadioBuy, BM_SETCHECK, (WPARAM)BST_CHECKED, 0);
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_BUTTON1: // calculate button
			EnableWindow(hBtnReset, TRUE);

			flag = SendMessage(hRadioUSD, BM_GETCHECK, 0, 0);
			if (flag == BST_CHECKED)
			{
				lstrcpy(buf, L"USD"); // strcpy() for unicode
			}
			MessageBox(hDlg, buf, L"Flag", MB_OK);
			break;
		case IDC_BUTTON2: // reset button
			EnableWindow(hBtnReset, FALSE);
			break;
		}
		break;
	case WM_CLOSE:
			EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
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
	switch (message)
	{
	case WM_INITDIALOG:
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

		EnableWindow(hEditResult, FALSE);
		break;
	case WM_CLOSE:
			EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
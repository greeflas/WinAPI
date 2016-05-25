#include "headers.h"
#include "resource.h"

// Global variables

// combo box
HWND hComboCat;
// edit
HWND hEditSum;
// list
HWND hListGoods, hListBasket;
// button
HWND hBtnAdd, hBtnDel, hBtnClear;

// categories
const TCHAR CAT1[] = L"Ноутбуки";
const TCHAR CAT2[] = L"Игровые компьютеры";
const TCHAR CAT3[] = L"Компьютеры для работы и учёбы";

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
	TCHAR buf[BUF_SIZE] { 0 };

	switch (message)
	{
	case WM_INITDIALOG:
		// handlers
		hComboCat = GetDlgItem(hDlg, IDC_COMBO_CAT);
		hEditSum = GetDlgItem(hDlg, IDC_EDIT_SUM);
		hListGoods = GetDlgItem(hDlg, IDC_LIST_GOODS);
		hListBasket = GetDlgItem(hDlg, IDC_LIST_BASKET);
		hBtnAdd = GetDlgItem(hDlg, IDC_BTN_ADD);
		hBtnDel = GetDlgItem(hDlg, IDC_BTN_DEL);
		hBtnClear = GetDlgItem(hDlg, IDC_BTN_CLEAR);

		// disable windows
		EnableWindow(hEditSum, FALSE);

		// add test data
		AddToList(hComboCat, CAT1);
		AddToList(hComboCat, CAT2);
		AddToList(hComboCat, CAT3);
		SendMessage(hComboCat, CB_SETCURSEL, 0, 0);
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_BTN_ADD:
			break;
		case IDC_BTN_DEL:
			break;
		case IDC_BTN_CLEAR:
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
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
enum Category
{
	GAME_PC,
	WORk_PC,
	NOTEBOOKS
};

const TCHAR CAT1[] = L"Ноутбуки";
const TCHAR CAT2[] = L"Игровые компьютеры";
const TCHAR CAT3[] = L"Компьютеры для работы и учёбы";

// goods
const int GOODS_NUM = 3;
const TCHAR *CAT_NOTEBOOKS[GOODS_NUM] = {
	L"Dell Inspiron 5558, 19 900грн",
	L"Dell Inspiron 3543, 13 799грн",
	L"Dell Inspiron 3542, 7 099грн"
};

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

	int list_items(0);
	int index(0);

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
			list_items = SendMessage(hListGoods, LB_GETCOUNT, 0, 0);
			if (list_items)
			{
				index = SendMessage(hListGoods, LB_GETCURSEL, 0, 0);
				SendMessage(hListGoods, LB_GETTEXT, index, (LPARAM)buf);
				SendMessage(hListBasket, LB_ADDSTRING, 0, (LPARAM)buf);
			}
			else
			{
				MessageBox(hDlg, L"List is empty!", L"Error", MB_OK | MB_ICONERROR);
			}
			break;
		case IDC_BTN_DEL:
			break;
		case IDC_BTN_CLEAR:
			SendMessage(hListBasket, LB_RESETCONTENT, 0, 0);
			break;
		}

		if (LOWORD(wParam) == IDC_COMBO_CAT
			&& HIWORD(wParam) == CBN_SELCHANGE)
		{
			SendMessage(hListGoods, LB_RESETCONTENT, 0, 0);

			int category = SendMessage(hComboCat, CB_GETCURSEL, 0, 0);
			switch (category)
			{
			case Category::NOTEBOOKS:
				for (size_t i = 0; i < GOODS_NUM; ++i)
					SendMessage(hListGoods, LB_ADDSTRING, 0, (LPARAM)CAT_NOTEBOOKS[i]);
				break;
			}
		}
		break;
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
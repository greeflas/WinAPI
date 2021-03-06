#include <windows.h>
#include <cstdio>

#include "resource.h"

// Global variables

// image
const int IMG_NUM = 6;
HBITMAP hBmp[IMG_NUM];

// list
HWND hListImages;

// static
HWND hStaticImage;

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
	static int img_index(0);

	switch (message)
	{
	case WM_INITDIALOG:
		hListImages = GetDlgItem(hDlg, IDC_LIST_IMAGES);
		hStaticImage = GetDlgItem(hDlg, IDC_IMAGE);
		hBtnStart = GetDlgItem(hDlg, IDC_BTN_START);
		hBtnStop = GetDlgItem(hDlg, IDC_BTN_STOP);
		hBtnPrev = GetDlgItem(hDlg, IDC_BTN_PREV);
		hBtnNext = GetDlgItem(hDlg, IDC_BTN_NEXT);

		EnableWindow(hBtnStop, FALSE);
		EnableWindow(hBtnStart, FALSE);

		for (size_t i = 0; i < IMG_NUM; ++i)
		{
			hBmp[i] = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP7 + i));
		}

		SendMessage(hListImages, LB_ADDSTRING, 0, (LPARAM)L"1.jpg");
		SendMessage(hListImages, LB_ADDSTRING, 0, (LPARAM)L"2.jpg");
		SendMessage(hListImages, LB_ADDSTRING, 0, (LPARAM)L"3.jpg");
		SendMessage(hListImages, LB_ADDSTRING, 0, (LPARAM)L"4.jpg");
		SendMessage(hListImages, LB_ADDSTRING, 0, (LPARAM)L"5.jpg");
		SendMessage(hListImages, LB_ADDSTRING, 0, (LPARAM)L"6.jpg");
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BTN_START:
			EnableWindow(hBtnStop, TRUE);
			SetTimer(hDlg, 1, 3000, NULL);
			break;
		case IDC_BTN_STOP:
			EnableWindow(hBtnStop, FALSE);
			KillTimer(hDlg, 1);
			break;
		case IDC_BTN_PREV:
			if (img_index == 0)
				img_index = 5;
			else
				--img_index;
			SendMessage(hStaticImage, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[img_index]));
			break;
		case IDC_BTN_NEXT:
			//img_index = SendMessage(hListImages, LB_GETCURSEL, 0, 0);
			if (img_index == 5)
				img_index = 0;
			else
				++img_index;
			SendMessage(hStaticImage, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[img_index]));
			break;
		case IDC_LIST_IMAGES:
			if (HIWORD(wParam) == LBN_SELCHANGE)
			{
				EnableWindow(hBtnStart, TRUE);

				img_index = SendMessage(hListImages, LB_GETCURSEL, 0, 0);
				SendMessage(hStaticImage, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[img_index]));
			}
			break;
		}
		break;
	case WM_TIMER:
		if (img_index > IMG_NUM)
			img_index = 0;
		else
			++img_index;

		SendMessage(hStaticImage, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp[img_index]));
		break;
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
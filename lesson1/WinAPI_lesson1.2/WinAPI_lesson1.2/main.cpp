#include <windows.h> // Windows API
#include <cstdio> // input/output library

#include "resource.h" // Form

// Global variables
HWND hEdit1, hEdit2, hEdit3; // дескрипторы элементов на макете

BOOL CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,
					HINSTANCE hPrevInst,
					LPSTR lpszCmdLine, // указатель на коммандную строку
					int nCmdShow)
{


	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int x, y; // mouse position
	static int count1(0), count2(0); // clicks count
	TCHAR buf[512] {0}; // buffer

	switch (message)
	{
	case WM_INITDIALOG:
		hEdit1 = GetDlgItem(hDlg, IDC_EDIT1);
		hEdit2 = GetDlgItem(hDlg, IDC_EDIT2);
		hEdit3 = GetDlgItem(hDlg, IDC_EDIT3);
		EnableWindow(hEdit1, FALSE);
		EnableWindow(hEdit2, FALSE);
		EnableWindow(hEdit3, FALSE);
		break;
	case WM_MOUSEMOVE:
		x = LOWORD(lParam); // lower word (first 2 bytes)
		y = HIWORD(lParam); // hight word (second 2 bytes)
		swprintf_s(buf, TEXT("X: %d, Y: %d"), x, y);
		SetWindowText(hEdit1, buf);
		break;
	case WM_LBUTTONDOWN:
		++count1;
		swprintf_s(buf, TEXT("%d"), count1);
		SetWindowText(hEdit2, buf);
		break;
	case WM_RBUTTONDOWN:
		++count2;
		swprintf_s(buf, TEXT("%d"), count2);
		SetWindowText(hEdit3, buf);
		break;
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
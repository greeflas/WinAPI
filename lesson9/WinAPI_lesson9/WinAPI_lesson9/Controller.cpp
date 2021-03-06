#include "Controller.h"

Controller *Controller::ptr = nullptr;

Controller::Controller()
{
	ptr = this;
}

BOOL CALLBACK Controller::DlgProc(HWND hWnd,
								UINT message,
								WPARAM wParam,
								LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hWnd, WM_VSCROLL, ptr->Cls_OnVScroll);
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
	}
	return FALSE;
}

BOOL Controller::Cls_OnInitDialog(HWND hWnd,
								HWND hWndFocus,
								LPARAM lParam)
{
	hCheckParam1 = GetDlgItem(hWnd, IDC_CHECK_PARAM1);
	hCheckParam2 = GetDlgItem(hWnd, IDC_CHECK_PARAM2);
	hSpin = GetDlgItem(hWnd, IDC_SPIN);
	hEdit = GetDlgItem(hWnd, IDC_EDIT);
	hMenu = GetDlgItem(hWnd, IDR_MENU);

	SendMessage(hSpin, UDM_SETRANGE32, -50, 50);
	SetWindowText(hEdit, L"0");

	hStatus = CreateStatusWindow(WS_CHILD | WS_VISIBLE | CCS_BOTTOM | SBARS_TOOLTIPS | SBARS_SIZEGRIP,
								NULL,
								hWnd,
								WM_USER);

	const int PARTS_NUM = 4;
	int parts[PARTS_NUM] { 0, 100, 200, -1 };

	SendMessage(hStatus, SB_SETPARTS, PARTS_NUM, (LPARAM)parts);
	SendMessage(hStatus, SB_SETTEXT, 1, (LPARAM)L"Weight: 0");
	SendMessage(hStatus, SB_SETTEXT, 2, (LPARAM)L"Param 1: off");
	SendMessage(hStatus, SB_SETTEXT, 3, (LPARAM)L"Param 2: off");

	// Set icon
	hIcon = LoadIcon(GetModuleHandle(0), MAKEINTRESOURCE(IDI_ICON1));
	SendMessage(hStatus, SB_SETICON, 1, (LPARAM)hIcon);

	// Set background color
	SendMessage(hStatus, SB_SETBKCOLOR, 0, (LPARAM)RGB(0, 160, 0));
	
	return TRUE;
}

void Controller::Cls_OnCommand(HWND hWnd,
							int id,
							HWND hCtl,
							UINT codeNotify)
{
	switch (id)
	{
	case IDC_CHECK_PARAM1: {
		LRESULT res = SendMessage(hCheckParam1, BM_GETCHECK, 0, 0);
		if (res == BST_CHECKED)
			SendMessage(hStatus, SB_SETTEXT, 2, (LPARAM)L"Param 1: true");
		else
			SendMessage(hStatus, SB_SETTEXT, 2, (LPARAM)L"Param 1: false");
		break;
	}
	case IDC_CHECK_PARAM2: {
		LRESULT res = SendMessage(hCheckParam2, BM_GETCHECK, 0, 0);
		if (res == BST_CHECKED)
			SendMessage(hStatus, SB_SETTEXT, 3, (LPARAM)L"Param 2: true");
		else
			SendMessage(hStatus, SB_SETTEXT, 3, (LPARAM)L"Param 2: false");
		break;
	}
	case ID_COW_FEED: {
		const int BUFF_SIZE = 1024;
		TCHAR buf[BUFF_SIZE] { 0 };

		int val = SendMessage(hStatus, SB_GETTEXT, 1, 0);
		swprintf_s(buf, L"Weight: %d", val + 1);

		SendMessage(hStatus, SB_SETTEXT, 1, (LPARAM)buf);
		break;
	}
	}
}

void Controller::Cls_OnVScroll(HWND hWnd,
							HWND hCtrl,
							UINT code,
							int pos)
{
	const int BUFF_SIZE = 1024;
	TCHAR buf[BUFF_SIZE] { 0 };

	swprintf_s(buf, L"Weight: %d", pos);
	SendMessage(hStatus, SB_SETTEXT, 1, (LPARAM)buf);
}

void Controller::Cls_OnClose(HWND hWnd)
{
	EndDialog(hWnd, 0);
}
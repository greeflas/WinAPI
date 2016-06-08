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
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
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

	SendMessage(hSpin, UDM_SETRANGE32, -50, 50);
	SetWindowText(hEdit, L"0");

	hStatus = CreateStatusWindow(WS_CHILD | WS_VISIBLE | CCS_BOTTOM | SBARS_TOOLTIPS | SBARS_SIZEGRIP,
								NULL,
								hWnd,
								WM_USER);

	const int PARTS_NUM = 4;
	int parts[PARTS_NUM] { 0, 70, 160, -1 };

	SendMessage(hStatus, SB_SETPARTS, PARTS_NUM, (LPARAM)parts);
	SendMessage(hStatus, SB_SETTEXT, 1, (LPARAM)L"Counter: 0");
	SendMessage(hStatus, SB_SETTEXT, 2, (LPARAM)L"Param 1: off");
	SendMessage(hStatus, SB_SETTEXT, 3, (LPARAM)L"Param 2: off");

	return TRUE;
}

void Controller::Cls_OnCommand(HWND hWnd,
							int id,
							HWND hCtl,
							UINT codeNotify)
{

}

void Controller::Cls_OnClose(HWND hWnd)
{
	EndDialog(hWnd, 0);
}
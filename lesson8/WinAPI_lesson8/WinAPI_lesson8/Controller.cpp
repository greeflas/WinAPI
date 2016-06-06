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
	hSpin = GetDlgItem(hWnd, IDC_SPIN);
	hEdit = GetDlgItem(hWnd, IDC_EDIT);

	SendMessage(hSpin, UDM_SETRANGE32, -50, 50);

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
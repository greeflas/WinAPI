#include "Controller.h"

// static variables
Controller *Controller::ptr = nullptr;

// construct - destruct
Controller::Controller()
{
	ptr = this;
}

Controller::~Controller()
{

}

// control methods
BOOL CALLBACK Controller::DlgProc(HWND hWnd,
								UINT message,
								WPARAM wParam,
								LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
	}


	return FALSE;
}

BOOL Controller::Cls_OnInitDialog(HWND hWnd,
								HWND hWndFocus,
								LPARAM lParam)
{
	

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
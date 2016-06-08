#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "headers.h"

class Controller
{
public:
	static Controller *ptr;

	// handlers
	HWND hStatus;
	HWND hCheckParam1, hCheckParam2;
	HWND hSpin;
	HWND hEdit;

	// Icons
	HICON hIcon;

	Controller();
	static BOOL CALLBACK DlgProc(HWND hWnd,
		UINT message,
		WPARAM wParam,
		LPARAM lParam);
	BOOL Cls_OnInitDialog(HWND hWnd,
		HWND hWndFocus,
		LPARAM lParam);
	void Cls_OnCommand(HWND hWnd,
		int id,
		HWND hCtl,
		UINT codeNotify);
	void Cls_OnClose(HWND hWnd);
};

#endif // CONTROLLER_H
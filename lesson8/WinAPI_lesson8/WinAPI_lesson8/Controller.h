#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "header.h"

class Controller
{
public:
	static Controller *ptr;

	// handlers
	HWND hSpin;
	HWND hEdit;

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
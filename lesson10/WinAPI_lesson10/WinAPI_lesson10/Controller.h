#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "headers.h"
#include "resource.h"

class Controller
{
public:
	static Controller *ptr;

	// handlers
	

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
	void Cls_OnVScroll(HWND hWnd, HWND hCtrl, UINT code, int pos);
	void Cls_OnClose(HWND hWnd);
};

#endif // CONTROLLER_H
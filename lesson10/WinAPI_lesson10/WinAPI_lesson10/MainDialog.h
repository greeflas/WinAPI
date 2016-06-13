#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include "Controller.h"
#include "resource.h"

class MainDialog: public Controller
{
public:
	MainDialog();
	~MainDialog();

	BOOL Cls_OnInitDialog(HWND hWnd,
						HWND hWndFocus,
						LPARAM lParam);
	void Cls_OnCommand(HWND hWnd,
					int id,
					HWND hCtl,
					UINT codeNotify);
};

#endif // MAIN_DIALOG_H
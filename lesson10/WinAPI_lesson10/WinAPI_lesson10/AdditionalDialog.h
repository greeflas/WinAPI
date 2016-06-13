#ifndef ADDITIONAL_DIALOG_H
#define ADDITIONAL_DIALOG_H

#include "Controller.h"
#include "resource.h"

class AdditionalDialog: public Controller
{
	// hendlers
	HWND hEditRes;

	TCHAR *text;
public:
	AdditionalDialog();
	AdditionalDialog(TCHAR *text);
	~AdditionalDialog();

	BOOL Cls_OnInitDialog(HWND hWnd,
						HWND hWndFocus,
						LPARAM lParam);
	void Cls_OnCommand(HWND hWnd,
					int ctl_id,
					HWND hCtl,
					UINT codeNotify);
};

#endif // ADDITIONAL_DIALOG_H
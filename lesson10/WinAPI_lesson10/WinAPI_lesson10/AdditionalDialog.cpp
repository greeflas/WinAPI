#include "headers.h"
#include "AdditionalDialog.h"

AdditionalDialog::AdditionalDialog(): Controller()
{
	text = nullptr;
}

AdditionalDialog::AdditionalDialog(TCHAR *text)
{
	this->ptr = this;
	this->text = text;
}

AdditionalDialog::~AdditionalDialog()
{
	if (!text)
		delete text;
}

BOOL AdditionalDialog::Cls_OnInitDialog(HWND hWnd,
								HWND hWndFocus,
								LPARAM lParam)
{
	hEditRes = GetDlgItem(hWnd, IDC_EDIT_RES);
	SetWindowText(hEditRes, this->text);

	return TRUE;
}

void AdditionalDialog::Cls_OnCommand(HWND hWnd,
									int ctl_id,
									HWND hCtl,
									UINT codeNotify)
{
	switch (ctl_id)
	{
	case IDC_BTN:
		MessageBox(hWnd, L"Dialog one!", L"Messaga", MB_OK | MB_ICONINFORMATION);
		break;
	}
}
#include "headers.h"
#include "MainDialog.h"
#include "AdditionalDialog.h"

MainDialog::MainDialog(): Controller()
{
		
}

MainDialog::~MainDialog()
{

}

BOOL MainDialog::Cls_OnInitDialog(HWND hWnd,
								HWND hWndFocus,
								LPARAM lParam)
{
	hEdit = GetDlgItem(hWnd, IDC_EDIT);
	hBtn = GetDlgItem(hWnd, IDC_BTN);

	return TRUE;
}

void MainDialog::Cls_OnCommand(HWND hWnd,
							int ctl_id,
							HWND hCtl,
							UINT codeNotify)
{
	switch (ctl_id)
	{
	case IDC_BTN:
		const int BUFF_SIZE = 1024;
		TCHAR buf[BUFF_SIZE] { 0 };
		
		GetWindowText(hEdit, buf, BUFF_SIZE);

		size_t len = wcslen(buf) + 1;
		TCHAR *text = new TCHAR[len];
		wcscpy(text, buf);

		AdditionalDialog ad(text);
		DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG2), hWnd, AdditionalDialog::DlgProc);
		break;
	}
}
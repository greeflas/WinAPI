#include "MainDialog.h"

int WINAPI WinMain(HINSTANCE hInst,
				HINSTANCE hPrevInst,
				LPSTR lpszCmdLine,
				int nCmdShow)
{
	MainDialog md;
	return DialogBox(hInst,
					MAKEINTRESOURCE(IDD_DIALOG1),
					NULL,
					MainDialog::DlgProc);
}
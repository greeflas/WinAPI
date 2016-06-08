#include "Controller.h"

int WINAPI WinMain(HINSTANCE hInst,
				HINSTANCE hPrevInst,
				LPSTR lpszCmdLine,
				int nCmdShow)
{
	Controller c;
	return DialogBox(hInst,
					MAKEINTRESOURCE(IDD_DIALOG1),
					NULL,
					Controller::DlgProc);
}
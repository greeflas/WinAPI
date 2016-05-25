#include "headers.h"

void AddToList(HWND handler, const TCHAR message[])
{
	SendMessage(handler, CB_ADDSTRING, 0, (LPARAM)message);
}
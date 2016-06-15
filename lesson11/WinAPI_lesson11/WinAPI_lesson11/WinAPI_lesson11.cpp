// WinAPI_lesson11.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WinAPI_lesson11.h"

#include "Student.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// hendlers
HWND hList;
HWND hEdit;
HWND hBtnDel, hBtnAdd, hBtnEdit;
// 'Student information' form
HWND hEditName, hEditBirth, hEditEmail, hEditAddress, hEditPhone;
HWND hBtnOK, hBtnCancel;

// Students
const int STUDENTS_NUM = 3;
Student students[STUDENTS_NUM] = 
{
	{ L"Vasya Pupkin", L"01/01/1970", L"11-111-111", L"vasya@gmail.com", L"Some str. 50/7" },
	{ L"Petro", L"27/04/1999", L"22-222-222", L"petro@gmail.com", L"Some str. 66/9" },
	{ L"Elizaveta Pupkina", L"03/01/1973", L"11-111-112", L"lizka.kiska@gmail.com", L"Some str. 50/8" },
};

std::vector<Student> v(students, students + 3);

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

INT_PTR CALLBACK	DlgProc(HWND , UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WINAPI_LESSON11, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI_LESSON11));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI_LESSON11));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WINAPI_LESSON11);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	const int BUFF_SIZE = 1024;
	TCHAR buf[BUFF_SIZE] { 0 };

	int index(0);

	switch (message)
	{
	case WM_CREATE:
		MoveWindow(hWnd, 700, 400, 550, 320, TRUE);
		SetWindowText(hWnd, L"Students");

		hList = CreateWindowEx(
			0, L"ListBox", NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | LBS_NOTIFY,
			10, 10, 200, 200, hWnd,
			(HMENU)IDC_LIST, hInst, 0
		);

		hEdit = CreateWindowEx(
			0, L"Edit", NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_READONLY,
			224, 10, 300, 194, hWnd,
			(HMENU)IDC_EDIT, hInst, 0
		);

		hBtnDel = CreateWindowEx(
			0, L"Button", L"Delete", WS_CHILD | WS_VISIBLE,
			10, 220, 120, 30, hWnd,
			(HMENU)IDC_BTN_ADD, hInst, 0
		);

		hBtnAdd = CreateWindowEx(
			0, L"Button", L"Add", WS_CHILD | WS_VISIBLE,
			140, 220, 120, 30, hWnd,
			(HMENU)IDC_BTN_ADD, hInst, 0
		);

		hBtnEdit = CreateWindowEx(
			0, L"Button", L"Edit", WS_CHILD | WS_VISIBLE,
			270, 220, 120, 30, hWnd,
			(HMENU)IDC_EDIT, hInst, 0
		);

		// add students from vector to list box
		for (auto itr = v.begin(); itr < v.end(); ++itr)
			SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)itr->name);
		SendMessage(hList, LB_SETCURSEL, 0, 0);
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case IDC_LIST:
			index = SendMessage(hList, LB_GETCURSEL, 0, 0);

			swprintf_s(
				buf,
				L" Adress: %s\r\n Date of birth: %s\r\n Phone number: %s\r\n E-mail: %s",
				v[index].adress,
				v[index].birth,
				v[index].phone,
				v[index].email
			);

			SetWindowText(hEdit, buf);
			break;
		case IDC_BTN_ADD:
			DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DlgProc);

			SendMessage(hList, LB_RESETCONTENT, 0, 0);
			for (auto itr = v.begin(); itr < v.end(); ++itr)
				SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)itr->name);
			SendMessage(hList, LB_SETCURSEL, 0, 0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

// Message hendler for form "Student information"
INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	const int BUFF_SIZE = 1024;
	TCHAR buf[BUFF_SIZE] { 0 };

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		hEditName = GetDlgItem(hDlg, IDC_EDIT_NAME);
		hEditBirth = GetDlgItem(hDlg, IDC_EDIT_BIRTH);
		hEditEmail = GetDlgItem(hDlg, IDC_EDIT_EMAIL);
		hEditAddress = GetDlgItem(hDlg, IDC_EDIT_ADDRESS);
		hEditPhone = GetDlgItem(hDlg, IDC_EDIT_PHONE);
		hBtnOK = GetDlgItem(hDlg, IDC_BTN_OK);
		hBtnCancel = GetDlgItem(hDlg, IDC_BTN_CANCEL);
		break;

	case WM_COMMAND:
		
		switch (wParam)
		{
		case IDCANCEL:
		case IDC_BTN_CANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		case IDC_BTN_OK:
			Student s;

			GetWindowText(hEditName, buf, BUFF_SIZE);
			lstrcpy(s.name, buf);

			GetWindowText(hEditBirth, buf, BUFF_SIZE);
			lstrcpy(s.birth, buf);

			GetWindowText(hEditEmail, buf, BUFF_SIZE);
			lstrcpy(s.email, buf);

			GetWindowText(hEditAddress, buf, BUFF_SIZE);
			lstrcpy(s.adress, buf);

			GetWindowText(hEditPhone, buf, BUFF_SIZE);
			lstrcpy(s.phone, buf);

			v.push_back(s);

			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

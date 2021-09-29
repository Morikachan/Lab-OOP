#include "framework.h"
#include "resource1.h"

static INT_PTR CALLBACK Work1(HWND, UINT, WPARAM, LPARAM);
int Func_DLG1(HINSTANCE hInst, HWND hWnd)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work1);
}
//Callback-функція вікна
INT_PTR CALLBACK Work1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (iMessage)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_NEXT)
		{
			EndDialog(hDlg, 1);
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == ID_CANCEL1)
		{
			EndDialog(hDlg, 0);
			return (INT_PTR)TRUE;
		}
	default: break;
	}
	return (INT_PTR)FALSE;
}
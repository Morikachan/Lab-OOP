#include "framework.h"
#include "resource2.h"

static INT_PTR CALLBACK Work2(HWND, UINT, WPARAM, LPARAM);
int Func_DLG2(HINSTANCE hInst, HWND hWnd)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Work2);
}
//Callback-функція вікна
INT_PTR CALLBACK Work2(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (iMessage)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_PREV)
		{
			EndDialog(hDlg, -1);
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == ID_OK || LOWORD(wParam) == ID_CANCEL2)
		{
			EndDialog(hDlg, 0);
			return (INT_PTR)TRUE;
		}
	default: break;
	}
	return (INT_PTR)FALSE;
}
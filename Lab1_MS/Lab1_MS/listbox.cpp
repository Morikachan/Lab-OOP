#include "framework.h"
#include "resource3.h"

static WCHAR buf[256];
static char str[5][10] = { "IP-01", "IP-02", "IP-03", "IP-04", "IP-05" };

static INT_PTR CALLBACK Work3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        for (int i = 0; i < 5; i++)
            SendDlgItemMessage(hDlg, IDC_LIST, LB_ADDSTRING, 0, (LPARAM)str[i]);

        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == ID_YES)
        {
            int idx = SendDlgItemMessage(hDlg, IDC_LIST, LB_GETCURSEL, 0, 0);
            SendDlgItemMessage(hDlg, IDC_LIST, LB_GETTEXT, idx, (LPARAM)buf);
            EndDialog(hDlg, 1);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == ID_CANCEL3)
        {
            EndDialog(hDlg, 0);
            return (INT_PTR)FALSE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

int Func_LIST(HINSTANCE hInst, HWND hWnd, WCHAR* dest) {
    if (DialogBox(hInst, MAKEINTRESOURCE(IDD_LISTBOX), hWnd, Work3) == 1) {
        lstrcpyW(dest, buf);
        return 1;
    }
    return 0;
}
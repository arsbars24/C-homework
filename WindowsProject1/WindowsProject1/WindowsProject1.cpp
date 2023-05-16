#include "framework.h"
#include "WindowsProject1.h"

#include <cmath>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        SetTimer(hWnd, 1, 100, NULL); // создание таймера с идентификатором 1 и периодом 10 миллисекунд
        break;
    case WM_TIMER:
        InvalidateRect(hWnd, NULL, TRUE); // сообщаем операционной системе, что содержимое окна нужно перерисовать
        break;
    case WM_COMMAND:
    {
        //int wmid = loword(wparam);
        //// разобрать выбор в меню:
        //switch (wmid)
        //{
        //case idm_about:
        //    dialogbox(hinst, makeintresource(idd_aboutbox), hwnd, about);
        //    break;
        //case idm_exit:
        //    destroywindow(hwnd);
        //    break;
        //default:
        //    return defwindowproc(hwnd, message, wparam, lparam);
        //}
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Set drawing parameters
        HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
        HBRUSH brushEarth = CreateSolidBrush(RGB(19, 126, 109));  // Green brush for Earth
        HBRUSH brushSun = CreateSolidBrush(RGB(255, 255, 0));   // Yellow brush for Sun
        HBRUSH brushMars = CreateSolidBrush(RGB(255, 0, 0));
        SelectObject(hdc, pen);

        // Draw window background
        RECT rect;
        GetClientRect(hWnd, &rect);
        FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));

        // Draw the Sun
        int cx = rect.right / 2;
        int cy = rect.bottom / 2;
        int rSun = 50;
        SelectObject(hdc, brushSun);
        Ellipse(hdc, cx - rSun, cy - rSun, cx + rSun, cy + rSun);

        // Draw the Earth's orbit
        int rEarth = 150;
        Arc(hdc, cx - rEarth, cy - rEarth, cx + rEarth, cy + rEarth, cx - rEarth, cy, cx - rEarth, cy);

        // Compute the position of the Earth in its orbit
        SYSTEMTIME time;
        GetSystemTime(&time);
        double angleEarth = 2 * 3.14 * (time.wSecond + time.wMilliseconds / 1000.0) / 60;
        int xPlanetEarth = cx + rEarth * cos(angleEarth);
        int yPlanetEarth = cy - rEarth * sin(angleEarth);

        // Draw the Earth
        int rPlanetEarth = 10;
        SelectObject(hdc, brushEarth);
        Ellipse(hdc, xPlanetEarth - rPlanetEarth, yPlanetEarth - rPlanetEarth, xPlanetEarth + rPlanetEarth, yPlanetEarth + rPlanetEarth);

        // Release the device context
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        KillTimer(hWnd, 1); // удаление таймера с идентификатором 1
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
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


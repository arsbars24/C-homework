// Solar.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Solar.h"
#include <math.h>
#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void Draw_Solar(HWND hwnd, HDC hdc);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SOLAR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SOLAR));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
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
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SOLAR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SOLAR);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
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
   hInst = hInstance; // Store instance handle in our global variable

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
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        
        Draw_Solar(hWnd, hdc);
        EndPaint(hWnd, &ps);
        break;
    }
    
    case WM_DESTROY:
        KillTimer(hWnd, 1); // удаление таймера с идентификатором 1
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

void Draw_Solar(HWND hwnd, HDC hdc) {
    

    // Set drawing parameters
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    HBRUSH brushEarth = CreateSolidBrush(RGB(0, 255, 0));  // Green brush for Earth
    HBRUSH brushSun = CreateSolidBrush(RGB(255, 255, 0));   // Yellow brush for Sun
    HBRUSH brushMars = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, pen);

    // Draw window background
    RECT rect;
    GetClientRect(hwnd, &rect);
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

    // Draw the Mars's orbit
    int rMars = 100;
    Arc(hdc, cx - rMars, cy - rMars, cx + rMars, cy + rMars, cx - rMars, cy, cx - rMars, cy);

    // Compute the position of the Earth in its orbit
    SYSTEMTIME time;
    GetSystemTime(&time);
    double angleEarth = 2 * 3.14 * (time.wSecond + time.wMilliseconds / 1000.0) / 60;
    int xPlanetEarth = cx + rEarth * cos(angleEarth);
    int yPlanetEarth = cy - rEarth * sin(angleEarth);

    // Compute the position of the Mars in its orbit
    double angleMars = -2 * 3.14 * (time.wSecond + time.wMilliseconds / 1000.0) / 30;
    int xPlanetMars = cx + rMars * cos(angleMars);
    int yPlanetMars = cy - rMars * sin(angleMars);

    // Draw the Earth
    int rPlanetEarth = 10;
    SelectObject(hdc, brushEarth);
    Ellipse(hdc, xPlanetEarth - rPlanetEarth, yPlanetEarth - rPlanetEarth, xPlanetEarth + rPlanetEarth, yPlanetEarth + rPlanetEarth);

    // Draw the Mars
    int rPlanetMars = 5;
    SelectObject(hdc, brushMars);
    Ellipse(hdc, xPlanetMars - rPlanetMars, yPlanetMars - rPlanetMars, xPlanetMars + rPlanetMars, yPlanetMars + rPlanetMars);


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

// сделать функцию для движения по окружности и раскрасить экран и фигуры


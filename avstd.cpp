
#define _SAPI_H
#define _SAPI54_H
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <tlhelp32.h>
#include <shellapi.h>
#include "avstd.hpp"

using namespace std;

void draw_rectangle(int x, int y, int r, int g, int b, int end_x, int end_y) {
    HDC hdc = GetDC(NULL);

    HBRUSH hbrush = CreateSolidBrush(RGB(r, g, b));

    RECT rect = {x, y, end_x, end_y};

    FillRect(hdc, &rect, hbrush);

    DeleteObject(hbrush);

    ReleaseDC(NULL, hdc);

}

void draw_text(int x, int y, const char text[]) {

    HDC hdc = GetDC(NULL);


    

    HFONT hFont = CreateFontA(
        72,                // Height in logical units (bigger = taller)
        0,                 // Width (0 = auto)
        0, 0,              // Escapement & orientation
        FW_BOLD,           // Weight
        FALSE, FALSE, FALSE, // Italic, underline, strikeout
        ANSI_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_DONTCARE,
        "Arial"            // Font face
    );

    SelectObject(hdc, hFont);
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(255, 255, 255));
    ExtTextOutA(hdc, x, y, 0, NULL, text, strlen(text), NULL);

    DeleteObject(hFont);
    ReleaseDC(NULL, hdc);

    

}

void melt_screen() {
    HDC hdcScreen = GetDC(NULL);
    HDC hdcMem = CreateCompatibleDC(hdcScreen);

    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);
    int center_x = screen_width / 2;
    int center_y = screen_height / 2;

    HBITMAP hBitmap = CreateCompatibleBitmap(hdcScreen, screen_width, screen_height);
    SelectObject(hdcMem, hBitmap);
    BitBlt(hdcMem, 0, 0, screen_width, screen_height, hdcScreen, 0, 0, SRCCOPY);

    for (int x = 0; x < screen_width; x += 10) {
        int melt_amount = rand() % 30;
        BitBlt(hdcScreen, x, melt_amount, 10, screen_height - melt_amount, hdcMem, x, 0, SRCCOPY);
    }
}

void glitch_screen() {
    HDC hdcScreen = GetDC(NULL);
    HDC hdcMem = CreateCompatibleDC(hdcScreen);

    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);

    HBITMAP hBitmap = CreateCompatibleBitmap(hdcScreen, screen_width, screen_height);
    SelectObject(hdcMem, hBitmap);
    BitBlt(hdcMem, 0, 0, screen_width, screen_height, hdcScreen, 0, 0, SRCCOPY);

    for (int x = 0; x < screen_width; x += 10) {
        int melt_amount = (rand() % 61) - 30;
        BitBlt(hdcScreen, x, melt_amount, 10, screen_height - melt_amount, hdcMem, x, 0, SRCCOPY); // vertical smear
    }

    for (int y = 0; y < screen_height; y += 10) {
        int melt_amount = (rand() % 61) - 30;
        BitBlt(hdcScreen, melt_amount, y, screen_width - melt_amount, 10, hdcMem, 0, y, SRCCOPY); // horizontal smear
    }
}

void Command(string command) {
    system(command.c_str());
}

 // Speech API

void MsgBox(const char* msg, const char* title) {
    MessageBox(NULL, msg, title, MB_OK | MB_ICONEXCLAMATION);
}



void ShowMessageBox(const std::string& message) {
    std::string command = "powershell -Command \"Add-Type -AssemblyName Microsoft.VisualBasic; ";
    command += "[Microsoft.VisualBasic.Interaction]::MsgBox('" + message + "')\"";
    system(command.c_str());
}
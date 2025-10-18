#define _SAPI_H
#define _SAPI54_H

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>


#ifndef AVSTD_HPP
#define AVSTD_HPP

using namespace std;

void draw_rectangle(int x, int y, int r, int g, int b, int end_x, int end_y);

void glitch_screen();

void draw_text(int x, int y, const char text[]);

void speak(const wchar_t* message);

void melt_screen();

void MsgBox(const char* msg, const char* title);



void Command(string command);

void ShowMessageBox(const std::string& message);

#endif
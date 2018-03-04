/*
Фисенко П.В ЗПИ-151
Лабораторная работа №3. Вариант 9

Программа выводит приветствие ‘Hello, World’ желтого цвета 
в направлении диагонали экрана поместив его в центр.
*/

#include "stdafx.h"
#include <windows.h>
#include <wincon.h>
#include <iostream>

using namespace std;

void main()
{
	COORD coord1;
	coord1.Y = 0; 
	coord1.X = 0;
	DWORD cWritten;
	WORD wColor = 0x0e;
	TCHAR str[255] = L"Hello, World!";
 
    //получаем хендл консоли
	void *hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    //выводим посимвольно фразу в консоль со смещением позиции курсора
	for (int i = 0; i < _tcslen(str); i++)
	{
		coord1.X = 30 + i;
		for (int j = 0; j <= i; j++) {
			coord1.Y = 5 + j;
			SetConsoleCursorPosition(hOut, coord1);
			WriteConsoleOutputAttribute(hOut, &wColor, 1, coord1, &cWritten);
		}	
		WriteConsoleOutputCharacter(hOut, &str[i], 1, coord1, &cWritten);
	}
	
	CloseHandle(hOut);
	getchar();
	ExitProcess(0);
}

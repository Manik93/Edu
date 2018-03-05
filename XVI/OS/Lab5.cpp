/*
Фисенко П.В ЗПИ-151
Лабораторная работа №5. Вариант 9

Программа выводит в центре экрана текстовую строку из нескольких слов и передвигает
при двойном «клике» символ, по которому он произведен на одну позицию вверх.
Выход из программы – одновременное нажатие правой кнопки мыши.
*/

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

using namespace std;

void main()
{
	TCHAR str[255] = L"Double click on any char to move it up!", buffer[1];
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD actlen;
	INPUT_RECORD charinfo;
	COORD pos;

	void *hInput = GetStdHandle(STD_INPUT_HANDLE);
	if (hInput == INVALID_HANDLE_VALUE)
	{
		printf("Error GetStdHandle"); ExitProcess(0);
	}

	void *hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOutput == INVALID_HANDLE_VALUE)
	{
		printf("Error GetStdHandle"); ExitProcess(0);
	}

	pos.X = 0; pos.Y = 10;
	
	//Выводим строку на экран
	for (int i = 0; i < _tcslen(str); i++)
	{
		pos.X = 20 + i;
		WriteConsoleOutputCharacter(hOutput, &str[i], 1, pos, &actlen);
	}
	
	//Считываем ввод в консоль в бесконечном цикле. Если сработало событие DOUBLE_CLICK,
	//то выходим из вложенного цикла и двигаем символ из позиции, соответствующей 
	//положению указателя мыши на одну позицию вверх. Если нажали правую кнопку мыши - выход.
	do
	{
		do
		{
			ReadConsoleInput(hInput, &charinfo, 1, &actlen);
			if (charinfo.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) ExitProcess(0);
		} while (charinfo.EventType != MOUSE_EVENT || charinfo.EventType == MOUSE_EVENT && charinfo.Event.MouseEvent.dwEventFlags != DOUBLE_CLICK);

		SetConsoleCursorPosition(hOutput, charinfo.Event.MouseEvent.dwMousePosition);
		GetConsoleScreenBufferInfo(hOutput, &csbi);
		pos = csbi.dwCursorPosition;

		ReadConsoleOutputCharacter(hOutput, buffer, 1, pos, &actlen);
		WriteConsoleOutputCharacter(hOutput, L" ", 1, pos, &actlen);
		pos.Y--;
		WriteConsoleOutputCharacter(hOutput, buffer, 1, pos, &actlen);
	} while (1);

	CloseHandle(hInput);
	CloseHandle(hOutput);
	getchar();
	ExitProcess(0);
}


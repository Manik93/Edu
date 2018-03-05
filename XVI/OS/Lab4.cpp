/*
Фисенко П.В ЗПИ-151
Лабораторная работа №4.Вариант 9

Программа запрашивает пароль, состоящий из трёх символьных комбинированных
сообщений, выводя при этом вместо вводимых символов - символ "*".
Если пароль введён правильно, то выводится приветствие "Hello, User". 
Выход из программы осуществить только после ввода символьной комбинации выхода.
Предварительно вывести подсказку. 
Комбинации:	
1) [N]LeftCtrl+'a'	2) [S]LeftCtrl+'b'	3) RightAlt+'c'		Выход:Shift + Alt + ’S’
*/

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

using namespace std;

void main()
{
	char textInf[] = "Press Shift + Alt + \'S\' to exit\n\rEnter password:";
	char loginSuccess[] = "\nHello, User!";
	char loginFailed[] = "\nInvalid password";
	char c = '*';
	INPUT_RECORD charinfo;
	BOOL pass = true;
	DWORD actlen, fdwMode, fdwSaveOldMode;

	//Хендл вывода
	void *hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		printf("Error GetStdHandle\n"); exit(-1);
	}

	//Хендл ввода
	void *hIn = GetStdHandle(STD_INPUT_HANDLE);
	if (hIn == INVALID_HANDLE_VALUE)
	{
		printf("Error GetStdHandle\n"); exit(-1);
	}

	//Пишем текст
	WriteConsoleA(hOut, textInf, sizeof(textInf), &actlen, NULL);

	//Получаем исходный режим ввода
	if (!GetConsoleMode(hIn, &fdwSaveOldMode))
	{
		printf("ErrorGetConsoleMode\n"); exit(-1);
	}

	//Модификация режима ввода
	fdwMode = fdwSaveOldMode&~ENABLE_MOUSE_INPUT&~ENABLE_ECHO_INPUT;

	//Присвоение модифицированного режима
	if (!SetConsoleMode(hIn, fdwMode))
	{
		printf("ErrorSetConsoleMode\n"); exit(-1);
	}

	//Ввод первой комбинации
	do
	{
		//Считываем ввод в консоль в бесконечном цикле
		ReadConsoleInput(hIn, &charinfo, 1, &actlen);
		//Если нажали
		if (charinfo.EventType == KEY_EVENT)
		{
			//Комбинацию LEFT_CTRL + A при включенном NumLock - продолжаем
			if (((charinfo.Event.KeyEvent.dwControlKeyState & (NUMLOCK_ON | LEFT_CTRL_PRESSED )) == (NUMLOCK_ON | LEFT_CTRL_PRESSED)) && (charinfo.Event.KeyEvent.wVirtualScanCode == 30)) break;
			//Комбинацию ALT + SHIFT + S - выходим из программы 
			if ((charinfo.Event.KeyEvent.dwControlKeyState & (SHIFT_PRESSED &~ LEFT_ALT_PRESSED)) && (charinfo.Event.KeyEvent.wVirtualKeyCode == 83))
			{
				pass = false;
				break;
			}
		}
	} while (1);

	//Если ввели верную комбинацию, то выводим символ * и продолжаем ввод
	if (pass) WriteConsoleA(hOut, &c, 1, &actlen, NULL);
	else
	{
		WriteConsoleA(hOut, loginFailed, strlen(loginFailed), &actlen, NULL);
		pass = false;
	}

	//Если первая комбинация верная, то вводим вторую комбинацию по анологии с предыдущей
	if (pass)
	do
	{
		ReadConsoleInput(hIn, &charinfo, 1, &actlen);
		if (charinfo.EventType == KEY_EVENT)
		{
			if (((charinfo.Event.KeyEvent.dwControlKeyState & (SCROLLLOCK_ON | LEFT_CTRL_PRESSED)) == (SCROLLLOCK_ON | LEFT_CTRL_PRESSED)) && (charinfo.Event.KeyEvent.wVirtualScanCode == 48)) break;
			if ((charinfo.Event.KeyEvent.dwControlKeyState & (SHIFT_PRESSED &~LEFT_ALT_PRESSED)) && (charinfo.Event.KeyEvent.wVirtualKeyCode == 83))
			{
				pass = false;
				break;
			}
		}
	} while (1);

	if (pass) WriteConsoleA(hOut, &c, 1, &actlen, NULL);
	else
	{
		WriteConsoleA(hOut, loginFailed, strlen(loginFailed), &actlen, NULL);
		pass = false;
	}

	//Если первая и вторая комбинации верные, то вводим третью комбинацию по анологии с предыдущими
	if (pass) do
	{
		ReadConsoleInput(hIn, &charinfo, 1, &actlen);
		if (charinfo.EventType == KEY_EVENT)
		{
			if (((charinfo.Event.KeyEvent.dwControlKeyState & (RIGHT_ALT_PRESSED)) == (RIGHT_ALT_PRESSED)) && (charinfo.Event.KeyEvent.wVirtualScanCode == 46)) break;
			if ((charinfo.Event.KeyEvent.dwControlKeyState & (SHIFT_PRESSED &~LEFT_ALT_PRESSED)) && (charinfo.Event.KeyEvent.wVirtualKeyCode == 83))
			{
				pass = false;
				break;
			}
		}
	} while (1);

	if (pass) WriteConsoleA(hOut, &c, 1, &actlen, NULL);
	else
	{
		WriteConsoleA(hOut, loginFailed, strlen(loginFailed), &actlen, NULL);
		pass = false;
	}

	//Если все комбинации введены верно - вывод приветствия
	if (pass) WriteConsoleA(hOut, loginSuccess, strlen(loginSuccess), &actlen, NULL);
	
	//Выход из приложения в случае, если вход был успешен
	if (pass)do
	{
		ReadConsoleInput(hIn, &charinfo, 1, &actlen);
		if (charinfo.EventType == KEY_EVENT)
		{
			if ((charinfo.Event.KeyEvent.dwControlKeyState & (SHIFT_PRESSED &~LEFT_ALT_PRESSED)) && (charinfo.Event.KeyEvent.wVirtualKeyCode == 83))
			{
				pass = false;
				break;
			}
		}
	} while (1);

	CloseHandle(hIn);
	CloseHandle(hOut);
	ExitProcess(0);
}

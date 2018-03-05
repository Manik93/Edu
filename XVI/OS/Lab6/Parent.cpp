/*
Фисенко П.В ЗПИ-151
Лабораторная работа №6. Вариант 9

При нажатии клавиши [A] (Условие W) программа создает дочерний процесс A.
Процесс A выводит периметры квадратов со сторонами от 1 до 20. 
При нажатии любой другой клавиши создается дочерний процесс B.
Процесс B выводит количество дней в каждом месяце года.
Программа закрывается при нажатии клавиши [ESC].
*/

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

DWORD CreationFlags;

void main()
{
	TCHAR chAName[] = L"ChildA.exe", chBName[] = L"ChildB.exe";
	char textInfo1[] = "Press [A] key to start process A, or any other key to start process B\n\r";
	char textInfo2[] = "\n\rPress [ESC] for exit\n\r";
	DWORD rc, actlen, fdwMode, fdwSaveOldMode;
	PROCESS_INFORMATION pi;
	INPUT_RECORD charinfo;	
	STARTUPINFO si;
	
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(si);
	CreationFlags = NORMAL_PRIORITY_CLASS;

	void *hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		printf("Error GetStdHandle\n"); exit(-1);
	}

	void *hIn = GetStdHandle(STD_INPUT_HANDLE);
	if (hIn == INVALID_HANDLE_VALUE)
	{
		printf("Error GetStdHandle\n"); exit(-1);
	}

	WriteConsoleA(hOut, textInfo1, sizeof(textInfo1), &actlen, NULL);

	if (!GetConsoleMode(hIn, &fdwSaveOldMode))
	{
		printf("ErrorGetConsoleMode\n"); exit(-1);
	}
	fdwMode = fdwSaveOldMode&~ENABLE_MOUSE_INPUT&~ENABLE_ECHO_INPUT;

	if (!SetConsoleMode(hIn, fdwMode))
	{
		printf("ErrorSetConsoleMode\n"); exit(-1);
	}

	
	
	do
	{	
		//Считываем ввод в консоль в бесконечном цикле
		ReadConsoleInput(hIn, &charinfo, 1, &actlen);
		//Если нажата любая клавиша
		if (charinfo.EventType == KEY_EVENT)
		{
			//и это клавиша 'A', то
			if (charinfo.Event.KeyEvent.wVirtualScanCode == 30)
			{  
				//Создаем процесс А (ChildA.exe)
				rc = CreateProcess(NULL, chAName, NULL, NULL, FALSE,
					CreationFlags, NULL, NULL, &si, &pi);
				//Если возникли проблемы при создании - выводим ошибку
				if (!rc)
				{
					printf("Error in creation process, code: %ld\n", GetLastError());
					getchar(); exit(-1);
				}
				//Выводим информацию о процессе и выходим из цикла
				printf("\n%ws process info:\n", chAName);
				printf("hProcess=%d\thThread=%d\tProcessID=%ld\tThreadID=%ld\n",
					pi.hProcess, pi.hThread, pi.dwProcessId, pi.dwThreadId);
				break;
			}
			else{//и это не клавиша 'A', то создаем процесс B (ChildB.exe)
				rc = CreateProcess(NULL, chBName, NULL, NULL, FALSE,
					CreationFlags, NULL, NULL, &si, &pi);
				//Если возникли проблемы при создании - выводим ошибку
				if (!rc)
				{
					printf("Error in creation process, code: %ld\n", GetLastError());
					getchar(); exit(-1);
				}
				//Выводим информацию о процессе и выходим из цикла
				printf("\n%ws process info:\n", chBName);
				printf("hProcess=%d\thThread=%d\tProcessID=%ld\tThreadID=%ld\n",
					pi.hProcess, pi.hThread, pi.dwProcessId, pi.dwThreadId);
				break;
			}
		}
	} while (1);

	//Выводим подсказку о выходе
	WriteConsoleA(hOut, textInfo2, sizeof(textInfo2), &actlen, NULL);

	//Ожидаем ввода клавиши ESC в бесконечном цикле. Если клавиша нажата - выходим.
	do
	{
		ReadConsoleInput(hIn, &charinfo, 1, &actlen);
		if (charinfo.EventType == KEY_EVENT && (charinfo.Event.KeyEvent.wVirtualScanCode == 1))
		{
			TerminateProcess(pi.hProcess, 0);
			break;
		}
	} while (1);

	printf("\nPress [Enter] to continue...");
	getchar();
	CloseHandle(hIn);
	CloseHandle(hOut);
	ExitProcess(0);
}
/*
Фисенко П.В ЗПИ-151
Лабораторная работа №1. Вариант 9

Программа вводит символьную строку длиной не более 20 символов,
проверяет, есть в данной строке символы цифр и выводит их количество
*/

#include "stdafx.h"
#include <Windows.h>
#include <wincon.h>
#include <stdio.h>

void main()
{
	char buffer[30] = "", numbers[11] = "1234567890", temp[4];
	int len = strlen(buffer), count = 0;
	DWORD actlen;
	HANDLE hstdin, hstdout;
	BOOL rc;

	//Организуем ввод-вывод
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hstdout == INVALID_HANDLE_VALUE)ExitProcess(0);
	hstdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hstdin == INVALID_HANDLE_VALUE)ExitProcess(0);
	//Вводим строку 
	rc = ReadFile(hstdin, buffer, 20, &actlen, NULL);
	if (!rc)ExitProcess(0);

	//Посимвольно проверяем введеную строку на соответствие 
	//с символами из строки-шаблона. 
	for (int i = 0; i < strlen(buffer) + len; ++i)
	{
		int match = 0;
		for (int j = 0; j < strlen(numbers); ++j)
		{
			if (buffer[i] == numbers[j]) {
				match = 1;
				break;
			}

		}
		//Если возникает совпадение - увеличиваем счетчик на 1, иначе - ничего не делаем.
		count += (match == 1) ? 1 : 0;
	}
	
	//Переводим число в строку и выводим в консоль
	_itoa_s(count, temp, 10);
	WriteFile(hstdout, temp, 2, &actlen, NULL);
	getchar();
	ExitProcess(0);
}
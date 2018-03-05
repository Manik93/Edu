/*
Фисенко П.В ЗПИ-151
Лабораторная работа №6. Вариант 9

Программа выводит периметры квадратов со сторонами от 1 до 20.
*/

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

void main()
{
	for (int i = 1; i <= 20; i++)
	{
		printf("\na=%d\tP=%d", i, 4 * i);
		Sleep(1000);
	}
	printf("\n\nDone!");
}
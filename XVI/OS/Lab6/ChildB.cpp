/*
Фисенко П.В ЗПИ-151
Лабораторная работа №6. Вариант 9

Программа выводит количество дней в каждом месяце года.
Високосность не учитывается.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void main()
{
	for (int i = 1; i <= 12; i++)
	{
		string month[12] = { "January, 31", "February, 28", "March, 31", "April, 30", "May, 31", "June, 30", "July, 31", "August, 31", "September, 30", "October, 31", "November, 30", "December, 31" };
		cout << "\n" + month[i - 1];
		Sleep(1000);
	}
	printf("\n\nDone!");
	ExitProcess(0);
}

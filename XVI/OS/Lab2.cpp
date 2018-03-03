/*
Фисенко П.В ЗПИ-151
Лабораторная работа №2. Вариант 9

Программа поочередно переписывает целые числа из двух файлов в один.
Запись прекращается, если достигнут конец хотя бы одного файла.
*/

#include "stdafx.h"
#include <windows.h>
#include <iostream>

using namespace std;

void main()
{
	char temp_a[] = "", temp_b[] = "", buff[128] = "";
	HANDLE hFile1, hFile2, hFileRes;
	DWORD actlen_a, actlen_b;
	BOOL rc_a, rc_b;
	int i = 0;

	//Создаем и проверяем файлы
	hFileRes = CreateFile(L"result.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFileRes == NULL) ExitProcess(0);
	hFile1 = CreateFile(L"file1.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile1 == NULL) ExitProcess(0);
	hFile2 = CreateFile(L"file2.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile2 == NULL) ExitProcess(0);

	//Выполняем цикл до тех пор, пока не получим ошибку считывания
	do	{

		//Считываем по 1 байту в каждой итерации
		rc_a = ReadFile(hFile1, &temp_a, 1, &actlen_a, NULL);
		rc_b = ReadFile(hFile2, &temp_b, 1, &actlen_b, NULL);

		//Если количество считанных байт = 0, то это конец файла.
		//Записываем собранный массив в файл и выходим из цикла.
		if ((actlen_a == 0) || (actlen_b == 0)) {
			cout << buff << "\nEOF!";
			WriteFile(hFileRes, buff, sizeof(buff), &actlen_a, NULL);
			break;
		}

		//Если количество считанных байт > 0, то собираем новый массив из 2х старых.
		buff[i] = temp_a[0];
		buff[++i] = temp_b[0];
		i++;

	} while ((rc_a) || (rc_b));

	CloseHandle(hFile1);
	CloseHandle(hFile2);
	CloseHandle(hFileRes);
	getchar();
	ExitProcess(0);
}
/*
������� �.� ���-151
������������ ������ �3. ������� 9

��������� ������� ����������� �Hello, World� ������� ����� 
� ����������� ��������� ������ �������� ��� � �����.
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
 
    //�������� ����� �������
	void *hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    //������� ����������� ����� � ������� �� ��������� ������� �������
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

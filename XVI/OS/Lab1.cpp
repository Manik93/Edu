/*
��������� ������ ���������� ������ ������ �� ����� 20 ��������,
���������, ���� � ������ ������ ������� ���� � ������� �� ����������
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

	//���������� ����-�����
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hstdout == INVALID_HANDLE_VALUE)ExitProcess(0);
	hstdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hstdin == INVALID_HANDLE_VALUE)ExitProcess(0);
	//������ ������ 
	rc = ReadFile(hstdin, buffer, 20, &actlen, NULL);
	if (!rc)ExitProcess(0);

	//����������� ��������� �������� ������ �� ������������ 
	//� ��������� �� ������-�������. 
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
		//���� ��������� ���������� - ����������� ������� �� 1, ����� - ������ �� ������.
		count += (match == 1) ? 1 : 0;
	}
	
	//��������� ����� � ������ � ������� � �������
	_itoa_s(count, temp, 10);
	WriteFile(hstdout, temp, 2, &actlen, NULL);
	getchar();
	ExitProcess(0);
}
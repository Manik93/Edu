/*
������� �.� ���-151
������������ ������ �2. ������� 9

��������� ���������� ������������ ����� ����� �� ���� ������ � ����.
������ ������������, ���� ��������� ����� ���� �� ������ �����.
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

	//������� � ��������� �����
	hFileRes = CreateFile(L"result.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFileRes == NULL) ExitProcess(0);
	hFile1 = CreateFile(L"file1.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile1 == NULL) ExitProcess(0);
	hFile2 = CreateFile(L"file2.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile2 == NULL) ExitProcess(0);

	//��������� ���� �� ��� ���, ���� �� ������� ������ ����������
	do	{

		//��������� �� 1 ����� � ������ ��������
		rc_a = ReadFile(hFile1, &temp_a, 1, &actlen_a, NULL);
		rc_b = ReadFile(hFile2, &temp_b, 1, &actlen_b, NULL);

		//���� ���������� ��������� ���� = 0, �� ��� ����� �����.
		//���������� ��������� ������ � ���� � ������� �� �����.
		if ((actlen_a == 0) || (actlen_b == 0)) {
			cout << buff << "\nEOF!";
			WriteFile(hFileRes, buff, sizeof(buff), &actlen_a, NULL);
			break;
		}

		//���� ���������� ��������� ���� > 0, �� �������� ����� ������ �� 2� ������.
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
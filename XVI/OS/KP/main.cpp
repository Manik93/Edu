/*
����������� ���������, ������� ������� � ��������� ������ ��������� ������ � �� N ����� �����
� ��������� �� -999 �� 999  ������� �� ����� ��� �����. �������� � ����� ��������� ������� 
������������ ����� �������� ����� T, N � T �������� ������������� �� ������� ��������. 
������ �������������� ����� ������� �������� � � �, ����������� ����������� � �������, 
��������� ������. ��� ������ ������� ���������� ����� ������ � ��������� ����, ������ ����� 
� ���� ����.

���������� ������ ���������� ���� ���� ��������� �������

����������� � ����� �����, ���������� �������� �������
*/

#include "Form1.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyProject::Form1 Form;
	Application::Run(%Form);
}
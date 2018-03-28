/*
Разработать программу, которая создает в отдельном потоке случайный массив А из N целых чисел
в диапазоне от -999 до 999  выводит на экран эти числа. Создание и вывод элементов массива 
производится через заданное время T, N и T вводятся пользователем до запуска процесса. 
Массив обрабатывается двумя другими потоками В и С. Все потоки выводят результаты своей работы в текстовые окна, каждый поток 
в свое окно.

B) Вычисление общего количества цифр всех элементов массива

C) Определение и вывод чисел, являющихся простыми числами
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
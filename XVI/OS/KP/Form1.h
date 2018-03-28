#pragma once

#include <time.h>
#include <cstdlib>
#include <string>

namespace MyProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:
		String^ buffer = "";
		int elemCount, numbCount, tCounter;
		static Random^ random = gcnew Random();

	private: System::Windows::Forms::TextBox^  elemCountInput;
	private: System::Windows::Forms::ProgressBar^  mThreadPBar;
	private: System::Windows::Forms::DataGridView^  simpleNumb;
	private: System::Windows::Forms::Label^  elemCountLabel;
	private: System::Windows::Forms::Label^  timeLabel;
	private: System::Windows::Forms::TextBox^  timeInput;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  numbCountOutput;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::BackgroundWorker^  bgWorker;
	private: System::Windows::Forms::Button^  fillBtn;
	private: System::Windows::Forms::DataGridView^  mainThread;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private:System::ComponentModel::Container ^components;

	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->bgWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->fillBtn = (gcnew System::Windows::Forms::Button());
			this->mainThread = (gcnew System::Windows::Forms::DataGridView());
			this->elemCountInput = (gcnew System::Windows::Forms::TextBox());
			this->mThreadPBar = (gcnew System::Windows::Forms::ProgressBar());
			this->simpleNumb = (gcnew System::Windows::Forms::DataGridView());
			this->elemCountLabel = (gcnew System::Windows::Forms::Label());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->timeInput = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numbCountOutput = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainThread))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->simpleNumb))->BeginInit();
			this->SuspendLayout();
			// 
			// bgWorker
			// 
			this->bgWorker->WorkerReportsProgress = true;
			this->bgWorker->WorkerSupportsCancellation = true;
			this->bgWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::bgWorker_DoWork);
			this->bgWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Form1::bgWorker_ProgressChanged);
			this->bgWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::bgWorker_RunWorkerCompleted);
			// 
			// fillBtn
			// 
			this->fillBtn->Location = System::Drawing::Point(619, 158);
			this->fillBtn->Name = L"fillBtn";
			this->fillBtn->Size = System::Drawing::Size(124, 23);
			this->fillBtn->TabIndex = 0;
			this->fillBtn->Text = L"Выполнить";
			this->fillBtn->UseVisualStyleBackColor = true;
			this->fillBtn->Click += gcnew System::EventHandler(this, &Form1::fillBtn_Click);
			// 
			// mainThread
			// 
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->mainThread->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle3;
			this->mainThread->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCellsExceptHeader;
			this->mainThread->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->mainThread->ColumnHeadersVisible = false;
			this->mainThread->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->mainThread->Location = System::Drawing::Point(12, 38);
			this->mainThread->Name = L"mainThread";
			this->mainThread->RowHeadersVisible = false;
			this->mainThread->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
			this->mainThread->RowTemplate->Height = 15;
			this->mainThread->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->mainThread->Size = System::Drawing::Size(311, 309);
			this->mainThread->TabIndex = 2;
			// 
			// elemCountInput
			// 
			this->elemCountInput->Location = System::Drawing::Point(619, 54);
			this->elemCountInput->MaxLength = 6;
			this->elemCountInput->Name = L"elemCountInput";
			this->elemCountInput->Size = System::Drawing::Size(53, 20);
			this->elemCountInput->TabIndex = 3;
			this->elemCountInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::elemCountInput_KeyPress);
			// 
			// mThreadPBar
			// 
			this->mThreadPBar->Location = System::Drawing::Point(12, 351);
			this->mThreadPBar->Name = L"mThreadPBar";
			this->mThreadPBar->Size = System::Drawing::Size(598, 16);
			this->mThreadPBar->Step = 1;
			this->mThreadPBar->TabIndex = 4;
			// 
			// simpleNumb
			// 
			this->simpleNumb->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCellsExceptHeader;
			this->simpleNumb->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->simpleNumb->ColumnHeadersVisible = false;
			this->simpleNumb->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->simpleNumb->Location = System::Drawing::Point(329, 38);
			this->simpleNumb->Name = L"simpleNumb";
			this->simpleNumb->RowHeadersVisible = false;
			this->simpleNumb->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
			this->simpleNumb->RowTemplate->Height = 15;
			this->simpleNumb->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->simpleNumb->Size = System::Drawing::Size(281, 309);
			this->simpleNumb->TabIndex = 5;
			// 
			// elemCountLabel
			// 
			this->elemCountLabel->AutoSize = true;
			this->elemCountLabel->Location = System::Drawing::Point(616, 38);
			this->elemCountLabel->Name = L"elemCountLabel";
			this->elemCountLabel->Size = System::Drawing::Size(127, 13);
			this->elemCountLabel->TabIndex = 6;
			this->elemCountLabel->Text = L"Количество элементов:";
			// 
			// timeLabel
			// 
			this->timeLabel->AutoSize = true;
			this->timeLabel->Location = System::Drawing::Point(616, 77);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(131, 13);
			this->timeLabel->TabIndex = 7;
			this->timeLabel->Text = L"Время задержки (мсек):";
			// 
			// timeInput
			// 
			this->timeInput->Location = System::Drawing::Point(619, 93);
			this->timeInput->MaxLength = 4;
			this->timeInput->Name = L"timeInput";
			this->timeInput->Size = System::Drawing::Size(34, 20);
			this->timeInput->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(616, 116);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Количество цифр:";
			// 
			// numbCountOutput
			// 
			this->numbCountOutput->Location = System::Drawing::Point(619, 132);
			this->numbCountOutput->MaxLength = 8;
			this->numbCountOutput->Name = L"numbCountOutput";
			this->numbCountOutput->ReadOnly = true;
			this->numbCountOutput->Size = System::Drawing::Size(53, 20);
			this->numbCountOutput->TabIndex = 10;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(619, 187);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(124, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Отмена";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(619, 345);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(124, 23);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Выход";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(8, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 20);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Все числа:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(325, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 20);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Простые числа:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(753, 379);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numbCountOutput);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->timeInput);
			this->Controls->Add(this->timeLabel);
			this->Controls->Add(this->elemCountLabel);
			this->Controls->Add(this->simpleNumb);
			this->Controls->Add(this->mThreadPBar);
			this->Controls->Add(this->elemCountInput);
			this->Controls->Add(this->mainThread);
			this->Controls->Add(this->fillBtn);
			this->Name = L"Form1";
			this->Text = L"КП Операционные системы (Вариант 9)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainThread))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->simpleNumb))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void ctor() {
				 this->InitializeComponent();
	}

			 //Проверка на простоту числа
	public:	 bool isPrime(int p) {
				 if (p < 2) return false;
				 if (p == 2) return true;
				 if (p % 2 == 0) return false;
				 double limit = sqrt(p);
				 for (int i = 3; i <= limit; i += 2) {
					 if ((p % i) == 0) return false;
				 }
				 return true;
	}

			 //Подсчет количества цифр
	public:	 int countr(array<String^, 2>^ arr, int d){
				 String^ numbers = "1234567890";
				 int numbCounter = 0;

				 for (int i = 0; i < d / 10 + 1; i++)
				 {
					 for (int j = 0; j < 10; j++)
					 {
						 //Если элемент матрицы не пустой
						 if (arr[i, j] != nullptr)
						 {
							 buffer = arr[i, j];
							 for (int _i = 0; _i < buffer->Length; ++_i) 
							 {
								 for (int _j = 0; _j <= numbers->Length; ++_j)
								 {
									 if (buffer[_i].Equals(L'-')) break;
									 if (buffer[_i] == numbers[_j]) 
									 {
										 numbCounter++;
										 break;
									 }
								 }
							 }
						 }
					 }
				 }
				 return numbCounter;
				 }

			 //Сжатие массива. Удаление элементов, равных нулю
	public:	 array<String^, 2 >^ delNulls(array<String^, 2>^ arr){

				 array<String^, 2 >^ A = gcnew array<String^, 2 >(elemCount / 10 + 1, 10); 
				 int _i = 0, _j = 0;

				 for (int i = 0; i < elemCount / 10 + 1; i++){
					 for (int j = 0; j < 10; j++){

						 if (arr[i, j] != nullptr){
							 A[_i, _j] = arr[i, j];
							 _j++;
							}
						 if (_j == 10) break;
						}
					 if (_j == 10) {
						 _j = 0;
						 _i++;
					 }
					 
					}
		return A;
	}


		 //Контроль ввода (только цифры)
private: System::Void elemCountInput_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08){
				 e->Handled = true;
			 }
}

		 //Запуск процесса
private: System::Void fillBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Если фоновый процесс запущен, то игнорируем нажатие
			 if (!bgWorker->IsBusy){
				 //Инициализируем переменные, меняем свойства объектов
				 mainThread->Columns->Clear();
				 simpleNumb->Columns->Clear();
				 if (elemCountInput->Text == "") elemCountInput->Text = "10";
				 if (timeInput->Text == "") timeInput->Text = "100";
				 elemCount = Convert::ToInt32(elemCountInput->Text);
				 mThreadPBar->Maximum = elemCount;
				 fillBtn->Enabled = false;
				 //Рапускаем фоновый поток
				 bgWorker->RunWorkerAsync();
			 }		
}

		 //Выполнение фоновой работы
private: System::Void bgWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 
			 //Объявляем переменные
			 String^ numbers = "1234567890";
			 int numbCount = 0;

			 //Создаём массив для простых чисел
			 array<String^, 2 >^ prime = gcnew array<String^, 2 >(elemCount / 10 + 1, 10);

			 //Создаём массив для остальных чисел
			 array<String^, 2 >^ notPrime = gcnew array<String^, 2 >(elemCount / 10 + 1, 10);

			 for (int i = 0; i < elemCount / 10 + 1; i++){
				 //Выполняем работу, пока не поступит сигнал отмены или она не будет завершена
				 if (!bgWorker->CancellationPending)
				 {
					 for (int j = 0; j < 10; j++){

						 //Генерируем число
						 int tNumb = rand() % 1998 - 999;

						 //Распределяем числа по массивам
						 if (isPrime(tNumb))
						 {
							 prime[i, j] = Convert::ToString(tNumb);
						 }
						 else
						 {
							 notPrime[i, j] = Convert::ToString(tNumb);
						 }

						 //Прогресс
						 bgWorker->ReportProgress(i * 10);
					 }

					 //Задержка выполнения
					 Thread::Sleep(random->Next(Convert::ToInt32(timeInput->Text)));
				 }
				 else
				 {
					 e->Cancel = true;
					 break;
				 }
				 
			 }

			 //Сжимаем массивы, убрав нулевые элементы
			 notPrime = delNulls(notPrime);
			 prime = delNulls(prime);

			 //Получаем общее количество цифр 
			 numbCount = countr(prime, elemCount) + countr(notPrime, elemCount);

			 //Создаем контеинер
			 array<Object^, 1>^ result = gcnew array<Object^,1>(3);
			 //Сохраняем данные в массив для передачи в главный поток
			 result[0] = numbCount;
			 result[1] = prime;
			 result[2] = notPrime;
			 //Передаём данные в главный поток
			 e->Result = result;
}


		 //Прогресс выполнения
private: System::Void bgWorker_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			 mThreadPBar->Value = e->ProgressPercentage;
}

		 //Действия после отработки потока
private: System::Void bgWorker_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 //Обработка возникших ошибок
			 if (e->Error != nullptr)
			 {
				 MessageBox::Show(e->Error->Message);
			 }
			 else
			 if (e->Cancelled)
			 {
				 fillBtn->Enabled = true;
			 }
			 else
			 {
				 tCounter = elemCount;

				 //Принимаем передаваемые аргументы
				 array<Object^>^ resArr = safe_cast<array<Object^>^>(e->Result);
				 array<String^, 2>^ all = safe_cast<array<String^, 2>^>(resArr[1]);
				 array<String^, 2>^ prime = safe_cast<array<String^, 2>^>(resArr[2]);

				 //Очищаем таблицы
				 mainThread->Columns->Clear();
				 simpleNumb->Columns->Clear();

				 //Добавляем колонки
				 for (int i = 0; i < 10; i++)
				 {
					 DataGridViewTextBoxColumn^ colp = gcnew DataGridViewTextBoxColumn();
					 DataGridViewTextBoxColumn^ colnP = gcnew DataGridViewTextBoxColumn();
					 mainThread->Columns->Add(colp);
					 simpleNumb->Columns->Add(colnP);
				 }

				 //Заполняем таблицу
				 for (int i = 0; i < elemCount / 10 + 1; i++)
				 {
					 //Если нехватает ряда для ввода данные - добавляем его
					 if (mainThread->RowCount < elemCount / 10 + 1) mainThread->Rows->Add();
					 if (simpleNumb->RowCount < elemCount / 10 + 1) simpleNumb->Rows->Add();
					 //Если остаток от деления на 10 (число столбцов) больше 0, то заполняем текущий ряд
					 //и отнимаем от общего числа генерируемых элементов количество созданных
					 if (tCounter / 10 > 0) 
					 {
						 for (int j = 0; j < 10; j++)
						 {
							 mainThread->Rows[i]->Cells[j]->Value = prime[i, j];
							 simpleNumb->Rows[i]->Cells[j]->Value = all[i, j];
						 }
						 tCounter -= 10;
					 }
					 //Если остаток от деления равен 0, то заполняем текущий ряд элементами
					 else
					 {
						 for (int j = 0; j < tCounter; j++)
						 {
							 mainThread->Rows[i]->Cells[j]->Value = prime[i, j];
							 simpleNumb->Rows[i]->Cells[j]->Value = all[i, j];
						 }
						 }
					 }
				 numbCountOutput->Text = Convert::ToString(resArr[0]);
				 fillBtn->Enabled = true;
				 }
			 }

		 //Выход из приложения
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}

		 //Отмена выполнения фонового потока
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 bgWorker->CancelAsync();
			 mainThread->Columns->Clear();
			 simpleNumb->Columns->Clear();
			 numbCountOutput->Text = "";
			 mThreadPBar->Value = 0;
}
};
}

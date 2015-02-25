#pragma once
#include <sstream>
#include <string>
#include <stdlib.h>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

namespace calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtNum1;
	protected: 
	private: System::Windows::Forms::TextBox^  txtNum2;
	private: System::Windows::Forms::TextBox^  txtResults;
	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::Button^  btnSubtract;
	private: System::Windows::Forms::Button^  btnMultiply;
	private: System::Windows::Forms::Button^  btnDivide;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtNum1 = (gcnew System::Windows::Forms::TextBox());
			this->txtNum2 = (gcnew System::Windows::Forms::TextBox());
			this->txtResults = (gcnew System::Windows::Forms::TextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnSubtract = (gcnew System::Windows::Forms::Button());
			this->btnMultiply = (gcnew System::Windows::Forms::Button());
			this->btnDivide = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtNum1
			// 
			this->txtNum1->Location = System::Drawing::Point(11, 14);
			this->txtNum1->Name = L"txtNum1";
			this->txtNum1->Size = System::Drawing::Size(242, 20);
			this->txtNum1->TabIndex = 0;
			// 
			// txtNum2
			// 
			this->txtNum2->Location = System::Drawing::Point(12, 40);
			this->txtNum2->Name = L"txtNum2";
			this->txtNum2->Size = System::Drawing::Size(241, 20);
			this->txtNum2->TabIndex = 1;
			// 
			// txtResults
			// 
			this->txtResults->Location = System::Drawing::Point(12, 91);
			this->txtResults->Name = L"txtResults";
			this->txtResults->Size = System::Drawing::Size(241, 20);
			this->txtResults->TabIndex = 2;
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(12, 66);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(56, 19);
			this->btnAdd->TabIndex = 3;
			this->btnAdd->Text = L"+";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Form1::btn_Click);
			// 
			// btnSubtract
			// 
			this->btnSubtract->Location = System::Drawing::Point(74, 66);
			this->btnSubtract->Name = L"btnSubtract";
			this->btnSubtract->Size = System::Drawing::Size(58, 19);
			this->btnSubtract->TabIndex = 4;
			this->btnSubtract->Text = L"-";
			this->btnSubtract->UseVisualStyleBackColor = true;
			this->btnSubtract->Click += gcnew System::EventHandler(this, &Form1::btn_Click);
			// 
			// btnMultiply
			// 
			this->btnMultiply->Location = System::Drawing::Point(138, 66);
			this->btnMultiply->Name = L"btnMultiply";
			this->btnMultiply->Size = System::Drawing::Size(54, 19);
			this->btnMultiply->TabIndex = 5;
			this->btnMultiply->Text = L"x";
			this->btnMultiply->UseVisualStyleBackColor = true;
			this->btnMultiply->Click += gcnew System::EventHandler(this, &Form1::btn_Click);
			// 
			// btnDivide
			// 
			this->btnDivide->Location = System::Drawing::Point(198, 66);
			this->btnDivide->Name = L"btnDivide";
			this->btnDivide->Size = System::Drawing::Size(55, 19);
			this->btnDivide->TabIndex = 6;
			this->btnDivide->Text = L"÷";
			this->btnDivide->UseVisualStyleBackColor = true;
			this->btnDivide->Click += gcnew System::EventHandler(this, &Form1::btn_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(265, 131);
			this->Controls->Add(this->btnDivide);
			this->Controls->Add(this->btnMultiply);
			this->Controls->Add(this->btnSubtract);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->txtResults);
			this->Controls->Add(this->txtNum2);
			this->Controls->Add(this->txtNum1);
			this->Name = L"Form1";
			this->Text = L"Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_Click(System::Object^  sender, System::EventArgs^  e) {
			      string strNum1 = marshal_as<string>(this->txtNum1->Text);
				  string strNum2 = marshal_as<string>(this->txtNum2->Text);
				  double dblNum1 = atof(strNum1.c_str());
				  double dblNum2 = atof(strNum2.c_str());
				  double dblResults;
				  if (sender == this->btnAdd) dblResults = dblNum1 + dblNum2;
				  if (sender == this->btnSubtract) dblResults = dblNum1 - dblNum2;
				  if (sender == this->btnMultiply) dblResults = dblNum1 * dblNum2;
				  if (sender == this->btnDivide) dblResults = dblNum1 / dblNum2;
				  this->txtResults->Text = dblResults.ToString();
			 
			 }
};
}


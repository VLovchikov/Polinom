#pragma once
#include "Polinom.h"
#include "Polinom.cpp"
#include "MonomList.h"
#include "MonomList.cpp"
std::string strnull="";
std::string str1;
std::string str2;
std::string outstr1;
std::string strtotal;


namespace Pollinom_Form {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button4;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(281, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(13, 96);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(281, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(12, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Polinom A";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Polinom B";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(19, 155);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(32, 29);
			this->button1->TabIndex = 4;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(72, 155);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(32, 29);
			this->button2->TabIndex = 5;
			this->button2->Text = L"-";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(126, 155);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(32, 29);
			this->button3->TabIndex = 6;
			this->button3->Text = L"*";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 225);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Answer:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(16, 252);
			this->label4->MaximumSize = System::Drawing::Size(300, 13);
			this->label4->MinimumSize = System::Drawing::Size(450, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(450, 13);
			this->label4->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(355, 42);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(20, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"X=";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(355, 77);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Y=";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(355, 107);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(20, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Z=";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(381, 39);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(39, 20);
			this->textBox3->TabIndex = 12;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(381, 73);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(39, 20);
			this->textBox4->TabIndex = 13;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(381, 104);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(39, 20);
			this->textBox5->TabIndex = 14;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(330, 171);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(34, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Total:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(370, 171);
			this->label9->MinimumSize = System::Drawing::Size(50, 13);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(50, 13);
			this->label9->TabIndex = 16;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(358, 130);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Calculate";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 295);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
    private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		label4->Text = gcnew String(strnull.c_str());
		int len1 = textBox1->Text->Length;
		str1.resize(len1);
		for (int i = 0; i < len1; i++)
		{
			str1[i] = textBox1->Text[i];
		}
		int len2 = textBox2->Text->Length;
		str2.resize(len2);
		for (int i = 0; i < len2; i++)
		{
			str2[i] = textBox2->Text[i];
		}
		Polinom A(str1);
		Polinom B(str2);
		A + B;
		str1 = "";
		str2 = "";
		outstr1=A.ReverseConvert();
		label4->Text = gcnew String(outstr1.c_str());
		outstr1 = "";
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	label4->Text = gcnew String(strnull.c_str());
	int len1 = textBox1->Text->Length;
	str1.resize(len1);
	for (int i = 0; i < len1; i++)
	{
		str1[i] = textBox1->Text[i];
	}
	int len2 = textBox2->Text->Length;
	str2.resize(len2);
	for (int i = 0; i < len2; i++)
	{
		str2[i] = textBox2->Text[i];
	}
	Polinom A(str1);
	Polinom B(str2);
	A - B;
	outstr1 = A.ReverseConvert();
	label4->Text = gcnew String(outstr1.c_str());
	outstr1 = "";
	str1 = "";
	str2 = "";
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	label4->Text = gcnew String(strnull.c_str());
	int len1 = textBox1->Text->Length;
	str1.resize(len1);
	for (int i = 0; i < len1; i++)
	{
		str1[i] = textBox1->Text[i];
	}
	int len2 = textBox2->Text->Length;
	str2.resize(len2);
	for (int i = 0; i < len2; i++)
	{
		str2[i] = textBox2->Text[i];
	}
	Polinom A(str1);
	Polinom B(str2);
	A * B;
	outstr1 = A.ReverseConvert();
	label4->Text = gcnew String(outstr1.c_str());
	outstr1 = "";
	str1 = "";
	str2 = "";
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
{
	double x;
	double y;
	double z;
	x = Convert::ToDouble(textBox3->Text);
	y = Convert::ToDouble(textBox4->Text);
	z = Convert::ToDouble(textBox5->Text);
	int len3 = label4->Text->Length;
	strtotal.resize(len3);
	for (int i = 0; i < len3; i++)
	{
		strtotal[i] = label4->Text[i];
	}
	Polinom A(strtotal);
	double tot;
	
	try
	{
		tot = A.Calculate(x, y, z);
	}
	catch (...)
	{
		string ss = "Error Calculating";
		label9->Text = gcnew String(ss.c_str());
		return;
	}
	label9->Text = gcnew String(Convert::ToString(tot));
}
};
}

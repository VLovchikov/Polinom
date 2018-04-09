#pragma once
#include "MyForm.h" 

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(cli::array<String^>^ args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Pollinom_Form::MyForm form;
	Application::Run(%form);
};
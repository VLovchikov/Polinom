#pragma once
#include "MyForm.h" 
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;
using namespace Pollinom_Form; 

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew MyForm());
	return 0;
}
#include "stdafx.h"
#include "MyForm.h"

using namespace  LuccME;

[STAThreadAttribute]
int main(void)
{
	//Guive to Windows the control of the forms styles
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//Call the main form
	LuccME::MyForm^ myForm1 = gcnew LuccME::MyForm();
	Application::Run(myForm1);
}
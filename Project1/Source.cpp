#include "stdafx.h"
#include "MyForm.h"

using namespace  CellFulfill;

[STAThreadAttribute]
int main(void)
{
	//Guive to Windows the control of the forms styles
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//Call the main form
	CellFulfill::MyForm^ myForm1 = gcnew CellFulfill::MyForm();
	Application::Run(myForm1);
}
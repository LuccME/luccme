#include "stdafx.h"
#include "MyForm.h"

using namespace  LuccME;

[STAThreadAttribute]
int main(void)
{
	LuccME::MyForm^ myForm1 = gcnew LuccME::MyForm();
	Application::Run(myForm1);
}
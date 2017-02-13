#include "stdafx.h"
#include "AboutForm.h"

System::Void CellFulfill::AboutForm::AboutForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		this->Text = "About";
		lProgram->Text = "CellFulfill Model Manager";
		lCompatible->Text = "Compatible with CellFulfill";
		lVersion->Text = "Version 2.8";
		lCopyright->Text = "Copyright © 2016. All rigths reserved.";
	}
	else {
		this->Text = "Sobre";
		lProgram->Text = "Gerenciador de Modelos CellFulfill";
		lCompatible->Text = "Compatível com CellFulfill";
		lVersion->Text = "Versão 2.8";
		lCopyright->Text = "Copyright © 2016. Todos os direitos reservados.";
	}
}

System::Void CellFulfill::AboutForm::linkLabel1_LinkClicked(System::Object ^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs ^ e)
{
	linkLabel1->LinkVisited = true;
	System::Diagnostics::Process::Start("http://CellFulfill.ccst.inpe.br/");
}

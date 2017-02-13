#include "stdafx.h"
#include "AboutForm.h"

System::Void CellFulfill::AboutForm::AboutForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		this->Text = "About";
		lProgram->Text = "CellFill Scripts Manager";
		lCompatible->Text = "Compatible with LuccME 3.0";
		lVersion->Text = "Version 1.0";
		lCopyright->Text = "Copyright © 2017. All rigths reserved.";
	}
	else {
		this->Text = "Sobre";
		lProgram->Text = "Gerenciador de Scripts de Preenchimento de Célula";
		lCompatible->Text = "Compatível com LuccME 3.0";
		lVersion->Text = "Versão 1.0";
		lCopyright->Text = "Copyright © 2017. Todos os direitos reservados.";
	}
}

System::Void CellFulfill::AboutForm::linkLabel1_LinkClicked(System::Object ^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs ^ e)
{
	linkLabel1->LinkVisited = true;
	System::Diagnostics::Process::Start("http://luccme.ccst.inpe.br/");
}

System::Void CellFulfill::AboutForm::linkLabel2_LinkClicked(System::Object ^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs ^ e)
{
	linkLabel2->LinkVisited = true;
	System::Diagnostics::Process::Start("https://github.com/TerraME/terrame");
}

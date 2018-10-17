#include "stdafx.h"
#include "AboutForm.h"

System::Void CellFulfill::AboutForm::AboutForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		this->Text = "About";
		lProgram->Text = "CellFill Scripts Manager";
		lCompatible->Text = "Compatible with LuccME and INPE-EM 3.X";
		lVersion->Text = "Version 2.1.1";
		lCopyright->Text = "Copyright © 2018. All rigths reserved.";
	}
	else {
		this->Text = "Sobre";
		lProgram->Text = "Gerenciador de Scripts de Preenchimento de Células";
		lCompatible->Text = "Compatível com LuccME e INPE-EM 3.X";
		lVersion->Text = "Versão 2.1.1";
		lCopyright->Text = "Copyright © 2018. Todos os direitos reservados.";
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

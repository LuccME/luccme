#include "stdafx.h"
#include "AboutForm.h"

System::Void LuccME::AboutForm::AboutForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		this->Text = "About";
		lProgram->Text = "LuccME Model Manager";
		lCompatible->Text = "Compatible with LuccME 2.1";
		lVersion->Text = "Version 1.1";
		lCopyright->Text = "Copyright © 2015. All rigths reserved.";
	}
	else {
		this->Text = "Sobre";
		lProgram->Text = "Gerenciador de Modelos LuccME";
		lCompatible->Text = "Compatível com LuccME 2.1";
		lVersion->Text = "Versão 1.1";
		lCopyright->Text = "Copyright © 2015. Todos os direitos reservados.";
	}
}

System::Void LuccME::AboutForm::linkLabel1_LinkClicked(System::Object ^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs ^ e)
{

	linkLabel1->LinkVisited = true;
	System::Diagnostics::Process::Start("http://luccme.ccst.inpe.br/");
}

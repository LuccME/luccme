#include "stdafx.h"
#include "MyForm.h"
#include "NovoModelo.h"
#include "LanguageForm.h"
#include "AboutForm.h"

using namespace LuccME;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

System::Void LuccME::MyForm::bNovoModelo_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LuccME::NovoModelo^ novoModelo = gcnew LuccME::NovoModelo(lLanguage, false, 0);
	this->Visible = false;
	novoModelo->ShowDialog();
	try {
		this->Visible = true;
	} catch (ObjectDisposedException^) {
		Application::Exit();
	}
	lLanguage = novoModelo->lLanguage;
	checkLanguage();
	MyForm::Update();
	if (novoModelo->lReturn == NEWMODEL) {
		bNovoModelo_Click(sender, e);
	}
	if (novoModelo->lReturn == OPENMODEL) {
		bAbrirModelo_Click(sender, e);
	}
}

System::Void LuccME::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	checkLanguage();
	this->Visible = true;
}

System::Void LuccME::MyForm::checkLanguage()
{
	String^ fileName = "language.dat";
	try {
		StreamReader^ din = File::OpenText(fileName);
		lLanguage = din->ReadLine();
		din->Close();
	}
	catch (Exception^)
	{
		lLanguage = DEFAULTLANGUAGE;
	}
	
	if (lLanguage == "en") {
		this->Text = "LuccME - Model Manager";
		bNovoModelo->Text = "New Model";
		bAbrirModelo->Text = "Open Model";
		arquivoToolStripMenuItem->Text = "File";
		novoToolStripMenuItem->Text = "New";
		abrirToolStripMenuItem->Text = "Open";
		sairToolStripMenuItem->Text = "Exit";
		preferênciasToolStripMenuItem->Text = "Preferences";
		idiomaToolStripMenuItem->Text = "Language";
		ajudaToolStripMenuItem->Text = "Help";
		sobreToolStripMenuItem->Text = "About";
	}
	else {
		this->Text = "LuccME - Gerenciador de Modelos";
		bNovoModelo->Text = "Novo Modelo";
		bAbrirModelo->Text = "Abrir Modelo";
		arquivoToolStripMenuItem->Text = "Arquivo";
		novoToolStripMenuItem->Text = "Novo";
		abrirToolStripMenuItem->Text = "Abrir";
		sairToolStripMenuItem->Text = "Sair";
		preferênciasToolStripMenuItem->Text = "Preferências";
		idiomaToolStripMenuItem->Text = "Idioma";
		ajudaToolStripMenuItem->Text = "Ajuda";
		sobreToolStripMenuItem->Text = "Sobre";
	}
}

System::Void LuccME::MyForm::idiomaToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LanguageForm^ languageForm = gcnew LanguageForm(lLanguage);
	languageForm->ShowInTaskbar = false;
	languageForm->MinimizeBox = false;
	languageForm->MaximizeBox = false;
	languageForm->ShowDialog();
	lLanguage = languageForm->lLanguage;
	checkLanguage();
	MyForm::Update();
}

System::Void LuccME::MyForm::sairToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Close();
}

System::Void LuccME::MyForm::sobreToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AboutForm^ aboutForm = gcnew AboutForm(lLanguage);
	aboutForm->ShowInTaskbar = false;
	aboutForm->ShowDialog();
}

System::Void LuccME::MyForm::bAbrirModelo_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LuccME::NovoModelo^ novoModelo = gcnew LuccME::NovoModelo(lLanguage, true, 0);
	this->Visible = false;
	novoModelo->ShowDialog();
	try {
		this->Visible = true;
	}
	catch (ObjectDisposedException^) {
		Application::Exit();
	}
	lLanguage = novoModelo->lLanguage;
	checkLanguage();
	MyForm::Update();
	if (novoModelo->lReturn == NEWMODEL) {
		bNovoModelo_Click(sender, e);
	}
	if (novoModelo->lReturn == OPENMODEL) {
		bAbrirModelo_Click(sender, e);
	}
}

System::Void LuccME::MyForm::luccMEToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		Help::ShowHelp(this, "help.chm");
	}
	else {
		Help::ShowHelp(this, "ajuda.chm");
	}
}

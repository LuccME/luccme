#include "stdafx.h"
#include "MyForm.h"
#include "NovoModelo.h"
#include "LanguageForm.h"
#include "AboutForm.h"

using namespace CellFulfill;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

System::Void CellFulfill::MyForm::bNovoModelo_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	CellFulfill::NovoModelo^ novoModelo = gcnew CellFulfill::NovoModelo(lLanguage, false, 0);
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
	if (novoModelo->lReturn == NEWSCRIPT) {
		bNovoModelo_Click(sender, e);
	}
	if (novoModelo->lReturn == OPENSCRIPT) {
		bAbrirModelo_Click(sender, e);
	}
}

System::Void CellFulfill::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	checkLanguage();
	this->Visible = true;
}

System::Void CellFulfill::MyForm::checkLanguage()
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
		this->Text = "Cell Fulfill - Script Manager";
		bNovoModelo->Text = "New Script";
		bAbrirModelo->Text = "Open Script";
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
		this->Text = "Preenchimento de Células - Gerenciador de Scripts";
		bNovoModelo->Text = "Novo Script";
		bAbrirModelo->Text = "Abrir Script";
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

System::Void CellFulfill::MyForm::idiomaToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
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

System::Void CellFulfill::MyForm::sairToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Close();
}

System::Void CellFulfill::MyForm::sobreToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AboutForm^ aboutForm = gcnew AboutForm(lLanguage);
	aboutForm->ShowInTaskbar = false;
	aboutForm->ShowDialog();
}

System::Void CellFulfill::MyForm::bAbrirModelo_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	CellFulfill::NovoModelo^ novoModelo = gcnew CellFulfill::NovoModelo(lLanguage, true, 0);
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
	if (novoModelo->lReturn == NEWSCRIPT) {
		bNovoModelo_Click(sender, e);
	}
	if (novoModelo->lReturn == OPENSCRIPT) {
		bAbrirModelo_Click(sender, e);
	}
}

System::Void CellFulfill::MyForm::CellFulfillToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		Help::ShowHelp(this, "help.chm");
	}
	else {
		Help::ShowHelp(this, "ajuda.chm");
	}
}

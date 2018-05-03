#include "stdafx.h"
#include "D_ExternalModel.h"

System::Void LuccME::D_ExternalModel::D_ExternalModel_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		this->Text = "Demand - External Model";
		bSalvar->Text = "Save";
		lFile->Text = "   File";
		bFile->Text = "Select";
		bSalvar->Text = "Save";
		gSExternalFileTitle = "Select Model File";
		gSExternalFileFilter = "Lua File (*.lua)|*.lua";
	}
	else {
		this->Text = "Demanda - Modelo Externo";
		bSalvar->Text = "Salvar";
		lFile->Text = "Arquivo";
		bFile->Text = "Selecionar";
		bSalvar->Text = "Salvar";
		gSExternalFileTitle = "Selecione o arquivo do Modelo";
		gSExternalFileFilter = "Arquivo Lua (*.lua)|*.lua";
	}

	//tbSelectedFile->ReadOnly = true;
	
	tbSelectedFile->Enabled = false;
	tbSelectedFile->ForeColor = System::Drawing::Color::Black;
	tbSelectedFile->BackColor = System::Drawing::Color::White;

	if (lReturn->Return != "") {
		tbSelectedFile->Text = lReturn->Return;
	}
}

System::Void LuccME::D_ExternalModel::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	lReturn->Return = tbSelectedFile->Lines[0];
	this->Close();
}

System::Void LuccME::D_ExternalModel::bFile_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Open the dialog to select the shape file and return the path
	LuccME::OpenFileDialog^ bdFile = gcnew OpenFileDialog;
	bdFile->Title = gSExternalFileTitle;
	bdFile->Multiselect = false;
	bdFile->Filter = gSExternalFileFilter;
	bdFile->FilterIndex = 1;
	bdFile->ShowHelp = true;

	if (bdFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		tbSelectedFile->Text = bdFile->FileName;
	}
}
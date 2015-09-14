#include "stdafx.h"
#include "LanguageForm.h"

System::Void LuccME::LanguageForm::LanguageForm_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		bSelectLanguage->Text = "Select";
		rLEn->Checked = true;
	}
	else {
		bSelectLanguage->Text = "Selecionar";
		rLBr->Checked = true;
	}
}

System::Void LuccME::LanguageForm::bSelectLanguage_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (rLEn->Checked == true) {
		lLanguage = "en";
	}
	else {
		lLanguage = "br";
	}

	String^ fileName = "language.dat";
	System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(fileName);
	sw->WriteLine(lLanguage);
	sw->Close();

	this->Close();
}


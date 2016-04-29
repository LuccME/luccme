#include "stdafx.h"
#include "P_MaxEntLike.h"

System::Void LuccME::P_MaxEntLike::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	//Create the efect of a edited TextBox (must select this function on focus->enter property of a TextBox)
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void LuccME::P_MaxEntLike::P_MaxEntLike_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		bSalvar->Text = "Save";
		gSAttributes = "Attributes";
		lAttrPerc->Text = "Attributes (Range)";
		lAttrClass->Text = "Attributes (Categorical)";
	}
	else {
		bSalvar->Text = "Salvar";
		gSAttributes = "Atributos";
		lAttrPerc->Text = "Atributos (Range)";
		lAttrClass->Text = "Atributos (Categóricos)";
	}
}
#include "stdafx.h"
#include "A_ABSO.h"

System::Void LuccME::A_ABSO::tMAxDifference_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	if (tMAxDifference->ForeColor != System::Drawing::Color::Black) {
		tMAxDifference->Text = "";
		tMAxDifference->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void LuccME::A_ABSO::bSalvar_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	tMAxDifference->Text = tMAxDifference->Text->Replace("\r","");
	tMAxDifference->Text = tMAxDifference->Text->Replace("\t", "");
	lReturn->Return = tMAxDifference->Text;
	this->Close();
}

System::Void LuccME::A_ABSO::A_ABSO_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Allocation - Simple Ordering";
		bSalvar->Text = "Save";
		lMaxDiffHelp->Text = "Absolute Value";
	}
	else {
		this->Text = "Aloca��o - Simple Ordering";
		bSalvar->Text = "Salvar";
		lMaxDiffHelp->Text = "Valor Absoluto";
	}
	
	if (lReturn->Return != "") {
		tMAxDifference->Text = lReturn->Return;
		tMAxDifference->ForeColor = System::Drawing::Color::Black;
	}
}

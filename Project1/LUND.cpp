#include "stdafx.h"
#include "LUND.h"

System::Void LuccME::LUND::LUND_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Land Use No Data Management";
		bSelect->Text = "Select";
		gSLUT = "Land Use Types";
	}
	else {
		this->Text = "Gerenciar Uso da Terra com No Data";
		bSelect->Text = "Selecionar";
		gSLUT = "Tipos de Uso da Terra";
	}

	this->lvLUT->View = View::Details;
	this->lvLUT->GridLines = true;
	this->lvLUT->Columns->Add(gSLUT, lvLUT->Width - 5, HorizontalAlignment::Left);
	if (this->lReturn->Return->Length > 0) {
		String^ aux = "";
		for (int i = 0; i < this->lReturn->Return->Length; i++) {
			if (this->lReturn->Return[i] != '\"') {
				if (this->lReturn->Return[i] == ',') {
					this->lvLUT->Items->Add(aux);
					aux = "";
				}
				else if (this->lReturn->Return[i] != ',')
				{
					aux += this->lReturn->Return[i];
				}
			}
		}
		if (aux != "") {
			this->lvLUT->Items->Add(aux);
			aux = "";
		}
	}
}

System::Void LuccME::LUND::bSelect_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	lReturn->Return = "";
	String^ selected = "";
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		if (lvLUT->Items[i]->Selected) {
			selected = lvLUT->Items[i]->Text;
		}
	}
	if (selected != "") {
		lReturn->Return = "\"" + selected + "\"";
	}
	close = true;
	LuccME::Form::Close();
}

System::Void LuccME::LUND::LUND_FormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e)
{
	if (!close) {
		lReturn->Return = "";
	}
}

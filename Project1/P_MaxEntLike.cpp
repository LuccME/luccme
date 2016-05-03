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
	initializeForm();

	if (lReturn->Language == "en") {
		bSalvar->Text = "Save";
		gSAttributes = "Attributes";
		lAttrPerc->Text = "Attributes (Range)";
		lAttrClass->Text = "Attributes (Categorical)";
		lUsePerc->Text = "% of Use to be a sample";
		gSEmptyUsePerc = "The use precent to be a sample must be fulfilled.";
		gSEmptyUsePercTitle = "Erro - Missing use precentage";
		gSEmptyDG = "At least one attribute must be informed.";
		gSEmptyDGTitle = "Error - Missing attributes";
		gSLUT = "Land Use Types";
	}
	else {
		bSalvar->Text = "Salvar";
		gSAttributes = "Atributos";
		lAttrPerc->Text = "Atributos (Range)";
		lAttrClass->Text = "Atributos (Categóricos)";
		lUsePerc->Text = "% Uso a ser considerado amostra";
		gSEmptyUsePerc = "A porcentagem do uso deve ser preenchido.";
		gSEmptyUsePercTitle = "Erro - Porcentagem de uso";
		gSEmptyDG = "Pelo menos um atributo deve ser informado.";
		gSEmptyDGTitle = "Error - Atributos";
		gSLUT = "Tipos de Uso da Terra";
	}

	this->lvLUT->View = View::Details;
	this->lvLUT->GridLines = true;
	this->lvLUT->Columns->Add(gSLUT, lvLUT->Width - 52, HorizontalAlignment::Left);

	if (this->lReturn->LUT->Length > 0) {
		String^ aux = "";
		for (int i = 0; i < this->lReturn->LUT->Length; i++) {
			if (this->lReturn->LUT[i] != '\"') {
				if (this->lReturn->LUT[i] == ',') {
					this->lvLUT->Items->Add(aux);
					aux = "";
				}
				else if (this->lReturn->LUT[i] != ',')
				{
					aux += this->lReturn->LUT[i];
				}
			}
		}
		if (aux != "") {
			this->lvLUT->Items->Add(aux);
			aux = "";
		}
	}

	this->lvLUT->Columns->Add("Status", 47, HorizontalAlignment::Left);

	// Coping the data from the NovoModeloForm
	if (this->lReturn->Return != "") {
		int rowCount = 0;
		for (int i = 0; i < this->lReturn->Return->Length; i++) {
			if (this->lReturn->Return[i] != '#') {
				lTempAttr[rowCount] += this->lReturn->Return[i];
			}
			else {
				lvLUT->Items[rowCount]->SubItems->Add("OK");
				rowCount++;
			}
		}
		if (lTempAttr[rowCount] != "") {
			lvLUT->Items[rowCount]->SubItems->Add("OK");
		}
	}
}

System::Void LuccME::P_MaxEntLike::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;

	lReturn->Return = "";

	if (tUsePerc->Text == "")
	{
		MessageBox::Show(gSEmptyUsePerc, gSEmptyUsePercTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = false;
	}
	else if (dgAttrPerc->Rows->Count == 1 && dgAttrClass->Rows->Count == 1)
	{
		MessageBox::Show(gSEmptyDG, gSEmptyDGTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = false;
	}

	if (check) {
		for (int i = 0; i < lTempAttr->Length; i++) {
			if (lTempAttr[i] == nullptr) {
				break;
			}
			lReturn->Return += lTempAttr[i] + "#";
		}
	}
	
	this->Close();
}

System::Void LuccME::P_MaxEntLike::bAddBetas_Click(System::Object^  sender, System::EventArgs^  e)
{
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		if (lvLUT->Items[i]->Selected == true) {
			lTempAttr[i] = "";

			lTempAttr[i] += tUsePerc->Text + ";";

			for (int j = 0; j < dgAttrPerc->Rows->Count; j++) {
				if (dgAttrPerc->Rows[j]->Cells[0]->Value != nullptr) {
					lTempAttr[i] += "\"";
					lTempAttr[i] += dgAttrPerc->Rows[j]->Cells[0]->Value;
					if (dgAttrPerc->Rows[j + 1]->Cells[0]->Value != nullptr) {
						lTempAttr[i] += "\",";
					}
					else {
						lTempAttr[i] += "\"";
					}
				}
			}

			lTempAttr[i] += "*";

			for (int j = 0; j < dgAttrClass->Rows->Count; j++) {
				if (dgAttrClass->Rows[j]->Cells[0]->Value != nullptr) {
					lTempAttr[i] += "\"";
					lTempAttr[i] += dgAttrClass->Rows[j]->Cells[0]->Value;
					if (dgAttrClass->Rows[j + 1]->Cells[0]->Value != nullptr) {
						lTempAttr[i] += "\",";
					}
					else {
						lTempAttr[i] += "\"";
					}
				}
			}

			lTempAttr[i] += "*";
			lvLUT->Items[i]->SubItems->Add("OK");
		}
	}
	
	lvLUT->Visible = true;
	bSalvar->Visible = true;
	tLUT->Visible = false;
	lUsePerc->Visible = false;
	tUsePerc->Visible = false;
	lAttrPerc->Visible = false;
	dgAttrPerc->Visible = false;
	lAttrClass->Visible = false;
	dgAttrClass->Visible = false;
	bAddBetas->Visible = false;
}

System::Void LuccME::P_MaxEntLike::lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	initializeForm();

	if (bAddBetas->Visible == false) {
		for (int i = 0; i < lvLUT->Items->Count; i++) {
			if (lvLUT->Items[i]->Selected == true) {
				tLUT->Text = lvLUT->Items[i]->Text;
				tLUT->ReadOnly = true;
				tLUT->Visible = true;
				lvLUT->Visible = false;

				if (lTempAttr[i] != nullptr) {
					setData(lTempAttr[i]);
				}
			}
		}

		bSalvar->Visible = false;
		lUsePerc->Visible = true;
		tUsePerc->Visible = true;
		lAttrPerc->Visible = true;
		dgAttrPerc->Visible = true;
		lAttrClass->Visible = true;
		dgAttrClass->Visible = true;
		bAddBetas->Visible = true;
	}
}

System::Void LuccME::P_MaxEntLike::setData(String^ dataSource)
{
	int j = 0;
	String^ tempAttr = "";


	tUsePerc->Text = "";

	while (dataSource[j] != ';')
	{
		tUsePerc->Text += dataSource[j];
		j++;
	}

	j++;
	while (dataSource[j] != '*')
	{
		if (dataSource[j] != ',') {
			if (dataSource[j] != '\"') {
				tempAttr += dataSource[j];
			}
		}
		else {
			dgAttrPerc->Rows->Add(tempAttr);
			tempAttr = "";
		}
		j++;
	}

	if (tempAttr != "") {
		dgAttrPerc->Rows->Add(tempAttr);
	}


	j++;
	tempAttr = "";

	while (dataSource[j] != '*')
	{
		if (dataSource[j] != ',') {
			if (dataSource[j] != '\"') {
				tempAttr += dataSource[j];
			}
		}
		else {
			dgAttrClass->Rows->Add(tempAttr);
			tempAttr = "";
		}
		j++;
	}

	if (tempAttr != "") {
		dgAttrClass->Rows->Add(tempAttr);
	}
}

System::Void LuccME::P_MaxEntLike::initializeForm()
{
	//Added Header
	dgAttrPerc->Rows->Clear();
	dgAttrPerc->ColumnCount = 0;
	dgAttrPerc->ColumnCount = 1;
	dgAttrPerc->Columns[0]->Name = gSAttributes;
	dgAttrPerc->Columns[0]->Width = 160;

	//Added Header
	dgAttrClass->Rows->Clear();
	dgAttrClass->ColumnCount = 0;
	dgAttrClass->ColumnCount = 1;
	dgAttrClass->Columns[0]->Name = gSAttributes;
	dgAttrClass->Columns[0]->Width = 160;
	
	if (lReturn->Component == DMAXENTLIKE) {
		tUsePerc->Text = "100";
		tUsePerc->Enabled = false;
	}
	else {
		tUsePerc->Text = "75";
		tUsePerc->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
}
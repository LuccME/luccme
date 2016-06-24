#include "stdafx.h"
#include "P_MaxEntLike.h"

using namespace System::Windows::Forms;

System::Void LuccME::P_MaxEntLike::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	//Create the efect of a edited TextBox (must select this function on focus->enter property of a TextBox)
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

/*
Locate the initial cell for copying or pasting
*/
System::Windows::Forms::DataGridViewCell ^ LuccME::P_MaxEntLike::GetStartCell(System::Windows::Forms::DataGridView ^ dgAttr)
{
	//get the smallest row,column index
	if (dgAttr->SelectedCells->Count == NONE)
		return nullptr;

	int rowIndex = dgAttr->Rows->Count - 1;
	int colIndex = dgAttr->Columns->Count - 1;

	for each(DataGridViewCell^ dgvCell in dgAttr->SelectedCells)
	{
		if (dgvCell->RowIndex < rowIndex)
			rowIndex = dgvCell->RowIndex;
		if (dgvCell->ColumnIndex < colIndex)
			colIndex = dgvCell->ColumnIndex;
	}

	return dgAttr[colIndex, rowIndex];
}

/*
Copy the clipboard data
*/
System::Void LuccME::P_MaxEntLike::CopyToClipboard(DataGridView^ dgAttr)
{
	DataObject^ dataObj = dgAttr->GetClipboardContent();
	if (dataObj != nullptr) {
		Clipboard::SetDataObject(dataObj);
	}
}


/*
Paste the clipboard data
*/
System::Void LuccME::P_MaxEntLike::PasteClipboardValue(DataGridView^ dgAttr)
{
	//Show Error if no cell is selected
	if (dgAttr->SelectedCells->Count == NONE)
	{
		MessageBox::Show(gSPaste, gSPasteTitle, MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	//Get the satring Cell
	DataGridViewCell^ startCell = GetStartCell(dgAttr);

	//Get the clipboard value in a dictionary
	String^ aux = Clipboard::GetText();

	if (aux != "") {
		array<String^>^ lines = aux->Split('\n');

		if (dgAttr->RowCount < lines->Length - 1) {
			while (dgAttr->RowCount < lines->Length) {
				dgAttr->Rows->Add();
			}
		}
		
		
		for (int i = 0; i < lines->Length - 1; i++) {
			dgAttr->Rows[i]->Cells[0]->Value = lines[i];
		}
	}
}

/*
Used to set the data from lReturn->Return to the form
*/
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
	while (dataSource[j] != ';')
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

	while (j < dataSource->Length)
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

/*
Initialized for the default values
*/
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

/*
Capture the keys press
*/
System::Void LuccME::P_MaxEntLike::dgAttr_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
	DataGridView^ dgAttr = (DataGridView^)sender;
	try
	{
		if (e->Modifiers == Keys::Control)
		{
			switch (e->KeyCode)
			{
			case Keys::C:
				CopyToClipboard(dgAttr);
				break;

			case Keys::V:
				PasteClipboardValue(dgAttr);
				break;
			}
		}
		else {
			switch (e->KeyCode)
			{
			case Keys::Delete:
				if (dgAttr->SelectedCells->Count != NONE)
				{
					DataGridViewCell^ startCell = GetStartCell(dgAttr);
					int row = startCell->RowIndex;
					
					for (int i = row; i < dgAttr->RowCount; i++) {
						if (dgAttr->Rows[i]->Cells[0]->Selected) {
							dgAttr->Rows[i]->Cells[0]->Value = "";
						}
					}
				}
			}
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(gSCopyPaste + ex->Message, gSCopyPasteTitle, MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
		gSCopyPasteTitle = "Copy/Paste";
		gSCopyPaste = "Copy/paste operation failed. ";
		gSPasteTitle = "Paste";
		gSPaste = "Please select a cell";
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
		gSCopyPasteTitle = "Copiar/Colar";
		gSCopyPaste = "Operação de Copiar/Colar falhou. ";
		gSPasteTitle = "Colar";
		gSPaste = "Selecione uma célula";
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
		dgAttrPerc->CurrentCell = nullptr;
		dgAttrClass->CurrentCell = nullptr;
	}
}

System::Void LuccME::P_MaxEntLike::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	lReturn->Return = "";

	for (int i = 0; i < lTempAttr->Length; i++) {
		if (lTempAttr[i] == nullptr) {
			break;
		}
		lReturn->Return += lTempAttr[i] + "#";
	}
	
	this->Close();
}

System::Void LuccME::P_MaxEntLike::bAddBetas_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;

	if (tUsePerc->Text == "")
	{
		MessageBox::Show(gSEmptyUsePerc, gSEmptyUsePercTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = false;
	}

	if (check) {
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

				lTempAttr[i] += ";";

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

				lvLUT->Items[i]->SubItems->Add("OK");
				lvLUT->Items[i]->Selected = false;
			}
		}

		tLUT->Visible = false;
		lUsePerc->Visible = false;
		tUsePerc->Visible = false;
		lAttrPerc->Visible = false;
		dgAttrPerc->Visible = false;
		lAttrClass->Visible = false;
		dgAttrClass->Visible = false;
		bAddBetas->Visible = false;
		lvLUT->Visible = true;
		bSalvar->Visible = true;
	}
}

System::Void LuccME::P_MaxEntLike::lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	initializeForm();
	dgAttrPerc->CurrentCell = nullptr;
	dgAttrClass->CurrentCell = nullptr;

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

System::Void LuccME::P_MaxEntLike::copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	CopyToClipboard(dgAttrPerc);
}

System::Void LuccME::P_MaxEntLike::pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	PasteClipboardValue(dgAttrPerc);
}

System::Void LuccME::P_MaxEntLike::toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	CopyToClipboard(dgAttrClass);
}

System::Void LuccME::P_MaxEntLike::toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	PasteClipboardValue(dgAttrClass);
}

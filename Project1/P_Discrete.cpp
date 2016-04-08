#include "stdafx.h"
#include "P_Discrete.h"

System::Void LuccME::P_Discrete::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void LuccME::P_Discrete::P_Discrete_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		bAddBetas->Text = "Add";
		bCancel->Text = "Cancel";
		bSalvar->Text = "Save";
		gSLUT = "Land Use Types";
		gSValues = "Values";
		gSEmptyComponent = "The data of the component must be fulfilled.";
		gSEmptyComponentTitle = "Component data missing";
		copyToolStripMenuItem->Text = "Copy";
		pasteToolStripMenuItem->Text = "Paste";
		gSEmptyBetaTitle = "Beta data missing";
		gSEmptyBeta = "The data of the beta must be fulfilled.";
	}
	else {
		bAddBetas->Text = "Adicionar";
		bCancel->Text = "Cancelar";
		bSalvar->Text = "Salvar";
		gSLUT = "Tipos de Uso da Terra";
		gSValues = "Valores";
		gSEmptyComponent = "Os dados do componente devem ser preenchidos.";
		gSEmptyComponentTitle = "Faltando preencher os dados";
		copyToolStripMenuItem->Text = "Copiar";
		pasteToolStripMenuItem->Text = "Colar";
		gSEmptyBetaTitle = "Faltando preencher os betas";
		gSEmptyBeta = "Os dados dos betas devem ser preenchidos.";
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

	if (this->lReturn->Component == 4) {
		this->Height = 574;
		this->lvLUT->Height = 291;
		bSalvar->Location = Point(221, 488);
		bCancel->Location = Point(263, 488);
		bAddBetas->Location = Point(367, 488);
		lBetas->Location = Point(328, 254);
		this->dgBetas->Location = Point(231,283);
		this->dgBetas->Height = this->dgBetas->Height - 40;
	}
	else if (this->lReturn->Component == 5) {
		this->Height = this->Height + 40;
		this->lvLUT->Height = this->lvLUT->Height + 40;
		bSalvar->Location = Point(221, 528);
		bCancel->Location = Point(263, 528); 
		bAddBetas->Location = Point(367, 528);
		lBetas->Location = Point(328, 294);
		this->dgBetas->Location = Point(231, 323);
		this->dgBetas->Height = this->dgBetas->Height - 40;
	}
	else {
		this->Height = 574;
		this->lvLUT->Height = 291;
		bSalvar->Location = Point(221, 488);
		bCancel->Location = Point(263, 488);
		bAddBetas->Location = Point(367, 488);
		lBetas->Location = Point(328, 214);
		this->dgBetas->Location = Point(231, 243);
		this->dgBetas->Height = 216;
	}
	
	this->lvLUT->Columns->Add("Status", 47, HorizontalAlignment::Left);

	// Coping the data from the NovoModeloForm
	if (this->lReturn->Return != "") {
		int rowCount = 0;
		for (int i = 0; i < this->lReturn->Return->Length; i++) {
			if (this->lReturn->Return[i] != '#') {
				lTempBetas[rowCount] += this->lReturn->Return[i];
			}
			else {
				lvLUT->Items[rowCount]->SubItems->Add("OK");
				rowCount++;
			}
		}
		if (lTempBetas[rowCount] != "") {
			lvLUT->Items[rowCount]->SubItems->Add("OK");
		}
	}
}

System::Void LuccME::P_Discrete::lvLUT_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (bAddBetas->Visible == false) {
		dgBetas->ColumnCount = 2;
		dgBetas->Columns[0]->Name = "Betas";
		dgBetas->Columns[1]->Name = gSValues;

		for (int i = 0; i < lvLUT->Items->Count; i++) {
			if (lvLUT->Items[i]->Selected == true) {
				tLUT->Text = lvLUT->Items[i]->Text;
				tLUT->ReadOnly = true;
				tLUT->Visible = true;
				lvLUT->Visible = false;
				if (lTempBetas[i] != nullptr) {
					int j = 0;
					String^ tempConst = "";
						
					while (lTempBetas[i][j] != ';') {
						tempConst += lTempBetas[i][j];
						j++;
					}
					j++;
						
					String^ tempElasticy = "";
					if (lReturn->Component >= 4) {
						while (lTempBetas[i][j] != ';') {
							tempElasticy += lTempBetas[i][j];
							j++;
						}
						j++;
					}

					String^ tempPNU = "";
					if (lReturn->Component == 5) {
						while (lTempBetas[i][j] != ';') {
							tempPNU += lTempBetas[i][j];
							j++;
						}
						j++;
					}
						
					String^ tempBeta = "";
					int rowCount = 0;
						
					for (int k = j; k < lTempBetas[i]->Length; k++) {
						if (lTempBetas[i][k] != '=') {
							if (lTempBetas[i][k] != ',') {
								tempBeta += lTempBetas[i][k];
							}
							else {
								dgBetas->Rows[rowCount]->Cells[1]->Value = tempBeta;
								tempBeta = "";
								rowCount++;
							}
						}
						else {
							dgBetas->Rows->Add();
							dgBetas->Rows[rowCount]->Cells[0]->Value = tempBeta;
							tempBeta = "";
						}
					}
						
					if (tempBeta != "") {
						dgBetas->Rows[rowCount]->Cells[1]->Value = tempBeta;
					}
					tConst->Text = tempConst;
					tConst->ForeColor = System::Drawing::Color::Black;
					if (lReturn->Component >= 4) {
						tElasticy->Text = tempElasticy;
						tElasticy->ForeColor = System::Drawing::Color::Black;
					}
					if (lReturn->Component == 5) {
						tPercNeighborsUse->Text = tempPNU;
						tPercNeighborsUse->ForeColor = System::Drawing::Color::Black;
					}
				}
			}
		}

		bSalvar->Visible = false;
		lConst->Visible = true;
		tConst->Visible = true;
		lBetas->Visible = true;
		dgBetas->Visible = true;
		bAddBetas->Visible = true;
		bCancel->Visible = true;

		if (lReturn->Component >= 4) {
			lElasticy->Visible = true;
			tElasticy->Visible = true;
		}

		if (lReturn->Component == 5) {
			lPercNeighborsUse->Visible = true;
			tPercNeighborsUse->Visible = true;
		}
	}
}

System::Void LuccME::P_Discrete::bCancel_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		lvLUT->Items[i]->Selected = false;
	}
	dgBetas->ColumnCount = 0;
	tConst->Text = "0.01";
	tConst->ForeColor = System::Drawing::Color::LightGray;
	lConst->Visible = false;
	tConst->Visible = false;
	lBetas->Visible = false;
	dgBetas->Visible = false;
	bAddBetas->Visible = false;
	bCancel->Visible = false;
	tLUT->Visible = false;
	lvLUT->Visible = true;
	bSalvar->Visible = true;

	if (this->lReturn->Component >= 4) {
		tElasticy->Text = "0.5";
		tElasticy->ForeColor = System::Drawing::Color::LightGray;
		lElasticy->Visible = false;
		tElasticy->Visible = false;
	}

	if (this->lReturn->Component == 5) {
		tPercNeighborsUse->Text = "0.5";
		tPercNeighborsUse->ForeColor = System::Drawing::Color::LightGray;
		lPercNeighborsUse->Visible = false;
		tPercNeighborsUse->Visible = false;
	}
}

System::Void LuccME::P_Discrete::bAddBetas_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		if (lvLUT->Items[i]->Selected == true) {
			lTempBetas[i] = "";
			lTempBetas[i] += tConst->Text->Replace(',', '.');
			lTempBetas[i] += ";";

			if (this->lReturn->Component >= 4) {
				lTempBetas[i] += tElasticy->Text->Replace(',', '.');
				lTempBetas[i] += ";";
			}
			
			if (this->lReturn->Component == 5) {
				lTempBetas[i] += tPercNeighborsUse->Text->Replace(',', '.');
				lTempBetas[i] += ";";
			}

			for (int j = 0; j < dgBetas->Rows->Count; j++) {
				if (((dgBetas->Rows[j]->Cells[0]->Value != nullptr) && (dgBetas->Rows[j]->Cells[1]->Value == nullptr))
					|| (dgBetas->Rows[j]->Cells[0]->Value == nullptr) && (dgBetas->Rows[j]->Cells[1]->Value != nullptr)) {
					MessageBox::Show(gSEmptyBeta, gSEmptyBetaTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					check = false;
					break;
				}
				if (dgBetas->Rows[j]->Cells[0]->Value != nullptr) {
					lTempBetas[i] += dgBetas->Rows[j]->Cells[0]->Value;
					lTempBetas[i] += "=";
				}
				if (dgBetas->Rows[j]->Cells[1]->Value != nullptr) {
					lTempBetas[i] += dgBetas->Rows[j]->Cells[1]->Value->ToString()->Replace(',', '.');
					if (j + 1 < dgBetas->Rows->Count) {
						if (dgBetas->Rows[j+1]->Cells[0]->Value != nullptr) {
							lTempBetas[i] += ",";
						}
					}
				}
			}

			if (check) {
				lvLUT->Items[i]->SubItems->Add("OK");
			}
			break;
		}
	}

	if (check) {
		for (int i = 0; i < lvLUT->Items->Count; i++) {
			lvLUT->Items[i]->Selected = false;
		}

		dgBetas->ColumnCount = 0;
		tConst->Text = "0.01";
		tConst->ForeColor = System::Drawing::Color::LightGray;
		tConst->Visible = false;
		bSalvar->Visible = true;
		lConst->Visible = false;
		lBetas->Visible = false;
		dgBetas->Visible = false;
		bAddBetas->Visible = false;
		bCancel->Visible = false;
		tLUT->Visible = false;
		lvLUT->Visible = true;

		if (this->lReturn->Component >= 4) {
			tElasticy->Text = "0.5";
			tElasticy->ForeColor = System::Drawing::Color::LightGray;
			lElasticy->Visible = false;
			tElasticy->Visible = false;
		}

		if (this->lReturn->Component == 5) {
			tPercNeighborsUse->Text = "0.5";
			tPercNeighborsUse->ForeColor = System::Drawing::Color::LightGray;
			lPercNeighborsUse->Visible = false;
			tPercNeighborsUse->Visible = false;
		}
	}
}

System::Void LuccME::P_Discrete::bSalvar_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		if (lvLUT->Items[i]->SubItems->Count <= 1) {
			check = false;
			break;
		}
	}
	
	lReturn->Return = "";

	if (check) {
		for (int i = 0; i < lvLUT->Items->Count; i++) {
			this->lReturn->Return += lTempBetas[i];
			if (i + 1 < lvLUT->Items->Count) {
				this->lReturn->Return = this->lReturn->Return->Replace("\n", "");
				this->lReturn->Return = this->lReturn->Return->Replace("\r", "");
				this->lReturn->Return += "#";
			}
		}
		this->Close();
	}
	else {
		MessageBox::Show(gSEmptyComponent, gSEmptyComponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Windows::Forms::DataGridViewCell ^ LuccME::P_Discrete::GetStartCell(System::Windows::Forms::DataGridView ^ dgView)
{
	//get the smallest row,column index
	if (dgView->SelectedCells->Count == 0)
		return nullptr;

	int rowIndex = dgView->Rows->Count - 1;
	int colIndex = dgView->Columns->Count - 2;

	for each(DataGridViewCell^ dgvCell in dgView->SelectedCells)
	{
		if (dgvCell->RowIndex < rowIndex)
			rowIndex = dgvCell->RowIndex;
		if (dgvCell->ColumnIndex < colIndex)
			colIndex = dgvCell->ColumnIndex;
	}

	return dgView[colIndex, rowIndex];
}

System::Void LuccME::P_Discrete::dgBetas_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
	try
	{
		if (e->Modifiers == Keys::Control)
		{
			switch (e->KeyCode)
			{
			case Keys::C:
				CopyToClipboard();
				break;

			case Keys::V:
				PasteClipboardValue();
				break;
			}
		}
		else {
			switch (e->KeyCode)
			{
			case Keys::Delete:
				if (dgBetas->SelectedCells->Count != 0)
				{
					DataGridViewCell^ startCell = GetStartCell(dgBetas);
					int row = startCell->RowIndex;
					int column = startCell->ColumnIndex;
					for (int i = row; i < dgBetas->RowCount; i++) {
						for (int j = column; j < dgBetas->ColumnCount; j++) {
							if (dgBetas->Rows[i]->Cells[j]->Selected == true) {
								dgBetas->Rows[i]->Cells[j]->Value = "";
							}
						}
					}
				}
				break;
			}
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Copy/paste operation failed. " + ex->Message, "Copy/Paste", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void LuccME::P_Discrete::CopyToClipboard()
{
	//Copy to clipboard
	DataObject^ dataObj = dgBetas->GetClipboardContent();
	if (dataObj != nullptr) {
		Clipboard::SetDataObject(dataObj);
	}
}

System::Void LuccME::P_Discrete::PasteClipboardValue()
{
	//Show Error if no cell is selected
	if (dgBetas->SelectedCells->Count == 0)
	{
		MessageBox::Show("Please select a cell", "Paste", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	//Get the satring Cell
	DataGridViewCell^ startCell = GetStartCell(dgBetas);

	//Get the clipboard value in a dictionary
	String^ aux = Clipboard::GetText();

	if (aux != "") {
		array<String^>^ lines = aux->Split('\n');
		array<String^>^ tempColumns = lines[0]->Split('\t');
		array<String^>^ content = gcnew array<String^>((lines->Length - 1) * (tempColumns->Length));

		int count = 0;
		for (int i = 0; i < lines->Length - 1; i++) {
			array<String^>^ temp = lines[i]->Split('\t');
			for (int j = 0; j < temp->Length; j++) {
				content[count] = temp[j];
				count++;
			}
		}

		int row = startCell->RowIndex;
		int column = startCell->ColumnIndex;
		int columnNumber = tempColumns->Length - 1;

		if (tempColumns->Length == 2) {
			if ((content->Length / dgBetas->ColumnCount) > dgBetas->RowCount) {
				dgBetas->RowCount = content->Length / dgBetas->ColumnCount + 1;
			}
		}
		else {
			if (content->Length > dgBetas->RowCount) {
				dgBetas->RowCount = content->Length + 1;
			}
		}


		for (int i = 0; i < content->Length; i++) {
			dgBetas->Rows[row]->Cells[column]->Value = content[i];
			column++;
			if (column > columnNumber) {
				row++;
				column = startCell->ColumnIndex;
			}
		}
	}
}

System::Void LuccME::P_Discrete::copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	CopyToClipboard();
}

System::Void LuccME::P_Discrete::pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	PasteClipboardValue();
}
#include "stdafx.h"
#include "P_Continuous.h"

System::Void LuccME::P_Continuous::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void LuccME::P_Continuous::P_Continuous_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		bAddBetas->Text = "Add";
		bCancel->Text = "Cancel";
		bSalvar->Text = "Save";
		gSLUT = "Land Use Types";
		gSValues = "Values";
		gSEmptyComponent = "The data of the component must be fulfilled.";
		gSEmptyComponentTitle = "Component data missing";
	}
	else {
		bAddBetas->Text = "Adicionar";
		bCancel->Text = "Cancelar";
		bSalvar->Text = "Salvar";
		gSLUT = "Tipos de Uso da Terra";
		gSValues = "Valores";
		gSEmptyComponent = "Os dados do componente devem ser preenchidos.";
		gSEmptyComponentTitle = "Faltando preencher os dados";
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

	if (this->lReturn->Component == 7) {
		this->Height = 645;
		this->lvLUT->Height = 371;
		bSalvar->Location = Point(221, 568);
		bCancel->Location = Point(263, 568);
		bAddBetas->Location = Point(367, 568);
		lBetas->Location = Point(328, 334);
		this->dgBetas->Location = Point(231, 363);
		this->dgBetas->Height = this->dgBetas->Height - 80;
	}
	else {
		this->Height = 605;
		this->lvLUT->Height = 351;
		bSalvar->Location = Point(219, 526);
		bCancel->Location = Point(261, 526);
		bAddBetas->Location = Point(365, 526);
		lBetas->Location = Point(328, 228);
		this->dgBetas->Location = Point(231, 257);
		this->dgBetas->Height = 246;
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

System::Void LuccME::P_Continuous::lvLUT_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
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
					bool isLog = false;
					if (lTempBetas[i][0] == '1') {
						isLog = true;
					}
					int j = 2;
					String^ tempConst = "";
					while (lTempBetas[i][j] != ';') {
						tempConst += lTempBetas[i][j];
						j++;
					}
					j++;

					String^ tempMinReg = "";
					String^ tempMaxReg = "";
					String^ tempRo = "";
					if (lReturn->Component == 7) {
						while (lTempBetas[i][j] != ';') {
							tempMinReg += lTempBetas[i][j];
							j++;
						}
						j++;
						while (lTempBetas[i][j] != ';') {
							tempMaxReg += lTempBetas[i][j];
							j++;
						}
						j++;
						while (lTempBetas[i][j] != ';') {
							tempRo += lTempBetas[i][j];
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
					cIsLog->Checked = isLog;
					tConst->Text = tempConst;
					tConst->ForeColor = System::Drawing::Color::Black;
					if (lReturn->Component == 7) {
						tMinReg->Text = tempMinReg;
						tMinReg->ForeColor = System::Drawing::Color::Black;
						tMaxReg->Text = tempMaxReg;
						tMaxReg->ForeColor = System::Drawing::Color::Black;
						tRo->Text = tempRo;
						tRo->ForeColor = System::Drawing::Color::Black;
					}
				}
			}
		}

		bSalvar->Visible = false;
		cIsLog->Visible = true;
		lConst->Visible = true;
		tConst->Visible = true;
		lBetas->Visible = true;
		dgBetas->Visible = true;
		bAddBetas->Visible = true;
		bCancel->Visible = true;
		
		if (lReturn->Component == 7) {
			lMinReg->Visible = true;
			tMinReg->Visible = true;
			lMaxReg->Visible = true;
			tMaxReg->Visible = true;
			lRo->Visible = true;
			tRo->Visible = true;
		}
	}
}

System::Void LuccME::P_Continuous::bCancel_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		lvLUT->Items[i]->Selected = false;
	}
	
	dgBetas->ColumnCount = 0;
	cIsLog->Checked = false;
	tConst->Text = "0.01";
	tConst->ForeColor = System::Drawing::Color::LightGray;
	lConst->Visible = false;
	tConst->Visible = false;
	lBetas->Visible = false;
	dgBetas->Visible = false;
	bAddBetas->Visible = false;
	bCancel->Visible = false;
	tLUT->Visible = false;
	cIsLog->Visible = false;
	lvLUT->Visible = true;
	bSalvar->Visible = true;
	
	if (lReturn->Component == 7) {
		tMinReg->Text = "0";
		tMinReg->ForeColor = System::Drawing::Color::LightGray;
		lMinReg->Visible = false;
		tMinReg->Visible = false;

		tMaxReg->Text = "1";
		tMaxReg->ForeColor = System::Drawing::Color::LightGray;
		lMaxReg->Visible = false;
		tMaxReg->Visible = false;

		tRo->Text = "0.5";
		tRo->ForeColor = System::Drawing::Color::LightGray;
		lRo->Visible = false;
		tRo->Visible = false;
	}
}

System::Void LuccME::P_Continuous::bAddBetas_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		if (lvLUT->Items[i]->Selected == true) {
			lTempBetas[i] = "";
			if (cIsLog->Checked) {
				lTempBetas[i] += "1";
				lTempBetas[i] += ";";
			}
			else {
				lTempBetas[i] += "0";
				lTempBetas[i] += ";";
			}

			lTempBetas[i] += tConst->Text;
			lTempBetas[i] += ";";

			if (this->lReturn->Component == 7) {
				lTempBetas[i] += tMinReg->Text;
				lTempBetas[i] += ";";
				lTempBetas[i] += tMaxReg->Text;
				lTempBetas[i] += ";";
				lTempBetas[i] += tRo->Text;
				lTempBetas[i] += ";";
			}

			for (int j = 0; j < dgBetas->Rows->Count; j++) {
				if (dgBetas->Rows[j]->Cells[0]->Value != nullptr) {
					lTempBetas[i] += dgBetas->Rows[j]->Cells[0]->Value;
					lTempBetas[i] += "=";
				}
				if (dgBetas->Rows[j]->Cells[1]->Value != nullptr) {
					lTempBetas[i] += dgBetas->Rows[j]->Cells[1]->Value;
					if (j + 1 < dgBetas->Rows->Count) {
						if (dgBetas->Rows[j + 1]->Cells[0]->Value != nullptr) {
							lTempBetas[i] += ",";
						}
					}
				}
			}

			lvLUT->Items[i]->SubItems->Add("OK");
			break;
		}
	}
	
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		lvLUT->Items[i]->Selected = false;
	}
	
	dgBetas->ColumnCount = 0;
	cIsLog->Checked = false;
	tConst->Text = "0.01";
	tConst->ForeColor = System::Drawing::Color::LightGray;
	tConst->Visible = false;
	lConst->Visible = false;
	lBetas->Visible = false;
	dgBetas->Visible = false;
	bAddBetas->Visible = false;
	bCancel->Visible = false;
	cIsLog->Visible = false;
	tLUT->Visible = false;
	lvLUT->Visible = true;
	bSalvar->Visible = true;

	if (this->lReturn->Component == 7) {
		tMinReg->Text = "0";
		tMinReg->ForeColor = System::Drawing::Color::LightGray;
		lMinReg->Visible = false;
		tMinReg->Visible = false;
		
		tMaxReg->Text = "1";
		tMaxReg->ForeColor = System::Drawing::Color::LightGray;
		lMaxReg->Visible = false;
		tMaxReg->Visible = false;

		tRo->Text = "0.5";
		tRo->ForeColor = System::Drawing::Color::LightGray;
		lRo->Visible = false;
		tRo->Visible = false;
	}
}

System::Void LuccME::P_Continuous::bSalvar_Click(System::Object ^ sender, System::EventArgs ^ e)
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

System::Windows::Forms::DataGridViewCell ^ LuccME::P_Continuous::GetStartCell(System::Windows::Forms::DataGridView ^ dgView)
{
	//get the smallest row,column index
	if (dgView->SelectedCells->Count == 0)
		return nullptr;

	int rowIndex = dgView->Rows->Count - 1;
	int colIndex = dgView->Columns->Count - 1;

	for each(DataGridViewCell^ dgvCell in dgView->SelectedCells)
	{
		if (dgvCell->RowIndex < rowIndex)
			rowIndex = dgvCell->RowIndex;
		if (dgvCell->ColumnIndex < colIndex)
			colIndex = dgvCell->ColumnIndex;
	}

	return dgView[colIndex, rowIndex];
}

System::Void LuccME::P_Continuous::dgBetas_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
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


System::Void LuccME::P_Continuous::CopyToClipboard()
{
	//Copy to clipboard
	DataObject^ dataObj = dgBetas->GetClipboardContent();
	if (dataObj != nullptr)
		Clipboard::SetDataObject(dataObj);
}

System::Void LuccME::P_Continuous::PasteClipboardValue()
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

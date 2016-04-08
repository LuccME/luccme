#include "stdafx.h"
#include "P_SpatialLagLinearRoads.h"

System::Void LuccME::P_SpatialLagLinearRoads::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void LuccME::P_SpatialLagLinearRoads::P_SpatialLagLinearRoads_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		bAddData->Text = "Add Data";
		bCancel->Text = "Cancel";
		bSalvar->Text = "Save";
		gSLUT = "Land Use Types";
		gSValues = "Values";
		gSAttributes = "Attributes";
		gSEmptyComponent = "The data of the component must be fulfilled.";
		gSEmptyComponentTitle = "Component data missing";
		copyToolStripMenuItem->Text = "Copy";
		copyAttr->Text = "Copy";
		copyBetasRM->Text = "Copy";
		pasteToolStripMenuItem->Text = "Paste";
		pasteAttr->Text = "Paste";
		pasteBetasRM->Text = "Paste";
		gSEmptyBetaTitle = "Beta data missing";
		gSEmptyBeta = "The beat data must be fulfilled.";
		gSEmptyBetaTitle = "Beta data missing";
		gSEmptyBetaRM = "The beta data of the Road Model must be fulfilled.";
		gSEmptyBetaRMTitle = "Beta data of Road Model missing";
	}
	else {
		bAddData->Text = "Adicionar Dados";
		bCancel->Text = "Cancelar";
		bSalvar->Text = "Salvar";
		gSLUT = "Tipos de Uso da Terra";
		gSValues = "Valores";
		gSAttributes = "Atributos";
		gSEmptyComponent = "Os dados do componente devem ser preenchidos.";
		gSEmptyComponentTitle = "Faltando preencher os dados";
		copyToolStripMenuItem->Text = "Copiar";
		copyAttr->Text = "Copiar";
		copyBetasRM->Text = "Copiar";
		pasteToolStripMenuItem->Text = "Colar";
		pasteAttr->Text = "Colar";
		pasteBetasRM->Text = "Colar";
		gSEmptyBetaTitle = "Faltando preencher os betas";
		gSEmptyBeta = "Os dados dos betas devem ser preenchidos.";
		gSEmptyBetaRMTitle = "Faltando preencher os betas do Road Model";
		gSEmptyBetaRM = "Os dados dos betas do Road Model devem ser preenchidos.";
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
	
	pbLogo1->Location = Point(58, 12);
	this->Width = 511;
}

System::Void LuccME::P_SpatialLagLinearRoads::lvLUT_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (bRoadsModel->Visible == false) {
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
					while (lTempBetas[i][j] != ';') {
						tempMinReg += lTempBetas[i][j];
						j++;
					}
					j++;

					String^ tempMaxReg = "";
					while (lTempBetas[i][j] != ';') {
						tempMaxReg += lTempBetas[i][j];
						j++;
					}
					j++;

					String^ tempRo = "";
					while (lTempBetas[i][j] != ';') {
						tempRo += lTempBetas[i][j];
						j++;
					}
					j++;

					String^ tempBeta = "";
					int rowCount = 0;

					while(lTempBetas[i][j] != '*') {
						if (lTempBetas[i][j] != '=') {
							if (lTempBetas[i][j] != ',') {
								tempBeta += lTempBetas[i][j];
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
						j++;
					}
					
					j++;
					String^ tempAttr = "";
					for (int k = j; k < lTempBetas[i]->Length; k++) {
						if (lTempBetas[i][k] != ';') {
							tempAttr += lTempBetas[i][k];
						}
						else {
							lTempAttributes[i] = tempAttr;
							lTempBetasRM[i] = lTempBetas[i]->Substring(k + 1);
							break;
						}
					}
					if (tempBeta != "") {
						dgBetas->Rows[rowCount]->Cells[1]->Value = tempBeta;
					}
					
					cIsLog->Checked = isLog;
					tConst->Text = tempConst;
					tConst->ForeColor = System::Drawing::Color::Black;
					tMinReg->Text = tempMinReg;
					tMinReg->ForeColor = System::Drawing::Color::Black;
					tMaxReg->Text = tempMaxReg;
					tMaxReg->ForeColor = System::Drawing::Color::Black;
					tRo->Text = tempRo;
					tRo->ForeColor = System::Drawing::Color::Black;
				}
			}
		}

		bAddData->Visible = false;
		dgAttr->Visible = false;
		dgBetasRM->Visible = false;
		lConstRM->Visible = false;
		tConstRM->Visible = false;
		lChangeRM->Visible = false;
		tChangeRM->Visible = false;
		bSalvar->Visible = false;

		cIsLog->Visible = true;
		lConst->Visible = true;
		tConst->Visible = true;
		lBetas->Visible = true;
		dgBetas->Visible = true;
		bRoadsModel->Visible = true;
		bCancel->Visible = true;
		lMinReg->Visible = true;
		tMinReg->Visible = true;
		lMaxReg->Visible = true;
		tMaxReg->Visible = true;
		lRo->Visible = true;
		tRo->Visible = true;
		
		pbLogo1->Location = Point(58, 12);
		this->Width = 511;
	}
}

System::Void LuccME::P_SpatialLagLinearRoads::bRoadsModel_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (bAddData->Visible == false) {
		dgAttr->ColumnCount = 1;
		dgAttr->Columns[0]->Name = gSAttributes;

		dgBetasRM->ColumnCount = 2;
		dgBetasRM->Columns[0]->Name = "Betas";
		dgBetasRM->Columns[1]->Name = gSValues;

		for (int i = 0; i < lvLUT->Items->Count; i++) {
			if (lvLUT->Items[i]->Selected == true) {
				if (lTempAttributes[i] != nullptr) {
					String^ tempAttr = "";
					for (int j = 0; j < lTempAttributes[i]->Length; j++) {
						if (lTempAttributes[i][j] != ',') {
							if (lTempAttributes[i][j] != '\"') {
								tempAttr += lTempAttributes[i][j];
							}
						}
						else {
							dgAttr->Rows->Add(tempAttr);
							tempAttr = "";
						}
					}
					if (tempAttr != "") {
						dgAttr->Rows->Add(tempAttr);
					}
				}

				if (lTempBetasRM[i] != nullptr) {
					int j = 0;

					String^ tempConstRM = "";
					while (lTempBetasRM[i][j] != ';') {
						tempConstRM += lTempBetasRM[i][j];
						j++;
					}
					j++;

					String^ tempChangeRM = "";
					while (lTempBetasRM[i][j] != ';') {
						tempChangeRM += lTempBetasRM[i][j];
						j++;
					}
					j++;

					String^ tempBetaRM = "";
					int rowCount = 0;

					while (j < lTempBetasRM[i]->Length) {
						if (lTempBetasRM[i][j] != '=') {
							if (lTempBetasRM[i][j] != ',') {
								tempBetaRM += lTempBetasRM[i][j];
							}
							else {
								dgBetasRM->Rows[rowCount]->Cells[1]->Value = tempBetaRM;
								tempBetaRM = "";
								rowCount++;
							}
						}
						else {
							dgBetasRM->Rows->Add();
							dgBetasRM->Rows[rowCount]->Cells[0]->Value = tempBetaRM;
							tempBetaRM = "";
						}
						j++;
					}
					if (tempBetaRM != "") {
						dgBetasRM->Rows[rowCount]->Cells[1]->Value = tempBetaRM;
					}

					tConstRM->Text = tempConstRM;
					tConstRM->ForeColor = System::Drawing::Color::Black;

					tChangeRM->Text = tempChangeRM;
					tChangeRM->ForeColor = System::Drawing::Color::Black;
				}
			}
		}

		bAddData->Visible = true;
		bRoadsModel->Visible = false;
		bCancel->Location = Point(385, 526);
		
		lAttributesRM->Visible = true;
		dgAttr->Visible = true;

		lBetasRM->Visible = true;
		dgBetasRM->Visible = true;
		
		lConstRM->Visible = true;
		tConstRM->Visible = true;
		
		lChangeRM->Visible = true;
		tChangeRM->Visible = true;
		
		pbLogo1->Location = Point(254, 12);
		this->Width = 904;
	}
}

System::Void LuccME::P_SpatialLagLinearRoads::bCancel_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		lvLUT->Items[i]->Selected = false;
	}

	tLUT->Visible = false;
	bCancel->Location = Point(226, 526);

	lBetas->Visible = false;
	dgBetas->ColumnCount = 0;
	dgBetas->Visible = false;

	lBetasRM->Visible = false;
	dgBetasRM->ColumnCount = 0;
	dgBetasRM->Visible = false;
	
	lAttributesRM->Visible = false;
	dgAttr->ColumnCount = 0;
	dgAttr->Visible = false;

	cIsLog->Checked = false;
	cIsLog->Visible = false;

	bRoadsModel->Visible = false;
	bCancel->Visible = false;

	tConst->Text = "0.01";
	tConst->ForeColor = System::Drawing::Color::LightGray;
	lConst->Visible = false;
	tConst->Visible = false;

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

	tConstRM->Text = "0.01";
	tConstRM->ForeColor = System::Drawing::Color::LightGray;
	lConstRM->Visible = false;
	tConstRM->Visible = false;

	tChangeRM->Text = "-1.5";
	tChangeRM->ForeColor = System::Drawing::Color::LightGray;
	lChangeRM->Visible = false;
	tChangeRM->Visible = false;

	lvLUT->Visible = true;
	bSalvar->Visible = true;

	pbLogo1->Location = Point(58, 12);
	this->Width = 511;
}

System::Void LuccME::P_SpatialLagLinearRoads::bAddData_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
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

			lTempBetas[i] += tConst->Text->Replace(',', '.');
			lTempBetas[i] += ";";
			lTempBetas[i] += tMinReg->Text->Replace(',', '.');
			lTempBetas[i] += ";";
			lTempBetas[i] += tMaxReg->Text->Replace(',', '.');
			lTempBetas[i] += ";";
			lTempBetas[i] += tRo->Text->Replace(',', '.');
			lTempBetas[i] += ";";

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
						if (dgBetas->Rows[j + 1]->Cells[0]->Value != nullptr) {
								lTempBetas[i] += ",";
						}
					}
				}
			}
			
			lTempBetas[i] += "*";

			for (int j = 0; j < dgAttr->Rows->Count; j++) {
				if (dgAttr->Rows[j]->Cells[0]->Value != nullptr) {
					lTempBetas[i] += "\"";
					lTempBetas[i] += dgAttr->Rows[j]->Cells[0]->Value;
					if (dgAttr->Rows[j + 1]->Cells[0]->Value != nullptr) {
						lTempBetas[i] += "\",";
					}
					else {
						lTempBetas[i] += "\"";
					}
				}
			}

			lTempBetas[i] += ";";
			lTempBetas[i] += tConstRM->Text->Replace(',', '.');
			lTempBetas[i] += ";";
			lTempBetas[i] += tChangeRM->Text->Replace(',', '.');
			lTempBetas[i] += ";";

			for (int j = 0; j < dgBetasRM->Rows->Count; j++) {
				if (((dgBetasRM->Rows[j]->Cells[0]->Value != nullptr) && (dgBetasRM->Rows[j]->Cells[1]->Value == nullptr))
					|| (dgBetasRM->Rows[j]->Cells[0]->Value == nullptr) && (dgBetasRM->Rows[j]->Cells[1]->Value != nullptr)) {
					MessageBox::Show(gSEmptyBetaRM, gSEmptyBetaRMTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					check = false;
					break;
				}
				if (dgBetasRM->Rows[j]->Cells[0]->Value != nullptr) {
					lTempBetas[i] += dgBetasRM->Rows[j]->Cells[0]->Value;
					lTempBetas[i] += "=";
				}
				if (dgBetasRM->Rows[j]->Cells[1]->Value != nullptr) {
					lTempBetas[i] += dgBetasRM->Rows[j]->Cells[1]->Value->ToString()->Replace(',', '.');
					if (j + 1 < dgBetasRM->Rows->Count) {
						if (dgBetasRM->Rows[j + 1]->Cells[0]->Value != nullptr) {
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

		tLUT->Visible = false;
		bCancel->Location = Point(226, 526);

		lBetas->Visible = false;
		dgBetas->ColumnCount = 0;
		dgBetas->Visible = false;

		lBetasRM->Visible = false;
		dgBetasRM->ColumnCount = 0;
		dgBetasRM->Visible = false;

		lAttributesRM->Visible = false;
		dgAttr->ColumnCount = 0;
		dgAttr->Visible = false;

		cIsLog->Checked = false;
		cIsLog->Visible = false;

		bRoadsModel->Visible = false;
		bCancel->Visible = false;

		tConst->Text = "0.01";
		tConst->ForeColor = System::Drawing::Color::LightGray;
		lConst->Visible = false;
		tConst->Visible = false;

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

		tConstRM->Text = "0.01";
		tConstRM->ForeColor = System::Drawing::Color::LightGray;
		lConstRM->Visible = false;
		tConstRM->Visible = false;

		tChangeRM->Text = "-1.5";
		tChangeRM->ForeColor = System::Drawing::Color::LightGray;
		lChangeRM->Visible = false;
		tChangeRM->Visible = false;

		lvLUT->Visible = true;
		bSalvar->Visible = true;

		pbLogo1->Location = Point(58, 12);
		this->Width = 511;
	}
}

System::Void LuccME::P_SpatialLagLinearRoads::bSalvar_Click(System::Object ^ sender, System::EventArgs ^ e)
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
				this->lReturn->Return += "#";
			}
		}
		this->Close();
	}
	else {
		MessageBox::Show(gSEmptyComponent, gSEmptyComponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Windows::Forms::DataGridViewCell ^ LuccME::P_SpatialLagLinearRoads::GetStartCell(System::Windows::Forms::DataGridView ^ dgView)
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

System::Void LuccME::P_SpatialLagLinearRoads::dgBetas_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
	try
	{
		if (e->Modifiers == Keys::Control)
		{
			switch (e->KeyCode)
			{
			case Keys::C:
				CopyToClipboard(dgBetas);
				break;

			case Keys::V:
				PasteClipboardValue(dgBetas);
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

System::Void LuccME::P_SpatialLagLinearRoads::dgAttr_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
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
				if (dgAttr->SelectedCells->Count != 0)
				{
					DataGridViewCell^ startCell = GetStartCell(dgAttr);
					int row = startCell->RowIndex;
					int column = startCell->ColumnIndex;
					for (int i = row; i < dgAttr->RowCount; i++) {
						for (int j = column; j < dgAttr->ColumnCount; j++) {
							if (dgAttr->Rows[i]->Cells[j]->Selected == true) {
								dgAttr->Rows[i]->Cells[j]->Value = "";
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

System::Void LuccME::P_SpatialLagLinearRoads::dgBetasRM_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
	try
	{
		if (e->Modifiers == Keys::Control)
		{
			switch (e->KeyCode)
			{
			case Keys::C:
				CopyToClipboard(dgBetasRM);
				break;

			case Keys::V:
				PasteClipboardValue(dgBetasRM);
				break;
			}
		}
		else {
			switch (e->KeyCode)
			{
			case Keys::Delete:
				if (dgBetasRM->SelectedCells->Count != 0)
				{
					DataGridViewCell^ startCell = GetStartCell(dgBetasRM);
					int row = startCell->RowIndex;
					int column = startCell->ColumnIndex;
					for (int i = row; i < dgBetasRM->RowCount; i++) {
						for (int j = column; j < dgBetasRM->ColumnCount; j++) {
							if (dgBetasRM->Rows[i]->Cells[j]->Selected == true) {
								dgBetasRM->Rows[i]->Cells[j]->Value = "";
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

System::Void LuccME::P_SpatialLagLinearRoads::CopyToClipboard(System::Windows::Forms::DataGridView ^ dgView)
{
	//Copy to clipboard
	DataObject^ dataObj = dgView->GetClipboardContent();
	if (dataObj != nullptr) {
		Clipboard::SetDataObject(dataObj);
	}
}

System::Void LuccME::P_SpatialLagLinearRoads::PasteClipboardValue(System::Windows::Forms::DataGridView ^ dgView)
{
	if (dgView->Name != "dgAttr") {
		//Show Error if no cell is selected
		if (dgView->SelectedCells->Count == 0)
		{
			MessageBox::Show("Please select a cell", "Paste", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		//Get the satring Cell
		DataGridViewCell^ startCell = GetStartCell(dgView);

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
				if ((content->Length / dgView->ColumnCount) > dgView->RowCount) {
					dgView->RowCount = content->Length / dgView->ColumnCount + 1;
				}
			}
			else {
				if (content->Length > dgView->RowCount) {
					dgView->RowCount = content->Length + 1;
				}
			}


			for (int i = 0; i < content->Length; i++) {
				dgView->Rows[row]->Cells[column]->Value = content[i];
				column++;
				if (column > columnNumber) {
					row++;
					column = startCell->ColumnIndex;
				}
			}
		}
	}
	else {
		//Show Error if no cell is selected
		if (dgView->SelectedCells->Count == 0)
		{
			MessageBox::Show("Please select a cell", "Paste", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		//Get the satring Cell
		DataGridViewCell^ startCell = GetStartCell(dgView);

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
			int columnNumber = tempColumns->Length;
			
			
			if (content->Length > dgView->RowCount) {
				dgView->RowCount = (content->Length/columnNumber) + 1;
			}
			
			for (int i = 0; i < content->Length; i++) {
				if (i%columnNumber == 0) {
					dgView->Rows[row]->Cells[column]->Value = content[i];
					row++;
				}
			}
		}
	}
}

System::Void LuccME::P_SpatialLagLinearRoads::copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	CopyToClipboard(dgBetas);
}

System::Void LuccME::P_SpatialLagLinearRoads::pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	PasteClipboardValue(dgBetas);
}

System::Void LuccME::P_SpatialLagLinearRoads::copyBetasRM_Click(System::Object^  sender, System::EventArgs^  e) {
	CopyToClipboard(dgBetasRM);
}

System::Void LuccME::P_SpatialLagLinearRoads::pasteBetasRM_Click(System::Object^  sender, System::EventArgs^  e) {
	PasteClipboardValue(dgBetasRM);
}

System::Void LuccME::P_SpatialLagLinearRoads::copyAttr_Click(System::Object^  sender, System::EventArgs^  e) {
	CopyToClipboard(dgAttr);
}

System::Void LuccME::P_SpatialLagLinearRoads::pasteAttr_Click(System::Object^  sender, System::EventArgs^  e) {
	PasteClipboardValue(dgAttr);
}

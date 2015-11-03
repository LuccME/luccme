#include "stdafx.h"
#include "A_Continuous.h"

System::Void LuccME::A_Continuous::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void LuccME::A_Continuous::A_Continuous_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		bSalvar->Text = "Save";
		lLegend->Text = "* -1 - Unidirectional, 0 - Bidirectional, 1 - Static";
	}
	else {
		bSalvar->Text = "Salvar";
		lLegend->Text = "* -1 - Unidirecional, 0 - Bidirecional, 1 - Estático";
	}

	if (lReturn->Return != "") {
		int j = 0;
		
		String^ maxDifference = "";
		while (lReturn->Return[j] != ';') {
			maxDifference += lReturn->Return[j];
			j++;
		}
		j++;

		String^ maxIteration = "";
		while (lReturn->Return[j] != ';') {
			maxIteration += lReturn->Return[j];
			j++;
		}
		j++;

		String^ initialElasticity = "";
		while (lReturn->Return[j] != ';') {
			initialElasticity += lReturn->Return[j];
			j++;
		}
		j++;

		String^ minElasticity = "";
		while (lReturn->Return[j] != ';') {
			minElasticity += lReturn->Return[j];
			j++;
		}
		j++;

		String^ maxElasticity = "";
		while (lReturn->Return[j] != ';') {
			maxElasticity += lReturn->Return[j];
			j++;
		}
		j++;

		String^ complementarLU = "";
		while (lReturn->Return[j] != ';') {
			complementarLU += lReturn->Return[j];
			j++;
		}
		j++;

		String^ saturationIndicator = "";
		String^ attrProtection = "";
		if (lReturn->Component == 4) {
			while (lReturn->Return[j] != ';') {
				saturationIndicator += lReturn->Return[j];
				j++;
			}
			j++;

			while (lReturn->Return[j] != ';') {
				attrProtection += lReturn->Return[j];
				j++;
			}
			j++;
		}

		tMaxDifference->Text = maxDifference;
		tMaxDifference->ForeColor = System::Drawing::Color::Black;

		tMaxIteration->Text = maxIteration;
		tMaxIteration->ForeColor = System::Drawing::Color::Black;

		tInitialElasticity->Text = initialElasticity;
		tInitialElasticity->ForeColor = System::Drawing::Color::Black;

		tMinElasticity->Text = minElasticity;
		tMinElasticity->ForeColor = System::Drawing::Color::Black;

		tMaxElasticity->Text = maxElasticity;
		tMaxElasticity->ForeColor = System::Drawing::Color::Black;

		tComplementarLU->Text = complementarLU;
		tComplementarLU->ForeColor = System::Drawing::Color::Black;
		
		if (lReturn->Component == 4) {
			tSaturationIndicator->Text = saturationIndicator;
			tSaturationIndicator->ForeColor = System::Drawing::Color::Black;

			tAttrProtection->Text = attrProtection;
			tAttrProtection->ForeColor = System::Drawing::Color::Black;
		}
		

		int count = 1;
		for (int i = 0; i < lReturn->LUT->Length; i++) {
			if (lReturn->LUT[i] == ',') {
				count++;
			}
		}

		dgAllocationData->ColumnCount = 8;
		dgAllocationData->Columns[0]->Name = "LandUseType";
		dgAllocationData->Columns[1]->Name = "static";
		dgAllocationData->Columns[2]->Name = "minValue";
		dgAllocationData->Columns[3]->Name = "maxValue";
		dgAllocationData->Columns[4]->Name = "minChange";
		dgAllocationData->Columns[5]->Name = "maxChange";
		dgAllocationData->Columns[6]->Name = "changeLimiarValue";
		dgAllocationData->Columns[7]->Name = "maxChangeAboveLimiar";

		String^ tempLUT = "";
		for (int i = 0; i < lReturn->LUT->Length; i++) {
			if (lReturn->LUT[i] != ',') {
				if (lReturn->LUT[i] != '\"') {
					tempLUT += lReturn->LUT[i];
				}
			}
			else {
				dgAllocationData->Rows->Add(tempLUT);
				tempLUT = "";
			}
		}
		if (tempLUT != "") {
			dgAllocationData->Rows->Add(tempLUT);
		}

		dgAllocationData->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;
		dgAllocationData->Columns[0]->ReadOnly = true;

		int rowCount = 0;
		int columnCount = 1;
		String^ tempValue = "";
		for (int i = j; i < lReturn->Return->Length; i++) {
			if (lReturn->Return[i] != ';') {
				if (lReturn->Return[i] != ',') {
					 tempValue += lReturn->Return[i];
				}
				else {
					dgAllocationData->Rows[rowCount]->Cells[columnCount]->Value = tempValue;
					tempValue = "";
					columnCount++;
				}
			}
			else {
				dgAllocationData->Rows[rowCount]->Cells[columnCount]->Value = tempValue;
				rowCount++;
				columnCount = 1;
				tempValue = "";
			}
		} 
		if (tempValue != "") {
			dgAllocationData->Rows[rowCount]->Cells[columnCount]->Value = tempValue;
		}
		
	} else{
		dgAllocationData->ColumnCount = 8;
		dgAllocationData->Columns[0]->Name = "LandUseType";
		dgAllocationData->Columns[1]->Name = "static*";
		dgAllocationData->Columns[2]->Name = "minValue";
		dgAllocationData->Columns[3]->Name = "maxValue";
		dgAllocationData->Columns[4]->Name = "minChange";
		dgAllocationData->Columns[5]->Name = "maxChange";
		dgAllocationData->Columns[6]->Name = "changeLimiarValue";
		dgAllocationData->Columns[7]->Name = "maxChangeAboveLimiar";

		int countRowDef = 0;
		String^ tempLUT = "";
		for (int i = 0; i < lReturn->LUT->Length; i++) {
			if (lReturn->LUT[i] != ',') {
				if (lReturn->LUT[i] != '\"') {
					tempLUT += lReturn->LUT[i];
				}
			}
			else {
				dgAllocationData->Rows->Add(tempLUT);
				dgAllocationData->Rows[countRowDef]->Cells[1]->Value = "0";
				dgAllocationData->Rows[countRowDef]->Cells[2]->Value = "0";
				dgAllocationData->Rows[countRowDef]->Cells[3]->Value = "1";
				dgAllocationData->Rows[countRowDef]->Cells[4]->Value = "0";
				dgAllocationData->Rows[countRowDef]->Cells[5]->Value = "1";
				dgAllocationData->Rows[countRowDef]->Cells[6]->Value = "1";
				dgAllocationData->Rows[countRowDef]->Cells[7]->Value = "0";
				countRowDef++;
				tempLUT = "";
			}
		}
		if (tempLUT != "") {
			dgAllocationData->Rows->Add(tempLUT);
			dgAllocationData->Rows[countRowDef]->Cells[1]->Value = "0";
			dgAllocationData->Rows[countRowDef]->Cells[2]->Value = "0";
			dgAllocationData->Rows[countRowDef]->Cells[3]->Value = "1";
			dgAllocationData->Rows[countRowDef]->Cells[4]->Value = "0";
			dgAllocationData->Rows[countRowDef]->Cells[5]->Value = "1";
			dgAllocationData->Rows[countRowDef]->Cells[6]->Value = "1";
			dgAllocationData->Rows[countRowDef]->Cells[7]->Value = "0";
		}

		for (int i = 0; i < 8; i++) {
			dgAllocationData->Columns[i]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;
		}
		dgAllocationData->Columns[0]->ReadOnly = true;
	}
	if (lReturn->Component == 4) {
		lSaturationIndicator->Visible = true;
		tSaturationIndicator->Visible = true;
		lAttrProtection->Visible = true;
		tAttrProtection->Visible = true;
	}
	else {
		lSaturationIndicator->Visible = false;
		tSaturationIndicator->Visible = false;
		lAttrProtection->Visible = false;
		tAttrProtection->Visible = false;
	}

	intialize = false;
}

System::Void LuccME::A_Continuous::bSalvar_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	lReturn->Return = "";

	lReturn->Return += tMaxDifference->Text;
	lReturn->Return += ";";
	lReturn->Return += tMaxIteration->Text;
	lReturn->Return += ";";
	lReturn->Return += tInitialElasticity->Text;
	lReturn->Return += ";";
	lReturn->Return += tMinElasticity->Text;
	lReturn->Return += ";";
	lReturn->Return += tMaxElasticity->Text;
	lReturn->Return += ";";
	lReturn->Return += tComplementarLU->Text;
	lReturn->Return += ";";
	
	if (lReturn->Component == 4) {
		lReturn->Return += tSaturationIndicator->Text;
		lReturn->Return += ";";
		lReturn->Return += tAttrProtection->Text;
		lReturn->Return += ";";
	}

	int count = 1;
	
	for (int i = 0; i < lReturn->LUT->Length; i++) {
		if (lReturn->LUT[i] == ',') {
			count++;
		}
	}
	
	for (int i = 0; i < count; i++) {
		lReturn->Return += dgAllocationData->Rows[i]->Cells[1]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAllocationData->Rows[i]->Cells[2]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAllocationData->Rows[i]->Cells[3]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAllocationData->Rows[i]->Cells[4]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAllocationData->Rows[i]->Cells[5]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAllocationData->Rows[i]->Cells[6]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAllocationData->Rows[i]->Cells[7]->Value;
		if (i + 1 < count) {
			lReturn->Return += ";";
		}
	}
	this->Close();
}

System::Windows::Forms::DataGridViewCell ^ LuccME::A_Continuous::GetStartCell(System::Windows::Forms::DataGridView ^ dgView)
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

System::Void LuccME::A_Continuous::dgAllocationData_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
	switch (e->KeyCode)
	{
		case Keys::Delete:
			if (dgAllocationData->SelectedCells->Count != 0)
			{
				DataGridViewCell^ startCell = GetStartCell(dgAllocationData);
				int row = startCell->RowIndex;
				int column = startCell->ColumnIndex;
				for (int i = row; i < dgAllocationData->RowCount; i++) {
					for (int j = column; j < dgAllocationData->ColumnCount; j++) {
						if (dgAllocationData->Rows[i]->Cells[j]->Selected == true && j != 0) {
							dgAllocationData->Rows[i]->Cells[j]->Value = "";
						}
					}
				}
			}
			break;
	}
}

System::Void LuccME::A_Continuous::dgAllocationData_CellEnter(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (!intialize) {
		DataGridViewCell^ startCell = GetStartCell(dgAllocationData);
		int row = startCell->RowIndex;
		int column = startCell->ColumnIndex;
		if (column > 0) {
			dgAllocationData->Rows[row]->Cells[column]->Style->ForeColor = System::Drawing::Color::Black;
		}
	}
}

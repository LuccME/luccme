#include "stdafx.h"
#include "A_AllocationClueSLike.h"

System::Void LuccME::A_AllocationClueSLike::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void LuccME::A_AllocationClueSLike::A_AllocationClueSLike_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Allocation - Allocation ClueS Like";
		bSalvar->Text = "Save";
		gSCells = "All the cells must be fullfilled.";
		gSCellsTitle = "Error - Empty Cells";
		lLegend->Text = "0 - Not Allowable Trasition; 1 - Allowable Transition";
	}
	else {
		this->Text = "Alocação - Allocation ClueS Like";
		bSalvar->Text = "Salvar";
		gSCells = "Todas as células devem ser preenchidas.";
		gSCellsTitle = "Erro - Células Vazias";
		lLegend->Text = "0 - Transição não Permitida; 1 - Transição Permitida";
	}

	if (lReturn->Return != "") {
		int j = 0;

		String^ tempMaxIteration = "";
		while (lReturn->Return[j] != ';') {
			tempMaxIteration += lReturn->Return[j];
			j++;
		}
		j++;

		String^ factorIteration = "";
		while (lReturn->Return[j] != ';') {
			factorIteration += lReturn->Return[j];
			j++;
		}
		j++;

		String^ tempMaxDifference = "";
		while (lReturn->Return[j] != ';') {
			tempMaxDifference += lReturn->Return[j];
			j++;
		}
		j++;

		tMaxIteration->Text = tempMaxIteration;
		tMaxIteration->ForeColor = System::Drawing::Color::Black;

		tFactorInteration->Text = factorIteration;
		tFactorInteration->ForeColor = System::Drawing::Color::Black;

		tMaxDifference->Text = tempMaxDifference;
		tMaxDifference->ForeColor = System::Drawing::Color::Black;

		String^ tempLUT = "";
		int count = 1;
		dgTransitionMatrix->ColumnCount = count;
		dgTransitionMatrix->Columns[count - 1]->Name = "->";
		count++;
		for (int i = 0; i < this->lReturn->LUT->Length; i++) {
			if (this->lReturn->LUT[i] != ',') {
				if (this->lReturn->LUT[i] != '\"') {
					tempLUT += this->lReturn->LUT[i];
				}
			}
			else {
				dgTransitionMatrix->ColumnCount = count;
				dgTransitionMatrix->Columns[count - 1]->Name = tempLUT;
				dgTransitionMatrix->Rows->Add(tempLUT);
				count++;
				tempLUT = "";
			}
		}
		if (tempLUT != "") {
			dgTransitionMatrix->ColumnCount = count;
			dgTransitionMatrix->Columns[count - 1]->Name = tempLUT;
			dgTransitionMatrix->Rows->Add(tempLUT);
		}

		dgTransitionMatrix->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;
		dgTransitionMatrix->Columns[0]->ReadOnly = true;
		//for (int i = 0; i < count; i++) {
		//	dgTransitionMatrix->Rows->Add();
		//}

		int row = 0;
		int column = 1;
		String^ tempValue;
		for (int i = j; i < this->lReturn->Return->Length; i++) {
			if (this->lReturn->Return[i] != ';') {
				if (this->lReturn->Return[i] != ',') {
					if (this->lReturn->Return[i] != '\"') {
						tempValue += this->lReturn->Return[i];
					}
				}
				else {
					dgTransitionMatrix->Rows[row]->Cells[column]->Value = tempValue;
					column++;
					tempValue = "";
				}
			}
			else {
				dgTransitionMatrix->Rows[row]->Cells[column]->Value = tempValue;
				column = 1;
				row++;
				tempValue = "";
			}
		}
		if (tempValue != "") {
			dgTransitionMatrix->Rows[row]->Cells[column]->Value = tempValue;
		}
	}
	else {
		if (lReturn->LUT != "") {
			String^ tempLUT = "";
			int count = 1;
			dgTransitionMatrix->ColumnCount = count;
			dgTransitionMatrix->Columns[count - 1]->Name = "->";
			count++;
			for (int i = 0; i < this->lReturn->LUT->Length; i++) {
				if (this->lReturn->LUT[i] != ',') {
					if (this->lReturn->LUT[i] != '\"') {
						tempLUT += this->lReturn->LUT[i];
					}
				}
				else {
					dgTransitionMatrix->ColumnCount = count;
					dgTransitionMatrix->Columns[count - 1]->Name = tempLUT;
					dgTransitionMatrix->Rows->Add(tempLUT);
					count++;
					tempLUT = "";
				}
			}
			if (tempLUT != "") {
				dgTransitionMatrix->ColumnCount = count;
				dgTransitionMatrix->Columns[count - 1]->Name = tempLUT;
				dgTransitionMatrix->Rows->Add(tempLUT);
			}

			dgTransitionMatrix->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;
			dgTransitionMatrix->Columns[0]->ReadOnly = true;
			//for (int i = 0; i < count; i++) {
			//	dgTransitionMatrix->Rows->Add();
			//}
		}
	}
}

System::Void LuccME::A_AllocationClueSLike::bSalvar_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;

	this->lReturn->Return = "";

	this->lReturn->Return += tMaxIteration->Text;
	this->lReturn->Return += ";";
	this->lReturn->Return += tFactorInteration->Text;
	this->lReturn->Return += ";";
	this->lReturn->Return += tMaxDifference->Text;
	this->lReturn->Return += ";";

	for (int i = 0; i < dgTransitionMatrix->RowCount; i++) {
		if (!check) {
			break;
		}
		for (int j = 1; j < dgTransitionMatrix->ColumnCount; j++) {
			if (dgTransitionMatrix->Rows[i]->Cells[j]->Value == nullptr) {
				MessageBox::Show(gSCells, gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				check = false;
				break;
			}
			else {
				this->lReturn->Return += dgTransitionMatrix->Rows[i]->Cells[j]->Value;
				if (j + 1 < dgTransitionMatrix->ColumnCount) {
					this->lReturn->Return += ",";
				}
			}
		}
		if (i + 1 < dgTransitionMatrix->RowCount) {
			if (dgTransitionMatrix->Rows[i + 1] != nullptr) {
				this->lReturn->Return += ";";
			}
		}
	}

	if (!check) {
		this->lReturn->Return = "";
	}
	else {
		this->Close();
	}
}

System::Void LuccME::A_AllocationClueSLike::dgTransitionMatrix_CellValidating(System::Object ^ sender, System::Windows::Forms::DataGridViewCellValidatingEventArgs ^ e)
{
	//int newInteger;

	//if (dgTransitionMatrix->Rows[e->RowIndex]->IsNewRow)
	//{
	//	return;
	//}
	//if (!Int32::TryParse(e->FormattedValue->ToString(),
	//	newInteger) || (newInteger < 0) || (newInteger > 1))
	//{
	//	e->Cancel = true;
	//}
}

System::Void LuccME::A_AllocationClueSLike::dgTransitionMatrix_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
	switch (e->KeyCode)
	{
	case Keys::Delete:
		if (dgTransitionMatrix->SelectedCells->Count != 0)
		{
			DataGridViewCell^ startCell = GetStartCell(dgTransitionMatrix);
			int row = startCell->RowIndex;
			int column = startCell->ColumnIndex;
			for (int i = row; i < dgTransitionMatrix->RowCount; i++) {
				for (int j = column; j < dgTransitionMatrix->ColumnCount; j++) {
					if (dgTransitionMatrix->Rows[i]->Cells[j]->Selected == true) {
						dgTransitionMatrix->Rows[i]->Cells[j]->Value = "";
					}
				}
			}
		}
		break;
	}
}

System::Windows::Forms::DataGridViewCell ^ LuccME::A_AllocationClueSLike::GetStartCell(System::Windows::Forms::DataGridView ^ dgView)
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

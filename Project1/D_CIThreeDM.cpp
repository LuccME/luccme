#include "stdafx.h"
#include "D_CIThreeDM.h"

System::Void LuccME::D_CIThreeDM::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void LuccME::D_CIThreeDM::D_CIThreeDM_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Demand - Compute Input Three Date Maps";
		lYearInterpolation->Text = "Years for Interpolation:";
		lMiddleYear->Text = "Middle Year";
		lFinalYear->Text = "Final Year";
		lLUTfI->Text = "Colunms for Interpolation";
		bSalvar->Text = "Save";
		gSCells = "All the cells must be fullfilled.";
		gSCellsTitle = "Error - Empty Cells";
		gSDataMod = "The data was modified, but not saved.\nThe data will be lost.\nDo you want to proceed?";
		gSExit = "Exit - Compute Input Two Date Maps";
	}
	else {
		this->Text = "Demanda - Compute Input Three Date Maps";
		lYearInterpolation->Text = "Anos para Interpolação:";
		lMiddleYear->Text = "Ano Intemediário";
		lFinalYear->Text = "Ano Final";
		lLUTfI->Text = "Colunas para Interpolação";
		bSalvar->Text = "Salvar";
		gSCells = "Todas as células devem ser preenchidas.";
		gSCellsTitle = "Erro - Células Vazias";
		gSDataMod = "Os dados foram modificados, mas não foram salvos.\nOs dados serão perdidos.\nDeseja continuar?";
		gSExit = "Sair - Compute Input Two Date Maps";
	}

	tFinalYear->Text = Convert::ToString(lReturn->FinalYear);
	tMiddleYear->Text = Convert::ToString(lReturn->MiddleYear);

	if (this->lReturn->Empty) {
		if (this->lReturn->Return->Length > 0) {
			String^ aux = "";
			int count = 1;
			for (int i = 0; i < this->lReturn->Return->Length; i++) {
				if (this->lReturn->Return[i] != ',') {
					if (this->lReturn->Return[i] != '\"') {
						aux += this->lReturn->Return[i];
					}
				}
				else {
					switch (count) {
					default:
						dgDemand->ColumnCount = count;
						dgDemand->Columns[count - 1]->Name = aux;
						count++;
						break;
					}
					aux = "";
				}
			}

			if (aux != "") {
				dgDemand->ColumnCount = count;
				dgDemand->Columns[count - 1]->Name = aux;
			}
		}
		dgDemand->Rows->Add();
		dgDemand->Rows->Add();
	}
	else {
		if (this->lReturn->Return->Length > 0) {
			String^ aux = "";
			int count = 1;
			int i = 0;

			while (this->lReturn->Return[i] != ';') {
				if (this->lReturn->Return[i] != ',') {
					if (this->lReturn->Return[i] != '\"') {
						aux += this->lReturn->Return[i];
					}
				}
				else {
					switch (count) {
					default:
						dgDemand->ColumnCount = count;
						dgDemand->Columns[count - 1]->Name = aux;
						count++;
						break;
					}
					aux = "";
				}
				i++;
			}
			if (aux != "") {
				dgDemand->ColumnCount = count;
				dgDemand->Columns[count - 1]->Name = aux;
			}
			
			dgDemand->Rows->Add();
			dgDemand->Rows->Add();
			
			aux = "";
			i++;
			
			int row = 0;
			int column = 0;

			for (int j = i; j < this->lReturn->Return->Length; j++) {
				if (this->lReturn->Return[j] != ';') {
					if (this->lReturn->Return[j] != ',') {
						if (this->lReturn->Return[j] != '\"') {
							aux += this->lReturn->Return[j];
						}
					}
					else {
						dgDemand->Rows[row]->Cells[column]->Value = aux;
						column++;
						aux = "";
					}
				}
				else {
					dgDemand->Rows[row]->Cells[column]->Value = aux;
					column = 0;
					row++;
					aux = "";
				}
			}
			if (aux != "") {
				dgDemand->Rows[row]->Cells[column]->Value = aux;
			}
		}
	}
	managed = false;
}

System::Void LuccME::D_CIThreeDM::bSalvar_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	String^ temp = "";

	for (int j = 0; j < dgDemand->ColumnCount; j++) {
		if (dgDemand->Rows[0]->Cells[j]->Value == nullptr) {
			MessageBox::Show(gSCells,gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = false;
		}
		else {
			if (j + 1 < dgDemand->ColumnCount) {
				temp += "\"";
				temp += dgDemand->Rows[0]->Cells[j]->Value;
				temp += "\",";
			}
			else {
				temp += "\"";
				temp += dgDemand->Rows[0]->Cells[j]->Value;
				temp += "\"";
			}

		}
	}
	temp += ";";
	for (int j = 0; j < dgDemand->ColumnCount; j++) {
		if (dgDemand->Rows[1]->Cells[j]->Value == nullptr) {
			MessageBox::Show(gSCells, gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = false;
		}
		else {
			if (j + 1 < dgDemand->ColumnCount) {
				temp += "\"";
				temp += dgDemand->Rows[1]->Cells[j]->Value;
				temp += "\",";
			}
			else {
				temp += "\"";
				temp += dgDemand->Rows[1]->Cells[j]->Value;
				temp += "\"";
			}

		}
	}

	if (check) {
		lReturn->MiddleYear = Convert::ToInt16(tMiddleYear->Text);
		lReturn->FinalYear = Convert::ToInt16(tFinalYear->Text);
		lReturn->Return = "";
		lReturn->Return = temp;
		close = true;
		this->Close();
	}
}

System::Void LuccME::D_CIThreeDM::D_CIThreeDM_FormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e)
{
	if (!close) {
		if (changed) {
			if (MessageBox::Show(gSDataMod, gSExit, MessageBoxButtons::YesNo, MessageBoxIcon::Question) == LuccME::DialogResult::No) {
				e->Cancel = true;
			}

		}
		if (lReturn->Return->Length != lReturn->LUT->Length) {
			int i = 0;
			while (this->lReturn->Return[i] != ';') {
				i++;
			}
			lReturn->Return = lReturn->Return->Substring(i + 1);
		}
		else {
			lReturn->Return = "";
		}
	}
}

System::Void LuccME::D_CIThreeDM::dgDemand_CellValueChanged(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (!managed) {
		changed = true;
	}
}

System::Windows::Forms::DataGridViewCell ^ LuccME::D_CIThreeDM::GetStartCell(System::Windows::Forms::DataGridView ^ dgView)
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

System::Void LuccME::D_CIThreeDM::dgDemand_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
	switch (e->KeyCode)
	{
	case Keys::Delete:
		if (dgDemand->SelectedCells->Count != 0)
		{
			DataGridViewCell^ startCell = GetStartCell(dgDemand);
			int row = startCell->RowIndex;
			int column = startCell->ColumnIndex;
			for (int i = row; i < dgDemand->RowCount; i++) {
				for (int j = column; j < dgDemand->ColumnCount; j++) {
					if (dgDemand->Rows[i]->Cells[j]->Selected == true) {
						dgDemand->Rows[i]->Cells[j]->Value = "";
					}
				}
			}
		}
		break;
	}
}


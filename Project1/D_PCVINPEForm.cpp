#include "stdafx.h"
#include "D_PCVINPEForm.h"

System::Void LuccME::D_PCVINPEForm::D_PCVINPEForm_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Demand - Pre Computed Values INPE";
		gSYear = "Years";
		gSCells = "All the cells must be fullfilled.";
		gSCellsTitle = "Error - Empty Cells";
		bSalvar->Text = "Save";
		gSDataMod = "The data was modified, but not saved.\nThe data will be lost.\nDo you want to proceed?";
		gSExit = "Exit - Pre Computed Values INPE";
		lPCVINPE->Text = "Annual Demand";
	}
	else {
		this->Text = "Demanda - Pre Computed Values INPE";
		gSYear = "Anos";
		gSCells = "Todas as células devem ser preenchidas.";
		gSCellsTitle = "Erro - Células Vazias";
		bSalvar->Text = "Salvar";
		gSDataMod = "Os dados foram modificados, mas não foram salvos.\nOs dados serão perdidos.\nDeseja continuar?";
		gSExit = "Sair - Pre Computed Values INPE";
		lPCVINPE->Text = "Demanda Anual";
	}

	dgDemand->ColumnCount = 1;
	dgDemand->Columns[0]->Name = gSYear;
	dgDemand->Columns[0]->Width = dgDemand->Columns[0]->Width / 2;
	dgDemand->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;
	
	int time = Convert::ToInt16(lReturn->StartTime);
	
	for (int i = 0; i < lReturn->YearsForSimulation; i++) {
		dgDemand->Rows->Add(Convert::ToString(time));
		time++;
	}
	
	dgDemand->Columns[0]->ReadOnly = true;
	
	if (this->lReturn->Empty) {
		if (this->lReturn->Return->Length > 0) {
			String^ aux = "";
			int count = 2;
			for (int i = 0; i < this->lReturn->Return->Length; i++) {
				if (this->lReturn->Return[i] != ',') {
					if (this->lReturn->Return[i] != '\"') {
						aux += this->lReturn->Return[i];
					}
				}
				else {
					dgDemand->ColumnCount = count;
					dgDemand->Columns[count-1]->Name = aux;
					count++;
					aux = "";
				}
			}

			if (aux != "") {
				dgDemand->ColumnCount = count;
				dgDemand->Columns[count - 1]->Name = aux;
			}
		}
	}
	else {
		if (this->lReturn->Return->Length > 0) {
			String^ aux = "";
			int count = 2;
			int i = 0;
			while (this->lReturn->Return[i] != ';') {
				if (this->lReturn->Return[i] != ',') {
					if (this->lReturn->Return[i] != '\"') {
						aux += this->lReturn->Return[i];
					}
				}
				else {
					dgDemand->ColumnCount = count;
					dgDemand->Columns[count - 1]->Name = aux;
					count++;
					aux = "";
				}
				i++;
			}
			if (aux != "") {
				dgDemand->ColumnCount = count;
				dgDemand->Columns[count - 1]->Name = aux;
			}
			aux = "";
			int rowCount = 0;
			int columnCount = 1;
			for (int j = i; j < lReturn->Return->Length; j++) {
				if (this->lReturn->Return[j] != ',') {
					if (this->lReturn->Return[j] != '{' && this->lReturn->Return[j] != '}' && this->lReturn->Return[j] != ';') {
						aux += this->lReturn->Return[j];
					}
				}
				else {
					if (rowCount <= dgDemand->Rows->Count - 1) {
						dgDemand->Rows[rowCount]->Cells[columnCount]->Value = aux;
						columnCount++;
						aux = "";
						if (columnCount >= dgDemand->Columns->Count) {
							rowCount++;
							columnCount = 1;
						}
					}
				}
			}
			if (aux != "") {
				if (rowCount < lReturn->YearsForSimulation) {
					dgDemand->Rows[rowCount]->Cells[columnCount]->Value = aux;
				}
			}
		}
	}
	managed = false;
}

System::Void LuccME::D_PCVINPEForm::bSalvar_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	String^ temp = "";
	for (int i = 0; i < dgDemand->RowCount; i++) {
		if (!check) {
			break;
		}
		temp += "{";
		for (int j = 1; j < dgDemand->ColumnCount; j++) {
			if (dgDemand->Rows[i]->Cells[j]->Value == nullptr) {
				MessageBox::Show(gSCells, gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				check = false;
			}
			else {
				if (j != 1) {
					temp += ",";
				}
				temp += dgDemand->Rows[i]->Cells[j]->Value;
			}
		}
		if (i + 1 < dgDemand->RowCount) {
			temp += "},;";
		}
		else {
			temp += "}";
		}
	}
	if (check) {
		lReturn->Return = "";
		lReturn->Return = temp;
		close = true;
		this->Close();
	}
}

System::Void LuccME::D_PCVINPEForm::D_PCVINPEForm_FormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e)
{
	if (!close) {
		if (changed) {
			if (MessageBox::Show(gSDataMod, gSYear, MessageBoxButtons::YesNo, MessageBoxIcon::Question) == LuccME::DialogResult::No) {
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

System::Void LuccME::D_PCVINPEForm::dgDemand_CellValueChanged(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (!managed) {
		changed = true;
	}
}

System::Void LuccME::D_PCVINPEForm::dgDemand_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
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
					if (dgDemand->SelectedCells->Count != NONE)
					{
						DataGridViewCell^ startCell = GetStartCell(dgDemand);
						int row = startCell->RowIndex;
						int column = startCell->ColumnIndex;
						for (int i = row; i < dgDemand->RowCount; i++) {
							for (int j = column; j < dgDemand->ColumnCount; j++) {
								if (dgDemand->Rows[i]->Cells[j]->Selected == true && j != 0) {
									dgDemand->Rows[i]->Cells[j]->Value = "";
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

System::Void LuccME::D_PCVINPEForm::CopyToClipboard()
{
	//Copy to clipboard
	DataObject^ dataObj = dgDemand->GetClipboardContent();
	if (dataObj != nullptr)
		Clipboard::SetDataObject(dataObj);
}

System::Void LuccME::D_PCVINPEForm::PasteClipboardValue()
{
	//Show Error if no cell is selected
	if (dgDemand->SelectedCells->Count == NONE)
	{
		MessageBox::Show("Please select a cell", "Paste", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	//Get the satring Cell
	DataGridViewCell^ startCell = GetStartCell(dgDemand);

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
		for (int i = 0; i < content->Length; i++) {
			dgDemand->Rows[row]->Cells[column]->Value = content[i];
			column++;
			if (column > columnNumber) {
				row++;
				column = startCell->ColumnIndex;
			}
		}
	}
}

System::Windows::Forms::DataGridViewCell^ LuccME::D_PCVINPEForm::GetStartCell(System::Windows::Forms::DataGridView^ dgView)
{
	//get the smallest row,column index
	if (dgView->SelectedCells->Count == NONE)
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

System::Void LuccME::D_PCVINPEForm::copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	CopyToClipboard();
}

System::Void LuccME::D_PCVINPEForm::pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	PasteClipboardValue();
}

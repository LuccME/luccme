#include "stdafx.h"
#include "P_DiscreteR.h"

using namespace System::Windows::Forms;

System::Void LuccME::P_DiscreteR::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

/*
Count the number of a caracter on a string
*/
System::Int16 LuccME::P_DiscreteR::countCaracter(String^ source, char caracter)
{
	int count = 0;
	for (int i = 0; i < source->Length; i++) {
		if (source[i] == caracter) {
			count++;
		}
	}
	return count;
}

/*
Initialized all the regions on tcRegions for the default values
*/
System::Void LuccME::P_DiscreteR::initializeRegions()
{
	dgBetas->ColumnCount = 2;
	dgBetas->Columns[0]->Name = gSAttributes;
	dgBetas->Columns[1]->Name = gSValues;
	dgBetas->Rows->Clear();
	tConst->Text = "0.01";
	tConst->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy->Text = "0.5";
		tElasticy->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse->Text = "0.5";
		tPercNeighborsUse->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy->Text = "0.5";
		tElasticy->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse->Text = "0.5";
		tPercNeighborsUse->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas2->ColumnCount = 2;
	dgBetas2->Columns[0]->Name = gSAttributes;
	dgBetas2->Columns[1]->Name = gSValues;
	dgBetas2->Rows->Clear();
	tConst2->Text = "0.01";
	tConst2->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy2->Text = "0.5";
		tElasticy2->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse2->Text = "0.5";
		tPercNeighborsUse2->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy2->Text = "0.5";
		tElasticy2->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse2->Text = "0.5";
		tPercNeighborsUse2->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas3->ColumnCount = 2;
	dgBetas3->Columns[0]->Name = gSAttributes;
	dgBetas3->Columns[1]->Name = gSValues;
	dgBetas3->Rows->Clear();
	tConst3->Text = "0.01";
	tConst3->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy3->Text = "0.5";
		tElasticy3->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse3->Text = "0.5";
		tPercNeighborsUse3->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy3->Text = "0.5";
		tElasticy3->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse3->Text = "0.5";
		tPercNeighborsUse3->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas4->ColumnCount = 2;
	dgBetas4->Columns[0]->Name = gSAttributes;
	dgBetas4->Columns[1]->Name = gSValues;
	dgBetas4->Rows->Clear();
	tConst4->Text = "0.01";
	tConst4->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy4->Text = "0.5";
		tElasticy4->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse4->Text = "0.5";
		tPercNeighborsUse4->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy4->Text = "0.5";
		tElasticy4->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse4->Text = "0.5";
		tPercNeighborsUse4->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas5->ColumnCount = 2;
	dgBetas5->Columns[0]->Name = gSAttributes;
	dgBetas5->Columns[1]->Name = gSValues;
	dgBetas5->Rows->Clear();
	tConst5->Text = "0.01";
	tConst5->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy5->Text = "0.5";
		tElasticy5->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse5->Text = "0.5";
		tPercNeighborsUse5->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy5->Text = "0.5";
		tElasticy5->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse5->Text = "0.5";
		tPercNeighborsUse5->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas6->ColumnCount = 2;
	dgBetas6->Columns[0]->Name = gSAttributes;
	dgBetas6->Columns[1]->Name = gSValues;
	dgBetas6->Rows->Clear();
	tConst6->Text = "0.01";
	tConst6->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy6->Text = "0.5";
		tElasticy6->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse6->Text = "0.5";
		tPercNeighborsUse6->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy6->Text = "0.5";
		tElasticy6->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse6->Text = "0.5";
		tPercNeighborsUse6->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas7->ColumnCount = 2;
	dgBetas7->Columns[0]->Name = gSAttributes;
	dgBetas7->Columns[1]->Name = gSValues;
	dgBetas7->Rows->Clear();
	tConst7->Text = "0.01";
	tConst7->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy7->Text = "0.5";
		tElasticy7->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse7->Text = "0.5";
		tPercNeighborsUse7->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy7->Text = "0.5";
		tElasticy7->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse7->Text = "0.5";
		tPercNeighborsUse7->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas8->ColumnCount = 2;
	dgBetas8->Columns[0]->Name = gSAttributes;
	dgBetas8->Columns[1]->Name = gSValues;
	dgBetas8->Rows->Clear();
	tConst8->Text = "0.01";
	tConst8->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy8->Text = "0.5";
		tElasticy8->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse8->Text = "0.5";
		tPercNeighborsUse8->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy8->Text = "0.5";
		tElasticy8->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse8->Text = "0.5";
		tPercNeighborsUse8->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas9->ColumnCount = 2;
	dgBetas9->Columns[0]->Name = gSAttributes;
	dgBetas9->Columns[1]->Name = gSValues;
	dgBetas9->Rows->Clear();
	tConst9->Text = "0.01";
	tConst9->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy9->Text = "0.5";
		tElasticy9->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse9->Text = "0.5";
		tPercNeighborsUse9->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy9->Text = "0.5";
		tElasticy9->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse9->Text = "0.5";
		tPercNeighborsUse9->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas10->ColumnCount = 2;
	dgBetas10->Columns[0]->Name = gSAttributes;
	dgBetas10->Columns[1]->Name = gSValues;
	dgBetas10->Rows->Clear();
	tConst10->Text = "0.01";
	tConst10->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy10->Text = "0.5";
		tElasticy10->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse10->Text = "0.5";
		tPercNeighborsUse10->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy10->Text = "0.5";
		tElasticy10->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tPercNeighborsUse10->Text = "0.5";
		tPercNeighborsUse10->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	tcRegions->SelectedIndex = 0;
}

/*
Make the components of a tRagion visible or not
*/
System::Void LuccME::P_DiscreteR::setVisibleONorOFF(Label^ lBetas, DataGridView^ dgBetas, Label^ lConst, TextBox^ tConst, Label^ lElasticy, TextBox^ tElasticy, Label^ lPercNeighborsUse, TextBox^ tPercNeighborsUse, bool status)
{
	lBetas->Visible = status;
	dgBetas->ColumnCount = 2;
	dgBetas->Columns[0]->Name = gSAttributes;
	dgBetas->Columns[1]->Name = gSValues;
	dgBetas->Visible = status;
	lConst->Visible = status;
	tConst->Visible = status;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		lElasticy->Visible = status;
		tElasticy->Visible = status;
	} 
	else if (lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		lElasticy->Visible = status;
		tElasticy->Visible = status;
		lPercNeighborsUse->Visible = status;
		tPercNeighborsUse->Visible = status;
	}
}

/*
Used when a tRegion is deleted, it copies the data from the tRegions higher than the deleted one.
*/
System::Void LuccME::P_DiscreteR::moveData(DataGridView^ dgBetas, TextBox^ tConst, TextBox^ tElasticy, TextBox^ tPercNeighborsUse, DataGridView^ dgBetas2, TextBox^ tConst2, TextBox^ tElasticy2, TextBox^ tPercNeighborsUse2)
{
	dgBetas->Rows->Clear();
	for (int i = 0; i < dgBetas2->RowCount - 1; i++) {
		dgBetas->Rows->Add();
		dgBetas->Rows[i]->Cells[0]->Value = dgBetas2->Rows[i]->Cells[0]->Value;
		dgBetas->Rows[i]->Cells[1]->Value = dgBetas2->Rows[i]->Cells[1]->Value;
	}
	tConst->Text = tConst2->Text;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy->Text = tElasticy2->Text;
	}
	else if (lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy->Text = tElasticy2->Text;
		tPercNeighborsUse->Text = tPercNeighborsUse2->Text;
	}
}

/*
Used to set the tRegions data from lReturn->Return, it copies the lTempBetas data to tRegion
*/
System::Int16 LuccME::P_DiscreteR::getRegionData(array<String^>^ lTempBetas, cReturnPotential^ lReturn, DataGridView^ dgBetas, TextBox^ tConst, TextBox^ tElasticy, TextBox^ tPercNeighborsUse, int i, int j)
{
	String^ tempConst = "";
	while (lTempBetas[i][j] != ';') {
		tempConst += lTempBetas[i][j];
		j++;
	}
	j++;

	String^ tempElasticy = "";
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		while (lTempBetas[i][j] != ';') {
			tempElasticy += lTempBetas[i][j];
			j++;
		}
		j++;
	}

	String^ tempPNU = "";
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		while (lTempBetas[i][j] != ';') {
			tempElasticy += lTempBetas[i][j];
			j++;
		}
		j++;

		while (lTempBetas[i][j] != ';') {
			tempPNU += lTempBetas[i][j];
			j++;
		}
		j++;
	}

	String^ tempBeta = "";
	int rowCount = 0;

	for (j; j < lTempBetas[i]->Length; j++) {
		if (lTempBetas[i][j] == '*') {
			j += 1;
			break;
		}
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
	}

	if (tempBeta != "") {
		dgBetas->Rows[rowCount]->Cells[1]->Value = tempBeta;
	}
	tConst->Text = tempConst;
	tConst->ForeColor = System::Drawing::Color::Black;
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		tElasticy->Text = tempElasticy;
		tElasticy->ForeColor = System::Drawing::Color::Black;
	}
	if (lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		tElasticy->Text = tempElasticy;
		tElasticy->ForeColor = System::Drawing::Color::Black;
		tPercNeighborsUse->Text = tempPNU;
		tPercNeighborsUse->ForeColor = System::Drawing::Color::Black;
	}

	return j;
}

/*
Used to save the tRegions data to lReturn->Return, it copies the tRegion data to lTempBetas
*/
System::Void LuccME::P_DiscreteR::setRegionData(DataGridView^ dgBetas, TextBox^ tConst, TextBox^ tElasticy, TextBox^ tPercNeighborsUse, int i, int j)
{
	lTempBetas[i] += tConst->Text->Replace(',', '.');
	lTempBetas[i] += ";";

	if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		lTempBetas[i] += tElasticy->Text->Replace(',', '.');
		lTempBetas[i] += ";";
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		lTempBetas[i] += tElasticy->Text->Replace(',', '.');
		lTempBetas[i] += ";";
		lTempBetas[i] += tPercNeighborsUse->Text->Replace(',', '.');
		lTempBetas[i] += ";";
	}


	for (int j = 0; j < dgBetas->Rows->Count; j++) {
		if (dgBetas->Rows[j]->Cells[0]->Value != nullptr) {
			lTempBetas[i] += dgBetas->Rows[j]->Cells[0]->Value;
			lTempBetas[i] += "=";
		}
		if (dgBetas->Rows[j]->Cells[1]->Value != nullptr) {
			lTempBetas[i] += dgBetas->Rows[j]->Cells[1]->Value->ToString()->Replace(",",".");
			if (j + 1 < dgBetas->Rows->Count) {
				if (dgBetas->Rows[j + 1]->Cells[0]->Value != nullptr) {
					lTempBetas[i] += ",";
				}
			}
		}
	}
	lTempBetas[i] += "*";
	lReturn->Regression += 1;
}

/*
Locate the initial cell for copying or pasting
*/
System::Windows::Forms::DataGridViewCell ^ LuccME::P_DiscreteR::GetStartCell(System::Windows::Forms::DataGridView ^ dgView)
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

/*
Capture the keys press
*/
System::Void LuccME::P_DiscreteR::dgBetas_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
	DataGridView^ dgView = (DataGridView^)sender;
	try
	{
		if (e->Modifiers == Keys::Control)
		{
			switch (e->KeyCode)
			{
			case Keys::C:
				CopyToClipboard(dgView);
				break;

			case Keys::V:
				PasteClipboardValue(dgView);
				break;
			}
		}
		else {
			switch (e->KeyCode)
			{
			case Keys::Delete:
				if (dgView->SelectedCells->Count != NONE)
				{
					DataGridViewCell^ startCell = GetStartCell(dgView);
					int row = startCell->RowIndex;
					int column = startCell->ColumnIndex;
					for (int i = row; i < dgView->RowCount; i++) {
						for (int j = column; j < dgView->ColumnCount; j++) {
							if (dgView->Rows[i]->Cells[j]->Selected == true) {
								dgView->Rows[i]->Cells[j]->Value = "";
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
		MessageBox::Show(gSCopyPaste + ex->Message, gSCopyPasteTitle, MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

/*
Copy the clipboard data
*/
System::Void LuccME::P_DiscreteR::CopyToClipboard(DataGridView^ dgView)
{
	DataObject^ dataObj = dgView->GetClipboardContent();
	if (dataObj != nullptr) {
		Clipboard::SetDataObject(dataObj);
	}
}


/*
Paste the clipboard data
*/
System::Void LuccME::P_DiscreteR::PasteClipboardValue(DataGridView^ dgView)
{
	//Show Error if no cell is selected
	if (dgView->SelectedCells->Count == NONE)
	{
		MessageBox::Show(gSPaste, gSPasteTitle, MessageBoxButtons::OK, MessageBoxIcon::Warning);
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

System::Void LuccME::P_DiscreteR::neighAttractionLogisticRegressionON()
{
	lElasticy->Visible = true;
	tElasticy->Visible = true;
	lElasticy2->Visible = true;
	tElasticy2->Visible = true;
	lElasticy3->Visible = true;
	tElasticy3->Visible = true;
	lElasticy4->Visible = true;
	tElasticy4->Visible = true;
	lElasticy5->Visible = true;
	tElasticy5->Visible = true;
	lElasticy6->Visible = true;
	tElasticy6->Visible = true;
	lElasticy7->Visible = true;
	tElasticy7->Visible = true;
	lElasticy8->Visible = true;
	tElasticy8->Visible = true;
	lElasticy9->Visible = true;
	tElasticy9->Visible = true;
	lElasticy10->Visible = true;
	tElasticy10->Visible = true;
	lPercNeighborsUse->Visible = true;
	tPercNeighborsUse->Visible = true;
	lPercNeighborsUse2->Visible = true;
	tPercNeighborsUse2->Visible = true;
	lPercNeighborsUse3->Visible = true;
	tPercNeighborsUse3->Visible = true;
	lPercNeighborsUse4->Visible = true;
	tPercNeighborsUse4->Visible = true;
	lPercNeighborsUse5->Visible = true;
	tPercNeighborsUse5->Visible = true;
	lPercNeighborsUse6->Visible = true;
	tPercNeighborsUse6->Visible = true;
	lPercNeighborsUse7->Visible = true;
	tPercNeighborsUse7->Visible = true;
	lPercNeighborsUse8->Visible = true;
	tPercNeighborsUse8->Visible = true;
	lPercNeighborsUse9->Visible = true;
	tPercNeighborsUse9->Visible = true;
	lPercNeighborsUse10->Visible = true;
	tPercNeighborsUse10->Visible = true;
}

System::Void LuccME::P_DiscreteR::logisticRegressionON()
{
	lElasticy->Visible = true;
	tElasticy->Visible = true;
	lElasticy2->Visible = true;
	tElasticy2->Visible = true;
	lElasticy3->Visible = true;
	tElasticy3->Visible = true;
	lElasticy4->Visible = true;
	tElasticy4->Visible = true;
	lElasticy5->Visible = true;
	tElasticy5->Visible = true;
	lElasticy6->Visible = true;
	tElasticy6->Visible = true;
	lElasticy7->Visible = true;
	tElasticy7->Visible = true;
	lElasticy8->Visible = true;
	tElasticy8->Visible = true;
	lElasticy9->Visible = true;
	tElasticy9->Visible = true;
	lElasticy10->Visible = true;
	tElasticy10->Visible = true;
}

System::Void LuccME::P_DiscreteR::P_DiscreteR_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		bAddBetas->Text = "Add";
		bCancel->Text = "Cancel";
		bSalvar->Text = "Save";
		gSLUT = "Land Use Types";
		gSValues = "Coefficient";
		gSAttributes = "Attributes";
		gSEmptyComponent = "The data of the component must be fulfilled.";
		gSEmptyComponentTitle = "Component data missing";
		lBetas->Text = "Factors";
		lBetas2->Text = "Factors";
		lBetas3->Text = "Factors";
		lBetas4->Text = "Factors";
		lBetas5->Text = "Factors";
		lBetas6->Text = "Factors";
		lBetas7->Text = "Factors";
		lBetas8->Text = "Factors";
		lBetas9->Text = "Factors";
		lBetas10->Text = "Factors";
		gSCopyPasteTitle = "Copy/Paste";
		gSCopyPaste = "Copy/paste operation failed. ";
		gSPasteTitle = "Paste";
		gSPaste = "Please select a cell";
	}
	else {
		bAddBetas->Text = "Adicionar";
		bCancel->Text = "Cancelar";
		bSalvar->Text = "Salvar";
		gSLUT = "Tipos de Uso da Terra";
		gSValues = "Coeficientes";
		gSAttributes = "Atributos";
		gSEmptyComponent = "Os dados do componente devem ser preenchidos.";
		gSEmptyComponentTitle = "Faltando preencher os dados";
		lBetas->Text = "Fatores";
		lBetas2->Text = "Fatores";
		lBetas3->Text = "Fatores";
		lBetas4->Text = "Fatores";
		lBetas5->Text = "Fatores";
		lBetas6->Text = "Fatores";
		lBetas7->Text = "Fatores";
		lBetas8->Text = "Fatores";
		lBetas9->Text = "Fatores";
		lBetas10->Text = "Fatores";
		gSCopyPasteTitle = "Copiar/Colar";
		gSCopyPaste = "Operação de Copiar/Colar falhou. ";
		gSPasteTitle = "Colar";
		gSPaste = "Selecione uma célula";
	}

	//Remove the Regions tabs
	for (int i = REGRESSIONNUMBER; i >= INITIALREGRESSIONSHOW; i--) {
		tcRegions->TabPages->RemoveAt(i);
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

	if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
		logisticRegressionON();
		lBetas->Location = Point(117, 80);
		dgBetas->Location = Point(25, 110);
		dgBetas->Height = 246;
		lBetas2->Location = Point(117, 80);
		dgBetas2->Location = Point(25, 110);
		dgBetas2->Height = 246;
		lBetas3->Location = Point(117, 80);
		dgBetas3->Location = Point(25, 110);
		dgBetas3->Height = 246;
		lBetas4->Location = Point(117, 80);
		dgBetas4->Location = Point(25, 110);
		dgBetas4->Height = 246;
		lBetas5->Location = Point(117, 80);
		dgBetas5->Location = Point(25, 110);
		dgBetas5->Height = 246;
		lBetas6->Location = Point(117, 80);
		dgBetas6->Location = Point(25, 110);
		dgBetas6->Height = 246;
		lBetas7->Location = Point(117, 80);
		dgBetas7->Location = Point(25, 110);
		dgBetas7->Height = 246;
		lBetas8->Location = Point(117, 80);
		dgBetas8->Location = Point(25, 110);
		dgBetas8->Height = 246;
		lBetas9->Location = Point(117, 80);
		dgBetas9->Location = Point(25, 110);
		dgBetas9->Height = 246;
		lBetas10->Location = Point(117, 80);
		dgBetas10->Location = Point(25, 110);
		dgBetas10->Height = 246;
	}
	else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
		neighAttractionLogisticRegressionON();
		lBetas->Location = Point(117, 110);
		dgBetas->Location = Point(25, 140);
		dgBetas->Height = 216;
		lBetas2->Location = Point(117, 110);
		dgBetas2->Location = Point(25, 140);
		dgBetas2->Height = 216;
		lBetas3->Location = Point(117, 110);
		dgBetas3->Location = Point(25, 140);
		dgBetas3->Height = 216;
		lBetas4->Location = Point(117, 110);
		dgBetas4->Location = Point(25, 140);
		dgBetas4->Height = 216;
		lBetas5->Location = Point(117, 110);
		dgBetas5->Location = Point(25, 140);
		dgBetas5->Height = 216;
		lBetas6->Location = Point(117, 110);
		dgBetas6->Location = Point(25, 140);
		dgBetas6->Height = 216;
		lBetas7->Location = Point(117, 110);
		dgBetas7->Location = Point(25, 140);
		dgBetas7->Height = 216;
		lBetas8->Location = Point(117, 110);
		dgBetas8->Location = Point(25, 140);
		dgBetas8->Height = 216;
		lBetas9->Location = Point(117, 110);
		dgBetas9->Location = Point(25, 140);
		dgBetas9->Height = 216;
		lBetas10->Location = Point(117, 110);
		dgBetas10->Location = Point(25, 140);
		dgBetas10->Height = 216;
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
				int fulfilledRegions = countCaracter(lTempBetas[rowCount], '*');
				if (fulfilledRegions == lReturn->Regression) {
					lvLUT->Items[rowCount]->SubItems->Add("OK");
				}
				rowCount++;
			}
		}
		if (lTempBetas[rowCount] != "") {
			lvLUT->Items[rowCount]->SubItems->Add("OK");
		}
	}

	for (int i = 0; i < lReturn->Regression; i++) {
		tcRegions->Visible = true;
		tcRegions->SelectedIndex = i;
		tcRegions->Visible = false;
	}

	tcRegions->SelectedIndex = NONE;
}

System::Void  LuccME::P_DiscreteR::lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (bAddBetas->Visible == false) {
		initializeRegions();

		for (int i = 0; i < lvLUT->Items->Count; i++) {
			if (lvLUT->Items[i]->Selected == true) {
				tLUT->Text = lvLUT->Items[i]->Text;
				tLUT->ReadOnly = true;
				tLUT->Visible = true;
				lvLUT->Visible = false;

				if (lTempBetas[i] != nullptr) {
					int fulfillRegions = -1; //It has an * on the end
					for (int r = 0; r < lTempBetas[i]->Length; r++) {
						if (lTempBetas[i][r] == '*') {
							fulfillRegions += 1;
						}
					}
					int j = 0;
					for (int k = 0; k < lReturn->Regression; k++) {
						if (k > fulfillRegions) {
							break;
						}

						switch (k)
						{
						case 0:
							j = getRegionData(lTempBetas, lReturn, dgBetas, tConst, tElasticy, tPercNeighborsUse, i, j);
							break;
						case 1:
							j = getRegionData(lTempBetas, lReturn, dgBetas2, tConst2, tElasticy2, tPercNeighborsUse2, i, j);
							break;
						case 2:
							j = getRegionData(lTempBetas, lReturn, dgBetas3, tConst3, tElasticy3, tPercNeighborsUse3, i, j);
							break;
						case 3:
							j = getRegionData(lTempBetas, lReturn, dgBetas4, tConst4, tElasticy4, tPercNeighborsUse4, i, j);
							break;
						case 4:
							j = getRegionData(lTempBetas, lReturn, dgBetas5, tConst5, tElasticy5, tPercNeighborsUse5, i, j);
							break;
						case 5:
							j = getRegionData(lTempBetas, lReturn, dgBetas6, tConst6, tElasticy6, tPercNeighborsUse6, i, j);
							break;
						case 6:
							j = getRegionData(lTempBetas, lReturn, dgBetas7, tConst7, tElasticy7, tPercNeighborsUse7, i, j);
							break;
						case 7:
							j = getRegionData(lTempBetas, lReturn, dgBetas8, tConst8, tElasticy8, tPercNeighborsUse8, i, j);
							break;
						case 8:
							j = getRegionData(lTempBetas, lReturn, dgBetas9, tConst9, tElasticy9, tPercNeighborsUse9, i, j);
							break;
						case 9:
							j = getRegionData(lTempBetas, lReturn, dgBetas10, tConst10, tElasticy10, tPercNeighborsUse10, i, j);
							break;
						default:
							break;
						}
					}
				}
			}
		}

		bSalvar->Visible = false;
		tcRegions->Visible = true;
		lConst->Visible = true;
		tConst->Visible = true;
		lBetas->Visible = true;
		dgBetas->Visible = true;
		bAddBetas->Visible = true;
		bCancel->Visible = true;

		if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSION) {
			logisticRegressionON();
		}
		else if (this->lReturn->Component == POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT) {
			neighAttractionLogisticRegressionON();
		}
	}
}

System::Void LuccME::P_DiscreteR::tcRegions_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	bDeleteRegression->Visible = false;
	if (tcRegions->SelectedIndex == (tcRegions->TabCount - 1)) {
		int nlvItems = countCaracter(lReturn->LUT, ',') + 1;
		for (int i = 0; i < lvLUT->Items->Count; i++) {
			if (lvLUT->Items[i]->SubItems->Count == 2) {
				lvLUT->Items[i]->SubItems->RemoveAt(1);
			}
		}
		tcRegions->TabPages[tcRegions->SelectedIndex]->Text = "Region " + (tcRegions->SelectedIndex + 1).ToString();
		if (tcRegions->SelectedIndex < REGRESSIONNUMBER) {
			switch (tcRegions->SelectedIndex)
			{
			case 1:
				tcRegions->TabPages->Add(tRegion3);
				break;
			case 2:
				tcRegions->TabPages->Add(tRegion4);
				break;
			case 3:
				tcRegions->TabPages->Add(tRegion5);
				break;
			case 4:
				tcRegions->TabPages->Add(tRegion6);
				break;
			case 5:
				tcRegions->TabPages->Add(tRegion7);
				break;
			case 6:
				tcRegions->TabPages->Add(tRegion8);
				break;
			case 7:
				tcRegions->TabPages->Add(tRegion9);
				break;
			case 8:
				tcRegions->TabPages->Add(tRegion10);
				break;
			default:
				break;
			}
		}

		switch (tcRegions->SelectedIndex)
		{
		case 0:
			setVisibleONorOFF(lBetas, dgBetas, lConst, tConst, lElasticy, tElasticy, lPercNeighborsUse, tPercNeighborsUse, true);
			break;
		case 1:
			setVisibleONorOFF(lBetas2, dgBetas2, lConst2, tConst2, lElasticy2, tElasticy2, lPercNeighborsUse2, tPercNeighborsUse2, true);
			break;
		case 2:
			setVisibleONorOFF(lBetas3, dgBetas3, lConst3, tConst3, lElasticy3, tElasticy3, lPercNeighborsUse3, tPercNeighborsUse3, true);
			break;
		case 3:
			setVisibleONorOFF(lBetas4, dgBetas4, lConst4, tConst4, lElasticy4, tElasticy4, lPercNeighborsUse4, tPercNeighborsUse4, true);
			break;
		case 4:
			setVisibleONorOFF(lBetas5, dgBetas5, lConst5, tConst5, lElasticy5, tElasticy5, lPercNeighborsUse5, tPercNeighborsUse5, true);
			break;
		case 5:
			setVisibleONorOFF(lBetas6, dgBetas6, lConst6, tConst6, lElasticy6, tElasticy6, lPercNeighborsUse6, tPercNeighborsUse6, true);
			break;
		case 6:
			setVisibleONorOFF(lBetas7, dgBetas7, lConst7, tConst7, lElasticy7, tElasticy7, lPercNeighborsUse7, tPercNeighborsUse7, true);
			break;
		case 7:
			setVisibleONorOFF(lBetas8, dgBetas8, lConst8, tConst8, lElasticy8, tElasticy8, lPercNeighborsUse8, tPercNeighborsUse8, true);
			break;
		case 8:
			setVisibleONorOFF(lBetas9, dgBetas9, lConst9, tConst9, lElasticy9, tElasticy9, lPercNeighborsUse9, tPercNeighborsUse9, true);
			break;
		case 9:
			setVisibleONorOFF(lBetas10, dgBetas10, lConst10, tConst10, lElasticy10, tElasticy10, lPercNeighborsUse10, tPercNeighborsUse10, true);
			break;
		default:
			break;
		}
	}

	if (tcRegions->SelectedIndex > 0) {
		bDeleteRegression->Visible = true;
	}
}

System::Void LuccME::P_DiscreteR::bDeleteRegression_Click(System::Object^  sender, System::EventArgs^  e)
{
	int rToRemove = tcRegions->SelectedIndex;
	int rNumber = tcRegions->TabCount;
	if (rToRemove > 0) {
		for (int i = rToRemove; i < rNumber - 1; i++) {
			switch (i)
			{
			case 1:
				moveData(dgBetas2, tConst2, tElasticy2, tPercNeighborsUse2, dgBetas3, tConst3, tElasticy3, tPercNeighborsUse3);
				break;
			case 2:
				moveData(dgBetas3, tConst3, tElasticy3, tPercNeighborsUse3, dgBetas4, tConst4, tElasticy4, tPercNeighborsUse4);
				break;
			case 3:
				moveData(dgBetas4, tConst4, tElasticy4, tPercNeighborsUse4, dgBetas5, tConst5, tElasticy5, tPercNeighborsUse5);
				break;
			case 4:
				moveData(dgBetas5, tConst5, tElasticy5, tPercNeighborsUse5, dgBetas6, tConst6, tElasticy6, tPercNeighborsUse6);
				break;
			case 5:
				moveData(dgBetas6, tConst6, tElasticy6, tPercNeighborsUse6, dgBetas7, tConst7, tElasticy7, tPercNeighborsUse7);
				break;
			case 6:
				moveData(dgBetas7, tConst7, tElasticy7, tPercNeighborsUse7, dgBetas8, tConst8, tElasticy8, tPercNeighborsUse8);
				break;
			case 7:
				moveData(dgBetas8, tConst8, tElasticy8, tPercNeighborsUse8, dgBetas9, tConst9, tElasticy9, tPercNeighborsUse9);
				break;
			case 8:
				moveData(dgBetas9, tConst9, tElasticy9, tPercNeighborsUse9, dgBetas10, tConst10, tElasticy10, tPercNeighborsUse10);
				break;
			default:
				break;
			}
		}
		tcRegions->TabPages->RemoveAt(tcRegions->TabCount - 1);
		tcRegions->TabPages[tcRegions->TabCount - 1]->Text = "+";
		tcRegions->SelectedIndex = NONE;

		for (int i = 0; i < lvLUT->Items->Count; i++) {
			if (lTempBetas[i] != nullptr) {
				int fulfillRegions = 0;
				array<int>^ lRegionsLocation = gcnew array<int>(tcRegions->TabCount);
				for (int r = 0; r < lTempBetas[i]->Length; r++) {
					if (lTempBetas[i][r] == '*') {
						lRegionsLocation[fulfillRegions] = r;
						fulfillRegions += 1;
					}
				}
				int count = 0;
				if (fulfillRegions > tcRegions->TabCount - 1) {
					String^ aux = lTempBetas[i]->Substring(0, lRegionsLocation[0] + 1);
					for (int r = 1; r < lRegionsLocation->Length; r++) {
						if (r < rToRemove) {
							aux += lTempBetas[i]->Substring(lRegionsLocation[count] + 1, (lRegionsLocation[count + 1] - lRegionsLocation[count]));
							count++;
						}
						else if (r > rToRemove) {
							aux += lTempBetas[i]->Substring(lRegionsLocation[count] + 1, (lRegionsLocation[count + 1] - lRegionsLocation[count]));
							count++;
						}
						else {
							count++;
						}
					}
					lTempBetas[i] = aux;
				}
			}
		}
	}
}

System::Void LuccME::P_DiscreteR::bCancel_Click(System::Object^  sender, System::EventArgs^  e)
{
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		lvLUT->Items[i]->Selected = false;
	}

	bAddBetas->Visible = false;
	bCancel->Visible = false;
	tLUT->Visible = false;
	lvLUT->Visible = true;
	bSalvar->Visible = true;
	initializeRegions();
	tcRegions->Visible = false;
	bDeleteRegression->Visible = false;
}

System::Void LuccME::P_DiscreteR::bAddBetas_Click(System::Object^  sender, System::EventArgs^  e)
{
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		if (lvLUT->Items[i]->Selected == true) {
			lReturn->Regression = 0;
			lTempBetas[i] = "";
			for (int j = 0; j < tcRegions->TabCount - 1; j++) {
				switch (j)
				{
				case 0:
					setRegionData(dgBetas, tConst, tElasticy, tPercNeighborsUse, i, j);
					break;
				case 1:
					setRegionData(dgBetas2, tConst2, tElasticy2, tPercNeighborsUse2, i, j);
					break;
				case 2:
					setRegionData(dgBetas3, tConst3, tElasticy3, tPercNeighborsUse3, i, j);
					break;
				case 3:
					setRegionData(dgBetas4, tConst4, tElasticy4, tPercNeighborsUse4, i, j);
					break;
				case 4:
					setRegionData(dgBetas5, tConst5, tElasticy5, tPercNeighborsUse5, i, j);
					break;
				case 5:
					setRegionData(dgBetas6, tConst6, tElasticy6, tPercNeighborsUse6, i, j);
					break;
				case 6:
					setRegionData(dgBetas7, tConst7, tElasticy7, tPercNeighborsUse7, i, j);
					break;
				case 7:
					setRegionData(dgBetas8, tConst8, tElasticy8, tPercNeighborsUse8, i, j);
					break;
				case 8:
					setRegionData(dgBetas9, tConst9, tElasticy9, tPercNeighborsUse9, i, j);
					break;
				case 9:
					setRegionData(dgBetas10, tConst10, tElasticy10, tPercNeighborsUse10, i, j);
					break;
				default:
					break;
				}
			}

			lvLUT->Items[i]->SubItems->Add("OK");
			break;
		}
	}

	for (int i = 0; i < lvLUT->Items->Count; i++) {
		lvLUT->Items[i]->Selected = false;
	}

	bAddBetas->Visible = false;
	bCancel->Visible = false;
	tLUT->Visible = false;
	lvLUT->Visible = true;
	bSalvar->Visible = true;
	initializeRegions();
	tcRegions->Visible = false;
	bDeleteRegression->Visible = false;
}

System::Void LuccME::P_DiscreteR::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void LuccME::P_DiscreteR::copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	switch (tcRegions->SelectedIndex)
	{
	case 0:
		CopyToClipboard(dgBetas);
		break;
	case 1:
		CopyToClipboard(dgBetas2);
		break;
	case 2:
		CopyToClipboard(dgBetas3);
		break;
	case 3:
		CopyToClipboard(dgBetas4);
		break;
	case 4:
		CopyToClipboard(dgBetas5);
		break;
	case 5:
		CopyToClipboard(dgBetas6);
		break;
	case 6:
		CopyToClipboard(dgBetas7);
		break;
	case 7:
		CopyToClipboard(dgBetas8);
		break;
	case 8:
		CopyToClipboard(dgBetas9);
		break;
	case 9:
		CopyToClipboard(dgBetas10);
		break;
	default:
		break;
	}
}

System::Void LuccME::P_DiscreteR::pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	switch (tcRegions->SelectedIndex)
	{
	case 0:
		PasteClipboardValue(dgBetas);
		break;
	case 1:
		PasteClipboardValue(dgBetas2);
		break;
	case 2:
		PasteClipboardValue(dgBetas3);
		break;
	case 3:
		PasteClipboardValue(dgBetas4);
		break;
	case 4:
		PasteClipboardValue(dgBetas5);
		break;
	case 5:
		PasteClipboardValue(dgBetas6);
		break;
	case 6:
		PasteClipboardValue(dgBetas7);
		break;
	case 7:
		PasteClipboardValue(dgBetas8);
		break;
	case 8:
		PasteClipboardValue(dgBetas9);
		break;
	case 9:
		PasteClipboardValue(dgBetas10);
		break;
	default:
		break;
	}
}

#include "stdafx.h"
#include "A_Continuous.h"

using namespace System::Windows::Forms;

/*
Used on the enter focus to change default values and colors
*/
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
		lMaxDiffHelp->Text = "Absolute Value";
		cbPotReg->Text = "Use Potential Regions";
	}
	else {
		bSalvar->Text = "Salvar";
		lLegend->Text = "* -1 - Unidirecional, 0 - Bidirecional, 1 - Estático";
		lMaxDiffHelp->Text = "Valor Absoluto";
		cbPotReg->Text = "Usar Regiões do Potencial";
	}

	if (lReturn->Return != "") {
		int j = 0;
		
		if (lReturn->PotRegression) {
			cbPotReg->Checked = true;
		}

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
		if (lReturn->Component == ALLOCATIONCCLUELIKESATURATION) {
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
		
		if (lReturn->Component == ALLOCATIONCCLUELIKESATURATION) {
			tSaturationIndicator->Text = saturationIndicator;
			tSaturationIndicator->ForeColor = System::Drawing::Color::Black;

			tAttrProtection->Text = attrProtection;
			tAttrProtection->ForeColor = System::Drawing::Color::Black;
		}
		
		array<String^>^ tempData = gcnew array<String^>(lReturn->Regression);

		for (int i = 0; i < lReturn->Regression; i++) {
			while (lReturn->Return[j] != '*') {
				tempData[i] += lReturn->Return[j];
				j++;
			}
			
			j++;

			switch (i)
			{
			case 0:
				setAllocationData(dgAllocationData, tempData[i]);
				break;
			case 1:
				setAllocationData(dgAllocationData2, tempData[i]);
				break;
			case 2:
				setAllocationData(dgAllocationData3, tempData[i]);
				break;
			case 3:
				setAllocationData(dgAllocationData4, tempData[i]);
				break;
			case 4:
				setAllocationData(dgAllocationData5, tempData[i]);
				break;
			case 5:
				setAllocationData(dgAllocationData6, tempData[i]);
				break;
			case 6:
				setAllocationData(dgAllocationData7, tempData[i]);
				break;
			case 7:
				setAllocationData(dgAllocationData8, tempData[i]);
				break;
			case 8:
				setAllocationData(dgAllocationData9, tempData[i]);
				break;
			case 9:
				setAllocationData(dgAllocationData10, tempData[i]);
				break;
			default:
				break;
			}
		}
	} else {
		initializeAllocationData(dgAllocationData);
		initializeAllocationData(dgAllocationData2);
		initializeAllocationData(dgAllocationData3);
		initializeAllocationData(dgAllocationData4);
		initializeAllocationData(dgAllocationData5);
		initializeAllocationData(dgAllocationData6);
		initializeAllocationData(dgAllocationData7);
		initializeAllocationData(dgAllocationData8);
		initializeAllocationData(dgAllocationData9);
		initializeAllocationData(dgAllocationData10);
	}

	if (lReturn->Component == ALLOCATIONCCLUELIKESATURATION) {
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
	
	//Remove the Regions tabs
	for (int i = REGRESSIONNUMBER; i >= INITIALREGRESSIONSHOW; i--) {
		tcRegions->TabPages->RemoveAt(i);
	}
	
	for (int i = 0; i < lReturn->Regression; i++) {
		tcRegions->Visible = true;
		tcRegions->SelectedIndex = i;
	}

	tcRegions->SelectedIndex = 0;
}

System::Void LuccME::A_Continuous::bSalvar_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	lReturn->Regression = 0;
	lReturn->Return = "";
	
	if (cbPotReg->Checked) {
		lReturn->PotRegression = true;
	}
	else {
		lReturn->PotRegression = false;
	}

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
	
	if (lReturn->Component == ALLOCATIONCCLUELIKESATURATION) {
		lReturn->Return += tSaturationIndicator->Text;
		lReturn->Return += ";";
		lReturn->Return += tAttrProtection->Text;
		lReturn->Return += ";";
	}

	for (int i = 0; i < tcRegions->TabCount - 1; i++) {
		switch (i)
		{
		case 0:
			getAllocationData(dgAllocationData);
			lReturn->Return += "*";
			break;
		case 1:
			getAllocationData(dgAllocationData2);
			lReturn->Return += "*";
			break;
		case 2:
			getAllocationData(dgAllocationData3);
			lReturn->Return += "*";
			break;
		case 3:
			getAllocationData(dgAllocationData4);
			lReturn->Return += "*";
			break;
		case 5:
			getAllocationData(dgAllocationData6);
			lReturn->Return += "*";
			break;
		case 6:
			getAllocationData(dgAllocationData7);
			lReturn->Return += "*";
			break;
		case 7:
			getAllocationData(dgAllocationData8);
			lReturn->Return += "*";
			break;
		case 8:
			getAllocationData(dgAllocationData9);
			lReturn->Return += "*";
			break;
		case 9:
			getAllocationData(dgAllocationData10);
			lReturn->Return += "*";
			break;
		default:
			break;
		}

		lReturn->Regression += 1;
	}

	lReturn->Return = lReturn->Return->Substring(0, lReturn->Return->Length - 2);
	lReturn->Return += "*";

	this->Close();
}

/*
Funtion that return a index on the grid (need to select a cell for delete fDelete = true)
*/
System::Windows::Forms::DataGridViewCell ^ LuccME::A_Continuous::GetStartCell(System::Windows::Forms::DataGridView ^ dgView, bool fDelete)
{
	//get the smallest row,column index
	if (dgView->SelectedCells->Count == NONE && fDelete)
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
Function to delete the values on the grid
*/
System::Void LuccME::A_Continuous::dgAllocData_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
	DataGridView^ dgView = (DataGridView^)sender;

	switch (e->KeyCode)
	{
		case Keys::Delete:
			if (dgView->SelectedCells->Count != NONE)
			{
				DataGridViewCell^ startCell = GetStartCell(dgView, true);
				int row = startCell->RowIndex;
				int column = startCell->ColumnIndex;
				for (int i = row; i < dgView->RowCount; i++) {
					for (int j = column; j < dgView->ColumnCount; j++) {
						if (dgView->Rows[i]->Cells[j]->Selected == true && j != 0) {
							dgView->Rows[i]->Cells[j]->Value = "";
						}
					}
				}
			}
			break;
	}
}

/*
Change the cell forecolor from Gray (default) to Black (user value)
*/
System::Void LuccME::A_Continuous::dgAllocData_CellEnter(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	DataGridView^ dgView = (DataGridView^)sender;

	if (!intialize) {
		DataGridViewCell^ startCell = GetStartCell(dgView, false);
		int row = startCell->RowIndex;
		int column = startCell->ColumnIndex;

		if (column > 0) {
			dgView->Rows[row]->Cells[column]->Style->ForeColor = System::Drawing::Color::Black;
		}
	}
}

/*
Initialize Allocation Data with the deafult values
*/
System::Void LuccME::A_Continuous::initializeAllocationData(DataGridView^ dgAllocData)
{
	dgAllocData->ColumnCount = 8;
	dgAllocData->Columns[0]->Name = "LandUseType";
	dgAllocData->Columns[1]->Name = "static*";
	dgAllocData->Columns[2]->Name = "minValue";
	dgAllocData->Columns[3]->Name = "maxValue";
	dgAllocData->Columns[4]->Name = "minChange";
	dgAllocData->Columns[5]->Name = "maxChange";
	dgAllocData->Columns[6]->Name = "changeLimiarValue";
	dgAllocData->Columns[7]->Name = "maxChangeAboveLimiar";

	int countRowDef = 0;
	String^ tempLUT = "";

	for (int i = 0; i < lReturn->LUT->Length; i++) {
		if (lReturn->LUT[i] != ',') {
			if (lReturn->LUT[i] != '\"') {
				tempLUT += lReturn->LUT[i];
			}
		}
		else {
			dgAllocData->Rows->Add(tempLUT);
			dgAllocData->Rows[countRowDef]->Cells[1]->Value = "0";
			dgAllocData->Rows[countRowDef]->Cells[2]->Value = "0";
			dgAllocData->Rows[countRowDef]->Cells[3]->Value = "1";
			dgAllocData->Rows[countRowDef]->Cells[4]->Value = "0";
			dgAllocData->Rows[countRowDef]->Cells[5]->Value = "1";
			dgAllocData->Rows[countRowDef]->Cells[6]->Value = "1";
			dgAllocData->Rows[countRowDef]->Cells[7]->Value = "0";
			countRowDef++;
			tempLUT = "";
		}
	}
	if (tempLUT != "") {
		dgAllocData->Rows->Add(tempLUT);
		dgAllocData->Rows[countRowDef]->Cells[1]->Value = "0";
		dgAllocData->Rows[countRowDef]->Cells[2]->Value = "0";
		dgAllocData->Rows[countRowDef]->Cells[3]->Value = "1";
		dgAllocData->Rows[countRowDef]->Cells[4]->Value = "0";
		dgAllocData->Rows[countRowDef]->Cells[5]->Value = "1";
		dgAllocData->Rows[countRowDef]->Cells[6]->Value = "1";
		dgAllocData->Rows[countRowDef]->Cells[7]->Value = "0";
	}

	for (int i = 0; i < 8; i++) {
		dgAllocData->Columns[i]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;
	}

	dgAllocationData->Columns[0]->ReadOnly = true;
}

/*
Set the data from Novo Form to Allocation components
*/
System::Void LuccME::A_Continuous::setAllocationData(DataGridView^ dgAllocData, String^ allocData)
{
	dgAllocData->ColumnCount = 8;
	dgAllocData->Columns[0]->Name = "LandUseType";
	dgAllocData->Columns[1]->Name = "static";
	dgAllocData->Columns[2]->Name = "minValue";
	dgAllocData->Columns[3]->Name = "maxValue";
	dgAllocData->Columns[4]->Name = "minChange";
	dgAllocData->Columns[5]->Name = "maxChange";
	dgAllocData->Columns[6]->Name = "changeLimiarValue";
	dgAllocData->Columns[7]->Name = "maxChangeAboveLimiar";

	String^ tempLUT = "";
	for (int i = 0; i < lReturn->LUT->Length; i++) {
		if (lReturn->LUT[i] != ',') {
			if (lReturn->LUT[i] != '\"') {
				tempLUT += lReturn->LUT[i];
			}
		}
		else {
			dgAllocData->Rows->Add(tempLUT);
			tempLUT = "";
		}
	}
	if (tempLUT != "") {
		dgAllocData->Rows->Add(tempLUT);
	}

	dgAllocData->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;
	dgAllocData->Columns[0]->ReadOnly = true;

	int rowCount = 0;
	int columnCount = 1;
	String^ tempValue = "";

	for (int i = 0; i < allocData->Length; i++) {
		if (allocData[i] != ';') {
			if (allocData[i] != ',') {
				tempValue += allocData[i];
			}
			else {
				dgAllocData->Rows[rowCount]->Cells[columnCount]->Value = tempValue;
				tempValue = "";
				columnCount++;
			}
		}
		else {
			dgAllocData->Rows[rowCount]->Cells[columnCount]->Value = tempValue;
			rowCount++;
			columnCount = 1;
			tempValue = "";
		}
	}

	if (tempValue != "") {
		dgAllocData->Rows[rowCount]->Cells[columnCount]->Value = tempValue;
	}

}

System::Void LuccME::A_Continuous::tcRegions_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	bDeleteRegression->Visible = false;

	if (tcRegions->SelectedIndex == (tcRegions->TabCount - 1)) {
		tcRegions->TabPages[tcRegions->SelectedIndex]->Text = "Region " + (tcRegions->SelectedIndex + 1).ToString();
		if (tcRegions->SelectedIndex < REGRESSIONNUMBER) {
			switch (tcRegions->SelectedIndex)
			{
			case 1:
				tcRegions->TabPages->Add(tRegion3);
				cbPotReg->Visible = true;
				break;
			case 2:
				tcRegions->TabPages->Add(tRegion4);
				cbPotReg->Visible = true;
				break;
			case 3:
				tcRegions->TabPages->Add(tRegion5);
				cbPotReg->Visible = true;
				break;
			case 4:
				tcRegions->TabPages->Add(tRegion6);
				cbPotReg->Visible = true;
				break;
			case 5:
				tcRegions->TabPages->Add(tRegion7);
				cbPotReg->Visible = true;
				break;
			case 6:
				tcRegions->TabPages->Add(tRegion8);
				cbPotReg->Visible = true;
				break;
			case 7:
				tcRegions->TabPages->Add(tRegion9);
				cbPotReg->Visible = true;
				break;
			case 8:
				tcRegions->TabPages->Add(tRegion10);
				cbPotReg->Visible = true;
				break;
			default:
				break;
			}
		}
	}

	if (tcRegions->SelectedIndex > 0) {
		bDeleteRegression->Visible = true;
		if (tcRegions->TabCount == 2) {
			cbPotReg->Checked = false;
			cbPotReg->Visible = false;
		}
	}
}

System::Void LuccME::A_Continuous::bDeleteRegression_Click(System::Object^  sender, System::EventArgs^  e)
{
	int rToRemove = tcRegions->SelectedIndex;
	int rNumber = tcRegions->TabCount;

	if (rToRemove > 0) {
		for (int i = rToRemove; i < rNumber - 1; i++) {
			switch (i)
			{
			case 1:
				moveData(dgAllocationData2, dgAllocationData3);
				break;
			case 2:
				moveData(dgAllocationData3, dgAllocationData4);
				break;
			case 3:
				moveData(dgAllocationData4, dgAllocationData5);
				break;
			case 4:
				moveData(dgAllocationData5, dgAllocationData6);
				break;
			case 5:
				moveData(dgAllocationData6, dgAllocationData7);
				break;
			case 6:
				moveData(dgAllocationData7, dgAllocationData8);
				break;
			case 7:
				moveData(dgAllocationData8, dgAllocationData9);
				break;
			case 8:
				moveData(dgAllocationData9, dgAllocationData10);
				break;
			default:
				break;
			}
		}

		tcRegions->TabPages->RemoveAt(tcRegions->TabCount - 1);
		tcRegions->TabPages[tcRegions->TabCount - 1]->Text = "+";
		tcRegions->SelectedIndex = 0;
	}
}

/*
Used when a tRegion is deleted, it copies the data from the tRegions higher than the deleted one.
*/
System::Void LuccME::A_Continuous::moveData(DataGridView^ dgAlloc, DataGridView^ dgAlloc2)
{
	dgAlloc->Rows->Clear();

	for (int i = 0; i < dgAlloc2->RowCount; i++) {
		dgAlloc->Rows->Add();
		dgAlloc->Rows[i]->Cells[0]->Value = dgAlloc2->Rows[i]->Cells[0]->Value;
		dgAlloc->Rows[i]->Cells[1]->Value = dgAlloc2->Rows[i]->Cells[1]->Value;
		dgAlloc->Rows[i]->Cells[2]->Value = dgAlloc2->Rows[i]->Cells[2]->Value;
		dgAlloc->Rows[i]->Cells[3]->Value = dgAlloc2->Rows[i]->Cells[3]->Value;
		dgAlloc->Rows[i]->Cells[4]->Value = dgAlloc2->Rows[i]->Cells[4]->Value;
		dgAlloc->Rows[i]->Cells[5]->Value = dgAlloc2->Rows[i]->Cells[5]->Value;
		dgAlloc->Rows[i]->Cells[6]->Value = dgAlloc2->Rows[i]->Cells[6]->Value;
		dgAlloc->Rows[i]->Cells[7]->Value = dgAlloc2->Rows[i]->Cells[7]->Value;
	}
}

/*
Get the values into Allocation components to lReturn 
*/
System::Void LuccME::A_Continuous::getAllocationData(DataGridView^ dgAlloc)
{
	int count = 1;

	for (int i = 0; i < lReturn->LUT->Length; i++) {
		if (lReturn->LUT[i] == ',') {
			count++;
		}
	}

	for (int i = 0; i < count; i++) {
		lReturn->Return += dgAlloc->Rows[i]->Cells[1]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAlloc->Rows[i]->Cells[2]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAlloc->Rows[i]->Cells[3]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAlloc->Rows[i]->Cells[4]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAlloc->Rows[i]->Cells[5]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAlloc->Rows[i]->Cells[6]->Value;
		lReturn->Return += ",";
		lReturn->Return += dgAlloc->Rows[i]->Cells[7]->Value;
		lReturn->Return += ";";
	}
}
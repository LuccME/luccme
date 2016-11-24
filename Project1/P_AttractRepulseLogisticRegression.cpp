#include "stdafx.h"
#include "P_AttractRepulseLogisticRegression.h"

using namespace System::Windows::Forms;

System::Void LuccME::P_AttractRepulseLogisticRegression::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
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
System::Int16 LuccME::P_AttractRepulseLogisticRegression::countCaracter(String^ source, char caracter)
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
System::Void LuccME::P_AttractRepulseLogisticRegression::initializeRegions()
{
	dgBetas->ColumnCount = 2;
	dgBetas->Columns[0]->Name = gSAttributes;
	dgBetas->Columns[1]->Name = gSValues;
	dgBetas->Rows->Clear();
	tConst->Text = "0.01";
	tConst->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tElasticy->Text = "0.5";
	tElasticy->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tPercNeighborsUse->Text = "0.5";
	tPercNeighborsUse->ForeColor = System::Drawing::SystemColors::ScrollBar;
	setInitializeAffinity(dgAffinityMatrix);

	dgBetas2->ColumnCount = 2;
	dgBetas2->Columns[0]->Name = gSAttributes;
	dgBetas2->Columns[1]->Name = gSValues;
	dgBetas2->Rows->Clear();
	tConst2->Text = "0.01";
	tConst2->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tElasticy2->Text = "0.5";
	tElasticy2->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tPercNeighborsUse2->Text = "0.5";
	tPercNeighborsUse2->ForeColor = System::Drawing::SystemColors::ScrollBar;
	setInitializeAffinity(dgAffinityMatrix2);

	dgBetas3->ColumnCount = 2;
	dgBetas3->Columns[0]->Name = gSAttributes;
	dgBetas3->Columns[1]->Name = gSValues;
	dgBetas3->Rows->Clear();
	tConst3->Text = "0.01";
	tConst3->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tElasticy3->Text = "0.5";
	tElasticy3->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tPercNeighborsUse3->Text = "0.5";
	tPercNeighborsUse3->ForeColor = System::Drawing::SystemColors::ScrollBar;
	setInitializeAffinity(dgAffinityMatrix3);

	dgBetas4->ColumnCount = 2;
	dgBetas4->Columns[0]->Name = gSAttributes;
	dgBetas4->Columns[1]->Name = gSValues;
	dgBetas4->Rows->Clear();
	tConst4->Text = "0.01";
	tConst4->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tElasticy4->Text = "0.5";
	tElasticy4->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tPercNeighborsUse4->Text = "0.5";
	tPercNeighborsUse4->ForeColor = System::Drawing::SystemColors::ScrollBar;
	setInitializeAffinity(dgAffinityMatrix4);

	dgBetas5->ColumnCount = 2;
	dgBetas5->Columns[0]->Name = gSAttributes;
	dgBetas5->Columns[1]->Name = gSValues;
	dgBetas5->Rows->Clear();
	tConst5->Text = "0.01";
	tConst5->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tElasticy5->Text = "0.5";
	tElasticy5->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tPercNeighborsUse5->Text = "0.5";
	tPercNeighborsUse5->ForeColor = System::Drawing::SystemColors::ScrollBar;
	setInitializeAffinity(dgAffinityMatrix5);

	dgBetas6->ColumnCount = 2;
	dgBetas6->Columns[0]->Name = gSAttributes;
	dgBetas6->Columns[1]->Name = gSValues;
	dgBetas6->Rows->Clear();
	tConst6->Text = "0.01";
	tConst6->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tElasticy6->Text = "0.5";
	tElasticy6->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tPercNeighborsUse6->Text = "0.5";
	tPercNeighborsUse6->ForeColor = System::Drawing::SystemColors::ScrollBar;
	setInitializeAffinity(dgAffinityMatrix6);

	dgBetas7->ColumnCount = 2;
	dgBetas7->Columns[0]->Name = gSAttributes;
	dgBetas7->Columns[1]->Name = gSValues;
	dgBetas7->Rows->Clear();
	tConst7->Text = "0.01";
	tConst7->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tElasticy7->Text = "0.5";
	tElasticy7->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tPercNeighborsUse7->Text = "0.5";
	tPercNeighborsUse7->ForeColor = System::Drawing::SystemColors::ScrollBar;
	setInitializeAffinity(dgAffinityMatrix7);

	dgBetas8->ColumnCount = 2;
	dgBetas8->Columns[0]->Name = gSAttributes;
	dgBetas8->Columns[1]->Name = gSValues;
	dgBetas8->Rows->Clear();
	tConst8->Text = "0.01";
	tConst8->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tElasticy8->Text = "0.5";
	tElasticy8->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tPercNeighborsUse8->Text = "0.5";
	tPercNeighborsUse8->ForeColor = System::Drawing::SystemColors::ScrollBar;
	setInitializeAffinity(dgAffinityMatrix8);

	dgBetas9->ColumnCount = 2;
	dgBetas9->Columns[0]->Name = gSAttributes;
	dgBetas9->Columns[1]->Name = gSValues;
	dgBetas9->Rows->Clear();
	tConst9->Text = "0.01";
	tConst9->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tElasticy9->Text = "0.5";
	tElasticy9->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tPercNeighborsUse9->Text = "0.5";
	tPercNeighborsUse9->ForeColor = System::Drawing::SystemColors::ScrollBar;
	setInitializeAffinity(dgAffinityMatrix9);

	dgBetas10->ColumnCount = 2;
	dgBetas10->Columns[0]->Name = gSAttributes;
	dgBetas10->Columns[1]->Name = gSValues;
	dgBetas10->Rows->Clear();
	tConst10->Text = "0.01";
	tConst10->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tElasticy10->Text = "0.5";
	tElasticy10->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tPercNeighborsUse10->Text = "0.5";
	tPercNeighborsUse10->ForeColor = System::Drawing::SystemColors::ScrollBar;
	setInitializeAffinity(dgAffinityMatrix10);

	tcRegions->SelectedIndex = 0;
}

/*
Make the components of a tRagion visible or not
*/
System::Void LuccME::P_AttractRepulseLogisticRegression::setVisibleONorOFF(Label^ lBetas, DataGridView^ dgBetas, Label^ lConst, TextBox^ tConst, Label^ lElasticy, TextBox^ tElasticy, Label^ lPercNeighborsUse, TextBox^ tPercNeighborsUse, DataGridView^ dgAffinity, Label^ lAffinityMatrix, Label^ lLegend, bool status)
{
	if (tLUT->Text != "Affinity Matrix") {
		lBetas->Visible = status;
		dgBetas->ColumnCount = 2;
		dgBetas->Columns[0]->Name = gSAttributes;
		dgBetas->Columns[1]->Name = gSValues;
		dgBetas->Visible = status;
		lConst->Visible = status;
		tConst->Visible = status;
		lElasticy->Visible = status;
		tElasticy->Visible = status;
		lPercNeighborsUse->Visible = status;
		tPercNeighborsUse->Visible = status;
		dgAffinity->Visible = !status;
		lAffinityMatrix->Visible = !status;
		lLegend->Visible = !status;
	}
	else {
		lBetas->Visible = !status;
		dgBetas->ColumnCount = 2;
		dgBetas->Columns[0]->Name = gSAttributes;
		dgBetas->Columns[1]->Name = gSValues;
		dgBetas->Visible = !status;
		lConst->Visible = !status;
		tConst->Visible = !status;
		lElasticy->Visible = !status;
		tElasticy->Visible = !status;
		lPercNeighborsUse->Visible = !status;
		tPercNeighborsUse->Visible = !status;
		dgAffinity->Visible = status;
		lAffinityMatrix->Visible = status;
		lLegend->Visible = status;
	}
}

System::Void LuccME::P_AttractRepulseLogisticRegression::setInitializeAffinity(DataGridView^ dgAffinity)
{
	dgAffinity->Rows->Clear();
	dgAffinity->ColumnCount = 0;

	String^ tempLUT = "";
	int count = 1;

	dgAffinity->ColumnCount = count;
	dgAffinity->Columns[count - 1]->Name = "->";
	
	count++;

	for (int i = 0; i < this->lReturn->LUT->Length; i++) {
		if (this->lReturn->LUT[i] != ',') {
			if (this->lReturn->LUT[i] != '\"') {
				tempLUT += this->lReturn->LUT[i];
			}
		}
		else {
			dgAffinity->ColumnCount = count;
			dgAffinity->Columns[count - 1]->Name = tempLUT;
			dgAffinity->Rows->Add(tempLUT);
			count++;
			tempLUT = "";
		}
	}
	if (tempLUT != "") {
		dgAffinity->ColumnCount = count;
		dgAffinity->Columns[count - 1]->Name = tempLUT;
		dgAffinity->Rows->Add(tempLUT);
	}
	dgAffinity->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;
	dgAffinity->Columns[0]->ReadOnly = true;
}

/*
Used when a tRegion is deleted, it copies the data from the tRegions higher than the deleted one.
*/
System::Void LuccME::P_AttractRepulseLogisticRegression::moveData(DataGridView^ dgBetas, TextBox^ tConst, TextBox^ tElasticy, TextBox^ tPercNeighborsUse, DataGridView^ dgAffinity, DataGridView^ dgBetas2, TextBox^ tConst2, TextBox^ tElasticy2, TextBox^ tPercNeighborsUse2, DataGridView^ dgAffinity2)
{
	dgBetas->Rows->Clear();
	for (int i = 0; i < dgBetas2->RowCount - 1; i++) {
		dgBetas->Rows->Add();
		dgBetas->Rows[i]->Cells[0]->Value = dgBetas2->Rows[i]->Cells[0]->Value;
		dgBetas->Rows[i]->Cells[1]->Value = dgBetas2->Rows[i]->Cells[1]->Value;
	}

	tConst->Text = tConst2->Text;
	tElasticy->Text = tElasticy2->Text;
	tPercNeighborsUse->Text = tPercNeighborsUse2->Text;

	dgAffinity->Rows->Clear();
	for (int i = 0; i < dgAffinity2->RowCount - 1; i++) {
		dgAffinity->Rows->Add();
		for (int j = 0; j < dgAffinity2->ColumnCount - 1; j++) {
			dgAffinity->Rows[i]->Cells[j]->Value = dgAffinity2->Rows[i]->Cells[j]->Value;
		}
	}
	dgAffinity->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;
	dgAffinity->Columns[0]->ReadOnly = true;
}

/*
Used to set the tRegions data from lReturn->Return, it copies the lTempBetas data to tRegion
*/
System::Int16 LuccME::P_AttractRepulseLogisticRegression::getRegionData(array<String^>^ lTempBetas, cReturnPotential^ lReturn, DataGridView^ dgBetas, TextBox^ tConst, TextBox^ tElasticy, TextBox^ tPercNeighborsUse, int i, int j)
{
	String^ tempConst = "";
	while (lTempBetas[i][j] != ';') {
		tempConst += lTempBetas[i][j];
		j++;
	}
	j++;

	String^ tempElasticy = "";
	while (lTempBetas[i][j] != ';') {
		tempElasticy += lTempBetas[i][j];
		j++;
	}
	j++;

	String^ tempPNU = "";
	while (lTempBetas[i][j] != ';') {
		tempPNU += lTempBetas[i][j];
		j++;
	}
	j++;

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
	tElasticy->Text = tempElasticy;
	tElasticy->ForeColor = System::Drawing::Color::Black;
	tPercNeighborsUse->Text = tempPNU;
	tPercNeighborsUse->ForeColor = System::Drawing::Color::Black;

	return j;
}

/*
Used to set the Affinity Matrix data from lReturn->Return, it copies the lTempBetas data to tRegion
*/
System::Void LuccME::P_AttractRepulseLogisticRegression::getMatrixData(array<String^>^ lTempValues, DataGridView^ dgAffinity, int k)
{
	int row = 0;
	int column = 1;
	String^ tempValue;
	for (int j = 0; j < lTempValues[k]->Length; j++) {
		if (lTempValues[k][j] != ';') {
			if (lTempValues[k][j] != ',') {
				if (lTempValues[k][j] != '\"') {
					if (lTempValues[k][j] != '%') {
						tempValue += lTempValues[k][j];
					}
				}
			}
			else {
				dgAffinity->Rows[row]->Cells[column]->Value = tempValue;
				column++;
				tempValue = "";
			}
		}
		else {
			dgAffinity->Rows[row]->Cells[column]->Value = tempValue;
			column = 1;
			row++;
			tempValue = "";
		}
	}
	if (tempValue != "") {
		dgAffinity->Rows[row]->Cells[column]->Value = tempValue;
	}
}

/*
Used to save the tRegions data to lReturn->Return, it copies the tRegion data to lTempBetas
*/
System::Void LuccME::P_AttractRepulseLogisticRegression::setRegionData(DataGridView^ dgBetas, TextBox^ tConst, TextBox^ tElasticy, TextBox^ tPercNeighborsUse, int i, int j)
{
	lTempBetas[i] += tConst->Text;
	lTempBetas[i] += ";";
	lTempBetas[i] += tElasticy->Text;
	lTempBetas[i] += ";";
	lTempBetas[i] += tPercNeighborsUse->Text;
	lTempBetas[i] += ";";

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
}

/*
Used to save the tRegions data to lReturn->Return, it copies the tRegion data to lTempValues
*/
System::Boolean LuccME::P_AttractRepulseLogisticRegression::setAffinityMatrixData( DataGridView^ dgAffinity, int k)
{
	bool check = true;
	for (int i = 0; i < dgAffinity->RowCount; i++) {
		for (int j = 1; j < dgAffinity->ColumnCount; j++) {
			if (dgAffinity->Rows[i]->Cells[j]->Value == nullptr) {
				MessageBox::Show(gSCells, gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				check = false;
				break;
			}
			else {
				lTempValues[k] += dgAffinity->Rows[i]->Cells[j]->Value;
				if (j + 1 < dgAffinity->ColumnCount) {
					lTempValues[k] += ",";
				}
			}
		}
		if (check) {
			if (i + 1 < dgAffinity->RowCount) {
				if (dgAffinity->Rows[i + 1] != nullptr) {
					lTempValues[k] += ";";
				}
			}
		}
		else {
			break;
		}
	}
	if (check) {
		lTempValues[k] += "%";
	}
	else {
		lTempValues[k] = nullptr;
	}
	
	return check;
}

/*
Locate the initial cell for copying or pasting
*/
System::Windows::Forms::DataGridViewCell ^ LuccME::P_AttractRepulseLogisticRegression::GetStartCell(System::Windows::Forms::DataGridView ^ dgView)
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
System::Void LuccME::P_AttractRepulseLogisticRegression::dgBetas_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
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
System::Void LuccME::P_AttractRepulseLogisticRegression::CopyToClipboard(DataGridView^ dgView)
{
	DataObject^ dataObj = dgView->GetClipboardContent();
	if (dataObj != nullptr) {
		Clipboard::SetDataObject(dataObj);
	}
}


/*
Paste the clipboard data
*/
System::Void LuccME::P_AttractRepulseLogisticRegression::PasteClipboardValue(DataGridView^ dgView)
{
	//Show Error if no cell is selected
	if (dgView->SelectedCells->Count == NONE)
	{
		MessageBox::Show(gSPasteTitle, gSPaste, MessageBoxButtons::OK, MessageBoxIcon::Warning);
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

System::Void LuccME::P_AttractRepulseLogisticRegression::P_AttractRepulseLogisticRegression_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		this->Text = "Pontential - Logistic Regression Attract Repulsion";
		bAddBetas->Text = "Add";
		bCancel->Text = "Cancel";
		bSalvar->Text = "Save";
		gSLUT = "Use Types and Matrix";
		gSValues = "Coefficient";
		gSAttributes = "Attributes";
		gSEmptyComponent = "The data of the component must be fulfilled.";
		gSEmptyComponentTitle = "Component data missing";
		gSCells = "All the cells must be fullfilled.";
		gSCellsTitle = "Error - Empty Cells";
		lBetas->Text = "Factors";
		lLegend->Text = "      0      - Indifferent, does not influence the land uses affinity.\n"
						"-0.1 a -1 - Repels, negative values one land use repels the other.\n"
						" 0.1 a  1 - Attracts, positive values one land use attracts the other. ";
		gSCopyPaste = "Copy/paste operation failed. ";
		gSPasteTitle = "Paste";
		gSPaste = "Please select a cell";
		gSCopyPasteTitle = "Copy/Paste";
		gSCopyPaste = "Copy/paste operation failed. ";
		gSPasteTitle = "Paste";
		gSPaste = "Please select a cell";
	}
	else {
		this->Text = "Pontencial - Logistic Regression Attract Repulsion";
		bAddBetas->Text = "Adicionar";
		bCancel->Text = "Cancelar";
		bSalvar->Text = "Salvar";
		gSLUT = "Usos da Terra e Matrix";
		gSValues = "Coeficientes";
		gSAttributes = "Atributos";
		gSEmptyComponent = "Os dados do componente devem ser preenchidos.";
		gSEmptyComponentTitle = "Faltando preencher os dados";
		gSCells = "Todas as células devem ser preenchidas.";
		gSCellsTitle = "Erro - Células Vazias";
		lBetas->Text = "Fatores";
		lLegend->Text = "      0      - Indiferente, não influencia na afinidade dos usos.\n"
						"-0.1 a -1 - Repele, valores negativos um uso repele o outro.\n"
						" 0.1 a  1 - Atrai, valores positivos um uso atrai o outro. ";
		gSCopyPasteTitle = "Copiar/Colar";
		gSCopyPaste = "Operação de Copiar/Colar falhou. ";
		gSPasteTitle = "Colar";
		gSPaste = "Selecione uma célula";
	}
	
	//Use the same values for al regions
	lBetas2->Text = lBetas->Text;
	lBetas3->Text = lBetas->Text;
	lBetas4->Text = lBetas->Text;
	lBetas5->Text = lBetas->Text;
	lBetas6->Text = lBetas->Text;
	lBetas7->Text = lBetas->Text;
	lBetas8->Text = lBetas->Text;
	lBetas9->Text = lBetas->Text;
	lBetas10->Text = lBetas->Text;

	lLegend2->Text = lLegend->Text;
	lLegend3->Text = lLegend->Text;
	lLegend4->Text = lLegend->Text;
	lLegend5->Text = lLegend->Text;
	lLegend6->Text = lLegend->Text;
	lLegend7->Text = lLegend->Text;
	lLegend8->Text = lLegend->Text;
	lLegend9->Text = lLegend->Text;
	lLegend10->Text = lLegend->Text;

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

	this->lvLUT->Items->Add("Affinity Matrix");
	this->lvLUT->Columns->Add("Status", 47, HorizontalAlignment::Left);

	// Coping the data from the NovoModeloForm
	int j = 0;
	if (this->lReturn->Return != "") {
		int rowCount = 0;
		for (int i = 0; i < this->lReturn->Return->Length; i++) {
			if (this->lReturn->Return[i] == '&') {
				j = i+1;
				break;
			}
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
		
		rowCount = 0;
		for (int i = j; i < this->lReturn->Return->Length; i++) {
			if (this->lReturn->Return[i] != '%') {
				lTempValues[rowCount] += this->lReturn->Return[i];
			}
			else {
				lTempValues[rowCount] += this->lReturn->Return[i];
				rowCount++;
			}
		}
		open = true;
	}

	for (int i = 0; i < lReturn->Regression; i++) {
		tcRegions->Visible = true;
		tcRegions->SelectedIndex = i;
		tcRegions->Visible = false;
	}

	open = false;
	tcRegions->SelectedIndex = NONE;
}

System::Void LuccME::P_AttractRepulseLogisticRegression::lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
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

		for (int k = 0; k < lReturn->Regression; k++) {
			switch (k)
			{
			case 0:
				setVisibleONorOFF(lBetas, dgBetas, lConst, tConst, lElasticy, tElasticy, lPercNeighborsUse, tPercNeighborsUse, dgAffinityMatrix, lAffinityMatrix, lLegend, true);
				if (lTempValues[k] != nullptr) {
					getMatrixData(lTempValues, dgAffinityMatrix, k);
				}
				break;
			case 1:
				setVisibleONorOFF(lBetas2, dgBetas2, lConst2, tConst2, lElasticy2, tElasticy2, lPercNeighborsUse2, tPercNeighborsUse2, dgAffinityMatrix2, lAffinityMatrix2, lLegend2, true);
				if (lTempValues[k] != nullptr) {
					getMatrixData(lTempValues, dgAffinityMatrix2, k);
				}
				break;
			case 2:
				setVisibleONorOFF(lBetas3, dgBetas3, lConst3, tConst3, lElasticy3, tElasticy3, lPercNeighborsUse3, tPercNeighborsUse3, dgAffinityMatrix3, lAffinityMatrix3, lLegend3, true);
				if (lTempValues[k] != nullptr) {
					getMatrixData(lTempValues, dgAffinityMatrix3, k);
				}
				break;
			case 3:
				setVisibleONorOFF(lBetas4, dgBetas4, lConst4, tConst4, lElasticy4, tElasticy4, lPercNeighborsUse4, tPercNeighborsUse4, dgAffinityMatrix4, lAffinityMatrix4, lLegend4, true);
				if (lTempValues[k] != nullptr) {
					getMatrixData(lTempValues, dgAffinityMatrix4, k);
				}
				break;
			case 4:
				setVisibleONorOFF(lBetas5, dgBetas5, lConst5, tConst5, lElasticy5, tElasticy5, lPercNeighborsUse5, tPercNeighborsUse5, dgAffinityMatrix5, lAffinityMatrix5, lLegend5, true);
				if (lTempValues[k] != nullptr) {
					getMatrixData(lTempValues, dgAffinityMatrix5, k);
				}
				break;
			case 5:
				setVisibleONorOFF(lBetas6, dgBetas6, lConst6, tConst6, lElasticy6, tElasticy6, lPercNeighborsUse6, tPercNeighborsUse6, dgAffinityMatrix6, lAffinityMatrix6, lLegend6, true);
				if (lTempValues[k] != nullptr) {
					getMatrixData(lTempValues, dgAffinityMatrix6, k);
				}
				break;
			case 6:
				setVisibleONorOFF(lBetas7, dgBetas7, lConst7, tConst7, lElasticy7, tElasticy7, lPercNeighborsUse7, tPercNeighborsUse7, dgAffinityMatrix7, lAffinityMatrix7, lLegend7, true);
				if (lTempValues[k] != nullptr) {
					getMatrixData(lTempValues, dgAffinityMatrix7, k);
				}
				break;
			case 7:
				setVisibleONorOFF(lBetas8, dgBetas8, lConst8, tConst8, lElasticy8, tElasticy8, lPercNeighborsUse8, tPercNeighborsUse8, dgAffinityMatrix8, lAffinityMatrix8, lLegend8, true);
				if (lTempValues[k] != nullptr) {
					getMatrixData(lTempValues, dgAffinityMatrix8, k);
				}
				break;
			case 8:
				setVisibleONorOFF(lBetas9, dgBetas9, lConst9, tConst9, lElasticy9, tElasticy9, lPercNeighborsUse9, tPercNeighborsUse9, dgAffinityMatrix9, lAffinityMatrix9, lLegend9, true);
				if (lTempValues[k] != nullptr) {
					getMatrixData(lTempValues, dgAffinityMatrix9, k);
				}
				break;
			case 9:
				setVisibleONorOFF(lBetas10, dgBetas10, lConst10, tConst10, lElasticy10, tElasticy10, lPercNeighborsUse10, tPercNeighborsUse10, dgAffinityMatrix10, lAffinityMatrix10, lLegend10, true);
				if (lTempValues[k] != nullptr) {
					getMatrixData(lTempValues, dgAffinityMatrix10, k);
				}
				break;
			default:
				break;
			}
		}

		bSalvar->Visible = false;
		tcRegions->Visible = true;
		bAddBetas->Visible = true;
		bCancel->Visible = true;
	}
}

System::Void LuccME::P_AttractRepulseLogisticRegression::tcRegions_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	bDeleteRegression->Visible = false;
	if (tcRegions->SelectedIndex == (tcRegions->TabCount - 1)) {
		if (!open) {
			int nlvItems = countCaracter(lReturn->LUT, ',') + 2;
			for (int i = 0; i < lvLUT->Items->Count; i++) {
				if (lvLUT->Items[i]->SubItems->Count == 2) {
					lvLUT->Items[i]->SubItems->RemoveAt(1);
				}
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
			
			if (tcRegions->SelectedIndex == lReturn->Regression) {
				lReturn->Regression += 1;
			}
		}

		switch (tcRegions->SelectedIndex)
		{
		case 0:
			setVisibleONorOFF(lBetas, dgBetas, lConst, tConst, lElasticy, tElasticy, lPercNeighborsUse, tPercNeighborsUse, dgAffinityMatrix, lAffinityMatrix, lLegend, true);
			break;
		case 1:
			setVisibleONorOFF(lBetas2, dgBetas2, lConst2, tConst2, lElasticy2, tElasticy2, lPercNeighborsUse2, tPercNeighborsUse2, dgAffinityMatrix2, lAffinityMatrix2, lLegend2, true);
			break;
		case 2:
			setVisibleONorOFF(lBetas3, dgBetas3, lConst3, tConst3, lElasticy3, tElasticy3, lPercNeighborsUse3, tPercNeighborsUse3, dgAffinityMatrix3, lAffinityMatrix3, lLegend3, true);
			break;
		case 3:
			setVisibleONorOFF(lBetas4, dgBetas4, lConst4, tConst4, lElasticy4, tElasticy4, lPercNeighborsUse4, tPercNeighborsUse4, dgAffinityMatrix4, lAffinityMatrix4, lLegend4, true);
			break;
		case 4:
			setVisibleONorOFF(lBetas5, dgBetas5, lConst5, tConst5, lElasticy5, tElasticy5, lPercNeighborsUse5, tPercNeighborsUse5, dgAffinityMatrix5, lAffinityMatrix5, lLegend5, true);
			break;
		case 5:
			setVisibleONorOFF(lBetas6, dgBetas6, lConst6, tConst6, lElasticy6, tElasticy6, lPercNeighborsUse6, tPercNeighborsUse6, dgAffinityMatrix6, lAffinityMatrix6, lLegend6, true);
			break;
		case 6:
			setVisibleONorOFF(lBetas7, dgBetas7, lConst7, tConst7, lElasticy7, tElasticy7, lPercNeighborsUse7, tPercNeighborsUse7, dgAffinityMatrix7, lAffinityMatrix7, lLegend7, true);
			break;
		case 7:
			setVisibleONorOFF(lBetas8, dgBetas8, lConst8, tConst8, lElasticy8, tElasticy8, lPercNeighborsUse8, tPercNeighborsUse8, dgAffinityMatrix8, lAffinityMatrix8, lLegend8, true);
			break;
		case 8:
			setVisibleONorOFF(lBetas9, dgBetas9, lConst9, tConst9, lElasticy9, tElasticy9, lPercNeighborsUse9, tPercNeighborsUse9, dgAffinityMatrix9, lAffinityMatrix9, lLegend9, true);
			break;
		case 9:
			setVisibleONorOFF(lBetas10, dgBetas10, lConst10, tConst10, lElasticy10, tElasticy10, lPercNeighborsUse10, tPercNeighborsUse10, dgAffinityMatrix10, lAffinityMatrix10, lLegend10, true);
			break;
		default:
			break;
		}
	}

	if (tcRegions->SelectedIndex > 0) {
		bDeleteRegression->Visible = true;
	}
}

System::Void LuccME::P_AttractRepulseLogisticRegression::bDeleteRegression_Click(System::Object^  sender, System::EventArgs^  e)
{
	int rToRemove = tcRegions->SelectedIndex;
	int rNumber = tcRegions->TabCount;
	if (rToRemove > 0) {
		for (int i = rToRemove; i < rNumber - 1; i++) {
			switch (i)
			{
			case 1:
				moveData(dgBetas2, tConst2, tElasticy2, tPercNeighborsUse2, dgAffinityMatrix2, dgBetas3, tConst3, tElasticy3, tPercNeighborsUse3, dgAffinityMatrix3);
				break;
			case 2:
				moveData(dgBetas3, tConst3, tElasticy3, tPercNeighborsUse3, dgAffinityMatrix3, dgBetas4, tConst4, tElasticy4, tPercNeighborsUse4, dgAffinityMatrix4);
				break;
			case 3:
				moveData(dgBetas4, tConst4, tElasticy4, tPercNeighborsUse4, dgAffinityMatrix4, dgBetas5, tConst5, tElasticy5, tPercNeighborsUse5, dgAffinityMatrix5);
				break;
			case 4:
				moveData(dgBetas5, tConst5, tElasticy5, tPercNeighborsUse5, dgAffinityMatrix5, dgBetas6, tConst6, tElasticy6, tPercNeighborsUse6, dgAffinityMatrix6);
				break;
			case 5:
				moveData(dgBetas6, tConst6, tElasticy6, tPercNeighborsUse6, dgAffinityMatrix6, dgBetas7, tConst7, tElasticy7, tPercNeighborsUse7, dgAffinityMatrix7);
				break;
			case 6:
				moveData(dgBetas7, tConst7, tElasticy7, tPercNeighborsUse7, dgAffinityMatrix7, dgBetas8, tConst8, tElasticy8, tPercNeighborsUse8, dgAffinityMatrix8);
				break;
			case 7:
				moveData(dgBetas8, tConst8, tElasticy8, tPercNeighborsUse8, dgAffinityMatrix8, dgBetas9, tConst9, tElasticy9, tPercNeighborsUse9, dgAffinityMatrix9);
				break;
			case 8:
				moveData(dgBetas9, tConst9, tElasticy9, tPercNeighborsUse9, dgAffinityMatrix9, dgBetas10, tConst10, tElasticy10, tPercNeighborsUse10, dgAffinityMatrix10);
				break;
			default:
				break;
			}
		}
		tcRegions->TabPages->RemoveAt(tcRegions->TabCount - 1);
		tcRegions->TabPages[tcRegions->TabCount - 1]->Text = "+";
		tcRegions->SelectedIndex = NONE;

		//Remove LUT data from the deleted region
		for (int i = 0; i < lvLUT->Items->Count - 1; i++) {
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
		for (int i = rToRemove; i < lTempValues->Length - 1; i++) {
			if (lTempValues[i + 1] != nullptr) {
				lTempValues[i] = lTempValues[i + 1];
			}
			else {
				lTempValues[i] = nullptr;
				break;
			}
		}
		lReturn->Regression -= 1;
	}
}

System::Void LuccME::P_AttractRepulseLogisticRegression::bAddBetas_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;
	for (int i = 0; i < lvLUT->Items->Count - 1; i++) {
		if (lvLUT->Items[i]->Selected == true) {
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

	if (tLUT->Text == "Affinity Matrix") {
		for (int j = 0; j < tcRegions->TabCount - 1; j++) {
			lTempValues[j] = "";
			switch (j)
			{
			case 0:
				check = setAffinityMatrixData(dgAffinityMatrix, j);
				break;
			case 1:
				check = setAffinityMatrixData(dgAffinityMatrix2, j);
				break;
			case 2:
				check = setAffinityMatrixData(dgAffinityMatrix3, j);
				break;
			case 3:
				check = setAffinityMatrixData(dgAffinityMatrix4, j);
				break;
			case 4:
				check = setAffinityMatrixData(dgAffinityMatrix5, j);
				break;
			case 5:
				check = setAffinityMatrixData(dgAffinityMatrix6, j);
				break;
			case 6:
				check = setAffinityMatrixData(dgAffinityMatrix7, j);
				break;
			case 7:
				check = setAffinityMatrixData(dgAffinityMatrix8, j);
				break;
			case 8:
				check = setAffinityMatrixData(dgAffinityMatrix9, j);
				break;
			case 9:
				check = setAffinityMatrixData(dgAffinityMatrix10, j);
				break;
			default:
				break;
			}
		}
		if (check) {
			lvLUT->Items[lvLUT->Items->Count - 1]->SubItems->Add("OK");
		}
	}

	if (check) {
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
}

System::Void LuccME::P_AttractRepulseLogisticRegression::bCancel_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void LuccME::P_AttractRepulseLogisticRegression::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
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
		for (int i = 0; i < lvLUT->Items->Count - 1; i++) {
			this->lReturn->Return += lTempBetas[i];
			if (i + 1 < lvLUT->Items->Count) {
				this->lReturn->Return = this->lReturn->Return->Replace("\n", "");
				this->lReturn->Return = this->lReturn->Return->Replace("\r", "");
				this->lReturn->Return += "#";
			}
		}
		this->lReturn->Return += "&";
		for (int i = 0; i < lReturn->Regression; i++) {
			this->lReturn->Return += lTempValues[i];
			this->lReturn->Return = this->lReturn->Return->Replace("\n", "");
			this->lReturn->Return = this->lReturn->Return->Replace("\r", "");
		}
		this->Close();
	}
	else {
		MessageBox::Show(gSEmptyComponent, gSEmptyComponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void LuccME::P_AttractRepulseLogisticRegression::copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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

System::Void LuccME::P_AttractRepulseLogisticRegression::pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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

#include "stdafx.h"
#include "P_ContinuousR.h"
#include "Function.h"

using namespace System::Windows::Forms;

/*
Count the number of a caracter on a string
*/
System::Int16 LuccME::P_ContinuousR::countCaracter(String^ source, char caracter)
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
Used on the enter focus to change default values and colors
*/
System::Void LuccME::P_ContinuousR::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

/*
Initialized all the regions on tcRegions for the default values
*/
System::Void LuccME::P_ContinuousR::initializeRegions()
{
	dgBetas->ColumnCount = 2;
	dgBetas->Columns[0]->Name = gSAttributes;
	dgBetas->Columns[1]->Name = gSValues;
	dgBetas->Rows->Clear();
	cIsLog->Checked = false;
	tConst->Text = "0.01";
	tConst->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == 7) {
		tMinReg->Text = "0";
		tMinReg->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tMaxReg->Text = "1";
		tMaxReg->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tRo->Text = "0.5";
		tRo->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas2->ColumnCount = 2;
	dgBetas2->Columns[0]->Name = gSAttributes;
	dgBetas2->Columns[1]->Name = gSValues;
	dgBetas2->Rows->Clear();
	cIsLog2->Checked = false;
	tConst2->Text = "0.01";
	tConst2->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == 7) {
		tMinReg2->Text = "0";
		tMinReg2->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tMaxReg2->Text = "1";
		tMaxReg2->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tRo2->Text = "0.5";
		tRo2->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas3->ColumnCount = 2;
	dgBetas3->Columns[0]->Name = gSAttributes;
	dgBetas3->Columns[1]->Name = gSValues;
	dgBetas3->Rows->Clear();
	cIsLog3->Checked = false;
	tConst3->Text = "0.01";
	tConst3->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == 7) {
		tMinReg3->Text = "0";
		tMinReg3->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tMaxReg3->Text = "1";
		tMaxReg3->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tRo3->Text = "0.5";
		tRo3->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas4->ColumnCount = 2;
	dgBetas4->Columns[0]->Name = gSAttributes;
	dgBetas4->Columns[1]->Name = gSValues;
	dgBetas4->Rows->Clear();
	cIsLog4->Checked = false;
	tConst4->Text = "0.01";
	tConst4->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == 7) {
		tMinReg4->Text = "0";
		tMinReg4->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tMaxReg4->Text = "1";
		tMaxReg4->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tRo4->Text = "0.5";
		tRo4->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas5->ColumnCount = 2;
	dgBetas5->Columns[0]->Name = gSAttributes;
	dgBetas5->Columns[1]->Name = gSValues;
	dgBetas5->Rows->Clear();
	cIsLog5->Checked = false;
	tConst5->Text = "0.01";
	tConst5->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == 7) {
		tMinReg5->Text = "0";
		tMinReg5->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tMaxReg5->Text = "1";
		tMaxReg5->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tRo5->Text = "0.5";
		tRo5->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas6->ColumnCount = 2;
	dgBetas6->Columns[0]->Name = gSAttributes;
	dgBetas6->Columns[1]->Name = gSValues;
	dgBetas6->Rows->Clear();
	cIsLog6->Checked = false;
	tConst6->Text = "0.01";
	tConst6->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == 7) {
		tMinReg6->Text = "0";
		tMinReg6->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tMaxReg6->Text = "1";
		tMaxReg6->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tRo6->Text = "0.5";
		tRo6->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas7->ColumnCount = 2;
	dgBetas7->Columns[0]->Name = gSAttributes;
	dgBetas7->Columns[1]->Name = gSValues;
	dgBetas7->Rows->Clear();
	cIsLog7->Checked = false;
	tConst7->Text = "0.01";
	tConst7->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == 7) {
		tMinReg7->Text = "0";
		tMinReg7->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tMaxReg7->Text = "1";
		tMaxReg7->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tRo7->Text = "0.5";
		tRo7->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas8->ColumnCount = 2;
	dgBetas8->Columns[0]->Name = gSAttributes;
	dgBetas8->Columns[1]->Name = gSValues;
	dgBetas8->Rows->Clear();
	cIsLog8->Checked = false;
	tConst8->Text = "0.01";
	tConst8->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == 7) {
		tMinReg8->Text = "0";
		tMinReg8->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tMaxReg8->Text = "1";
		tMaxReg8->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tRo8->Text = "0.5";
		tRo8->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas9->ColumnCount = 2;
	dgBetas9->Columns[0]->Name = gSAttributes;
	dgBetas9->Columns[1]->Name = gSValues;
	dgBetas9->Rows->Clear();
	cIsLog9->Checked = false;
	tConst9->Text = "0.01";
	tConst9->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == 7) {
		tMinReg9->Text = "0";
		tMinReg9->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tMaxReg9->Text = "1";
		tMaxReg9->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tRo9->Text = "0.5";
		tRo9->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}

	dgBetas10->ColumnCount = 2;
	dgBetas10->Columns[0]->Name = gSAttributes;
	dgBetas10->Columns[1]->Name = gSValues;
	dgBetas10->Rows->Clear();
	cIsLog10->Checked = false;
	tConst10->Text = "0.01";
	tConst10->ForeColor = System::Drawing::SystemColors::ScrollBar;
	if (lReturn->Component == 7) {
		tMinReg10->Text = "0";
		tMinReg10->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tMaxReg10->Text = "1";
		tMaxReg10->ForeColor = System::Drawing::SystemColors::ScrollBar;
		tRo10->Text = "0.5";
		tRo10->ForeColor = System::Drawing::SystemColors::ScrollBar;
	}
	tcRegions->SelectedIndex = 0;
}

/*
Make the components of a tRagion visible or not
*/
System::Void LuccME::P_ContinuousR::setVisibleONorOFF(Label^ lBetas, DataGridView^ dgBetas, CheckBox^ cIsLog, Label^ lConst, TextBox^ tConst, Label^ lMinReg, TextBox^ tMinReg, Label^ lMaxReg, TextBox^ tMaxReg, Label^ lRo, TextBox^ tRo, bool status)
{
	lBetas->Visible = status;
	dgBetas->ColumnCount = 2;
	dgBetas->Columns[0]->Name = gSAttributes;
	dgBetas->Columns[1]->Name = gSValues;
	dgBetas->Visible = status;
	cIsLog->Visible = status;
	lConst->Visible = status;
	tConst->Visible = status;
	if (lReturn->Component == 7) {
		lMinReg->Visible = status;
		tMinReg->Visible = status;
		lMaxReg->Visible = status;
		tMaxReg->Visible = status;
		lRo->Visible = status;
		tRo->Visible = status;
	}
}

/*
Used when a tRegion is deleted, it copies the data from the tRegions higher than the deleted one.
*/
System::Void LuccME::P_ContinuousR::moveData(DataGridView^ dgBetas, CheckBox^ cIsLog, TextBox^ tConst, TextBox^ tMinReg, TextBox^ tMaxReg, TextBox^ tRo, DataGridView^ dgBetas2, CheckBox^ cIsLog2, TextBox^ tConst2, TextBox^ tMinReg2, TextBox^ tMaxReg2, TextBox^ tRo2)
{
	dgBetas->Rows->Clear();
	for (int i = 0; i < dgBetas2->RowCount - 1; i++) {
		dgBetas->Rows->Add();
		dgBetas->Rows[i]->Cells[0]->Value = dgBetas2->Rows[i]->Cells[0]->Value;
		dgBetas->Rows[i]->Cells[1]->Value = dgBetas2->Rows[i]->Cells[1]->Value;
	}
	cIsLog->Checked = cIsLog2->Checked;
	tConst->Text = tConst2->Text;
	if (lReturn->Component == 7) {
		tMinReg->Text = tMinReg2->Text;
		tMaxReg->Text = tMaxReg2->Text;
		tRo->Text = tRo2->Text;
	}
}

/*
Used to set the tRegions data from lReturn->Return, it copies the lTempBetas data to tRegion
*/
System::Int16 LuccME::P_ContinuousR::getRegionData(array<String^>^ lTempBetas, cReturnPotential^ lReturn, DataGridView^ dgBetas, CheckBox^ cIsLog, TextBox^ tConst, TextBox^ tMinReg, TextBox^ tMaxReg, TextBox^ tRo, int i, int j)
{
	bool isLog = false;

	if (lTempBetas[i][j] == '1') {
		isLog = true;
	}
	j += 2;
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

	return j;
}

/*
Used to save the tRegions data to lReturn->Return, it copies the tRegion data to lTempBetas
*/
System::Void LuccME::P_ContinuousR::setRegionData(DataGridView^ dgBetas, CheckBox^ cIsLog, TextBox^ tConst, TextBox^ tMinReg, TextBox^ tMaxReg, TextBox^ tRo, int i, int j)
{
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
	lTempBetas[i] += "*";
	lReturn->Regression += 1;
}

/*
Locate the initial cell for copying or pasting
*/
System::Windows::Forms::DataGridViewCell ^ LuccME::P_ContinuousR::GetStartCell(System::Windows::Forms::DataGridView ^ dgView)
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
System::Void LuccME::P_ContinuousR::dgBetas_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
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
				if (dgView->SelectedCells->Count != 0)
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
		MessageBox::Show("Copy/paste operation failed. " + ex->Message, "Copy/Paste", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

/*
Copy the clipboard data
*/
System::Void LuccME::P_ContinuousR::CopyToClipboard(DataGridView^ dgView)
{
	DataObject^ dataObj = dgView->GetClipboardContent();
	if (dataObj != nullptr) {
		Clipboard::SetDataObject(dataObj);
	}
}


/*
Paste the clipboard data
*/
System::Void LuccME::P_ContinuousR::PasteClipboardValue(DataGridView^ dgView)
{
	//Show Error if no cell is selected
	if (dgView->SelectedCells->Count == NONE)
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

System::Void LuccME::P_ContinuousR::P_ContinuousR_Shown(System::Object^  sender, System::EventArgs^  e)
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

	if (this->lReturn->Component == 7) {
		this->Height = 674;
		this->lvLUT->Height = 430;
		this->tcRegions->Height = 429;
		bSalvar->Location = Point(238, 600);
		bCancel->Location = Point(271, 600);
		bAddBetas->Location = Point(375, 600);
		
		lBetas->Location = Point(117, 178);
		dgBetas->Location = Point(20, 207);
		dgBetas->Height = this->dgBetas->Height - 60;
		lBetas2->Location = Point(117, 178);
		dgBetas2->Location = Point(20, 207);
		dgBetas2->Height = this->dgBetas2->Height - 60;
		lBetas3->Location = Point(117, 178);
		dgBetas3->Location = Point(20, 207);
		dgBetas3->Height = this->dgBetas3->Height - 60;
		lBetas4->Location = Point(117, 178);
		dgBetas4->Location = Point(20, 207);
		dgBetas4->Height = this->dgBetas4->Height - 60;
		lBetas5->Location = Point(117, 178);
		dgBetas5->Location = Point(20, 207);
		dgBetas5->Height = this->dgBetas5->Height - 60;
		lBetas6->Location = Point(117, 178);
		dgBetas6->Location = Point(20, 207);
		dgBetas6->Height = this->dgBetas6->Height - 60;
		lBetas7->Location = Point(117, 178);
		dgBetas7->Location = Point(20, 207);
		dgBetas7->Height = this->dgBetas7->Height - 60;
		lBetas8->Location = Point(117, 178);
		dgBetas8->Location = Point(20, 207);
		dgBetas8->Height = this->dgBetas8->Height - 60;
		lBetas9->Location = Point(117, 178);
		dgBetas9->Location = Point(20, 207);
		dgBetas9->Height = this->dgBetas9->Height - 60;
		lBetas10->Location = Point(117, 178);
		dgBetas10->Location = Point(20, 207);
		dgBetas10->Height = this->dgBetas10->Height - 60;
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

	tcRegions->SelectedIndex = 0;
}

System::Void LuccME::P_ContinuousR::lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
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
								j = getRegionData(lTempBetas, lReturn, dgBetas, cIsLog, tConst, tMinReg, tMaxReg, tRo, i, j);
								break;
							case 1:
								j = getRegionData(lTempBetas, lReturn, dgBetas2, cIsLog2, tConst2, tMinReg2, tMaxReg2, tRo2, i, j);
								break;
							case 2:
								j = getRegionData(lTempBetas, lReturn, dgBetas3, cIsLog3, tConst3, tMinReg3, tMaxReg3, tRo3, i, j);
								break;
							case 3:
								j = getRegionData(lTempBetas, lReturn, dgBetas4, cIsLog4, tConst4, tMinReg4, tMaxReg4, tRo4, i, j);
								break;
							case 4:
								j = getRegionData(lTempBetas, lReturn, dgBetas5, cIsLog5, tConst5, tMinReg5, tMaxReg5, tRo5, i, j);
								break;
							case 5:
								j = getRegionData(lTempBetas, lReturn, dgBetas6, cIsLog6, tConst6, tMinReg6, tMaxReg6, tRo6, i, j);
								break;
							case 6:
								j = getRegionData(lTempBetas, lReturn, dgBetas7, cIsLog7, tConst7, tMinReg7, tMaxReg7, tRo7, i, j);
								break;
							case 7:
								j = getRegionData(lTempBetas, lReturn, dgBetas8, cIsLog8, tConst8, tMinReg8, tMaxReg8, tRo8, i, j);
								break;
							case 8:
								j = getRegionData(lTempBetas, lReturn, dgBetas9, cIsLog9, tConst9, tMinReg9, tMaxReg9, tRo9, i, j);
								break;
							case 9:
								j = getRegionData(lTempBetas, lReturn, dgBetas10, cIsLog10, tConst10, tMinReg10, tMaxReg10, tRo10, i, j);
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

System::Void LuccME::P_ContinuousR::tcRegions_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
{
	bDeleteRegression->Visible = false;
	if (tcRegions->SelectedIndex == (tcRegions->TabCount - 1)) {
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
				setVisibleONorOFF(lBetas, dgBetas, cIsLog, lConst, tConst, lMinReg, tMinReg, lMaxReg, tMaxReg, lRo, tRo, true);
				break;
			case 1:
				setVisibleONorOFF(lBetas2, dgBetas2, cIsLog2, lConst2, tConst2, lMinReg2, tMinReg2, lMaxReg2, tMaxReg2, lRo2, tRo2, true);
				break;
			case 2:
				setVisibleONorOFF(lBetas3, dgBetas3, cIsLog3, lConst3, tConst3, lMinReg3, tMinReg3, lMaxReg3, tMaxReg3, lRo3, tRo3, true);
				break;
			case 3:
				setVisibleONorOFF(lBetas4, dgBetas4, cIsLog4, lConst4, tConst4, lMinReg4, tMinReg4, lMaxReg4, tMaxReg4, lRo4, tRo4, true);
				break;
			case 4:
				setVisibleONorOFF(lBetas5, dgBetas5, cIsLog5, lConst5, tConst5, lMinReg5, tMinReg5, lMaxReg5, tMaxReg5, lRo5, tRo5, true);
				break;
			case 5:
				setVisibleONorOFF(lBetas6, dgBetas6, cIsLog6, lConst6, tConst6, lMinReg6, tMinReg6, lMaxReg6, tMaxReg6, lRo6, tRo6, true);
				break;
			case 6:
				setVisibleONorOFF(lBetas7, dgBetas7, cIsLog7, lConst7, tConst7, lMinReg7, tMinReg7, lMaxReg7, tMaxReg7, lRo7, tRo7, true);
				break;
			case 7:
				setVisibleONorOFF(lBetas8, dgBetas8, cIsLog8, lConst8, tConst8, lMinReg8, tMinReg8, lMaxReg8, tMaxReg8, lRo8, tRo8, true);
				break;
			case 8:
				setVisibleONorOFF(lBetas9, dgBetas9, cIsLog9, lConst9, tConst9, lMinReg9, tMinReg9, lMaxReg9, tMaxReg9, lRo9, tRo9, true);
				break;
			case 9:
				setVisibleONorOFF(lBetas10, dgBetas10, cIsLog10, lConst10, tConst10, lMinReg10, tMinReg10, lMaxReg10, tMaxReg10, lRo10, tRo10, true);
				break;
			default:
				break;
		}
	}
	
	if (tcRegions->SelectedIndex > 0) {
		bDeleteRegression->Visible = true;
	}
}

System::Void LuccME::P_ContinuousR::bDeleteRegression_Click(System::Object^  sender, System::EventArgs^  e)
{
	int rToRemove = tcRegions->SelectedIndex;
	int rNumber = tcRegions->TabCount;
	if (rToRemove > 0) {
		for (int i = rToRemove; i < rNumber-1; i++) {
			switch (i)
			{
			case 1:
				moveData(dgBetas2, cIsLog2, tConst2, tMinReg2, tMaxReg2, tRo2, dgBetas3, cIsLog3, tConst3, tMinReg3, tMaxReg3, tRo3);
				break;
			case 2:
				moveData(dgBetas3, cIsLog3, tConst3, tMinReg3, tMaxReg3, tRo3, dgBetas4, cIsLog4, tConst4, tMinReg4, tMaxReg4, tRo4);
				break;
			case 3:
				moveData(dgBetas4, cIsLog4, tConst4, tMinReg4, tMaxReg4, tRo4, dgBetas5, cIsLog5, tConst5, tMinReg5, tMaxReg5, tRo5);
				break;
			case 4:
				moveData(dgBetas5, cIsLog5, tConst5, tMinReg5, tMaxReg5, tRo5, dgBetas6, cIsLog6, tConst6, tMinReg6, tMaxReg6, tRo6);
				break;
			case 5:
				moveData(dgBetas6, cIsLog6, tConst6, tMinReg6, tMaxReg6, tRo6, dgBetas7, cIsLog7, tConst7, tMinReg7, tMaxReg7, tRo7);
				break;
			case 6:
				moveData(dgBetas7, cIsLog7, tConst7, tMinReg7, tMaxReg7, tRo7, dgBetas8, cIsLog8, tConst8, tMinReg8, tMaxReg8, tRo8);
				break;
			case 7:
				moveData(dgBetas8, cIsLog8, tConst8, tMinReg8, tMaxReg8, tRo8, dgBetas9, cIsLog9, tConst9, tMinReg9, tMaxReg9, tRo9);
				break;
			case 8:
				moveData(dgBetas9, cIsLog9, tConst9, tMinReg9, tMaxReg9, tRo9, dgBetas10, cIsLog10, tConst10, tMinReg10, tMaxReg10, tRo10);
				break;
			default:
				break;
			}
		}
		tcRegions->TabPages->RemoveAt(tcRegions->TabCount - 1);
		tcRegions->TabPages[tcRegions->TabCount - 1]->Text = "+";
		tcRegions->SelectedIndex = 0;

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
						else if(r > rToRemove){
							aux += lTempBetas[i]->Substring(lRegionsLocation[count] + 1, (lRegionsLocation[count + 1]- lRegionsLocation[count]));
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

System::Void LuccME::P_ContinuousR::bCancel_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void LuccME::P_ContinuousR::bAddBetas_Click(System::Object^  sender, System::EventArgs^  e)
{
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		if (lvLUT->Items[i]->Selected == true) {
			lReturn->Regression = 0;
			lTempBetas[i] = "";
			for (int j = 0; j < tcRegions->TabCount - 1; j++) {
				switch (j)
				{
				case 0:
					setRegionData(dgBetas, cIsLog, tConst, tMinReg, tMaxReg, tRo, i, j);
					break;
				case 1:
					setRegionData(dgBetas2, cIsLog2, tConst2, tMinReg2, tMaxReg2, tRo2, i, j);
					break;
				case 2:
					setRegionData(dgBetas3, cIsLog3, tConst3, tMinReg3, tMaxReg3, tRo3, i, j);
					break;
				case 3:
					setRegionData(dgBetas4, cIsLog4, tConst4, tMinReg4, tMaxReg4, tRo4, i, j);
					break;
				case 4:
					setRegionData(dgBetas5, cIsLog5, tConst5, tMinReg5, tMaxReg5, tRo5, i, j);
					break;
				case 5:
					setRegionData(dgBetas6, cIsLog6, tConst6, tMinReg6, tMaxReg6, tRo6, i, j);
					break;
				case 6:
					setRegionData(dgBetas7, cIsLog7, tConst7, tMinReg7, tMaxReg7, tRo7, i, j);
					break;
				case 7:
					setRegionData(dgBetas8, cIsLog8, tConst8, tMinReg8, tMaxReg8, tRo8, i, j);
					break;
				case 8:
					setRegionData(dgBetas9, cIsLog9, tConst9, tMinReg9, tMaxReg9, tRo9, i, j);
					break;
				case 9:
					setRegionData(dgBetas10, cIsLog10, tConst10, tMinReg10, tMaxReg10, tRo10, i, j);
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

System::Void LuccME::P_ContinuousR::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
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

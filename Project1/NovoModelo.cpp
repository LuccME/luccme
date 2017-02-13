#include "stdafx.h"
#include "NovoModelo.h"
#include "LanguageForm.h"
#include "AboutForm.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


/*
Define all the used Strings, for portuguese and english.
*/
System::Void CellFulfill::NovoModelo::checkLanguage()
{
	//Select Strings according to the selected language
	if (lLanguage == "en") {
		this->Text = "Creating a New Script";
		
		//tpScript
		tpScript->Text = "Script Definition";
		lFiles->Text = "Files";
		lDirProj->Text = "Folder to Save Scripts";
		bSelectFolder->Text = "Select";
		lScriptDefinition->Text = "Script Definition";
		lScriptName->Text = "Script Name";

		//tpCellularSpace
		tpCellularSpace->Text = "Creating Cellular Space";
		lLimitFile->Text = "File for Cellular Space Limit";
		bShape->Text = "Select";
		lCellSpaceName->Text = "Cellular Space Output Name";
		lCellSpaceResolution->Text = "Resolution";
		
		//tpAttributeFill
		tpAttributeFill->Text = "Attributes to Fill";
		bDeleteAttribute->Text = "Remove";
		lOperationName->Text = "Select an Operation";
		lOperationOut->Text = "Output Attribute";
		lSelectOperation->Text = "Input Attribute";
		lDefaultOperation->Text = "Dummy Value";
		lAreaOperation->Text = "Use Area Geometry";
		
		//Strings
		gSShapeTitle = "Select a Shape File";
		gSShapeFilter = "Shape File (*.shp)|*.shp";
		gSAttributes = "Attributes";
		gSFileFormatError = "File added is not suported: ";
		gSFileFormatErrorTitle = "Invalid file type";
		gSAttributesTitle = "Select the Attribute(s) File(s)";
		gSAttributesFilter = "Shape File (*.shp)|*.shp|TIF File (*.tif)|*.tif| All Files (*.*)|*.*";
		gSDeleteAttribute = "Do you want to remove the attribute: ";
		gSDeleteAttributeTitle = "Removing Attribute";
		gSFolder = "Project folder not selected in Model Definition.";
		gSFolderTitle = "Error - Project folder is missing";
		gSScriptName = "Script Name not defined in Model Definition.";
		gSScriptNameTitle = "Error - Script Name is missing";
		gSUnauthorized = "You do not have writting permission on the selected folder.\nTry a different one or run LuccME as admin.";
		gSUnauthorizedTitle = "Error - Writting Permimission";
		gSSuccessTitle = "File successfully generate";
		gSSuccess = "File successfully recorded:\n";
		gSFileMissing = "Error writing the File.\nCheck the path:";
		gSFileMissingTitle = "Make File Error";
		gSMFE = "Error recording the file.";
		gSMFETitle = "Error - File Generation";
		gSFE = "An unexpected error while recording the file.";
		gSLimitFileAddress = "Limit File not defined in Creating Cellular Spcae.";
		gSLimitFileAddressTitle = "Error - Limit File is missing";
		gSLimitFileAddress2 = "Limit File is not supported: ";
		gSLimitFileAddress2Title = "Error - Limit File is not supported";
		gSAOMissing = "All Attributes Operations must be defined in Attributes to Fill.";
		gSAOMissingTitle = "Error - Missing Attributes Operation";
		gSCellSpaceName = "Cellular Space Name not defined in Creating Cellular Space.";
		gSCellSpaceNameTitle = "Error - Cellular Space Name is missing";
		gSCellSpaceResolution = "Cellular Space Resolution not defined in Creating Cellular Space.";
		gSCellSpaceResolutionTitle = "Error - Cellular Space Resolution is missing";
	}
	else {
		this->Text = "Criando um Novo Script";
		
		//tpScript
		tpScript->Text = "Definições do Script";
		lFiles->Text = "Arquivos";
		lDirProj->Text = "Pasta para Salvar os Scripts";
		bSelectFolder->Text = "Selecionar";
		lScriptDefinition->Text = "Definições do Script";
		lScriptName->Text = "Nome do Script";

		//tpCellularSpace
		tpCellularSpace->Text = "Criando o Espaço Celular";
		lLimitFile->Text = "Arquivo de Limite do Espaço Celular";
		bShape->Text = "Selecionar";
		lCellSpaceName->Text = "Nome do Saída do Espaço Celular";
		lCellSpaceResolution->Text = "Resolução";

		//tpAttributeFill
		tpAttributeFill->Text = "Atributos de Preenchimento";
		bDeleteAttribute->Text = "Remover";
		lOperationName->Text = "Selecione uma Operação";
		lOperationOut->Text = "Atributo de Saída";
		lSelectOperation->Text = "Atributo de Entrada";
		lDefaultOperation->Text = "Valor de Dummy";
		lAreaOperation->Text = "Usar Geometria da Área";

		//Strigs
		gSShapeTitle = "Escolha o arquivo Shape";
		gSShapeFilter = "Arquivo Shape (*.shp)|*.shp";
		gSAttributes = "Atributos";
		gSFileFormatError = "Arquivo adicionado não é suportado: ";
		gSFileFormatErrorTitle = "Tipo de Arquivo inválido";
		gSAttributesTitle = "Selecione os Arquivos dos Atributos";
		gSAttributesFilter = "Shape File (*.shp)|*.shp|TIF File (*.tif)|*.tif| All Files (*.*)|*.*";
		gSDeleteAttribute = "Você deseja remover o atributo: ";
		gSDeleteAttributeTitle = "Removendo Atributo";
		gSFolder = "Pasta do projeto não selecionada em Definições do Modelo.";
		gSFolderTitle = "Erro - Pasta do projeto não selecionada";
		gSScriptName = "Nome do Script não definido em Definições do Modelo.";
		gSScriptNameTitle = "Erro - Nome do Script não definido";
		gSUnauthorized = "Você não possui permissão de escrita no diretório selecionado.\nEscolha outro diretório ou execute o LuccME como administrador.";
		gSUnauthorizedTitle = "Erro - Permissão de escrita";
		gSSuccessTitle = "Arquivo gerado com Sucesso";
		gSSuccess = "Arquivo gravado com sucesso:\n";
		gSFileMissing = "Erro na gravação do arquivo.\nVerifique o caminho:";
		gSFileMissingTitle = "Erro na geração do Arquivo";
		gSMFE = "Erro na gravação do arquivo.";
		gSMFETitle = "Erro - Geração do Arquivo";
		gSFE = "Erro não esperado gravando o arquivo.";
		gSLimitFileAddress = "Arquivo de Limite não definido em Criando Espaço Celular.";
		gSLimitFileAddressTitle = "Erro - Arquivo de Limite não definido";
		gSLimitFileAddress2 = "Arquivo de limite não suportado: ";
		gSLimitFileAddress2Title = "Error - Arquivo de Limite não suportado";
		gSAOMissing = "Todos os atributos devem ter suas operações definidas em Atributos de Preenchimento.";
		gSAOMissingTitle = "Erro - Operações de Atributos não definida";
		gSCellSpaceName = "Nome do Espaço Celular não definido em Criando o Espaço Celular.";
		gSCellSpaceNameTitle = "Erro - Nome do Espaço Celular não definido";
		gSCellSpaceResolution = "Resolução do Espaço Celular não definido em Criando o Espaço Celular.";
		gSCellSpaceResolutionTitle = "Erro - Resolução do Espaço Celular não definida";
	}
}


/*
Set the Operation VIsual OFF
*/
System::Void CellFulfill::NovoModelo::operationVisualOFF()
{
	cbOperation->Items->Clear();
	cbOperation->Visible = false;
	
	lOperationName->Visible = false;
	lOperationOut->Visible = false;
	lDefaultOperation->Visible = false;
	lSelectOperation->Visible = false;
	lAreaOperation->Visible = false;

	tOperationOut->Text = "";
	tOperationOut->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tOperationOut->Visible = false;
	
	tSelectOperation->Text = "use0";
	tSelectOperation->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tSelectOperation->Visible = false;

	tDefaultOperation->Text = "";
	tDefaultOperation->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tDefaultOperation->Visible = false;
	
	rbFalseOperation->Checked = true;
	rbTrueOperation->Visible = false;
	rbFalseOperation->Visible = false;
	
	
	
	for (int i = 0; i < lvAttributesToFill->Items->Count; i++) {
		lvAttributesToFill->Items[i]->Selected = false;
	}

	tSelectedAttribute->Text = "";
	tSelectedAttribute->Visible = false;
	lvAttributesToFill->Visible = true;
	
	bSaveOperation->Visible = false;
	bDeleteAttribute->Visible = false;
	bAddAttribute->Visible = true;
}

/*
Return the index for an Vector Operation
*/
System::Int32 CellFulfill::NovoModelo::attributeToindex()
{
	for (int i = 0; i < lvAttributesToFill->Items->Count; i++) {
		if (lvAttributesToFill->Items[i]->Selected) {
			return i;
		}
	}
}

/*
Return the Operation name based on the index
*/
System::String^ CellFulfill::NovoModelo::vectorOperationToName(int operation)
{
	if (operation == 0) {
		return "coverage";
	}
	else if (operation == 1) {
		return "average";
	}
	else if (operation == 2) {
		return "area";
	}
	else if (operation == 3) {
		return "distance";
	}
	else if (operation == 4) {
		return "presence";
	}
	else if (operation == 5) {
		return "mode";
	}
	else if (operation == 6) {
		return "maximum";
	}
	else if (operation == 7) {
		return "minimum";
	}
	else if (operation == 8) {
		return "sum";
	}
	else if (operation == 9) {
		return "count";
	}
	else if (operation == 10) {
		return "length";
	}
	else if (operation == 11) {
		return "stdev";
	}
	else if (operation == 12) {
		return "nearest";
	}
}

/*
Return the Operation name based on the index
*/
System::String^ CellFulfill::NovoModelo::rasterOperationToName(int operation)
{
	if (operation == 0) {
		return "coverage";
	}
	else if (operation == 1) {
		return "average";
	}
	else if (operation == 2) {
		return "mode";
	}
	else if (operation == 3) {
		return "maximum";
	}
	else if (operation == 4) {
		return "minimum";
	}
	else if (operation == 5) {
		return "sum";
	}
	else if (operation == 6) {
		return "stdev";
	}
}

/*
Return the index for an Vector Operation 
*/
System::Int32 CellFulfill::NovoModelo::vectorOperationToindex(String^ operation)
{
	if (operation->Equals("coverage")) {
		return 0;
	} 
	else if (operation->Equals("average")) {
		return 1;
	}
	else if (operation->Equals("area")) {
		return 2;
	}
	else if (operation->Equals("distance")) {
		return 3;
	}
	else if (operation->Equals("presence")) {
		return 4;
	}
	else if (operation->Equals("mode")) {
		return 5;
	}
	else if (operation->Equals("maximum")) {
		return 6;
	}
	else if (operation->Equals("minimum")) {
		return 7;
	}
	else if (operation->Equals("sum")) {
		return 8;
	}
	else if (operation->Equals("count")) {
		return 9;
	}
	else if (operation->Equals("length")) {
		return 10;
	}
	else if (operation->Equals("stdev")) {
		return 11;
	}
	else if (operation->Equals("nearest")) {
		return 12;
	}
}

/*
Return the index for an Raster Operation
*/
System::Int32 CellFulfill::NovoModelo::rasterOperationToindex(String^ operation)
{
	if (operation->Equals("coverage")) {
		return 0;
	}
	else if (operation->Equals("average")) {
		return 1;
	}
	else if (operation->Equals("mode")) {
		return 2;
	}
	else if (operation->Equals("maximum")) {
		return 3;
	}
	else if (operation->Equals("minimum")) {
		return 4;
	}
	else if (operation->Equals("sum")) {
		return 5;
	}
	else if (operation->Equals("stdev")) {
		return 6;
	}
}

/*
Visual Effect on TextBox Components
*/
System::Void CellFulfill::NovoModelo::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	//Create the efect of a edited TextBox (must select this function on focus->enter property of a TextBox)
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void CellFulfill::NovoModelo::CellFulfillToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		Help::ShowHelp(this, "help.chm");
	}
	else {
		Help::ShowHelp(this, "ajuda.chm");
	}
}

System::Void CellFulfill::NovoModelo::abrirToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	lReturn = OPENSCRIPT;
	this->Close();
}

System::Void CellFulfill::NovoModelo::novoToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	lReturn = NEWSCRIPT;
	this->Close();
}

System::Void CellFulfill::NovoModelo::sobreToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AboutForm^ aboutForm = gcnew AboutForm(lLanguage);
	aboutForm->ShowInTaskbar = false;
	aboutForm->ShowDialog();
}

System::Void CellFulfill::NovoModelo::sairToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Application::Exit();
}

System::Void CellFulfill::NovoModelo::idiomaToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LanguageForm^ languageForm = gcnew LanguageForm(lLanguage);
	languageForm->ShowInTaskbar = false;
	languageForm->MinimizeBox = false;
	languageForm->MaximizeBox = false;
	languageForm->ShowDialog();
	lLanguage = languageForm->lLanguage;
	checkLanguage();
	NovoModelo::Update();
}

System::Void CellFulfill::NovoModelo::bSelectFolder_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Open the dialog to select a folder and return the path
	CellFulfill::FolderBrowserDialog^ modelFolder = gcnew FolderBrowserDialog();

	if (modelFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		lSelectedFolder->Text = modelFolder->SelectedPath;
	}
}

System::Void CellFulfill::NovoModelo::bShape_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Open the dialog to select the shape file and return the path
	CellFulfill::OpenFileDialog^ shapeFile = gcnew OpenFileDialog;
	shapeFile->Title = gSShapeTitle;
	shapeFile->Multiselect = false;
	shapeFile->Filter = gSShapeFilter;
	shapeFile->FilterIndex = 1;
	shapeFile->ShowHelp = true;

	if (shapeFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		lLimitFileAddress->Text = shapeFile->FileName;
	}
}

System::Void CellFulfill::NovoModelo::tabControl1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (tabControl1->SelectedIndex == ATTRFULFILL) {
		if (lvAttributesToFill->Columns->Count == NONE) {
			lvAttributesToFill->Clear();
			lvAttributesToFill->View = View::Details;
			lvAttributesToFill->GridLines = true;
			lvAttributesToFill->Columns->Add(gSAttributes, lvAttributesToFill->Width - 50, HorizontalAlignment::Left);
			lvAttributesToFill->Columns->Add("Status", 47, HorizontalAlignment::Center);
		}
	}
}

System::Void CellFulfill::NovoModelo::lvAttributesToFill_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
	try
	{
		auto filePaths = dynamic_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop));
		Collections::ArrayList^ attributeErrorList = gcnew Collections::ArrayList();
		int lastSlash = 0;
		bool error = false;

		if (filePaths != nullptr && filePaths->Length > 0) {
			for (int i = 0; i < filePaths->Length; i++) {
				if (filePaths[i]->Contains(".shp") || filePaths[i]->Contains(".tif")) {
					array<String^>^ attributeToList = { filePaths[i], "", "", "", "", "" };
					attributeList->Add(attributeToList);
					lastSlash = 0;
					for (int j = 0; j < filePaths[i]->Length; j++) {
						if (filePaths[i][j] == '\\') {
							lastSlash = j + 1;
						}
					}
					lvAttributesToFill->Items->Add(filePaths[i]->Substring(lastSlash, filePaths[i]->Length - lastSlash));
				}
				else {
					error = true;
					lastSlash = 0;
					for (int j = 0; j < filePaths[i]->Length; j++) {
						if (filePaths[i][j] == '\\') {
							lastSlash = j + 1;
						}
					}
					attributeErrorList->Add(filePaths[i]->Substring(lastSlash, filePaths[i]->Length - lastSlash));
				}
			}

			if (error) {
				System::Threading::Thread::Sleep(SECOND/4);
				for (int i = 0; i < attributeErrorList->Count; i++) {
					MessageBox::Show(gSFileFormatError + attributeErrorList[i], gSFileFormatErrorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
	}
	catch (...)
	{

	}
}

System::Void CellFulfill::NovoModelo::lvAttributesToFill_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	bAddAttribute->Visible = false;
	bDeleteAttribute->Visible = true;

	if (bSaveOperation->Visible == false) {
		int i = attributeToindex();
		
		tSelectedAttribute->Text = lvAttributesToFill->Items[i]->Text;
		tSelectedAttribute->Visible = true;
		lvAttributesToFill->Visible = false;
		
		if (lvAttributesToFill->Items[i]->Text->Contains(".shp")) {
			cbOperation->Items->Clear();
			cbOperation->Items->AddRange(vectorList);
			
			lOperationName->Visible = true;
			cbOperation->Visible = true;
			bSaveOperation->Visible = true;

			array<String^>^ dataTemp = safe_cast<array<String^>^>(attributeList[i]);
			
			if (dataTemp[AS_OPERATION] != "") {
				cbOperation->SelectedIndex = vectorOperationToindex(dataTemp[AS_OPERATION]);
				switch (cbOperation->SelectedIndex)
				{
				case 0:
				case 5:
				case 6:
				case 7:
				case 11:
					if (dataTemp[AS_OUTPUT] != "") {
						tOperationOut->Text = dataTemp[AS_OUTPUT];
						tOperationOut->ForeColor = System::Drawing::Color::Black;
					}
					if (dataTemp[AS_SELECT] != "") {
						tSelectOperation->Text = dataTemp[AS_SELECT];
						tSelectOperation->ForeColor = System::Drawing::Color::Black;
					}
					if (dataTemp[AS_DEFAULT] != "") {
						tDefaultOperation->Text = dataTemp[AS_DEFAULT];
						tDefaultOperation->ForeColor = System::Drawing::Color::Black;

					}
					lOperationName->Visible = true;
					lOperationOut->Visible = true;
					tOperationOut->Visible = true;
					lSelectOperation->Visible = true;
					tSelectOperation->Visible = true;
					lDefaultOperation->Visible = true;
					tDefaultOperation->Visible = true;
					bSaveOperation->Visible = true;
					lAreaOperation->Visible = false;
					rbTrueOperation->Visible = false;
					rbFalseOperation->Visible = false;
					break;
				case 1:
				case 8:
				case 12:
					if (dataTemp[AS_OUTPUT] != "") {
						tOperationOut->Text = dataTemp[AS_OUTPUT];
						tOperationOut->ForeColor = System::Drawing::Color::Black;
					}
					if (dataTemp[AS_SELECT] != "") {
						tSelectOperation->Text = dataTemp[AS_SELECT];
						tSelectOperation->ForeColor = System::Drawing::Color::Black;
					}
					if (dataTemp[AS_AREA] != "") {
						if (dataTemp[AS_AREA] == "true") {
							rbTrueOperation->Checked = true;
						}
						else {
							rbFalseOperation->Checked = true;
						}
					}
					if (dataTemp[AS_DEFAULT] != "") {
						tDefaultOperation->Text = dataTemp[AS_DEFAULT];
						tDefaultOperation->ForeColor = System::Drawing::Color::Black;
					}
					lOperationName->Visible = true;
					lOperationOut->Visible = true;
					tOperationOut->Visible = true;
					lSelectOperation->Visible = true;
					tSelectOperation->Visible = true;
					lAreaOperation->Visible = true;
					rbTrueOperation->Visible = true;
					rbFalseOperation->Visible = true;
					lDefaultOperation->Visible = true;
					tDefaultOperation->Visible = true;
					bSaveOperation->Visible = true;
					break;
				default:
					if (dataTemp[AS_OUTPUT] != "") {
						tOperationOut->Text = dataTemp[AS_OUTPUT];
						tOperationOut->ForeColor = System::Drawing::Color::Black;
					}
					lOperationName->Visible = true;
					lOperationOut->Visible = true;
					tOperationOut->Visible = true;
					lSelectOperation->Visible = false;
					tSelectOperation->Visible = false;
					lDefaultOperation->Visible = false;
					tDefaultOperation->Visible = false;
					lAreaOperation->Visible = false;
					rbTrueOperation->Visible = false;
					rbFalseOperation->Visible = false;
					bSaveOperation->Visible = true;
					break;
				}
			}
		}
		else {
			cbOperation->Items->Clear();
			cbOperation->Items->AddRange(rasterList);
			cbOperation->Visible = true;
			lOperationName->Visible = true;
			array<String^>^ dataTemp = safe_cast<array<String^>^>(attributeList[i]);
			if (dataTemp[AS_OPERATION] != "") {
				cbOperation->SelectedIndex = rasterOperationToindex(dataTemp[AS_OPERATION]);
				switch (cbOperation->SelectedIndex)
				{
				case 0:
				case 2:
				case 3:
				case 4:
				case 6:
					if (dataTemp[AS_OUTPUT] != "") {
						tOperationOut->Text = dataTemp[AS_OUTPUT];
						tOperationOut->ForeColor = System::Drawing::Color::Black;
					}
					if (dataTemp[AS_DEFAULT] != "") {
						tDefaultOperation->Text = dataTemp[AS_DEFAULT];
						tDefaultOperation->ForeColor = System::Drawing::Color::Black;

					}
					lOperationName->Visible = true;
					lOperationOut->Visible = true;
					tOperationOut->Visible = true;
					lDefaultOperation->Visible = true;
					tDefaultOperation->Visible = true;
					bSaveOperation->Visible = true;
					lSelectOperation->Visible = false;
					tSelectOperation->Visible = false;
					lAreaOperation->Visible = false;
					rbTrueOperation->Visible = false;
					rbFalseOperation->Visible = false;
					break;
				case 1:
				case 5:
					if (dataTemp[AS_OUTPUT] != "") {
						tOperationOut->Text = dataTemp[AS_OUTPUT];
						tOperationOut->ForeColor = System::Drawing::Color::Black;
					}
					if (dataTemp[AS_SELECT] != "") {
						tSelectOperation->Text = dataTemp[AS_SELECT];
						tSelectOperation->ForeColor = System::Drawing::Color::Black;
					}
					if (dataTemp[AS_AREA] != "") {
						if (dataTemp[AS_AREA] == "true") {
							rbTrueOperation->Checked = true;
						}
						else {
							rbFalseOperation->Checked = true;
						}
					}
					if (dataTemp[AS_DEFAULT] != "") {
						tDefaultOperation->Text = dataTemp[AS_DEFAULT];
						tDefaultOperation->ForeColor = System::Drawing::Color::Black;
					}
					lOperationName->Visible = true;
					lOperationOut->Visible = true;
					tOperationOut->Visible = true;
					lSelectOperation->Visible = false;
					tSelectOperation->Visible = false;
					lDefaultOperation->Visible = true;
					tDefaultOperation->Visible = true;
					lAreaOperation->Visible = true;
					rbTrueOperation->Visible = true;
					rbFalseOperation->Visible = true;
					bSaveOperation->Visible = true;
					break;
				default:
					if (dataTemp[AS_OUTPUT] != "") {
						tOperationOut->Text = dataTemp[AS_OUTPUT];
						tOperationOut->ForeColor = System::Drawing::Color::Black;
					}
					lOperationName->Visible = true;
					lOperationOut->Visible = true;
					tOperationOut->Visible = true;
					lSelectOperation->Visible = false;
					tSelectOperation->Visible = false;
					lDefaultOperation->Visible = false;
					tDefaultOperation->Visible = false;
					lAreaOperation->Visible = false;
					rbTrueOperation->Visible = false;
					rbFalseOperation->Visible = false;
					bSaveOperation->Visible = true;
					break;
				}
			}
		}
	}
}

System::Void CellFulfill::NovoModelo::cbOperation_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	int i = attributeToindex();
	if (lvAttributesToFill->Items[i]->Text->Contains(".shp")) {
		switch (cbOperation->SelectedIndex)
		{
		case 0:
		case 5:
		case 6:
		case 7:
		case 11:
			lOperationName->Visible = true;
			lOperationOut->Visible = true;
			tOperationOut->Visible = true;
			lSelectOperation->Visible = true;
			tSelectOperation->Visible = true;
			lDefaultOperation->Visible = true;
			tDefaultOperation->Visible = true;
			lAreaOperation->Visible = false;
			rbTrueOperation->Visible = false;
			rbFalseOperation->Visible = false;
			bSaveOperation->Visible = true;
			break;
		case 1:
		case 8:
		case 12:
			lOperationName->Visible = true;
			lOperationOut->Visible = true;
			tOperationOut->Visible = true;
			lSelectOperation->Visible = true;
			tSelectOperation->Visible = true;
			lDefaultOperation->Visible = true;
			tDefaultOperation->Visible = true;
			lAreaOperation->Visible = true;
			rbTrueOperation->Visible = true;
			rbFalseOperation->Visible = true;
			bSaveOperation->Visible = true;
			break;
		default:
			lOperationName->Visible = true;
			lOperationOut->Visible = true;
			tOperationOut->Visible = true;
			lSelectOperation->Visible = false;
			tSelectOperation->Visible = false;
			lDefaultOperation->Visible = false;
			tDefaultOperation->Visible = false;
			lAreaOperation->Visible = false;
			rbTrueOperation->Visible = false;
			rbFalseOperation->Visible = false;
			bSaveOperation->Visible = true;
			break;
		}
	}
	else {
		switch (cbOperation->SelectedIndex)
		{
		case 0:
		case 2:
		case 3:
		case 4:
		case 6:
			lOperationName->Visible = true;
			lOperationOut->Visible = true;
			tOperationOut->Visible = true;
			lSelectOperation->Visible = false;
			tSelectOperation->Visible = false;
			lDefaultOperation->Visible = true;
			tDefaultOperation->Visible = true;
			lAreaOperation->Visible = false;
			rbTrueOperation->Visible = false;
			rbFalseOperation->Visible = false;
			bSaveOperation->Visible = true;
			break;
		case 1:
		case 5:
			lOperationName->Visible = true;
			lOperationOut->Visible = true;
			tOperationOut->Visible = true;
			lSelectOperation->Visible = false;
			tSelectOperation->Visible = false;
			lDefaultOperation->Visible = true;
			tDefaultOperation->Visible = true;
			lAreaOperation->Visible = true;
			rbTrueOperation->Visible = true;
			rbFalseOperation->Visible = true;
			bSaveOperation->Visible = true;
			break;
		default:
			lOperationName->Visible = true;
			lOperationOut->Visible = true;
			tOperationOut->Visible = true;
			lSelectOperation->Visible = false;
			tSelectOperation->Visible = false;
			lDefaultOperation->Visible = false;
			tDefaultOperation->Visible = false;
			lAreaOperation->Visible = false;
			rbTrueOperation->Visible = false;
			rbFalseOperation->Visible = false;
			bSaveOperation->Visible = true;
			break;
		}
	}

	CellFulfill::NovoModelo::Update();
}

System::Void CellFulfill::NovoModelo::bAddAttribute_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Open the dialog to select the shape file and return the path
	CellFulfill::OpenFileDialog^ attributesFiles = gcnew OpenFileDialog;
	attributesFiles->Title = gSAttributesTitle;
	attributesFiles->Multiselect = true;
	attributesFiles->Filter = gSAttributesFilter;
	attributesFiles->FilterIndex = 1;
	attributesFiles->ShowHelp = true;

	if (attributesFiles->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (attributesFiles->FileNames != nullptr && attributesFiles->FileNames->Length > 0) {
			Collections::ArrayList^ attributeErrorList = gcnew Collections::ArrayList();
			int lastSlash = 0;
			bool error = false;
			for (int i = 0; i < attributesFiles->FileNames->Length; i++) {
				if (attributesFiles->FileNames[i]->Contains(".shp") || attributesFiles->FileNames[i]->Contains(".tif")) {
					array<String^>^ attributeToList = { attributesFiles->FileNames[i], "", "", "", "", "" };
					attributeList->Add(attributeToList);
					lastSlash = 0;
					for (int j = 0; j < attributesFiles->FileNames[i]->Length; j++) {
						if (attributesFiles->FileNames[i][j] == '\\') {
							lastSlash = j + 1;
						}
					}
					lvAttributesToFill->Items->Add(attributesFiles->FileNames[i]->Substring(lastSlash, attributesFiles->FileNames[i]->Length - lastSlash));
				}
				else {
					error = true;
					lastSlash = 0;
					for (int j = 0; j < attributesFiles->FileNames[i]->Length; j++) {
						if (attributesFiles->FileNames[i][j] == '\\') {
							lastSlash = j + 1;
						}
					}
					attributeErrorList->Add(attributesFiles->FileNames[i]->Substring(lastSlash, attributesFiles->FileNames[i]->Length - lastSlash));
				}
			}

			if (error) {
				System::Threading::Thread::Sleep(SECOND);
				for (int i = 0; i < attributeErrorList->Count; i++) {
					MessageBox::Show(gSFileFormatError + attributeErrorList[i], gSFileFormatErrorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				System::Threading::Thread::Sleep(SECOND);
			}
		}
	}
}

System::Void CellFulfill::NovoModelo::bSaveOperation_Click(System::Object^  sender, System::EventArgs^  e)
{
	int attributeIndex = attributeToindex();
	if (cbOperation->SelectedItem != "" && tOperationOut->Text != "") {
		array<String^>^ attributeToList = safe_cast<array<String^>^>(attributeList[attributeIndex]);
		if (attributeToList[AS_ATTRIBUTE]->Contains(".shp")) {
			switch (cbOperation->SelectedIndex)
			{
			case 0:
			case 5:
			case 6:
			case 7:
			case 11:
				attributeToList[AS_OPERATION] = vectorOperationToName(cbOperation->SelectedIndex);
				attributeToList[AS_OUTPUT] = tOperationOut->Text;
				attributeToList[AS_SELECT] = tSelectOperation->Text;

				if (tDefaultOperation->Text != "null" || tDefaultOperation->Text != "") {
					attributeToList[AS_DEFAULT] = tDefaultOperation->Text;
				}
				
				attributeList[attributeIndex] = attributeToList;
				lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
				operationVisualOFF();
				break;
			case 1:
			case 8:
			case 12:
				attributeToList[AS_OPERATION] = vectorOperationToName(cbOperation->SelectedIndex);
				attributeToList[AS_OUTPUT] = tOperationOut->Text;
				attributeToList[AS_SELECT] = tSelectOperation->Text;
				
				if (tDefaultOperation->Text != "null" && tDefaultOperation->Text != "") {
					attributeToList[AS_DEFAULT] = tDefaultOperation->Text;
				}
				
				if (rbTrueOperation->Checked) {
					attributeToList[AS_AREA] = "true";
				}
				else {
					attributeToList[AS_AREA] = "false";
				}

				attributeList[attributeIndex] = attributeToList;
				lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
				operationVisualOFF();
				break;
			default:
				attributeToList[AS_OPERATION] = vectorOperationToName(cbOperation->SelectedIndex);
				attributeToList[AS_OUTPUT] = tOperationOut->Text;

				attributeList[attributeIndex] = attributeToList;
				lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
				operationVisualOFF();
				break;
			}
		}
		else {
			switch (cbOperation->SelectedIndex)
			{
			case 0:
			case 2:
			case 3:
			case 4:
			case 6:
				attributeToList[AS_OPERATION] = vectorOperationToName(cbOperation->SelectedIndex);
				attributeToList[AS_OUTPUT] = tOperationOut->Text;

				if (tDefaultOperation->Text != "null" || tDefaultOperation->Text != "") {
					attributeToList[AS_DEFAULT] = tDefaultOperation->Text;
				}

				attributeList[attributeIndex] = attributeToList;
				lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
				operationVisualOFF();
				break;
			case 1:
			case 5:
				attributeToList[AS_OPERATION] = vectorOperationToName(cbOperation->SelectedIndex);
				attributeToList[AS_OUTPUT] = tOperationOut->Text;

				if (tDefaultOperation->Text != "null" && tDefaultOperation->Text != "") {
					attributeToList[AS_DEFAULT] = tDefaultOperation->Text;
				}

				if (rbTrueOperation->Checked) {
					attributeToList[AS_AREA] = "true";
				}
				else {
					attributeToList[AS_AREA] = "false";
				}

				attributeList[attributeIndex] = attributeToList;
				lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
				operationVisualOFF();
				break;
			default:
				attributeToList[AS_OPERATION] = vectorOperationToName(cbOperation->SelectedIndex);
				attributeToList[AS_OUTPUT] = tOperationOut->Text;

				attributeList[attributeIndex] = attributeToList;
				lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
				operationVisualOFF();
				break;
			}
		}
	}
}

System::Void CellFulfill::NovoModelo::bDeleteAttribute_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (MessageBox::Show(gSDeleteAttribute + tSelectedAttribute->Text, gSDeleteAttributeTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == CellFulfill::DialogResult::Yes) {
		int i = attributeToindex();
		lvAttributesToFill->Items->RemoveAt(i);
		attributeList->RemoveAt(i);
		operationVisualOFF();
	}
}

System::Void CellFulfill::NovoModelo::bFileMaker_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool checked = true;

	if (lSelectedFolder->Text == "") {
		MessageBox::Show(gSFolder, gSFolderTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tScriptName->Text == "") {
		MessageBox::Show(gSScriptName, gSScriptNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (lLimitFileAddress->Text == "") {
		MessageBox::Show(gSLimitFileAddress, gSLimitFileAddressTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (!(lLimitFileAddress->Text->Contains(".shp") || lLimitFileAddress->Text->Contains(".tif"))) {
		MessageBox::Show(gSLimitFileAddress2, gSLimitFileAddress2Title, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tCellSpaceName->Text == "") {
		MessageBox::Show(gSCellSpaceName, gSCellSpaceNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tCellSpaceResolution->Text == "") {
		MessageBox::Show(gSCellSpaceResolution, gSCellSpaceResolutionTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	for (int i = 0; i < lvAttributesToFill->Items->Count; i++) {
		if (lvAttributesToFill->Items[i]->SubItems->Count <= 1) {
			MessageBox::Show(gSAOMissing, gSAOMissingTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
			break;
		}
	}

	if (checked) {
		bool mainFile = false;

		DateTime now = DateTime::Now;
		String^ dateTime = now.ToString("d") + " at " + now.ToString("T");

		//Creating main File
		String^ path = lSelectedFolder->Text->Replace("\\", "\\\\") + "\\" + tScriptName->Text->ToLower() + ".lua";
		path = path->Replace("\\\\", "\\");

		StreamWriter^ sw = nullptr;

		try {
			//Sometimes Widows got and error to access the file, this force to retry
			try
			{
				if (File::Exists(path))
				{
					File::Delete(path);
				}
				sw = File::CreateText(path);
			}
			catch (UnauthorizedAccessException^)
			{
				MessageBox::Show(gSUnauthorized, gSUnauthorizedTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				checked = false;
			}

			if (checked) {
				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("--          This file contains a Fill Cell Script           --");
				sw->WriteLine("--               Compatible with LuccME 3.0                 --");
				sw->WriteLine("--       Generated with Fill Cell Script Configurator       --");
				sw->WriteLine("--               " + dateTime + "                     --");
				sw->WriteLine("--------------------------------------------------------------\n");
				sw->WriteLine("local x = os.clock()"); 
				sw->WriteLine("import(\"terralib\")");
				sw->WriteLine("");
				sw->WriteLine("-- CREATING PROJECT --");
				sw->WriteLine("print(\"Creating Project\")");
				sw->WriteLine("proj = Project {");
				sw->WriteLine("\tfile = \"t3mp.tview\",");
				sw->WriteLine("\tclean = true");
				sw->WriteLine("}");
				sw->WriteLine("");
				sw->WriteLine("-- ADDING LAYERS --");
				sw->WriteLine("print(\"Adding Layers to the Project\")");
				sw->WriteLine("l1 = Layer{");
				sw->WriteLine("\tproject = proj,");
				sw->WriteLine("\tname = \"limit\",");
				sw->WriteLine("\tfile = \"" + lLimitFileAddress->Text->Replace("\\", "\\\\") + "\"");
				sw->WriteLine("}");
				sw->WriteLine("");
				sw->WriteLine("print(\"Limit added\")");
				
				for (int i = 0; i < lvAttributesToFill->Items->Count; i++) {
					array<String^>^ attributeToList = safe_cast<array<String^>^>(attributeList[i]);
					sw->WriteLine("l" + (i+2).ToString() + " = Layer{");
					sw->WriteLine("\tproject = proj,");
					sw->WriteLine("\tname = \"layer" + (i + 2).ToString() + "\",");
					sw->WriteLine("\tfile = \"" + attributeToList[AS_ATTRIBUTE]->Replace("\\", "\\\\") + "\"");
					sw->WriteLine("}");
					sw->WriteLine("print(\"Layer" + (i + 2).ToString() + " added\")");
					sw->WriteLine("");
				}
				
				sw->WriteLine("-- CREATING CELLULAR SPACE --");
				sw->WriteLine("print(\"Creating Cellular Space\")");
				sw->WriteLine("local cs = Layer{");
				sw->WriteLine("\tproject = proj,");
				
				if (lLimitFileAddress->Text->Contains(".shp")) {
					sw->WriteLine("\tsource = \"shp\",");
				}
				else {
					sw->WriteLine("\tsource = \"tif\",");
				}

				sw->WriteLine("\tname = \"cs\",");
				sw->WriteLine("\tinput = l1.name,");
				sw->WriteLine("\tresolution = " + tCellSpaceResolution->Text + ",");
				sw->WriteLine("\tfile = \"" + tCellSpaceName->Text + ".shp\",");
				sw->WriteLine("\tclean = true");
				sw->WriteLine("}");
				sw->WriteLine("");

				sw->WriteLine("-- ATTRIBUTES TO FILL --");
				for (int i = 0; i < lvAttributesToFill->Items->Count; i++) {
					array<String^>^ attributeToList = safe_cast<array<String^>^>(attributeList[i]);
					sw->WriteLine("print(\"Filling Attribute in Layer"+ (i + 2).ToString() + "\")");
					sw->WriteLine("cs:fill{");
					sw->WriteLine("\tlayer = \"layer" + (i + 2).ToString() + "\",");
					sw->WriteLine("\toperation = \""+ attributeToList[AS_OPERATION] +"\",");
					if (attributeToList[AS_OUTPUT] != "") {
						sw->WriteLine("\tattribute = \"" + attributeToList[AS_OUTPUT] + "\",");
					}
					if (attributeToList[AS_SELECT] != "") {
						sw->WriteLine("\tselect = \"" + attributeToList[AS_SELECT] + "\",");
					}
					if (attributeToList[AS_AREA] == "true") {
						sw->WriteLine("\tarea = true,");
					}
					if (attributeToList[AS_DEFAULT] != "" && attributeToList[AS_DEFAULT] != "null") {
						sw->WriteLine("\tdefault = " + lDefaultOperation->Text);
					}
					sw->WriteLine("}");
					sw->WriteLine("");
				}

				sw->WriteLine("print(string.format(\"\\nElapsed time : %.2fs\\n\", os.clock() - x))");
				sw->WriteLine("print(\"\\nEnd of Script\")");
				sw->WriteLine("");
				sw->WriteLine("-- Hold the screen --");
				sw->WriteLine("io.write(\"\\nPress enter key to exit...\")");
				sw->WriteLine("io.flush()");
				sw->WriteLine("io.read()");
				sw->WriteLine("");
				sw->WriteLine("local projFile = File(\"t3mp.tview\")");
				sw->WriteLine("if(projFile:exists()) then");
				sw->WriteLine("\tprojFile:delete()");
				sw->WriteLine("end");

				sw->Close();

				if (File::Exists(path))
				{
					mainFile = true;
				}

				if (mainFile) {
					if (lSelectedFolder->Text->Length > ROOTDIR) {
						MessageBox::Show(gSSuccess + lSelectedFolder->Text + "\\" + tScriptName->Text->ToLower() + ".lua", gSSuccessTitle,
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else {
						MessageBox::Show(gSSuccess + lSelectedFolder->Text + tScriptName->Text->ToLower() + ".lua", gSSuccessTitle,
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}

					lRunScript->Visible = true;
					bRun->Visible = true;
					runnable = true;

				}
				else {
					if (!mainFile) {
						MessageBox::Show(gSFileMissing + lSelectedFolder->Text, gSFileMissingTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
		}
		catch (Exception^) {
			if (!mainFile) {
				if (forceWriting) {
					MessageBox::Show(gSMFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					closing = true;
					this->Close();
				}
				else {
					System::Threading::Thread::Sleep(SECOND);
					if (File::Exists(path))
					{
						File::Delete(path);
					}

					forceWriting = true;
					bFileMaker_Click(sender, e);
				}
			}
		}
	}
}

System::Void CellFulfill::NovoModelo::bRun_Click(System::Object^  sender, System::EventArgs^  e)
{
	Environment::SetEnvironmentVariable("TME_PATH", "C:\\Luccme\\Terrame\\bin");
	Environment::SetEnvironmentVariable("PATH", "C:\\Luccme\\Terrame\\bin");

	String^ arguments = "";

	if (lSelectedFolder->Text[lSelectedFolder->Text->Length - 1] != '\\') {
		arguments = "\"" + lSelectedFolder->Text->Replace("\\", "\\\\") + "\\\\" + tScriptName->Text->ToLower() + ".lua\"";
	}
	else {
		arguments = "\"" + lSelectedFolder->Text->Replace("\\", "\\\\") + tScriptName->Text->ToLower() + ".lua\"";
	}

	System::Diagnostics::Process^ cmd = gcnew System::Diagnostics::Process;
	cmd->StartInfo->FileName = "C:\\LuccME\\TerraME\\bin\\TerraME.exe";
	cmd->StartInfo->Arguments = arguments;
	cmd->Start();
	cmd->WaitForExit();
	cmd->Close();

	cmd = gcnew System::Diagnostics::Process;
	arguments = "";
}

System::Void CellFulfill::NovoModelo::NovoModelo_Load(System::Object^  sender, System::EventArgs^  e)
{
	rasterList[0] = "coverage";
	rasterList[1] = "average";
	rasterList[2] = "mode";
	rasterList[3] = "maximum";
	rasterList[4] = "minimum";
	rasterList[5] = "sum";
	rasterList[6] = "stdev";

	vectorList[0] = "coverage";
	vectorList[1] = "average";
	vectorList[2] = "area";
	vectorList[3] = "distance";
	vectorList[4] = "presence";
	vectorList[5] = "mode";
	vectorList[6] = "maximum";
	vectorList[7] = "minimum";
	vectorList[8] = "sum";
	vectorList[9] = "count";
	vectorList[10] = "length";
	vectorList[11] = "stdev";
	vectorList[12] = "nearest";
	
	checkLanguage();
}
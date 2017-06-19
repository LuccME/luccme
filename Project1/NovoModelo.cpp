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

		//Menu
		arquivoToolStripMenuItem->Text = "File";
		novoToolStripMenuItem->Text = "New";
		abrirToolStripMenuItem->Text = "Open";
		sairToolStripMenuItem->Text = "Exit";
		preferênciasToolStripMenuItem->Text = "Preferences";
		idiomaToolStripMenuItem->Text = "Language";
		ajudaToolStripMenuItem->Text = "Help";
		sobreToolStripMenuItem->Text = "About";
		cellFillToolStripMenuItem->Text = "Cell Fill";
		
		//tpScript
		tpScript->Text = "Script Definition";
		lFiles->Text = "   Files";
		lDirProj->Text = "Folder to Save Scripts";
		bSelectFolder->Text = "Select";
		lScriptDefinition->Text = "   Script Definition";
		lScriptName->Text = "Script Name";

		//tpCellularSpace
		bShape->Text = "Select";
		lCellSpaceName->Text = "    Cellular Space Output Name";
		lCellSpaceResolution->Text = "Spatial Resolution";
		lM->Text = "meters";
		cbUseCS->Text = "Use existing Cellular Space";
		if (!csExist) {
			tpCellularSpace->Text = "Creating Cellular Space";
			lLimitFile->Text = "     File for Cellular Space Limit";
		}
		else {
			tpCellularSpace->Text = "Using Cellular Space";
			lLimitFile->Text = "          File with Cellular Space";
		}
		
		//tpAttributeFill
		tpAttributeFill->Text = "Data to Fill";
		bDeleteAttribute->Text = "Remove";
		lOperationName->Text = "    Select an Operation";
		lOperationOut->Text = "Output Attribute";
		lSelectOperation->Text = "Input Attribute";
		lDefaultOperation->Text = "Default Value";
		lAreaOperation->Text = "Use Area Geometry";
		lDummyOperation->Text = "Dummy Value";

		//tpMakeFiles
		tpMakeFiles->Text = "Make File";
		lFileMaker->Text = "    Make File";
		bFileMaker->Text = "Make File";
		lRunScript->Text = "    Run Script";
		bRun->Text = "Run Script";
		
		//Strings
		gSShapeTitle = "Select a Shape File";
		gSShapeFilter = "Shape File (*.shp)|*.shp";
		gSAttributes = "Attributes";
		gSFiles = "Files";
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
		gSScriptLoad = "Select the Script File";
		gSScriptLoadTitle = "Script File to Import";
		gSLuaFile = "Lua File(*.lua)|*.lua";
		gSEditing = "Editing a Script";
		gSImportError = "Incloplete file, can't import it.";
		gSImportErrorTitle = "Error - Importing Files";
		gSGeometry = "Select the data geometry representation";
		gSGeometryTitle = "Error - Select a Geometry Representation";
	}
	else {
		this->Text = "Criando um Novo Script";

		
		// Menu
		arquivoToolStripMenuItem->Text = "Arquivo";
		novoToolStripMenuItem->Text = "Novo";
		abrirToolStripMenuItem->Text = "Abrir";
		sairToolStripMenuItem->Text = "Sair";
		preferênciasToolStripMenuItem->Text = "Preferências";
		idiomaToolStripMenuItem->Text = "Idioma";
		ajudaToolStripMenuItem->Text = "Ajuda";
		sobreToolStripMenuItem->Text = "Sobre";
		cellFillToolStripMenuItem->Text = "Preenchimento";
		
		//tpScript
		tpScript->Text = "Definições do Script";
		lFiles->Text = "Arquivos";
		lDirProj->Text = "Pasta para Salvar os Scripts";
		bSelectFolder->Text = "Selecionar";
		lScriptDefinition->Text = "Definições do Script";
		lScriptName->Text = "Nome do Script";

		//tpCellularSpace

		bShape->Text = "Selecionar";
		lCellSpaceName->Text = "Nome de Saída do Espaço Celular";
		lCellSpaceResolution->Text = "Resolução Espacial";
		lM->Text = "metros";
		cbUseCS->Text = "Usar Espaço Celular existente";
		if (!csExist) {
			tpCellularSpace->Text = "Criando o Espaço Celular";
			lLimitFile->Text = "Arquivo de Limite do Espaço Celular";
		}
		else {
			tpCellularSpace->Text = "Usando o Espaço Celular";
			lLimitFile->Text = "          Arquivo do Espaço Celular";
		}

		//tpAttributeFill
		tpAttributeFill->Text = "Dados para Preenchimento";
		bDeleteAttribute->Text = "Remover";
		lOperationName->Text = "Selecione uma Operação";
		lOperationOut->Text = "Atributo de Saída";
		lSelectOperation->Text = "Atributo de Entrada";
		lDefaultOperation->Text = "Valor Default";
		lAreaOperation->Text = "Usar Geometria da Área";
		lDummyOperation->Text = "Valor Dummy";

		//tpMakeFiles
		tpMakeFiles->Text = "Gerar Arquivo";
		lFileMaker->Text = "Gerar Arquivo";
		bFileMaker->Text = "Gerar Arquivo";
		lRunScript->Text = "Rodar Script";
		bRun->Text = "Rodar Script";

		//Strigs
		gSShapeTitle = "Escolha o arquivo Shape";
		gSShapeFilter = "Arquivo Shape (*.shp)|*.shp";
		gSAttributes = "Atributos";
		gSFiles = "Arquivos";
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
		gSScriptLoad = "Selecione o Arquivo do Script";
		gSScriptLoadTitle = "Importar Arquivo de Script";
		gSLuaFile = "Arquivo Lua (*.lua)|*.lua";
		gSEditing = "Editando um Script";
		gSImportError = "Arquivo incompleto, não pode ser carregado.";
		gSImportErrorTitle = "Erro - Importando Arquivos";
		gSGeometry = "Selecione a representação geométrica do dado.";
		gSGeometryTitle = "Erro - Selecione a Representação Geométrica";
	}
}

/*
Set the Operation Visual OFF
*/
System::Void CellFulfill::NovoModelo::operationVisualOFF()
{
	cbOperation->Items->Clear();
	cbOperation->Visible = false;

	lGeometricRepresentation->Visible = false;
	gbGeometricRepresentation->Visible = false;
	
	lOperationName->Visible = false;
	lOperationOut->Visible = false;
	lDefaultOperation->Visible = false;
	lDummyOperation->Visible = false;
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

	tDummyOperation->Text = "";
	tDummyOperation->ForeColor = System::Drawing::SystemColors::ScrollBar;
	tDummyOperation->Visible = false;
	
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
Return the index for a file on AttributesToFill
*/
System::Int32 CellFulfill::NovoModelo::attributeToindex()
{
	int i = 0;
	for (i = 0; i < lvAttributesToFill->Items->Count; i++) {
		if (lvAttributesToFill->Items[i]->Selected) {
			break;
		}
	}
	
	return i;
}

/*
Return the Operation name based on the index for Polygon Vector
*/
System::String^ CellFulfill::NovoModelo::polygonOperationToName(int operation)
{
	if (operation == P_COVERAGE) {
		return "coverage";
	}
	else if (operation == P_AVERAGE) {
		return "average";
	}
	else if (operation == P_AREA) {
		return "area";
	}
	else if (operation == P_DISTANCE) {
		return "distance";
	}
	else if (operation == P_PRESENCE) {
		return "presence";
	}
	else if (operation == P_MODE) {
		return "mode";
	}
	else if (operation == P_MAXIMUM) {
		return "maximum";
	}
	else if (operation == P_MINIMUM) {
		return "minimum";
	}
	else if (operation == P_SUM) {
		return "sum";
	}
	else if (operation == P_COUNT) {
		return "count";
	}
	else if (operation == P_STDEV) {
		return "stdev";
	}

	return "";
}

/*
Return the Operation name based on the index for Non Polygon Vector
*/
System::String^ CellFulfill::NovoModelo::nonPolygonOperationToName(int operation)
{
	if (operation == NP_AVERAGE) {
		return "average";
	}
	else if (operation == NP_DISTANCE) {
		return "distance";
	}
	else if (operation == NP_PRESENCE) {
		return "presence";
	}
	else if (operation == NP_MODE) {
		return "mode";
	}
	else if (operation == NP_MAXIMUM) {
		return "maximum";
	}
	else if (operation == NP_MINIMUM) {
		return "minimum";
	}
	else if (operation == NP_SUM) {
		return "sum";
	}
	else if (operation == NP_COUNT) {
		return "count";
	}
	else if (operation == NP_STDEV) {
		return "stdev";
	}

	return "";
}

/*
Return the Operation name based on the index for Raster
*/
System::String^ CellFulfill::NovoModelo::rasterOperationToName(int operation)
{
	if (operation == COVERAGE) {
		return "coverage";
	}
	else if (operation == AVERAGE) {
		return "average";
	}
	else if (operation == MODE) {
		return "mode";
	}
	else if (operation == MAXIMUM) {
		return "maximum";
	}
	else if (operation == MINIMUM) {
		return "minimum";
	}
	else if (operation == SUM) {
		return "sum";
	}
	else if (operation == STDEV) {
		return "stdev";
	}

	return "";
}

/*
Return the index for a Polygon Vector Operation 
*/
System::Int32 CellFulfill::NovoModelo::polygonOperationToindex(String^ operation)
{
	if (operation->Equals("coverage")) {
		return P_COVERAGE;
	} 
	else if (operation->Equals("average")) {
		return P_AVERAGE;
	}
	else if (operation->Equals("area")) {
		return P_AREA;
	}
	else if (operation->Equals("distance")) {
		return P_DISTANCE;
	}
	else if (operation->Equals("presence")) {
		return P_PRESENCE;
	}
	else if (operation->Equals("mode")) {
		return P_MODE;
	}
	else if (operation->Equals("maximum")) {
		return P_MAXIMUM;
	}
	else if (operation->Equals("minimum")) {
		return P_MINIMUM;
	}
	else if (operation->Equals("sum")) {
		return P_SUM;
	}
	else if (operation->Equals("count")) {
		return P_COUNT;
	}
	else if (operation->Equals("stdev")) {
		return P_STDEV;
	}

	return -1;
}

/*
Return the index for a Non Polygon Vector Operation
*/
System::Int32 CellFulfill::NovoModelo::nonPolygonOperationToindex(String^ operation)
{
	if (operation->Equals("average")) {
		return NP_AVERAGE;
	}
	else if (operation->Equals("distance")) {
		return NP_DISTANCE;
	}
	else if (operation->Equals("presence")) {
		return NP_PRESENCE;
	}
	else if (operation->Equals("mode")) {
		return NP_MODE;
	}
	else if (operation->Equals("maximum")) {
		return NP_MAXIMUM;
	}
	else if (operation->Equals("minimum")) {
		return NP_MINIMUM;
	}
	else if (operation->Equals("sum")) {
		return NP_SUM;
	}
	else if (operation->Equals("count")) {
		return NP_COUNT;
	}
	else if (operation->Equals("stdev")) {
		return NP_STDEV;
	}

	return -1;
}

/*
Return the index for a Raster Operation
*/
System::Int32 CellFulfill::NovoModelo::rasterOperationToindex(String^ operation)
{
	if (operation->Equals("coverage")) {
		return COVERAGE;
	}
	else if (operation->Equals("average")) {
		return AVERAGE;
	}
	else if (operation->Equals("mode")) {
		return MODE;
	}
	else if (operation->Equals("maximum")) {
		return MAXIMUM;
	}
	else if (operation->Equals("minimum")) {
		return MINIMUM;
	}
	else if (operation->Equals("sum")) {
		return SUM;
	}
	else if (operation->Equals("stdev")) {
		return STDEV;
	}

	return -1;
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
		Help::ShowHelp(this, "fillcellhelp.chm");
	}
	else {
		Help::ShowHelp(this, "fillcellajuda.chm");
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
			lvAttributesToFill->Columns->Add(gSFiles, lvAttributesToFill->Width - 50, HorizontalAlignment::Left);
			lvAttributesToFill->Columns->Add("Status", 47, HorizontalAlignment::Center);
		}
	}

	if (tabControl1->SelectedIndex == RUNSCRIPT) {
		if (!runnable) {
			lRunScript->Visible = false;
			bRun->Visible = false;
		}
		else {
			lRunScript->Visible = true;
			bRun->Visible = true;
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
					array<String^>^ attributeToList = { filePaths[i], "", "", "", "", "", "", "" };
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
		
		//Vector
		if (lvAttributesToFill->Items[i]->Text->Contains(".shp")) {
			lOperationName->Location = System::Drawing::Point(388, 105);
			cbOperation->Location = System::Drawing::Point(362, 131);
			lOperationOut->Location = System::Drawing::Point(328, 176);
			tOperationOut->Location = System::Drawing::Point(482, 178);
			lSelectOperation->Location = System::Drawing::Point(309, 213);
			tSelectOperation->Location = System::Drawing::Point(482, 215);
			lAreaOperation->Location = System::Drawing::Point(320, 251);
			rbTrueOperation->Location = System::Drawing::Point(534, 253);
			rbFalseOperation->Location = System::Drawing::Point(583, 253);

			cbOperation->Items->Clear();

			rbLine->Checked = false;
			rbDot->Checked = false;
			rbPolygon->Checked = false;
		
			lGeometricRepresentation->Visible = true;
			gbGeometricRepresentation->Visible = true;
			lOperationName->Visible = true;
			cbOperation->Visible = true;
			bSaveOperation->Visible = true;

			array<String^>^ dataTemp = safe_cast<array<String^>^>(attributeList[i]);

			if (dataTemp[AS_SHPTYPE] != "" && dataTemp[AS_SHPTYPE]->Equals("polygon")) {
				rbPolygon->Checked = true;
			} else if (dataTemp[AS_SHPTYPE] != "" && dataTemp[AS_SHPTYPE]->Equals("line")) {
				rbLine->Checked = true;
			} else if (dataTemp[AS_SHPTYPE] != "" && dataTemp[AS_SHPTYPE]->Equals("dot")) {
				rbDot->Checked = true;
			}
			
			if (dataTemp[AS_OPERATION] != "") {
				//Polygon
				if (rbPolygon->Checked) {
					cbOperation->Items->Clear();
					cbOperation->Items->AddRange(polygonList);
					cbOperation->SelectedIndex = polygonOperationToindex(dataTemp[AS_OPERATION]);

					switch (cbOperation->SelectedIndex)
					{
					case P_COVERAGE:
					case P_MODE:
					case P_MAXIMUM:
					case P_MINIMUM:
					case P_STDEV:
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
						lDefaultOperation->Visible = false;
						tDefaultOperation->Visible = false;
						lDummyOperation->Visible = false;
						tDummyOperation->Visible = false;
						bSaveOperation->Visible = true;
						lAreaOperation->Visible = false;
						rbTrueOperation->Visible = false;
						rbFalseOperation->Visible = false;
						break;
					case P_AVERAGE:
					case P_SUM:
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

						if (rbPolygon->Checked) {
							lAreaOperation->Visible = true;
							rbTrueOperation->Visible = true;
							rbFalseOperation->Visible = true;
						}

						lDefaultOperation->Visible = false;
						tDefaultOperation->Visible = false;
						lDummyOperation->Visible = false;
						tDummyOperation->Visible = false;
						bSaveOperation->Visible = true;
						break;
					case P_AREA:
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
						lSelectOperation->Visible = false;
						tSelectOperation->Visible = false;
						lDefaultOperation->Visible = true;
						tDefaultOperation->Visible = true;
						lDummyOperation->Visible = false;
						tDummyOperation->Visible = false;
						lAreaOperation->Visible = false;
						rbTrueOperation->Visible = false;
						rbFalseOperation->Visible = false;
						bSaveOperation->Visible = true;
						break;
					case P_DISTANCE:
					case P_PRESENCE:
					case P_COUNT:
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
						lDummyOperation->Visible = false;
						tDummyOperation->Visible = false;
						lAreaOperation->Visible = false;
						rbTrueOperation->Visible = false;
						rbFalseOperation->Visible = false;
						bSaveOperation->Visible = true;
						break;
					}
				}
				//Non Polygon
				else {
					cbOperation->Items->Clear();
					cbOperation->Items->AddRange(nonPolygonList);
					cbOperation->SelectedIndex = nonPolygonOperationToindex(dataTemp[AS_OPERATION]);

					switch (cbOperation->SelectedIndex)
					{
					case NP_MODE:
					case NP_MAXIMUM:
					case NP_MINIMUM:
					case NP_STDEV:
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
						lDummyOperation->Visible = false;
						tDummyOperation->Visible = false;
						bSaveOperation->Visible = true;
						lAreaOperation->Visible = false;
						rbTrueOperation->Visible = false;
						rbFalseOperation->Visible = false;
						break;
					case NP_AVERAGE:
					case NP_SUM:
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

						if (rbPolygon->Checked) {
							lAreaOperation->Visible = true;
							rbTrueOperation->Visible = true;
							rbFalseOperation->Visible = true;
						}

						lDefaultOperation->Visible = true;
						tDefaultOperation->Visible = true;
						lDummyOperation->Visible = false;
						tDummyOperation->Visible = false;
						bSaveOperation->Visible = true;
						break;
					case NP_DISTANCE:
					case NP_PRESENCE:
					case NP_COUNT:
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
						lDummyOperation->Visible = false;
						tDummyOperation->Visible = false;
						lAreaOperation->Visible = false;
						rbTrueOperation->Visible = false;
						rbFalseOperation->Visible = false;
						bSaveOperation->Visible = true;
						break;
					}
				}
				

				
			}
		}
		//Raster
		else {
			int yDelta = 10;
			lOperationName->Location = System::Drawing::Point(388, 95 - yDelta);
			cbOperation->Location = System::Drawing::Point(362, 121 - yDelta);
			lOperationOut->Location = System::Drawing::Point(328, 176 - yDelta);
			tOperationOut->Location = System::Drawing::Point(482, 178 - yDelta);
			lDefaultOperation->Location = System::Drawing::Point(360, 213 - yDelta);
			tDefaultOperation->Location = System::Drawing::Point(482, 215 - yDelta);
			lDummyOperation->Location = System::Drawing::Point(360, 249 - yDelta);
			tDummyOperation->Location = System::Drawing::Point(483, 251 - yDelta);
			lAreaOperation->Location = System::Drawing::Point(320, 300 - yDelta);
			rbTrueOperation->Location = System::Drawing::Point(534, 303 - yDelta);
			rbFalseOperation->Location = System::Drawing::Point(583, 303 - yDelta);

			cbOperation->Items->Clear();
			cbOperation->Items->AddRange(rasterList);

			lGeometricRepresentation->Visible = false;
			gbGeometricRepresentation->Visible = false;
			cbOperation->Visible = true;
			lOperationName->Visible = true;
			
			array<String^>^ dataTemp = safe_cast<array<String^>^>(attributeList[i]);
			
			if (dataTemp[AS_OPERATION] != "") {
				cbOperation->SelectedIndex = rasterOperationToindex(dataTemp[AS_OPERATION]);
				switch (cbOperation->SelectedIndex)
				{
				case COVERAGE:
				case MODE:
				case MAXIMUM:
				case MINIMUM:
				case STDEV:
					if (dataTemp[AS_OUTPUT] != "") {
						tOperationOut->Text = dataTemp[AS_OUTPUT];
						tOperationOut->ForeColor = System::Drawing::Color::Black;
					}
					
					if (dataTemp[AS_DEFAULT] != "") {
						tDefaultOperation->Text = dataTemp[AS_DEFAULT];
						tDefaultOperation->ForeColor = System::Drawing::Color::Black;

					}
					
					if (dataTemp[AS_DUMMY] != "") {
						tDefaultOperation->Text = dataTemp[AS_DUMMY];
						tDefaultOperation->ForeColor = System::Drawing::Color::Black;

					}
					
					lOperationName->Visible = true;
					lOperationOut->Visible = true;
					tOperationOut->Visible = true;
					lDefaultOperation->Visible = true;
					tDefaultOperation->Visible = true;
					lDummyOperation->Visible = true;
					tDummyOperation->Visible = true;
					bSaveOperation->Visible = true;
					lSelectOperation->Visible = false;
					tSelectOperation->Visible = false;
					lAreaOperation->Visible = false;
					rbTrueOperation->Visible = false;
					rbFalseOperation->Visible = false;
					break;
				case AVERAGE:
				case SUM:
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
					
					if (dataTemp[AS_DUMMY] != "") {
						tDefaultOperation->Text = dataTemp[AS_DUMMY];
						tDefaultOperation->ForeColor = System::Drawing::Color::Black;

					}
					lOperationName->Visible = true;
					lOperationOut->Visible = true;
					tOperationOut->Visible = true;
					lSelectOperation->Visible = false;
					tSelectOperation->Visible = false;
					lDefaultOperation->Visible = true;
					tDefaultOperation->Visible = true;
					lDummyOperation->Visible = true;
					tDummyOperation->Visible = true;
					lAreaOperation->Visible = false;
					rbTrueOperation->Visible = false;
					rbFalseOperation->Visible = false;
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
					lDummyOperation->Visible = false;
					tDummyOperation->Visible = false;
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
	//Vector
	if (lvAttributesToFill->Items[i]->Text->Contains(".shp")) {
		//Polygon
		if (rbPolygon->Checked) {
			switch (cbOperation->SelectedIndex)
			{
			case P_COVERAGE:
			case P_MODE:
			case P_MAXIMUM:
			case P_MINIMUM:
			case P_STDEV:
				lOperationName->Visible = true;
				lOperationOut->Visible = true;
				tOperationOut->Visible = true;
				lSelectOperation->Visible = true;
				tSelectOperation->Visible = true;
				lDefaultOperation->Visible = true;
				tDefaultOperation->Visible = true;
				lDummyOperation->Visible = false;
				tDummyOperation->Visible = false;
				lAreaOperation->Visible = false;
				rbTrueOperation->Visible = false;
				rbFalseOperation->Visible = false;
				bSaveOperation->Visible = true;
				break;
			case P_AVERAGE:
			case P_SUM:
				lOperationName->Visible = true;
				lOperationOut->Visible = true;
				tOperationOut->Visible = true;
				lSelectOperation->Visible = true;
				tSelectOperation->Visible = true;
				lDefaultOperation->Visible = false;
				tDefaultOperation->Visible = false;
				lDummyOperation->Visible = false;
				tDummyOperation->Visible = false;
				if (rbPolygon->Checked) {
					lAreaOperation->Visible = true;
					rbTrueOperation->Visible = true;
					rbFalseOperation->Visible = true;
				}
				bSaveOperation->Visible = true;
				break;
			case P_AREA:
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
			case P_DISTANCE:
			case P_PRESENCE:
			case P_COUNT:
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
		//Non Polygon
		else {
			switch (cbOperation->SelectedIndex)
			{
			case NP_MODE:
			case NP_MAXIMUM:
			case NP_MINIMUM:
			case NP_STDEV:
				lOperationName->Visible = true;
				lOperationOut->Visible = true;
				tOperationOut->Visible = true;
				lSelectOperation->Visible = true;
				tSelectOperation->Visible = true;
				lDefaultOperation->Visible = true;
				tDefaultOperation->Visible = true;
				lDummyOperation->Visible = false;
				tDummyOperation->Visible = false;
				lAreaOperation->Visible = false;
				rbTrueOperation->Visible = false;
				rbFalseOperation->Visible = false;
				bSaveOperation->Visible = true;
				break;
			case NP_AVERAGE:
			case NP_SUM:
				lOperationName->Visible = true;
				lOperationOut->Visible = true;
				tOperationOut->Visible = true;
				lSelectOperation->Visible = true;
				tSelectOperation->Visible = true;
				lDefaultOperation->Visible = true;
				tDefaultOperation->Visible = true;
				lDummyOperation->Visible = false;
				tDummyOperation->Visible = false;
				if (rbPolygon->Checked) {
					lAreaOperation->Visible = true;
					rbTrueOperation->Visible = true;
					rbFalseOperation->Visible = true;
				}
				bSaveOperation->Visible = true;
				break;
			case NP_DISTANCE:
			case NP_PRESENCE:
			case NP_COUNT:
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
	}
	//Raster
	else {
		switch (cbOperation->SelectedIndex)
		{
		case COVERAGE:
		case MODE:
		case MAXIMUM:
		case MINIMUM:
		case STDEV:
			lOperationName->Visible = true;
			lOperationOut->Visible = true;
			tOperationOut->Visible = true;
			lSelectOperation->Visible = false;
			tSelectOperation->Visible = false;
			lDefaultOperation->Visible = true;
			tDefaultOperation->Visible = true;
			lDummyOperation->Visible = true;
			tDummyOperation->Visible = true;
			lAreaOperation->Visible = false;
			rbTrueOperation->Visible = false;
			rbFalseOperation->Visible = false;
			bSaveOperation->Visible = true;
			break;
		case AVERAGE:
		case SUM:
			lOperationName->Visible = true;
			lOperationOut->Visible = true;
			tOperationOut->Visible = true;
			lSelectOperation->Visible = false;
			tSelectOperation->Visible = false;
			lDefaultOperation->Visible = true;
			tDefaultOperation->Visible = true;
			lDummyOperation->Visible = true;
			tDummyOperation->Visible = true;
			lAreaOperation->Visible = false;
			rbTrueOperation->Visible = false;
			rbFalseOperation->Visible = false;
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
			lDummyOperation->Visible = false;
			tDummyOperation->Visible = false;
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
					array<String^>^ attributeToList = { attributesFiles->FileNames[i], "", "", "", "", "", "", "" };
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
	bool check = true;
	
	if (tSelectedAttribute->Text->Contains(".shp")) {
		if ((!rbLine->Checked) && (!rbDot->Checked) && (!rbPolygon->Checked)) {
			MessageBox::Show(gSGeometry, gSGeometryTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = false;
		}
	}
	
	int attributeIndex = attributeToindex();

	if (cbOperation->SelectedItem != "" && tOperationOut->Text != "" && check) {
		array<String^>^ attributeToList = safe_cast<array<String^>^>(attributeList[attributeIndex]);
		
		//Polygon Vector
		if (attributeToList[AS_ATTRIBUTE]->Contains(".shp")) {
			if (rbPolygon->Checked) {
				switch (cbOperation->SelectedIndex)
				{
				case P_COVERAGE:
				case P_MODE:
				case P_MAXIMUM:
				case P_MINIMUM:
				case P_STDEV:
					attributeToList[AS_OPERATION] = polygonOperationToName(cbOperation->SelectedIndex);
					attributeToList[AS_OUTPUT] = tOperationOut->Text;
					attributeToList[AS_SELECT] = tSelectOperation->Text;

					if (tDefaultOperation->Text != "null" || tDefaultOperation->Text != "") {
						attributeToList[AS_DEFAULT] = tDefaultOperation->Text;
					}

					if (rbPolygon->Checked) {
						attributeToList[AS_SHPTYPE] = "polygon";
					}
					else if (rbLine->Checked) {
						attributeToList[AS_SHPTYPE] = "line";
					}
					else if (rbDot->Checked) {
						attributeToList[AS_SHPTYPE] = "dot";
					}

					attributeList[attributeIndex] = attributeToList;
					lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
					operationVisualOFF();
					break;
				case P_AVERAGE:
				case P_SUM:
					attributeToList[AS_OPERATION] = polygonOperationToName(cbOperation->SelectedIndex);
					attributeToList[AS_OUTPUT] = tOperationOut->Text;
					attributeToList[AS_SELECT] = tSelectOperation->Text;
					attributeToList[AS_DEFAULT] = tDefaultOperation->Text;


					if (rbTrueOperation->Checked) {
						attributeToList[AS_AREA] = "true";
					}
					else {
						attributeToList[AS_AREA] = "false";
					}

					if (rbPolygon->Checked) {
						attributeToList[AS_SHPTYPE] = "polygon";
					}
					else if (rbLine->Checked) {
						attributeToList[AS_SHPTYPE] = "line";
					}
					else if (rbDot->Checked) {
						attributeToList[AS_SHPTYPE] = "dot";
					}

					attributeList[attributeIndex] = attributeToList;
					lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
					operationVisualOFF();
					break;
				case P_AREA:
					attributeToList[AS_OPERATION] = polygonOperationToName(cbOperation->SelectedIndex);
					attributeToList[AS_OUTPUT] = tOperationOut->Text;
					attributeToList[AS_DEFAULT] = tDefaultOperation->Text;

					if (rbPolygon->Checked) {
						attributeToList[AS_SHPTYPE] = "polygon";
					}
					else if (rbLine->Checked) {
						attributeToList[AS_SHPTYPE] = "line";
					}
					else if (rbDot->Checked) {
						attributeToList[AS_SHPTYPE] = "dot";
					}

					attributeList[attributeIndex] = attributeToList;
					lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
					operationVisualOFF();
					break;
				case P_DISTANCE:
				case P_PRESENCE:
				case P_COUNT:
				default:
					attributeToList[AS_OPERATION] = polygonOperationToName(cbOperation->SelectedIndex);
					attributeToList[AS_OUTPUT] = tOperationOut->Text;

					if (rbPolygon->Checked) {
						attributeToList[AS_SHPTYPE] = "polygon";
					}
					else if (rbLine->Checked) {
						attributeToList[AS_SHPTYPE] = "line";
					}
					else if (rbDot->Checked) {
						attributeToList[AS_SHPTYPE] = "dot";
					}

					attributeList[attributeIndex] = attributeToList;
					lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
					operationVisualOFF();
					break;
				}
			}
			//Non Polygon Vector
			else {
				switch (cbOperation->SelectedIndex)
				{
				case NP_MODE:
				case NP_MAXIMUM:
				case NP_MINIMUM:
				case NP_STDEV:
					attributeToList[AS_OPERATION] = nonPolygonOperationToName(cbOperation->SelectedIndex);
					attributeToList[AS_OUTPUT] = tOperationOut->Text;
					attributeToList[AS_SELECT] = tSelectOperation->Text;
					attributeToList[AS_DEFAULT] = tDefaultOperation->Text;

					if (rbPolygon->Checked) {
						attributeToList[AS_SHPTYPE] = "polygon";
					}
					else if (rbLine->Checked) {
						attributeToList[AS_SHPTYPE] = "line";
					}
					else if (rbDot->Checked) {
						attributeToList[AS_SHPTYPE] = "dot";
					}

					attributeList[attributeIndex] = attributeToList;
					lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
					operationVisualOFF();
					break;
				case NP_AVERAGE:
				case NP_SUM:
					attributeToList[AS_OPERATION] = nonPolygonOperationToName(cbOperation->SelectedIndex);
					attributeToList[AS_OUTPUT] = tOperationOut->Text;
					attributeToList[AS_SELECT] = tSelectOperation->Text;
					attributeToList[AS_DEFAULT] = tDefaultOperation->Text;
					
					if (rbTrueOperation->Checked) {
						attributeToList[AS_AREA] = "true";
					}
					else {
						attributeToList[AS_AREA] = "false";
					}

					if (rbPolygon->Checked) {
						attributeToList[AS_SHPTYPE] = "polygon";
					}
					else if (rbLine->Checked) {
						attributeToList[AS_SHPTYPE] = "line";
					}
					else if (rbDot->Checked) {
						attributeToList[AS_SHPTYPE] = "dot";
					}

					attributeList[attributeIndex] = attributeToList;
					lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
					operationVisualOFF();
					break;
				case NP_DISTANCE:
				case NP_PRESENCE:
				case NP_COUNT:
				default:
					attributeToList[AS_OPERATION] = nonPolygonOperationToName(cbOperation->SelectedIndex);
					attributeToList[AS_OUTPUT] = tOperationOut->Text;

					if (rbPolygon->Checked) {
						attributeToList[AS_SHPTYPE] = "polygon";
					}
					else if (rbLine->Checked) {
						attributeToList[AS_SHPTYPE] = "line";
					}
					else if (rbDot->Checked) {
						attributeToList[AS_SHPTYPE] = "dot";
					}

					attributeList[attributeIndex] = attributeToList;
					lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
					operationVisualOFF();
					break;
				}
			}
		}
		//Raster
		else {
			switch (cbOperation->SelectedIndex)
			{
			case COVERAGE:
			case MODE:
			case MAXIMUM:
			case MINIMUM:
			case STDEV:
				attributeToList[AS_OPERATION] = rasterOperationToName(cbOperation->SelectedIndex);
				attributeToList[AS_OUTPUT] = tOperationOut->Text;
				attributeToList[AS_DEFAULT] = tDefaultOperation->Text;

				if (tDummyOperation->Text != "null" && tDummyOperation->Text != "") {
					attributeToList[AS_DUMMY] = tDummyOperation->Text;
				}

				attributeList[attributeIndex] = attributeToList;
				lvAttributesToFill->Items[attributeIndex]->SubItems->Add("OK");
				operationVisualOFF();
				break;
			case AVERAGE:
			case SUM:
				attributeToList[AS_OPERATION] = rasterOperationToName(cbOperation->SelectedIndex);
				attributeToList[AS_OUTPUT] = tOperationOut->Text;
				attributeToList[AS_DEFAULT] = tDefaultOperation->Text;
				
				if (tDummyOperation->Text != "null" && tDummyOperation->Text != "") {
					attributeToList[AS_DUMMY] = tDummyOperation->Text;
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
				attributeToList[AS_OPERATION] = rasterOperationToName(cbOperation->SelectedIndex);
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

	else if (tCellSpaceName->Text == "" && !cbUseCS->Checked) {
		MessageBox::Show(gSCellSpaceName, gSCellSpaceNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tCellSpaceResolution->Text == "" && !cbUseCS->Checked) {
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
				sw->WriteLine("--               Compatible with LuccME 3.1                 --");
				sw->WriteLine("--       Generated with Fill Cell Script Configurator       --");
				sw->WriteLine("--               " + dateTime + "                     --");
				sw->WriteLine("--------------------------------------------------------------\n");
				sw->WriteLine("local x = os.clock()"); 
				sw->WriteLine("import(\"terralib\")");
				sw->WriteLine("");
				sw->WriteLine("local projFile = File(\"t3mp.tview\")");
				sw->WriteLine("if(projFile:exists()) then");
				sw->WriteLine("\tprojFile:delete()");
				sw->WriteLine("end");
				sw->WriteLine("");
				sw->WriteLine("-- CREATING PROJECT --");
				sw->WriteLine("print(\"-- Creating Project --\\n\")");
				sw->WriteLine("");
				sw->WriteLine("proj = Project {");
				sw->WriteLine("\tfile = \"t3mp.tview\",");
				sw->WriteLine("\tclean = true");
				sw->WriteLine("}");
				sw->WriteLine("");
				sw->WriteLine("-- ADDING LAYERS --");
				sw->WriteLine("print(\"-- Adding Layers to the Project --\")");
				sw->WriteLine("");
				sw->WriteLine("l1 = Layer{");
				sw->WriteLine("\tproject = proj,");
				sw->WriteLine("\tname = \"limit\",");
				sw->WriteLine("\tfile = \"" + lLimitFileAddress->Text->Replace("\\", "\\\\") + "\"");
				sw->WriteLine("}");

				int lastSlash = 0;
				for (int i = 0; i < lLimitFileAddress->Text->Length; i++) {
					if (lLimitFileAddress->Text[i] == '\\') {
						lastSlash = i + 1;
					}
				}

				if (!cbUseCS->Checked) {
					sw->WriteLine("print(\"Added Limit: " + lLimitFileAddress->Text->Substring(lastSlash, lLimitFileAddress->Text->Length - lastSlash) + "\")");
					sw->WriteLine("");
				}
				else {
					sw->WriteLine("print(\"Added Cellular Spaced: " + lLimitFileAddress->Text->Substring(lastSlash, lLimitFileAddress->Text->Length - lastSlash) + "\")");
					sw->WriteLine("");
				}
				
				for (int i = 0; i < lvAttributesToFill->Items->Count; i++) {
					array<String^>^ attributeToList = safe_cast<array<String^>^>(attributeList[i]);
					
					sw->WriteLine("l" + (i+2).ToString() + " = Layer{");
					sw->WriteLine("\tproject = proj,");
					sw->WriteLine("\tname = \"layer" + (i + 2).ToString() + "\",");
					sw->WriteLine("\tfile = \"" + attributeToList[AS_ATTRIBUTE]->Replace("\\", "\\\\") + "\"");
					
					sw->WriteLine("}");

					lastSlash = 0;
					for (int i = 0; i < attributeToList[AS_ATTRIBUTE]->Length; i++) {
						if (attributeToList[AS_ATTRIBUTE][i] == '\\') {
							lastSlash = i + 1;
						}
					}

					sw->WriteLine("print(\"Added Layer" + (i + 2).ToString() + ": " + attributeToList[AS_ATTRIBUTE]->Substring(lastSlash, attributeToList[AS_ATTRIBUTE]->Length - lastSlash) + "\")");
					sw->WriteLine("");
				}

				sw->WriteLine("-- Checking EPSGs --");
				sw->WriteLine("print(\"\\n-- Checking EPSGs--\")");
				
				lastSlash = 0;
				for (int i = 0; i <lLimitFileAddress->Text->Length; i++) {
					if (lLimitFileAddress->Text[i] == '\\') {
						lastSlash = i + 1;
					}
				}

				String^ attributesName = "\"" + lLimitFileAddress->Text->Substring(lastSlash, lLimitFileAddress->Text->Length - lastSlash) + "\", "; 
				String^ attributesEPSG = "l1.epsg, ";
				
				for (int i = 0; i < lvAttributesToFill->Items->Count; i++) {
					array<String^>^ attributeToList = safe_cast<array<String^>^>(attributeList[i]);
					
					attributesEPSG += "l" + (i + 2) + ".epsg";
					attributesName += "\"" + lvAttributesToFill->Items[i]->Text + "\"";
					

					if ((i + 1) < lvAttributesToFill->Items->Count) {
						attributesName += ", ";
						attributesEPSG += ", ";
					}
				}

				sw->WriteLine("local epsgVector = {" + attributesEPSG + "}");
				sw->WriteLine("local fileVector = {" + attributesName + "}");
				sw->WriteLine("local checkEPSG = true");
				sw->WriteLine("");
				sw->WriteLine("for i = 1, #epsgVector, 1 do");
				sw->WriteLine("\tif (epsgVector[i] ~= l1.epsg) then");
				sw->WriteLine("\t\tprint(\"Error: EPSG does not math - limit : \"..l1.epsg..\" \"..fileVector[i]..\" : \"..epsgVector[i])");
				sw->WriteLine("\t\tcheckEPSG = false");
				sw->WriteLine("\tend");
				sw->WriteLine("");
				sw->WriteLine("\tif checkEPSG then print(\"EPSG - limit : \"..l1.epsg..\"\\t\"..fileVector[i]..\": \"..epsgVector[i]) end");
				sw->WriteLine("end");
				sw->WriteLine("");
				sw->WriteLine("if not checkEPSG then os.exit() end");
				sw->WriteLine("");
				
				if (!cbUseCS->Checked) {
					sw->WriteLine("-- CREATING CELLULAR SPACE --");
					sw->WriteLine("print(\"\\n-- Creating Cellular Space --\\n\")");
					sw->WriteLine("");
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
				}
				else {
					sw->WriteLine("-- OPENING CELLULAR SPACE --");
					sw->WriteLine("print(\"\\n-- Openning Cellular Space -- \\n\")");
					sw->WriteLine("local cs = Layer{");
					sw->WriteLine("\tproject = proj,");
					sw->WriteLine("\tname = l1.name,");
					sw->WriteLine("}");
					sw->WriteLine("");
				}

				sw->WriteLine("-- FILLING CELLULAR SPACE --");
				for (int i = 0; i < lvAttributesToFill->Items->Count; i++) {
					array<String^>^ attributeToList = safe_cast<array<String^>^>(attributeList[i]);
					
					lastSlash = 0;
					for (int i = 0; i < attributeToList[AS_ATTRIBUTE]->Length; i++) {
						if (attributeToList[AS_ATTRIBUTE][i] == '\\') {
							lastSlash = i + 1;
						}
					}

					sw->WriteLine("print(\"Filling " + attributeToList[AS_ATTRIBUTE]->Substring(lastSlash, attributeToList[AS_ATTRIBUTE]->Length - lastSlash) + " into Cellular Space using " + attributeToList[AS_OPERATION] + " operation\")");
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
					
					if (attributeToList[AS_DEFAULT] != "" && attributeToList[AS_DEFAULT] != "null" && attributeToList[AS_DEFAULT] != "nill") {
						sw->WriteLine("\tmissing = " + attributeToList[AS_DEFAULT] + ",");
					}

					if (attributeToList[AS_DUMMY] != "" && attributeToList[AS_DUMMY] != "null" && attributeToList[AS_DUMMY] != "nill") {
						sw->WriteLine("\tdummy = " + attributeToList[AS_DUMMY] + ",");
					}

					if (attributeToList[AS_SHPTYPE] != "") {
						sw->WriteLine("\tdataType = \"" + attributeToList[AS_SHPTYPE] + "\"");
					}

					sw->WriteLine("}\n");
				}

				sw->WriteLine("projFile = File(\"t3mp.tview\")");
				sw->WriteLine("if(projFile:exists()) then");
				sw->WriteLine("\tprojFile:delete()");
				sw->WriteLine("end");
				sw->WriteLine("print(string.format(\"\\nElapsed time : %.2fs\\n\", os.clock() - x))");
				sw->WriteLine("print(\"\\nEnd of Script\")");
				sw->WriteLine("");

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
#ifdef LUCCME
	Environment::SetEnvironmentVariable("TME_PATH", "C:\\Luccme\\Terrame\\bin");
	Environment::SetEnvironmentVariable("PATH", "C:\\Luccme\\Terrame\\bin");
#endif 
#ifndef LUCCME
	Environment::SetEnvironmentVariable("TME_PATH", "C:\\FillCell\\Terrame\\bin");
	Environment::SetEnvironmentVariable("PATH", "C:\\FillCell\\Terrame\\bin");
#endif 

	String^ arguments = "";

	if (lSelectedFolder->Text[lSelectedFolder->Text->Length - 1] != '\\') {
		arguments = "\"" + lSelectedFolder->Text->Replace("\\", "\\\\") + "\\\\" + tScriptName->Text->ToLower() + ".lua\"";
	}
	else {
		arguments = "\"" + lSelectedFolder->Text->Replace("\\", "\\\\") + tScriptName->Text->ToLower() + ".lua\"";
	}

	System::Diagnostics::Process^ cmd = gcnew System::Diagnostics::Process;

#ifdef LUCCME
	cmd->StartInfo->FileName = "C:\\Luccme\\TerraME\\bin\\luccme.bat";
#endif
#ifndef LUCCME
	cmd->StartInfo->FileName = "C:\\FillCell\\TerraME\\bin\\luccme.bat";
#endif 
	
	cmd->StartInfo->Arguments = arguments;
	cmd->Start();
	cmd->WaitForExit();
	cmd->Close();

	cmd = gcnew System::Diagnostics::Process;
	arguments = "";
}

System::Void CellFulfill::NovoModelo::NovoModelo_Load(System::Object^  sender, System::EventArgs^  e)
{
	rasterList[COVERAGE] = "coverage";
	rasterList[AVERAGE] = "average";
	rasterList[MODE] = "mode";
	rasterList[MAXIMUM] = "maximum";
	rasterList[MINIMUM] = "minimum";
	rasterList[SUM] = "sum";
	rasterList[STDEV] = "stdev";

	polygonList[P_COVERAGE] = "coverage";
	polygonList[P_AVERAGE] = "average";
	polygonList[P_AREA] = "area";
	polygonList[P_DISTANCE] = "distance";
	polygonList[P_PRESENCE] = "presence";
	polygonList[P_MODE] = "mode";
	polygonList[P_MAXIMUM] = "maximum";
	polygonList[P_MINIMUM] = "minimum";
	polygonList[P_SUM] = "sum";
	polygonList[P_COUNT] = "count";
	polygonList[P_STDEV] = "stdev";

	nonPolygonList[NP_AVERAGE] = "average";
	nonPolygonList[NP_DISTANCE] = "distance";
	nonPolygonList[NP_PRESENCE] = "presence";
	nonPolygonList[NP_MODE] = "mode";
	nonPolygonList[NP_MAXIMUM] = "maximum";
	nonPolygonList[NP_MINIMUM] = "minimum";
	nonPolygonList[NP_SUM] = "sum";
	nonPolygonList[NP_COUNT] = "count";
	nonPolygonList[NP_STDEV] = "stdev";
	
	checkLanguage();

	if (lOpen) {
		try {
			if (lvAttributesToFill->Columns->Count == NONE) {
				lvAttributesToFill->Clear();
				lvAttributesToFill->View = View::Details;
				lvAttributesToFill->GridLines = true;
				lvAttributesToFill->Columns->Add(gSAttributes, lvAttributesToFill->Width - 50, HorizontalAlignment::Left);
				lvAttributesToFill->Columns->Add("Status", 47, HorizontalAlignment::Center);
			}

			CellFulfill::OpenFileDialog^ scriptFile = gcnew OpenFileDialog;
			scriptFile->Title = gSScriptLoad;
			scriptFile->Multiselect = false;
			scriptFile->Filter = gSLuaFile;
			scriptFile->FilterIndex = 1;
			scriptFile->ShowHelp = true;

			bool fileOK = false;

			if (scriptFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ fileName = scriptFile->FileName;
				System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(fileName);

				String^ line = sw->ReadLine();

				// Set Script Definition
				int lastSlash = 0;
				for (int i = 0; i < fileName->Length; i++) {
					if (fileName[i] == '\\') {
						lastSlash = i + 1;
					}
				}

				tScriptName->Text = fileName->Substring(lastSlash, fileName->Length - (lastSlash + EXTENSION));
				tScriptName->ForeColor = System::Drawing::Color::Black;
				lSelectedFolder->Text = fileName->Substring(0, lastSlash - 1);
				gParameters[SCRIPTNAME] = tScriptName->Text;
				gParameters[SCRIPTFOLDER] = lSelectedFolder->Text;

				// Search if it is a existing cellular space
				while (sw->EndOfStream == false) {
					if (line->Contains("Openning Cellular Space") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						csExist = true;
						break;
					}
				}

				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);
				fileOK = false;


				// Get the attributes address
				while (sw->EndOfStream == false) {
					if (line->Contains("local cs = Layer{") != TRUE) {
						if (line->Contains("file = ") && !line->Contains("t3mp.tview")) {
							line = line->Replace("\\\\", "\\");
							line = line->Replace("file = ", "");
							line = line->Replace("\t", "");
							line = line->Replace("\"", "");
							line = line->Replace(",", "");

							array<String^>^ dataTemp = { line, "", "", "", "", "", "", "" };
							attributeList->Add(dataTemp);

							int lastSlash = 0;
							for (int i = 0; i < line->Length; i++) {
								if (line[i] == '\\') {
									lastSlash = i + 1;
								}
							}

							lvAttributesToFill->Items->Add(line->Substring(lastSlash, line->Length - lastSlash));
						}
						line = sw->ReadLine();
					}
					else {
						fileOK = true;
						break;
					}
				}

				// Remove the limit shape file from the attribute list and set the address
				if (lvAttributesToFill->Items->Count > NONE) {
					array<String^>^ dataTemp = safe_cast<array<String^>^>(attributeList[0]);

					lLimitFileAddress->Text = dataTemp[0];	//Address set
					gParameters[SHPADDRESS] = lLimitFileAddress->Text;
					lvAttributesToFill->Items->RemoveAt(0);
					attributeList->RemoveAt(0);

					for (int i = 0; i < lvAttributesToFill->Items->Count; i++) {
						gParameters[SCRIPTATTRIBUTES] += lvAttributesToFill->Items[i]->Text + ";";
					}
				}

				sw->Close();
					
				if (!csExist) {
					sw = gcnew System::IO::StreamReader(fileName);
					fileOK = false;

					bool csResolutionFound = false;
					bool csFileFound = false;

					line = sw->ReadLine();

					// Get Cellular Space Information
					while (sw->EndOfStream == false) {
						if (line->Contains("local cs = Layer{") != TRUE) {
							line = sw->ReadLine();
						}
						else {
							while (sw->EndOfStream == false) {
								if (line->Contains("resolution")) {
									line = line->Replace("\t", "");
									line = line->Replace("resolution = ", "");
									line = line->Replace(",", "");

									tCellSpaceResolution->Text = line;
									tCellSpaceResolution->ForeColor = System::Drawing::Color::Black;
									csResolutionFound = true;
									gParameters[SHPRESOLUTION] = tCellSpaceResolution->Text;
								}

								if (line->Contains("file")) {
									line = line->Replace("\t", "");
									line = line->Replace("file = ", "");
									line = line->Replace(",", "");
									line = line->Replace("\"", "");

									tCellSpaceName->Text = line->Substring(0, line->Length - EXTENSION);
									tCellSpaceName->ForeColor = System::Drawing::Color::Black;
									csFileFound = true;
									gParameters[SHPOUTNAME] = tCellSpaceName->Text;
								}

								if (csFileFound && csResolutionFound) {
									fileOK = true;
									break;
								}

								line = sw->ReadLine();
							}
						}

						if (csFileFound && csResolutionFound) {
							break;
						}
					}

					sw->Close();
				} 
				else {
					cbUseCS->Checked = true;
				}
			
				sw = gcnew System::IO::StreamReader(fileName);
				fileOK = false;

				line = sw->ReadLine();

				while (sw->EndOfStream == false) {
					if (line->Contains("cs:fill{") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						break;
					}
				}

				line = sw->ReadLine();
				for (int i = 0; i < attributeList->Count; i++) {
					while (sw->EndOfStream == false) {
						if (line->Contains("cs:fill{") != TRUE) {
							array<String^>^ dataTemp = safe_cast<array<String^>^>(attributeList[i]);
							if (line->Contains("operation = ")) {
								line = line->Replace("operation = ", "");
								line = line->Replace("\t", "");
								line = line->Replace("\"", "");
								line = line->Replace(",", "");
								dataTemp[AS_OPERATION] = line;
							}
							else if (line->Contains("attribute = ")) {
								line = line->Replace("attribute = ", "");
								line = line->Replace("\t", "");
								line = line->Replace("\"", "");
								line = line->Replace(",", "");
								dataTemp[AS_OUTPUT] = line;
							}
							else if (line->Contains("select = ")) {
								line = line->Replace("select = ", "");
								line = line->Replace("\t", "");
								line = line->Replace("\"", "");
								line = line->Replace(",", "");
								dataTemp[AS_SELECT] = line;
							}
							else if (line->Contains("area = ")) {
								dataTemp[AS_AREA] = "true";
							}
							else if (line->Contains("missing = ")) {
								line = line->Replace("missing = ", "");
								line = line->Replace("\t", "");
								line = line->Replace("\"", "");
								line = line->Replace(",", "");
								dataTemp[AS_DEFAULT] = line;
							}
							else if (line->Contains("dummy = ")) {
								line = line->Replace("dummy = ", "");
								line = line->Replace("\t", "");
								line = line->Replace("\"", "");
								line = line->Replace(",", "");
								dataTemp[AS_DUMMY] = line;
							}
							else if (line->Contains("dataType = ")) {
								line = line->Replace("dataType = ", "");
								line = line->Replace("\t", "");
								line = line->Replace("\"", "");
								line = line->Replace(",", "");
								dataTemp[AS_SHPTYPE] = line;
							}

							line = sw->ReadLine();
						}
						else {
							lvAttributesToFill->Items[i]->SubItems->Add("OK");
							line = sw->ReadLine();
							break;
						}
					}

					if ((i + 1) == attributeList->Count) {
						lvAttributesToFill->Items[i]->SubItems->Add("OK");
						fileOK = true;
					}
				}	
				
				sw->Close();
			}

			if (fileOK) {
				lRunScript->Visible = true;
				bRun->Visible = true;
				runnable = true;
				checkLanguage();
				this->Text = gSEditing;
			}
		}
		catch (Exception^ e) {
			if (e->GetType()->ToString() == "System.IndexOutOfRangeException") {
				MessageBox::Show(gSImportError, gSImportErrorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				closing = true;
				this->Close();
			}
		}
	}
}

System::Void CellFulfill::NovoModelo::cbUseCS_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (cbUseCS->Checked) {
		checkLanguage();
		
		tCellSpaceName->Text = "";
		tCellSpaceName->Enabled = false;
		tCellSpaceResolution->Text = "";
		tCellSpaceResolution->Enabled = false;
		
		if (!csExist) {
			runnable = false;
			lLimitFileAddress->Text = "";
			lvAttributesToFill->Items->Clear();
			attributeList->Clear();
		}

		csExist = true;
	}
	else if (cbUseCS->Checked == false) {
		csExist = false;
		checkLanguage();
		tCellSpaceName->Enabled = true;
		tCellSpaceResolution->Enabled = true;
	}
}

System::Void CellFulfill::NovoModelo::tCellSpaceResolution_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	tResDummy->Text = tCellSpaceResolution->Text;
}

System::Void CellFulfill::NovoModelo::rbPolygon_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (rbPolygon->Checked) {
		cbOperation->Items->Clear();
		cbOperation->Items->AddRange(polygonList);

		lOperationOut->Visible = false;
		tOperationOut->Visible = false;
		lSelectOperation->Visible = false;
		tSelectOperation->Visible = false;
		lDefaultOperation->Visible = false;
		tDefaultOperation->Visible = false;
		lDummyOperation->Visible = false;
		tDummyOperation->Visible = false;
		lAreaOperation->Visible = false;
		rbTrueOperation->Visible = false;
		rbFalseOperation->Visible = false;
		bSaveOperation->Visible = true;
	}
}

System::Void CellFulfill::NovoModelo::rbLine_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (rbLine->Checked) {
		cbOperation->Items->Clear();
		cbOperation->Items->AddRange(nonPolygonList);
		
		lOperationOut->Visible = false;
		tOperationOut->Visible = false;
		lSelectOperation->Visible = false;
		tSelectOperation->Visible = false;
		lDefaultOperation->Visible = false;
		tDefaultOperation->Visible = false;
		lDummyOperation->Visible = false;
		tDummyOperation->Visible = false;
		lAreaOperation->Visible = false;
		rbTrueOperation->Visible = false;
		rbFalseOperation->Visible = false;
		bSaveOperation->Visible = true;
	}
}

System::Void CellFulfill::NovoModelo::rbDot_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (rbDot->Checked) {
		cbOperation->Items->Clear();
		cbOperation->Items->AddRange(nonPolygonList);

		lOperationOut->Visible = false;
		tOperationOut->Visible = false;
		lSelectOperation->Visible = false;
		tSelectOperation->Visible = false;
		lDefaultOperation->Visible = false;
		tDefaultOperation->Visible = false;
		lDummyOperation->Visible = false;
		tDummyOperation->Visible = false;
		lAreaOperation->Visible = false;
		rbTrueOperation->Visible = false;
		rbFalseOperation->Visible = false;
		bSaveOperation->Visible = true;
	}
}
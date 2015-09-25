#include "stdafx.h"
#include "NovoModelo.h"
#include "LUTForm.h"
#include "MySQLForm.h"
#include "D_PCVINPEForm.h"
#include "D_CITwoDM.h"
#include "D_CIThreeDM.h"
#include "PotDiscreteForm.h"
#include "PotContinuousForm.h"
#include "AllocDiscreteForm.h"
#include "AllocContinuousForm.h"
#include "Function.h"
#include "LanguageForm.h"
#include "AboutForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

System::Void LuccME::NovoModelo::checkLanguage()
{
	if (gPotentialComponent > 5 || gAllocationComponent > 2) {
		bPotDiscrete->Enabled = false;
		bAllocDiscrete->Enabled = false;
		bPotContinuous->Enabled = true;
		bAllocContinuous->Enabled = true;
	}
	else if ((gPotentialComponent > 0 && gPotentialComponent < 6) || (gAllocationComponent > 0 && gAllocationComponent < 3)) {
		bPotDiscrete->Enabled = true;
		bAllocDiscrete->Enabled = true;
		bPotContinuous->Enabled = false;
		bAllocContinuous->Enabled = false;
	}
	else {
		bPotDiscrete->Enabled = true;
		bAllocDiscrete->Enabled = true;
		bPotContinuous->Enabled = true;
		bAllocContinuous->Enabled = true;
	}


	if (lLanguage == "en") {
		//Form
		this->Text = "LuccME - Creating a new model";
		//Menu
		arquivoToolStripMenuItem->Text = "File";
		novoToolStripMenuItem->Text = "New";
		abrirToolStripMenuItem->Text = "Open";
		sairToolStripMenuItem->Text = "Exit";
		preferênciasToolStripMenuItem->Text = "Preferences";
		idiomaToolStripMenuItem->Text = "Language";
		ajudaToolStripMenuItem->Text = "Help";
		sobreToolStripMenuItem->Text = "About";
		//Tabs
		tabPage1->Text = "Model Definitions";
		tabPage2->Text = "Spatial Definitions";
		tabPage3->Text = "Land Use Types";
		tabPage4->Text = "Components";
		tabPage5->Text = "Parameters to Save";
		tabPage6->Text = "Files Maker";
		tabPage7->Text = "Advanced Resources";
		tabPage8->Text = "Validation";
		//tabPage1
		lArquivos->Text = "     Files";
		lDirProj->Text = "Folder to Save the Model";
		bSelectFolder->Text = "Select";
		lDefinicoesModelo->Text = "   Model Definitions";
		lModelName->Text = "Model Name";
		lStartTime->Text = "Start Time";
		lEndTime->Text = "End Time";
		//tabPage2
		lSpacialDimensions->Text = " Spatial Definitions";
		lDatabase->Text = "Database File";
		bSelectDatabase->Text = "Select";
		bMySQL->Text = "Configure";
		lThemeName->Text = "Theme Name";
		lCellArea->Text = "Cell Area";
		//tabPage3
		lLUTLarge->Text = "     Land Use Types";
		lLUTMedium->Text = "Land Use Types";
		bLUTManager->Text = "Manager";
		lLUND->Text = "Land Use No Data";
		bLUNDManager->Text = "Manager";
		//tabPage4
		lComponentes->Text = "   Select the Components";
		lDemand->Text = "Demand ";
		lPotential->Text = "Potential";
		lAllocation->Text = "Allocation";
		bPotDiscrete->Text = "Discrete Components";
		bPotContinuous->Text = "Continuous Components";
		bAllocDiscrete->Text = "Discrete Components";
		bAllocContinuous->Text = "Continuous Components";
		//tabPage5
		lSalvar->Text = "Save";
		lOutputTheme->Text = "Ouput Theme Name";
		cSaveYearly->Text = "Yearly Save";
		lSelectYears->Text = "     Years to Save";
		bSelectedYears->Text = "Select";
		lSaveAttr->Text = "      Attributes to Save";
		bSelectedAttr->Text = "Select";
		//tabPage6
		lFileMaker->Text = "       Files Maker";
		bGerarArquivos->Text = "Make Files";
		lRunModel->Text = "       Run Model";
		bRun->Text = "Run Model";
		//tabPage7
		cDynamicVariables->Text = "Dynamic Variables";
		lAnosVariaveis->Text = "Years with variables";
		lAtualizaveis->Text = "     to be Updated";
		bDynamicSelect->Text = "Select";
		cScenario->Text = "Scenario";
		lScenariosStartTime->Text = "    Scenario Start Time";
		lScenarioName->Text = "  Scenario Name";
		//tabPage8
		lInputThemeName->Text = "  Theme Name";
		lAttributeForValidation->Text = "Attribute for Validation";
		lAttributeFinalValidation->Text = "Real Final Attribute";
		lAttributeInitValidation->Text = "Initial Attribute";
		bValidate->Text = "Validate";
		//Strings
		gSExit = "The data changed will be lost.\nDo you want to proceed?";
		gSExitTitle = "Exiting - Data not saved";
		gSSuccessTitle = "Files successfully generate";
		gSSuccess = "Files successfully recorded:\n";
		gSEditing = "LuccME - Editing a model";
		gSNewModel = "All the data will be lost.\nDo you want to proceed?";
		gSNewModelTitle = "Create a New Model";
		gSOpenModelTitle = "Open a New Model";
		gSMainImport = "Main file imported with sucess.\nSelect the Submodel File.";
		gSMainImportTitle = "Main File Loaded, Select Submodel";
		gSMainLoad = "Select the Main File."; 
		gSMainLoadTitle = "Main File to Import";
		gSMainFile = "Select Main File";
		gSSubmodelFile = "Select Submodel File";
		gSLuaFile = "Lua File(*.lua)|*.lua";
		gSAccess = "Access Database";
		gSDBTitle = "Select a Database File";
		gSDBFilter = "Access Database (*.mdb)|*.mdb";
		gSMySQL = "MySQL Database";
		gSLUTManager = "Land Use no Data Manager";
		gSDemand1Info = "Another demand component was modified.\nThe demand values will be erased.\nDo you want to proceed?";
		gSDemand1Title = "Another demand component already in use";
		gSDemand2Info = "The Land use types was modified.\nThe demand values will be erased.\nDo you want to proceed?";
		gSDemand2Title = "Using Default Time";
		gSDefaultTime = "Using defalut time for the simulation.\nDo you want to proceed?";
		gStringDefaultTimeTitle = "Using Default Time";
		gSLUTNotDef = "The Land Use Types must be defined.";
		gSLUTNotDefTitle = "Error - Land Use Types not informed.";
		gSTimeNotDef = "The suimulation time (start and end) must be defined.";
		gSTimeNotDefTitle = "Error - Initial and Final time not informed";
		gSLUT = "Land Use Types";
		gSAnos = "Years";
		gSFolder = "Project folder not selected in Model Definition.";
		gSFolderTitle = "Error - Project folder is missing";
		gSModelName = "Model Name not defined in Model Definition.";
		gSModelNameTitle = "Error - Model Name is missing";
		gSStartTime = "Start Time not defined in Model Definition.";
		gSStartTimeTitle = "Error - Start Time is missing";
		gSEndTime = "End Time not defined in Model Definition.";
		gSEndTimeTitle = "Error - End Time is missing";
		gSDBSave = "Database not set in Spatial Definitions.";
		gSDBSaveTitle = "Error - Databse not set";
		gSThemeName = "Theme Name not defined in Spatial Definition.";
		gSThemeNameTitle = "Error - Theme Name is missing";
		gSCellArea = "Cell Area not defined in Spatial Definition.";
		gSCellAreaTitle = "Error - Cell Area is missing";
		gSLUTShow = "Land Use Types not defined in Land Use Types.";
		gSLUTShowTitle = "Error - Land Use Types are missing";
		gSLUTNDShow = "Land Use Types No Data not defined in Land Use Types.";
		gSLUTNDShowTitle = "Error - Land Use Types No Data are missing";
		gSDemandnS = "Demand Component not selected in Components.";
		gSDemandnSTitle = "Error - Demand Component not selected";
		gSPotentialnS = "Potential Component not selected in Components.";
		gSPotentialnSTitle = "Error - Potential Component not selected";
		gSAllocationnS = "Allocation Component not selected in Components.";
		gSAllocationnSTitle = "Error - Allocation Component not selected";
		gSOutputTheme = "Output Theme Name not defined in Save.";
		gSOutputThemeTitle = "Error - Output Theme Name is missing";
		gSYearSave = "Years to be save not defined in Save.\nSelect one of the options.";
		gSYearSaveTitle = "Error - Years to be save not defined";
		gSAlloCont = "A Continuous Allocation Component was modified.\nDo you want to set a Discrete Potential Component?";
		gSPotDiscTitle = "Open Discrete Potential Component (Continuos Allocation)";
		gSAlloDisc = "A Discrete Allocation Component was modified.\nDo you want to set a Continuous Potential Component?"; 
		gSPotContTitle = "Open Continuous Potential Component (Discrete Allocation)";
		gSPotCont = "A Continuous Pontential Component was modified.\nDo you want to set a Discrete Allocation Component?"; 
		gSAllocDiscTitle = "Open Discrete Allocation Component (Continuos Potential)";
		gSPotDisc = "A Discrete Pontential Component was modified.\nDo you want to set a Continuous Allocation Component?"; 
		gSAllocContTitle = "Open Continuous Allocation Component (Discrete Potential)";
		gSUnauthorized = "You do not have writting permission on the selected folder.\nTry a different one or run LuccME as admin.";
		gSUnauthorizedTitle = "Error - Writting Permimission";
		gSPotContAlocDisc = "Continuous Potential Component and Discrete Allocation Component.";
		gSPotContAlocDiscTitle = "Error - Using Continuous and Discrete Components";
		gSPotDiscAlocCont = "Discrete Potential Component and Continuous Allocation Component.";
		gSImportError = "Incloplete file, can't import it.";
		gSImportErrorTitle = "Error - Importing Files";
		gSMFE = "Error recording the main file.";
		gSMFETitle = "Error - Files Generation";
		gSSMFE = "Error recording the submodel file.";
		gSFE = "An unexpected error while recording the files.";
		gSCheckDyn = "The years for update the dynamic variables must be selected.";
		gSCheckDynTitle = "Error - Years of Dynamic Variables";
		gSScenName = "The name of the scenario must be fulfilled.";
		gSScenNameTitle = "Error - Scenario Name";
		gSScenST = "The start time of the scenarios must be informed.";
		gSScenSTTitle = "Error - Scenario Start Time";
	}
	else {
		//Form
		this->Text = "LuccME - Criando um novo modelo";
		//Menu
		arquivoToolStripMenuItem->Text = "Arquivo";
		novoToolStripMenuItem->Text = "Novo";
		abrirToolStripMenuItem->Text = "Abrir";
		sairToolStripMenuItem->Text = "Sair";
		preferênciasToolStripMenuItem->Text = "Preferências";
		idiomaToolStripMenuItem->Text = "Idioma";
		ajudaToolStripMenuItem->Text = "Ajuda";
		sobreToolStripMenuItem->Text = "Sobre";
		//Tabs
		tabPage1->Text = "Definições do Modelo";
		tabPage2->Text = "Definições Espaciais";
		tabPage3->Text = "Tipos de Uso da Terra";
		tabPage4->Text = "Componentes";
		tabPage5->Text = "Salvar Parâmetros";
		tabPage6->Text = "Gerar Arquivos";
		tabPage7->Text = "Recursos Avançados";
		//tabPage1
		lArquivos->Text = "Arquivos";
		lDirProj->Text = "Pasta para Salvar o Modelo";
		bSelectFolder->Text = "Selecionar";
		lDefinicoesModelo->Text = "Definições do Modelo";
		lModelName->Text = "Nome do Modelo";
		lStartTime->Text = "Ano de Início";
		lEndTime->Text = "Ano de Término";
		//tabPage2
		lSpacialDimensions->Text = "Definições Espaciais";
		lDatabase->Text = "Arquivo do Banco de Dados";
		bSelectDatabase->Text = "Selecionar";
		bMySQL->Text = "Configurar";
		lThemeName->Text = "Nome do Tema";
		lCellArea->Text = "Tamanho da Célula";
		//tabPage3
		lLUTLarge->Text = "Tipos de Uso da Terra";
		lLUTMedium->Text = "Tipos de Uso da Terra";
		bLUTManager->Text = "Gerenciar";
		lLUND->Text = "Tipo de Uso com \"No Data\"";
		bLUNDManager->Text = "Gerenciar";
		//tabPage4
		lComponentes->Text = "Selecione os Componentes";
		lDemand->Text = "Demanda";
		lPotential->Text = "Potencial";
		lAllocation->Text = " Alocação";
		bPotDiscrete->Text = "Componentes Discretos";
		bPotContinuous->Text = "Componentes Contínuos";
		bAllocDiscrete->Text = "Componentes Discretos";
		bAllocContinuous->Text = "Componentes Contínuos";
		//tabPage5
		lSalvar->Text = "Salvar";
		lOutputTheme->Text = "Nome do Tema de Saída";
		cSaveYearly->Text = "Salvar Anualmente";
		lSelectYears->Text = "Anos a serem Salvos";
		bSelectedYears->Text = "Selecionar";
		lSaveAttr->Text = "Atributos a serem Salvos";
		bSelectedAttr->Text = "Selecionar";
		//tabPage6
		lFileMaker->Text = "Gerar os Arquivos";
		bGerarArquivos->Text = "Gerar Arquivos";
		lRunModel->Text = "Rodar o Modelo";
		bRun->Text = "Rodar Modelo";
		//tabPage7
		cDynamicVariables->Text = "Variáveis Dinamicas";
		lAnosVariaveis->Text = "Anos com Variáveis";
		lAtualizaveis->Text = "a serem Atualizadas";
		bDynamicSelect->Text = "Selecionar";
		cScenario->Text = "Cenário";
		lScenariosStartTime->Text = "Ano de Início do Cenário";
		lScenarioName->Text = "Nome de Cenário";
		//tabPage8
		lInputThemeName->Text = "Nome do Tema";
		lAttributeForValidation->Text = "Atributo a ser Validado";
		lAttributeFinalValidation->Text = "Atributo Real Final";
		lAttributeInitValidation->Text = "Atributo Inicial";
		bValidate->Text = "Validar";
		//Strings
		gSScenST = "O ano de início do cenário deve ser preenchido.";
		gSScenSTTitle = "Erro - Ano de início dos Cenários";
		gSCheckDyn = "Os anos de atualização das variáveis dinâmicas devem ser selecionados."; 
		gSCheckDynTitle = "Erro - Anos Variáveis Dinâmicas";
		gSFE = "Erro não esperado gravando os arquivos.";
		gSSMFE = "Erro na gravação do arquivo Submodel.";
		gSMFE = "Erro na gravação do arquivo Main.";
		gSMFETitle = "Erro - Geração dos Arquivos";
		gSImportError = "Arquivo incompleto, não pode ser carregado."; 
		gSImportErrorTitle = "Erro - Importando Arquivos";
		gSPotDiscAlocCont = "Componente de Potencial Discreto e Componente de Alocação Contínuo.";
		gSPotContAlocDisc = "Componente de Potencial Contínuo e Componente de Alocação Discreto.";
		gSPotContAlocDiscTitle = "Erro - Componentes Contínuos e Discretos sendo utilizados";
		gSExit = "Os dados alterados serão perdidos.\nDeseja Continuar?";
		gSExitTitle = "Saindo - Dados não salvos";
		gSSuccessTitle = "Arquivos gerados com Sucesso";
		gSSuccess = "Arquivos gravados com sucesso:\n";
		gSEditing = "LuccME - Editando um modelo";
		gSNewModel = "Todos os dados serão perdidos.\nDeseja Continuar?";
		gSNewModelTitle = "Criar um Novo Modelo";
		gSOpenModelTitle = "Abrir um Novo Modelo";
		gSMainImport = "Arquivo Main importado com sucesso.\nSelecione o Arquivo do Submodelo.";
		gSMainImportTitle = "Arquivo Main Carregado, Selecione o Submodelo";
		gSMainLoad = "Selecione o Arquivo Main.";
		gSMainLoadTitle = "Arquivo Main a ser Importado";
		gSMainFile = "Selecione o arquivo Main";
		gSSubmodelFile = "Selecione o arquivo Submodel";
		gSLuaFile = "Arquivo Lua (*.lua)|*.lua";
		gSAccess = "Banco de dados Access";
		gSDBTitle = "Escolha o arquivo do Bando de Dados";
		gSDBFilter = "Banco Access (*.mdb)|*.mdb";
		gSMySQL = "Banco de dados MySQL";
		gSLUTManager = "Gerenciador de Tipo de Uso da Terra sem Dados";
		gSDemand1Info = "Outro componente de demanda foi modificado anteriormente.\nOs valores de demanda serão apagados.\nDeseja continuar?";
		gSDemand1Title = "Outro componente de Demanda já utilizado";
		gSDemand2Info = "Os Tipos de uso da terra foram modificados.\nOs valores de demanda serão apagados.\nDeseja continuar?";
		gSDemand2Title = "Utilizando Tempo Padrão";
		gSDefaultTime = "Utilizando tempo de simulação padrão.\nDeseja continuar?";
		gStringDefaultTimeTitle = "Utilizando Tempo Padrão";
		gSLUTNotDef = "Os Tipos de Uso da Terra devem ser definidos.";
		gSLUTNotDefTitle = "Erro - Tipos de Uso da Terra não informados";
		gSTimeNotDef = "Os tempos da Simulação (inicial e final) devem ser definidos.";
		gSTimeNotDefTitle = "Erro - Tempos inicial e final não informados.";
		gSLUT = "Tipos de Uso da Terra";
		gSAnos = "Anos";
		gSFolder = "Pasta do projeto não selecionada em Definições do Modelo.";
		gSFolderTitle = "Erro - Pasta do projeto não selecionada";
		gSModelName = "Nome do Modelo não definido em Definições do Modelo.";
		gSModelNameTitle = "Erro - Nome do Modelo não definido";
		gSStartTime = "Ano de Início não definido em Definições do Modelo.";
		gSStartTimeTitle = "Erro - Ano de Início não definido";
		gSEndTime = "Ano de Termino não definido em Definições do Modelo.";
		gSEndTimeTitle = "Erro - Ano de Termino não definido";
		gSDBSave = "Banco de dados não definido em Definições Espaciais.";
		gSDBSaveTitle = "Error - Banco de dados não definido";
		gSThemeName = "Nome do Tema não definido em Definições Espaciais.";
		gSThemeNameTitle = "Erro - Nome do Tema não definido";
		gSCellArea = "Cell Area não definido em Definições Espaciais.";
		gSCellAreaTitle = "Erro - Cell Area não definido";
		gSLUTShow = "Tipos de Uso da Terra não definidos em Tipos de Uso da Terra";
		gSLUTShowTitle = "Erro - Tipos de Uso da Terra não definidos";
		gSLUTNDShow = "Tipos de Uso da Terra sem Dados não definidos em Tipos de Uso da Terra";
		gSLUTNDShowTitle = "Erro - Tipos de Uso da Terra sem Dados não definidos";
		gSDemandnS = "Component de Demanda não selecionado em Componentes.";
		gSDemandnSTitle = "Erro - Component de Demanda não selecionado";
		gSPotentialnS = "Component de Potencial não selecionado em Componentes.";
		gSPotentialnSTitle = "Erro - Component de Potencial não selecionado";
		gSAllocationnS = "Component de Alocação não selecionado em Componentes.";
		gSAllocationnSTitle = "Erro - Component de Alocação não selecionado";
		gSOutputTheme = "Nome do tema de saída não definido em Salvar Parâmetros.";
		gSOutputThemeTitle = "Erro - Nome do Tema de Saída não definido";
		gSYearSave = "Os anos a serem salvos não foram definidos em Salva Parâmetros.\nSelecione uma das opções.";
		gSYearSaveTitle = "Error - Anos a serem salvos não definidos";
		gSAlloCont = "Um Componente de Alocação Contínuo foi alterado.\nVocê deseja abrir um Componente de Potencial Discreto?";
		gSPotDiscTitle = "Abrir Componente de Potencial Discreto (Alocação Contínuo)";
		gSAlloDisc = "Um Componente de Alocação Discreto foi alterado.\nVocê deseja abrir um Componente de Potencial Contínuo?";
		gSPotContTitle = "Abrir Componente de Potencial Contínuos (Alocação Discreto)";
		gSPotCont = "Um Componente de Potencial Contínuo foi alterado.\nVocê deseja abrir um Componente de Alocação Discreto?";
		gSAllocDiscTitle = "Abrir Componente de Alocação Discreto (Potencial Contínuo)";
		gSPotDisc = "Um Componente de Potencial Discreto foi alterado.\nVocê deseja abrir um Componente de Alocação Contínuo?";
		gSAllocContTitle = "Abrir Componente de Alocação Contínuo (Potencial Discreto)";
		gSUnauthorized = "Você não possui permissão de escrita no diretório selecionado.\nEscolha outro diretório ou execute o LuccME como administrador.";
		gSUnauthorizedTitle = "Erro - Permissão de escrita";
		gSScenName = "O nomde do cenário deve ser preenchido.";
		gSScenNameTitle = "Erro - Nome do Cenário";
	}
}

System::Void LuccME::NovoModelo::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void LuccME::NovoModelo::bSelectFolder_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LuccME::FolderBrowserDialog^ modelFolder = gcnew FolderBrowserDialog();

	if (modelFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		lSelectedFolder->Text = modelFolder->SelectedPath;
	}
}

System::Void LuccME::NovoModelo::bSelectDatabase_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LuccME::OpenFileDialog^ bdFile = gcnew OpenFileDialog;
	bdFile->Title = gSDBTitle;
	bdFile->Multiselect = false;
	bdFile->Filter = gSDBFilter;
	bdFile->FilterIndex = 1;

	if (bdFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		gSelectedDatabase = bdFile->FileName;
		array<String^>^ lines = { gSAccess, bdFile->FileName };
		tbSelectedBatabase->Lines = lines;
		access = true;
	}
}

System::Void LuccME::NovoModelo::bMySQL_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cReturn^ lDatabase = gcnew cReturn();
	if (access)
	{
		lDatabase->Return = "";
	}
	else {
		if (tbSelectedBatabase->Text != "") {
			array<String^>^ auxLines = tbSelectedBatabase->Lines;
			String^ auxLine = "";

			auxLine += auxLines[1]->Substring(gSHost->Length);
			auxLine += ",";
			auxLine += auxLines[2]->Substring(gSUser->Length);
			auxLine += ",";
			auxLine += auxLines[3]->Substring(gSPassword->Length);
			auxLine += ",";
			auxLine += auxLines[4]->Substring(gSDatabase->Length);
		}
		lDatabase->Return = gSelectedDatabase;
	}
	
	lDatabase->Language = lLanguage;

	LuccME::MySQLForm^ mySQLForm = gcnew MySQLForm(lDatabase);
	mySQLForm->ShowDialog();
	
	gSelectedDatabase = lDatabase->Return;

	if (gSelectedDatabase != "") {
		array<String^>^ lines = { gSMySQL, "", "", "", "" };

		if (gSelectedDatabase->Length > 0) {
			String^ aux = "";
			int count = 1;
			for (int i = 0; i < gSelectedDatabase->Length; i++) {
				if (gSelectedDatabase[i] != ',') {
					aux += gSelectedDatabase[i];
				}
				else {
					switch (count) {
					case 1:
						lines[1] = String::Concat(gSHost, aux);
						count++;
						break;
					case 2:
						lines[2] = String::Concat(gSUser, aux);
						count++;
						break;
					case 3:
						lines[3] = String::Concat(gSPassword, aux);
						count++;
						break;
					default:
						break;
					}
					aux = "";
				}
			}

			if (aux != "") {
				lines[4] = String::Concat(gSDatabase, aux);
			}
		}
		tbSelectedBatabase->Lines = lines;
		access = false;
	}
}

System::Void LuccME::NovoModelo::bLUTManager_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cReturn^ lLandUses = gcnew cReturn();
	lLandUses->Return = gLandUseTypes;
	lLandUses->Language = lLanguage;

	LuccME::LUTForm^ landUseTypeForm = gcnew LUTForm(lLandUses);
	landUseTypeForm->ShowDialog();

	gLandUseTypes = lLandUses->Return;
	lLUTShow->Text = gLandUseTypes;
}

System::Void LuccME::NovoModelo::bLUNDManager_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cReturn^ lLandUsesNoData = gcnew cReturn();
	if (gLandUseNoData == "" && gLandUseTypes != "") {
		gLandUseNoData = gLandUseTypes;
	}
	lLandUsesNoData->Return = gLandUseNoData;
	lLandUsesNoData->Language = lLanguage;
	
	LuccME::LUTForm^ landUseTypeForm = gcnew LUTForm(lLandUsesNoData);
	landUseTypeForm->Text = gSLUTManager;
	landUseTypeForm->ShowDialog();

	gLandUseNoData = lLandUsesNoData->Return;
	lLUNDShow->Text = gLandUseNoData;
}

System::Void LuccME::NovoModelo::bD_PCVINPE_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cReturnPCVINPE^ lDemand = gcnew cReturnPCVINPE();
	bool check = true;

	if (gDemand == "" || gDemandLUT->Length != gLandUseTypes->Length || gDemandComponent != 1) {
		if (gDemandComponent != 1 && gDemandComponent != 0 ) {
			if (MessageBox::Show(gSDemand1Info, gSDemand1Title, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::Yes) {
				lDemand->Return = gLandUseTypes;
				lDemand->Empty = true;
			}
			else {
				check = false;
			}
		}
		if (gDemandLUT->Length != gLandUseTypes->Length && gDemand != "") {
			if (MessageBox::Show(gSDemand2Info, gSDemand2Title, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::Yes) {
				lDemand->Return = gLandUseTypes;
				lDemand->Empty = true;
			}
			else {
				check = false;
			}
		}
		else {
			lDemand->Return = gLandUseTypes;
			lDemand->Empty = true;
		}
	}
	else {
		lDemand->Return = gLandUseTypes + ";" + gDemand;
		lDemand->Empty = false;
	}

	if (gLandUseTypes != "" && tEndTime->Text != "" && tStartTime->Text != "") {
		if (tEndTime->ForeColor != System::Drawing::Color::Black || tStartTime->ForeColor != System::Drawing::Color::Black) {
			if (MessageBox::Show(gSDefaultTime,gStringDefaultTimeTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
				check = false;
			}
		}
	}
	else {
		if (gLandUseTypes == "") {
			MessageBox::Show(gSLUTNotDef, gSLUTNotDefTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = false;
		}
		else {
			MessageBox::Show(gSTimeNotDef, gSTimeNotDefTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = false;
		}
	}

	if (check) {
		lDemand->StartTime = tStartTime->Text;
		lDemand->YearsForSimulation = Convert::ToInt16(tEndTime->Text) - Convert::ToInt16(tStartTime->Text) + 1;
		lDemand->LUT = gLandUseTypes;
		lDemand->Language = lLanguage;

		LuccME::D_PCVINPEForm^ demandForm = gcnew D_PCVINPEForm(lDemand);
		demandForm->ShowDialog();

		gDemand = lDemand->Return;
		gDemand = gDemand->Replace("\n", "");
		gDemand = gDemand->Replace("\r", "");
		gDemandLUT = gLandUseTypes;
		if (gDemand != "") {
			int count = 0;
			for (int i = 0; i < gDemand->Length; i++) {
				if (gDemand[i] == ';') {
					count++;
				}
			}
			array<String^>^ lines = gcnew array<String^>(count + 3); //If has 1 semicolon there are 2 values + header (2)
			String^ auxLine = "";
			lines[0] = "PreComputedValuesINPE";
			lines[1] = gDemandLUT;
			count = 2;
			for (int i = 0; i < gDemand->Length; i++) {
				if (gDemand[i] != ';') {
					auxLine += gDemand[i];
				}
				else {
					lines[count] = auxLine;
					auxLine = "";
					count++;
				}
			}
			if (auxLine != "") {
				lines[count] = auxLine;
			}
			tbDemand->Lines = lines;
			gDemandComponent = 1;
		}
	}
}

System::Void LuccME::NovoModelo::bD_CITwoDM_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cReturnCITwoMP^ lDemand = gcnew cReturnCITwoMP();
	bool check = true;

	if (gDemand == "" || gDemandLUT->Length != gLandUseTypes->Length || gDemandComponent != 2) {
		if (gDemandComponent != 2 && gDemandComponent != 0) {
			if (MessageBox::Show(gSDemand1Info, gSDemand1Title, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::Yes) {
				lDemand->Return = gLandUseTypes;
				lDemand->Empty = true;
			}
			else {
				check = false;
			}
		}
		if (gDemandLUT->Length != gLandUseTypes->Length && gDemand != "") {
			if (MessageBox::Show(gSDemand2Info, gSDemand2Title, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::Yes) {
				lDemand->Return = gLandUseTypes;
				lDemand->Empty = true;
			}
			else {
				check = false;
			}
		}
		else {
			lDemand->Return = gLandUseTypes;
			lDemand->Empty = true;
		}
	}
	else {
		lDemand->Return = gLandUseTypes + ";" + gDemand;
		lDemand->Empty = false;
	}

	if (gLandUseTypes == "") {
		MessageBox::Show(gSLUTNotDef, gSLUTNotDefTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = false;
	}

	if (check) {
		lDemand->FinalYear = Convert::ToInt16(tEndTime->Text);
		lDemand->LUT = gLandUseTypes;
		lDemand->Language = lLanguage;
		LuccME::D_CITwoDM^ demandForm = gcnew D_CITwoDM(lDemand);
		demandForm->ShowDialog();
		gDemand = lDemand->Return;
		gDemandLUT = gLandUseTypes;
		if (gDemand != "") {
			gDemandFinalYear = Convert::ToString(lDemand->FinalYear);
			int count = 0;
			
			for (int i = 0; i < gDemand->Length; i++) {
				if (gDemand[i] == ',') {
					count++;
				}
			}
			array<String^>^ lines = gcnew array<String^>(4); 
			lines[0] = "ComputeInputTwoDateMaps";
			lines[1] = "finalYearForInterpolation = " + gDemandFinalYear;
			lines[2] = gDemandLUT;
			lines[3] = gDemand;

			tbDemand->Lines = lines;
			gDemandComponent = 2;
		}
	}
}

System::Void LuccME::NovoModelo::bD_CIThreeDM_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cReturnCIThreeMP^ lDemand = gcnew cReturnCIThreeMP();
	bool check = true;

	if (gDemand == "" || gDemandLUT->Length != gLandUseTypes->Length || gDemandComponent != 3) {
		if (gDemandComponent != 3 && gDemandComponent != 0) {
			if (MessageBox::Show(gSDemand1Info, gSDemand1Title, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::Yes) {
				lDemand->Return = gLandUseTypes;
				lDemand->Empty = true;
			}
			else {
				check = false;
			}
		}
		if (gDemandLUT->Length != gLandUseTypes->Length && gDemand != "") {
			if (MessageBox::Show(gSDemand2Info, gSDemand2Title, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::Yes) {
				lDemand->Return = gLandUseTypes;
				lDemand->Empty = true;
			}
			else {
				check = false;
			}
		}
		else {
			lDemand->Return = gLandUseTypes;
			lDemand->Empty = true;
		}
	}
	else {
		lDemand->Return = gLandUseTypes + ";" + gDemand;
		lDemand->Empty = false;
	}

	if (gLandUseTypes == "") {
		MessageBox::Show(gSLUTNotDef, gSLUTNotDefTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = false;
	}

	if (check) {
		lDemand->MiddleYear = (Convert::ToInt16(tEndTime->Text) - Convert::ToInt16(tStartTime->Text)) / 2 + Convert::ToInt16(tStartTime->Text);
		lDemand->FinalYear = Convert::ToInt16(tEndTime->Text);
		lDemand->LUT = gLandUseTypes;
		lDemand->Language = lLanguage;
		LuccME::D_CIThreeDM^ demandForm = gcnew D_CIThreeDM(lDemand);
		demandForm->ShowDialog();
		gDemand = lDemand->Return;
		gDemandLUT = gLandUseTypes;
		if (gDemand != "") {
			gDemandFinalYear = Convert::ToString(lDemand->FinalYear);
			gDemandMiddleYear = Convert::ToString(lDemand->MiddleYear);

			array<String^>^ lines = gcnew array<String^>(6);
			lines[0] = "ComputeInputThreeDateMaps";
			lines[1] = "middleYearForInterpolation = " + gDemandMiddleYear;
			lines[2] = "finalYearForInterpolation = " + gDemandFinalYear;

			String^ auxline = "";
			int i = 0;
			while (gDemand[i] != ';') {
				auxline += gDemand[i];
				i++;
			}
			lines[3] = gDemandLUT;
			lines[4] = auxline;
			lines[5] = gDemand->Substring(i + 1);

			tbDemand->Lines = lines;
			gDemandComponent = 3;
		}
	}
}

System::Void LuccME::NovoModelo::bPotDiscrete_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (gAllocationComponent > 2) {
		if (MessageBox::Show(gSAlloCont, gSPotDiscTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
	}

	if (gLandUseTypes == "") {
		MessageBox::Show(gSLUTNotDef, gSLUTNotDefTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = false;
	}

	if (check) {
		cReturnPotential^ lPotential = gcnew cReturnPotential();
		lPotential->Return = gPotential;
		lPotential->LUT = gLandUseTypes;
		lPotential->Component = gPotentialComponent;
		lPotential->Language = lLanguage;
		PotDiscreteForm^ potDiscreteForm = gcnew PotDiscreteForm(lPotential);
		potDiscreteForm->ShowDialog();
		gPotential = lPotential->Return;
		gPotentialComponent = lPotential->Component;
		gPotentialLUT = gLandUseTypes;

		int count = 2;
		int lineCount = 0;
		for (int i = 0; i < gPotentialLUT->Length; i++) {
			if (gPotentialLUT[i] == ',') {
				count++;
			}
		}

		array<String^>^ lines = { "" };
		array<String^>^ lines2 = gcnew array<String^>(count);
		lines2[0] = "InverseDistanceRule";
		array<String^>^ lines3 = gcnew array<String^>(count + 1);
		array<String^>^ lines4 = gcnew array<String^>(count + 2);

		switch (lPotential->Component)
		{
		case 1:
			lines[0] = "NeighSimpleRule{}";
			tbPotential->Lines = lines;
			break;

		case 2:
			lines2[0] = "NeighInverseDistanceRule";

		case 3:
			if (gPotential != "") {
				lineCount = 1;
				for (int i = 0; i < gPotential->Length; i++) {
					if (gPotential[i] != '#') {
						lines2[lineCount] += gPotential[i];
					}
					else {
						lines2[lineCount] = String::Concat("const=", lines2[lineCount]);
						lines2[lineCount] = lines2[lineCount]->Replace(";", ",betas={");
						lines2[lineCount] = lines2[lineCount]->Replace("=", " = ");
						lines2[lineCount] = lines2[lineCount]->Replace(",", ", ");
						lines2[lineCount] = lines2[lineCount] = String::Concat(lines2[lineCount], "}");
						lineCount++;
					}
				}
				if (lines2[lineCount] != "") {
					lines2[lineCount] = String::Concat("const=", lines2[lineCount]);
					lines2[lineCount] = lines2[lineCount]->Replace(";", ",betas={");
					lines2[lineCount] = lines2[lineCount]->Replace("=", " = ");
					lines2[lineCount] = lines2[lineCount]->Replace(",", ", ");
					lines2[lineCount] = lines2[lineCount] = String::Concat(lines2[lineCount], "}");
				}
				tbPotential->Lines = lines2;
			}
			break;

		case 4:
			if (gPotential != "") {
				lines3[0] = "LogisticRegression";
				lineCount = 1;
				bool first = true;
				for (int i = 0; i < gPotential->Length; i++) {
					if (gPotential[i] != '#') {
						if (gPotential[i] != ';') {
							lines3[lineCount] += gPotential[i];
						}
						else {
							if (first) {
								lines3[lineCount] += "$";
								first = false;
							}
							else {
								lines3[lineCount] += gPotential[i];
							}
						}
					}
					else {
						lines3[lineCount] = String::Concat("const=", lines3[lineCount]);
						lines3[lineCount] = lines3[lineCount]->Replace("$", ",elasticity=");
						lines3[lineCount] = lines3[lineCount]->Replace(";", ",betas={");
						lines3[lineCount] = lines3[lineCount]->Replace("=", " = ");
						lines3[lineCount] = lines3[lineCount]->Replace(",", ", ");
						lines3[lineCount] = lines3[lineCount] = String::Concat(lines3[lineCount], "}");
						lineCount++;
						first = true;
					}
				}
				if (lines3[lineCount] != "") {
					lines3[lineCount] = String::Concat("const=", lines3[lineCount]);
					lines3[lineCount] = lines3[lineCount]->Replace("$", ",elasticity=");
					lines3[lineCount] = lines3[lineCount]->Replace(";", ",betas={");
					lines3[lineCount] = lines3[lineCount]->Replace("=", " = ");
					lines3[lineCount] = lines3[lineCount]->Replace(",", ", ");
					lines3[lineCount] = lines3[lineCount] = String::Concat(lines3[lineCount], "}");
				}
				tbPotential->Lines = lines3;
			}
			break;

		case 5:
			if (gPotential != "") {
				lines4[0] = "NeighAttractionLogisticRegression";
				lineCount = 1;
				bool first = true;
				bool second = true;
				for (int i = 0; i < gPotential->Length; i++) {
					if (gPotential[i] != '#') {
						if (gPotential[i] != ';') {
							lines4[lineCount] += gPotential[i];
						}
						else {
							if (first) {
								lines4[lineCount] += "$";
								first = false;
							}
							else if (second) {
								lines4[lineCount] += "@";
								second = false;
							}
							else {
								lines4[lineCount] += gPotential[i];
							}
						}
					}
					else {
						lines4[lineCount] = String::Concat("const=", lines4[lineCount]);
						lines4[lineCount] = lines4[lineCount]->Replace("$", ",elasticity=");
						lines4[lineCount] = lines4[lineCount]->Replace("@", ",percNeighborsUse=");
						lines4[lineCount] = lines4[lineCount]->Replace(";", ",betas={");
						lines4[lineCount] = lines4[lineCount]->Replace("=", " = ");
						lines4[lineCount] = lines4[lineCount]->Replace(",", ", ");
						lines4[lineCount] = lines4[lineCount] = String::Concat(lines4[lineCount], "}");
						lineCount++;
						first = true;
						second = true;
					}
				}
				if (lines4[lineCount] != "") {
					lines4[lineCount] = String::Concat("const=", lines4[lineCount]);
					lines4[lineCount] = lines4[lineCount]->Replace("$", ",elasticity=");
					lines4[lineCount] = lines4[lineCount]->Replace("@", ",percNeighborsUse=");
					lines4[lineCount] = lines4[lineCount]->Replace(";", ",betas={");
					lines4[lineCount] = lines4[lineCount]->Replace("=", " = ");
					lines4[lineCount] = lines4[lineCount]->Replace(",", ", ");
					lines4[lineCount] = lines4[lineCount] = String::Concat(lines4[lineCount], "}");
				}
				tbPotential->Lines = lines4;
			}
			break;
		}
	}
	checkLanguage();
}

System::Void LuccME::NovoModelo::bPotContinuous_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;

	if (gAllocationComponent != 0 && gAllocationComponent < 3) {
		if (MessageBox::Show(gSAlloDisc, gSPotContTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
	}

	if (gLandUseTypes == "") {
		MessageBox::Show(gSLUTNotDef, gSLUTNotDefTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = false;
	}

	if (check) {
		cReturnPotential^ lPotential = gcnew cReturnPotential();
		lPotential->Return = gPotential;
		lPotential->LUT = gLandUseTypes;
		lPotential->Component = gPotentialComponent;
		lPotential->Language = lLanguage;
		PotContinuousForm^ potDiscreteForm = gcnew PotContinuousForm(lPotential);
		potDiscreteForm->ShowDialog();
		gPotential = lPotential->Return;
		gPotentialComponent = lPotential->Component;
		gPotentialLUT = gLandUseTypes;

		int count = 2;
		int lineCount = 0;
		for (int i = 0; i < gPotentialLUT->Length; i++) {
			if (gPotentialLUT[i] == ',') {
				count++;
			}
		}

		array<String^>^ lines = gcnew array<String^>(count + 1);
		array<String^>^ lines2 = gcnew array<String^>(count + 4);
		array<String^>^ lines3 = gcnew array<String^>(count + 10);

		switch (lPotential->Component)
		{
		case 6:
			if (gPotential != "") {
				lines[0] = "LinearRegression";
				lineCount = 1;
				bool first = true;
				for (int i = 0; i < gPotential->Length; i++) {
					if (gPotential[i] != '#') {
						if (gPotential[i] != ';') {
							lines[lineCount] += gPotential[i];
						}
						else {
							if (first) {
								lines[lineCount] += "$";
								first = false;
							}
							else {
								lines[lineCount] += gPotential[i];
							}
						}
					}
					else {
						if (lines[lineCount][0] == '0') {
							lines[lineCount] = String::Concat("false", lines[lineCount]->Substring(1));
						}
						else {
							lines[lineCount] = String::Concat("true", lines[lineCount]->Substring(1));
						}
						lines[lineCount] = String::Concat("isLog=", lines[lineCount]);
						lines[lineCount] = lines[lineCount]->Replace("$", ",const=");
						lines[lineCount] = lines[lineCount]->Replace(";", ",betas={");
						lines[lineCount] = lines[lineCount]->Replace("=", " = ");
						lines[lineCount] = lines[lineCount]->Replace(",", ", ");
						lines[lineCount] = lines[lineCount] = String::Concat(lines[lineCount], "}");
						lineCount++;
						first = true;
					}
				}
				if (lines[lineCount] != "") {
					if (lines[lineCount][0] == '0') {
						lines[lineCount] = String::Concat("false", lines[lineCount]->Substring(1));
					}
					else {
						lines[lineCount] = String::Concat("true", lines[lineCount]->Substring(1));
					}
					lines[lineCount] = String::Concat("isLog=", lines[lineCount]);
					lines[lineCount] = lines[lineCount]->Replace("$", ",const=");
					lines[lineCount] = lines[lineCount]->Replace(";", ",betas={");
					lines[lineCount] = lines[lineCount]->Replace("=", " = ");
					lines[lineCount] = lines[lineCount]->Replace(",", ", ");
					lines[lineCount] = lines[lineCount] = String::Concat(lines[lineCount], "}");
				}
				tbPotential->Lines = lines;
			}
			break;

		case 7:
			if (gPotential != "") {
				lines2[0] = "SpatialLagRegression";
				lineCount = 1;
				int change = 0;

				for (int i = 0; i < gPotential->Length; i++) {
					if (gPotential[i] != '#') {
						if (gPotential[i] != ';') {
							lines2[lineCount] += gPotential[i];
						}
						else {
							switch (change)
							{
							case 0:
								lines2[lineCount] += "$";
								change++;
								break;

							case 1:
								lines2[lineCount] += "@";
								change++;
								break;

							case 2:
								lines2[lineCount] += "%";
								change++;
								break;

							case 3:
								lines2[lineCount] += "&";
								change++;
								break;
							default:
								lines2[lineCount] += gPotential[i];
								break;
							}
						}
					}
					else {
						if (lines2[lineCount][0] == '0') {
							lines2[lineCount] = String::Concat("false", lines2[lineCount]->Substring(1));
						}
						else {
							lines2[lineCount] = String::Concat("true", lines2[lineCount]->Substring(1));
						}
						lines2[lineCount] = String::Concat("isLog = ", lines2[lineCount]);
						lines2[lineCount] = lines2[lineCount]->Replace("$", ",const=");
						lines2[lineCount] = lines2[lineCount]->Replace("@", ",minReg=");
						lines2[lineCount] = lines2[lineCount]->Replace("%", ",maxReg=");
						lines2[lineCount] = lines2[lineCount]->Replace("&", ",ro=");
						lines2[lineCount] = lines2[lineCount]->Replace(";", ",betas={");
						lines2[lineCount] = lines2[lineCount]->Replace("=", " = ");
						lines2[lineCount] = lines2[lineCount]->Replace(",", ", ");
						lines2[lineCount] = lines2[lineCount] = String::Concat(lines2[lineCount], "}");
						lineCount++;
						change = 0;
					}
				}
				if (lines2[lineCount] != "") {
					if (lines2[lineCount][0] == '0') {
						lines2[lineCount] = String::Concat("false", lines2[lineCount]->Substring(1));
					}
					else {
						lines2[lineCount] = String::Concat("true", lines2[lineCount]->Substring(1));
					}
					lines2[lineCount] = String::Concat("isLog = ", lines2[lineCount]);
					lines2[lineCount] = lines2[lineCount]->Replace("$", ",const=");
					lines2[lineCount] = lines2[lineCount]->Replace("@", ",minReg=");
					lines2[lineCount] = lines2[lineCount]->Replace("%", ",maxReg=");
					lines2[lineCount] = lines2[lineCount]->Replace("&", ",ro=");
					lines2[lineCount] = lines2[lineCount]->Replace(";", ",betas={");
					lines2[lineCount] = lines2[lineCount]->Replace("=", " = ");
					lines2[lineCount] = lines2[lineCount]->Replace(",", ", ");
					lines2[lineCount] = lines2[lineCount] = String::Concat(lines2[lineCount], "}");
				}
				tbPotential->Lines = lines2;
			}
			break;

		case 8:
			if (gPotential != "") {
				lines3[0] = "SpatialLagLinearRoads";
				lineCount = 1;
				int change = 0;

				for (int i = 0; i < gPotential->Length; i++) {
					if (gPotential[i] != '#') {
						if (gPotential[i] != ';') {
							lines3[lineCount] += gPotential[i];
						}
						else {
							switch (change)
							{
							case 0:
								lines3[lineCount] += "$";
								change++;
								break;

							case 1:
								lines3[lineCount] += "@";
								change++;
								break;

							case 2:
								lines3[lineCount] += "%";
								change++;
								break;

							case 3:
								lines3[lineCount] += "&";
								change++;
								break;

							case 4:
								lines3[lineCount] += "!";
								change++;
								break;

							case 5:
								lines3[lineCount] += "£";
								change++;
								break;

							case 6:
								lines3[lineCount] += "¢";
								change++;
								break;

							default:
								lines3[lineCount] += gPotential[i];
								break;
							}
						}

					}
					else {
						if (lines3[lineCount][0] == '0') {
							lines3[lineCount] = String::Concat("false", lines3[lineCount]->Substring(1));
						}
						else {
							lines3[lineCount] = String::Concat("true", lines3[lineCount]->Substring(1));
						}
						lines3[lineCount] = String::Concat("isLog = ", lines3[lineCount]);
						lines3[lineCount] = lines3[lineCount]->Replace("$", ",const=");
						lines3[lineCount] = lines3[lineCount]->Replace("@", ",minReg=");
						lines3[lineCount] = lines3[lineCount]->Replace("%", ",maxReg=");
						lines3[lineCount] = lines3[lineCount]->Replace("&", ",ro=");
						lines3[lineCount] = lines3[lineCount]->Replace("!", ",betas = {");
						lines3[lineCount] = lines3[lineCount]->Replace("*", "},roadsModel={ attrs={");;
						lines3[lineCount] = lines3[lineCount]->Replace("£", "},const=");
						lines3[lineCount] = lines3[lineCount]->Replace("¢", ",change=");
						lines3[lineCount] = lines3[lineCount]->Replace(";", ",betas={");
						lines3[lineCount] = lines3[lineCount]->Replace("=", " = ");
						lines3[lineCount] = lines3[lineCount]->Replace(",", ", ");
						lines3[lineCount] = lines3[lineCount] = String::Concat(lines3[lineCount], "}}");
						lineCount++;
						change = 0;
					}
				}
				if (lines3[lineCount] != "") {
					if (lines3[lineCount][0] == '0') {
						lines3[lineCount] = String::Concat("false", lines3[lineCount]->Substring(1));
					}
					else {
						lines3[lineCount] = String::Concat("true", lines3[lineCount]->Substring(1));
					}
					lines3[lineCount] = String::Concat("isLog = ", lines3[lineCount]);
					lines3[lineCount] = lines3[lineCount]->Replace("$", ",const=");
					lines3[lineCount] = lines3[lineCount]->Replace("@", ",minReg=");
					lines3[lineCount] = lines3[lineCount]->Replace("%", ",maxReg=");
					lines3[lineCount] = lines3[lineCount]->Replace("&", ",ro=");
					lines3[lineCount] = lines3[lineCount]->Replace("!", ",betas = {");
					lines3[lineCount] = lines3[lineCount]->Replace("*", "},roadsModel={ attrs={");;
					lines3[lineCount] = lines3[lineCount]->Replace("£", "},const=");
					lines3[lineCount] = lines3[lineCount]->Replace("¢", ",change=");
					lines3[lineCount] = lines3[lineCount]->Replace(";", ",betas={");
					lines3[lineCount] = lines3[lineCount]->Replace("=", " = ");
					lines3[lineCount] = lines3[lineCount]->Replace(",", ", ");
					lines3[lineCount] = lines3[lineCount] = String::Concat(lines3[lineCount], "}}");
				}
				tbPotential->Lines = lines3;
			}
			break;
		}
	}
	checkLanguage();
}

System::Void LuccME::NovoModelo::bAllocDiscrete_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;

	if (gPotentialComponent > 5) {
		if (MessageBox::Show(gSPotCont, gSAllocDiscTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
	}

	if (gLandUseTypes == "") {
		MessageBox::Show(gSLUTNotDef, gSLUTNotDefTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = false;
	}

	if (check) {
		cReturnAllocation^ lAllocation = gcnew cReturnAllocation();
		lAllocation->Return = gAllocation;
		lAllocation->LUT = gLandUseTypes;
		lAllocation->Component = gAllocationComponent;
		lAllocation->Language = lLanguage;

		AllocDiscreteForm^ allocationForm = gcnew AllocDiscreteForm(lAllocation);
		allocationForm->ShowDialog();

		gAllocation = lAllocation->Return;
		gAllocationLUT = gLandUseTypes;
		gAllocationComponent = lAllocation->Component;

		int count = 1;
		for (int i = 0; i < gAllocationLUT->Length; i++) {
			if (gAllocationLUT[i] == ',') {
				count++;
			}
		}

		array<String^>^ lines = gcnew array<String^>(2);
		array<String^>^ lines2 = gcnew array<String^>(count + 5);

		switch (lAllocation->Component)
		{
		case 1:
			if (gAllocation != "") {
				lines[0] = "AllocationBySimpleOrdering";
				lines[1] = "maxDifference = " + lAllocation->Return;
				tbAllocation->Lines = lines;
			}
			break;

		case 2:
			if (gAllocation != "") {
				lines2[0] = "AllocationClueSLike";
				int lineCount = 1;
				int change = 0;
				int j = 0;

				lines2[lineCount] = "maxIteration = ";
				while (gAllocation[j] != ';') {
					lines2[lineCount] += gAllocation[j];
					j++;
				}
				lineCount++;
				j++;

				lines2[lineCount] = "factorIteration = ";
				while (gAllocation[j] != ';') {
					lines2[lineCount] += gAllocation[j];
					j++;
				}
				lineCount++;
				j++;

				lines2[lineCount] = "maxDifference = ";
				while (gAllocation[j] != ';') {
					lines2[lineCount] += gAllocation[j];
					j++;
				}
				lineCount++;
				j++;

				lines2[lineCount] = "transitionMatrix";
				lineCount++;
				for (int i = j; i < gAllocation->Length; i++) {
					if (gAllocation[i] != ';') {
						if (gAllocation[i] != ',') {
							lines2[lineCount] += gAllocation[i];
						}
						else {
							lines2[lineCount] += ", ";
						}
					}
					else {
						lineCount++;
					}
				}

				tbAllocation->Lines = lines2;
			}
			break;
		}
	}
	checkLanguage();
}

System::Void LuccME::NovoModelo::bAllocContinuous_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;

	if (gPotentialComponent != 0 && gPotentialComponent < 6) {
		if (MessageBox::Show(gSPotDisc, gSAllocContTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
	}

	if (gLandUseTypes == "") {
		MessageBox::Show(gSLUTNotDef, gSLUTNotDefTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = false;
	}

	if (check) {
		cReturnAllocation^ lAllocation = gcnew cReturnAllocation();
		lAllocation->Return = gAllocation;
		lAllocation->LUT = gLandUseTypes;
		lAllocation->Component = gAllocationComponent;
		lAllocation->Language = lLanguage;

		AllocContinuousForm^ allocationForm = gcnew AllocContinuousForm(lAllocation);
		allocationForm->ShowDialog();

		gAllocation = lAllocation->Return;
		gAllocationLUT = gLandUseTypes;
		gAllocationComponent = lAllocation->Component;

		if (gAllocation != "") {
			int j = 0;

			String^ maxDifference = "";
			while (gAllocation[j] != ';') {
				maxDifference += gAllocation[j];
				j++;
			}
			j++;

			String^ maxIteration = "";
			while (gAllocation[j] != ';') {
				maxIteration += gAllocation[j];
				j++;
			}
			j++;

			String^ initialElasticity = "";
			while (gAllocation[j] != ';') {
				initialElasticity += gAllocation[j];
				j++;
			}
			j++;

			String^ minElasticity = "";
			while (gAllocation[j] != ';') {
				minElasticity += gAllocation[j];
				j++;
			}
			j++;

			String^ maxElasticity = "";
			while (gAllocation[j] != ';') {
				maxElasticity += gAllocation[j];
				j++;
			}
			j++;

			String^ complementarLU = "";
			while (gAllocation[j] != ';') {
				complementarLU += gAllocation[j];
				j++;
			}
			j++;

			String^ saturationIndicator = "";
			String^ attrProtection = "";
			if (gAllocationComponent == 4) {
				while (gAllocation[j] != ';') {
					saturationIndicator += gAllocation[j];
					j++;
				}
				j++;

				while (gAllocation[j] != ';') {
					attrProtection += gAllocation[j];
					j++;
				}
				j++;
			}

			int count = 1;
			for (int i = 0; i < gAllocationLUT->Length; i++) {
				if (gAllocationLUT[i] == ',') {
					count++;
				}
			}

			array<String^>^ lines = gcnew array<String^>(count + 10);

			if (gAllocationComponent == 3)
			{
				lines[0] = "AllocationClueLike";
				lines[7] = "allocationData";
				count = 8;
			}
			else {
				lines[0] = "AllocationClueLikeSaturation";
				lines[7] = "saturationIndicator = " + saturationIndicator;
				lines[8] = "attrProtection = " + attrProtection;
				lines[9] = "allocationData";
				count = 10;
			}
			lines[1] = "maxDifference = " + maxDifference;
			lines[2] = "maxIteration = " + maxIteration;
			lines[3] = "initialElasticity = " + initialElasticity;
			lines[4] = "minElasticity = " + minElasticity;
			lines[5] = "maxElasticity = " + maxElasticity;
			lines[6] = "complementarLU = " + complementarLU;

			int change = 0;
			for (int i = j; i < gAllocation->Length; i++) {
				if (gAllocation[i] != ';') {
					if (gAllocation[i] != ',') {
						lines[count] += gAllocation[i];
					}
					else {
						switch (change)
						{
						case 0:
							lines[count] += "$";
							change++;
							break;

						case 1:
							lines[count] += "@";
							change++;
							break;

						case 2:
							lines[count] += "%";
							change++;
							break;

						case 3:
							lines[count] += "&";
							change++;
							break;

						case 4:
							lines[count] += "!";
							change++;
							break;

						case 5:
							lines[count] += "£";
							change++;
							break;

						case 6:
							lines[count] += "¢";
							change++;
							break;

						default:
							lines[count] += gAllocation[i];
							break;
						}
					}
				}
				else {
					lines[count] = String::Concat("static=", lines[count]);
					lines[count] = lines[count]->Replace("$", ",minValue=");
					lines[count] = lines[count]->Replace("@", ",maxValue=");
					lines[count] = lines[count]->Replace("%", ",minChange=");
					lines[count] = lines[count]->Replace("&", ",maxChange=");
					lines[count] = lines[count]->Replace("!", ",changeLimiarValue=");
					lines[count] = lines[count]->Replace("£", ",maxChangeAboveLimiar=");
					lines[count] = lines[count]->Replace(",", ", ");
					lines[count] = lines[count]->Replace("=", " = ");
					count++;
					change = 0;
				}
			}
			if (lines[count] != "") {
				lines[count] = String::Concat("static=", lines[count]);
				lines[count] = lines[count]->Replace("$", ",minValue=");
				lines[count] = lines[count]->Replace("@", ",maxValue=");
				lines[count] = lines[count]->Replace("%", ",minChange=");
				lines[count] = lines[count]->Replace("&", ",maxChange=");
				lines[count] = lines[count]->Replace("!", ",changeLimiarValue=");
				lines[count] = lines[count]->Replace("£", ",maxChangeAboveLimiar=");
				lines[count] = lines[count]->Replace(",", ", ");
				lines[count] = lines[count]->Replace("=", " = ");
			}
			tbAllocation->Lines = lines;
		}
	}
	checkLanguage();
}

System::Void LuccME::NovoModelo::cSaveYearly_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (cSaveYearly->Checked == false) {
		lvYearsToSave->Clear();

		int time = Convert::ToInt16(tEndTime->Text) - Convert::ToInt16(tStartTime->Text);
		int tempTime = Convert::ToInt16(tStartTime->Text);
		
		lvYearsToSave->View = View::Details;
		lvYearsToSave->GridLines = true;
		lvYearsToSave->Columns->Add(gSAnos, lvYearsToSave->Width - 22, HorizontalAlignment::Center);
		
		for (int i = 0; i <= time; i++) {
			lvYearsToSave->Items->Add(Convert::ToString(tempTime + i));
		}

		lSelectYears->Visible = true;
		lvYearsToSave->Visible = true;
		bSelectedYears->Visible = true;
	}
	else {
		lvYearsToSave->Clear();
		lYearsToSave->Text = "";
		lSelectYears->Visible = false;
		lvYearsToSave->Visible = false;
		bSelectedYears->Visible = false;
	}
}

System::Void LuccME::NovoModelo::bSelectedYears_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	lYearsToSave->Text = "";
	for (int i = 0; i < lvYearsToSave->Items->Count; i++) {
		if (lvYearsToSave->Items[i]->Selected) {
			lYearsToSave->Text += lvYearsToSave->Items[i]->Text + ", ";
		}
	}
	if (lYearsToSave->Text != "") {
		lYearsToSave->Text = lYearsToSave->Text->Substring(0, lYearsToSave->Text->Length - 2);
	}
	gAttrTime = Convert::ToInt16(tEndTime->Text) - Convert::ToInt16(tStartTime->Text);
}

System::Void LuccME::NovoModelo::tNovoModelo_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (tNovoModelo->SelectedIndex == 4) {
		if (gAttrLUT != gLandUseTypes) {
			lAttrToSave->Text = "";
		}

		int time = Convert::ToInt16(tEndTime->Text) - Convert::ToInt16(tStartTime->Text);
		int tempTime = Convert::ToInt16(tStartTime->Text);

		lvYearsToSave->Clear();
		lvYearsToSave->View = View::Details;
		lvYearsToSave->GridLines = true;
		lvYearsToSave->Columns->Add(gSAnos, lvYearsToSave->Width - 22, HorizontalAlignment::Center);

		for (int i = 0; i <= time; i++) {
			lvYearsToSave->Items->Add(Convert::ToString(tempTime + i));
		}

		if (gAttrTime != time) {
			lYearsToSave->Text = "";
		}

		if (lLUTShow->Text != "") {
			lvSaveAttr->Clear();
			lvSaveAttr->View = View::Details;
			lvSaveAttr->GridLines = true;
			lvSaveAttr->Columns->Add(gSLUT, lvSaveAttr->Width - 5, HorizontalAlignment::Center);

			String^ temp = "";
			for (int i = 0; i < lLUTShow->Text->Length; i++) {
				if (lLUTShow->Text[i] != ',') {
					if (lLUTShow->Text[i] != '\"') {
						temp += lLUTShow->Text[i];
					}
				}
				else {
					lvSaveAttr->Items->Add(temp);
					temp = "";
				}
			}
			if (temp != "") {
				lvSaveAttr->Items->Add(temp);
			}
			bSelectedAttr->Visible = true;
		}
		else {
			bSelectedAttr->Visible = false;
		}
	}

	if (tNovoModelo->SelectedIndex == 6) {
		int time = Convert::ToInt16(tEndTime->Text) - Convert::ToInt16(tStartTime->Text);
		int tempTime = Convert::ToInt16(tStartTime->Text);

		if (gDynTime != time) {
			lDynamicConfirm->Text = "";
		}
		
		lvYearsDynamic->Clear();
		lvYearsDynamic->View = View::Details;
		lvYearsDynamic->GridLines = true;
		lvYearsDynamic->Columns->Add(gSAnos, lvYearsDynamic->Width - 22, HorizontalAlignment::Center);

		for (int i = 0; i <= time; i++) {
			lvYearsDynamic->Items->Add(Convert::ToString(tempTime + i));
		}
	}
	
	if (tNovoModelo->SelectedIndex == 7) {
		if (runnable == true) {
			lInputThemeName->Visible = true;
			tInputThemeName->Visible = true;
			lAttributeForValidation->Visible = true;
			tAttributeForValidation->Visible = true;
			lAttributeFinalValidation->Visible = true;
			tAttributeFinalValidation->Visible = true;
			lAttributeInitValidation->Visible = true;
			tAttributeInitValidation->Visible = true;
			bValidate->Visible = true;
		}
	}
}

System::Void LuccME::NovoModelo::bSelectedAttr_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	lAttrToSave->Text = "";
	for (int i = 0; i < lvSaveAttr->Items->Count; i++) {
		if (lvSaveAttr->Items[i]->Selected) {
			lAttrToSave->Text += lvSaveAttr->Items[i]->Text + ", ";
		}
	}
	if (lAttrToSave->Text != "") {
		lAttrToSave->Text = lAttrToSave->Text->Substring(0, lAttrToSave->Text->Length - 2);
	}
	gAttrLUT = gLandUseTypes;
}

System::Void LuccME::NovoModelo::bGerarArquivos_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool checked = true;

	if (lSelectedFolder->Text == "") {
		MessageBox::Show(gSFolder, gSFolderTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tModelName->Text == "") {
		MessageBox::Show(gSModelName, gSModelNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tStartTime->Text == "") {
		MessageBox::Show(gSStartTime, gSStartTimeTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tEndTime->Text == "") {
		MessageBox::Show(gSEndTime, gSEndTimeTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tbSelectedBatabase->Text == "") {
		MessageBox::Show(gSDBSave, gSDBSaveTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tThemeName->Text == "") {
		MessageBox::Show(gSThemeName, gSThemeNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tCellArea->Text == "") {
		MessageBox::Show(gSCellArea, gSCellAreaTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (lLUTShow->Text == "") {
		MessageBox::Show(gSLUTShow, gSLUTShowTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (lLUNDShow->Text == "") {
		MessageBox::Show(gSLUTNDShow, gSLUTNDShowTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (gDemandComponent == 0) {
		MessageBox::Show(gSDemandnS, gSDemandnSTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (gPotentialComponent == 0) {
		MessageBox::Show(gSPotentialnS, gSPotentialnSTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (gAllocationComponent == 0) {
		MessageBox::Show(gSAllocationnS, gSAllocationnSTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tOutputTheme->Text == "") {
		MessageBox::Show(gSOutputTheme, gSOutputThemeTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (lYearsToSave->Text == "" && cSaveYearly->Checked == false) {
		MessageBox::Show(gSYearSave, gSYearSaveTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (gPotentialComponent > 5 && (gAllocationComponent > 0 && gAllocationComponent < 3)) {
		MessageBox::Show(gSPotContAlocDisc, gSPotContAlocDiscTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if ((gPotentialComponent > 0 && gPotentialComponent < 6) && gAllocationComponent > 2) {
		MessageBox::Show(gSPotDiscAlocCont, gSPotContAlocDiscTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (cDynamicVariables->Checked == true) {
		if (lDynamicConfirm->Text == "") {
			MessageBox::Show(gSCheckDyn, gSCheckDynTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}
	}

	else if (cScenario->Checked == true) {
		if (cDynamicVariables->Checked == false) {
			MessageBox::Show(gSCheckDyn, gSCheckDynTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}
		else if (tScenarioName->Text == "") {
			MessageBox::Show(gSScenName, gSScenNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}
		else if (tScenariosStartTime->Text == "") {
			MessageBox::Show(gSScenST, gSScenSTTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}
	}

	if (checked) {
		bool mainFile = false;
		bool subFile = false;

		DateTime now = DateTime::Now;
		String^ dateTime = now.ToString("d") + " at " + now.ToString("T");

		//Creating main File
		String^ path = lSelectedFolder->Text->Replace("\\", "\\\\") + "\\" + tModelName->Text->ToLower() + "_main.lua";
		path = path->Replace("\\\\\\\\", "\\\\");


		StreamWriter^ sw = nullptr;

		try {
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
				sw->WriteLine("-- This file contains a LUCCME APPLICATION MODEL definition --");
				sw->WriteLine("--               Compatible with LuccME 2.1                 --");
				sw->WriteLine("--        Generated with LuccMe Model Configurator          --");
				sw->WriteLine("--               " + dateTime + "                     --");
				sw->WriteLine("--------------------------------------------------------------\n");

				sw->WriteLine("require (\"luccme\")\n");
				String^ folderAux = lSelectedFolder->Text->Replace("\\", "\\\\");
				if (folderAux->Length > 4) {
					sw->WriteLine("dofile (\"" + folderAux + "\\\\" + tModelName->Text->ToLower() + "_submodel.lua\")\n");
				}
				else {
					sw->WriteLine("dofile (\"" + folderAux + tModelName->Text->ToLower() + "_submodel.lua\")\n");
				}
				sw->WriteLine();

				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("--             LuccME APPLICATION MODEL DEFINITION          --");
				sw->WriteLine("--------------------------------------------------------------");

				sw->WriteLine(tModelName->Text + " = LuccMEModel");
				sw->WriteLine("{");
				sw->WriteLine("\tname = \"" + tModelName->Text + "\",\n");

				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\t-- Temporal dimension definition                   --");
				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\tstartTime = " + tStartTime->Text + ",");
				sw->WriteLine("\tendTime = " + tEndTime->Text + ",\n");

				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\t-- Spatial dimension definition                    --");
				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\tcs = CellularSpace");
				sw->WriteLine("\t{");
				if (tbSelectedBatabase->Lines->Length > 0) {
					if (tbSelectedBatabase->Lines[0]->ToString() == gSAccess) {
						sw->WriteLine("\t\tdatabase = \"" + tbSelectedBatabase->Lines[1]->ToString()->Replace("\\", "\\\\") + "\",");
					}
					else {
						sw->WriteLine("\t\t" + tbSelectedBatabase->Lines[1]->ToString() + ",");
						sw->WriteLine("\t\t" + tbSelectedBatabase->Lines[2]->ToString() + ",");
						sw->WriteLine("\t\t" + tbSelectedBatabase->Lines[3]->ToString() + ",");
						sw->WriteLine("\t\t" + tbSelectedBatabase->Lines[4]->ToString() + ",\n");
					}
				}
				sw->WriteLine("\t\ttheme = \"" + tThemeName->Text + "\",");
				sw->WriteLine("\t\tcellArea = " + tCellArea->Text + ",");
				sw->WriteLine("\t},");

				if (cDynamicVariables->Checked == true) {
					sw->WriteLine();
					sw->WriteLine("\t-----------------------------------------------------");
					sw->WriteLine("\t-- Dynamic variables definition                    --");
					sw->WriteLine("\t-----------------------------------------------------");
					sw->WriteLine("\tupdateYears = {" + lDynamicConfirm->Text + "},");

					if (cScenario->Checked == true) {
						sw->WriteLine("\tscenarioStartTime = " + tScenariosStartTime->Text + ",");
						sw->WriteLine("\tscenarioName = \"" + tScenarioName->Text + "\",");
					}
				}

				sw->WriteLine();
				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\t-- Land use variables definition                   --");
				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\tlandUseTypes =");
				sw->WriteLine("\t{");
				sw->WriteLine("\t\t" + lLUTShow->Text->Replace(",", ", "));
				sw->WriteLine("\t},\n");
				sw->WriteLine("\tlandUseNoData	= " + lLUNDShow->Text->Replace(",", ", ") + ",\n");

				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\t-- Behaviour dimension definition:                 --");
				sw->WriteLine("\t-- DEMAND, POTENTIAL AND ALLOCATION COMPONENTS     --");
				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\tdemand = D1,");
				sw->WriteLine("\tpotential = P1,");
				sw->WriteLine("\tallocation = A1,\n");

				sw->WriteLine("\tsave  =");
				sw->WriteLine("\t{");
				sw->WriteLine("\t\toutputTheme = \"" + tOutputTheme->Text + "_\",");
				if (cSaveYearly->Checked) {
					sw->WriteLine("\t\tyearly = true,");

				}
				else {
					sw->WriteLine("\t\tsaveYears = {" + lYearsToSave->Text + "},");
				}

				sw->WriteLine("\t\tmode = \"multiple\",");
				sw->WriteLine("\t\tsaveAttrs = ");
				sw->WriteLine("\t\t{");
				String^ aux = "";
				for (int i = 0; i < lAttrToSave->Text->Length; i++) {
					if (lAttrToSave->Text[i] != ',') {
						aux += lAttrToSave->Text[i];
					}
					else {
						if (aux[0] == ' ') {
							aux = aux->Remove(0, 1);
						}
						sw->WriteLine("\t\t\t\"" + aux + "_out\",");
						sw->WriteLine("\t\t\t\"" + aux + "_change\",");
						sw->WriteLine("\t\t\t\"" + aux + "_pot\",");
						aux = "";
					}
				}
				if (aux != "") {
					if (aux[0] == ' ') {
						aux = aux->Remove(0, 1);
					}
					sw->WriteLine("\t\t\t\"" + aux + "_out\",");
					sw->WriteLine("\t\t\t\"" + aux + "_change\",");
					sw->WriteLine("\t\t\t\"" + aux + "_pot\",");
				}
				sw->WriteLine("\t\t},\n");
				sw->WriteLine("\t},\n");

				if (cIsCoupled->Checked) {
					sw->WriteLine("\tisCoupled = true");
				}
				else {
					sw->WriteLine("\tisCoupled = false");
				}
				sw->WriteLine("}  -- END LuccME application model definition\n");

				sw->WriteLine("-----------------------------------------------------");
				sw->WriteLine("-- ENVIROMMENT DEFINITION                          --");
				sw->WriteLine("-----------------------------------------------------");
				sw->WriteLine("timer = Timer");
				sw->WriteLine("{");
				sw->WriteLine("\tEvent");
				sw->WriteLine("\t{");
				sw->WriteLine("\t\ttime = " + tModelName->Text + ".startTime,");
				sw->WriteLine("\t\tperiod = 1,");
				sw->WriteLine("\t\tpriority = 1,");
				sw->WriteLine("\t\taction = function(event)");
				sw->WriteLine("\t\t\t\t\t\t" + tModelName->Text + ":execute(event)");
				sw->WriteLine("\t\t\t\t  end");
				sw->WriteLine("\t}");
				sw->WriteLine("}\n");

				sw->WriteLine("env_" + tModelName->Text + " = Environment{}");
				sw->WriteLine("env_" + tModelName->Text + ":add(timer)\n");

				sw->WriteLine("-----------------------------------------------------");
				sw->WriteLine("-- ENVIROMMENT EXECUTION                           --");
				sw->WriteLine("-----------------------------------------------------");
				sw->WriteLine("if " + tModelName->Text + ".isCoupled == false then");
				sw->WriteLine("\ttsave = databaseSave(" + tModelName->Text + ")");
				sw->WriteLine("\tenv_" + tModelName->Text + ":add(tsave)");
				sw->WriteLine("\tenv_" + tModelName->Text + ":execute(" + tModelName->Text + ".endTime)");
				sw->WriteLine("\tsaveSingleTheme (" + tModelName->Text + ", true)");
				sw->WriteLine("end");

				sw->Close();

				if (File::Exists(path))
				{
					mainFile = true;
				}

				//Creating Submodel File
				path = lSelectedFolder->Text->Replace("\\", "\\\\") + "\\" + tModelName->Text->ToLower() + "_submodel.lua";
				path = path->Replace("\\\\\\\\", "\\\\");

				if (File::Exists(path))
				{
					File::Delete(path);
				}

				sw = File::CreateText(path);

				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("--       This file contains the COMPONENTS definition       --");
				sw->WriteLine("--               Compatible with LuccME 2.1                 --");
				sw->WriteLine("--        Generated with LuccMe Model Configurator          --");
				sw->WriteLine("--               " + dateTime + "                     --");
				sw->WriteLine("--------------------------------------------------------------\n");

				if (tbDemand->Lines->Length > 0) {
					sw->WriteLine("-----------------------------------------------------");
					sw->WriteLine("-- Demand                                          --");
					sw->WriteLine("-----------------------------------------------------");

					int tempYear = 0;
					switch (gDemandComponent)
					{
					case 1:
						sw->WriteLine("D1 = " + tbDemand->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\tannualDemand =");
						sw->WriteLine("\t{");
						sw->WriteLine("\t\t-- " + tbDemand->Lines[1]->ToString()->Replace(",", ", "));
						tempYear = Convert::ToInt16(tStartTime->Text);
						for (int i = 2; i < tbDemand->Lines->Length; i++) {
							if (i == 2) {
								sw->WriteLine("\t\t" + tbDemand->Lines[i]->ToString()->Replace(",", ", ") + "\t-- " + Convert::ToString(tempYear + i - 2));
							}
							else {
								sw->WriteLine("\t\t" + tbDemand->Lines[i]->ToString()->Replace(",", ", ") + "\t-- " + Convert::ToString(tempYear + i - 2));
							}
						}
						sw->WriteLine("\t}");
						sw->WriteLine("}\n");
						break;

					case 2:
						sw->WriteLine("D1 = " + tbDemand->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\t" + tbDemand->Lines[1]->ToString()->Replace(",", ", ") + ",");
						sw->WriteLine("\tfinalLandUseTypesForInterpolation = {" + tbDemand->Lines[3]->ToString()->Replace(",", ", ") + "},");
						sw->WriteLine("}\n");
						break;

					case 3:
						sw->WriteLine("D1 = " + tbDemand->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\t" + tbDemand->Lines[1]->ToString()->Replace(",", ", ") + ",");
						sw->WriteLine("\tmiddleLandUseTypesForInterpolation = {" + tbDemand->Lines[4]->ToString()->Replace(",", ", ") + "},");
						sw->WriteLine("\t" + tbDemand->Lines[2]->ToString()->Replace(",", ", ") + ",");
						sw->WriteLine("\tfinalLandUseTypesForInterpolation = {" + tbDemand->Lines[5]->ToString()->Replace(",", ", ") + "},");
						sw->WriteLine("}\n");
						break;

					default:
						break;
					}
				}

				if (tbPotential->Lines->Length > 0) {
					sw->WriteLine("-----------------------------------------------------");
					sw->WriteLine("-- Potential                                       --");
					sw->WriteLine("-----------------------------------------------------");

					array<String^>^ tempLUTs = gcnew array<String^>(50);
					int row = 0;
					String^ aux = "";
					String^ tempBetas = "";
					for (int i = 0; i < gLandUseTypes->Length; i++) {
						if (gLandUseTypes[i] != ',') {
							if (gLandUseTypes[i] != '\"') {
								aux += gLandUseTypes[i];
							}
						}
						else {
							tempLUTs[row] = aux;
							aux = "";
							row++;
						}
					}
					if (aux != "") {
						tempLUTs[row] = aux;
					}

					switch (gPotentialComponent)
					{
					case 1:
						sw->WriteLine("P1 = " + tbPotential->Lines[0] + "\n");
						break;

					case 2:

					case 3:

					case 4:

					case 5:

					case 6:

					case 7:
						sw->WriteLine("P1 = " + tbPotential->Lines[0]);
						sw->WriteLine("{");
						if (gPotentialComponent < 4) {
							sw->WriteLine("\tpotentialData =");
						}
						else {
							sw->WriteLine("\tregressionData =");
						}
						sw->WriteLine("\t{");
						sw->WriteLine("\t\t--Region 1");
						sw->WriteLine("\t\t{");

						for (int i = 1; i < tbPotential->Lines->Length; i++) {
							if (tbPotential->Lines[i]->ToString() != "") {
								//sw->WriteLine("\t\t\t{ " + tbPotential->Lines[i] + " },\t\t-- " + tempLUTs[i - 1]);
								sw->WriteLine("\t\t\t-- " + tempLUTs[i - 1]);
								sw->WriteLine("\t\t\t{");
								aux = tbPotential->Lines[i]->ToString()->Replace("betas", "$betas");
								int j = 0;
								while (aux[j] != '$') {
									if (aux[j] != ',') {
										if (aux[j] != ' ') {
											tempBetas += aux[j];
										}
									}
									else {
										sw->WriteLine("\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
										tempBetas = "";
									}
									j++;
								}
								j++;
								sw->WriteLine("\n\t\t\t\t" + aux->Substring(j, 7)); //Betas
								sw->WriteLine("\t\t\t\t{");
								j += 9;
								for (int k = j; k < aux->Length; k++) {
									if (aux[k] != ',') {
										if (aux[k] != '}') {
											if (aux[k] != ' ') {
												tempBetas += aux[k];
											}
										}
										else {
											sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = "));
											sw->WriteLine("\t\t\t\t}");
											sw->WriteLine("\t\t\t},\n");
											tempBetas = "";
											break;
										}
									}
									else {
										sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
										tempBetas = "";
									}
								}
							}
						}

						sw->WriteLine("\t\t}");
						sw->WriteLine("\t}");
						sw->WriteLine("}\n");
						break;

					case 8:
						sw->WriteLine("P1 = " + tbPotential->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\tregressionData =");
						sw->WriteLine("\t{");
						sw->WriteLine("\t\t--Region 1");
						sw->WriteLine("\t\t{");

						for (int i = 1; i < tbPotential->Lines->Length; i++) {
							if (tbPotential->Lines[i]->ToString() != "") {
								sw->WriteLine("\t\t\t-- " + tempLUTs[i - 1]);
								sw->WriteLine("\t\t\t{");
								aux = tbPotential->Lines[i]->ToString()->Replace("betas", "$betas");
								aux = aux->Replace("roadsModel", "%roadsModel");
								int j = 0;
								while (aux[j] != '$') {
									if (aux[j] != ',') {
										if (aux[j] != ' ') {
											tempBetas += aux[j];
										}
									}
									else {
										sw->WriteLine("\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
										tempBetas = "";
									}
									j++;
								}
								j++;
								sw->WriteLine("\n\t\t\t\t" + aux->Substring(j, 9)); //Betas
								sw->WriteLine("\t\t\t\t{");
								j += 11;
								while (aux[j] != '%') {
									if (aux[j] != ',') {
										if (aux[j] != '}') {
											if (aux[j] != ' ') {
												tempBetas += aux[j];
											}
										}
										else {
											sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = "));
											sw->WriteLine("\t\t\t\t},");
											tempBetas = "";
											break;
										}
									}
									else {
										sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
										tempBetas = "";
									}
									j++;
								}
								j += 4;
								sw->WriteLine("\n\t\t\t\t" + aux->Substring(j, 13)); //roadsModel
								sw->WriteLine("\t\t\t\t{");
								j += 15;
								sw->WriteLine("\t\t\t\t\t" + aux->Substring(j, 8)); //attrs
								sw->WriteLine("\t\t\t\t\t{");
								j += 9;
								while (aux[j] != '}') {
									if (aux[j] != ',') {
										if (aux[j] != ' ') {
											tempBetas += aux[j];
										}
									}
									else {
										sw->WriteLine("\t\t\t\t\t\t" + tempBetas + ",");
										tempBetas = "";
									}
									j++;
								}
								if (tempBetas != "") {
									sw->WriteLine("\t\t\t\t\t\t" + tempBetas);
									tempBetas = "";
								}
								sw->WriteLine("\t\t\t\t\t},");
								j += 2;
								while (aux[j] != '$') {
									if (aux[j] != ',') {
										if (aux[j] != '}') {
											if (aux[j] != ' ') {
												tempBetas += aux[j];
											}
										}
										else {
											sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = "));
											sw->WriteLine("\t\t\t\t},");
											tempBetas = "";
											break;
										}
									}
									else {
										sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
										tempBetas = "";
									}
									j++;
								}
								j++;
								sw->WriteLine("\n\t\t\t\t\t" + aux->Substring(j, 7)); //Betas
								sw->WriteLine("\t\t\t\t\t{");
								j += 9;
								for (int k = j; k < aux->Length; k++) {
									if (aux[k] != ',') {
										if (aux[k] != '}') {
											if (aux[k] != ' ') {
												tempBetas += aux[k];
											}
										}
										else {
											sw->WriteLine("\t\t\t\t\t\t" + tempBetas->Replace("=", " = "));
											sw->WriteLine("\t\t\t\t\t}");
											sw->WriteLine("\t\t\t\t}");
											sw->WriteLine("\t\t\t},\n");
											tempBetas = "";
											break;
										}
									}
									else {
										sw->WriteLine("\t\t\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
										tempBetas = "";
									}
								}

							}
						}

						sw->WriteLine("\t\t}");
						sw->WriteLine("\t}");
						sw->WriteLine("}\n");
						break;

					default:
						break;
					}
				}

				if (tbAllocation->Lines->Length > 0) {
					sw->WriteLine("-----------------------------------------------------");
					sw->WriteLine("-- Allocation                                      --");
					sw->WriteLine("-----------------------------------------------------");

					array<String^>^ tempLUTs = gcnew array<String^>(50);
					int row = 0;
					String^ aux = "";
					String^ tempBetas = "";
					for (int i = 0; i < gLandUseTypes->Length; i++) {
						if (gLandUseTypes[i] != ',') {
							if (gLandUseTypes[i] != '\"') {
								aux += gLandUseTypes[i];
							}
						}
						else {
							tempLUTs[row] = aux;
							aux = "";
							row++;
						}
					}
					if (aux != "") {
						tempLUTs[row] = aux;
					}

					switch (gAllocationComponent)
					{
					case 1:
						sw->WriteLine("A1 = " + tbAllocation->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\t" + tbAllocation->Lines[1]);
						sw->WriteLine("}\n");
						break;

					case 2:
						sw->WriteLine("A1 = " + tbAllocation->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\t" + tbAllocation->Lines[1] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[2] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[3] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[4] + " =");
						sw->WriteLine("\t{");
						sw->WriteLine("\t\t--Region 1");
						sw->WriteLine("\t\t{");
						for (int i = 5; tbAllocation->Lines->Length - 1; i++) {
							if (i + 1 < tbAllocation->Lines->Length) {
								sw->WriteLine("\t\t\t{" + tbAllocation->Lines[i] + "},");
							}
							else {
								sw->WriteLine("\t\t\t{" + tbAllocation->Lines[i] + "}");
								break;
							}
						}
						sw->WriteLine("\t\t}");
						sw->WriteLine("\t}");
						sw->WriteLine("}\n");
						break;

					case 3:
						sw->WriteLine("A1 = " + tbAllocation->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\t" + tbAllocation->Lines[1] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[2] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[3] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[4] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[5] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[6]->ToString()->Replace("= ", "= \"") + "\",");
						sw->WriteLine("\t" + tbAllocation->Lines[7] + " =");
						sw->WriteLine("\t{");
						for (int i = 8; i < tbAllocation->Lines->Length - 1; i++) {
							if (tbAllocation->Lines[i] != "") {
								if (i + 1 < tbAllocation->Lines->Length) {
									sw->WriteLine("\t\t{" + tbAllocation->Lines[i] + "},\t-- " + tempLUTs[i - 8]);
								}
								else {
									sw->WriteLine("\t\t{" + tbAllocation->Lines[i] + "}\t-- " + tempLUTs[i - 8]);
									break;
								}
							}
						}
						sw->WriteLine("\t}");
						sw->WriteLine("}\n");
						break;

					case 4:
						sw->WriteLine("A1 = " + tbAllocation->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\t" + tbAllocation->Lines[1] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[2] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[3] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[4] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[5] + ",");
						sw->WriteLine("\t" + tbAllocation->Lines[6]->ToString()->Replace("= ", "= \"") + "\",");
						sw->WriteLine("\t" + tbAllocation->Lines[7]->ToString()->Replace("= ", "= \"") + "\",");
						sw->WriteLine("\t" + tbAllocation->Lines[8]->ToString()->Replace("= ", "= \"") + "\",");
						sw->WriteLine("\t" + tbAllocation->Lines[9] + " =");
						sw->WriteLine("\t{");
						for (int i = 10; i < tbAllocation->Lines->Length; i++) {
							if (tbAllocation->Lines[i] != "") {
								if (i + 1 < tbAllocation->Lines->Length) {
									sw->WriteLine("\t\t{" + tbAllocation->Lines[i] + "},\t-- " + tempLUTs[i - 10]);
								}
								else {
									sw->WriteLine("\t\t{" + tbAllocation->Lines[i] + "}\t-- " + tempLUTs[i - 10]);
									break;
								}
							}
						}
						sw->WriteLine("\t}");
						sw->WriteLine("}\n");
						break;
					default:
						break;
					}

				}
				sw->Close();

				if (File::Exists(path))
				{
					subFile = true;

				}

				if (mainFile && subFile) {
					if (lSelectedFolder->Text->Length > 4) {
						MessageBox::Show(gSSuccess + lSelectedFolder->Text + "\\" + tModelName->Text->ToLower() + "_main.lua" +
							"\n" + lSelectedFolder->Text + "\\" + tModelName->Text->ToLower() + "_submodel.lua", gSSuccessTitle,
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else {
						MessageBox::Show(gSSuccess + lSelectedFolder->Text + tModelName->Text->ToLower() + "_main.lua" +
							"\n" + lSelectedFolder->Text + tModelName->Text->ToLower() + "_submodel.lua", gSSuccessTitle,
							MessageBoxButtons::OK, MessageBoxIcon::Information);
					}

					lRunModel->Visible = true;
					bRun->Visible = true;
					runnable = true;
				}
				else {
					if (!mainFile) {
						MessageBox::Show("Erro na gravação do arquivo Principal.\nVerifique o caminho:" + lSelectedFolder->Text, "Erro na geração dos Arquivos",
							MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
					else {
						MessageBox::Show("Erro na gravação do arquivo Submodelos.\nVerifique o caminho:" + lSelectedFolder->Text, "Erro na geração dos Arquivos",
							MessageBoxButtons::OK, MessageBoxIcon::Error);
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
					System::Threading::Thread::Sleep(1000);
					if (File::Exists(path))
					{
						File::Delete(path);
					}

					forceWriting = true;
					bGerarArquivos_Click(sender, e);
				}
			}
			else if (!subFile) {
				if (forceWriting) {
					MessageBox::Show(gSSMFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					closing = true;
					this->Close();
				}
				else {
					System::Threading::Thread::Sleep(1000);
					if (File::Exists(path))
					{
						File::Delete(path);
					}

					forceWriting = true;
					bGerarArquivos_Click(sender, e);
				}
			}
			else {
				if (forceWriting) {
					MessageBox::Show(gSFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					closing = true;
					this->Close();
				}
				else {
					System::Threading::Thread::Sleep(1000);
					if (File::Exists(path))
					{
						File::Delete(path);
					}

					forceWriting = true;
					bGerarArquivos_Click(sender, e);
				}
			}
		}
	}
}

System::Void LuccME::NovoModelo::bRun_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	String^ arguments = "";
	if (lSelectedFolder->Text[lSelectedFolder->Text->Length - 1] != '\\') {
		arguments = "\"" + lSelectedFolder->Text->Replace("\\", "\\\\") + "\\\\" + tModelName->Text->ToLower() + "_main.lua\"";
	}
	else {
		arguments = "\"" + lSelectedFolder->Text->Replace("\\", "\\\\") + tModelName->Text->ToLower() + "_main.lua\"";
	}
	
	System::Diagnostics::Process^ cmd = gcnew System::Diagnostics::Process;
	cmd->StartInfo->FileName = "C:\\LuccME\\TerraME\\bin\\TerraME.exe";
	cmd->StartInfo->Arguments = arguments;
	cmd->Start();
	cmd->WaitForExit();
	cmd->Close();
}

System::Void LuccME::NovoModelo::NovoModelo_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	checkLanguage();
	NovoModelo::Update();
	if (lOpen) {
		try {
			bool main = false;
			bool submodel = false;
			bool imported = true;
			this->Text = gSEditing;

			MessageBox::Show(gSMainLoad, gSMainLoadTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);

			LuccME::OpenFileDialog^ mainFile = gcnew OpenFileDialog;
			mainFile->Title = gSMainFile;
			mainFile->Multiselect = false;
			mainFile->Filter = gSLuaFile;
			mainFile->FilterIndex = 1;

			if (mainFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ fileName = mainFile->FileName;
				System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(fileName);
				bool found = false;
			
				String^ line = sw->ReadLine();
			
				while (sw->EndOfStream == false) {
					if (line->Contains("dofile") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				String^ tempLine = "";
				int lastSlash = 0;
				int j = 0;
			
				if (found) {
					while (line[j] != '\"') {
						j++;
					}

					j++;
					line = line->Replace("\\\\", "\\");

					for (int i = j; i < line->Length; i++) {
						if (line[i] != '\\') {
							tempLine += line[i];
						}
						else {
							if (line[i] == '\\') {
								tempLine += line[i];
								lastSlash = i;
							}
						}
					}

					lSelectedFolder->Text = tempLine->Substring(0, lastSlash - j);
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);
			
				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("name") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					j = 0;
					while (line[j] != '\"') {
						j++;
					}

					j++;
					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != '\"') {
							tempLine += line[i];
						}
						else {
							break;
						}
					}

					tModelName->Text = tempLine;
					tModelName->ForeColor = System::Drawing::Color::Black;

					tempLine = "";
					lastSlash = 0;
					line = mainFile->FileName;

					for (int i = 0; i < line->Length; i++) {
						if (line[i] != '\\') {
							tempLine += line[i];
						}
						else {
							if (line[i] == '\\') {
								tempLine += line[i];
								lastSlash = i;
							}
						}
					}


					tempLine = tempLine->Substring(0, lastSlash);

					if (lSelectedFolder->Text != tempLine) {
						lSelectedFolder->Text = "";
						imported = false;
					}
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("startTime") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					j = 0;
					while (line[j] != '=') {
						j++;
					}

					j++;
					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != ',') {
							if (line[i] != ' ') {
								tempLine += line[i];
							}
						}
						else {
							break;
						}
					}

					tStartTime->Text = tempLine;
					tStartTime->ForeColor = System::Drawing::Color::Black;
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("endTime") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					j = 0;
					while (line[j] != '=') {
						j++;
					}

					j++;
					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != ',') {
							if (line[i] != ' ') {
								tempLine += line[i];
							}
						}
						else {
							break;
						}
					}

					tEndTime->Text = tempLine;
					tEndTime->ForeColor = System::Drawing::Color::Black;
				}

				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				if (found) {
					line = sw->ReadLine();
					while (line->Contains("endTime") != 1) {
						line = sw->ReadLine();
					}
				}

				found = false;
				String^ tempDB = "";

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("theme") != 1) {
						tempDB += line;
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempDB = tempDB->Replace("\n", "");
					tempDB = tempDB->Replace("\t", "");
					String^ dbAux = "";

					if (tempDB->Contains("host")) {
						j = 0;
						while (tempDB[j] != '{') {
							j++;
						}

						tempDB = tempDB->Substring(j + 1)->Replace(" ", "");

						array<String^>^ tempBd = gcnew array<String^>(5);
						tempBd[0] = gSMySQL;
						gSelectedDatabase = "";

						j = 0;
						while (tempDB[j] != '=') {
							j++;
						}

						tempDB = tempDB->Substring(j + 1);

						j = 0;
						dbAux = "";
						while (tempDB[j] != ',') {
							dbAux += tempDB[j];
							j++;
						}

						tempBd[1] = "host = " + dbAux;
						gSelectedDatabase += dbAux;

						j = 0;
						while (tempDB[j] != '=') {
							j++;
						}

						tempDB = tempDB->Substring(j + 1);

						j = 0;
						dbAux = "";
						while (tempDB[j] != ',') {
							dbAux += tempDB[j];
							j++;
						}

						tempBd[2] = "user = " + dbAux;
						gSelectedDatabase += "," + dbAux;

						j = 0;
						while (tempDB[j] != '=') {
							j++;
						}

						tempDB = tempDB->Substring(j + 1);

						j = 0;
						dbAux = "";
						while (tempDB[j] != ',') {
							dbAux += tempDB[j];
							j++;
						}

						tempBd[3] = "password = " + dbAux;
						gSelectedDatabase += "," + dbAux;

						j = 0;
						while (tempDB[j] != '=') {
							j++;
						}

						tempDB = tempDB->Substring(j + 1);

						j = 0;
						dbAux = "";
						while (tempDB[j] != ',') {
							dbAux += tempDB[j];
							j++;
						}

						tempBd[4] = "database = " + dbAux;
						gSelectedDatabase += "," + dbAux;

						tbSelectedBatabase->Lines = tempBd;
						access = false;
					}
					else {
						j = 0;
						while (tempDB[j] != '{') {
							j++;
						}

						tempDB = tempDB->Substring(j + 1);

						j = 0;
						while (tempDB[j] != '\"') {
							j++;
						}

						j++;
						dbAux = "";

						for (int i = j; i < tempDB->Length - 2; i++) {
							if (tempDB[j] != '\"') {
								dbAux += tempDB[i];
							}
							else {
								break;
							}
						}

						dbAux = dbAux->Replace("\\\\", "\\");

						{
							array<String^>^ tempBd = gcnew array<String^>(2);
							String^ path = dbAux;

							if (File::Exists(path))
							{
								tempBd[0] = gSAccess;
								tempBd[1] = dbAux;
								tbSelectedBatabase->Lines = tempBd;
								access = true;
							}
							else {
								imported = false;
							}
						}
					}

					j = 0;
					while (line[j] != '\"') {
						j++;
					}

					j++;
					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != '\"') {
							tempLine += line[i];
						}
						else {
							break;
						}
					}
					tThemeName->Text = tempLine;
					tThemeName->ForeColor = System::Drawing::Color::Black;
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("cellArea") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					j = 0;
					while (line[j] != '=') {
						j++;
					}

					j++;
					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != ',') {
							if (line[i] != ' ') {
								tempLine += line[i];
							}
						}
						else {
							break;
						}
					}
					tCellArea->Text = tempLine;
					tCellArea->ForeColor = System::Drawing::Color::Black;
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);
			
				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("updateYears") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempLine = "";
					j = 0;
					while (line[j] != '{') {
						j++;
					}
					j++;
					while (line[j] != '}') {
						tempLine += line[j];
						j++;
					}
					cDynamicVariables->Checked = true;
					lDynamicConfirm->Text = tempLine;
					gDynTime = Convert::ToInt16(tEndTime->Text) - Convert::ToInt16(tStartTime->Text);

				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("scenarioStartTime") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					j = 0;
					while (line[j] != '=') {
						j++;
					}

					j++;
					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != ',') {
							if (line[i] != ' ') {
								tempLine += line[i];
							}
						}
						else {
							break;
						}
					}
					cScenario->Checked = true;
					tScenariosStartTime->Text = tempLine;
					tScenariosStartTime->ForeColor = System::Drawing::Color::Black;
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("scenarioName") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					j = 0;
					while (line[j] != '\"') {
						j++;
					}

					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != ',') {
							tempLine += line[i];
						}
						else {
							break;
						}
					}

					tScenarioName->Text = tempLine->Replace("\"","");
					tScenarioName->ForeColor = System::Drawing::Color::Black;
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("landUseTypes") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				int k = 0;

				if (found) {
					tempLine = "";
					while (line->Contains("},") != 1) {
						tempLine += line;
						line = sw->ReadLine();
					}
					tempLine += line; //add },
					j = 0;
					while (tempLine[j] != '\"') {
						j++;
					}

					k = j;
					j++;

					while (tempLine[j] != '}') {
						j++;
					}

					tempLine = tempLine->Substring(k, j - k)->Replace(", ", ",");
					tempLine = tempLine->Replace("\t", " ");
					tempLine = tempLine->Replace("\" ", "\"");
					tempLine = tempLine->Replace(" \"", "\"");

					lLUTShow->Text = tempLine;
					gLandUseTypes = lLUTShow->Text;
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("landUseNoData") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					j = 0;
					while (line[j] != '\"') {
						j++;
					}

					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != ',') {
							tempLine += line[i];
						}
						else {
							break;
						}
					}

					lLUNDShow->Text = tempLine;
					gLandUseNoData = lLUNDShow->Text;
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("outputTheme") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					j = 0;
					while (line[j] != '\"') {
						j++;
					}

					j++;
					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != '_') {
							tempLine += line[i];
						}
						else {
							break;
						}
					}
					tOutputTheme->Text = tempLine;
					tOutputTheme->ForeColor = System::Drawing::Color::Black;
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();

				while (sw->EndOfStream == false) {
					if (line->Contains("yearly") != 1) {
						if (line->Contains("saveYears") == 1) {
							found = true;
							break;
						}
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					if (line->Contains("yearly") == 1) {
						cSaveYearly->Checked = true;
					}
					else {
						tempLine = "";
						j = 0;
						while (line[j] != '{') {
							j++;
						}
						j++;
						while (line[j] != '}') {
							tempLine += line[j];
							j++;
						}
						cSaveYearly->Checked = false;
						lYearsToSave->Text = tempLine;
						gAttrTime = Convert::ToInt16(tEndTime->Text) - Convert::ToInt16(tStartTime->Text);
					}
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("saveAttrs") != 1) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempLine = "";
					while (line->Contains("},") != 1) {
						tempLine += line;
						line = sw->ReadLine();
					}

					tempLine += line; //add },
					if (tempLine->Length > 25) {
						j = 0;
						while (tempLine[j] != '\"') {
							j++;
						}

						j++;
						k = j;
						while (tempLine[j] != ',') {
							j++;
						}

						String^ testeAux = tempLine->Substring(k, j - k);

						lAttrToSave->Text = "";
						lAttrToSave->Text += tempLine->Substring(k, j - k)->Replace("\"", "");
						tempLine = tempLine->Substring(j - 4);

						tempLine = tempLine->Replace("\t", " ");
						tempLine = tempLine->Replace("  ", " ");
						tempLine = tempLine->Replace(", ", ",");
						j = 0;
						k = 0;
						for (int i = 0; i < tempLine->Length; i++) {
							if (j == 3) {
								String^ tempLUT = tempLine->Substring(i);
								String^ tempAux = "";
								k = 0;
								while (tempLUT[k] != ',') {
									if (k < tempLUT->Length - 1) {
										if (tempLUT[k] != '\"') {
											if (tempLUT[k] != '}') {
												if (tempLUT[k] != ',') {
													tempAux += tempLUT[k];
												}
											}
										}
										k++;
									}
									else {
										break;
									}
								}
								if (tempAux == "") {
									break;
								}
								lAttrToSave->Text += ", " + tempAux;
								j = 0;
								i += k;
							}
							if (tempLine[i] == ',') {
								j++;
							}
						}
						lAttrToSave->Text = lAttrToSave->Text->Replace("_out", "");
						lAttrToSave->Text = lAttrToSave->Text->Replace("  ", " ");
						gAttrLUT = gLandUseTypes;
					}
				}
				sw->Close();
				main = true;
				MessageBox::Show(gSMainImport, gSMainImportTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			LuccME::OpenFileDialog^ submodelFile = gcnew OpenFileDialog;
			submodelFile->Title = gSSubmodelFile;
			submodelFile->Multiselect = false;
			submodelFile->Filter = gSLuaFile;
			submodelFile->FilterIndex = 1;

			if (submodelFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ fileName = submodelFile->FileName;
				System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(fileName);

				String^ line = sw->ReadLine();
				while (line->Contains("=") != 1) {
					line = sw->ReadLine();
				}

				int j = 0;
				while (line[j] != '=') {
					j++;
				}

				j++;
				String^ tempLine = "";
				tempLine = line->Substring(j);
				tempLine = tempLine->Replace(" ", "");
			
				//Demand
				if (tempLine == "PreComputedValuesINPE") {
					j = 0;
					line = sw->ReadLine();
					j++;
					while (line->Contains("=") != 1) {
						line = sw->ReadLine();
						j++;
					}
					tempLine = "";
					line = sw->ReadLine();
					j++;
					while (line->Length != 1) {
						line = sw->ReadLine();
						tempLine += line;
						j++;
					}
					tempLine = tempLine->Replace("\n", "");
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace(" ", "");
				
					gDemand = "";
					bool enter = false;
					for (int i = j; i < tempLine->Length; i++) {
						while (tempLine[i] != '{') {
							if (i == tempLine->Length - 1) {
								enter = false;
								break;
							}
							i++;
							enter = true;
						}
						if (enter) {
							while (tempLine[i] != '}') {
								gDemand += tempLine[i];
								i++;
							}
							gDemand += "},;";
							enter = false;
						}
					}
					gDemand = gDemand->Substring(0, gDemand->Length - 2);
					gDemandLUT = gLandUseTypes;
					if (gDemand != "") {
						int count = 0;
						for (int i = 0; i < gDemand->Length; i++) {
							if (gDemand[i] == ';') {
								count++;
							}
						}
						array<String^>^ lines = gcnew array<String^>(count + 3); //If has 1 semicolon there are 2 values + header (2)
						String^ auxLine = "";
						lines[0] = "PreComputedValuesINPE";
						lines[1] = gDemandLUT;
						count = 2;
						for (int i = 0; i < gDemand->Length; i++) {
							if (gDemand[i] != ';') {
								auxLine += gDemand[i];
							}
							else {
								lines[count] = auxLine;
								auxLine = "";
								count++;
							}
						}
						if (auxLine != "") {
							lines[count] = auxLine;
						}
						tbDemand->Lines = lines;
						gDemandComponent = 1;
					}
				}

				if (tempLine == "ComputeInputTwoDateMaps") {
					tempLine = "";
					gDemandLUT = gLandUseTypes;
					while (line->Contains("finalYearForInterpolation") != 1) {
						line = sw->ReadLine();
					}
					for (int i = 0; i < line->Length; i++) {
						while (line[i] != '=') {
							i++;
						}
						while (line[i] != ',') {
							tempLine += line[i];
							i++;
						}
					}
				
					tempLine = tempLine->Replace("=", "");
					tempLine = tempLine->Replace(" ", "");
					gDemandFinalYear = tempLine;
				
					tempLine = "";
					while (line->Contains("finalLandUseTypesForInterpolation") != 1) {
						line = sw->ReadLine();
					}
					bool enter = true;
					for (int i = 0; i < line->Length; i++) {
						while (line[i] != '{') {
							if (i == line->Length - 1) {
								enter = false;
								break;
							}
							i++;
						}
						if (enter) {
							while (line[i] != '}') {
								tempLine += line[i];
								i++;
							}
						}
					}
				
					gDemand = "";
					tempLine = tempLine->Replace(" ", "");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}", "");
					gDemand = tempLine;

					if (gDemand != "") {
						int count = 0;

						for (int i = 0; i < gDemand->Length; i++) {
							if (gDemand[i] == ',') {
								count++;
							}
						}
						array<String^>^ lines = gcnew array<String^>(4);
						lines[0] = "ComputeInputTwoDateMaps";
						lines[1] = "finalYearForInterpolation = " + gDemandFinalYear;
						lines[2] = gDemandLUT;
						lines[3] = gDemand;

						tbDemand->Lines = lines;
						gDemandComponent = 2;
					}
				}

				if (tempLine == "ComputeInputThreeDateMaps") {
					tempLine = "";
					gDemandLUT = gLandUseTypes;

					while (line->Contains("middleYearForInterpolation") != 1) {
						line = sw->ReadLine();
					}
					for (int i = 0; i < line->Length; i++) {
						while (line[i] != '=') {
							i++;
						}
						while (line[i] != ',') {
							tempLine += line[i];
							i++;
						}
					}

					tempLine = tempLine->Replace("=", "");
					tempLine = tempLine->Replace(" ", "");
					gDemandMiddleYear = tempLine;
				
					tempLine = "";
					while (line->Contains("middleLandUseTypesForInterpolation") != 1) {
						line = sw->ReadLine();
					}
					bool enter = true;
					for (int i = 0; i < line->Length; i++) {
						while (line[i] != '{') {
							if (i == line->Length - 1) {
								enter = false;
								break;
							}
							i++;
						}
						if (enter) {
							while (line[i] != '}') {
								tempLine += line[i];
								i++;
							}
						}
					}

					gDemand = "";
					tempLine = tempLine->Replace(" ", "");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}", "");
					gDemand = tempLine + ";";

					tempLine = "";
					while (line->Contains("finalYearForInterpolation") != 1) {
						line = sw->ReadLine();
					}
					for (int i = 0; i < line->Length; i++) {
						while (line[i] != '=') {
							i++;
						}
						while (line[i] != ',') {
							tempLine += line[i];
							i++;
						}
					}

					tempLine = tempLine->Replace("=", "");
					tempLine = tempLine->Replace(" ", "");
					gDemandFinalYear = tempLine;
				
					tempLine = "";
					while (line->Contains("finalLandUseTypesForInterpolation") != 1) {
						line = sw->ReadLine();
					}
					enter = true;
					for (int i = 0; i < line->Length; i++) {
						while (line[i] != '{') {
							if (i == line->Length - 1) {
								enter = false;
								break;
							}
							i++;
						}
						if (enter) {
							while (line[i] != '}') {
								tempLine += line[i];
								i++;
							}
						}
					}

					tempLine = tempLine->Replace(" ", "");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}", "");
					gDemand += tempLine;

					if (gDemand != "") {
						array<String^>^ lines = gcnew array<String^>(6);
						lines[0] = "ComputeInputThreeDateMaps";
						lines[1] = "middleYearForInterpolation = " + gDemandMiddleYear;
						lines[2] = "finalYearForInterpolation = " + gDemandFinalYear;

						String^ auxline = "";
						int i = 0;
						while (gDemand[i] != ';') {
							auxline += gDemand[i];
							i++;
						}
						lines[3] = gDemandLUT;
						lines[4] = auxline;
						lines[5] = gDemand->Substring(i + 1);

						tbDemand->Lines = lines;
						gDemandComponent = 3;
					}
				}

				//Potencial
				line = sw->ReadLine();
				while (line->Contains("=") != 1) {
					line = sw->ReadLine();
				}

				j = 0;
				while (line[j] != '=') {
					j++;
				}

				j++;
				tempLine = "";
				tempLine = line->Substring(j);
				tempLine = tempLine->Replace(" ", "");

				if (tempLine == "NeighSimpleRule{}") {
					array<String^>^ lines = { "NeighSimpleRule{}" };
					tbPotential->Lines = lines;
					gPotentialComponent = 1;
					gPotentialLUT = gLandUseTypes;
				}

				if (tempLine == "NeighInverseDistanceRule") {
					gPotential = "";
					gPotentialComponent = 2;
					gPotentialLUT = gLandUseTypes;
					int count = 2;
					for (int i = 0; i < gPotentialLUT->Length; i++) {
						if (gPotentialLUT[i] == ',') {
							count++;
						}
					}

					line = sw->ReadLine();
					while (line->Contains("=") != 1) { //potencialData
						line = sw->ReadLine();
					}

					for (int k = 0; k < count - 1; k++) {
						line = sw->ReadLine();
						while (line->Contains("const") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("const=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("betas") != 1) { 
							line = sw->ReadLine();
						}

						tempLine = "";
						while (line->Contains("}") != 1) {
							tempLine += line;
							line = sw->ReadLine();
						}

						tempLine += "}";
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("\t", "");
						tempLine = tempLine->Replace(" ", "");

						String^ tempAux = "";
						bool enter = true;
						for (int i = 0; i < tempLine->Length; i++) {
							while (tempLine[i] != '{') {
								if (i == tempLine->Length - 1) {
									enter = false;
									break;
								}
								i++;
							}
							if (enter) {
								while (tempLine[i] != '}') {
									tempAux += tempLine[i];
									i++;
								}
							}
						}
						tempAux = tempAux->Replace("{", "");
						gPotential += tempAux + "#";
					}
					gPotential = gPotential->Substring(0, gPotential->Length - 1);

					array<String^>^ lines2 = gcnew array<String^>(count);

					lines2[0] = "NeighInverseDistanceRule";

					if (gPotential != "") {
						int lineCount = 1;
						for (int i = 0; i < gPotential->Length; i++) {
							if (gPotential[i] != '#') {
								lines2[lineCount] += gPotential[i];
							}
							else {
								lines2[lineCount] = String::Concat("const=", lines2[lineCount]);
								lines2[lineCount] = lines2[lineCount]->Replace(";", ",betas={");
								lines2[lineCount] = lines2[lineCount]->Replace("=", " = ");
								lines2[lineCount] = lines2[lineCount]->Replace(",", ", ");
								lines2[lineCount] = lines2[lineCount] = String::Concat(lines2[lineCount], "}");
								lineCount++;
							}
						}
						if (lines2[lineCount] != "") {
							lines2[lineCount] = String::Concat("const=", lines2[lineCount]);
							lines2[lineCount] = lines2[lineCount]->Replace(";", ",betas={");
							lines2[lineCount] = lines2[lineCount]->Replace("=", " = ");
							lines2[lineCount] = lines2[lineCount]->Replace(",", ", ");
							lines2[lineCount] = lines2[lineCount] = String::Concat(lines2[lineCount], "}");
						}
						tbPotential->Lines = lines2;
					}
					
				}

				if (tempLine == "InverseDistanceRule") {
					gPotential = "";
					gPotentialComponent = 3;
					gPotentialLUT = gLandUseTypes;
					int count = 2;
					for (int i = 0; i < gPotentialLUT->Length; i++) {
						if (gPotentialLUT[i] == ',') {
							count++;
						}
					}

					line = sw->ReadLine();
					while (line->Contains("=") != 1) { //potencialData
						line = sw->ReadLine();
					}

					for (int k = 0; k < count - 1; k++) {
						line = sw->ReadLine();
						while (line->Contains("const") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("const=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("betas") != 1) { 
							line = sw->ReadLine();
						}

						tempLine = "";
						while (line->Contains("}") != 1) {
							tempLine += line;
							line = sw->ReadLine();
						}

						tempLine += "}";
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("\t", "");
						tempLine = tempLine->Replace(" ", "");

						String^ tempAux = "";
						bool enter = true;
						for (int i = 0; i < tempLine->Length; i++) {
							while (tempLine[i] != '{') {
								if (i == tempLine->Length - 1) {
									enter = false;
									break;
								}
								i++;
							}
							if (enter) {
								while (tempLine[i] != '}') {
									tempAux += tempLine[i];
									i++;
								}
							}
						}
						tempAux = tempAux->Replace("{", "");
						gPotential += tempAux + "#";
					}
					gPotential = gPotential->Substring(0, gPotential->Length - 1);

					array<String^>^ lines2 = gcnew array<String^>(count);

					lines2[0] = "InverseDistanceRule";

					if (gPotential != "") {
						int lineCount = 1;
						for (int i = 0; i < gPotential->Length; i++) {
							if (gPotential[i] != '#') {
								lines2[lineCount] += gPotential[i];
							}
							else {
								lines2[lineCount] = String::Concat("const=", lines2[lineCount]);
								lines2[lineCount] = lines2[lineCount]->Replace(";", ",betas={");
								lines2[lineCount] = lines2[lineCount]->Replace("=", " = ");
								lines2[lineCount] = lines2[lineCount]->Replace(",", ", ");
								lines2[lineCount] = lines2[lineCount] = String::Concat(lines2[lineCount], "}");
								lineCount++;
							}
						}
						if (lines2[lineCount] != "") {
							lines2[lineCount] = String::Concat("const=", lines2[lineCount]);
							lines2[lineCount] = lines2[lineCount]->Replace(";", ",betas={");
							lines2[lineCount] = lines2[lineCount]->Replace("=", " = ");
							lines2[lineCount] = lines2[lineCount]->Replace(",", ", ");
							lines2[lineCount] = lines2[lineCount] = String::Concat(lines2[lineCount], "}");
						}
						tbPotential->Lines = lines2;
					}

				}

				if (tempLine == "LogisticRegression") {
					gPotential = "";
					gPotentialComponent = 4;
					gPotentialLUT = gLandUseTypes;
					int count = 2;
					for (int i = 0; i < gPotentialLUT->Length; i++) {
						if (gPotentialLUT[i] == ',') {
							count++;
						}
					}

					line = sw->ReadLine();
					while (line->Contains("=") != 1) { //potencialData
						line = sw->ReadLine();
					}

					for (int k = 0; k < count - 1; k++) {
						line = sw->ReadLine();
						while (line->Contains("const") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("const=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("elasticity") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("elasticity=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("betas") != 1) { 
							line = sw->ReadLine();
						}

						tempLine = "";
						while (line->Contains("}") != 1) {
							tempLine += line;
							line = sw->ReadLine();
						}

						tempLine += "}";
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("\t", "");
						tempLine = tempLine->Replace(" ", "");

						String^ tempAux = "";
						bool enter = true;
						for (int i = 0; i < tempLine->Length; i++) {
							while (tempLine[i] != '{') {
								if (i == tempLine->Length - 1) {
									enter = false;
									break;
								}
								i++;
							}
							if (enter) {
								while (tempLine[i] != '}') {
									tempAux += tempLine[i];
									i++;
								}
							}
						}
						tempAux = tempAux->Replace("{", "");
						gPotential += tempAux + "#";
					}
	
					gPotential = gPotential->Substring(0, gPotential->Length - 1);
					array<String^>^ lines3 = gcnew array<String^>(count + 1);
					lines3[0] = "LogisticRegression";

					if (gPotential != "") {
							int lineCount = 1;
						bool first = true;
						for (int i = 0; i < gPotential->Length; i++) {
							if (gPotential[i] != '#') {
								if (gPotential[i] != ';') {
									lines3[lineCount] += gPotential[i];
								}
								else {
									if (first) {
										lines3[lineCount] += "$";
										first = false;
									}
									else {
										lines3[lineCount] += gPotential[i];
									}
								}
							}
							else {
								lines3[lineCount] = String::Concat("const=", lines3[lineCount]);
								lines3[lineCount] = lines3[lineCount]->Replace("$", ",elasticity=");
								lines3[lineCount] = lines3[lineCount]->Replace(";", ",betas={");
								lines3[lineCount] = lines3[lineCount]->Replace("=", " = ");
								lines3[lineCount] = lines3[lineCount]->Replace(",", ", ");
								lines3[lineCount] = lines3[lineCount] = String::Concat(lines3[lineCount], "}");
								lineCount++;
								first = true;
							}
						}
						if (lines3[lineCount] != "") {
							lines3[lineCount] = String::Concat("const=", lines3[lineCount]);
							lines3[lineCount] = lines3[lineCount]->Replace("$", ",elasticity=");
							lines3[lineCount] = lines3[lineCount]->Replace(";", ",betas={");
							lines3[lineCount] = lines3[lineCount]->Replace("=", " = ");
							lines3[lineCount] = lines3[lineCount]->Replace(",", ", ");
							lines3[lineCount] = lines3[lineCount] = String::Concat(lines3[lineCount], "}");
						}
						tbPotential->Lines = lines3;
					}

				}

				if (tempLine == "NeighAttractionLogisticRegression") {
					gPotential = "";
					gPotentialComponent = 5;
					gPotentialLUT = gLandUseTypes;
					int count = 2;
					for (int i = 0; i < gPotentialLUT->Length; i++) {
						if (gPotentialLUT[i] == ',') {
							count++;
						}
					}

					line = sw->ReadLine();
					while (line->Contains("=") != 1) { //potencialData
						line = sw->ReadLine();
					}

					for (int k = 0; k < count - 1; k++) {
						line = sw->ReadLine();
						while (line->Contains("const") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("const=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("elasticity") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("elasticity=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("percNeighborsUse") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("percNeighborsUse=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("betas") != 1) { 
							line = sw->ReadLine();
						}

						tempLine = "";
						while (line->Contains("}") != 1) {
							tempLine += line;
							line = sw->ReadLine();
						}

						tempLine += "}";
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("\t", "");
						tempLine = tempLine->Replace(" ", "");

						String^ tempAux = "";
						bool enter = true;
						for (int i = 0; i < tempLine->Length; i++) {
							while (tempLine[i] != '{') {
								if (i == tempLine->Length - 1) {
									enter = false;
									break;
								}
								i++;
							}
							if (enter) {
								while (tempLine[i] != '}') {
									tempAux += tempLine[i];
									i++;
								}
							}
						}
						tempAux = tempAux->Replace("{", "");
						gPotential += tempAux + "#";
					}

					gPotential = gPotential->Substring(0, gPotential->Length - 1);
					array<String^>^ lines4 = gcnew array<String^>(count + 2);
					lines4[0] = "NeighAttractionLogisticRegression";

					if (gPotential != "") {
						int lineCount = 1;
						bool first = true;
						bool second = true;
						for (int i = 0; i < gPotential->Length; i++) {
							if (gPotential[i] != '#') {
								if (gPotential[i] != ';') {
									lines4[lineCount] += gPotential[i];
								}
								else {
									if (first) {
										lines4[lineCount] += "$";
										first = false;
									}
									else if (second) {
										lines4[lineCount] += "@";
										second = false;
									}
									else {
										lines4[lineCount] += gPotential[i];
									}
								}
							}
							else {
								lines4[lineCount] = String::Concat("const=", lines4[lineCount]);
								lines4[lineCount] = lines4[lineCount]->Replace("$", ",elasticity=");
								lines4[lineCount] = lines4[lineCount]->Replace("@", ",percNeighborsUse=");
								lines4[lineCount] = lines4[lineCount]->Replace(";", ",betas={");
								lines4[lineCount] = lines4[lineCount]->Replace("=", " = ");
								lines4[lineCount] = lines4[lineCount]->Replace(",", ", ");
								lines4[lineCount] = lines4[lineCount] = String::Concat(lines4[lineCount], "}");
								lineCount++;
								first = true;
								second = true;
							}
						}
						if (lines4[lineCount] != "") {
							lines4[lineCount] = String::Concat("const=", lines4[lineCount]);
							lines4[lineCount] = lines4[lineCount]->Replace("$", ",elasticity=");
							lines4[lineCount] = lines4[lineCount]->Replace("@", ",percNeighborsUse=");
							lines4[lineCount] = lines4[lineCount]->Replace(";", ",betas={");
							lines4[lineCount] = lines4[lineCount]->Replace("=", " = ");
							lines4[lineCount] = lines4[lineCount]->Replace(",", ", ");
							lines4[lineCount] = lines4[lineCount] = String::Concat(lines4[lineCount], "}");
						}
						tbPotential->Lines = lines4;
					}

				}

				if (tempLine == "LinearRegression") {
					gPotential = "";
					gPotentialComponent = 6;
					gPotentialLUT = gLandUseTypes;
					int count = 2;
					for (int i = 0; i < gPotentialLUT->Length; i++) {
						if (gPotentialLUT[i] == ',') {
							count++;
						}
					}

					line = sw->ReadLine();
					while (line->Contains("=") != 1) { //regressionData
						line = sw->ReadLine();
					}

					for (int k = 0; k < count - 1; k++) {
						line = sw->ReadLine();
						while (line->Contains("isLog") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("isLog=", "");
						line = line->Replace(",", "");
						if (line == "true") {
							line = "1;";
						}
						else {
							line = "0;";
						}
					
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("const") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("const=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("betas") != 1) { 
							line = sw->ReadLine();
						}

						tempLine = "";
						while (line->Contains("}") != 1) {
							tempLine += line;
							line = sw->ReadLine();
						}

						tempLine += "}";
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("\t", "");
						tempLine = tempLine->Replace(" ", "");

						String^ tempAux = "";
						bool enter = true;
						for (int i = 0; i < tempLine->Length; i++) {
							while (tempLine[i] != '{') {
								if (i == tempLine->Length - 1) {
									enter = false;
									break;
								}
								i++;
							}
							if (enter) {
								while (tempLine[i] != '}') {
									tempAux += tempLine[i];
									i++;
								}
							}
						}
						tempAux = tempAux->Replace("{", "");
						gPotential += tempAux + "#";
					}

					gPotential = gPotential->Substring(0, gPotential->Length - 1);
				
					array<String^>^ lines = gcnew array<String^>(count + 1);
					lines[0] = "LinearRegression";

					if (gPotential != "") {
						int lineCount = 1;
						bool first = true;
						for (int i = 0; i < gPotential->Length; i++) {
							if (gPotential[i] != '#') {
								if (gPotential[i] != ';') {
									lines[lineCount] += gPotential[i];
								}
								else {
									if (first) {
										lines[lineCount] += "$";
										first = false;
									}
									else {
										lines[lineCount] += gPotential[i];
									}
								}
							}
							else {
								if (lines[lineCount][0] == '0') {
									lines[lineCount] = String::Concat("false", lines[lineCount]->Substring(1));
								}
								else {
									lines[lineCount] = String::Concat("true", lines[lineCount]->Substring(1));
								}
								lines[lineCount] = String::Concat("isLog=", lines[lineCount]);
								lines[lineCount] = lines[lineCount]->Replace("$", ",const=");
								lines[lineCount] = lines[lineCount]->Replace(";", ",betas={");
								lines[lineCount] = lines[lineCount]->Replace("=", " = ");
								lines[lineCount] = lines[lineCount]->Replace(",", ", ");
								lines[lineCount] = lines[lineCount] = String::Concat(lines[lineCount], "}");
								lineCount++;
								first = true;
							}
						}
						if (lines[lineCount] != "") {
							if (lines[lineCount][0] == '0') {
								lines[lineCount] = String::Concat("false", lines[lineCount]->Substring(1));
							}
							else {
								lines[lineCount] = String::Concat("true", lines[lineCount]->Substring(1));
							}
							lines[lineCount] = String::Concat("isLog=", lines[lineCount]);
							lines[lineCount] = lines[lineCount]->Replace("$", ",const=");
							lines[lineCount] = lines[lineCount]->Replace(";", ",betas={");
							lines[lineCount] = lines[lineCount]->Replace("=", " = ");
							lines[lineCount] = lines[lineCount]->Replace(",", ", ");
							lines[lineCount] = lines[lineCount] = String::Concat(lines[lineCount], "}");
						}
					
						tbPotential->Lines = lines;
					}
				}

				if (tempLine == "SpatialLagRegression") {
					gPotential = "";
					gPotentialComponent = 7;
					gPotentialLUT = gLandUseTypes;
					int count = 2;
					for (int i = 0; i < gPotentialLUT->Length; i++) {
						if (gPotentialLUT[i] == ',') {
							count++;
						}
					}

					line = sw->ReadLine();
					while (line->Contains("=") != 1) { //regressionData
						line = sw->ReadLine();
					}

					for (int k = 0; k < count - 1; k++) {
						line = sw->ReadLine();
						while (line->Contains("isLog") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("isLog=", "");
						line = line->Replace(",", "");
						if (line == "true") {
							line = "1;";
						}
						else {
							line = "0;";
						}

						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("const") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("const=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("minReg") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("minReg=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("maxReg") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("maxReg=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("ro") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("ro=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("betas") != 1) { 
							line = sw->ReadLine();
						}

						tempLine = "";
						while (line->Contains("}") != 1) {
							tempLine += line;
							line = sw->ReadLine();
						}

						tempLine += "}";
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("\t", "");
						tempLine = tempLine->Replace(" ", "");

						String^ tempAux = "";
						bool enter = true;
						for (int i = 0; i < tempLine->Length; i++) {
							while (tempLine[i] != '{') {
								if (i == tempLine->Length - 1) {
									enter = false;
									break;
								}
								i++;
							}
							if (enter) {
								while (tempLine[i] != '}') {
									tempAux += tempLine[i];
									i++;
								}
							}
						}
						tempAux = tempAux->Replace("{", "");
						gPotential += tempAux + "#";
					}

					gPotential = gPotential->Substring(0, gPotential->Length - 1);

					array<String^>^ lines2 = gcnew array<String^>(count + 4);
					lines2[0] = "SpatialLagRegression";

					if (gPotential != "") {
						int lineCount = 1;
						int change = 0;

						for (int i = 0; i < gPotential->Length; i++) {
							if (gPotential[i] != '#') {
								if (gPotential[i] != ';') {
									lines2[lineCount] += gPotential[i];
								}
								else {
									switch (change)
									{
									case 0:
										lines2[lineCount] += "$";
										change++;
										break;

									case 1:
										lines2[lineCount] += "@";
										change++;
										break;

									case 2:
										lines2[lineCount] += "%";
										change++;
										break;

									case 3:
										lines2[lineCount] += "&";
										change++;
										break;
									default:
										lines2[lineCount] += gPotential[i];
										break;
									}
								}
							}
							else {
								if (lines2[lineCount][0] == '0') {
									lines2[lineCount] = String::Concat("false", lines2[lineCount]->Substring(1));
								}
								else {
									lines2[lineCount] = String::Concat("true", lines2[lineCount]->Substring(1));
								}
								lines2[lineCount] = String::Concat("isLog = ", lines2[lineCount]);
								lines2[lineCount] = lines2[lineCount]->Replace("$", ",const=");
								lines2[lineCount] = lines2[lineCount]->Replace("@", ",minReg=");
								lines2[lineCount] = lines2[lineCount]->Replace("%", ",maxReg=");
								lines2[lineCount] = lines2[lineCount]->Replace("&", ",ro=");
								lines2[lineCount] = lines2[lineCount]->Replace(";", ",betas={");
								lines2[lineCount] = lines2[lineCount]->Replace("=", " = ");
								lines2[lineCount] = lines2[lineCount]->Replace(",", ", ");
								lines2[lineCount] = lines2[lineCount] = String::Concat(lines2[lineCount], "}");
								lineCount++;
								change = 0;
							}
						}
						if (lines2[lineCount] != "") {
							if (lines2[lineCount][0] == '0') {
								lines2[lineCount] = String::Concat("false", lines2[lineCount]->Substring(1));
							}
							else {
								lines2[lineCount] = String::Concat("true", lines2[lineCount]->Substring(1));
							}
							lines2[lineCount] = String::Concat("isLog = ", lines2[lineCount]);
							lines2[lineCount] = lines2[lineCount]->Replace("$", ",const=");
							lines2[lineCount] = lines2[lineCount]->Replace("@", ",minReg=");
							lines2[lineCount] = lines2[lineCount]->Replace("%", ",maxReg=");
							lines2[lineCount] = lines2[lineCount]->Replace("&", ",ro=");
							lines2[lineCount] = lines2[lineCount]->Replace(";", ",betas={");
							lines2[lineCount] = lines2[lineCount]->Replace("=", " = ");
							lines2[lineCount] = lines2[lineCount]->Replace(",", ", ");
							lines2[lineCount] = lines2[lineCount] = String::Concat(lines2[lineCount], "}");
						}

						tbPotential->Lines = lines2;
					}
				}

				if (tempLine == "SpatialLagLinearRoads") {
					gPotential = "";
					gPotentialComponent = 8;
					gPotentialLUT = gLandUseTypes;
					int count = 2;
					for (int i = 0; i < gPotentialLUT->Length; i++) {
						if (gPotentialLUT[i] == ',') {
							count++;
						}
					}

					line = sw->ReadLine();
					while (line->Contains("=") != 1) { //regressionData
						line = sw->ReadLine();
					}

					for (int k = 0; k < count - 1; k++) {
						line = sw->ReadLine();
						while (line->Contains("isLog") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("isLog=", "");
						line = line->Replace(",", "");
						if (line == "true") {
							line = "1;";
						}
						else {
							line = "0;";
						}

						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("const") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("const=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("minReg") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("minReg=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("maxReg") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("maxReg=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("ro") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("ro=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("betas") != 1) { 
							line = sw->ReadLine();
						}

						tempLine = "";
						while (line->Contains("}") != 1) {
							tempLine += line;
							line = sw->ReadLine();
						}

						tempLine += "}";
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("\t", "");
						tempLine = tempLine->Replace(" ", "");

						String^ tempAux = "";
						bool enter = true;
						for (int i = 0; i < tempLine->Length; i++) {
							while (tempLine[i] != '{') {
								if (i == tempLine->Length - 1) {
									enter = false;
									break;
								}
								i++;
							}
							if (enter) {
								while (tempLine[i] != '}') {
									tempAux += tempLine[i];
									i++;
								}
							}
						}
						tempAux = tempAux->Replace("{", "");
						gPotential += tempAux + "*";
				
						line = sw->ReadLine();
						while (line->Contains("=") != 1) { //roadsModel
							line = sw->ReadLine();
						}

						line = sw->ReadLine();
						while (line->Contains("attrs") != 1) {  
							line = sw->ReadLine();
						}

						tempLine = "";
						while (line->Contains("}") != 1) {
							tempLine += line;
							line = sw->ReadLine();
						}

						tempLine += "}";
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("\t", "");
						tempLine = tempLine->Replace(" ", "");

						tempAux = "";
						enter = true;
						for (int i = 0; i < tempLine->Length; i++) {
							while (tempLine[i] != '{') {
								if (i == tempLine->Length - 1) {
									enter = false;
									break;
								}
								i++;
							}
							if (enter) {
								while (tempLine[i] != '}') {
									tempAux += tempLine[i];
									i++;
								}
							}
						}
						tempAux = tempAux->Replace("{", "");
						gPotential += tempAux + ";";

						line = sw->ReadLine();
						while (line->Contains("const") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("const=", "");
						line = line->Replace(",", ";");
						gPotential += line;

						line = sw->ReadLine();
						while (line->Contains("change") != 1) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("change=", "");
						line = line->Replace(",", ";");
						gPotential += line;


						line = sw->ReadLine();
						while (line->Contains("betas") != 1) { //betas roadmodel
							line = sw->ReadLine();
						}

						tempLine = "";
						while (line->Contains("}") != 1) {
							tempLine += line;
							line = sw->ReadLine();
						}

						tempLine += "}";
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("\t", "");
						tempLine = tempLine->Replace(" ", "");

						tempAux = "";
						enter = true;
						for (int i = 0; i < tempLine->Length; i++) {
							while (tempLine[i] != '{') {
								if (i == tempLine->Length - 1) {
									enter = false;
									break;
								}
								i++;
							}
							if (enter) {
								while (tempLine[i] != '}') {
									tempAux += tempLine[i];
									i++;
								}
							}
						}
						tempAux = tempAux->Replace("{", "");
						gPotential += tempAux + "#";
					}

					gPotential = gPotential->Substring(0, gPotential->Length - 1);

					array<String^>^ lines3 = gcnew array<String^>(count + 10);
					lines3[0] = "SpatialLagLinearRoads";

					if (gPotential != "") {
						int lineCount = 1;
						int change = 0;

						for (int i = 0; i < gPotential->Length; i++) {
							if (gPotential[i] != '#') {
								if (gPotential[i] != ';') {
									lines3[lineCount] += gPotential[i];
								}
								else {
									switch (change)
									{
									case 0:
										lines3[lineCount] += "$";
										change++;
										break;

									case 1:
										lines3[lineCount] += "@";
										change++;
										break;

									case 2:
										lines3[lineCount] += "%";
										change++;
										break;

									case 3:
										lines3[lineCount] += "&";
										change++;
										break;

									case 4:
										lines3[lineCount] += "!";
										change++;
										break;

									case 5:
										lines3[lineCount] += "£";
										change++;
										break;

									case 6:
										lines3[lineCount] += "¢";
										change++;
										break;

									default:
										lines3[lineCount] += gPotential[i];
										break;
									}
								}

							}
							else {
								if (lines3[lineCount][0] == '0') {
									lines3[lineCount] = String::Concat("false", lines3[lineCount]->Substring(1));
								}
								else {
									lines3[lineCount] = String::Concat("true", lines3[lineCount]->Substring(1));
								}
								lines3[lineCount] = String::Concat("isLog = ", lines3[lineCount]);
								lines3[lineCount] = lines3[lineCount]->Replace("$", ",const=");
								lines3[lineCount] = lines3[lineCount]->Replace("@", ",minReg=");
								lines3[lineCount] = lines3[lineCount]->Replace("%", ",maxReg=");
								lines3[lineCount] = lines3[lineCount]->Replace("&", ",ro=");
								lines3[lineCount] = lines3[lineCount]->Replace("!", ",betas = {");
								lines3[lineCount] = lines3[lineCount]->Replace("*", "},roadsModel={ attrs={");;
								lines3[lineCount] = lines3[lineCount]->Replace("£", "},const=");
								lines3[lineCount] = lines3[lineCount]->Replace("¢", ",change=");
								lines3[lineCount] = lines3[lineCount]->Replace(";", ",betas={");
								lines3[lineCount] = lines3[lineCount]->Replace("=", " = ");
								lines3[lineCount] = lines3[lineCount]->Replace(",", ", ");
								lines3[lineCount] = lines3[lineCount] = String::Concat(lines3[lineCount], "}}");
								lineCount++;
								change = 0;
							}
						}
						if (lines3[lineCount] != "") {
							if (lines3[lineCount][0] == '0') {
								lines3[lineCount] = String::Concat("false", lines3[lineCount]->Substring(1));
							}
							else {
								lines3[lineCount] = String::Concat("true", lines3[lineCount]->Substring(1));
							}
							lines3[lineCount] = String::Concat("isLog = ", lines3[lineCount]);
							lines3[lineCount] = lines3[lineCount]->Replace("$", ",const=");
							lines3[lineCount] = lines3[lineCount]->Replace("@", ",minReg=");
							lines3[lineCount] = lines3[lineCount]->Replace("%", ",maxReg=");
							lines3[lineCount] = lines3[lineCount]->Replace("&", ",ro=");
							lines3[lineCount] = lines3[lineCount]->Replace("!", ",betas = {");
							lines3[lineCount] = lines3[lineCount]->Replace("*", "},roadsModel={ attrs={");;
							lines3[lineCount] = lines3[lineCount]->Replace("£", "},const=");
							lines3[lineCount] = lines3[lineCount]->Replace("¢", ",change=");
							lines3[lineCount] = lines3[lineCount]->Replace(";", ",betas={");
							lines3[lineCount] = lines3[lineCount]->Replace("=", " = ");
							lines3[lineCount] = lines3[lineCount]->Replace(",", ", ");
							lines3[lineCount] = lines3[lineCount] = String::Concat(lines3[lineCount], "}}");
						}
						tbPotential->Lines = lines3;
					}
				}
			
				//Allocation
				gAllocationLUT = gLandUseTypes;

				int count = 1;
				for (int i = 0; i < gAllocationLUT->Length; i++) {
					if (gAllocationLUT[i] == ',') {
						count++;
					}
				}

				line = sw->ReadLine();
				while (line->Contains("=") != 1) {
					line = sw->ReadLine();
				}

				j = 0;
				while (line[j] != '=') {
					j++;
				}

				j++;
				tempLine = "";
				tempLine = line->Substring(j);
				tempLine = tempLine->Replace(" ", "");

				if (tempLine == "AllocationBySimpleOrdering") {
					gAllocation = "";
					gAllocationComponent = 1;

					line = sw->ReadLine();
					while (line->Contains("maxDifference") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxDifference=", "");
					line = line->Replace(",", ";");
					gAllocation = line;

					array<String^>^ lines = gcnew array<String^>(2);
				
					if (gAllocation != "") {
						lines[0] = "AllocationBySimpleOrdering";
						lines[1] = "maxDifference = " + gAllocation;
						tbAllocation->Lines = lines;
					}
				}

				if (tempLine == "AllocationClueSLike") {
					gAllocation = "";
					gAllocationComponent = 2;
					gAllocationLUT = gLandUseTypes;

					line = sw->ReadLine();
					while (line->Contains("maxIteration") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxIteration=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("factorIteration") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("factorIteration=", "");
					line = line->Replace(",", ";");
					gAllocation += line;
		
					line = sw->ReadLine();
					while (line->Contains("maxDifference") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxDifference=", "");
					line = line->Replace(",", ";");
					gAllocation += line;
				
					line = sw->ReadLine();
					while (line->Contains("transitionMatrix") != 1) {
						line = sw->ReadLine();
						j++;
					}
				
					tempLine = "";
					line = sw->ReadLine();
					while (line != "}") {
						line = sw->ReadLine();
						tempLine += line;
						j++;
					}

					tempLine = tempLine->Replace("--", "");
					tempLine = tempLine->Replace("Region 1", "");
					tempLine = tempLine->Replace("Region1", "");
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace("\n", "");
					tempLine = tempLine->Replace("{{{", "{");
					tempLine = tempLine->Replace("{{", "{");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}}}", "}");
					tempLine = tempLine->Replace("}}", "}");
					tempLine = tempLine->Replace("}", ";");
					tempLine = tempLine->Replace(";,", ";");
					tempLine = tempLine->Replace(" ", "");

					gAllocation += tempLine;

					array<String^>^ lines2 = gcnew array<String^>(count + 5);

					if (gAllocation != "") {
						lines2[0] = "AllocationClueSLike";
						int lineCount = 1;
						int change = 0;
						int j = 0;

						lines2[lineCount] = "maxIteration = ";
						while (gAllocation[j] != ';') {
							lines2[lineCount] += gAllocation[j];
							j++;
						}
						lineCount++;
						j++;

						lines2[lineCount] = "factorIteration = ";
						while (gAllocation[j] != ';') {
							lines2[lineCount] += gAllocation[j];
							j++;
						}
						lineCount++;
						j++;

						lines2[lineCount] = "maxDifference = ";
						while (gAllocation[j] != ';') {
							lines2[lineCount] += gAllocation[j];
							j++;
						}
						lineCount++;
						j++;

						lines2[lineCount] = "transitionMatrix";
						lineCount++;
						for (int i = j; i < gAllocation->Length; i++) {
							if (gAllocation[i] != ';') {
								if (gAllocation[i] != ',') {
									lines2[lineCount] += gAllocation[i];
								}
								else {
									lines2[lineCount] += ", ";
								}
							}
							else {
								lineCount++;
							}
						}

						tbAllocation->Lines = lines2;
					}
				}

				if (tempLine == "AllocationClueLike") {
					gAllocation = "";
					gAllocationComponent = 3;
					gAllocationLUT = gLandUseTypes;

					line = sw->ReadLine();
					while (line->Contains("maxDifference") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxDifference=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("maxIteration") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxIteration=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("initialElasticity") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("initialElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("minElasticity") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("minElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("maxElasticity") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("complementarLU") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("complementarLU=", "");
					line = line->Replace(",", ";");
					line = line->Replace("\"", "");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("allocationData") != 1) {
						line = sw->ReadLine();
						j++;
					}

					tempLine = "";
					line = sw->ReadLine();
					while (line != "}") {
						line = sw->ReadLine();
						line = line->Replace(" ", "");
						line = line->Replace("\t", "");
						line = line->Replace("--", "$");
						j = 0;
						while (line[j] != '$' && j < line->Length - 1) {
							tempLine += line[j];
							j++;
						}
					}

					tempLine = tempLine->Replace("--", "");
					tempLine = tempLine->Replace("Region 1", "");
					tempLine = tempLine->Replace("Region1", "");
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace("\n", "");
					tempLine = tempLine->Replace("{{{", "{");
					tempLine = tempLine->Replace("{{", "{");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}}}", "}");
					tempLine = tempLine->Replace("}}", "}");
					tempLine = tempLine->Replace("}", ";");
					tempLine = tempLine->Replace(";,", ";");
					tempLine = tempLine->Replace(" ", "");
					tempLine = tempLine->Replace("static=", "");
					tempLine = tempLine->Replace("minValue=", "");
					tempLine = tempLine->Replace("maxValue=", "");
					tempLine = tempLine->Replace("minChange=", "");
					tempLine = tempLine->Replace("maxChange=", "");
					tempLine = tempLine->Replace("changeLimiarValue=", "");
					tempLine = tempLine->Replace("maxChangeAboveLimiar=", "");
					tempLine = tempLine->Replace("maxChangeAboveLimiar=", "");

					gAllocation += tempLine;
					gAllocation = gAllocation->Substring(0, gAllocation->Length - 1);

					if (gAllocation != "") {
						int j = 0;

						String^ maxDifference = "";
						while (gAllocation[j] != ';') {
							maxDifference += gAllocation[j];
							j++;
						}
						j++;

						String^ maxIteration = "";
						while (gAllocation[j] != ';') {
							maxIteration += gAllocation[j];
							j++;
						}
						j++;

						String^ initialElasticity = "";
						while (gAllocation[j] != ';') {
							initialElasticity += gAllocation[j];
							j++;
						}
						j++;

						String^ minElasticity = "";
						while (gAllocation[j] != ';') {
							minElasticity += gAllocation[j];
							j++;
						}
						j++;

						String^ maxElasticity = "";
						while (gAllocation[j] != ';') {
							maxElasticity += gAllocation[j];
							j++;
						}
						j++;

						String^ complementarLU = "";
						while (gAllocation[j] != ';') {
							complementarLU += gAllocation[j];
							j++;
						}
						j++;

						array<String^>^ lines = gcnew array<String^>(count + 10);

						lines[0] = "AllocationClueLike";

						lines[1] = "maxDifference = " + maxDifference;
						lines[2] = "maxIteration = " + maxIteration;
						lines[3] = "initialElasticity = " + initialElasticity;
						lines[4] = "minElasticity = " + minElasticity;
						lines[5] = "maxElasticity = " + maxElasticity;
						lines[6] = "complementarLU = " + complementarLU;
						lines[7] = "allocationData";
						count = 8;

						int change = 0;
						for (int i = j; i < gAllocation->Length; i++) {
							if (gAllocation[i] != ';') {
								if (gAllocation[i] != ',') {
									lines[count] += gAllocation[i];
								}
								else {
									switch (change)
									{
									case 0:
										lines[count] += "$";
										change++;
										break;

									case 1:
										lines[count] += "@";
										change++;
										break;

									case 2:
										lines[count] += "%";
										change++;
										break;

									case 3:
										lines[count] += "&";
										change++;
										break;

									case 4:
										lines[count] += "!";
										change++;
										break;

									case 5:
										lines[count] += "£";
										change++;
										break;

									case 6:
										lines[count] += "¢";
										change++;
										break;

									default:
										lines[count] += gAllocation[i];
										break;
									}
								}
							}
							else {
								lines[count] = String::Concat("static=", lines[count]);
								lines[count] = lines[count]->Replace("$", ",minValue=");
								lines[count] = lines[count]->Replace("@", ",maxValue=");
								lines[count] = lines[count]->Replace("%", ",minChange=");
								lines[count] = lines[count]->Replace("&", ",maxChange=");
								lines[count] = lines[count]->Replace("!", ",changeLimiarValue=");
								lines[count] = lines[count]->Replace("£", ",maxChangeAboveLimiar=");
								lines[count] = lines[count]->Replace(",", ", ");
								lines[count] = lines[count]->Replace("=", " = ");
								count++;
								change = 0;
							}
						}
						if (lines[count] != "") {
							lines[count] = String::Concat("static=", lines[count]);
							lines[count] = lines[count]->Replace("$", ",minValue=");
							lines[count] = lines[count]->Replace("@", ",maxValue=");
							lines[count] = lines[count]->Replace("%", ",minChange=");
							lines[count] = lines[count]->Replace("&", ",maxChange=");
							lines[count] = lines[count]->Replace("!", ",changeLimiarValue=");
							lines[count] = lines[count]->Replace("£", ",maxChangeAboveLimiar=");
							lines[count] = lines[count]->Replace(",", ", ");
							lines[count] = lines[count]->Replace("=", " = ");
						}
						tbAllocation->Lines = lines;
					}
				
				}

				if (tempLine == "AllocationClueLikeSaturation") {
					gAllocation = "";
					gAllocationComponent = 4;
					gAllocationLUT = gLandUseTypes;

					line = sw->ReadLine();
					while (line->Contains("maxDifference") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxDifference=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("maxIteration") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxIteration=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("initialElasticity") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("initialElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("minElasticity") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("minElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("maxElasticity") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("complementarLU") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("complementarLU=", "");
					line = line->Replace(",", ";");
					line = line->Replace("\"", "");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("saturationIndicator") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("saturationIndicator=", "");
					line = line->Replace(",", ";");
					line = line->Replace("\"", "");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("attrProtection") != 1) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("attrProtection=", "");
					line = line->Replace(",", ";");
					line = line->Replace("\"", "");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("allocationData") != 1) {
						line = sw->ReadLine();
						j++;
					}

					tempLine = "";
					line = sw->ReadLine();
					while (line != "}") {
						line = sw->ReadLine();
						line = line->Replace(" ", "");
						line = line->Replace("\t", "");
						line = line->Replace("--", "$");
						j = 0;
						while (line[j] != '$' && j < line->Length - 1) {
							tempLine += line[j];
							j++;
						}
					}

					tempLine = tempLine->Replace("--", "");
					tempLine = tempLine->Replace("Region 1", "");
					tempLine = tempLine->Replace("Region1", "");
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace("\n", "");
					tempLine = tempLine->Replace("{{{", "{");
					tempLine = tempLine->Replace("{{", "{");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}}}", "}");
					tempLine = tempLine->Replace("}}", "}");
					tempLine = tempLine->Replace("}", ";");
					tempLine = tempLine->Replace(";,", ";");
					tempLine = tempLine->Replace(" ", "");
					tempLine = tempLine->Replace("static=", "");
					tempLine = tempLine->Replace("minValue=", "");
					tempLine = tempLine->Replace("maxValue=", "");
					tempLine = tempLine->Replace("minChange=", "");
					tempLine = tempLine->Replace("maxChange=", "");
					tempLine = tempLine->Replace("changeLimiarValue=", "");
					tempLine = tempLine->Replace("maxChangeAboveLimiar=", "");
					tempLine = tempLine->Replace("maxChangeAboveLimiar=", "");

					gAllocation += tempLine;
					gAllocation = gAllocation->Substring(0, gAllocation->Length - 1);

					if (gAllocation != "") {
						int j = 0;

						String^ maxDifference = "";
						while (gAllocation[j] != ';') {
							maxDifference += gAllocation[j];
							j++;
						}
						j++;

						String^ maxIteration = "";
						while (gAllocation[j] != ';') {
							maxIteration += gAllocation[j];
							j++;
						}
						j++;

						String^ initialElasticity = "";
						while (gAllocation[j] != ';') {
							initialElasticity += gAllocation[j];
							j++;
						}
						j++;

						String^ minElasticity = "";
						while (gAllocation[j] != ';') {
							minElasticity += gAllocation[j];
							j++;
						}
						j++;

						String^ maxElasticity = "";
						while (gAllocation[j] != ';') {
							maxElasticity += gAllocation[j];
							j++;
						}
						j++;

						String^ complementarLU = "";
						while (gAllocation[j] != ';') {
							complementarLU += gAllocation[j];
							j++;
						}
						j++;

						String^ saturationIndicator = "";
						String^ attrProtection = "";
						if (gAllocationComponent == 4) {
							while (gAllocation[j] != ';') {
								saturationIndicator += gAllocation[j];
								j++;
							}
							j++;

							while (gAllocation[j] != ';') {
								attrProtection += gAllocation[j];
								j++;
							}
							j++;
						}

						int count = 1;
						for (int i = 0; i < gAllocationLUT->Length; i++) {
							if (gAllocationLUT[i] == ',') {
								count++;
							}
						}

						array<String^>^ lines = gcnew array<String^>(count + 10);

						lines[0] = "AllocationClueLikeSaturation";
						lines[1] = "maxDifference = " + maxDifference;
						lines[2] = "maxIteration = " + maxIteration;
						lines[3] = "initialElasticity = " + initialElasticity;
						lines[4] = "minElasticity = " + minElasticity;
						lines[5] = "maxElasticity = " + maxElasticity;
						lines[6] = "complementarLU = " + complementarLU;
						lines[7] = "saturationIndicator = " + saturationIndicator;
						lines[8] = "attrProtection = " + attrProtection;
						lines[9] = "allocationData";
						count = 10;

						int change = 0;
						for (int i = j; i < gAllocation->Length; i++) {
							if (gAllocation[i] != ';') {
								if (gAllocation[i] != ',') {
									lines[count] += gAllocation[i];
								}
								else {
									switch (change)
									{
									case 0:
										lines[count] += "$";
										change++;
										break;

									case 1:
										lines[count] += "@";
										change++;
										break;

									case 2:
										lines[count] += "%";
										change++;
										break;

									case 3:
										lines[count] += "&";
										change++;
										break;

									case 4:
										lines[count] += "!";
										change++;
										break;

									case 5:
										lines[count] += "£";
										change++;
										break;

									case 6:
										lines[count] += "¢";
										change++;
										break;

									default:
										lines[count] += gAllocation[i];
										break;
									}
								}
							}
							else {
								lines[count] = String::Concat("static=", lines[count]);
								lines[count] = lines[count]->Replace("$", ",minValue=");
								lines[count] = lines[count]->Replace("@", ",maxValue=");
								lines[count] = lines[count]->Replace("%", ",minChange=");
								lines[count] = lines[count]->Replace("&", ",maxChange=");
								lines[count] = lines[count]->Replace("!", ",changeLimiarValue=");
								lines[count] = lines[count]->Replace("£", ",maxChangeAboveLimiar=");
								lines[count] = lines[count]->Replace(",", ", ");
								lines[count] = lines[count]->Replace("=", " = ");
								count++;
								change = 0;
							}
						}
						if (lines[count] != "") {
							lines[count] = String::Concat("static=", lines[count]);
							lines[count] = lines[count]->Replace("$", ",minValue=");
							lines[count] = lines[count]->Replace("@", ",maxValue=");
							lines[count] = lines[count]->Replace("%", ",minChange=");
							lines[count] = lines[count]->Replace("&", ",maxChange=");
							lines[count] = lines[count]->Replace("!", ",changeLimiarValue=");
							lines[count] = lines[count]->Replace("£", ",maxChangeAboveLimiar=");
							lines[count] = lines[count]->Replace(",", ", ");
							lines[count] = lines[count]->Replace("=", " = ");
						}
						tbAllocation->Lines = lines;
					}

				}

				sw->Close();
				submodel = true;
			}
		
			if (main && submodel && imported) {
				if (gPotentialComponent > 5 && (gAllocationComponent > 0 && gAllocationComponent < 3)) {
					MessageBox::Show(gSPotContAlocDisc, gSPotContAlocDiscTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else if ((gPotentialComponent > 0 && gPotentialComponent < 6) && gAllocationComponent > 2) {
					MessageBox::Show(gSPotDiscAlocCont, gSPotContAlocDiscTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else {
					lRunModel->Visible = true;
					bRun->Visible = true;
					runnable = true;
					checkLanguage();
				}
			}
		} 
		catch(Exception^ e){
			if (e->GetType()->ToString() == "System.IndexOutOfRangeException") {
				MessageBox::Show(gSImportError, gSImportErrorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				closing = true;
				this->Close();
			}
		}
	}
}

System::Void LuccME::NovoModelo::idiomaToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LanguageForm^ languageForm = gcnew LanguageForm(lLanguage);
	languageForm->ShowDialog();
	lLanguage = languageForm->lLanguage;
	checkLanguage();
	NovoModelo::Update();
}

System::Void LuccME::NovoModelo::sairToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Application::Exit();
}

System::Void LuccME::NovoModelo::sobreToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AboutForm^ aboutForm = gcnew AboutForm(lLanguage);
	aboutForm->ShowDialog();
}

System::Void LuccME::NovoModelo::novoToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (MessageBox::Show(gSNewModel, gSNewModelTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
		check = false;
	}
	if (check) {
		lReturn = 1;
		this->Close();
	}
}

System::Void LuccME::NovoModelo::abrirToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (MessageBox::Show(gSNewModel, gSOpenModelTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
		check = false;
	}
	if (check) {
		lReturn = 2;
		this->Close();
	}
}

System::Void LuccME::NovoModelo::luccMEToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		Help::ShowHelp(this, "help.chm");
	}
	else {
		Help::ShowHelp(this, "ajuda.chm");
	}
}

System::Void LuccME::NovoModelo::NovoModelo_FormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e)
{
	if (!closing) {
		if (tModelName->ForeColor == System::Drawing::Color::Black || tStartTime->ForeColor == System::Drawing::Color::Black ||
			tEndTime->ForeColor == System::Drawing::Color::Black || tThemeName->ForeColor == System::Drawing::Color::Black ||
			tCellArea->ForeColor == System::Drawing::Color::Black || tOutputTheme->ForeColor == System::Drawing::Color::Black ||
			lSelectedFolder->Text != "" || lLUNDShow->Text != "" || lLUTShow->Text != "" || lYearsToSave->Text != "" || lAttrToSave->Text != "" ||
			tbSelectedBatabase->Lines->Length > 0 || tbDemand->Lines->Length > 0 || tbPotential->Lines->Length > 0 || tbAllocation->Lines->Length > 0) {
			if (MessageBox::Show(gSExit, gSExitTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
				e->Cancel = true;
			}
		}
	}
}

System::Void LuccME::NovoModelo::cDynamicVariables_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (cDynamicVariables->Checked == true) {
		lAnosVariaveis->Visible = true;
		lAtualizaveis->Visible = true;
		lvYearsDynamic->Visible = true;
		bDynamicSelect->Visible = true;
		lDynamicConfirm->Visible = true;
	}
	else {
		lAnosVariaveis->Visible = false;
		lAtualizaveis->Visible = false;
		lvYearsDynamic->Visible = false;
		bDynamicSelect->Visible = false;
		lDynamicConfirm->Visible = false;
	}
}

System::Void LuccME::NovoModelo::bDynamicSelect_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	lDynamicConfirm->Text = "";
	for (int i = 0; i < lvYearsDynamic->Items->Count; i++) {
		if (lvYearsDynamic->Items[i]->Selected) {
			lDynamicConfirm->Text += lvYearsDynamic->Items[i]->Text + ", ";
		}
	}
	if (lDynamicConfirm->Text != "") {
		lDynamicConfirm->Text = lDynamicConfirm->Text->Substring(0, lDynamicConfirm->Text->Length - 2);
	}
	gDynTime = Convert::ToInt16(tEndTime->Text) - Convert::ToInt16(tStartTime->Text);
}

System::Void LuccME::NovoModelo::cScenario_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (cScenario->Checked == true) {
		lScenariosStartTime->Visible = true;
		tScenariosStartTime->Visible = true;
		lScenarioName->Visible = true;
		tScenarioName->Visible = true;
	}
	else {
		lScenariosStartTime->Visible = false;
		tScenariosStartTime->Visible = false;
		lScenarioName->Visible = false;
		tScenarioName->Visible = false;
	}
}

System::Void LuccME::NovoModelo::bValidate_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	String^ path = "validation.lua";
	StreamWriter^ sw = File::CreateText(path);

	sw->WriteLine("error = function(message, code)");
	sw->WriteLine("print(message)");
	sw->WriteLine("local answer");
	sw->WriteLine("repeat");
	sw->WriteLine("io.write(\"\\nPress enter key to exit...\")");
	sw->WriteLine("io.flush()");
	sw->WriteLine("answer = io.read()");
	sw->WriteLine("until answer ~= \"`\"");
	sw->WriteLine("os.exit()");
	sw->WriteLine("end");
	sw->WriteLine("");
	sw->WriteLine("numberOfWindows = 20");
	sw->WriteLine("");
	sw->WriteLine("input_theme_name = \"" + tInputThemeName->Text + "\"");
	sw->WriteLine("last_sim = \"" + tAttributeForValidation->Text + "\"");
	sw->WriteLine("init_real = \"" + tAttributeInitValidation->Text + "\"");
	sw->WriteLine("last_real = \"" + tAttributeFinalValidation->Text + "\"");
	sw->WriteLine("");
	if (access) {
		sw->WriteLine("cs = CellularSpace {database = \"" + tbSelectedBatabase->Lines[1]->ToString()->Replace("\\", "\\\\") + "\", theme = input_theme_name}");
	}
	else {
		sw->WriteLine("cs = CellularSpace {" + tbSelectedBatabase->Lines[1]->ToString() + ",");
		sw->WriteLine(tbSelectedBatabase->Lines[2]->ToString() + ",");
		sw->WriteLine(tbSelectedBatabase->Lines[3]->ToString() + ",");
		sw->WriteLine(tbSelectedBatabase->Lines[4]->ToString() + ",");
		sw->WriteLine("theme = input_theme_name\n}");
	}
	sw->WriteLine("");
	sw->WriteLine("flag_save = true");
	sw->WriteLine("output_theme = \"validation\"");
	sw->WriteLine("attribute1 = \"sim\"");
	sw->WriteLine("attribute2 = \"real\"");
	sw->WriteLine("");
	sw->WriteLine("if cs.cells[1][init_real]== nil then error(\"Attribute: \"..init_real..\". Does not exist in the theme.\") end");
	sw->WriteLine("if cs.cells[1][last_real]== nil then error(\"Attribute: \"..last_real..\". Does not exist in the theme.\") end");
	sw->WriteLine("if cs.cells[1][last_sim]== nil then	error(\"Attribute: \"..last_real..\".Does not exist in the theme\") end");
	sw->WriteLine("");
	sw->WriteLine("forEachCell(cs, function(cell) ");
	sw->WriteLine("cell[attribute1] = cell[last_sim] - cell[init_real]");
	sw->WriteLine("cell[attribute2] = cell[last_real]- cell[init_real]");
	sw->WriteLine("end)");
	sw->WriteLine("");
	sw->WriteLine("MultiRes = function(cs1, attribute1, cs2, attribute2, window)");
	sw->WriteLine("forEachCell(cs2, function(cell)	cell.flag = 0 end)");
	sw->WriteLine("local count = 0");
	sw->WriteLine("local diff = 0");
	sw->WriteLine("local sum = 0");
	sw->WriteLine("local cc1 = {}");
	sw->WriteLine("local cc2 = {}");
	sw->WriteLine("local internalcount = 0");
	sw->WriteLine("");
	sw->WriteLine("forEachCell(cs2, function(cell)");
	sw->WriteLine("internalcount = 0");
	sw->WriteLine("sumcc1 = 0");
	sw->WriteLine("sumcc2 = 0");
	sw->WriteLine("");
	sw->WriteLine("if cell.flag == 0 then");
	sw->WriteLine("for xx = 0, (window - 1) do");
	sw->WriteLine("for yy = 0, (window - 1) do");
	sw->WriteLine("if cs1:getCell(cell.x+xx, cell.y+yy) ~= nil then");
	sw->WriteLine("internalcount = internalcount + 1");
	sw->WriteLine("cc1[internalcount] = cs1:getCell(cell.x+xx, cell.y+yy)");
	sw->WriteLine("cc2[internalcount] = cs2:getCell(cell.x+xx, cell.y+yy)");
	sw->WriteLine("end");
	sw->WriteLine("end");
	sw->WriteLine("end");
	sw->WriteLine("");
	sw->WriteLine("for j = 1, internalcount do");
	sw->WriteLine("sumcc1 = sumcc1 + cc1[j][attribute1]");
	sw->WriteLine("sumcc2 = sumcc2 + cc2[j][attribute2]");
	sw->WriteLine("end");
	sw->WriteLine("");
	sw->WriteLine("diffcell = (sumcc2 - sumcc1)");
	sw->WriteLine("count = count + internalcount");
	sw->WriteLine("");
	sw->WriteLine("for i = 1, internalcount do");
	sw->WriteLine("cc2[i][\"diff\"..window] = diffcell");
	sw->WriteLine("cc2[i].flag = 1");
	sw->WriteLine("end");
	sw->WriteLine("");
	sw->WriteLine("sum = sum + sumcc2");
	sw->WriteLine("diff = diff + math.abs(diffcell)");
	sw->WriteLine("return true");
	sw->WriteLine("end");
	sw->WriteLine("end)");
	sw->WriteLine("return count, diff, sum");
	sw->WriteLine("end");
	sw->WriteLine("");
	sw->WriteLine("print(\"\\nSimulation Results - Sucess Allocated Cells (%):\\n\")");
	sw->WriteLine("io.flush()");
	sw->WriteLine("attrs = {}");
	sw->WriteLine("");
	sw->WriteLine("for i = 1, numberOfWindows do");
	sw->WriteLine("attrs[i]=\"diff\"..i");
	sw->WriteLine("total,diff,sum = MultiRes(cs, attribute1, cs, attribute2, i)");
	sw->WriteLine("");
	sw->WriteLine("if (sum < diff) then");
	sw->WriteLine("total,diff,sum = MultiRes(cs, attribute2, cs, attribute1, i)");
	sw->WriteLine("end");
	sw->WriteLine("");
	sw->WriteLine("if (sum == 0) then sum = 0.00001 end");
	sw->WriteLine("print (i, 1 - (diff/(2*sum)))");
	sw->WriteLine("io.flush()");
	sw->WriteLine("end");
	sw->WriteLine("");
	sw->WriteLine("attrs[numberOfWindows+1] = attribute1");
	sw->WriteLine("attrs[numberOfWindows+2] = attribute2");
	sw->WriteLine("");
	sw->WriteLine("if (flag_save) then cs:save(1, output_theme, attrs ) end");
	sw->WriteLine("print(\"\\nEnd of Validation\")");
	sw->WriteLine("local answer");
	sw->WriteLine("repeat");
	sw->WriteLine("io.write(\"\\nPress enter key to exit...\")");
	sw->WriteLine("io.flush()");
	sw->WriteLine("answer = io.read()");
	sw->WriteLine("until answer ~= \"`\"");

	sw->Close();

	String^ arguments = "validation.lua";
	System::Diagnostics::Process^ cmd = gcnew System::Diagnostics::Process;
	cmd->StartInfo->FileName = "C:\\LuccME\\TerraME\\bin\\TerraME.exe";
	cmd->StartInfo->Arguments = arguments;
	cmd->Start();
	cmd->WaitForExit();
	cmd->Close();

	if (File::Exists(path))
	{
		File::Delete(path);
	}
}

#include "stdafx.h"
#include "NovoModelo.h"
#include "LUTForm.h"
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
#include "LUND.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/*
Define all the used Strings, for portuguese and english.
*/
System::Void LuccME::NovoModelo::checkLanguage()
{
	//Handles with Discrete or Continuous Component selection (enable or disable buttons)
	if (gPotentialComponent > NUMDISCPOTCOMP || gAllocationComponent > NUMDISCALLOCCOMP) {
		bPotDiscrete->Enabled = false;
		bAllocDiscrete->Enabled = false;
		bPotContinuous->Enabled = true;
		bAllocContinuous->Enabled = true;
	}
	else if ((gPotentialComponent > 0 && gPotentialComponent <= NUMDISCPOTCOMP) || (gAllocationComponent > 0 && gAllocationComponent <= NUMDISCALLOCCOMP)) {
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

	//Select Strings according to the selected language
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
		tabDefModel->Text = "Model Definitions";
		tabDefSpatial->Text = "Spatial Definitions";
		tabLUT->Text = "Land Use Types";
		tabComponent->Text = "Components";
		tabSaveParam->Text = "Parameters to Save";
		tabFileMaker->Text = "Files Maker";
		tabAdvRes->Text = "Advanced Resources";
		tabValidation->Text = "Validation";
		//tabDefModel
		lArquivos->Text = "     Files";
		lDirProj->Text = "Folder to Save the Model";
		bSelectFolder->Text = "Select";
		lDefinicoesModelo->Text = "   Model Definitions";
		lModelName->Text = "Model Name";
		lStartTime->Text = "Start Time";
		lEndTime->Text = "End Time";
		//tabDefSpatial
		lSpacialDimensions->Text = " Spatial Definitions";
		lDatabase->Text = "File:";
		bSelectDatabase->Text = "Select";
		lThemeName->Text = "Layer Name";
		lCellArea->Text = "Cell Area";
		lTerraview->Text = "Terraview Project";
		//tabLUT
		lLUTLarge->Text = "     Land Use Types";
		lLUTMedium->Text = "Land Use Types";
		bLUTManager->Text = "Manager";
		lLUND->Text = "Land Use No Data";
		bLUNDManager->Text = "Manager";
		//tabComponent
		lComponentes->Text = "   Select the Components";
		lDemand->Text = "Demand ";
		lPotential->Text = "Potential";
		lAllocation->Text = "Allocation";
		bPotDiscrete->Text = "Discrete Components";
		bPotContinuous->Text = "Continuous Components";
		bAllocDiscrete->Text = "Discrete Components";
		bAllocContinuous->Text = "Continuous Components";
		//tabSaveParam
		lSalvar->Text = "Save";
		lOutputTheme->Text = "Ouput Theme Name";
		cSaveYearly->Text = "Yearly Save";
		lSelectYears->Text = "     Years to Save";
		bSelectedYears->Text = "Select";
		lSaveAttr->Text = "      Attributes to Save";
		bSelectedAttr->Text = "Select";
		lSaidaAdicionais->Text = "Aditional Outputs";
		cPot->Text = "Potential";
		cChange->Text = "Change";
		cReg->Text = "Regression";
		cAuxOut->Text = "Auxilary";
		//tabFileMaker
		lFileMaker->Text = "       Files Maker";
		bGerarArquivos->Text = "Make Files";
		lRunModel->Text = "       Run Model";
		bRun->Text = "Run Model";
		//tabAdvRes
		cDynamicVariables->Text = "Dynamic Variables";
		lAnosVariaveis->Text = "Years with variables";
		lAtualizaveis->Text = "     to be Updated";
		bDynamicSelect->Text = "Select";
		cScenario->Text = "Scenario";
		lScenariosStartTime->Text = "    Scenario Start Time";
		lScenarioName->Text = "  Scenario Name";
		lScenarioYears->Text = "Years with Scenario";
		//tabValidation
		lValidationMethod->Text = "Validation/Calibration Method";
		lInputThemeName->Text = "  Theme Name";
		lAttributeForValidation->Text = "Attribute for Validation";
		lAttributeFinalValidation->Text = "Real Final Attribute";
		lAttributeInitValidation->Text = "Initial Attribute";
		lRange->Text = "   % Allowed Error per Cell";
		lNumbWindows->Text = "Number of Windows";
		lSimResult->Text = "   Simulated Result";
		lThemeHelp->Text = "Output Model Theme Name";
		cValidationSave->Location = Point(265, 320);
		cValidationSave->Text = "Save into Database";
		bValidate->Text = "Validate";
		cSaveValidationFile->Text = "Save Validation Files";
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
		gSProject = "Project File";
		gSDBTitle = "Select a Database File";
		gSDBFilter = "Terraview Project (*.tview)|*.tview";
		gSShape = "Shape File";
		gSShapeTitle = "Select a Shape File";
		gSShapeFilter = "Shape File (*.shp)|*.shp";
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
		gSScenSYU = "The scenario years to update musb be informed.";
		gSScenSYUTitle = "Error - Scenario Update Year";
		gSValSectMet = "A Validation/Calibration must be selected.";
		gSValSectMetTitle = "Error - Validation/Calibration Method Not Selected";
		gSValExt = "print(\"Hit percentage CONSIDERING THE STANDARD ARISING in each window:\\n\")";
		gSValDiff = "print(\"Hit percentage CONSIDERING THE CHANGES in each window:\\n\")";
		gSAttribToSave = "Attribute to be save not defined in Save.\nSelect one of the options.";
		gSAttribToSaveTitle = "Error - Attribute to be save not defined";
		gSPotCont2Info = "The Land Uses Types changes.\nAll the data will be erased.\nDo you want to proceed?";
		gSPotCont2Title = "Warning - Land Use Changes";
		gSMainImportOld = "Main file vesrion 2.x imported with sucess.\nSelect the Submodel File.";
		gSMainImportOldtTitle = "Main File v2.x Loaded, Select Submodel";
		gSFileMissing = "Error writing the main File.\nCheck the path:";
		gSFileMissing2 = "Error writing the submodel File.\nCheck the path:";
		gSFileMissingTitle = "Make Files Error";
		//Combo Box
		cbValidationMethod->Items->Clear();
		cbValidationMethod->Items->Add("Multiresolution for Whole Area (ext)");
		cbValidationMethod->Items->Add("Multiresolution for Modified Area (diff)");
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
		tabDefModel->Text = "Definições do Modelo";
		tabDefSpatial->Text = "Definições Espaciais";
		tabLUT->Text = "Tipos de Uso da Terra";
		tabComponent->Text = "Componentes";
		tabSaveParam->Text = "Salvar Parâmetros";
		tabFileMaker->Text = "Gerar Arquivos";
		tabAdvRes->Text = "Recursos Avançados";
		//tabDefModel
		lArquivos->Text = "Arquivos";
		lDirProj->Text = "Pasta para Salvar o Modelo";
		bSelectFolder->Text = "Selecionar";
		lDefinicoesModelo->Text = "Definições do Modelo";
		lModelName->Text = "Nome do Modelo";
		lStartTime->Text = "Ano de Início";
		lEndTime->Text = "Ano de Término";
		//tabDefSpatial
		lSpacialDimensions->Text = "Definições Espaciais";
		lDatabase->Text = "Arquivo:";
		bSelectDatabase->Text = "Selecionar";
		lThemeName->Text = "Nome da Camada";
		lCellArea->Text = "Tamanho da Célula";
		lTerraview->Text = "Projeto Terraview";
		//tabLUT
		lLUTLarge->Text = "Tipos de Uso da Terra";
		lLUTMedium->Text = "Tipos de Uso da Terra";
		bLUTManager->Text = "Gerenciar";
		lLUND->Text = "Tipo de Uso com \"No Data\"";
		bLUNDManager->Text = "Gerenciar";
		//tabComponent
		lComponentes->Text = "Selecione os Componentes";
		lDemand->Text = "Demanda";
		lPotential->Text = "Potencial";
		lAllocation->Text = " Alocação";
		bPotDiscrete->Text = "Componentes Discretos";
		bPotContinuous->Text = "Componentes Contínuos";
		bAllocDiscrete->Text = "Componentes Discretos";
		bAllocContinuous->Text = "Componentes Contínuos";
		//tabSaveParam
		lSalvar->Text = "Salvar";
		lOutputTheme->Text = "Nome do Tema de Saída";
		cSaveYearly->Text = "Salvar Anualmente";
		lSelectYears->Text = "Anos a serem Salvos";
		bSelectedYears->Text = "Selecionar";
		lSaveAttr->Text = "Atributos a serem Salvos";
		bSelectedAttr->Text = "Selecionar";
		lSaidaAdicionais->Text = "Saídas Adicionais";
		cPot->Text = "Potencial";
		cChange->Text = "Mudança";
		cReg->Text = "Regressão";
		cAuxOut->Text = "Auxiliares";
		//tabFileMaker
		lFileMaker->Text = "Gerar os Arquivos";
		bGerarArquivos->Text = "Gerar Arquivos";
		lRunModel->Text = "Rodar o Modelo";
		bRun->Text = "Rodar Modelo";
		//tabAdvRes
		cDynamicVariables->Text = "Variáveis Dinamicas";
		lAnosVariaveis->Text = "Anos com Variáveis";
		lAtualizaveis->Text = "a serem Atualizadas";
		bDynamicSelect->Text = "Selecionar";
		cScenario->Text = "Cenário";
		lScenariosStartTime->Text = "Ano de Início do Cenário";
		lScenarioName->Text = "Nome de Cenário";
		lScenarioYears->Text = "Anos com Cenário";
		//tabValidation
		lValidationMethod->Text = "Método de Validação/Calibração";
		lInputThemeName->Text = "Nome do Tema";
		lAttributeForValidation->Text = "Atributo a ser Validado";
		lAttributeFinalValidation->Text = "Atributo Real Final";
		lAttributeInitValidation->Text = "Atributo Inicial";
		lRange->Text = "% Erro Permitido por Célula";
		lNumbWindows->Text = " Número de Janelas";
		lSimResult->Text = "Resultado Simulado";
		lThemeHelp->Text = "Tema de Saída do Modelo";
		cValidationSave->Location = Point(240, 320);
		cValidationSave->Text = "Salvar no Banco de Dados";
		bValidate->Text = "Validar";
		cSaveValidationFile->Text = "Salvar os Arquivos de Validação";
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
		gSProject = "Arquivo do Projeto";
		gSDBTitle = "Escolha o arquivo do Bando de Dados";
		gSDBFilter = "Projeto Terraview (*.tview)|*.tview";
		gSShape = "Arquivo Shape";
		gSShapeTitle = "Escolha o arquivo Shape";
		gSShapeFilter = "Arquivo Shape (*.shp)|*.shp";
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
		gSScenSYU = "O(s) ano(s) de atualização do cenário deve(m) ser informado(s).";
		gSScenSYUTitle = "Erro - Atualização Cenário";
		gSValSectMet = "Um Método de Validação/Calibração deve ser selecionado.";
		gSValSectMetTitle = "Erro - Nenhum Método de Validação/Calibração selecionado";
		gSValExt = "print(\"Porcentagem de acertos CONSIDERANDO O PADRAO RESULTANTE em cada janela:\\n\")";
		gSValDiff = "print(\"Porcentagem de acertos DE MUDANCA em cada janela:\\n\")";
		gSAttribToSave = "Os atributos a serem salvos não foram definidos em Salva Parâmetros.\nSelecione uma das opções.";
		gSAttribToSaveTitle = "Error - Atributos a serem salvos não definidos";
		gSPotCont2Info = "Os Tipos de Uso da Terra mudaram.\nTodos os dados serão apagados.\nDeseja continuar?";
		gSPotCont2Title = "Aviso - Mudança dos Tipos de Uso da Terra";
		gSMainImportOld = "Arquivo Main versão 2.x importado com sucesso.\nSelecione o Arquivo do Submodelo.";
		gSMainImportOldtTitle = "Arquivo Main v2.x Carregado, Selecione o Submodelo";
		gSFileMissing = "Erro na gravação do arquivo Principal.\nVerifique o caminho:";
		gSFileMissing2 = "Erro na gravação do arquivo de Sub-Modelo.\nVerifique o caminho:";
		gSFileMissingTitle = "Erro na geração dos Arquivos";
		//Combo Box
		cbValidationMethod->Items->Clear();
		cbValidationMethod->Items->Add("Multiresolução de Toda a Área (ext)");
		cbValidationMethod->Items->Add("Multiresolução das Áreas onde Houveram Mudanças (dif)");
	}
}

System::Void LuccME::NovoModelo::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	//Create the efect of a edited TextBox (must select this function on focus->enter property of a TextBox)
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

/*
Count a number of a caracter on a String
*/
System::Int16 LuccME::NovoModelo::countCaracter(String^ source, char caracter)
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
This funtion create the visual return on the multiline textbox for the Linear Regression component
*/
System::Void LuccME::NovoModelo::showReturnLinearRegression()
{
	int count = countCaracter(gPotential, '*');
	int lineCount = 0;
	int regression = 0;
	int nLut = countCaracter(gPotentialLUT, ',') + 1;

	array<String^>^ lines = gcnew array<String^>(count + 1);

	lines[lineCount] = "PotentialCLinearRegression";
	lineCount = 1;
	regression = 0;
	bool first = true;
	for (int i = 0; i < gPotential->Length; i++) {
		if (gPotential[i] != '#') {
			if (gPotential[i] != '*') {
				if (gPotential[i] != ';') {
					lines[lineCount + regression] += gPotential[i];
				}
				else {
					if (first) {
						lines[lineCount + regression] += "$";
						first = false;
					}
					else {
						lines[lineCount + regression] += gPotential[i];
					}
				}
			}
			else {
				if ((i + 1) <  gPotential->Length) {
					if (gPotential[i + 1] != '#') {
						regression += nLut;
						first = true;
					}
				}
			}
		}
		else {
			int controlLoop;
			if (gPotentialRegression == 1) {
				controlLoop = 1;
			}
			else {
				controlLoop = gPotentialRegression * nLut;
			}

			for (int j = 0; j < controlLoop; j += nLut) {
				if (lines[lineCount + j][0] == '0') {
					lines[lineCount + j] = String::Concat("false", lines[lineCount + j]->Substring(1));
				}
				else {
					lines[lineCount + j] = String::Concat("true", lines[lineCount + j]->Substring(1));
				}
				lines[lineCount + j] = String::Concat("isLog=", lines[lineCount + j]);
				lines[lineCount + j] = lines[lineCount + j]->Replace("$", ",const=");
				lines[lineCount + j] = lines[lineCount + j]->Replace(";", ",betas={");
				lines[lineCount + j] = lines[lineCount + j]->Replace("=", " = ");
				lines[lineCount + j] = lines[lineCount + j]->Replace(",", ", ");
				lines[lineCount + j] = lines[lineCount + j] = String::Concat(lines[lineCount + j], "}");
			}
			regression = 0;
			lineCount++;
			first = true;
		}

	}

	if (lines[lineCount] != "") {
		int controlLoop;
		if (gPotentialRegression == 1) {
			controlLoop = 1;
		}
		else {
			controlLoop = gPotentialRegression * nLut;
		}

		for (int j = 0; j < controlLoop; j += nLut) {
			if (lines[lineCount + j][0] == '0') {
				lines[lineCount + j] = String::Concat("false", lines[lineCount + j]->Substring(1));
			}
			else {
				lines[lineCount + j] = String::Concat("true", lines[lineCount + j]->Substring(1));
			}
			lines[lineCount + j] = String::Concat("isLog=", lines[lineCount + j]);
			lines[lineCount + j] = lines[lineCount + j]->Replace("$", ",const=");
			lines[lineCount + j] = lines[lineCount + j]->Replace(";", ",betas={");
			lines[lineCount + j] = lines[lineCount + j]->Replace("=", " = ");
			lines[lineCount + j] = lines[lineCount + j]->Replace(",", ", ");
			lines[lineCount + j] = lines[lineCount + j] = String::Concat(lines[lineCount + j], "}");
		}
	}

	tbPotential->Lines = lines;
}

/*
This funtion create the visual return on the multiline textbox for the SpatialLag Regression component
*/
System::Void LuccME::NovoModelo::showReturnSpatialLagRegression()
{
	int count = countCaracter(gPotential, '*');
	int lineCount = 0;
	int regression = 0;
	int nLut = countCaracter(gPotentialLUT, ',') + 1;

	array<String^>^ lines = gcnew array<String^>(count + 1);

	lines[lineCount] = "PotentialCSpatialLagRegression";
	lineCount = 1;
	regression = 0;
	int change = 0;

	for (int i = 0; i < gPotential->Length; i++) {
		if (gPotential[i] != '#') {
			if (gPotential[i] != '*') {
				if (gPotential[i] != ';') {
					lines[lineCount + regression] += gPotential[i];
				}
				else {
					switch (change)
					{
					case 0:
						lines[lineCount + regression] += "$";
						change++;
						break;

					case 1:
						lines[lineCount + regression] += "@";
						change++;
						break;

					case 2:
						lines[lineCount + regression] += "%";
						change++;
						break;

					case 3:
						lines[lineCount + regression] += "&";
						change++;
						break;
					default:
						lines[lineCount + regression] += gPotential[i];
						break;
					}
				}
			}
			else {
				if ((i + 1) <  gPotential->Length) {
					if (gPotential[i + 1] != '#') {
						regression += nLut;
						change = 0;
					}
				}
			}
		}
		else {
			int controlLoop;
			if (gPotentialRegression == 1) {
				controlLoop = 1;
			}
			else {
				controlLoop = gPotentialRegression * nLut;
			}

			for (int j = 0; j < controlLoop; j += nLut) {
				if (lines[lineCount + j][0] == '0') {
					lines[lineCount + j] = String::Concat("false", lines[lineCount + j]->Substring(1));
				}
				else {
					lines[lineCount + j] = String::Concat("true", lines[lineCount + j]->Substring(1));
				}
				lines[lineCount + j] = String::Concat("isLog=", lines[lineCount + j]);
				lines[lineCount + j] = lines[lineCount + j]->Replace("$", ",const=");
				lines[lineCount + j] = lines[lineCount + j]->Replace("@", ",minReg=");
				lines[lineCount + j] = lines[lineCount + j]->Replace("%", ",maxReg=");
				lines[lineCount + j] = lines[lineCount + j]->Replace("&", ",ro=");
				lines[lineCount + j] = lines[lineCount + j]->Replace(";", ",betas={");
				lines[lineCount + j] = lines[lineCount + j]->Replace("=", " = ");
				lines[lineCount + j] = lines[lineCount + j]->Replace(",", ", ");
				lines[lineCount + j] = lines[lineCount + j] = String::Concat(lines[lineCount + j], "}");
				change = 0;
			}
			regression = 0;
			lineCount++;
		}

	}

	if (lines[lineCount] != "") {
		int controlLoop;
		if (gPotentialRegression == 1) {
			controlLoop = 1;
		}
		else {
			controlLoop = gPotentialRegression * nLut;
		}

		for (int j = 0; j < controlLoop; j += nLut) {
			if (lines[lineCount + j][0] == '0') {
				lines[lineCount + j] = String::Concat("false", lines[lineCount + j]->Substring(1));
			}
			else {
				lines[lineCount + j] = String::Concat("true", lines[lineCount + j]->Substring(1));
			}
			lines[lineCount + j] = String::Concat("isLog=", lines[lineCount + j]);
			lines[lineCount + j] = lines[lineCount + j]->Replace("$", ",const=");
			lines[lineCount + j] = lines[lineCount + j]->Replace("@", ",minReg=");
			lines[lineCount + j] = lines[lineCount + j]->Replace("%", ",maxReg=");
			lines[lineCount + j] = lines[lineCount + j]->Replace("&", ",ro=");
			lines[lineCount + j] = lines[lineCount + j]->Replace(";", ",betas={");
			lines[lineCount + j] = lines[lineCount + j]->Replace("=", " = ");
			lines[lineCount + j] = lines[lineCount + j]->Replace(",", ", ");
			lines[lineCount + j] = lines[lineCount + j] = String::Concat(lines[lineCount + j], "}");
		}
	}

	tbPotential->Lines = lines;
}

/*
This funtion create the visual return on the multiline textbox for the SpatialLag Linear Roads component
*/
System::Void LuccME::NovoModelo::showReturnSpatialLagLinearRoads()
{
	int count = countCaracter(gPotential, '*');
	int lineCount = 0;
	int regression = 0;
	int nLut = countCaracter(gPotentialLUT, ',') + 1;

	array<String^>^ lines = gcnew array<String^>(count + 1);

	lines[lineCount] = "PotentialCSpatialLagLinearRegressionMix";
	lineCount = 1;
	int change = 0;

	for (int i = 0; i < gPotential->Length; i++) {
		if (gPotential[i] != '#') {
			if (gPotential[i] != ';') {
				lines[lineCount] += gPotential[i];
			}
			else {
				switch (change)
				{
				case 0:
					lines[lineCount] += "$";
					change++;
					break;

				case 1:
					lines[lineCount] += "@";
					change++;
					break;

				case 2:
					lines[lineCount] += "%";
					change++;
					break;

				case 3:
					lines[lineCount] += "&";
					change++;
					break;

				case 4:
					lines[lineCount] += "!";
					change++;
					break;

				case 5:
					lines[lineCount] += "£";
					change++;
					break;

				case 6:
					lines[lineCount] += "¢";
					change++;
					break;

				default:
					lines[lineCount] += gPotential[i];
					break;
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
			lines[lineCount] = String::Concat("isLog = ", lines[lineCount]);
			lines[lineCount] = lines[lineCount]->Replace("$", ",const=");
			lines[lineCount] = lines[lineCount]->Replace("@", ",minReg=");
			lines[lineCount] = lines[lineCount]->Replace("%", ",maxReg=");
			lines[lineCount] = lines[lineCount]->Replace("&", ",ro=");
			lines[lineCount] = lines[lineCount]->Replace("!", ",betas = {");
			lines[lineCount] = lines[lineCount]->Replace("*", "},roadsModel={ attrs={");;
			lines[lineCount] = lines[lineCount]->Replace("£", "},const=");
			lines[lineCount] = lines[lineCount]->Replace("¢", ",change=");
			lines[lineCount] = lines[lineCount]->Replace(";", ",betas={");
			lines[lineCount] = lines[lineCount]->Replace("=", " = ");
			lines[lineCount] = lines[lineCount]->Replace(",", ", ");
			lines[lineCount] = lines[lineCount] = String::Concat(lines[lineCount], "}}");
			lineCount++;
			change = 0;
		}
	}
	if (lines[lineCount] != "") {
		if (lines[lineCount][0] == '0') {
			lines[lineCount] = String::Concat("false", lines[lineCount]->Substring(1));
		}
		else {
			lines[lineCount] = String::Concat("true", lines[lineCount]->Substring(1));
		}
		lines[lineCount] = String::Concat("isLog = ", lines[lineCount]);
		lines[lineCount] = lines[lineCount]->Replace("$", ",const=");
		lines[lineCount] = lines[lineCount]->Replace("@", ",minReg=");
		lines[lineCount] = lines[lineCount]->Replace("%", ",maxReg=");
		lines[lineCount] = lines[lineCount]->Replace("&", ",ro=");
		lines[lineCount] = lines[lineCount]->Replace("!", ",betas = {");
		lines[lineCount] = lines[lineCount]->Replace("*", "},roadsModel={ attrs={");;
		lines[lineCount] = lines[lineCount]->Replace("£", "},const=");
		lines[lineCount] = lines[lineCount]->Replace("¢", ",change=");
		lines[lineCount] = lines[lineCount]->Replace(";", ",betas={");
		lines[lineCount] = lines[lineCount]->Replace("=", " = ");
		lines[lineCount] = lines[lineCount]->Replace(",", ", ");
		lines[lineCount] = lines[lineCount] = String::Concat(lines[lineCount], "}}");
	}
	tbPotential->Lines = lines;
}


/*
This funtion create the visual return on the multiline textbox for the "Distance Rule" components
*/
System::Void LuccME::NovoModelo::showReturnDistanceRule(String^ componentName)
{
	int count = countCaracter(gPotential, '*');
	int lineCount = 0;
	int regression = 0;
	int nLut = countCaracter(gPotentialLUT, ',') + 1;

	array<String^>^ lines = gcnew array<String^>(count + 1);

	lines[lineCount] = componentName;

	lineCount = 1;

	for (int i = 0; i < gPotential->Length; i++) {
		if (gPotential[i] != '#') {
			if (gPotential[i] != '*') {
				lines[lineCount + regression] += gPotential[i];
			}
			else {
				if ((i + 1) <  gPotential->Length) {
					if (gPotential[i + 1] != '#') {
						regression += nLut;
					}
				}
			}
		}
		else {
			int controlLoop;
			if (gPotentialRegression == 1) {
				controlLoop = 1;
			}
			else {
				controlLoop = gPotentialRegression * nLut;
			}

			for (int j = 0; j < controlLoop; j += nLut) {
				lines[lineCount + j] = String::Concat("const=", lines[lineCount + j]);
				lines[lineCount + j] = lines[lineCount + j]->Replace(";", ",betas={");
				lines[lineCount + j] = lines[lineCount + j]->Replace("=", " = ");
				lines[lineCount + j] = lines[lineCount + j]->Replace(",", ", ");
				lines[lineCount + j] = lines[lineCount + j] = String::Concat(lines[lineCount + j], "}");
			}
			lineCount++;
			regression = 0;
		}
	}
	if (lines[lineCount] != "") {
		int controlLoop;
		if (gPotentialRegression == 1) {
			controlLoop = 1;
		}
		else {
			controlLoop = gPotentialRegression * nLut;
		}

		for (int j = 0; j < controlLoop; j += nLut) {
			lines[lineCount + j] = String::Concat("const=", lines[lineCount + j]);
			lines[lineCount + j] = lines[lineCount + j]->Replace(";", ",betas={");
			lines[lineCount + j] = lines[lineCount + j]->Replace("=", " = ");
			lines[lineCount + j] = lines[lineCount + j]->Replace(",", ", ");
			lines[lineCount + j] = lines[lineCount + j] = String::Concat(lines[lineCount + j], "}");
		}
	}
	tbPotential->Lines = lines;
}

/*
This funtion create the visual return on the multiline textbox for the Logistic Regression component
*/
System::Void LuccME::NovoModelo::showReturnLogisticRegression()
{
	int count = countCaracter(gPotential, '*');
	int lineCount = 0;
	int regression = 0;
	int nLut = countCaracter(gPotentialLUT, ',') + 1;

	array<String^>^ lines = gcnew array<String^>(count + 1);

	lines[lineCount] = "PotentialDLogisticRegression";

	lineCount = 1;
	bool first = true;

	for (int i = 0; i < gPotential->Length; i++) {
		if (gPotential[i] != '#') {
			if (gPotential[i] != '*') {
				if (gPotential[i] != ';') {
					lines[lineCount + regression] += gPotential[i];
				}
				else {
					if (first) {
						lines[lineCount + regression] += "$";
						first = false;
					}
					else {
						lines[lineCount + regression] += gPotential[i];
					}
				}
			}
			else {
				if ((i + 1) <  gPotential->Length) {
					if (gPotential[i + 1] != '#') {
						regression += nLut;
						first = true;
					}
				}
			}
		}
		else {
			int controlLoop;
			if (gPotentialRegression == 1) {
				controlLoop = 1;
			}
			else {
				controlLoop = gPotentialRegression * nLut;
			}

			for (int j = 0; j < controlLoop; j += nLut) {
				lines[lineCount + j] = String::Concat("const=", lines[lineCount + j]);
				lines[lineCount + j] = lines[lineCount + j]->Replace("$", ",elasticity=");
				lines[lineCount + j] = lines[lineCount + j]->Replace(";", ",betas={");
				lines[lineCount + j] = lines[lineCount + j]->Replace("=", " = ");
				lines[lineCount + j] = lines[lineCount + j]->Replace(",", ", ");
				lines[lineCount + j] = lines[lineCount + j] = String::Concat(lines[lineCount + j], "}");
			}
			lineCount++;
			first = true;
			regression = 0;
		}
	}
	if (lines[lineCount] != "") {
		int controlLoop;
		if (gPotentialRegression == 1) {
			controlLoop = 1;
		}
		else {
			controlLoop = gPotentialRegression * nLut;
		}

		for (int j = 0; j < controlLoop; j += nLut) {
			lines[lineCount + j] = String::Concat("const=", lines[lineCount + j]);
			lines[lineCount + j] = lines[lineCount + j]->Replace("$", ",elasticity=");
			lines[lineCount + j] = lines[lineCount + j]->Replace(";", ",betas={");
			lines[lineCount + j] = lines[lineCount + j]->Replace("=", " = ");
			lines[lineCount + j] = lines[lineCount + j]->Replace(",", ", ");
			lines[lineCount + j] = lines[lineCount + j] = String::Concat(lines[lineCount + j], "}");
		}
	}
	tbPotential->Lines = lines;
}

/*
This funtion create the visual return on the multiline textbox for the Neigh Attraction Logistic Regression component
*/
System::Void LuccME::NovoModelo::showReturnNeighAttractionLogisticRegression()
{
	int count = countCaracter(gPotential, '*');
	int lineCount = 0;
	int regression = 0;
	int nLut = countCaracter(gPotentialLUT, ',') + 1;

	array<String^>^ lines = gcnew array<String^>(count + 1);

	lines[lineCount] = "PotentialDLogisticRegressionNeighAttract";

	lineCount = 1;

	bool first = true;
	bool second = true;

	for (int i = 0; i < gPotential->Length; i++) {
		if (gPotential[i] != '#') {
			if (gPotential[i] != '*') {
				if (gPotential[i] != ';') {
					lines[lineCount + regression] += gPotential[i];
				}
				else {
					if (first) {
						lines[lineCount + regression] += "$";
						first = false;
					}
					else if (second) {
						lines[lineCount + regression] += "@";
						second = false;
					}
					else {
						lines[lineCount + regression] += gPotential[i];
					}
				}
			}
			else {
				if ((i + 1) <  gPotential->Length) {
					if (gPotential[i + 1] != '#') {
						regression += nLut;
						first = true;
						second = true;
					}
				}
			}
		}
		else {
			int controlLoop;
			if (gPotentialRegression == 1) {
				controlLoop = 1;
			}
			else {
				controlLoop = gPotentialRegression * nLut;
			}

			for (int j = 0; j < controlLoop; j += nLut) {
				lines[lineCount + j] = String::Concat("const=", lines[lineCount + j]);
				lines[lineCount + j] = lines[lineCount + j]->Replace("$", ",elasticity=");
				lines[lineCount + j] = lines[lineCount + j]->Replace("@", ",percNeighborsUse=");
				lines[lineCount + j] = lines[lineCount + j]->Replace(";", ",betas={");
				lines[lineCount + j] = lines[lineCount + j]->Replace("=", " = ");
				lines[lineCount + j] = lines[lineCount + j]->Replace(",", ", ");
				lines[lineCount + j] = lines[lineCount + j] = String::Concat(lines[lineCount + j], "}");
			}
			lineCount++;
			first = true;
			second = true;
			regression = 0;
		}
	}
	if (lines[lineCount] != "") {
		int controlLoop;
		if (gPotentialRegression == 1) {
			controlLoop = 1;
		}
		else {
			controlLoop = gPotentialRegression * nLut;
		}

		for (int j = 0; j < controlLoop; j += nLut) {
			lines[lineCount + j] = String::Concat("const=", lines[lineCount + j]);
			lines[lineCount + j] = lines[lineCount + j]->Replace("$", ",elasticity=");
			lines[lineCount + j] = lines[lineCount + j]->Replace("@", ",percNeighborsUse=");
			lines[lineCount + j] = lines[lineCount + j]->Replace(";", ",betas={");
			lines[lineCount + j] = lines[lineCount + j]->Replace("=", " = ");
			lines[lineCount + j] = lines[lineCount + j]->Replace(",", ", ");
			lines[lineCount + j] = lines[lineCount + j] = String::Concat(lines[lineCount + j], "}");
		}
	}
	tbPotential->Lines = lines;
}

/*
This funtion create the visual return on the multiline textbox for the Maximum Entropy Like component
*/
System::Void LuccME::NovoModelo::showReturnMaxEntLike(String^ component)
{
	int count = countCaracter(gPotential, '#');
	int lineCount = 0;

	array<String^>^ lines = gcnew array<String^>(count + 1);

	lines[lineCount] = component;

	lineCount = 1;
	int change = 0;

	for (int i = 0; i < gPotential->Length; i++) {
		if (gPotential[i] != '#') {
			if (gPotential[i] != ';') {
				lines[lineCount] += gPotential[i];
			}
			else {
				switch (change)
				{
				case 0:
					lines[lineCount] += "$";
					change++;
					break;

				case 1:
					lines[lineCount] += "@";
					change++;
					break;

				default:
					lines[lineCount] += gPotential[i];
					break;
				}
			}
		}
		else {
			lines[lineCount] = String::Concat("cellUsePercentage=", lines[lineCount]);
			lines[lineCount] = lines[lineCount]->Replace("$", ",attributesPerc={");
			lines[lineCount] = lines[lineCount]->Replace("@", "},attributesClass={");
			lines[lineCount] = lines[lineCount]->Replace("=", " = ");
			lines[lineCount] = lines[lineCount]->Replace(",", ", ");
			lines[lineCount] = lines[lineCount] = String::Concat(lines[lineCount], "}}");
			lineCount++;
			change = 0;
		}
	}
	tbPotential->Lines = lines;
}

/*
This funtion create the visual return on the multiline textbox for the AttractiveRepulsiveLinearregression component
*/
System::Void LuccME::NovoModelo::showReturnARLR()
{
	int count = countCaracter(gPotential, '*');
	int countAffinity = countCaracter(gPotential, '%');
	int lineCount = 0;
	int regression = 0;
	int nLut = countCaracter(gPotentialLUT, ',') + 1;

	array<String^>^ lines = gcnew array<String^>(count + (countAffinity * nLut) + 2);

	lines[lineCount] = "PotentialDLogisticRegressionNeighAttractRepulsion";

	lineCount = 1;

	bool first = true;
	bool second = true;

	int i = 0;

	for (i = 0; i < gPotential->Length; i++) {
		if (gPotential[i] != '&'){
			if (gPotential[i] != '#') {
				if (gPotential[i] != '*') {
					if (gPotential[i] != ';') {
						lines[lineCount + regression] += gPotential[i];
					}
					else {
						if (first) {
							lines[lineCount + regression] += "$";
							first = false;
						}
						else if (second) {
							lines[lineCount + regression] += "@";
							second = false;
						}
						else {
							lines[lineCount + regression] += gPotential[i];
						}
					}
				}
				else {
					if ((i + 1) < gPotential->Length) {
						if (gPotential[i + 1] != '#') {
							regression += nLut;
							first = true;
							second = true;
						}
					}
				}
			}
			else {
				int controlLoop;
				if (gPotentialRegression == 1) {
					controlLoop = 1;
				}
				else {
					controlLoop = gPotentialRegression * nLut;
				}

				for (int j = 0; j < controlLoop; j += nLut) {
					lines[lineCount + j] = String::Concat("const=", lines[lineCount + j]);
					lines[lineCount + j] = lines[lineCount + j]->Replace("$", ",elasticity=");
					lines[lineCount + j] = lines[lineCount + j]->Replace("@", ",percNeighborsUse=");
					lines[lineCount + j] = lines[lineCount + j]->Replace(";", ",betas={");
					lines[lineCount + j] = lines[lineCount + j]->Replace("=", " = ");
					lines[lineCount + j] = lines[lineCount + j]->Replace(",", ", ");
					lines[lineCount + j] = lines[lineCount + j] = String::Concat(lines[lineCount + j], "}");
				}
				lineCount++;
				first = true;
				second = true;
				regression = 0;
			}
		}
		else {
			break;
		}
	}

	i++;
	if (gPotentialRegression > 1) {
		lineCount = (gPotentialRegression * nLut) + 1;
	}
	
	lines[lineCount] = "transitionMatrix=";
	lineCount++;
	for (i; i < gPotential->Length; i++) {
		if (gPotential[i] != ';') {
			if (gPotential[i] != ',') {
				if (gPotential[i] != '%') {
					lines[lineCount] += gPotential[i];
				}
				else {
					lineCount++;
				}
			}
			else {
				lines[lineCount] += ", ";
			}
		}
		else {
			lineCount++;
		}
	}

	tbPotential->Lines = lines;
}

System::Void LuccME::NovoModelo::bSelectFolder_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	//Open the dialog to select a folder and return the path
	LuccME::FolderBrowserDialog^ modelFolder = gcnew FolderBrowserDialog();

	if (modelFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		lSelectedFolder->Text = modelFolder->SelectedPath;
	}
}

System::Void LuccME::NovoModelo::bSelectDatabase_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	//Open the dialog to select the access database and return the path
	LuccME::OpenFileDialog^ bdFile = gcnew OpenFileDialog;
	bdFile->Title = gSDBTitle;
	bdFile->Multiselect = false;
	bdFile->Filter = gSDBFilter;
	bdFile->FilterIndex = 1;
	bdFile->ShowHelp = true;

	if (bdFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		gSelectedDatabase = bdFile->FileName;
		array<String^>^ lines = { gSProject, bdFile->FileName };
		tbSelectedBatabase->Lines = lines;
		shape = false;
		tThemeName->Enabled = true;
	}
}

System::Void LuccME::NovoModelo::bLUTManager_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cReturn^ lLandUses = gcnew cReturn();
	int nLUT = countCaracter(gLandUseTypes, ',') + 1;

	lLandUses->Return = gLandUseTypes;
	lLandUses->Language = lLanguage;

	array<String^>^ backupLUT = gLandUseTypes->Split(',');

	LuccME::LUTForm^ landUseTypeForm = gcnew LUTForm(lLandUses);
	landUseTypeForm->MinimizeBox = false;
	landUseTypeForm->MaximizeBox = false;
	landUseTypeForm->ShowInTaskbar = false;
	landUseTypeForm->ShowDialog();

	int nNLUT = countCaracter(lLandUses->Return, ',') + 1;

	if (nLUT < nNLUT) {
		nLUT = nNLUT;
	}

	array<String^>^ tempLandUses = gcnew array<String^>(nLUT);
	array<String^>^ tempNewLandUses = gcnew array<String^>(nLUT);

	tempLandUses = backupLUT;
	
	gLandUseTypes = lLandUses->Return;
	tempNewLandUses = gLandUseTypes->Split(',');

	bool equalUses = false;
	if (gLandUseTypes != "" && lLUTShow->Text != "") {
		equalUses = true;
		int count = 0;
		for (int i = 0; i < tempLandUses->Length; i++) {
			if (tempLandUses[i] != nullptr && tempNewLandUses[i] != nullptr) {
				if (tempLandUses[i]->ToLower() != tempNewLandUses[i]->ToLower()) {
					count++;
				}
			}
		}
		if (count > 1) {
			equalUses = false;
		}
	}

	if (equalUses) {
		gDemandLUT = gLandUseTypes;
		gAllocationLUT = gLandUseTypes;
		gPotentialLUT = gLandUseTypes;
		
		if (gAllocationComponent == ALLOCATIONCCLUELIKE || gAllocationComponent == ALLOCATIONCCLUELIKESATURATION) {
			array<String^>^ auxAllocation = tbAllocation->Text->Split('\n');
			String^ auxAllocationLine = auxAllocation[6];
			auxAllocationLine = auxAllocationLine->Replace("complementarLU = ", "");
			auxAllocationLine = auxAllocationLine->Replace("\n", "");
			auxAllocationLine = auxAllocationLine->Replace("\r", "");
			auxAllocationLine = "\"" + auxAllocationLine + "\"";
			for (int i = 0; i < backupLUT->Length; i++) {
				if (auxAllocationLine == backupLUT[i]) {
					gAllocation = gAllocation->Replace(";" + auxAllocationLine->Replace("\"", "") + ";", ";" + tempNewLandUses[i]->Replace("\"", "") + ";");
					auxAllocation[6] = "complementarLU = " + tempNewLandUses[i]->Replace("\"","");
					break;
				}
			}
			tbAllocation->Lines = auxAllocation;
		}
	}

	lLUTShow->Text = gLandUseTypes;
}

System::Void LuccME::NovoModelo::bLUNDManager_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cReturn^ lLandUsesNoData = gcnew cReturn();

	if (gLandUseTypes != "") {
		gLandUseNoData = gLandUseTypes;
	}
	lLandUsesNoData->Return = gLandUseNoData;
	lLandUsesNoData->Language = lLanguage;
	
	LuccME::LUND^ landUseTypeForm = gcnew LUND(lLandUsesNoData);
	landUseTypeForm->MinimizeBox = false;
	landUseTypeForm->MaximizeBox = false;
	landUseTypeForm->ShowInTaskbar = false;
	landUseTypeForm->ShowDialog();
	
	gLandUseNoData = lLandUsesNoData->Return;
	if (!(lLUNDShow->Text != "" && gLandUseNoData == "")) {
		lLUNDShow->Text = gLandUseNoData;
	}
}

System::Void LuccME::NovoModelo::bD_PCVINPE_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cReturnPCVINPE^ lDemand = gcnew cReturnPCVINPE();
	bool check = true;
	String^ rTempAux = "";

	if (gDemand == "" || gDemandLUT != gLandUseTypes || gDemandComponent != PCVINPE) {
		if (gDemandComponent != PCVINPE && gDemandComponent != NONE ) {
			if (MessageBox::Show(gSDemand1Info, gSDemand1Title, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::Yes) {
				rTempAux = gDemand;
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
		demandForm->MinimizeBox = false;
		demandForm->MaximizeBox = false;
		demandForm->ShowInTaskbar = false;
		demandForm->ShowDialog();

		gDemand = lDemand->Return;
		gDemand = gDemand->Replace("\n", "");
		gDemand = gDemand->Replace("\r", "");
		gDemandLUT = gLandUseTypes;
		
		if (gDemand != "") {
			int count = 0;
			
			count += countCaracter(gDemand, ';');
			
			array<String^>^ lines = gcnew array<String^>(count + 3); //If has 1 semicolon there are 2 values + header (2)
			String^ auxLine = "";

			lines[0] = "DemandPreComputedValues";
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
			gDemandComponent = PCVINPE;
		}
		else {
			gDemand = rTempAux;
		}
	}
}

System::Void LuccME::NovoModelo::bD_CITwoDM_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cReturnCITwoMP^ lDemand = gcnew cReturnCITwoMP();
	bool check = true;
	String^ rTempAux = "";

	if (gDemand == "" || gDemandLUT != gLandUseTypes || gDemandComponent != CITWODM) {
		if (gDemandComponent != CITWODM && gDemandComponent != NONE) {
			if (MessageBox::Show(gSDemand1Info, gSDemand1Title, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::Yes) {
				rTempAux = gDemand;
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
		demandForm->MinimizeBox = false;
		demandForm->MaximizeBox = false;
		demandForm->ShowInTaskbar = false;
		demandForm->ShowDialog();
		
		gDemand = lDemand->Return;
		gDemandLUT = gLandUseTypes;
		
		if (gDemand != "") {
			array<String^>^ lines = gcnew array<String^>(4);
			
			gDemandFinalYear = Convert::ToString(lDemand->FinalYear);
			lines[0] = "DemandComputeTwoDates";
			lines[1] = "finalYearForInterpolation = " + gDemandFinalYear;
			lines[2] = gDemandLUT;
			lines[3] = gDemand;

			tbDemand->Lines = lines;
			gDemandComponent = CITWODM;
		}
		else {
			gDemand = rTempAux;
		}
	}
}

System::Void LuccME::NovoModelo::bD_CIThreeDM_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cReturnCIThreeMP^ lDemand = gcnew cReturnCIThreeMP();
	bool check = true;
	String^ rTempAux = "";

	if (gDemand == "" || gDemandLUT != gLandUseTypes || gDemandComponent != CITHREEDM) {
		if (gDemandComponent != CITHREEDM && gDemandComponent != NONE) {
			if (MessageBox::Show(gSDemand1Info, gSDemand1Title, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::Yes) {
				rTempAux = gDemand;
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
		demandForm->MinimizeBox = false;
		demandForm->MaximizeBox = false;
		demandForm->ShowInTaskbar = false;
		demandForm->ShowDialog();

		gDemand = lDemand->Return;
		gDemandLUT = gLandUseTypes;
		
		if (gDemand != "") {
			array<String^>^ lines = gcnew array<String^>(6);

			gDemandFinalYear = Convert::ToString(lDemand->FinalYear);
			gDemandMiddleYear = Convert::ToString(lDemand->MiddleYear);
			lines[0] = "DemandComputeThreeDates";
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
			gDemandComponent = CITHREEDM;
		}
		else {
			gDemand = rTempAux;
		}
	}
}

System::Void LuccME::NovoModelo::bPotDiscrete_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (gAllocationComponent > NUMDISCALLOCCOMP) {
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
		lPotential->Regression = gPotentialRegression;
		
		PotDiscreteForm^ potDiscreteForm = gcnew PotDiscreteForm(lPotential);
		potDiscreteForm->MinimizeBox = false;
		potDiscreteForm->MaximizeBox = false;
		potDiscreteForm->ShowInTaskbar = false;
		potDiscreteForm->ShowDialog();
		
		gPotential = lPotential->Return;
		gPotential = gPotential->Replace("\n", "");
		gPotential = gPotential->Replace("\r", "");
		gPotentialComponent = lPotential->Component;
		gPotentialRegression = lPotential->Regression;
		gPotentialLUT = gLandUseTypes;

		int count = 2;
		int lineCount = 0;

		count += countCaracter(gPotentialLUT, ',');

		array<String^>^ lines = { "" };
		
		switch (lPotential->Component)
		{
		case POTENTIALDNEIGHSIMPLERULE:
			lines[0] = "PotentialDNeighSimpleRule{}";
			tbPotential->Lines = lines;
			break;

		case POTENTIALDNEIGHINVERSEDISTANCERULE:
			if (gPotential != "") {
				showReturnDistanceRule("PotentialDNeighInverseDistanceRule");
			}
			break;

		case POTENTIALDINVERSEDISTANCERULE:
			if (gPotential != "") {
				showReturnDistanceRule("PotentialDInverseDistanceRule");
			}
			break;

		case POTENTIALDLOGISTICREGRESSION:
			if (gPotential != "") {
				showReturnLogisticRegression();
			}
			break;

		case POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT:
			if (gPotential != "") {
				showReturnNeighAttractionLogisticRegression();
			}
			break;

		case POTENTIALDMAXIMUMENTROPYLIKE:
			if (gPotential != "") {
				showReturnMaxEntLike("PotentialDMaximumEntropyLike");
			}
			break;

		case POTENTIALDLOGISTICREGRESSIONNEIGHATTRACTREPULSION:
			if (gPotential != "") {
				showReturnARLR();
			}
		}
	}
	checkLanguage();
}

System::Void LuccME::NovoModelo::bPotContinuous_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;

	if (gAllocationComponent != NONE && gAllocationComponent <= NUMDISCALLOCCOMP) {
		if (MessageBox::Show(gSAlloDisc, gSPotContTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
	}

	if (gLandUseTypes == "") {
		MessageBox::Show(gSLUTNotDef, gSLUTNotDefTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = false;
	}

	if (gPotentialLUT != gLandUseTypes && gPotential != "") {
		if (MessageBox::Show(gSPotCont2Info, gSPotCont2Title, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::Yes) {
			gPotential = "";
		}
		else {
			check = false;
		}
	}

	if (check) {
		cReturnPotential^ lPotential = gcnew cReturnPotential();
		lPotential->Return = gPotential;
		lPotential->LUT = gLandUseTypes;
		lPotential->Component = gPotentialComponent;
		lPotential->Language = lLanguage;
		lPotential->Regression = gPotentialRegression;
		
		PotContinuousForm^ potContinuousForm = gcnew PotContinuousForm(lPotential);
		potContinuousForm->MinimizeBox = false;
		potContinuousForm->MaximizeBox = false;
		potContinuousForm->ShowInTaskbar = false;
		potContinuousForm->ShowDialog();
		
		gPotential = lPotential->Return;
		gPotentialComponent = lPotential->Component;
		gPotentialRegression = lPotential->Regression;
		gPotentialLUT = gLandUseTypes;
		
		switch (lPotential->Component)
		{
		case POTENTIALCLINEARREGRESSION:
			if (gPotential != "") {
				showReturnLinearRegression();
			}
			break;

		case POTENTIALCSPATIALLAGREGRESSION:
			if (gPotential != "") {
				showReturnSpatialLagRegression();
			}
			break;

		case POTENTIALCSPATIALLAGLINEARREGRESSIONMIX:
			if (gPotential != "") {
				showReturnSpatialLagLinearRoads();
			}
			break;

		case POTENTIALCMAXIMUMENTROPYLIKE:
			if (gPotential != "") {
				showReturnMaxEntLike("PotentialCMaximumEntropyLike");
			}
			break;
		}
	}
	checkLanguage();
}

System::Void LuccME::NovoModelo::bAllocDiscrete_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;

	if (gPotentialComponent > NUMDISCPOTCOMP) {
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
		allocationForm->MinimizeBox = false;
		allocationForm->MaximizeBox = false;
		allocationForm->ShowInTaskbar = false;
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
		case ALLOCATIONDSIMPLEORDERING:
			if (gAllocation != "") {
				lines[0] = "AllocationDSimpleOrdering";
				lines[1] = "maxDifference = " + lAllocation->Return;
				tbAllocation->Lines = lines;
			}
			break;

		case ALLOCATIONDCLUESNEIGHORDERING:
		case ALLOCATIONDCLUESLIKE:
			if (gAllocation != "") {
				if (lAllocation->Component == ALLOCATIONDCLUESLIKE) {
					lines2[0] = "AllocationDClueSLike";
				}
				else {
					lines2[0] = "AllocationDClueSNeighOrdering";
				}

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

	if (gPotentialComponent != 0 && gPotentialComponent <= NUMDISCALLOCCOMP) {
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
		allocationForm->MinimizeBox = false;
		allocationForm->MaximizeBox = false;
		allocationForm->ShowInTaskbar = false;
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
			if (gAllocationComponent == ALLOCATIONCCLUELIKESATURATION) {
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

			if (gAllocationComponent == ALLOCATIONCCLUELIKE)
			{
				lines[0] = "AllocationCClueLike";
				lines[7] = "allocationData";
				count = 8;
			}
			else if(gAllocationComponent == ALLOCATIONCCLUELIKESATURATION) {
				lines[0] = "AllocationCClueLikeSaturation";
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
	if (tNovoModelo->SelectedIndex == COMPONENT) {
		if (gPotentialComponent > NUMDISCPOTCOMP || gAllocationComponent > NUMDISCALLOCCOMP) {
			bPotDiscrete->Enabled = false;
			bAllocDiscrete->Enabled = false;
			bPotContinuous->Enabled = true;
			bAllocContinuous->Enabled = true;
		}
		else if ((gPotentialComponent > 0 && gPotentialComponent <= NUMDISCPOTCOMP) || (gAllocationComponent > 0 && gAllocationComponent <= NUMDISCALLOCCOMP)) {
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
	}

	if (tNovoModelo->SelectedIndex == SAVEPARAM) {
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

		if (tOutputTheme->ForeColor != System::Drawing::Color::Black) {
			tOutputTheme->Text = tModelName->Text + "_";
		}

		if (gPotentialComponent == POTENTIALCLINEARREGRESSION || gPotentialComponent == POTENTIALDLOGISTICREGRESSION || gPotentialComponent == POTENTIALCSPATIALLAGLINEARREGRESSIONMIX || gPotentialComponent == POTENTIALCSPATIALLAGREGRESSION) {
			cReg->Enabled = true;
		}
	}

	if (tNovoModelo->SelectedIndex == ADVRES) {
		int time = Convert::ToInt16(tEndTime->Text) - Convert::ToInt16(tStartTime->Text);
		int tempTime = Convert::ToInt16(tStartTime->Text);

		if (gDynTime != time) {
			lDynamicConfirm->Text = "";
		}
		
		lvYearsDynamic->Clear();
		lvYearsDynamic->View = View::Details;
		lvYearsDynamic->GridLines = true;
		lvYearsDynamic->Columns->Add(gSAnos, lvYearsDynamic->Width - 22, HorizontalAlignment::Center);

		lvYearScenario->Clear();
		lvYearScenario->View = View::Details;
		lvYearScenario->GridLines = true;
		lvYearScenario->Columns->Add(gSAnos, lvYearsDynamic->Width - 22, HorizontalAlignment::Center);

		for (int i = 0; i <= time; i++) {
			lvYearsDynamic->Items->Add(Convert::ToString(tempTime + i));
			lvYearScenario->Items->Add(Convert::ToString(tempTime + i));
		}

		if (shape && cScenario->Checked == true) {
			lScenarioYears->Visible = true;
			lvYearScenario->Visible = true;
			bScenario->Visible = true;
			lScenarioYearsConfirm->Visible = true;
		}
	}
	
	if (tNovoModelo->SelectedIndex == VALIDATION) {
		if (shape) {
			if (lLanguage == "en") {
				lInputThemeName->Text = "  Shape Name";
				lThemeHelp->Text = "Output Shape File Name";
			}
			else {
				lInputThemeName->Text = "Nome do Shape";
				lThemeHelp->Text = "Nome do Shape de Saída";
			}
		}

		if (gAllocationComponent > NUMDISCALLOCCOMP || gPotentialComponent > NUMDISCPOTCOMP) {
			tRange->Enabled = true;
		}
		else {
			tRange->Text = "0";
			tRange->Enabled = false;
		}
		
		if (tOutputTheme->ForeColor == System::Drawing::Color::Black && tInputThemeName->ForeColor != System::Drawing::Color::Black) {
			tInputThemeName->Text = tOutputTheme->Text + tEndTime->Text;
		}

		if (tAttributeInitValidation->ForeColor != System::Drawing::Color::Black) {
			String^ auxAttributeName = "";
			if (gLandUseTypes != "") {
				for (int i = 0; i < gLandUseTypes->Length-1; i++) {
					if (gLandUseTypes[i] != ',') {
						auxAttributeName += gLandUseTypes[i];
					}
					else {
						break;
					}
				}
				
				tAttributeInitValidation->Text = auxAttributeName->Replace("\"", "");
			}
		}

		if (tAttributeForValidation->ForeColor != System::Drawing::Color::Black) {
			tAttributeForValidation->Text = tAttributeInitValidation->Text + "_out";
		}
	
		if (tAttributeFinalValidation->ForeColor != System::Drawing::Color::Black) {
			tAttributeFinalValidation->Text = tAttributeInitValidation->Text + tEndTime->Text;
		}
		
		if (runnable == true) {
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

	else if (gDemandComponent == NONE) {
		MessageBox::Show(gSDemandnS, gSDemandnSTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (gPotentialComponent == NONE) {
		MessageBox::Show(gSPotentialnS, gSPotentialnSTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (gAllocationComponent == NONE) {
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

	else if ((lYearsToSave->Text != "" || cSaveYearly->Checked == true) && (lAttrToSave->Text == "")) {
		MessageBox::Show(gSAttribToSave, gSAttribToSaveTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (gPotentialComponent > NUMDISCPOTCOMP && (gAllocationComponent > NONE && gAllocationComponent <= NUMDISCALLOCCOMP)) {
		MessageBox::Show(gSPotContAlocDisc, gSPotContAlocDiscTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if ((gPotentialComponent > NONE && gPotentialComponent <= NUMDISCPOTCOMP) && gAllocationComponent > NUMDISCALLOCCOMP) {
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
		else if (shape) {
			if (lScenarioYearsConfirm->Text == "") {
				MessageBox::Show(gSScenSYU, gSScenSYUTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				checked = false;
			}
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
				sw->WriteLine("-- This file contains a LUCCME APPLICATION MODEL definition --");
				sw->WriteLine("--               Compatible with LuccME 3.0                 --");
				sw->WriteLine("--        Generated with LuccMe Model Configurator          --");
				sw->WriteLine("--               " + dateTime + "                     --");
				sw->WriteLine("--------------------------------------------------------------\n");

				if (shape) {
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- Creating Terraview Project                               --");
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("");
					sw->WriteLine("import(\"terralib\")\n");
					sw->WriteLine("proj = Project {");
					sw->WriteLine("\tfile = \"t3mp.tview\",");
					sw->WriteLine("\tclean = true");
					sw->WriteLine("}\n");

					sw->WriteLine("l1 = Layer{");
					sw->WriteLine("\tproject = proj,");
					sw->WriteLine("\tname = \"" + tThemeName->Text + "\",");
					sw->WriteLine("\tfile = \"" + tbSelectedBatabase->Lines[1]->ToString()->Replace("\\", "\\\\") + "\"");
					sw->WriteLine("}\n");

					int dynamicVariables = 0;
					if (cDynamicVariables->Checked == true && lDynamicConfirm->Text != "") {
						int updateYearsCount = countCaracter(lDynamicConfirm->Text, ',') + 1;
						array<String^>^ updateYearsArray = gcnew array<String^>(updateYearsCount);
						String^ layerName = tbSelectedBatabase->Lines[1]->ToString()->Replace("\\", "\\\\");
						layerName = layerName->Replace(".shp", "");
						int caracter = 0;

						for (int i = 0; i < updateYearsArray->Length; i++) {
							while (lDynamicConfirm->Text[caracter] != ',') {
								updateYearsArray[i] += lDynamicConfirm->Text[caracter];
								caracter++;
								if (caracter == lDynamicConfirm->Text->Length) {
									break;
								}
							}
							caracter++;
						}

						for (int i = 0; i < updateYearsArray->Length; i++) {
							sw->WriteLine("l" + (i + 2) + " = Layer{");
							sw->WriteLine("\tproject = proj,");
							sw->WriteLine("\tname = \"" + tThemeName->Text + "_" + updateYearsArray[i]->Replace(" ", "") + "\",");
							sw->WriteLine("\tfile = \"" + layerName + "_" + updateYearsArray[i]->Replace(" ", "") + ".shp\"");
							sw->WriteLine("}\n");
						}
						dynamicVariables = updateYearsCount;
					}

					if (cScenario->Checked == true && lScenarioYearsConfirm->Text != "" && tScenarioName->Text != "") {
						int updateYearsCount = countCaracter(lScenarioYearsConfirm->Text, ',') + 1;
						array<String^>^ updateYearsArray = gcnew array<String^>(updateYearsCount);
						String^ layerName = tbSelectedBatabase->Lines[1]->ToString()->Replace("\\", "\\\\");
						layerName = layerName->Replace(".shp", "");
						int caracter = 0;
						
						for (int i = 0; i < updateYearsArray->Length; i++) {
							while (lScenarioYearsConfirm->Text[caracter] != ',') {
								updateYearsArray[i] += lScenarioYearsConfirm->Text[caracter];
								caracter++;
								if (caracter == lScenarioYearsConfirm->Text->Length) {
									break;
								}
							}
							caracter++;
						}

						for (int i = 0; i < updateYearsArray->Length; i++) {
							sw->WriteLine("l" + (i + 2 + dynamicVariables) + " = Layer{");
							sw->WriteLine("\tproject = proj,");
							sw->WriteLine("\tname = \"" + tThemeName->Text + "_" + tScenarioName->Text + "_" + updateYearsArray[i]->Replace(" ", "") + "\",");
							sw->WriteLine("\tfile = \"" + layerName + "_" + tScenarioName->Text + "_" + updateYearsArray[i]->Replace(" ", "") + ".shp\"");
							sw->WriteLine("}\n");
						}
					}
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- LuccME Model                                             --");
					sw->WriteLine("--------------------------------------------------------------");
				}
				
				sw->WriteLine("");
				sw->WriteLine("import(\"luccme\")\n");
				String^ folderAux = lSelectedFolder->Text->Replace("\\", "\\\\");
				if (folderAux->Length > ROOTDIR) {
					sw->WriteLine("dofile(\"" + folderAux + "\\\\" + tModelName->Text->ToLower() + "_submodel.lua\")\n");
				}
				else {
					sw->WriteLine("dofile(\"" + folderAux + tModelName->Text->ToLower() + "_submodel.lua\")\n");
				}
				sw->WriteLine();

				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("-- LuccME APPLICATION MODEL DEFINITION                      --");
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
				
				if (tbSelectedBatabase->Lines[0]->ToString() == gSShape) {
					sw->WriteLine("\tcs = CellularSpace");
					sw->WriteLine("\t{");
					sw->WriteLine("\t\tproject = \"t3mp.tview\",");
					sw->WriteLine("\t\tlayer = \"" + tThemeName->Text + "\",");
					sw->WriteLine("\t\tcellArea = " + tCellArea->Text + ",");
					sw->WriteLine("\t},");
				}
				else {
					sw->WriteLine("\tcs = CellularSpace");
					sw->WriteLine("\t{");
					sw->WriteLine("\t\tproject = \"" + tbSelectedBatabase->Lines[1]->ToString()->Replace("\\", "\\\\") + "\",");
					sw->WriteLine("\t\tlayer = \"" + tThemeName->Text + "\",");
					sw->WriteLine("\t\tcellArea = " + tCellArea->Text + ",");
					sw->WriteLine("\t},");
				}

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
				sw->WriteLine("\t\toutputTheme = \"" + tOutputTheme->Text + "\",");
				sw->WriteLine("\t\tmode = \"multiple\",");
				if (cSaveYearly->Checked) {
					sw->WriteLine("\t\tyearly = true,");

				}
				else {
					sw->WriteLine("\t\tsaveYears = {" + lYearsToSave->Text + "},");
				}

				if (lAttrToSave->Text != "") {
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
							if (cChange->Checked) {
								sw->WriteLine("\t\t\t\"" + aux + "_change\",");
							}
							if (cPot->Checked) {
								sw->WriteLine("\t\t\t\"" + aux + "_pot\",");
							}
							if (cReg->Checked) {
								sw->WriteLine("\t\t\t\"" + aux + "_reg\",");
							}
							aux = "";

						}
					}
					if (aux != "") {
						if (aux[0] == ' ') {
							aux = aux->Remove(0, 1);
						}
						sw->WriteLine("\t\t\t\"" + aux + "_out\",");
						if (cChange->Checked) {
							sw->WriteLine("\t\t\t\"" + aux + "_change\",");
						}
						if (cPot->Checked) {
							sw->WriteLine("\t\t\t\"" + aux + "_pot\",");
						}
						if (cReg->Checked) {
							sw->WriteLine("\t\t\t\"" + aux + "_reg\",");
						}
					}
					sw->WriteLine("\t\t},\n");
				}
				sw->WriteLine("\t},\n");

				if (cAuxOut->Checked) {
					sw->WriteLine("\thasAuxiliaryOutputs = true,");
				}

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
				sw->WriteLine("\t\tstart = " + tModelName->Text + ".startTime,");
				sw->WriteLine("\t\taction = function(event)");
				sw->WriteLine("\t\t\t\t\t" + tModelName->Text + ":run(event)");
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
				sw->WriteLine("\tenv_" + tModelName->Text + ":run(" + tModelName->Text + ".endTime)");
				sw->WriteLine("\tsaveSingleTheme (" + tModelName->Text + ", true)");
				
				if (shape) {
					sw->WriteLine("\tlocal projFile = File(\"t3mp.tview\")");
					sw->WriteLine("\tif(projFile:exists()) then");
					sw->WriteLine("\t\tprojFile:delete()");
					sw->WriteLine("\tend");
				}

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
				sw->WriteLine("--               Compatible with LuccME 3.0                 --");
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
					case PCVINPE:
						sw->WriteLine("D1 = " + tbDemand->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\tannualDemand =");
						sw->WriteLine("\t{");
						sw->WriteLine("\t\t-- " + tbDemand->Lines[1]->ToString()->Replace(",", ", "));
						tempYear = Convert::ToInt16(tStartTime->Text);
						for (int i = 2; i < tbDemand->Lines->Length; i++) {
							sw->WriteLine("\t\t" + tbDemand->Lines[i]->ToString()->Replace(",", ", ") + "\t-- " + Convert::ToString(tempYear + i - 2));
						}
						sw->WriteLine("\t}");
						sw->WriteLine("}\n");
						break;

					case CITWODM:
						sw->WriteLine("D1 = " + tbDemand->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\t" + tbDemand->Lines[1]->ToString()->Replace(",", ", ") + ",");
						sw->WriteLine("\tfinalLandUseTypesForInterpolation = {" + tbDemand->Lines[3]->ToString()->Replace(",", ", ") + "},");
						sw->WriteLine("}\n");
						break;

					case CITHREEDM:
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

					int activeRegion = 1;
					int nLut = countCaracter(gPotentialLUT, ',') + 1;
					int endRegion = 0;
					int activeLUT = 0;
					int startAffinity = 0;

					switch (gPotentialComponent)
					{
					case POTENTIALDNEIGHSIMPLERULE:
						sw->WriteLine("P1 = " + tbPotential->Lines[0] + "\n");
						break;

					case POTENTIALDNEIGHINVERSEDISTANCERULE:
					case POTENTIALDINVERSEDISTANCERULE:
					case POTENTIALDLOGISTICREGRESSION:
					case POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT:
					case POTENTIALCLINEARREGRESSION:
					case POTENTIALCSPATIALLAGREGRESSION:
						sw->WriteLine("P1 = " + tbPotential->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\tpotentialData =");
						sw->WriteLine("\t{");
						if (gPotentialRegression > 1) {
							sw->WriteLine("\t\tregionAttr = \"region\",");
							sw->WriteLine("");
						}
						for (int k = 1; k < tbPotential->Lines->Length; k += nLut) {
							sw->WriteLine("\t\t-- Region " + activeRegion.ToString());
							sw->WriteLine("\t\t{");
							if(gPotentialRegression == 1){
								endRegion = (tbPotential->Lines->Length - 1);
							}
							else {
								endRegion = ((tbPotential->Lines->Length - 1) / gPotentialRegression)*activeRegion;
							}
							for (int i = k; i <= endRegion; i++) {
								if (tbPotential->Lines[i]->ToString() != "") {
									sw->WriteLine("\t\t\t-- " + tempLUTs[activeLUT]);
									activeLUT++;
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
												if (activeLUT != nLut) {
													sw->WriteLine("\t\t\t},\n");
												}
												else {
													sw->WriteLine("\t\t\t}");
												}
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
							activeRegion++;
							activeLUT = 0;
							if (activeRegion <= gPotentialRegression) {
								sw->WriteLine("\t\t},\n");
							}
							else {
								sw->WriteLine("\t\t}");
							}
						}

						sw->WriteLine("\t}");
						sw->WriteLine("}\n");
						break;

					case POTENTIALDLOGISTICREGRESSIONNEIGHATTRACTREPULSION:
						sw->WriteLine("P1 = " + tbPotential->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\tpotentialData =");
						sw->WriteLine("\t{");
						if (gPotentialRegression > 1) {
							sw->WriteLine("\t\tregionAttr = \"region\",");
							sw->WriteLine("");
						}

						for (int k = 1; k < tbPotential->Lines->Length - (nLut*gPotentialRegression) - 2; k += nLut) {
							sw->WriteLine("\t\t-- Region " + activeRegion.ToString());
							sw->WriteLine("\t\t{");
							if (gPotentialRegression == 1) {
								endRegion = tbPotential->Lines->Length - (nLut*gPotentialRegression) - 2;
							}
							else {
								endRegion = ((tbPotential->Lines->Length - (nLut*gPotentialRegression) - 2) / gPotentialRegression)*activeRegion;
							}
							for (int i = k; i <= endRegion; i++) {
								if (tbPotential->Lines[i]->ToString() != "") {
									sw->WriteLine("\t\t\t-- " + tempLUTs[activeLUT]);
									activeLUT++;
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
												if (activeLUT != nLut) {
													sw->WriteLine("\t\t\t},\n");
												}
												else {
													sw->WriteLine("\t\t\t}");
												}
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
							activeRegion++;
							activeLUT = 0;
							if (activeRegion <= gPotentialRegression) {
								sw->WriteLine("\t\t},\n");
							}
							else {
								sw->WriteLine("\t\t}");
							}
						}
						sw->WriteLine("\t},\n");
						sw->WriteLine("\taffinityMatrix = ");
						sw->WriteLine("\t{");
						activeRegion = 1;
						startAffinity = endRegion + 2;
						for (int k = startAffinity; k < tbPotential->Lines->Length; k += nLut) {
							endRegion = startAffinity + (nLut * activeRegion);
							sw->WriteLine("\t\t-- Region " + activeRegion.ToString());
							sw->WriteLine("\t\t{");
							for (int i = k; i < endRegion; i++) {
								if (i + 1 < endRegion) {
									sw->WriteLine("\t\t\t{" + tbPotential->Lines[i] + "},");
								}
								else {
									sw->WriteLine("\t\t\t{" + tbPotential->Lines[i] + "}");
									break;
								}
							}
							if (k + nLut < tbPotential->Lines->Length) {
								sw->WriteLine("\t\t},\n");
							}
							else {
								sw->WriteLine("\t\t}");
							}
							activeRegion++;
						}

						sw->WriteLine("\t}");
						sw->WriteLine("}\n");
						break;
					case POTENTIALCSPATIALLAGLINEARREGRESSIONMIX:
						sw->WriteLine("P1 = " + tbPotential->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\tpotentialData =");
						sw->WriteLine("\t{");
						sw->WriteLine("\t\t-- Region 1");
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

					case POTENTIALDMAXIMUMENTROPYLIKE:
					case POTENTIALCMAXIMUMENTROPYLIKE:
						sw->WriteLine("P1 = " + tbPotential->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\tpotentialData =");
						sw->WriteLine("\t{");
						sw->WriteLine("\t\t-- Region 1");
						sw->WriteLine("\t\t{");

						for (int i = 1; i < tbPotential->Lines->Length; i++) {
							if (tbPotential->Lines[i]->ToString() != "") {
								sw->WriteLine("\t\t\t-- " + tempLUTs[i - 1]);
								sw->WriteLine("\t\t\t{");

								aux = tbPotential->Lines[i]->ToString()->Replace("attributesPerc", "$attributesPerc");
								aux = aux->Replace(", attributesClass", "attributesClass");

								int j = 0;
								String^ auxAttributes = "";

								//cellUsePercentage
								while (aux[j] != '$') {
									auxAttributes += aux[j];
									j++;
								}

								sw->WriteLine("\t\t\t\t" + auxAttributes);
								sw->WriteLine("");
								auxAttributes = "";
								j++;


								//attributesPerc
								while (aux[j] != '{') {
									auxAttributes += aux[j];
									j++;
								}

								sw->WriteLine("\t\t\t\t" + auxAttributes);
								sw->WriteLine("\t\t\t\t{");
								auxAttributes = "";
								j++;

								while (aux[j] != '}') {
									if (aux[j] != ',') {
										auxAttributes += aux[j];
									}
									else {
										if (aux[j + 1] != '}') {
											sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"","\"") + ",");
										}
										else {
											sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"", "\""));
										}
										auxAttributes = "";
									}
									j++;
								}

								if (auxAttributes != "") {
									sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"", "\""));
								}

								sw->WriteLine("\t\t\t\t},");
								sw->WriteLine("");
								auxAttributes = "";
								j++;

								//attributesClass
								while (aux[j] != '{') {
									auxAttributes += aux[j];
									j++;
								}

								sw->WriteLine("\t\t\t\t" + auxAttributes);
								sw->WriteLine("\t\t\t\t{");
								auxAttributes = "";
								j++;

								while (aux[j] != '}') {
									if (aux[j] != ',') {
										auxAttributes += aux[j];
									}
									else {
										if (aux[j + 1] != '}') {
											sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"", "\"") + ",");
										}
										else {
											sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"", "\""));
										}
										auxAttributes = "";
									}
									j++;
								}

								if (auxAttributes != "") {
									sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"", "\""));
								}

								if (aux[j + 1] != '}') {
									sw->WriteLine("\t\t\t\t},");
								} else {
									sw->WriteLine("\t\t\t\t}");
								}
								auxAttributes = "";
								j++;

								if (i + 1 < tbPotential->Lines->Length) {
									sw->WriteLine("\t\t\t},");
									sw->WriteLine("");
								} else {
									sw->WriteLine("\t\t\t}");
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
					case ALLOCATIONDSIMPLEORDERING:
						sw->WriteLine("A1 = " + tbAllocation->Lines[0]);
						sw->WriteLine("{");
						sw->WriteLine("\t" + tbAllocation->Lines[1]);
						sw->WriteLine("}\n");
						break;

					case ALLOCATIONDCLUESNEIGHORDERING:
					case ALLOCATIONDCLUESLIKE:
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

					case ALLOCATIONCCLUELIKE:
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

					case ALLOCATIONCCLUELIKESATURATION:
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
					if (lSelectedFolder->Text->Length > ROOTDIR) {
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

					gParametersValues[0] = lSelectedFolder->Text;
					gParametersValues[1] = tModelName->Text;
					gParametersValues[2] = tStartTime->Text;
					gParametersValues[3] = tEndTime->Text;
					gParametersValues[4] = tThemeName->Text;
					gParametersValues[5] = tbSelectedBatabase->Lines[1]->ToString();
					gParametersValues[6] = tCellArea->Text;
					gParametersValues[7] = lDynamicConfirm->Text;
					gParametersValues[8] = tScenariosStartTime->Text;
					gParametersValues[9] = tScenarioName->Text;
					gParametersValues[10] = lLUTShow->Text;
					gParametersValues[11] = lLUNDShow->Text;
					gParametersValues[12] = tOutputTheme->Text;
					gParametersValues[13] = lYearsToSave->Text;
					gParametersValues[14] = lAttrToSave->Text;
					gParametersValues[15] = tbDemand->Lines[0]->ToString();
					gParametersValues[16] = tbPotential->Lines[0]->ToString();
					gParametersValues[17] = tbAllocation->Lines[0]->ToString();
				}
				else {
					if (!mainFile) {
						MessageBox::Show(gSFileMissing + lSelectedFolder->Text, gSFileMissingTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
					else {
						MessageBox::Show(gSFileMissing2 + lSelectedFolder->Text, gSFileMissingTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
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
					System::Threading::Thread::Sleep(SECOND);
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
					System::Threading::Thread::Sleep(SECOND);
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
	Environment::SetEnvironmentVariable("TME_PATH", "C:\\Luccme\\Terrame\\bin");
	Environment::SetEnvironmentVariable("PATH", "C:\\Luccme\\Terrame\\bin");

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

	cmd = gcnew System::Diagnostics::Process;
	arguments = "";
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

			MessageBox::Show(gSMainLoad, gSMainLoadTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);

			LuccME::OpenFileDialog^ mainFile = gcnew OpenFileDialog;
			mainFile->Title = gSMainFile;
			mainFile->Multiselect = false;
			mainFile->Filter = gSLuaFile;
			mainFile->FilterIndex = 1;
			mainFile->ShowHelp = true;

			if (mainFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ fileName = mainFile->FileName;
				System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(fileName);
				bool found = false;

				//Used to know when the LuccME Model begins
				int beginning = 0;
			
				String^ line = sw->ReadLine();
			
				while (sw->EndOfStream == false) {
					if (line->Contains("dofile") != TRUE) {
						line = sw->ReadLine();
						beginning++;
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
					if (lSelectedFolder->Text->Length == 2) {
						lSelectedFolder->Text += "\\";
					}
				}
				
				gParametersValues[0] = lSelectedFolder->Text;
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);
			
				//When using Shape file the key word (name =) is used before
				for (int k = 0; k <= beginning; k++) {
					line = sw->ReadLine();
				}

				while (sw->EndOfStream == false) {
					if (line->Contains("name =") != TRUE) {
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
					if (tempLine->Length == 2) {
						tempLine += "\\";
					}

					if (lSelectedFolder->Text != tempLine) {
						lSelectedFolder->Text = "";
						imported = false;
					}
				}

				gParametersValues[1] = tModelName->Text;
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("startTime") != TRUE) {
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

				gParametersValues[2] = tStartTime->Text;
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("endTime") != TRUE) {
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

				gParametersValues[3] = tEndTime->Text;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				bool oldModel = false;
				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("theme") != 1) {
						line = sw->ReadLine();
					}
					else {
						oldModel = true;
						imported = false;
						break;
					}
				}

				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				if (found) {
					line = sw->ReadLine();
					while (line->Contains("endTime") != TRUE) {
						line = sw->ReadLine();
					}
				}

				found = false;
				String^ tempDB = "";

				if (!oldModel) {
					line = sw->ReadLine();
					while (sw->EndOfStream == false) {
						if (line->Contains("layer") != TRUE) {
							tempDB += line;
							line = sw->ReadLine();
						}
						else {
							found = true;
							break;
						}
					}
				}

				if (found) {
					tempDB = tempDB->Replace("\n", "");
					tempDB = tempDB->Replace("\t", "");
					String^ dbAux = "";
					
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

						//Using Shape file the project name is always t3mp.tview
						if (path == "t3mp.tview") {
							shape = true;
							tThemeName->Enabled = false;
							sw->Close();
							sw = gcnew System::IO::StreamReader(fileName);
							String^ tempShape = "";
							while (sw->EndOfStream == false) {
								if (tempShape->Contains(":\\") != TRUE) {
									tempShape = sw->ReadLine();
								}
								else {
									break;
								}
							}
							tempShape = tempShape->Replace("\n", "");
							tempShape = tempShape->Replace("\t", "");
							tempShape = tempShape->Replace("file = ", "");
							tempShape = tempShape->Replace("\"", "");
							tempShape = tempShape->Replace("\\\\", "\\");
							
							if (File::Exists(tempShape))
							{
								tempBd[0] = gSShape;
								tempBd[1] = tempShape;
								tbSelectedBatabase->Lines = tempBd;
							}
							else {
								imported = false;
							}
						}
						//Using postgis
						else {
							if (File::Exists(path))
							{
								tempBd[0] = gSProject;
								tempBd[1] = dbAux;
								tbSelectedBatabase->Lines = tempBd;
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

				if (imported) {
					gParametersValues[4] = tThemeName->Text;
					gParametersValues[5] = tbSelectedBatabase->Lines[1]->ToString();
				}
				else {
					gParametersValues[4] = "";
					gParametersValues[5] = "";
				}
				
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("cellArea") != TRUE) {
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

				gParametersValues[6] = tCellArea->Text;
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);
			
				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("updateYears") != TRUE) {
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

				gParametersValues[7] = lDynamicConfirm->Text;
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("scenarioStartTime") != TRUE) {
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

				gParametersValues[8] = tScenariosStartTime->Text;
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("scenarioName") != TRUE) {
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

					if (shape) {
						sw->Close();
						sw = gcnew System::IO::StreamReader(fileName);
						
						int countScenario = 0;
						
						line = sw->ReadLine();
						while (sw->EndOfStream == false) {
							if (line->Contains(tScenarioName->Text) == TRUE && line->Contains("name =") == FALSE) {
								countScenario++;
							}
							line = sw->ReadLine();
						}
						
						sw->Close();
						sw = gcnew System::IO::StreamReader(fileName);
						String^ auxSYU = "";

						for (int k = 0; k < countScenario - 1; k++) {
							line = sw->ReadLine();
							while (sw->EndOfStream == false) {
								if (line->Contains(tScenarioName->Text) == TRUE && line->Contains("name =") == FALSE) {
									line = line->Replace("\t", "");
									line = line->Replace("\n", "");
									line = line->Replace("\"", "");
									line = line->Substring(0, line->Length - 4);
									line = line->Substring(line->Length - 4, 4);
									auxSYU += line + ", ";
									break;
								}
								line = sw->ReadLine();
							}
						}

						lScenarioYearsConfirm->Text = auxSYU->Substring(0, auxSYU->Length - 2);
					}
				}

				gParametersValues[9] = tScenarioName->Text;
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("landUseTypes") != TRUE) {
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
					while (line->Contains("},") != TRUE) {
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

				gParametersValues[10] = lLUTShow->Text;
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("landUseNoData") != TRUE) {
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

				gParametersValues[11] = lLUNDShow->Text;
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("outputTheme") != TRUE) {
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
						if (line[i] != ',') {
							tempLine += line[i];
						}
						else {
							break;
						}
					}
					tempLine = tempLine->Replace("\"", "");
					tOutputTheme->Text = tempLine;
					tOutputTheme->ForeColor = System::Drawing::Color::Black;
				}

				gParametersValues[12] = tOutputTheme->Text;
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();

				while (sw->EndOfStream == false) {
					if (line->Contains("yearly") != TRUE) {
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

				gParametersValues[13] = lYearsToSave->Text;
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("saveAttrs") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempLine = "";
					while (line->Contains("},") != TRUE) {
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

						tempLine = tempLine->Replace("\t","");
						tempLine = tempLine->Replace(" ", "");
						tempLine = tempLine->Replace("saveAttrs={", "");
						tempLine = tempLine->Replace(",},", "");
						tempLine = tempLine->Replace("_out", "");
						tempLine = tempLine->Replace("_pot", "");
						tempLine = tempLine->Replace("_change", "");
						tempLine = tempLine->Replace("_reg", "");
						tempLine = tempLine->Replace("\"", "");

						array<String^>^ attrsTemp = tempLine->Split(',');
						lAttrToSave->Text = attrsTemp[0];
						
						for (int z = 1; z < attrsTemp->Length; z++) {
							if (!lAttrToSave->Text->Contains(attrsTemp[z])) {
								lAttrToSave->Text += ", " + attrsTemp[z];
							}
						}

						gAttrLUT = gLandUseTypes;
					}
				}

				gParametersValues[14] = lAttrToSave->Text;
				sw->Close();

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("hasAuxiliaryOutputs") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					cAuxOut->Checked = true;
				}

				sw->Close();
				main = true;
				if (!oldModel) {
					MessageBox::Show(gSMainImport, gSMainImportTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show(gSMainImportOld, gSMainImportOldtTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}

			LuccME::OpenFileDialog^ submodelFile = gcnew OpenFileDialog;
			submodelFile->Title = gSSubmodelFile;
			submodelFile->Multiselect = false;
			submodelFile->Filter = gSLuaFile;
			submodelFile->FilterIndex = 1;
			submodelFile->ShowHelp = true;

			if (submodelFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ fileName = submodelFile->FileName;
				System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(fileName);

				String^ line = sw->ReadLine();
				while (line->Contains("=") != TRUE) {
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
				if (tempLine == "DemandPreComputedValues") {
					j = 0;
					line = sw->ReadLine();
					j++;
					while (line->Contains("=") != TRUE) {
						line = sw->ReadLine();
						j++;
					}
					tempLine = "";
					line = sw->ReadLine();
					j++;
					while (line->Length != TRUE) {
						line = sw->ReadLine();
						tempLine += line;
						j++;
					}
					tempLine = tempLine->Replace("\n", "");
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace(" ", "");
				
					gDemand = "";
					bool enter = false;
					for (int i = 0; i < tempLine->Length; i++) {
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

						count += countCaracter(gDemand, ';');

						array<String^>^ lines = gcnew array<String^>(count + 3); //If has 1 semicolon there are 2 values + header (2)
						String^ auxLine = "";
						lines[0] = "DemandPreComputedValues";
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
						gDemandComponent = PCVINPE;
					}
				}

				if (tempLine == "DemandComputeTwoDates") {
					tempLine = "";
					gDemandLUT = gLandUseTypes;
					while (line->Contains("finalYearForInterpolation") != TRUE) {
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
					while (line->Contains("finalLandUseTypesForInterpolation") != TRUE) {
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
						array<String^>^ lines = gcnew array<String^>(4);

						lines[0] = "DemandComputeTwoDates";
						lines[1] = "finalYearForInterpolation = " + gDemandFinalYear;
						lines[2] = gDemandLUT;
						lines[3] = gDemand;

						tbDemand->Lines = lines;
						gDemandComponent = CITWODM;
					}
				}

				if (tempLine == "DemandComputeThreeDates") {
					tempLine = "";
					gDemandLUT = gLandUseTypes;

					while (line->Contains("middleYearForInterpolation") != TRUE) {
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
					while (line->Contains("middleLandUseTypesForInterpolation") != TRUE) {
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
					while (line->Contains("finalYearForInterpolation") != TRUE) {
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
					while (line->Contains("finalLandUseTypesForInterpolation") != TRUE) {
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
						lines[0] = "DemandComputeThreeDates";
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
						gDemandComponent = CITHREEDM;
					}
				}

				gParametersValues[15] = tbDemand->Lines[0]->ToString();

				//Potencial
				line = sw->ReadLine();
				while (line->Contains("=") != TRUE) {
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

				if (tempLine == "PotentialDNeighSimpleRule{}") {
					array<String^>^ lines = { "PotentialDNeighSimpleRule{}" };
					tbPotential->Lines = lines;
					gPotentialComponent = POTENTIALDNEIGHSIMPLERULE;
					gPotentialLUT = gLandUseTypes;
				}

				if (tempLine == "PotentialDNeighInverseDistanceRule") {
					gPotential = "";
					gPotentialComponent = POTENTIALDNEIGHINVERSEDISTANCERULE;
					gPotentialLUT = gLandUseTypes;
					int count = 2;

					count += countCaracter(gPotentialLUT, ',');
					
					line = sw->ReadLine();
					while (line->Contains("=") != TRUE) { //potentialData
						line = sw->ReadLine();
					}

					int countBraces = 0;
					while (line->Contains("Allocation") != TRUE) {
						line = sw->ReadLine();
						if (line->Contains("{")) {
							countBraces++;
						}
					}

					countBraces -= 1; //To remove the potencialData brace

					int nLUT = countCaracter(gPotentialLUT, ',') + 1;
					int bracesForLUT = 2;
					int nRegions = countBraces / (bracesForLUT*nLUT);
					int activeRegion = 0;
					array<String^>^ auxPotData = gcnew array<String^>(nRegions*nLUT);

					gPotentialRegression = nRegions;

					sw->Close();
					sw = gcnew System::IO::StreamReader(fileName);

					while (line->Contains("potentialData") != TRUE) {
						line = sw->ReadLine();
					}

					for (int i = 0; i < nRegions; i++) {
						for (int k = 0; k < count - 1; k++) {
							int position = k + (nLUT*activeRegion);

							line = sw->ReadLine();
							while (line->Contains("const") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("const=", "");
							line = line->Replace(",", ";");
							
							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("betas") != TRUE) {
								line = sw->ReadLine();
							}

							tempLine = "";
							while (line->Contains("}") != TRUE) {
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
							auxPotData[position] += tempAux + "*";
						}
						activeRegion++;
					}

					for (int i = 0; i < nLUT; i++) {
						for (int j = i; j < auxPotData->Length; j += nLUT) {
							gPotential += auxPotData[j];
						}
						gPotential += "#";
					}

					gPotential = gPotential->Substring(0, gPotential->Length - 1);

					if (gPotential != "") {
						showReturnDistanceRule("PotentialDNeighInverseDistanceRule");
					}
				}

				if (tempLine == "PotentialDInverseDistanceRule") {
					gPotential = "";
					gPotentialComponent = POTENTIALDINVERSEDISTANCERULE;
					gPotentialLUT = gLandUseTypes;
					int count = 2;

					count += countCaracter(gPotentialLUT, ',');

					line = sw->ReadLine();
					while (line->Contains("=") != TRUE) { //potentialData
						line = sw->ReadLine();
					}

					int countBraces = 0;
					while (line->Contains("Allocation") != TRUE) {
						line = sw->ReadLine();
						if (line->Contains("{")) {
							countBraces++;
						}
					}

					countBraces -= 1; //To remove the potencialData brace

					int nLUT = countCaracter(gPotentialLUT, ',') + 1;
					int bracesForLUT = 2;
					int nRegions = countBraces / (bracesForLUT*nLUT);
					int activeRegion = 0;
					array<String^>^ auxPotData = gcnew array<String^>(nRegions*nLUT);

					gPotentialRegression = nRegions;

					sw->Close();
					sw = gcnew System::IO::StreamReader(fileName);

					while (line->Contains("potentialData") != TRUE) {
						line = sw->ReadLine();
					}

					for (int i = 0; i < nRegions; i++) {
						for (int k = 0; k < count - 1; k++) {
							int position = k + (nLUT*activeRegion);

							line = sw->ReadLine();
							while (line->Contains("const") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("const=", "");
							line = line->Replace(",", ";");
							
							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("betas") != TRUE) {
								line = sw->ReadLine();
							}

							tempLine = "";
							while (line->Contains("}") != TRUE) {
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
							auxPotData[position] += tempAux + "*";
						}
						activeRegion++;
					}

					for (int i = 0; i < nLUT; i++) {
						for (int j = i; j < auxPotData->Length; j += nLUT) {
							gPotential += auxPotData[j];
						}
						gPotential += "#";
					}

					gPotential = gPotential->Substring(0, gPotential->Length - 1);

					if (gPotential != "") {
						showReturnDistanceRule("PotentialDInverseDistanceRule");
					}
				}

				if (tempLine == "PotentialDLogisticRegression") {
					gPotential = "";
					gPotentialComponent = POTENTIALDLOGISTICREGRESSION;
					gPotentialLUT = gLandUseTypes;
					int count = 2;

					count += countCaracter(gPotentialLUT, ',');

					line = sw->ReadLine();
					while (line->Contains("=") != TRUE) { //potentialData
						line = sw->ReadLine();
					}

					int countBraces = 0;
					while (line->Contains("Allocation") != TRUE) {
						line = sw->ReadLine();
						if (line->Contains("{")) {
							countBraces++;
						}
					}

					countBraces -= 1; //To remove the potencialData brace

					int nLUT = countCaracter(gPotentialLUT, ',') + 1;
					int bracesForLUT = 2;
					int nRegions = countBraces / (bracesForLUT*nLUT);
					int activeRegion = 0;
					array<String^>^ auxPotData = gcnew array<String^>(nRegions*nLUT);

					gPotentialRegression = nRegions;

					sw->Close();
					sw = gcnew System::IO::StreamReader(fileName);

					while (line->Contains("potentialData") != TRUE) {
						line = sw->ReadLine();
					}

					for (int i = 0; i < nRegions; i++) {
						for (int k = 0; k < count - 1; k++) {
							int position = k + (nLUT*activeRegion);

							line = sw->ReadLine();
							while (line->Contains("const") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("const=", "");
							line = line->Replace(",", ";");

							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("elasticity") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("elasticity=", "");
							line = line->Replace(",", ";");

							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("betas") != TRUE) {
								line = sw->ReadLine();
							}

							tempLine = "";
							while (line->Contains("}") != TRUE) {
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
							auxPotData[position] += tempAux + "*";
						}
						activeRegion++;
					}

					for (int i = 0; i < nLUT; i++) {
						for (int j = i; j < auxPotData->Length; j += nLUT) {
							gPotential += auxPotData[j];
						}
						gPotential += "#";
					}

					gPotential = gPotential->Substring(0, gPotential->Length - 1);

					if (gPotential != "") {
						showReturnLogisticRegression();
					}
				}
	
				if (tempLine == "PotentialDLogisticRegressionNeighAttract") {
					gPotential = "";
					gPotentialComponent = POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT;
					gPotentialLUT = gLandUseTypes;
					int count = 2;

					count += countCaracter(gPotentialLUT, ',');

					line = sw->ReadLine();
					while (line->Contains("=") != TRUE) { //potentialData
						line = sw->ReadLine();
					}

					int countBraces = 0;
					while (line->Contains("Allocation") != TRUE) {
						line = sw->ReadLine();
						if (line->Contains("{")) {
							countBraces++;
						}
					}

					countBraces -= 1; //To remove the potencialData brace

					int nLUT = countCaracter(gPotentialLUT, ',') + 1;
					int bracesForLUT = 2;
					int nRegions = countBraces / (bracesForLUT*nLUT);
					int activeRegion = 0;
					array<String^>^ auxPotData = gcnew array<String^>(nRegions*nLUT);

					gPotentialRegression = nRegions;

					sw->Close();
					sw = gcnew System::IO::StreamReader(fileName);

					while (line->Contains("potentialData") != TRUE) {
						line = sw->ReadLine();
					}

					for (int i = 0; i < nRegions; i++) {
						for (int k = 0; k < count - 1; k++) {
							int position = k + (nLUT*activeRegion);

							line = sw->ReadLine();
							while (line->Contains("const") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("const=", "");
							line = line->Replace(",", ";");
							
							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("elasticity") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("elasticity=", "");
							line = line->Replace(",", ";");
							
							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("percNeighborsUse") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("percNeighborsUse=", "");
							line = line->Replace(",", ";");
							
							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("betas") != TRUE) {
								line = sw->ReadLine();
							}

							tempLine = "";
							while (line->Contains("}") != TRUE) {
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
							auxPotData[position] += tempAux + "*";
						}
						activeRegion++;
					}

					for (int i = 0; i < nLUT; i++) {
						for (int j = i; j < auxPotData->Length; j += nLUT) {
							gPotential += auxPotData[j];
						}
						gPotential += "#";
					}

					gPotential = gPotential->Substring(0, gPotential->Length - 1);

					if (gPotential != "") {
						showReturnNeighAttractionLogisticRegression();
					}
				}
				
				if (tempLine == "PotentialDLogisticRegressionNeighAttractRepulsion") {
					gPotential = "";
					gPotentialComponent = POTENTIALDLOGISTICREGRESSIONNEIGHATTRACTREPULSION;
					gPotentialLUT = gLandUseTypes;
					int count = 2;

					count += countCaracter(gPotentialLUT, ',');

					line = sw->ReadLine();
					while (line->Contains("=") != TRUE) { //potentialData
						line = sw->ReadLine();
					}

					int countBraces = 0;
					while (line->Contains("affinityMatrix") != TRUE) {
						line = sw->ReadLine();
						if (line->Contains("{")) {
							countBraces++;
						}
					}

					countBraces -= 1; //To remove the potencialData brace

					int nLUT = countCaracter(gPotentialLUT, ',') + 1;
					int bracesForLUT = 2;
					int nRegions = countBraces / (bracesForLUT*nLUT);
					int activeRegion = 0;
					array<String^>^ auxPotData = gcnew array<String^>(nRegions*nLUT);

					gPotentialRegression = nRegions;

					sw->Close();
					sw = gcnew System::IO::StreamReader(fileName);

					while (line->Contains("potentialData") != TRUE) {
						line = sw->ReadLine();
					}

					for (int i = 0; i < nRegions; i++) {
						for (int k = 0; k < count - 1; k++) {
							int position = k + (nLUT*activeRegion);

							line = sw->ReadLine();
							while (line->Contains("const") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("const=", "");
							line = line->Replace(",", ";");

							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("elasticity") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("elasticity=", "");
							line = line->Replace(",", ";");

							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("percNeighborsUse") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("percNeighborsUse=", "");
							line = line->Replace(",", ";");

							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("betas") != TRUE) {
								line = sw->ReadLine();
							}

							tempLine = "";
							while (line->Contains("}") != TRUE) {
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
							auxPotData[position] += tempAux + "*";
						}
						activeRegion++;
					}

					for (int i = 0; i < nLUT; i++) {
						for (int j = i; j < auxPotData->Length; j += nLUT) {
							gPotential += auxPotData[j];
						}
						gPotential += "#";
					}

					//Fazer a parte da Affinity Matrix
					sw->Close();
					sw = gcnew System::IO::StreamReader(fileName);

					while (line->Contains("affinityMatrix") != TRUE) {
						line = sw->ReadLine();
					}

					gPotential += "&";

					int fulfillMatrix = 0;
					for (int i = 0; i < gPotentialRegression; i++) {
						while (fulfillMatrix < nLUT) {
							line = sw->ReadLine();
							if (line->Contains("{") & line->Contains("}")) {
								line = line->Replace("{", "");
								line = line->Replace("},", "");
								line = line->Replace("}", "");
								line = line->Replace(" ", "");
								gPotential += line;
								if (fulfillMatrix + 1 < nLUT) {
									gPotential += ";";
								}
								fulfillMatrix++;
							}
						}
						gPotential += "%";
						fulfillMatrix = 0;
					}

					gPotential = gPotential->Replace("\t", "");
					gPotential = gPotential->Replace("\n", "");

					if (gPotential != "") {
						showReturnARLR();
					}
				}

				//Contiuous Potential Components
				if (tempLine == "PotentialCLinearRegression") {
					gPotential = "";
					gPotentialComponent = POTENTIALCLINEARREGRESSION;
					gPotentialLUT = gLandUseTypes;
					int count = 2;

					count += countCaracter(gPotentialLUT, ',');

					line = sw->ReadLine();
					while (line->Contains("=") != TRUE) { //potentialData
						line = sw->ReadLine();
					}
					
					int countBraces = 0;
					while (line->Contains("Allocation") != TRUE) {
						line = sw->ReadLine();
						if (line->Contains("{")) {
							countBraces++;
						}
					}
					
					countBraces -= 1; //To remove the potencialData brace
					
					int nLUT = countCaracter(gPotentialLUT, ',') + 1;
					int bracesForLUT = 2;
					int nRegions = countBraces / (bracesForLUT*nLUT);
					int activeRegion = 0;
					array<String^>^ auxPotData = gcnew array<String^>(nRegions*nLUT);

					gPotentialRegression = nRegions;

					sw->Close();
					sw = gcnew System::IO::StreamReader(fileName);

					while (line->Contains("potentialData") != TRUE) {
						line = sw->ReadLine();
					}

					for (int i = 0; i < nRegions; i++) {
						for (int k = 0; k < count - 1; k++) {
							int position = k + (nLUT*activeRegion);
							line = sw->ReadLine();
							while (line->Contains("isLog") != TRUE) {
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

							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("const") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("const=", "");
							line = line->Replace(",", ";");

							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("betas") != TRUE) {
								line = sw->ReadLine();
							}

							tempLine = "";
							while (line->Contains("}") != TRUE) {
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
							auxPotData[position] += tempAux + "*";
						}
						activeRegion++;
					}
					
					for (int i = 0; i < nLUT; i++) {
						for (int j = i; j < auxPotData->Length; j += nLUT) {
							gPotential += auxPotData[j];
						}
						gPotential += "#";
					}

					gPotential = gPotential->Substring(0, gPotential->Length - 1);
				
					if (gPotential != "") {
						showReturnLinearRegression();
					}
				}

				if (tempLine == "PotentialCSpatialLagRegression") {
					gPotential = "";
					gPotentialComponent = POTENTIALCSPATIALLAGREGRESSION;
					gPotentialLUT = gLandUseTypes;
					int count = 2;

					count += countCaracter(gPotentialLUT, ',');

					line = sw->ReadLine();
					while (line->Contains("=") != TRUE) { //potentialData
						line = sw->ReadLine();
					}

					int countBraces = 0;
					while (line->Contains("Allocation") != TRUE) {
						line = sw->ReadLine();
						if (line->Contains("{")) {
							countBraces++;
						}
					}

					countBraces -= 1; //To remove the potencialData brace

					int nLUT = countCaracter(gPotentialLUT, ',') + 1;
					int bracesForLUT = 2;
					int nRegions = countBraces / (bracesForLUT*nLUT);
					int activeRegion = 0;
					array<String^>^ auxPotData = gcnew array<String^>(nRegions*nLUT);

					gPotentialRegression = nRegions;

					sw->Close();
					sw = gcnew System::IO::StreamReader(fileName);

					while (line->Contains("potentialData") != TRUE) {
						line = sw->ReadLine();
					}

					for (int i = 0; i < nRegions; i++) {
						for (int k = 0; k < count - 1; k++) {
							int position = k + (nLUT*activeRegion);
							line = sw->ReadLine();
							while (line->Contains("isLog") != TRUE) {
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

							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("const") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("const=", "");
							line = line->Replace(",", ";");
							
							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("minReg") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("minReg=", "");
							line = line->Replace(",", ";");
							
							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("maxReg") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("maxReg=", "");
							line = line->Replace(",", ";");
							
							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("ro") != TRUE) {
								line = sw->ReadLine();
							}

							line = line->Replace("\n", "");
							line = line->Replace("\t", "");
							line = line->Replace(" ", "");
							line = line->Replace("ro=", "");
							line = line->Replace(",", ";");
							
							auxPotData[position] += line;

							line = sw->ReadLine();
							while (line->Contains("betas") != TRUE) {
								line = sw->ReadLine();
							}

							tempLine = "";
							while (line->Contains("}") != TRUE) {
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
							auxPotData[position] += tempAux + "*";
						}
						activeRegion++;
					}

					for (int i = 0; i < nLUT; i++) {
						for (int j = i; j < auxPotData->Length; j += nLUT) {
							gPotential += auxPotData[j];
						}
						gPotential += "#";
					}

					gPotential = gPotential->Substring(0, gPotential->Length - 1);

					if (gPotential != "") {
						showReturnSpatialLagRegression();
					}
				}

				if (tempLine == "PotentialCSpatialLagLinearRegressionMix") {
					gPotential = "";
					gPotentialComponent = POTENTIALCSPATIALLAGLINEARREGRESSIONMIX;
					gPotentialLUT = gLandUseTypes;
					int count = 2;
					for (int i = 0; i < gPotentialLUT->Length; i++) {
						if (gPotentialLUT[i] == ',') {
							count++;
						}
					}

					line = sw->ReadLine();
					while (line->Contains("=") != 1) { //potentialData
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

					if (gPotential != "") {
						showReturnSpatialLagLinearRoads();
					}
				}

				if (tempLine == "PotentialDMaximumEntropyLike" || tempLine == "PotentialCMaximumEntropyLike") {
					gPotential = "";
					if (tempLine == "PotentialDMaximumEntropyLike") {
						gPotentialComponent = POTENTIALDMAXIMUMENTROPYLIKE;
					} 	
					else {
						gPotentialComponent = POTENTIALCMAXIMUMENTROPYLIKE;
					}
					gPotentialLUT = gLandUseTypes;
					int count = 2;

					count += countCaracter(gPotentialLUT, ',');

					line = sw->ReadLine();
					while (line->Contains("potentialData") != TRUE) {
						line = sw->ReadLine();
					}

					for (int k = 0; k < count - 1; k++) {
						line = sw->ReadLine();
						while (line->Contains("cellUsePercentage") != TRUE) { 
							line = sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("cellUsePercentage=", "");
						line = line->Replace(",", ";");

						gPotential += line;

						line = "";
						while (line->Contains("}") != TRUE) {
							line += sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("attributesPerc={", "");
						line = line->Replace("},", ";");
						
						gPotential += line;


						line = "";
						while (line->Contains("}") != TRUE) {
							line += sw->ReadLine();
						}

						line = line->Replace("\n", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
						line = line->Replace("attributesClass={", "");
						line = line->Replace("}", "#");

						gPotential += line;
					}

					if (gPotential != "") {
						if (gPotentialComponent == POTENTIALDMAXIMUMENTROPYLIKE) {
							showReturnMaxEntLike("PotentialDMaximumEntropyLike");
						}
						else {
							showReturnMaxEntLike("PotentialCMaximumEntropyLike");
						}
					}
				}

				gParametersValues[16] = tbPotential->Lines[0]->ToString();

				//Allocation
				gAllocationLUT = gLandUseTypes;

				int count = 1;

				count += countCaracter(gAllocationLUT, ',');

				line = sw->ReadLine();
				while (line->Contains("=") != TRUE) {
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

				if (tempLine == "AllocationDSimpleOrdering") {
					gAllocation = "";
					gAllocationComponent = ALLOCATIONDSIMPLEORDERING;

					line = sw->ReadLine();
					while (line->Contains("maxDifference") != TRUE) {
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
						lines[0] = "AllocationDSimpleOrdering";
						lines[1] = "maxDifference = " + gAllocation;
						tbAllocation->Lines = lines;
					}
				}

				if (tempLine == "AllocationDClueSLike" || tempLine == "AllocationDClueSNeighOrdering") {
					gAllocation = "";
					if (tempLine == "AllocationDClueSLike") {
						gAllocationComponent = ALLOCATIONDCLUESLIKE;
					}
					else {
						gAllocationComponent = ALLOCATIONDCLUESNEIGHORDERING;
					}
					
					gAllocationLUT = gLandUseTypes;

					line = sw->ReadLine();
					while (line->Contains("maxIteration") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxIteration=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("factorIteration") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("factorIteration=", "");
					line = line->Replace(",", ";");
					gAllocation += line;
		
					line = sw->ReadLine();
					while (line->Contains("maxDifference") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxDifference=", "");
					line = line->Replace(",", ";");
					gAllocation += line;
				
					line = sw->ReadLine();
					while (line->Contains("transitionMatrix") != TRUE) {
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
						if (gAllocationComponent == ALLOCATIONDCLUESLIKE) {
							lines2[0] = "AllocationDClueSLike";
						}
						else {
							lines2[0] = "AllocationDClueSNeighOrdering";
						}

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

				//Contiouos Allocation Components
				if (tempLine == "AllocationCClueLike") {
					gAllocation = "";
					gAllocationComponent = ALLOCATIONCCLUELIKE;
					gAllocationLUT = gLandUseTypes;

					line = sw->ReadLine();
					while (line->Contains("maxDifference") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxDifference=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("maxIteration") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxIteration=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("initialElasticity") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("initialElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("minElasticity") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("minElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("maxElasticity") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("complementarLU") != TRUE) {
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
					while (line->Contains("allocationData") != TRUE) {
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

						lines[0] = "AllocationCClueLike";

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

				if (tempLine == "AllocationCClueLikeSaturation") {
					gAllocation = "";
					gAllocationComponent = ALLOCATIONCCLUELIKESATURATION;
					gAllocationLUT = gLandUseTypes;

					line = sw->ReadLine();
					while (line->Contains("maxDifference") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxDifference=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("maxIteration") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxIteration=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("initialElasticity") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("initialElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("minElasticity") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("minElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("maxElasticity") != TRUE) {
						line = sw->ReadLine();
					}

					line = line->Replace("\n", "");
					line = line->Replace("\t", "");
					line = line->Replace(" ", "");
					line = line->Replace("maxElasticity=", "");
					line = line->Replace(",", ";");
					gAllocation += line;

					line = sw->ReadLine();
					while (line->Contains("complementarLU") != TRUE) {
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
					while (line->Contains("saturationIndicator") != TRUE) {
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
					while (line->Contains("attrProtection") != TRUE) {
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
					while (line->Contains("allocationData") != TRUE) {
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
						if (gAllocationComponent == ALLOCATIONCCLUELIKESATURATION) {
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

						count += countCaracter(gAllocationLUT, ',');
						
						array<String^>^ lines = gcnew array<String^>(count + 10);

						lines[0] = "AllocationCClueLikeSaturation";
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

				gParametersValues[17] = tbAllocation->Lines[0]->ToString();
				sw->Close();
				submodel = true;
			}
		
			if (main && submodel && imported) {
				if (gPotentialComponent > NUMDISCPOTCOMP && (gAllocationComponent > 0 && gAllocationComponent <= NUMDISCALLOCCOMP)) {
					MessageBox::Show(gSPotContAlocDisc, gSPotContAlocDiscTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else if ((gPotentialComponent > 0 && gPotentialComponent <= NUMDISCPOTCOMP) && gAllocationComponent > NUMDISCALLOCCOMP) {
					MessageBox::Show(gSPotDiscAlocCont, gSPotContAlocDiscTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else {
					lRunModel->Visible = true;
					bRun->Visible = true;
					runnable = true;
					checkLanguage();
					this->Text = gSEditing;
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
	languageForm->ShowInTaskbar = false;
	languageForm->MinimizeBox = false;
	languageForm->MaximizeBox = false;
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
	aboutForm->ShowInTaskbar = false;
	aboutForm->ShowDialog();
}

System::Void LuccME::NovoModelo::novoToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	lReturn = NEWMODEL;
	this->Close();
}

System::Void LuccME::NovoModelo::abrirToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	lReturn = OPENMODEL;
	this->Close();
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
	if (!closing && !runnable) {
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
	else if (!closing && runnable) {
		if (gParametersValues[0] != lSelectedFolder->Text || gParametersValues[1] != tModelName->Text || gParametersValues[2] != tStartTime->Text ||
			gParametersValues[3] != tEndTime->Text || gParametersValues[4] != tThemeName->Text || gParametersValues[5] != tbSelectedBatabase->Lines[1]->ToString() ||
			gParametersValues[6] != tCellArea->Text || gParametersValues[7] != lDynamicConfirm->Text || gParametersValues[8] != tScenariosStartTime->Text ||
			gParametersValues[9] != tScenarioName->Text || gParametersValues[10] != lLUTShow->Text || gParametersValues[11] != lLUNDShow->Text ||
			gParametersValues[12] != tOutputTheme->Text || gParametersValues[13] != lYearsToSave->Text || gParametersValues[14] != lAttrToSave->Text ||
			gParametersValues[15] != tbDemand->Lines[0]->ToString() || gParametersValues[16] != tbPotential->Lines[0]->ToString() ||
			gParametersValues[17] != tbAllocation->Lines[0]->ToString()) {
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
		if (shape) {
			lScenarioYears->Visible = true;
			lvYearScenario->Visible = true;
			bScenario->Visible = true;
			lScenarioYearsConfirm->Visible = true;
		}
	}
	else {
		lScenariosStartTime->Visible = false;
		tScenariosStartTime->Visible = false;
		lScenarioName->Visible = false;
		tScenarioName->Visible = false;
		lScenarioYears->Visible = false;
		lvYearScenario->Visible = false;
		bScenario->Visible = false;
		lScenarioYearsConfirm->Visible = false;
	}
}

System::Void LuccME::NovoModelo::bValidate_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool checked = true;

	if (tbSelectedBatabase->Text == "") {
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
	else if (!cbValidationMethod->SelectedItem) {
		MessageBox::Show(gSValSectMet, gSValSectMetTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}
	else if (checked) {
		String^ path = "validation.lua";
		StreamWriter^ sw = File::CreateText(path);

		//Function to hold the cmd open when catch an error
		sw->WriteLine("error = function(message, code)");
		sw->WriteLine("\tprint(message)");
		sw->WriteLine("\tlocal answer");
		sw->WriteLine("\trepeat");
		sw->WriteLine("\t\tio.write(\"\\nPress enter key to exit...\")");
		sw->WriteLine("\t\tio.flush()");
		sw->WriteLine("\t\tanswer = io.read()");
		sw->WriteLine("\tuntil answer ~= \"`\"");
		sw->WriteLine("\tos.exit()");
		sw->WriteLine("end");
		sw->WriteLine("");

		if (shape) {
			sw->WriteLine("import(\"terralib\")");
			sw->WriteLine("proj = Project{");
			sw->WriteLine("\tfile = \"t3mp.tview\",");
			sw->WriteLine("\tclean = true");
			sw->WriteLine("}");
			sw->WriteLine("l1 = Layer{");
			sw->WriteLine("\tproject = proj,");
			sw->WriteLine("name = \"layer\",");

			String^ aux = tbSelectedBatabase->Lines[1]->ToString();
			int i = aux->Length - 1;

			while (i > 0) {
				if (aux[i] == '\\') {
					aux = aux->Substring(0, i);
					break;
				}
				i--;
			}

			sw->WriteLine("file = \"" + aux->Replace("\\", "\\\\") + "\\\\" + tInputThemeName->Text->Replace(".shp", "") + ".shp\"");
			sw->WriteLine("}");
		}
		
		//Input parameters
		sw->WriteLine("numberOfWindows = " + tNumberWindows->Text);
		if (cValidationSave->Checked) {
			sw->WriteLine("flag_save = true");
		}
		else {
			sw->WriteLine("flag_save = false");
		}
		sw->WriteLine("final_year = " + tEndTime->Text);
		sw->WriteLine("");
		sw->WriteLine("input_theme_name = \"" + tInputThemeName->Text + "\"");
		sw->WriteLine("last_sim = \"" + tAttributeForValidation->Text + "\"");
		sw->WriteLine("init_real = \"" + tAttributeInitValidation->Text + "\"");
		sw->WriteLine("last_real = \"" + tAttributeFinalValidation->Text + "\"");
		sw->WriteLine("");

		if (!shape) {
			sw->WriteLine("cs = CellularSpace {");
			sw->WriteLine("\t\tproject = \"" + tbSelectedBatabase->Lines[1]->ToString()->Replace("\\", "\\\\") + "\",");
			sw->WriteLine("\t\tlayer = input_theme_name");
			sw->WriteLine("}");
		}
		else {
			sw->WriteLine("cs = CellularSpace {");
			sw->WriteLine("\t\tproject = \"t3mp.tview\",");
			sw->WriteLine("\t\tlayer = \"layer\"");
			sw->WriteLine("}");
		}

		sw->WriteLine("");
		sw->WriteLine("range = " + tRange->Text + " / 100");
		
		String^ folderAux = "";

		switch (cbValidationMethod->SelectedIndex)
		{
			//Ext Method
			case 0:
				folderAux = lSelectedFolder->Text->Replace("\\", "\\\\");
				if (folderAux->Length > ROOTDIR) {
					sw->WriteLine("file = io.open(\"" + folderAux + "\\\\" + tModelName->Text->ToLower() + "_ext_result.txt\", \"w\")\n");
				}
				else {
					sw->WriteLine("file = io.open(\"" + folderAux + tModelName->Text->ToLower() + "_ext_result.txt\", \"w\")\n");
				}
				sw->WriteLine("output_theme = \"validation_ext_" + tInputThemeName->Text + "_" + tAttributeForValidation->Text +"_\"");
				sw->WriteLine("");
				sw->WriteLine("attribute1 = \"sim\"");
				sw->WriteLine("attribute2 = \"diff\"");
				sw->WriteLine("");
				sw->WriteLine("if cs.cells[1][init_real] == nil then error(\"Attribute: \"..init_real..\". Does not exist in the theme.\") end");
				sw->WriteLine("if cs.cells[1][last_real] == nil then error(\"Attribute: \"..last_real..\". Does not exist in the theme.\") end");
				sw->WriteLine("if cs.cells[1][last_sim] == nil then error(\"Attribute: \"..last_sim..\". Does not exist in the theme.\") end");
				sw->WriteLine("");
				sw->WriteLine("forEachCell(cs, function(cell) ");
				sw->WriteLine("\tcell[attribute1] = cell[last_sim]");
				sw->WriteLine("\tcell[attribute2] = cell[last_real]");
				sw->WriteLine("end)");
				sw->WriteLine("");
				sw->WriteLine("MultiRes = function(cs1, attribute1, cs2, attribute2, window)");
				sw->WriteLine("\tforEachCell(cs2, function(cell) cell.flag = 0 end)");
				sw->WriteLine("");
				sw->WriteLine("\tlocal count = 0");
				sw->WriteLine("\tlocal diff = 0");
				sw->WriteLine("\tlocal sum = 0");
				sw->WriteLine("\tlocal cc1 = {}");
				sw->WriteLine("\tlocal cc2 = {}");
				sw->WriteLine("\tlocal internalcount = 0");
				sw->WriteLine("");
				sw->WriteLine("\tforEachCell(cs2, function(cell)");
				sw->WriteLine("\t\tinternalcount = 0");
				sw->WriteLine("\t\tsumcc1 = 0");
				sw->WriteLine("\t\tsumcc2 = 0");
				sw->WriteLine("");
				sw->WriteLine("\t\tif cell.flag == 0 then");
				sw->WriteLine("\t\t\tfor xx = 0, (window - 1) do");
				sw->WriteLine("\t\t\t\tfor yy = 0,(window - 1) do");
				sw->WriteLine("\t\t\t\t\tif cs1:get(cell.x + xx, cell.y + yy) ~= nil then");
				sw->WriteLine("\t\t\t\t\t\tinternalcount = internalcount + 1");
				sw->WriteLine("\t\t\t\t\t\tcc1[internalcount] = cs1:get(cell.x + xx, cell.y + yy)");
				sw->WriteLine("\t\t\t\t\t\tcc2[internalcount] = cs2:get(cell.x + xx, cell.y + yy)");
				sw->WriteLine("\t\t\t\t\tend");
				sw->WriteLine("\t\t\t\tend");
				sw->WriteLine("\t\t\tend");
				sw->WriteLine("");
				sw->WriteLine("\t\t\tfor j = 1, internalcount do");
				sw->WriteLine("\t\t\t\tsumcc1 = sumcc1 + cc1[j][attribute1]");
				sw->WriteLine("\t\t\t\tsumcc2 = sumcc2 + cc2[j][attribute2]");
				sw->WriteLine("\t\t\tend");
				sw->WriteLine("");
				sw->WriteLine("\t\t\tif math.abs((sumcc2 - sumcc1)/internalcount) < range then sumcc1 = sumcc2 end");
				sw->WriteLine("");
				sw->WriteLine("\t\t\tdiffcell = (sumcc2 - sumcc1)");
				sw->WriteLine("\t\t\tcount = count + internalcount");
				sw->WriteLine("");
				sw->WriteLine("\t\t\tfor i = 1, internalcount do");
				sw->WriteLine("\t\t\t\tcc2[i][\"diff\"..window] = diffcell");
				sw->WriteLine("\t\t\t\tcc2[i].flag = 1");
				sw->WriteLine("\t\t\tend");
				sw->WriteLine("");
				sw->WriteLine("\t\t\tsum = sum + math.abs(sumcc2)");
				sw->WriteLine("\t\t\tdiff = diff + math.abs(diffcell)");
				sw->WriteLine("");
				sw->WriteLine("\t\t\treturn true");
				sw->WriteLine("\t\tend");
				sw->WriteLine("\tend)");
				sw->WriteLine("");
				sw->WriteLine("\treturn count, diff, sum");
				sw->WriteLine("end");
				sw->WriteLine("");
				sw->WriteLine("file:write(\"======================================================\")");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"======================================================\")");
				if (gAllocationComponent > NUMDISCALLOCCOMP) {
					sw->WriteLine("file:write(\"Validation Metric for Continuous Data - version 1.0\\n\")");
					sw->WriteLine("file:write(\"\\n\")");
					sw->WriteLine("print(\"Validation Metric for Continuous Data - version 1.0\\n\")");
				}
				else {
					sw->WriteLine("file:write(\"Validation Metric for Discrete Data - version 1.0\\n\")");
					sw->WriteLine("file:write(\"\\n\")");
					sw->WriteLine("print(\"Validation Metric for Discrete Data - version 1.0\\n\")");
				}
				sw->WriteLine("file:write(\"layer\t\t : \", input_theme_name)");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"layer\t\t : \", input_theme_name)");
				sw->WriteLine("file:write(\"attr REAL initial:\", init_real)");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"attr REAL initial:\", init_real)");
				sw->WriteLine("file:write(\"attr REAL final  :\", last_real)");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"attr REAL final  :\", last_real)");
				sw->WriteLine("file:write(\"attr SIM  final  :\", last_sim)");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"attr SIM  final  :\", last_sim)");
				sw->WriteLine("file:write(\"Accepted error   :\", (range * 100)..\"%\")");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"Accepted error   :\", (range * 100)..\"%\")");
				sw->WriteLine("file:write(\"======================================================\\n\")");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"======================================================\\n\")");
				sw->WriteLine("");
				sw->WriteLine("file:write(\"" + gSValExt->Replace("print(\"",""));
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine(gSValExt);
				sw->WriteLine("io.flush()");
				sw->WriteLine("attrs = {}");
				sw->WriteLine("");
				sw->WriteLine("for i = 1, numberOfWindows do");
				sw->WriteLine("\tattrs[i]=\"diff\"..i");
				sw->WriteLine("");
				sw->WriteLine("\ttotal, diff, sum = MultiRes(cs, attribute1, cs, attribute2, i)");
				sw->WriteLine("");
				sw->WriteLine("\tif (sum < diff) then total, diff, sum = MultiRes(cs, attribute2, cs, attribute1, i) end");
				sw->WriteLine("\tif (sum == 0) then sum = 0.00001 end");
				sw->WriteLine("");
				sw->WriteLine("\tfile:write(i..\"\\t\", string.format(\"%.2f\",((1 - diff / (2 * sum)) * 100))..\" %\")");
				sw->WriteLine("\tfile:write(\"\\n\")");
				sw->WriteLine("\tprint(i, string.format(\"%.2f\",((1 - diff / (2 * sum)) * 100))..\" %\")");
				sw->WriteLine("\tio.flush()");
				sw->WriteLine("end");
				sw->WriteLine("");
				sw->WriteLine("forEachCell(cs, function(cell)");
				sw->WriteLine("\t\t\t\t for i = 1, #attrs do");
				sw->WriteLine("\t\t\t\t\tif(not cell[attrs[i]]) then	cell[attrs[i]] = 0 end");
				sw->WriteLine("\t\t\t\tend");
				sw->WriteLine("end)");
				sw->WriteLine("");
				sw->WriteLine("if (flag_save) then");
				sw->WriteLine("\tprint(\"\\nSaving \"..output_theme..\" into database.\")");
				sw->WriteLine("\tcs:save(output_theme, attrs)");
				sw->WriteLine("end");
				sw->WriteLine("");
				sw->WriteLine("file:close()");
				break;

			//Diff Method
			case 1:
				folderAux = lSelectedFolder->Text->Replace("\\", "\\\\");
				if (folderAux->Length > ROOTDIR) {
					sw->WriteLine("file = io.open(\"" + folderAux + "\\\\" + tModelName->Text->ToLower() + "_diff_result.txt\", \"w\")\n");
				}
				else {
					sw->WriteLine("file = io.open(\"" + folderAux + tModelName->Text->ToLower() + "_diff_result.txt\", \"w\")\n");
				}
				sw->WriteLine("output_theme = \"validation_diff_" + tInputThemeName->Text + "_" + tAttributeForValidation->Text + "_\"");
				sw->WriteLine("");
				sw->WriteLine("attribute1 = \"diff_sim\"");
				sw->WriteLine("attribute2 = \"diff_real\"");
				sw->WriteLine("");
				sw->WriteLine("if cs.cells[1][init_real] == nil then error(\"Attribute: \"..init_real..\". Does not exist in the theme.\") end");
				sw->WriteLine("if cs.cells[1][last_real] == nil then error(\"Attribute: \"..last_real..\". Does not exist in the theme.\") end");
				sw->WriteLine("if cs.cells[1][last_sim] == nil then error(\"Attribute: \"..last_sim..\". Does not exist in the theme.\") end");
				sw->WriteLine("");
				sw->WriteLine("forEachCell(cs, function(cell) ");
				sw->WriteLine("\tcell[attribute1] = cell[last_sim] - cell[init_real]");
				sw->WriteLine("\tcell[attribute2] = cell[last_real] - cell[init_real]");
				sw->WriteLine("end)");
				sw->WriteLine("");
				sw->WriteLine("MultiRes = function(cs1, attribute1, cs2, attribute2, window)");
				sw->WriteLine("\tforEachCell(cs2, function(cell) cell.flag = 0 end)");
				sw->WriteLine("");
				sw->WriteLine("\tlocal count = 0");
				sw->WriteLine("\tlocal diff = 0");
				sw->WriteLine("\tlocal sum = 0");
				sw->WriteLine("\tlocal cc1 = {}");
				sw->WriteLine("\tlocal cc2 = {}");
				sw->WriteLine("\tlocal internalcount = 0");
				sw->WriteLine("");
				sw->WriteLine("\tforEachCell(cs2, function(cell)");
				sw->WriteLine("\t\tinternalcount = 0");
				sw->WriteLine("\t\tsumcc1 = 0");
				sw->WriteLine("\t\tsumcc2 = 0");
				sw->WriteLine("");
				sw->WriteLine("\t\tif cell.flag == 0 then");
				sw->WriteLine("\t\t\tfor xx = 0, (window - 1) do");
				sw->WriteLine("\t\t\t\tfor yy = 0, (window - 1) do");
				sw->WriteLine("\t\t\t\t\tif cs1:get(cell.x + xx, cell.y + yy) ~= nil then");
				sw->WriteLine("\t\t\t\t\t\tinternalcount = internalcount + 1");
				sw->WriteLine("\t\t\t\t\t\tcc1[internalcount] = cs1:get(cell.x + xx, cell.y + yy)");
				sw->WriteLine("\t\t\t\t\t\tcc2[internalcount] = cs2:get(cell.x + xx, cell.y + yy)");
				sw->WriteLine("\t\t\t\t\tend");
				sw->WriteLine("\t\t\t\tend");
				sw->WriteLine("\t\t\tend");
				sw->WriteLine("");
				sw->WriteLine("\t\t\tfor j = 1, internalcount do");
				sw->WriteLine("\t\t\t\tsumcc1 = sumcc1 + cc1[j][attribute1]");
				sw->WriteLine("\t\t\t\tsumcc2 = sumcc2 + cc2[j][attribute2]");
				sw->WriteLine("\t\t\tend");
				sw->WriteLine("");
				sw->WriteLine("\t\t\tif math.abs((sumcc2 - sumcc1)/internalcount) < range then sumcc1 = sumcc2 end");
				sw->WriteLine("");
				sw->WriteLine("\t\t\tdiffcell = (sumcc2 - sumcc1)");
				sw->WriteLine("\t\t\tcount = count + 1");
				sw->WriteLine("");
				sw->WriteLine("\t\t\tfor i = 1, internalcount do");
				sw->WriteLine("\t\t\t\tcc2[i][\"diff\"..window] = diffcell");
				sw->WriteLine("\t\t\t\tcc2[i].flag = 1");
				sw->WriteLine("\t\t\tend");
				sw->WriteLine("");
				sw->WriteLine("\t\t\tsum = sum + math.abs(sumcc2)");
				sw->WriteLine("\t\t\tdiff = diff + math.abs(diffcell)");
				sw->WriteLine("");
				sw->WriteLine("\t\t\treturn true");
				sw->WriteLine("\t\tend");
				sw->WriteLine("\tend)");
				sw->WriteLine("");
				sw->WriteLine("\treturn count * window * window, diff, sum");
				sw->WriteLine("end");
				sw->WriteLine("");
				sw->WriteLine("file:write(\"======================================================\")");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"======================================================\")");
				if (gAllocationComponent > NUMDISCALLOCCOMP) {
					sw->WriteLine("file:write(\"Validation Metric for Continuous Data - version 1.0\\n\")");
					sw->WriteLine("file:write(\"\\n\")");
					sw->WriteLine("print(\"Validation Metric for Continuous Data - version 1.0\\n\")");
				}
				else {
					sw->WriteLine("file:write(\"Validation Metric for Discrete Data - version 1.0\\n\")");
					sw->WriteLine("file:write(\"\\n\")");
					sw->WriteLine("print(\"Validation Metric for Discrete Data - version 1.0\\n\")");
				}
				sw->WriteLine("file:write(\"layer\t\t : \", input_theme_name)");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"layer\t\t : \", input_theme_name)");
				sw->WriteLine("file:write(\"attr REAL initial:\", init_real)");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"attr REAL initial:\", init_real)");
				sw->WriteLine("file:write(\"attr REAL final  :\", last_real)");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"attr REAL final  :\", last_real)");
				sw->WriteLine("file:write(\"attr SIM  final  :\", last_sim)");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"attr SIM  final  :\", last_sim)");
				sw->WriteLine("file:write(\"Accepted error   :\", (range * 100)..\"%\")");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"Accepted error   :\", (range * 100)..\"%\")");
				sw->WriteLine("file:write(\"======================================================\\n\")");
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine("print(\"======================================================\\n\")");
				sw->WriteLine("");
				sw->WriteLine("file:write(\"" + gSValDiff->Replace("print(\"", ""));
				sw->WriteLine("file:write(\"\\n\")");
				sw->WriteLine(gSValDiff);
				sw->WriteLine("io.flush()");
				sw->WriteLine("attrs = {}");
				sw->WriteLine("");
				sw->WriteLine("for i = 1, numberOfWindows do");
				sw->WriteLine("\tattrs[i]=\"diff\"..i");
				sw->WriteLine("");
				sw->WriteLine("\ttotal, diff, sum = MultiRes(cs, attribute1, cs, attribute2, i)");
				sw->WriteLine("");
				sw->WriteLine("\tif (sum == 0) then sum = 0.00001 end");
				sw->WriteLine("");
				sw->WriteLine("\tif ((i == 1) or (i % 1 == 0)) then");
				sw->WriteLine("\t\tif (1 - diff / (2 * sum) >= 0) then");
				sw->WriteLine("\t\t\tfile:write(i..\"\\t\", string.format(\"%.2f\",((1 - diff / (2 * sum)) * 100))..\" %\")");
				sw->WriteLine("\t\t\tfile:write(\"\\n\")");
				sw->WriteLine("\t\t\tprint(i, string.format(\"%.2f\",((1 - diff / (2 * sum)) * 100))..\" %\")");
				sw->WriteLine("\t\telse");
				sw->WriteLine("\t\t\tfile:write(i..\"\\t\",\"0.00 %\")");
				sw->WriteLine("\t\t\tprint(i, \"0.00 %\")");
				sw->WriteLine("\t\tend");
				sw->WriteLine("\tend");
				sw->WriteLine("\tio.flush()");
				sw->WriteLine("end");
				sw->WriteLine("");
				sw->WriteLine("forEachCell(cs, function(cell)");
				sw->WriteLine("\t\t\t\t for i = 1, #attrs do");
				sw->WriteLine("\t\t\t\t\tif(not cell[attrs[i]]) then	cell[attrs[i]] = 0 end");
				sw->WriteLine("\t\t\t\tend");
				sw->WriteLine("end)");
				sw->WriteLine(""); 
				sw->WriteLine("if (flag_save) then");
				sw->WriteLine("\tprint(\"\\nSaving \"..output_theme..\" into database.\")");
				sw->WriteLine("\tcs:save(output_theme, attrs)");
				sw->WriteLine("end");
				sw->WriteLine("");
				sw->WriteLine("file:close()");
				break;
			default:
				break;
		}

		//Hold cmd open
		sw->WriteLine("print(\"\\nEnd of Validation\")");
		sw->WriteLine("");
		sw->WriteLine("local answer");
		sw->WriteLine("repeat");
		sw->WriteLine("\tio.write(\"\\nPress enter key to exit...\")");
		sw->WriteLine("\tio.flush()");
		sw->WriteLine("\tanswer = io.read()");
		sw->WriteLine("until answer ~= \"`\"");

		sw->Close();

		Environment::SetEnvironmentVariable("TME_PATH", "C:\\Luccme\\Terrame\\bin");
		Environment::SetEnvironmentVariable("PATH", "C:\\Luccme\\Terrame\\bin");

		String^ arguments = "validation.lua";
		System::Diagnostics::Process^ cmd = gcnew System::Diagnostics::Process;

		cmd->StartInfo->FileName = "C:\\LuccME\\TerraME\\bin\\TerraME.exe";
		cmd->StartInfo->Arguments = arguments;
		cmd->Start();
		cmd->WaitForExit();
		cmd->Close();

		if (cSaveValidationFile->Checked == true) {
			FileInfo^ copyValidation = gcnew FileInfo("validation.lua");
			if (gAllocationComponent > NUMDISCALLOCCOMP) {
				if (cbValidationMethod->SelectedIndex == 0) {
					copyValidation->CopyTo(lSelectedFolder->Text + "\\" + "validationExtContinuous.lua");
				}
				else {
					copyValidation->CopyTo(lSelectedFolder->Text + "\\validationDifContinuous.lua");
				}
			}
			else {
				if (cbValidationMethod->SelectedIndex == 0) {
					copyValidation->CopyTo(lSelectedFolder->Text + "\\validationExtDiscrete.lua");
				}
				else {
					copyValidation->CopyTo(lSelectedFolder->Text + "\\validationDifDiscrete.lua");
				}
			}
		}

		//Delete file after cmd closes
		if (File::Exists("validation.lua"))
		{
			File::Delete("validation.lua");
		}

		if (File::Exists("t3mp.tview"))
		{
			File::Delete("t3mp.tview");
		}
	}
}

System::Void LuccME::NovoModelo::tAttributeInitValidation_Leave(System::Object^  sender, System::EventArgs^  e) {
	if (tAttributeForValidation->ForeColor != System::Drawing::Color::Black) {
		tAttributeForValidation->Text = tAttributeInitValidation->Text + "_out";
	}

	if (tAttributeFinalValidation->ForeColor != System::Drawing::Color::Black) {
		tAttributeFinalValidation->Text = tAttributeInitValidation->Text + tEndTime->Text;
	}
}

System::Void LuccME::NovoModelo::tModelName_Leave(System::Object^  sender, System::EventArgs^  e)
{
	tModelName->Text = tModelName->Text->Replace(" ", "");
}

System::Void LuccME::NovoModelo::bShape_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Open the dialog to select the shape file and return the path
	LuccME::OpenFileDialog^ bdFile = gcnew OpenFileDialog;
	bdFile->Title = gSShapeTitle;
	bdFile->Multiselect = false;
	bdFile->Filter = gSShapeFilter;
	bdFile->FilterIndex = 1;
	bdFile->ShowHelp = true;

	if (bdFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		gSelectedDatabase = bdFile->FileName;
		array<String^>^ lines = { gSShape, bdFile->FileName };
		tbSelectedBatabase->Lines = lines;
		shape = true;
		tThemeName->Text = "layer";
		tThemeName->Enabled = false;
	}
}

System::Void LuccME::NovoModelo::bScenario_Click(System::Object^  sender, System::EventArgs^  e)
{
	lScenarioYearsConfirm->Text = "";
	for (int i = 0; i < lvYearScenario->Items->Count; i++) {
		if (lvYearScenario->Items[i]->Selected) {
			lScenarioYearsConfirm->Text += lvYearScenario->Items[i]->Text + ", ";
		}
	}
	if (lScenarioYearsConfirm->Text != "") {
		lScenarioYearsConfirm->Text = lScenarioYearsConfirm->Text->Substring(0, lScenarioYearsConfirm->Text->Length - 2);
	}
}

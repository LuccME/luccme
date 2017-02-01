#pragma once

namespace LuccME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System;
	using namespace System::IO;

	/// <summary>
	/// Summary for NovoModelo
	/// </summary>
	public ref class NovoModelo : public System::Windows::Forms::Form
	{
	private: 
		String^ gSScenST = "";
		String^ gSScenSTTitle = "";
		String^ gSScenName = "";
		String^ gSScenNameTitle = "";
		String^ gSCheckDyn = "";
		String^ gSCheckDynTitle = "";
		String^ gSImportError = "";
		String^ gSImportErrorTitle = "";
		String^ gSPotContAlocDisc = "";
		String^ gSPotContAlocDiscTitle = "";
		String^ gSPotDiscAlocCont = "";
		String^ gSUnauthorized = "";
		String^ gSUnauthorizedTitle = "";
		String^ gSExit = "";
		String^ gSExitTitle = "";
		String^ gSSuccessTitle = "";
		String^ gSSuccess = "";
		String^ gSEditing = "";
		String^ gSHost = "host = ";
		String^ gSUser = "user = ";
		String^ gSPassword = "password = ";
		String^ gSDatabase = "database = ";
		String^ gSNewModel = "";
		String^ gSNewModelTitle = "";
		String^ gSOpenModelTitle = "";
		String^ gSProject = "";
		String^ gSMainImport = "";
		String^ gSMainImportTitle = "";
		String^ gSMainLoad = "";
		String^ gSMainLoadTitle = "";
		String^ gSMainFile = "";
		String^ gSSubmodelFile = "";
		String^ gSLuaFile = "";
		String^ gSDBTitle = "";
		String^ gSDBFilter = "";
		String^ gSShape = "";
		String^ gSShapeTitle = "";
		String^ gSShapeFilter = "";
		String^ gSLUTManager = ""; 
		String^ gSDemand1Info = ""; 
		String^ gSDemand1Title = "";
		String^ gSDemand2Info = "";
		String^ gSDemand2Title = "";
		String^ gSDefaultTime = "";
		String^ gStringDefaultTimeTitle = "";
		String^ gSLUTNotDef = "";
		String^ gSLUTNotDefTitle = "";
		String^ gSTimeNotDef = "";
		String^ gSTimeNotDefTitle = "";
		String^ gSLUT = "";
		String^ gSAnos = "";
		String^ gSFolder = "";
		String^ gSFolderTitle = "";
		String^ gSModelName = "";
		String^ gSModelNameTitle = "";
		String^ gSStartTime = "";
		String^ gSStartTimeTitle = "";
		String^ gSEndTime = "";
		String^ gSEndTimeTitle = "";
		String^ gSDBSave = "";
		String^ gSDBSaveTitle = "";
		String^ gSThemeName = "";
		String^ gSThemeNameTitle = "";
		String^ gSCellArea = "";
		String^ gSCellAreaTitle = "";
		String^ gSLUTShow = "";
		String^ gSLUTShowTitle = "";
		String^ gSLUTNDShow = "";
		String^ gSLUTNDShowTitle = "";
		String^ gSDemandnS = "";
		String^ gSDemandnSTitle = "";
		String^ gSPotentialnS = "";
		String^ gSPotentialnSTitle = "";
		String^ gSAllocationnS = "";
		String^ gSAllocationnSTitle = "";
		String^ gSOutputTheme = "";
		String^ gSOutputThemeTitle = "";
		String^ gSYearSave = "";
		String^ gSYearSaveTitle = "";
		String^ gSAlloCont = "";
		String^ gSPotDiscTitle = "";
		String^ gSAlloDisc = "";
		String^ gSPotContTitle = "";
		String^ gSPotCont = "";
		String^ gSAllocDiscTitle = "";
		String^ gSPotDisc = "";
		String^ gSAllocContTitle = "";
		String^ gSMFE = "";
		String^ gSMFETitle = "";
		String^ gSSMFE = "";
		String^ gSFE = "";
		String^ gSValSectMet = "";
		String^ gSValSectMetTitle = "";
		String^ gSValExt = "";
		String^ gSValDiff = "";
		String^ gSAttribToSave = "";
		String^ gSAttribToSaveTitle = "";
		String^ gSPotCont2Info = "";
		String^ gSPotCont2Title = "";
		String^ gSMainImportOld = "";
		String^ gSMainImportOldtTitle = "";
		String^ gSFileMissing = "";
		String^ gSFileMissing2 = "";
		String^ gSFileMissingTitle = "";
		String^ gSScenSYU = "";
		String^ gSScenSYUTitle = "";

	public:
		bool closing = false;
		bool forceWriting = false;
		bool runnable = false;
		bool shape = false;
		bool lOpen = false;

		int gDemandComponent = 0;
		int gPotentialComponent = 0;
		int gAllocationComponent = 0;
		int gAttrTime = 0;
		int gDynTime = 0;
		int gPotentialRegression = 1;

		String^ gLandUseTypes = "";
		String^ gLandUseNoData = "";
		String^ gSelectedDatabase = "";
		String^ gDemand = "";
		String^ gDemandLUT = "";
		String^ gDemandFinalYear = "";
		String^ gDemandMiddleYear = "";
		String^ gPotential = "";
		String^ gPotentialLUT = "";
		String^ gAllocation = "";
		String^ gAllocationLUT = "";
		String^ gAttrLUT = "";
		String^ lLanguage;
		
		array<String^>^ gParametersValues = gcnew array<String^>(21);
		//[0] = lSelectedFolder->Text;
		//[1] = tModelName->Text;
		//[2] = tStartTime->Text;
		//[3] = tEndTime->Text;
		//[4] = tThemeName->Text;
		//[5] = tbSelectedBatabase->Lines[1]->ToString();
		//[6] = tCellArea->Text;
		//[7] = lDynamicConfirm->Text;
		//[8] = tScenariosStartTime->Text;
		//[9] = tScenarioName->Text;
		//[10] = lLUTShow->Text;
		//[11] = lLUNDShow->Text;
		//[12] = tOutputTheme->Text;
		//[13] = lYearsToSave->Text;
		//[14] = lAttrToSave->Text;
		//[15] = tbDemand->Lines[0]->ToString();
		//[16] = tbPotential->Lines[0]->ToString();
		//[17] = tbAllocation->Lines[0]->ToString();

	public:
		int lReturn;
		NovoModelo(String^ pLanguage, bool pOpen, int pReturn)
		{
			InitializeComponent();
			lLanguage = pLanguage;
			lOpen = pOpen;
			lReturn = pReturn;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NovoModelo()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  lShape;
	private: System::Windows::Forms::Button^  bShape;
	private: System::Windows::Forms::Label^  lTerraview;
	private: System::Windows::Forms::Button^  bScenario;
	private: System::Windows::Forms::Label^  lScenarioYearsConfirm;
	private: System::Windows::Forms::Label^  lScenarioYears;
	private: System::Windows::Forms::ListView^  lvYearScenario;
	private: System::Windows::Forms::CheckBox^  cReg;
	private: System::Windows::Forms::CheckBox^  cChange;
	private: System::Windows::Forms::CheckBox^  cPot;
	private: System::Windows::Forms::Label^  lSaidaAdicionais;
	private: System::Windows::Forms::CheckBox^  cSaveValidationFile;
	private: System::Windows::Forms::CheckBox^  cAuxOut;
	private: System::Windows::Forms::TextBox^  tbSelectedBatabase;
	private: System::Windows::Forms::TextBox^  tbDemand;
	private: System::Windows::Forms::Button^  bPotContinuous;
	private: System::Windows::Forms::Button^  bPotDiscrete;
	private: System::Windows::Forms::TextBox^  tbPotential;
	private: System::Windows::Forms::Label^  lPotential;
	private: System::Windows::Forms::TextBox^  tbAllocation;
	private: System::Windows::Forms::Button^  bAllocContinuous;
	private: System::Windows::Forms::Button^  bAllocDiscrete;
	private: System::Windows::Forms::Label^  lAllocation;
	private: System::Windows::Forms::TabPage^  tabSaveParam;
	private: System::Windows::Forms::Label^  lSalvar;
	private: System::Windows::Forms::TextBox^  tOutputTheme;
	private: System::Windows::Forms::Label^  lOutputTheme;
	private: System::Windows::Forms::CheckBox^  cSaveYearly;
	private: System::Windows::Forms::Label^  lSelectYears;
	private: System::Windows::Forms::ListView^  lvYearsToSave;
	private: System::Windows::Forms::Label^  lSaveAttr;
	private: System::Windows::Forms::ListView^  lvSaveAttr;
	private: System::Windows::Forms::Button^  bSelectedYears;
	private: System::Windows::Forms::Label^  lYearsToSave;
	private: System::Windows::Forms::Label^  lAttrToSave;
	private: System::Windows::Forms::Button^  bSelectedAttr;
	private: System::Windows::Forms::TabPage^  tabFileMaker;
	private: System::Windows::Forms::Label^  lFileMaker;
	private: System::Windows::Forms::Button^  bGerarArquivos;
	private: System::Windows::Forms::CheckBox^  cIsCoupled;
	private: System::Windows::Forms::Button^  bRun;
	private: System::Windows::Forms::Label^  lRunModel;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;
	private: System::Windows::Forms::TabPage^  tabAdvRes;
	private: System::Windows::Forms::CheckBox^  cDynamicVariables;
	private: System::Windows::Forms::Label^  lAtualizaveis;
	private: System::Windows::Forms::Button^  bDynamicSelect;
	private: System::Windows::Forms::Label^  lDynamicConfirm;
	private: System::Windows::Forms::Label^  lAnosVariaveis;
	private: System::Windows::Forms::ListView^  lvYearsDynamic;
	private: System::Windows::Forms::CheckBox^  cScenario;
	private: System::Windows::Forms::TextBox^  tScenariosStartTime;
	private: System::Windows::Forms::Label^  lScenariosStartTime;
	private: System::Windows::Forms::TextBox^  tScenarioName;
	private: System::Windows::Forms::Label^  lScenarioName;
	private: System::Windows::Forms::TabPage^  tabValidation;
	private: System::Windows::Forms::Button^  bValidate;
	private: System::Windows::Forms::TextBox^  tAttributeFinalValidation;
	private: System::Windows::Forms::Label^  lAttributeFinalValidation;
	private: System::Windows::Forms::TextBox^  tAttributeInitValidation;
	private: System::Windows::Forms::Label^  lAttributeInitValidation;
	private: System::Windows::Forms::TextBox^  tAttributeForValidation;
	private: System::Windows::Forms::Label^  lAttributeForValidation;
	private: System::Windows::Forms::TextBox^  tInputThemeName;
	private: System::Windows::Forms::Label^  lInputThemeName;
	private: System::Windows::Forms::ComboBox^  cbValidationMethod;
	private: System::Windows::Forms::Label^  lValidationMethod;
	private: System::Windows::Forms::TextBox^  tNumberWindows;
	private: System::Windows::Forms::Label^  lNumbWindows;
	private: System::Windows::Forms::TextBox^  tRange;
	private: System::Windows::Forms::Label^  lRange;
	private: System::Windows::Forms::Label^  lSimResult;
	private: System::Windows::Forms::Label^  lThemeHelp;
	private: System::Windows::Forms::CheckBox^  cValidationSave;
	private: System::Windows::Forms::Label^  lRangeHelp;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  arquivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  novoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ajudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  luccMEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  preferênciasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  idiomaToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  tNovoModelo;
	private: System::Windows::Forms::TabPage^  tabDefModel;
	private: System::Windows::Forms::TextBox^  tEndTime;
	private: System::Windows::Forms::Label^  lEndTime;
	private: System::Windows::Forms::Label^  lDefinicoesModelo;
	private: System::Windows::Forms::Label^  lArquivos;
	private: System::Windows::Forms::TextBox^  tStartTime;
	private: System::Windows::Forms::Label^  lStartTime;
	private: System::Windows::Forms::TextBox^  tModelName;
	private: System::Windows::Forms::Label^  lModelName;
	private: System::Windows::Forms::Label^  lSelectedFolder;
	private: System::Windows::Forms::Button^  bSelectFolder;
	private: System::Windows::Forms::Label^  lDirProj;
	private: System::Windows::Forms::TabPage^  tabDefSpatial;
	private: System::Windows::Forms::Button^  bSelectDatabase;
	private: System::Windows::Forms::TextBox^  tCellArea;
	private: System::Windows::Forms::Label^  lCellArea;
	private: System::Windows::Forms::TextBox^  tThemeName;
	private: System::Windows::Forms::Label^  lThemeName;
	private: System::Windows::Forms::Label^  lSpacialDimensions;
	private: System::Windows::Forms::Label^  lSelectedBatabase;
	private: System::Windows::Forms::Label^  lDatabase;
	private: System::Windows::Forms::TabPage^  tabLUT;
	private: System::Windows::Forms::Label^  lLUNDShow;
	private: System::Windows::Forms::Button^  bLUNDManager;
	private: System::Windows::Forms::Label^  lLUND;
	private: System::Windows::Forms::Label^  lLUTShow;
	private: System::Windows::Forms::Button^  bLUTManager;
	private: System::Windows::Forms::Label^  lLUTMedium;
	private: System::Windows::Forms::Label^  lLUTLarge;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::TabPage^  tabComponent;
	private: System::Windows::Forms::Button^  bD_CIThreeDM;
	private: System::Windows::Forms::Button^  bD_CITwoDM;
	private: System::Windows::Forms::Button^  bD_PCVINPE;
	private: System::Windows::Forms::Label^  lDemand;
	private: System::Windows::Forms::Label^  lComponentes;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(NovoModelo::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->arquivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->novoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sairToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->preferênciasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->idiomaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ajudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->luccMEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tNovoModelo = (gcnew System::Windows::Forms::TabControl());
			this->tabDefModel = (gcnew System::Windows::Forms::TabPage());
			this->tEndTime = (gcnew System::Windows::Forms::TextBox());
			this->lEndTime = (gcnew System::Windows::Forms::Label());
			this->lDefinicoesModelo = (gcnew System::Windows::Forms::Label());
			this->lArquivos = (gcnew System::Windows::Forms::Label());
			this->tStartTime = (gcnew System::Windows::Forms::TextBox());
			this->lStartTime = (gcnew System::Windows::Forms::Label());
			this->tModelName = (gcnew System::Windows::Forms::TextBox());
			this->lModelName = (gcnew System::Windows::Forms::Label());
			this->lSelectedFolder = (gcnew System::Windows::Forms::Label());
			this->bSelectFolder = (gcnew System::Windows::Forms::Button());
			this->lDirProj = (gcnew System::Windows::Forms::Label());
			this->tabDefSpatial = (gcnew System::Windows::Forms::TabPage());
			this->lTerraview = (gcnew System::Windows::Forms::Label());
			this->lShape = (gcnew System::Windows::Forms::Label());
			this->bShape = (gcnew System::Windows::Forms::Button());
			this->tbSelectedBatabase = (gcnew System::Windows::Forms::TextBox());
			this->bSelectDatabase = (gcnew System::Windows::Forms::Button());
			this->tCellArea = (gcnew System::Windows::Forms::TextBox());
			this->lCellArea = (gcnew System::Windows::Forms::Label());
			this->tThemeName = (gcnew System::Windows::Forms::TextBox());
			this->lThemeName = (gcnew System::Windows::Forms::Label());
			this->lSpacialDimensions = (gcnew System::Windows::Forms::Label());
			this->lSelectedBatabase = (gcnew System::Windows::Forms::Label());
			this->lDatabase = (gcnew System::Windows::Forms::Label());
			this->tabLUT = (gcnew System::Windows::Forms::TabPage());
			this->lLUNDShow = (gcnew System::Windows::Forms::Label());
			this->bLUNDManager = (gcnew System::Windows::Forms::Button());
			this->lLUND = (gcnew System::Windows::Forms::Label());
			this->lLUTShow = (gcnew System::Windows::Forms::Label());
			this->bLUTManager = (gcnew System::Windows::Forms::Button());
			this->lLUTMedium = (gcnew System::Windows::Forms::Label());
			this->lLUTLarge = (gcnew System::Windows::Forms::Label());
			this->tabComponent = (gcnew System::Windows::Forms::TabPage());
			this->tbAllocation = (gcnew System::Windows::Forms::TextBox());
			this->bAllocContinuous = (gcnew System::Windows::Forms::Button());
			this->bAllocDiscrete = (gcnew System::Windows::Forms::Button());
			this->lAllocation = (gcnew System::Windows::Forms::Label());
			this->bPotContinuous = (gcnew System::Windows::Forms::Button());
			this->bPotDiscrete = (gcnew System::Windows::Forms::Button());
			this->tbPotential = (gcnew System::Windows::Forms::TextBox());
			this->lPotential = (gcnew System::Windows::Forms::Label());
			this->tbDemand = (gcnew System::Windows::Forms::TextBox());
			this->bD_CIThreeDM = (gcnew System::Windows::Forms::Button());
			this->bD_CITwoDM = (gcnew System::Windows::Forms::Button());
			this->bD_PCVINPE = (gcnew System::Windows::Forms::Button());
			this->lDemand = (gcnew System::Windows::Forms::Label());
			this->lComponentes = (gcnew System::Windows::Forms::Label());
			this->tabSaveParam = (gcnew System::Windows::Forms::TabPage());
			this->cAuxOut = (gcnew System::Windows::Forms::CheckBox());
			this->cReg = (gcnew System::Windows::Forms::CheckBox());
			this->cChange = (gcnew System::Windows::Forms::CheckBox());
			this->cPot = (gcnew System::Windows::Forms::CheckBox());
			this->cIsCoupled = (gcnew System::Windows::Forms::CheckBox());
			this->bSelectedAttr = (gcnew System::Windows::Forms::Button());
			this->lAttrToSave = (gcnew System::Windows::Forms::Label());
			this->bSelectedYears = (gcnew System::Windows::Forms::Button());
			this->lYearsToSave = (gcnew System::Windows::Forms::Label());
			this->lSaidaAdicionais = (gcnew System::Windows::Forms::Label());
			this->lSaveAttr = (gcnew System::Windows::Forms::Label());
			this->lvSaveAttr = (gcnew System::Windows::Forms::ListView());
			this->lSelectYears = (gcnew System::Windows::Forms::Label());
			this->lvYearsToSave = (gcnew System::Windows::Forms::ListView());
			this->cSaveYearly = (gcnew System::Windows::Forms::CheckBox());
			this->lSalvar = (gcnew System::Windows::Forms::Label());
			this->tOutputTheme = (gcnew System::Windows::Forms::TextBox());
			this->lOutputTheme = (gcnew System::Windows::Forms::Label());
			this->tabFileMaker = (gcnew System::Windows::Forms::TabPage());
			this->bRun = (gcnew System::Windows::Forms::Button());
			this->lRunModel = (gcnew System::Windows::Forms::Label());
			this->bGerarArquivos = (gcnew System::Windows::Forms::Button());
			this->lFileMaker = (gcnew System::Windows::Forms::Label());
			this->tabAdvRes = (gcnew System::Windows::Forms::TabPage());
			this->bScenario = (gcnew System::Windows::Forms::Button());
			this->lScenarioYearsConfirm = (gcnew System::Windows::Forms::Label());
			this->lScenarioYears = (gcnew System::Windows::Forms::Label());
			this->lvYearScenario = (gcnew System::Windows::Forms::ListView());
			this->tScenarioName = (gcnew System::Windows::Forms::TextBox());
			this->lScenarioName = (gcnew System::Windows::Forms::Label());
			this->tScenariosStartTime = (gcnew System::Windows::Forms::TextBox());
			this->lScenariosStartTime = (gcnew System::Windows::Forms::Label());
			this->cScenario = (gcnew System::Windows::Forms::CheckBox());
			this->lAtualizaveis = (gcnew System::Windows::Forms::Label());
			this->bDynamicSelect = (gcnew System::Windows::Forms::Button());
			this->lDynamicConfirm = (gcnew System::Windows::Forms::Label());
			this->lAnosVariaveis = (gcnew System::Windows::Forms::Label());
			this->lvYearsDynamic = (gcnew System::Windows::Forms::ListView());
			this->cDynamicVariables = (gcnew System::Windows::Forms::CheckBox());
			this->tabValidation = (gcnew System::Windows::Forms::TabPage());
			this->lRangeHelp = (gcnew System::Windows::Forms::Label());
			this->cbValidationMethod = (gcnew System::Windows::Forms::ComboBox());
			this->cSaveValidationFile = (gcnew System::Windows::Forms::CheckBox());
			this->cValidationSave = (gcnew System::Windows::Forms::CheckBox());
			this->lThemeHelp = (gcnew System::Windows::Forms::Label());
			this->lSimResult = (gcnew System::Windows::Forms::Label());
			this->tNumberWindows = (gcnew System::Windows::Forms::TextBox());
			this->lNumbWindows = (gcnew System::Windows::Forms::Label());
			this->tRange = (gcnew System::Windows::Forms::TextBox());
			this->lRange = (gcnew System::Windows::Forms::Label());
			this->lValidationMethod = (gcnew System::Windows::Forms::Label());
			this->bValidate = (gcnew System::Windows::Forms::Button());
			this->tAttributeFinalValidation = (gcnew System::Windows::Forms::TextBox());
			this->lAttributeFinalValidation = (gcnew System::Windows::Forms::Label());
			this->tAttributeInitValidation = (gcnew System::Windows::Forms::TextBox());
			this->lAttributeInitValidation = (gcnew System::Windows::Forms::Label());
			this->tAttributeForValidation = (gcnew System::Windows::Forms::TextBox());
			this->lAttributeForValidation = (gcnew System::Windows::Forms::Label());
			this->tInputThemeName = (gcnew System::Windows::Forms::TextBox());
			this->lInputThemeName = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->tNovoModelo->SuspendLayout();
			this->tabDefModel->SuspendLayout();
			this->tabDefSpatial->SuspendLayout();
			this->tabLUT->SuspendLayout();
			this->tabComponent->SuspendLayout();
			this->tabSaveParam->SuspendLayout();
			this->tabFileMaker->SuspendLayout();
			this->tabAdvRes->SuspendLayout();
			this->tabValidation->SuspendLayout();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(178, 33);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 13;
			this->pbLogo1->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->arquivoToolStripMenuItem,
					this->preferênciasToolStripMenuItem, this->ajudaToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(745, 24);
			this->menuStrip1->TabIndex = 17;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// arquivoToolStripMenuItem
			// 
			this->arquivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->novoToolStripMenuItem,
					this->abrirToolStripMenuItem, this->sairToolStripMenuItem
			});
			this->arquivoToolStripMenuItem->Name = L"arquivoToolStripMenuItem";
			this->arquivoToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->arquivoToolStripMenuItem->Text = L"Arquivo";
			// 
			// novoToolStripMenuItem
			// 
			this->novoToolStripMenuItem->Name = L"novoToolStripMenuItem";
			this->novoToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->novoToolStripMenuItem->Text = L"Novo";
			this->novoToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::novoToolStripMenuItem_Click);
			// 
			// abrirToolStripMenuItem
			// 
			this->abrirToolStripMenuItem->Name = L"abrirToolStripMenuItem";
			this->abrirToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->abrirToolStripMenuItem->Text = L"Abrir";
			this->abrirToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::abrirToolStripMenuItem_Click);
			// 
			// sairToolStripMenuItem
			// 
			this->sairToolStripMenuItem->Name = L"sairToolStripMenuItem";
			this->sairToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->sairToolStripMenuItem->Text = L"Sair";
			this->sairToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::sairToolStripMenuItem_Click);
			// 
			// preferênciasToolStripMenuItem
			// 
			this->preferênciasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->idiomaToolStripMenuItem });
			this->preferênciasToolStripMenuItem->Name = L"preferênciasToolStripMenuItem";
			this->preferênciasToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->preferênciasToolStripMenuItem->Text = L"Preferências";
			// 
			// idiomaToolStripMenuItem
			// 
			this->idiomaToolStripMenuItem->Name = L"idiomaToolStripMenuItem";
			this->idiomaToolStripMenuItem->Size = System::Drawing::Size(111, 22);
			this->idiomaToolStripMenuItem->Text = L"Idioma";
			this->idiomaToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::idiomaToolStripMenuItem_Click);
			// 
			// ajudaToolStripMenuItem
			// 
			this->ajudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->luccMEToolStripMenuItem,
					this->sobreToolStripMenuItem
			});
			this->ajudaToolStripMenuItem->Name = L"ajudaToolStripMenuItem";
			this->ajudaToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->ajudaToolStripMenuItem->Text = L"Ajuda";
			// 
			// luccMEToolStripMenuItem
			// 
			this->luccMEToolStripMenuItem->Name = L"luccMEToolStripMenuItem";
			this->luccMEToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->luccMEToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->luccMEToolStripMenuItem->Text = L"LuccME";
			this->luccMEToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::luccMEToolStripMenuItem_Click);
			// 
			// sobreToolStripMenuItem
			// 
			this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			this->sobreToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->sobreToolStripMenuItem->Text = L"Sobre";
			this->sobreToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::sobreToolStripMenuItem_Click);
			// 
			// tNovoModelo
			// 
			this->tNovoModelo->Controls->Add(this->tabDefModel);
			this->tNovoModelo->Controls->Add(this->tabDefSpatial);
			this->tNovoModelo->Controls->Add(this->tabLUT);
			this->tNovoModelo->Controls->Add(this->tabComponent);
			this->tNovoModelo->Controls->Add(this->tabSaveParam);
			this->tNovoModelo->Controls->Add(this->tabFileMaker);
			this->tNovoModelo->Controls->Add(this->tabAdvRes);
			this->tNovoModelo->Controls->Add(this->tabValidation);
			this->tNovoModelo->Location = System::Drawing::Point(12, 173);
			this->tNovoModelo->Name = L"tNovoModelo";
			this->tNovoModelo->SelectedIndex = 0;
			this->tNovoModelo->Size = System::Drawing::Size(725, 481);
			this->tNovoModelo->TabIndex = 18;
			this->tNovoModelo->SelectedIndexChanged += gcnew System::EventHandler(this, &NovoModelo::tNovoModelo_SelectedIndexChanged);
			// 
			// tabDefModel
			// 
			this->tabDefModel->Controls->Add(this->tEndTime);
			this->tabDefModel->Controls->Add(this->lEndTime);
			this->tabDefModel->Controls->Add(this->lDefinicoesModelo);
			this->tabDefModel->Controls->Add(this->lArquivos);
			this->tabDefModel->Controls->Add(this->tStartTime);
			this->tabDefModel->Controls->Add(this->lStartTime);
			this->tabDefModel->Controls->Add(this->tModelName);
			this->tabDefModel->Controls->Add(this->lModelName);
			this->tabDefModel->Controls->Add(this->lSelectedFolder);
			this->tabDefModel->Controls->Add(this->bSelectFolder);
			this->tabDefModel->Controls->Add(this->lDirProj);
			this->tabDefModel->Location = System::Drawing::Point(4, 22);
			this->tabDefModel->Name = L"tabDefModel";
			this->tabDefModel->Padding = System::Windows::Forms::Padding(3);
			this->tabDefModel->Size = System::Drawing::Size(717, 455);
			this->tabDefModel->TabIndex = 0;
			this->tabDefModel->Text = L"Definições do Modelo";
			this->tabDefModel->UseVisualStyleBackColor = true;
			// 
			// tEndTime
			// 
			this->tEndTime->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tEndTime->Location = System::Drawing::Point(249, 297);
			this->tEndTime->Name = L"tEndTime";
			this->tEndTime->Size = System::Drawing::Size(80, 20);
			this->tEndTime->TabIndex = 72;
			this->tEndTime->Text = L"2010";
			this->tEndTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tEndTime->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lEndTime
			// 
			this->lEndTime->AutoSize = true;
			this->lEndTime->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lEndTime->Location = System::Drawing::Point(23, 296);
			this->lEndTime->Name = L"lEndTime";
			this->lEndTime->Size = System::Drawing::Size(134, 23);
			this->lEndTime->TabIndex = 71;
			this->lEndTime->Text = L"Ano de Termino";
			this->lEndTime->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lDefinicoesModelo
			// 
			this->lDefinicoesModelo->AutoSize = true;
			this->lDefinicoesModelo->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDefinicoesModelo->Location = System::Drawing::Point(244, 171);
			this->lDefinicoesModelo->Name = L"lDefinicoesModelo";
			this->lDefinicoesModelo->Size = System::Drawing::Size(202, 26);
			this->lDefinicoesModelo->TabIndex = 70;
			this->lDefinicoesModelo->Text = L"Definições do Modelo";
			this->lDefinicoesModelo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lArquivos
			// 
			this->lArquivos->AutoSize = true;
			this->lArquivos->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lArquivos->Location = System::Drawing::Point(301, 26);
			this->lArquivos->Name = L"lArquivos";
			this->lArquivos->Size = System::Drawing::Size(88, 26);
			this->lArquivos->TabIndex = 69;
			this->lArquivos->Text = L"Arquivos";
			this->lArquivos->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tStartTime
			// 
			this->tStartTime->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tStartTime->Location = System::Drawing::Point(249, 257);
			this->tStartTime->Name = L"tStartTime";
			this->tStartTime->Size = System::Drawing::Size(80, 20);
			this->tStartTime->TabIndex = 68;
			this->tStartTime->Text = L"1999";
			this->tStartTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tStartTime->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lStartTime
			// 
			this->lStartTime->AutoSize = true;
			this->lStartTime->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lStartTime->Location = System::Drawing::Point(23, 256);
			this->lStartTime->Name = L"lStartTime";
			this->lStartTime->Size = System::Drawing::Size(113, 23);
			this->lStartTime->TabIndex = 67;
			this->lStartTime->Text = L"Ano de Início";
			this->lStartTime->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tModelName
			// 
			this->tModelName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tModelName->Location = System::Drawing::Point(249, 214);
			this->tModelName->Name = L"tModelName";
			this->tModelName->Size = System::Drawing::Size(194, 20);
			this->tModelName->TabIndex = 66;
			this->tModelName->Text = L"LuccMe_model";
			this->tModelName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tModelName->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			this->tModelName->Leave += gcnew System::EventHandler(this, &NovoModelo::tModelName_Leave);
			// 
			// lModelName
			// 
			this->lModelName->AutoSize = true;
			this->lModelName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lModelName->Location = System::Drawing::Point(23, 213);
			this->lModelName->Name = L"lModelName";
			this->lModelName->Size = System::Drawing::Size(148, 23);
			this->lModelName->TabIndex = 65;
			this->lModelName->Text = L"Nome do Modelo";
			this->lModelName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lSelectedFolder
			// 
			this->lSelectedFolder->AutoSize = true;
			this->lSelectedFolder->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSelectedFolder->Location = System::Drawing::Point(23, 132);
			this->lSelectedFolder->Name = L"lSelectedFolder";
			this->lSelectedFolder->Size = System::Drawing::Size(0, 19);
			this->lSelectedFolder->TabIndex = 64;
			// 
			// bSelectFolder
			// 
			this->bSelectFolder->Location = System::Drawing::Point(308, 78);
			this->bSelectFolder->Name = L"bSelectFolder";
			this->bSelectFolder->Size = System::Drawing::Size(75, 23);
			this->bSelectFolder->TabIndex = 63;
			this->bSelectFolder->Text = L"Selecionar";
			this->bSelectFolder->UseVisualStyleBackColor = true;
			this->bSelectFolder->Click += gcnew System::EventHandler(this, &NovoModelo::bSelectFolder_Click);
			// 
			// lDirProj
			// 
			this->lDirProj->AutoSize = true;
			this->lDirProj->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDirProj->Location = System::Drawing::Point(18, 78);
			this->lDirProj->Name = L"lDirProj";
			this->lDirProj->Size = System::Drawing::Size(224, 23);
			this->lDirProj->TabIndex = 62;
			this->lDirProj->Text = L"Pasta para Salvar o Modelo";
			this->lDirProj->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tabDefSpatial
			// 
			this->tabDefSpatial->Controls->Add(this->lTerraview);
			this->tabDefSpatial->Controls->Add(this->lShape);
			this->tabDefSpatial->Controls->Add(this->bShape);
			this->tabDefSpatial->Controls->Add(this->tbSelectedBatabase);
			this->tabDefSpatial->Controls->Add(this->bSelectDatabase);
			this->tabDefSpatial->Controls->Add(this->tCellArea);
			this->tabDefSpatial->Controls->Add(this->lCellArea);
			this->tabDefSpatial->Controls->Add(this->tThemeName);
			this->tabDefSpatial->Controls->Add(this->lThemeName);
			this->tabDefSpatial->Controls->Add(this->lSpacialDimensions);
			this->tabDefSpatial->Controls->Add(this->lSelectedBatabase);
			this->tabDefSpatial->Controls->Add(this->lDatabase);
			this->tabDefSpatial->Location = System::Drawing::Point(4, 22);
			this->tabDefSpatial->Name = L"tabDefSpatial";
			this->tabDefSpatial->Padding = System::Windows::Forms::Padding(3);
			this->tabDefSpatial->Size = System::Drawing::Size(717, 455);
			this->tabDefSpatial->TabIndex = 1;
			this->tabDefSpatial->Text = L"Definições Espaciais";
			this->tabDefSpatial->UseVisualStyleBackColor = true;
			// 
			// lTerraview
			// 
			this->lTerraview->AutoSize = true;
			this->lTerraview->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lTerraview->Location = System::Drawing::Point(158, 68);
			this->lTerraview->Name = L"lTerraview";
			this->lTerraview->Size = System::Drawing::Size(151, 23);
			this->lTerraview->TabIndex = 94;
			this->lTerraview->Text = L"Projeto Terraview";
			this->lTerraview->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lShape
			// 
			this->lShape->AutoSize = true;
			this->lShape->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lShape->Location = System::Drawing::Point(434, 68);
			this->lShape->Name = L"lShape";
			this->lShape->Size = System::Drawing::Size(58, 23);
			this->lShape->TabIndex = 93;
			this->lShape->Text = L"Shape";
			this->lShape->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// bShape
			// 
			this->bShape->Location = System::Drawing::Point(425, 94);
			this->bShape->Name = L"bShape";
			this->bShape->Size = System::Drawing::Size(75, 23);
			this->bShape->TabIndex = 92;
			this->bShape->Text = L"Selecionar";
			this->bShape->UseVisualStyleBackColor = true;
			this->bShape->Click += gcnew System::EventHandler(this, &NovoModelo::bShape_Click);
			// 
			// tbSelectedBatabase
			// 
			this->tbSelectedBatabase->BackColor = System::Drawing::SystemColors::Control;
			this->tbSelectedBatabase->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSelectedBatabase->Location = System::Drawing::Point(14, 128);
			this->tbSelectedBatabase->Multiline = true;
			this->tbSelectedBatabase->Name = L"tbSelectedBatabase";
			this->tbSelectedBatabase->Size = System::Drawing::Size(496, 98);
			this->tbSelectedBatabase->TabIndex = 90;
			// 
			// bSelectDatabase
			// 
			this->bSelectDatabase->Location = System::Drawing::Point(191, 94);
			this->bSelectDatabase->Name = L"bSelectDatabase";
			this->bSelectDatabase->Size = System::Drawing::Size(75, 23);
			this->bSelectDatabase->TabIndex = 79;
			this->bSelectDatabase->Text = L"Selecionar";
			this->bSelectDatabase->UseVisualStyleBackColor = true;
			this->bSelectDatabase->Click += gcnew System::EventHandler(this, &NovoModelo::bSelectDatabase_Click);
			// 
			// tCellArea
			// 
			this->tCellArea->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tCellArea->Location = System::Drawing::Point(195, 284);
			this->tCellArea->Name = L"tCellArea";
			this->tCellArea->Size = System::Drawing::Size(80, 20);
			this->tCellArea->TabIndex = 85;
			this->tCellArea->Text = L"6.25";
			this->tCellArea->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tCellArea->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lCellArea
			// 
			this->lCellArea->AutoSize = true;
			this->lCellArea->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lCellArea->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lCellArea->Location = System::Drawing::Point(12, 283);
			this->lCellArea->Name = L"lCellArea";
			this->lCellArea->Size = System::Drawing::Size(157, 23);
			this->lCellArea->TabIndex = 84;
			this->lCellArea->Text = L"Tamanho da Célula";
			this->lCellArea->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tThemeName
			// 
			this->tThemeName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tThemeName->Location = System::Drawing::Point(195, 241);
			this->tThemeName->Name = L"tThemeName";
			this->tThemeName->Size = System::Drawing::Size(194, 20);
			this->tThemeName->TabIndex = 83;
			this->tThemeName->Text = L"layer_name";
			this->tThemeName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tThemeName->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lThemeName
			// 
			this->lThemeName->AutoSize = true;
			this->lThemeName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lThemeName->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lThemeName->Location = System::Drawing::Point(12, 240);
			this->lThemeName->Name = L"lThemeName";
			this->lThemeName->Size = System::Drawing::Size(127, 23);
			this->lThemeName->TabIndex = 82;
			this->lThemeName->Text = L"Nome do Tema";
			this->lThemeName->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lSpacialDimensions
			// 
			this->lSpacialDimensions->AutoSize = true;
			this->lSpacialDimensions->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSpacialDimensions->Location = System::Drawing::Point(248, 26);
			this->lSpacialDimensions->Name = L"lSpacialDimensions";
			this->lSpacialDimensions->Size = System::Drawing::Size(184, 26);
			this->lSpacialDimensions->TabIndex = 81;
			this->lSpacialDimensions->Text = L"Definições Espaciais";
			this->lSpacialDimensions->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lSelectedBatabase
			// 
			this->lSelectedBatabase->AutoSize = true;
			this->lSelectedBatabase->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->lSelectedBatabase->Location = System::Drawing::Point(516, 423);
			this->lSelectedBatabase->Name = L"lSelectedBatabase";
			this->lSelectedBatabase->Size = System::Drawing::Size(181, 19);
			this->lSelectedBatabase->TabIndex = 80;
			this->lSelectedBatabase->Text = L"                                           ";
			// 
			// lDatabase
			// 
			this->lDatabase->AutoSize = true;
			this->lDatabase->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDatabase->Location = System::Drawing::Point(12, 94);
			this->lDatabase->Name = L"lDatabase";
			this->lDatabase->Size = System::Drawing::Size(78, 23);
			this->lDatabase->TabIndex = 78;
			this->lDatabase->Text = L"Arquivo:";
			this->lDatabase->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tabLUT
			// 
			this->tabLUT->Controls->Add(this->lLUNDShow);
			this->tabLUT->Controls->Add(this->bLUNDManager);
			this->tabLUT->Controls->Add(this->lLUND);
			this->tabLUT->Controls->Add(this->lLUTShow);
			this->tabLUT->Controls->Add(this->bLUTManager);
			this->tabLUT->Controls->Add(this->lLUTMedium);
			this->tabLUT->Controls->Add(this->lLUTLarge);
			this->tabLUT->Location = System::Drawing::Point(4, 22);
			this->tabLUT->Name = L"tabLUT";
			this->tabLUT->Padding = System::Windows::Forms::Padding(3);
			this->tabLUT->Size = System::Drawing::Size(717, 455);
			this->tabLUT->TabIndex = 2;
			this->tabLUT->Text = L"Tipos de Uso da Terra";
			this->tabLUT->UseVisualStyleBackColor = true;
			// 
			// lLUNDShow
			// 
			this->lLUNDShow->AutoSize = true;
			this->lLUNDShow->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->lLUNDShow->Location = System::Drawing::Point(40, 270);
			this->lLUNDShow->Name = L"lLUNDShow";
			this->lLUNDShow->Size = System::Drawing::Size(0, 19);
			this->lLUNDShow->TabIndex = 80;
			// 
			// bLUNDManager
			// 
			this->bLUNDManager->Location = System::Drawing::Point(319, 220);
			this->bLUNDManager->Name = L"bLUNDManager";
			this->bLUNDManager->Size = System::Drawing::Size(75, 23);
			this->bLUNDManager->TabIndex = 79;
			this->bLUNDManager->Text = L"Gerenciar";
			this->bLUNDManager->UseVisualStyleBackColor = true;
			this->bLUNDManager->Click += gcnew System::EventHandler(this, &NovoModelo::bLUNDManager_Click);
			// 
			// lLUND
			// 
			this->lLUND->AutoSize = true;
			this->lLUND->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lLUND->Location = System::Drawing::Point(29, 220);
			this->lLUND->Name = L"lLUND";
			this->lLUND->Size = System::Drawing::Size(231, 23);
			this->lLUND->TabIndex = 78;
			this->lLUND->Text = L"Tipos de Uso com \"No Data\"";
			this->lLUND->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lLUTShow
			// 
			this->lLUTShow->AutoSize = true;
			this->lLUTShow->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->lLUTShow->Location = System::Drawing::Point(40, 139);
			this->lLUTShow->Name = L"lLUTShow";
			this->lLUTShow->Size = System::Drawing::Size(0, 19);
			this->lLUTShow->TabIndex = 77;
			// 
			// bLUTManager
			// 
			this->bLUTManager->Location = System::Drawing::Point(319, 99);
			this->bLUTManager->Name = L"bLUTManager";
			this->bLUTManager->Size = System::Drawing::Size(75, 23);
			this->bLUTManager->TabIndex = 76;
			this->bLUTManager->Text = L"Gerenciar";
			this->bLUTManager->UseVisualStyleBackColor = true;
			this->bLUTManager->Click += gcnew System::EventHandler(this, &NovoModelo::bLUTManager_Click);
			// 
			// lLUTMedium
			// 
			this->lLUTMedium->AutoSize = true;
			this->lLUTMedium->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lLUTMedium->Location = System::Drawing::Point(29, 99);
			this->lLUTMedium->Name = L"lLUTMedium";
			this->lLUTMedium->Size = System::Drawing::Size(181, 23);
			this->lLUTMedium->TabIndex = 75;
			this->lLUTMedium->Text = L"Tipos de Uso da Terra ";
			this->lLUTMedium->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lLUTLarge
			// 
			this->lLUTLarge->AutoSize = true;
			this->lLUTLarge->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lLUTLarge->Location = System::Drawing::Point(261, 26);
			this->lLUTLarge->Name = L"lLUTLarge";
			this->lLUTLarge->Size = System::Drawing::Size(196, 26);
			this->lLUTLarge->TabIndex = 74;
			this->lLUTLarge->Text = L"Tipos de Uso da Terra";
			this->lLUTLarge->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tabComponent
			// 
			this->tabComponent->Controls->Add(this->tbAllocation);
			this->tabComponent->Controls->Add(this->bAllocContinuous);
			this->tabComponent->Controls->Add(this->bAllocDiscrete);
			this->tabComponent->Controls->Add(this->lAllocation);
			this->tabComponent->Controls->Add(this->bPotContinuous);
			this->tabComponent->Controls->Add(this->bPotDiscrete);
			this->tabComponent->Controls->Add(this->tbPotential);
			this->tabComponent->Controls->Add(this->lPotential);
			this->tabComponent->Controls->Add(this->tbDemand);
			this->tabComponent->Controls->Add(this->bD_CIThreeDM);
			this->tabComponent->Controls->Add(this->bD_CITwoDM);
			this->tabComponent->Controls->Add(this->bD_PCVINPE);
			this->tabComponent->Controls->Add(this->lDemand);
			this->tabComponent->Controls->Add(this->lComponentes);
			this->tabComponent->Location = System::Drawing::Point(4, 22);
			this->tabComponent->Name = L"tabComponent";
			this->tabComponent->Size = System::Drawing::Size(717, 455);
			this->tabComponent->TabIndex = 3;
			this->tabComponent->Text = L"Componentes";
			this->tabComponent->UseVisualStyleBackColor = true;
			// 
			// tbAllocation
			// 
			this->tbAllocation->BackColor = System::Drawing::SystemColors::Control;
			this->tbAllocation->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbAllocation->Location = System::Drawing::Point(500, 316);
			this->tbAllocation->Multiline = true;
			this->tbAllocation->Name = L"tbAllocation";
			this->tbAllocation->ReadOnly = true;
			this->tbAllocation->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbAllocation->Size = System::Drawing::Size(171, 126);
			this->tbAllocation->TabIndex = 89;
			this->tbAllocation->WordWrap = false;
			// 
			// bAllocContinuous
			// 
			this->bAllocContinuous->Location = System::Drawing::Point(500, 221);
			this->bAllocContinuous->Name = L"bAllocContinuous";
			this->bAllocContinuous->Size = System::Drawing::Size(171, 39);
			this->bAllocContinuous->TabIndex = 88;
			this->bAllocContinuous->Text = L"Componentes Continuos";
			this->bAllocContinuous->UseVisualStyleBackColor = true;
			this->bAllocContinuous->Click += gcnew System::EventHandler(this, &NovoModelo::bAllocContinuous_Click);
			// 
			// bAllocDiscrete
			// 
			this->bAllocDiscrete->Location = System::Drawing::Point(500, 151);
			this->bAllocDiscrete->Name = L"bAllocDiscrete";
			this->bAllocDiscrete->Size = System::Drawing::Size(171, 39);
			this->bAllocDiscrete->TabIndex = 87;
			this->bAllocDiscrete->Text = L"Componentes Discretos";
			this->bAllocDiscrete->UseVisualStyleBackColor = true;
			this->bAllocDiscrete->Click += gcnew System::EventHandler(this, &NovoModelo::bAllocDiscrete_Click);
			// 
			// lAllocation
			// 
			this->lAllocation->AutoSize = true;
			this->lAllocation->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAllocation->Location = System::Drawing::Point(540, 75);
			this->lAllocation->Name = L"lAllocation";
			this->lAllocation->Size = System::Drawing::Size(90, 26);
			this->lAllocation->TabIndex = 86;
			this->lAllocation->Text = L"Alocação";
			this->lAllocation->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bPotContinuous
			// 
			this->bPotContinuous->Location = System::Drawing::Point(270, 221);
			this->bPotContinuous->Name = L"bPotContinuous";
			this->bPotContinuous->Size = System::Drawing::Size(171, 39);
			this->bPotContinuous->TabIndex = 85;
			this->bPotContinuous->Text = L"Componentes Continuos";
			this->bPotContinuous->UseVisualStyleBackColor = true;
			this->bPotContinuous->Click += gcnew System::EventHandler(this, &NovoModelo::bPotContinuous_Click);
			// 
			// bPotDiscrete
			// 
			this->bPotDiscrete->Location = System::Drawing::Point(270, 151);
			this->bPotDiscrete->Name = L"bPotDiscrete";
			this->bPotDiscrete->Size = System::Drawing::Size(171, 39);
			this->bPotDiscrete->TabIndex = 84;
			this->bPotDiscrete->Text = L"Componentes Discretos";
			this->bPotDiscrete->UseVisualStyleBackColor = true;
			this->bPotDiscrete->Click += gcnew System::EventHandler(this, &NovoModelo::bPotDiscrete_Click);
			// 
			// tbPotential
			// 
			this->tbPotential->BackColor = System::Drawing::SystemColors::Control;
			this->tbPotential->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPotential->Location = System::Drawing::Point(269, 316);
			this->tbPotential->Multiline = true;
			this->tbPotential->Name = L"tbPotential";
			this->tbPotential->ReadOnly = true;
			this->tbPotential->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbPotential->Size = System::Drawing::Size(171, 126);
			this->tbPotential->TabIndex = 83;
			this->tbPotential->WordWrap = false;
			// 
			// lPotential
			// 
			this->lPotential->AutoSize = true;
			this->lPotential->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPotential->Location = System::Drawing::Point(309, 75);
			this->lPotential->Name = L"lPotential";
			this->lPotential->Size = System::Drawing::Size(92, 26);
			this->lPotential->TabIndex = 82;
			this->lPotential->Text = L"Potencial";
			this->lPotential->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbDemand
			// 
			this->tbDemand->BackColor = System::Drawing::SystemColors::Control;
			this->tbDemand->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbDemand->Location = System::Drawing::Point(22, 316);
			this->tbDemand->Multiline = true;
			this->tbDemand->Name = L"tbDemand";
			this->tbDemand->ReadOnly = true;
			this->tbDemand->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbDemand->Size = System::Drawing::Size(171, 126);
			this->tbDemand->TabIndex = 80;
			this->tbDemand->WordWrap = false;
			// 
			// bD_CIThreeDM
			// 
			this->bD_CIThreeDM->Location = System::Drawing::Point(22, 260);
			this->bD_CIThreeDM->Name = L"bD_CIThreeDM";
			this->bD_CIThreeDM->Size = System::Drawing::Size(171, 39);
			this->bD_CIThreeDM->TabIndex = 79;
			this->bD_CIThreeDM->Text = L"Compute Three Dates";
			this->bD_CIThreeDM->UseVisualStyleBackColor = true;
			this->bD_CIThreeDM->Click += gcnew System::EventHandler(this, &NovoModelo::bD_CIThreeDM_Click);
			// 
			// bD_CITwoDM
			// 
			this->bD_CITwoDM->Location = System::Drawing::Point(22, 190);
			this->bD_CITwoDM->Name = L"bD_CITwoDM";
			this->bD_CITwoDM->Size = System::Drawing::Size(171, 39);
			this->bD_CITwoDM->TabIndex = 78;
			this->bD_CITwoDM->Text = L"Compute Two Dates";
			this->bD_CITwoDM->UseVisualStyleBackColor = true;
			this->bD_CITwoDM->Click += gcnew System::EventHandler(this, &NovoModelo::bD_CITwoDM_Click);
			// 
			// bD_PCVINPE
			// 
			this->bD_PCVINPE->Location = System::Drawing::Point(22, 120);
			this->bD_PCVINPE->Name = L"bD_PCVINPE";
			this->bD_PCVINPE->Size = System::Drawing::Size(171, 39);
			this->bD_PCVINPE->TabIndex = 77;
			this->bD_PCVINPE->Text = L"Pre Computed Values";
			this->bD_PCVINPE->UseVisualStyleBackColor = true;
			this->bD_PCVINPE->Click += gcnew System::EventHandler(this, &NovoModelo::bD_PCVINPE_Click);
			// 
			// lDemand
			// 
			this->lDemand->AutoSize = true;
			this->lDemand->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDemand->Location = System::Drawing::Point(60, 75);
			this->lDemand->Name = L"lDemand";
			this->lDemand->Size = System::Drawing::Size(95, 26);
			this->lDemand->TabIndex = 76;
			this->lDemand->Text = L"Demanda";
			this->lDemand->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lComponentes
			// 
			this->lComponentes->AutoSize = true;
			this->lComponentes->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lComponentes->Location = System::Drawing::Point(229, 26);
			this->lComponentes->Name = L"lComponentes";
			this->lComponentes->Size = System::Drawing::Size(245, 26);
			this->lComponentes->TabIndex = 75;
			this->lComponentes->Text = L"Selecione os Componentes";
			this->lComponentes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tabSaveParam
			// 
			this->tabSaveParam->Controls->Add(this->cAuxOut);
			this->tabSaveParam->Controls->Add(this->cReg);
			this->tabSaveParam->Controls->Add(this->cChange);
			this->tabSaveParam->Controls->Add(this->cPot);
			this->tabSaveParam->Controls->Add(this->cIsCoupled);
			this->tabSaveParam->Controls->Add(this->bSelectedAttr);
			this->tabSaveParam->Controls->Add(this->lAttrToSave);
			this->tabSaveParam->Controls->Add(this->bSelectedYears);
			this->tabSaveParam->Controls->Add(this->lYearsToSave);
			this->tabSaveParam->Controls->Add(this->lSaidaAdicionais);
			this->tabSaveParam->Controls->Add(this->lSaveAttr);
			this->tabSaveParam->Controls->Add(this->lvSaveAttr);
			this->tabSaveParam->Controls->Add(this->lSelectYears);
			this->tabSaveParam->Controls->Add(this->lvYearsToSave);
			this->tabSaveParam->Controls->Add(this->cSaveYearly);
			this->tabSaveParam->Controls->Add(this->lSalvar);
			this->tabSaveParam->Controls->Add(this->tOutputTheme);
			this->tabSaveParam->Controls->Add(this->lOutputTheme);
			this->tabSaveParam->Location = System::Drawing::Point(4, 22);
			this->tabSaveParam->Name = L"tabSaveParam";
			this->tabSaveParam->Padding = System::Windows::Forms::Padding(3);
			this->tabSaveParam->Size = System::Drawing::Size(717, 455);
			this->tabSaveParam->TabIndex = 4;
			this->tabSaveParam->Text = L"Salvar Parâmetros";
			this->tabSaveParam->UseVisualStyleBackColor = true;
			// 
			// cAuxOut
			// 
			this->cAuxOut->AutoSize = true;
			this->cAuxOut->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold));
			this->cAuxOut->Location = System::Drawing::Point(626, 429);
			this->cAuxOut->Name = L"cAuxOut";
			this->cAuxOut->Size = System::Drawing::Size(94, 23);
			this->cAuxOut->TabIndex = 97;
			this->cAuxOut->Text = L"Agregado";
			this->cAuxOut->UseVisualStyleBackColor = true;
			// 
			// cReg
			// 
			this->cReg->AutoSize = true;
			this->cReg->Enabled = false;
			this->cReg->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold));
			this->cReg->Location = System::Drawing::Point(525, 429);
			this->cReg->Name = L"cReg";
			this->cReg->Size = System::Drawing::Size(96, 23);
			this->cReg->TabIndex = 97;
			this->cReg->Text = L"Regressão";
			this->cReg->UseVisualStyleBackColor = true;
			// 
			// cChange
			// 
			this->cChange->AutoSize = true;
			this->cChange->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold));
			this->cChange->Location = System::Drawing::Point(427, 429);
			this->cChange->Name = L"cChange";
			this->cChange->Size = System::Drawing::Size(92, 23);
			this->cChange->TabIndex = 97;
			this->cChange->Text = L"Mudança";
			this->cChange->UseVisualStyleBackColor = true;
			// 
			// cPot
			// 
			this->cPot->AutoSize = true;
			this->cPot->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold));
			this->cPot->Location = System::Drawing::Point(326, 429);
			this->cPot->Name = L"cPot";
			this->cPot->Size = System::Drawing::Size(92, 23);
			this->cPot->TabIndex = 97;
			this->cPot->Text = L"Potencial";
			this->cPot->UseVisualStyleBackColor = true;
			// 
			// cIsCoupled
			// 
			this->cIsCoupled->AutoSize = true;
			this->cIsCoupled->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsCoupled->Location = System::Drawing::Point(531, 3);
			this->cIsCoupled->Name = L"cIsCoupled";
			this->cIsCoupled->Size = System::Drawing::Size(107, 27);
			this->cIsCoupled->TabIndex = 96;
			this->cIsCoupled->Text = L"isCoupled";
			this->cIsCoupled->UseVisualStyleBackColor = true;
			this->cIsCoupled->Visible = false;
			// 
			// bSelectedAttr
			// 
			this->bSelectedAttr->Location = System::Drawing::Point(541, 330);
			this->bSelectedAttr->Name = L"bSelectedAttr";
			this->bSelectedAttr->Size = System::Drawing::Size(75, 23);
			this->bSelectedAttr->TabIndex = 95;
			this->bSelectedAttr->Text = L"Selecionar";
			this->bSelectedAttr->UseVisualStyleBackColor = true;
			this->bSelectedAttr->Visible = false;
			this->bSelectedAttr->Click += gcnew System::EventHandler(this, &NovoModelo::bSelectedAttr_Click);
			// 
			// lAttrToSave
			// 
			this->lAttrToSave->AutoSize = true;
			this->lAttrToSave->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAttrToSave->Location = System::Drawing::Point(486, 374);
			this->lAttrToSave->Name = L"lAttrToSave";
			this->lAttrToSave->Size = System::Drawing::Size(0, 19);
			this->lAttrToSave->TabIndex = 94;
			// 
			// bSelectedYears
			// 
			this->bSelectedYears->Location = System::Drawing::Point(66, 382);
			this->bSelectedYears->Name = L"bSelectedYears";
			this->bSelectedYears->Size = System::Drawing::Size(75, 23);
			this->bSelectedYears->TabIndex = 93;
			this->bSelectedYears->Text = L"Selecionar";
			this->bSelectedYears->UseVisualStyleBackColor = true;
			this->bSelectedYears->Visible = false;
			this->bSelectedYears->Click += gcnew System::EventHandler(this, &NovoModelo::bSelectedYears_Click);
			// 
			// lYearsToSave
			// 
			this->lYearsToSave->AutoSize = true;
			this->lYearsToSave->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lYearsToSave->Location = System::Drawing::Point(27, 421);
			this->lYearsToSave->Name = L"lYearsToSave";
			this->lYearsToSave->Size = System::Drawing::Size(0, 19);
			this->lYearsToSave->TabIndex = 92;
			// 
			// lSaidaAdicionais
			// 
			this->lSaidaAdicionais->AutoSize = true;
			this->lSaidaAdicionais->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSaidaAdicionais->Location = System::Drawing::Point(439, 403);
			this->lSaidaAdicionais->Name = L"lSaidaAdicionais";
			this->lSaidaAdicionais->Size = System::Drawing::Size(146, 23);
			this->lSaidaAdicionais->TabIndex = 91;
			this->lSaidaAdicionais->Text = L"Saídas Adicionais";
			this->lSaidaAdicionais->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lSaveAttr
			// 
			this->lSaveAttr->AutoSize = true;
			this->lSaveAttr->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSaveAttr->Location = System::Drawing::Point(472, 82);
			this->lSaveAttr->Name = L"lSaveAttr";
			this->lSaveAttr->Size = System::Drawing::Size(206, 23);
			this->lSaveAttr->TabIndex = 91;
			this->lSaveAttr->Text = L"Atributos a serem Salvos";
			this->lSaveAttr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lvSaveAttr
			// 
			this->lvSaveAttr->Location = System::Drawing::Point(490, 111);
			this->lvSaveAttr->Name = L"lvSaveAttr";
			this->lvSaveAttr->Size = System::Drawing::Size(171, 207);
			this->lvSaveAttr->TabIndex = 90;
			this->lvSaveAttr->UseCompatibleStateImageBehavior = false;
			// 
			// lSelectYears
			// 
			this->lSelectYears->AutoSize = true;
			this->lSelectYears->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSelectYears->Location = System::Drawing::Point(23, 173);
			this->lSelectYears->Name = L"lSelectYears";
			this->lSelectYears->Size = System::Drawing::Size(171, 23);
			this->lSelectYears->TabIndex = 89;
			this->lSelectYears->Text = L"Anos a serem Salvos";
			this->lSelectYears->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lSelectYears->Visible = false;
			// 
			// lvYearsToSave
			// 
			this->lvYearsToSave->Location = System::Drawing::Point(22, 204);
			this->lvYearsToSave->Name = L"lvYearsToSave";
			this->lvYearsToSave->Size = System::Drawing::Size(171, 166);
			this->lvYearsToSave->TabIndex = 88;
			this->lvYearsToSave->UseCompatibleStateImageBehavior = false;
			this->lvYearsToSave->Visible = false;
			// 
			// cSaveYearly
			// 
			this->cSaveYearly->AutoSize = true;
			this->cSaveYearly->Checked = true;
			this->cSaveYearly->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cSaveYearly->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cSaveYearly->Location = System::Drawing::Point(24, 134);
			this->cSaveYearly->Name = L"cSaveYearly";
			this->cSaveYearly->Size = System::Drawing::Size(179, 27);
			this->cSaveYearly->TabIndex = 87;
			this->cSaveYearly->Text = L"Salvar Anualmente";
			this->cSaveYearly->UseVisualStyleBackColor = true;
			this->cSaveYearly->CheckedChanged += gcnew System::EventHandler(this, &NovoModelo::cSaveYearly_CheckedChanged);
			// 
			// lSalvar
			// 
			this->lSalvar->AutoSize = true;
			this->lSalvar->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSalvar->Location = System::Drawing::Point(327, 26);
			this->lSalvar->Name = L"lSalvar";
			this->lSalvar->Size = System::Drawing::Size(64, 26);
			this->lSalvar->TabIndex = 86;
			this->lSalvar->Text = L"Salvar";
			this->lSalvar->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tOutputTheme
			// 
			this->tOutputTheme->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tOutputTheme->Location = System::Drawing::Point(148, 85);
			this->tOutputTheme->Name = L"tOutputTheme";
			this->tOutputTheme->Size = System::Drawing::Size(162, 20);
			this->tOutputTheme->TabIndex = 85;
			this->tOutputTheme->Text = L"LuccMe_Model_";
			this->tOutputTheme->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tOutputTheme->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lOutputTheme
			// 
			this->lOutputTheme->AutoSize = true;
			this->lOutputTheme->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lOutputTheme->Location = System::Drawing::Point(17, 82);
			this->lOutputTheme->Name = L"lOutputTheme";
			this->lOutputTheme->Size = System::Drawing::Size(128, 23);
			this->lOutputTheme->TabIndex = 84;
			this->lOutputTheme->Text = L"Nome de Saída";
			this->lOutputTheme->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tabFileMaker
			// 
			this->tabFileMaker->Controls->Add(this->bRun);
			this->tabFileMaker->Controls->Add(this->lRunModel);
			this->tabFileMaker->Controls->Add(this->bGerarArquivos);
			this->tabFileMaker->Controls->Add(this->lFileMaker);
			this->tabFileMaker->Location = System::Drawing::Point(4, 22);
			this->tabFileMaker->Name = L"tabFileMaker";
			this->tabFileMaker->Padding = System::Windows::Forms::Padding(3);
			this->tabFileMaker->Size = System::Drawing::Size(717, 455);
			this->tabFileMaker->TabIndex = 5;
			this->tabFileMaker->Text = L"Gerar Arquivo";
			this->tabFileMaker->UseVisualStyleBackColor = true;
			// 
			// bRun
			// 
			this->bRun->Location = System::Drawing::Point(264, 260);
			this->bRun->Name = L"bRun";
			this->bRun->Size = System::Drawing::Size(185, 47);
			this->bRun->TabIndex = 91;
			this->bRun->Text = L"Rodar Modelo";
			this->bRun->UseVisualStyleBackColor = true;
			this->bRun->Visible = false;
			this->bRun->Click += gcnew System::EventHandler(this, &NovoModelo::bRun_Click);
			// 
			// lRunModel
			// 
			this->lRunModel->AutoSize = true;
			this->lRunModel->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRunModel->Location = System::Drawing::Point(281, 213);
			this->lRunModel->Name = L"lRunModel";
			this->lRunModel->Size = System::Drawing::Size(151, 26);
			this->lRunModel->TabIndex = 90;
			this->lRunModel->Text = L"Rodar o Modelo";
			this->lRunModel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lRunModel->Visible = false;
			// 
			// bGerarArquivos
			// 
			this->bGerarArquivos->Location = System::Drawing::Point(264, 78);
			this->bGerarArquivos->Name = L"bGerarArquivos";
			this->bGerarArquivos->Size = System::Drawing::Size(185, 47);
			this->bGerarArquivos->TabIndex = 89;
			this->bGerarArquivos->Text = L"Gerar Arquivos";
			this->bGerarArquivos->UseVisualStyleBackColor = true;
			this->bGerarArquivos->Click += gcnew System::EventHandler(this, &NovoModelo::bGerarArquivos_Click);
			// 
			// lFileMaker
			// 
			this->lFileMaker->AutoSize = true;
			this->lFileMaker->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lFileMaker->Location = System::Drawing::Point(274, 29);
			this->lFileMaker->Name = L"lFileMaker";
			this->lFileMaker->Size = System::Drawing::Size(165, 26);
			this->lFileMaker->TabIndex = 87;
			this->lFileMaker->Text = L"Gerar os Arquivos";
			this->lFileMaker->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tabAdvRes
			// 
			this->tabAdvRes->Controls->Add(this->bScenario);
			this->tabAdvRes->Controls->Add(this->lScenarioYearsConfirm);
			this->tabAdvRes->Controls->Add(this->lScenarioYears);
			this->tabAdvRes->Controls->Add(this->lvYearScenario);
			this->tabAdvRes->Controls->Add(this->tScenarioName);
			this->tabAdvRes->Controls->Add(this->lScenarioName);
			this->tabAdvRes->Controls->Add(this->tScenariosStartTime);
			this->tabAdvRes->Controls->Add(this->lScenariosStartTime);
			this->tabAdvRes->Controls->Add(this->cScenario);
			this->tabAdvRes->Controls->Add(this->lAtualizaveis);
			this->tabAdvRes->Controls->Add(this->bDynamicSelect);
			this->tabAdvRes->Controls->Add(this->lDynamicConfirm);
			this->tabAdvRes->Controls->Add(this->lAnosVariaveis);
			this->tabAdvRes->Controls->Add(this->lvYearsDynamic);
			this->tabAdvRes->Controls->Add(this->cDynamicVariables);
			this->tabAdvRes->Location = System::Drawing::Point(4, 22);
			this->tabAdvRes->Name = L"tabAdvRes";
			this->tabAdvRes->Padding = System::Windows::Forms::Padding(3);
			this->tabAdvRes->Size = System::Drawing::Size(717, 455);
			this->tabAdvRes->TabIndex = 6;
			this->tabAdvRes->Text = L"Recursos Avançados";
			this->tabAdvRes->UseVisualStyleBackColor = true;
			// 
			// bScenario
			// 
			this->bScenario->Location = System::Drawing::Point(476, 380);
			this->bScenario->Name = L"bScenario";
			this->bScenario->Size = System::Drawing::Size(75, 23);
			this->bScenario->TabIndex = 107;
			this->bScenario->Text = L"Selecionar";
			this->bScenario->UseVisualStyleBackColor = true;
			this->bScenario->Visible = false;
			this->bScenario->Click += gcnew System::EventHandler(this, &NovoModelo::bScenario_Click);
			// 
			// lScenarioYearsConfirm
			// 
			this->lScenarioYearsConfirm->AutoSize = true;
			this->lScenarioYearsConfirm->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lScenarioYearsConfirm->Location = System::Drawing::Point(435, 417);
			this->lScenarioYearsConfirm->Name = L"lScenarioYearsConfirm";
			this->lScenarioYearsConfirm->Size = System::Drawing::Size(0, 19);
			this->lScenarioYearsConfirm->TabIndex = 106;
			this->lScenarioYearsConfirm->Visible = false;
			// 
			// lScenarioYears
			// 
			this->lScenarioYears->AutoSize = true;
			this->lScenarioYears->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lScenarioYears->Location = System::Drawing::Point(433, 219);
			this->lScenarioYears->Name = L"lScenarioYears";
			this->lScenarioYears->Size = System::Drawing::Size(163, 23);
			this->lScenarioYears->TabIndex = 105;
			this->lScenarioYears->Text = L"Anos com Variáveis";
			this->lScenarioYears->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lScenarioYears->Visible = false;
			// 
			// lvYearScenario
			// 
			this->lvYearScenario->Location = System::Drawing::Point(428, 245);
			this->lvYearScenario->Name = L"lvYearScenario";
			this->lvYearScenario->Size = System::Drawing::Size(171, 129);
			this->lvYearScenario->TabIndex = 104;
			this->lvYearScenario->UseCompatibleStateImageBehavior = false;
			this->lvYearScenario->Visible = false;
			// 
			// tScenarioName
			// 
			this->tScenarioName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tScenarioName->Location = System::Drawing::Point(432, 180);
			this->tScenarioName->Name = L"tScenarioName";
			this->tScenarioName->Size = System::Drawing::Size(162, 20);
			this->tScenarioName->TabIndex = 103;
			this->tScenarioName->Text = L"cenarioA";
			this->tScenarioName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tScenarioName->Visible = false;
			this->tScenarioName->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lScenarioName
			// 
			this->lScenarioName->AutoSize = true;
			this->lScenarioName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lScenarioName->Location = System::Drawing::Point(440, 151);
			this->lScenarioName->Name = L"lScenarioName";
			this->lScenarioName->Size = System::Drawing::Size(147, 23);
			this->lScenarioName->TabIndex = 102;
			this->lScenarioName->Text = L"Nome de Cenário";
			this->lScenarioName->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lScenarioName->Visible = false;
			// 
			// tScenariosStartTime
			// 
			this->tScenariosStartTime->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tScenariosStartTime->Location = System::Drawing::Point(432, 111);
			this->tScenariosStartTime->Name = L"tScenariosStartTime";
			this->tScenariosStartTime->Size = System::Drawing::Size(162, 20);
			this->tScenariosStartTime->TabIndex = 101;
			this->tScenariosStartTime->Text = L"2015";
			this->tScenariosStartTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tScenariosStartTime->Visible = false;
			this->tScenariosStartTime->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			this->tScenariosStartTime->Leave += gcnew System::EventHandler(this, &NovoModelo::validateDate);
			// 
			// lScenariosStartTime
			// 
			this->lScenariosStartTime->AutoSize = true;
			this->lScenariosStartTime->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lScenariosStartTime->Location = System::Drawing::Point(413, 82);
			this->lScenariosStartTime->Name = L"lScenariosStartTime";
			this->lScenariosStartTime->Size = System::Drawing::Size(202, 23);
			this->lScenariosStartTime->TabIndex = 100;
			this->lScenariosStartTime->Text = L"Ano de Início do Cenário";
			this->lScenariosStartTime->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lScenariosStartTime->Visible = false;
			// 
			// cScenario
			// 
			this->cScenario->AutoSize = true;
			this->cScenario->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cScenario->Location = System::Drawing::Point(467, 21);
			this->cScenario->Name = L"cScenario";
			this->cScenario->Size = System::Drawing::Size(98, 27);
			this->cScenario->TabIndex = 99;
			this->cScenario->Text = L"Cenários";
			this->cScenario->UseVisualStyleBackColor = true;
			this->cScenario->CheckedChanged += gcnew System::EventHandler(this, &NovoModelo::cScenario_CheckedChanged);
			// 
			// lAtualizaveis
			// 
			this->lAtualizaveis->AutoSize = true;
			this->lAtualizaveis->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAtualizaveis->Location = System::Drawing::Point(86, 86);
			this->lAtualizaveis->Name = L"lAtualizaveis";
			this->lAtualizaveis->Size = System::Drawing::Size(168, 23);
			this->lAtualizaveis->TabIndex = 98;
			this->lAtualizaveis->Text = L"a serem Atualizadas";
			this->lAtualizaveis->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lAtualizaveis->Visible = false;
			// 
			// bDynamicSelect
			// 
			this->bDynamicSelect->Location = System::Drawing::Point(127, 290);
			this->bDynamicSelect->Name = L"bDynamicSelect";
			this->bDynamicSelect->Size = System::Drawing::Size(75, 23);
			this->bDynamicSelect->TabIndex = 97;
			this->bDynamicSelect->Text = L"Selecionar";
			this->bDynamicSelect->UseVisualStyleBackColor = true;
			this->bDynamicSelect->Visible = false;
			this->bDynamicSelect->Click += gcnew System::EventHandler(this, &NovoModelo::bDynamicSelect_Click);
			// 
			// lDynamicConfirm
			// 
			this->lDynamicConfirm->AutoSize = true;
			this->lDynamicConfirm->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDynamicConfirm->Location = System::Drawing::Point(79, 327);
			this->lDynamicConfirm->Name = L"lDynamicConfirm";
			this->lDynamicConfirm->Size = System::Drawing::Size(0, 19);
			this->lDynamicConfirm->TabIndex = 96;
			this->lDynamicConfirm->Visible = false;
			// 
			// lAnosVariaveis
			// 
			this->lAnosVariaveis->AutoSize = true;
			this->lAnosVariaveis->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAnosVariaveis->Location = System::Drawing::Point(89, 64);
			this->lAnosVariaveis->Name = L"lAnosVariaveis";
			this->lAnosVariaveis->Size = System::Drawing::Size(163, 23);
			this->lAnosVariaveis->TabIndex = 95;
			this->lAnosVariaveis->Text = L"Anos com Variáveis";
			this->lAnosVariaveis->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lAnosVariaveis->Visible = false;
			// 
			// lvYearsDynamic
			// 
			this->lvYearsDynamic->Location = System::Drawing::Point(83, 112);
			this->lvYearsDynamic->Name = L"lvYearsDynamic";
			this->lvYearsDynamic->Size = System::Drawing::Size(171, 166);
			this->lvYearsDynamic->TabIndex = 94;
			this->lvYearsDynamic->UseCompatibleStateImageBehavior = false;
			this->lvYearsDynamic->Visible = false;
			// 
			// cDynamicVariables
			// 
			this->cDynamicVariables->AutoSize = true;
			this->cDynamicVariables->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cDynamicVariables->Location = System::Drawing::Point(83, 21);
			this->cDynamicVariables->Name = L"cDynamicVariables";
			this->cDynamicVariables->Size = System::Drawing::Size(186, 27);
			this->cDynamicVariables->TabIndex = 88;
			this->cDynamicVariables->Text = L"Variáveis Dinâmicas";
			this->cDynamicVariables->UseVisualStyleBackColor = true;
			this->cDynamicVariables->CheckedChanged += gcnew System::EventHandler(this, &NovoModelo::cDynamicVariables_CheckedChanged);
			// 
			// tabValidation
			// 
			this->tabValidation->Controls->Add(this->lRangeHelp);
			this->tabValidation->Controls->Add(this->cbValidationMethod);
			this->tabValidation->Controls->Add(this->cSaveValidationFile);
			this->tabValidation->Controls->Add(this->cValidationSave);
			this->tabValidation->Controls->Add(this->lThemeHelp);
			this->tabValidation->Controls->Add(this->lSimResult);
			this->tabValidation->Controls->Add(this->tNumberWindows);
			this->tabValidation->Controls->Add(this->lNumbWindows);
			this->tabValidation->Controls->Add(this->tRange);
			this->tabValidation->Controls->Add(this->lRange);
			this->tabValidation->Controls->Add(this->lValidationMethod);
			this->tabValidation->Controls->Add(this->bValidate);
			this->tabValidation->Controls->Add(this->tAttributeFinalValidation);
			this->tabValidation->Controls->Add(this->lAttributeFinalValidation);
			this->tabValidation->Controls->Add(this->tAttributeInitValidation);
			this->tabValidation->Controls->Add(this->lAttributeInitValidation);
			this->tabValidation->Controls->Add(this->tAttributeForValidation);
			this->tabValidation->Controls->Add(this->lAttributeForValidation);
			this->tabValidation->Controls->Add(this->tInputThemeName);
			this->tabValidation->Controls->Add(this->lInputThemeName);
			this->tabValidation->Location = System::Drawing::Point(4, 22);
			this->tabValidation->Name = L"tabValidation";
			this->tabValidation->Padding = System::Windows::Forms::Padding(3);
			this->tabValidation->Size = System::Drawing::Size(717, 455);
			this->tabValidation->TabIndex = 7;
			this->tabValidation->Text = L"Validação";
			this->tabValidation->UseVisualStyleBackColor = true;
			// 
			// lRangeHelp
			// 
			this->lRangeHelp->AutoSize = true;
			this->lRangeHelp->Font = (gcnew System::Drawing::Font(L"Calibri", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRangeHelp->Location = System::Drawing::Point(568, 185);
			this->lRangeHelp->Name = L"lRangeHelp";
			this->lRangeHelp->Size = System::Drawing::Size(38, 13);
			this->lRangeHelp->TabIndex = 120;
			this->lRangeHelp->Text = L"0 - 100";
			this->lRangeHelp->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// cbValidationMethod
			// 
			this->cbValidationMethod->BackColor = System::Drawing::SystemColors::Window;
			this->cbValidationMethod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbValidationMethod->Location = System::Drawing::Point(195, 68);
			this->cbValidationMethod->Name = L"cbValidationMethod";
			this->cbValidationMethod->Size = System::Drawing::Size(316, 21);
			this->cbValidationMethod->TabIndex = 105;
			// 
			// cSaveValidationFile
			// 
			this->cSaveValidationFile->AutoSize = true;
			this->cSaveValidationFile->Font = (gcnew System::Drawing::Font(L"Calibri", 12.25F, System::Drawing::FontStyle::Bold));
			this->cSaveValidationFile->Location = System::Drawing::Point(8, 428);
			this->cSaveValidationFile->Name = L"cSaveValidationFile";
			this->cSaveValidationFile->Size = System::Drawing::Size(249, 25);
			this->cSaveValidationFile->TabIndex = 119;
			this->cSaveValidationFile->Text = L"Salvar os Arquivos de Validação";
			this->cSaveValidationFile->UseVisualStyleBackColor = true;
			// 
			// cValidationSave
			// 
			this->cValidationSave->AutoSize = true;
			this->cValidationSave->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cValidationSave->Location = System::Drawing::Point(240, 320);
			this->cValidationSave->Name = L"cValidationSave";
			this->cValidationSave->Size = System::Drawing::Size(232, 27);
			this->cValidationSave->TabIndex = 119;
			this->cValidationSave->Text = L"Salvar no Bando de Dados";
			this->cValidationSave->UseVisualStyleBackColor = true;
			// 
			// lThemeHelp
			// 
			this->lThemeHelp->AutoSize = true;
			this->lThemeHelp->Font = (gcnew System::Drawing::Font(L"Calibri", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lThemeHelp->Location = System::Drawing::Point(52, 185);
			this->lThemeHelp->Name = L"lThemeHelp";
			this->lThemeHelp->Size = System::Drawing::Size(124, 13);
			this->lThemeHelp->TabIndex = 118;
			this->lThemeHelp->Text = L"Tema de Saída do Modelo";
			this->lThemeHelp->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lSimResult
			// 
			this->lSimResult->AutoSize = true;
			this->lSimResult->Font = (gcnew System::Drawing::Font(L"Calibri", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSimResult->Location = System::Drawing::Point(65, 281);
			this->lSimResult->Name = L"lSimResult";
			this->lSimResult->Size = System::Drawing::Size(98, 13);
			this->lSimResult->TabIndex = 117;
			this->lSimResult->Text = L"Resultado Simulado";
			this->lSimResult->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tNumberWindows
			// 
			this->tNumberWindows->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tNumberWindows->Location = System::Drawing::Point(506, 258);
			this->tNumberWindows->Name = L"tNumberWindows";
			this->tNumberWindows->Size = System::Drawing::Size(162, 20);
			this->tNumberWindows->TabIndex = 116;
			this->tNumberWindows->Text = L"10";
			this->tNumberWindows->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tNumberWindows->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lNumbWindows
			// 
			this->lNumbWindows->AutoSize = true;
			this->lNumbWindows->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lNumbWindows->Location = System::Drawing::Point(502, 232);
			this->lNumbWindows->Name = L"lNumbWindows";
			this->lNumbWindows->Size = System::Drawing::Size(173, 23);
			this->lNumbWindows->TabIndex = 115;
			this->lNumbWindows->Text = L"Number of Windows";
			this->lNumbWindows->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tRange
			// 
			this->tRange->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRange->Location = System::Drawing::Point(506, 162);
			this->tRange->Name = L"tRange";
			this->tRange->Size = System::Drawing::Size(162, 20);
			this->tRange->TabIndex = 105;
			this->tRange->Text = L"0";
			this->tRange->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRange->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lRange
			// 
			this->lRange->AutoSize = true;
			this->lRange->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRange->Location = System::Drawing::Point(472, 136);
			this->lRange->Name = L"lRange";
			this->lRange->Size = System::Drawing::Size(227, 23);
			this->lRange->TabIndex = 113;
			this->lRange->Text = L"% Erro Permitido por Célula";
			this->lRange->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lValidationMethod
			// 
			this->lValidationMethod->AutoSize = true;
			this->lValidationMethod->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lValidationMethod->Location = System::Drawing::Point(227, 42);
			this->lValidationMethod->Name = L"lValidationMethod";
			this->lValidationMethod->Size = System::Drawing::Size(267, 23);
			this->lValidationMethod->TabIndex = 112;
			this->lValidationMethod->Text = L"Método de Validação/Calibração";
			this->lValidationMethod->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// bValidate
			// 
			this->bValidate->Location = System::Drawing::Point(264, 383);
			this->bValidate->Name = L"bValidate";
			this->bValidate->Size = System::Drawing::Size(185, 47);
			this->bValidate->TabIndex = 110;
			this->bValidate->Text = L"Validar";
			this->bValidate->UseVisualStyleBackColor = true;
			this->bValidate->Click += gcnew System::EventHandler(this, &NovoModelo::bValidate_Click);
			// 
			// tAttributeFinalValidation
			// 
			this->tAttributeFinalValidation->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAttributeFinalValidation->Location = System::Drawing::Point(275, 258);
			this->tAttributeFinalValidation->Name = L"tAttributeFinalValidation";
			this->tAttributeFinalValidation->Size = System::Drawing::Size(162, 20);
			this->tAttributeFinalValidation->TabIndex = 107;
			this->tAttributeFinalValidation->Text = L"desmatamento";
			this->tAttributeFinalValidation->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAttributeFinalValidation->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lAttributeFinalValidation
			// 
			this->lAttributeFinalValidation->AutoSize = true;
			this->lAttributeFinalValidation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAttributeFinalValidation->Location = System::Drawing::Point(277, 232);
			this->lAttributeFinalValidation->Name = L"lAttributeFinalValidation";
			this->lAttributeFinalValidation->Size = System::Drawing::Size(158, 23);
			this->lAttributeFinalValidation->TabIndex = 108;
			this->lAttributeFinalValidation->Text = L"Atributo Real Final";
			this->lAttributeFinalValidation->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAttributeInitValidation
			// 
			this->tAttributeInitValidation->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAttributeInitValidation->Location = System::Drawing::Point(275, 162);
			this->tAttributeInitValidation->Name = L"tAttributeInitValidation";
			this->tAttributeInitValidation->Size = System::Drawing::Size(162, 20);
			this->tAttributeInitValidation->TabIndex = 104;
			this->tAttributeInitValidation->Text = L"desmatamento";
			this->tAttributeInitValidation->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAttributeInitValidation->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			this->tAttributeInitValidation->Leave += gcnew System::EventHandler(this, &NovoModelo::tAttributeInitValidation_Leave);
			// 
			// lAttributeInitValidation
			// 
			this->lAttributeInitValidation->AutoSize = true;
			this->lAttributeInitValidation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAttributeInitValidation->Location = System::Drawing::Point(292, 136);
			this->lAttributeInitValidation->Name = L"lAttributeInitValidation";
			this->lAttributeInitValidation->Size = System::Drawing::Size(128, 23);
			this->lAttributeInitValidation->TabIndex = 106;
			this->lAttributeInitValidation->Text = L"Atributo Inicial";
			this->lAttributeInitValidation->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAttributeForValidation
			// 
			this->tAttributeForValidation->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAttributeForValidation->Location = System::Drawing::Point(33, 258);
			this->tAttributeForValidation->Name = L"tAttributeForValidation";
			this->tAttributeForValidation->Size = System::Drawing::Size(162, 20);
			this->tAttributeForValidation->TabIndex = 106;
			this->tAttributeForValidation->Text = L"desmatamento_out";
			this->tAttributeForValidation->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAttributeForValidation->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lAttributeForValidation
			// 
			this->lAttributeForValidation->AutoSize = true;
			this->lAttributeForValidation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAttributeForValidation->Location = System::Drawing::Point(19, 232);
			this->lAttributeForValidation->Name = L"lAttributeForValidation";
			this->lAttributeForValidation->Size = System::Drawing::Size(191, 23);
			this->lAttributeForValidation->TabIndex = 104;
			this->lAttributeForValidation->Text = L"Atributo a ser Validado";
			this->lAttributeForValidation->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tInputThemeName
			// 
			this->tInputThemeName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tInputThemeName->Location = System::Drawing::Point(33, 162);
			this->tInputThemeName->Name = L"tInputThemeName";
			this->tInputThemeName->Size = System::Drawing::Size(162, 20);
			this->tInputThemeName->TabIndex = 103;
			this->tInputThemeName->Text = L"theme_name";
			this->tInputThemeName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tInputThemeName->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lInputThemeName
			// 
			this->lInputThemeName->AutoSize = true;
			this->lInputThemeName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lInputThemeName->Location = System::Drawing::Point(51, 136);
			this->lInputThemeName->Name = L"lInputThemeName";
			this->lInputThemeName->Size = System::Drawing::Size(127, 23);
			this->lInputThemeName->TabIndex = 102;
			this->lInputThemeName->Text = L"Nome do Tema";
			this->lInputThemeName->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 655);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(745, 22);
			this->statusStrip1->TabIndex = 19;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// NovoModelo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(745, 677);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->tNovoModelo);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"NovoModelo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Criando um Novo Modelo";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &NovoModelo::NovoModelo_FormClosing);
			this->Load += gcnew System::EventHandler(this, &NovoModelo::NovoModelo_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tNovoModelo->ResumeLayout(false);
			this->tabDefModel->ResumeLayout(false);
			this->tabDefModel->PerformLayout();
			this->tabDefSpatial->ResumeLayout(false);
			this->tabDefSpatial->PerformLayout();
			this->tabLUT->ResumeLayout(false);
			this->tabLUT->PerformLayout();
			this->tabComponent->ResumeLayout(false);
			this->tabComponent->PerformLayout();
			this->tabSaveParam->ResumeLayout(false);
			this->tabSaveParam->PerformLayout();
			this->tabFileMaker->ResumeLayout(false);
			this->tabFileMaker->PerformLayout();
			this->tabAdvRes->ResumeLayout(false);
			this->tabAdvRes->PerformLayout();
			this->tabValidation->ResumeLayout(false);
			this->tabValidation->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkLanguage();
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSelectFolder_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSelectDatabase_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bLUTManager_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bLUNDManager_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bD_PCVINPE_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bD_CITwoDM_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bD_CIThreeDM_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bPotDiscrete_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bPotContinuous_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bAllocDiscrete_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bAllocContinuous_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cSaveYearly_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSelectedYears_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tNovoModelo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSelectedAttr_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bGerarArquivos_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bRun_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NovoModelo_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void idiomaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void sobreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void novoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void abrirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void luccMEToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NovoModelo_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void cDynamicVariables_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bDynamicSelect_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cScenario_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bValidate_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tAttributeInitValidation_Leave(System::Object^  sender, System::EventArgs^  e);
	private: System::Int16 countCaracter(String^ source, char caracter);
	private: System::Void showReturnLinearRegression();
	private: System::Void showReturnSpatialLagRegression(); 
	private: System::Void showReturnSpatialLagLinearRoads();
	private: System::Void showReturnDistanceRule(String^ componentName); 
	private: System::Void showReturnLogisticRegression();
	private: System::Void showReturnNeighAttractionLogisticRegression();
	private: System::Void showReturnMaxEntLike(String^ component);
	private: System::Void showReturnARLR();
	private: System::Void tModelName_Leave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bShape_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bScenario_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void LuccME::NovoModelo::checkScenarioDynamicVariableDates();
	private: System::Void validateDate(System::Object^  sender, System::EventArgs^  e);
};
}

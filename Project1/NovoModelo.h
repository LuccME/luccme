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
		System::Windows::Forms::TextBox^  tbSelectedBatabase;
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
		String^ gSAccess = "";
		String^ gSMainImport = "";
		String^ gSMainImportTitle = "";
		String^ gSMainLoad = "";
		String^ gSMainLoadTitle = "";
		String^ gSMainFile = "";
		String^ gSSubmodelFile = "";
		String^ gSLuaFile = "";
		String^ gSDBTitle = "";
		String^ gSDBFilter = "";
		String^ gSMySQL = "";
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

	public:
		String^ gLandUseTypes = "";
		String^ gLandUseNoData = "";
		String^ gSelectedDatabase = "";
		String^ gDemand = "";
		String^ gDemandLUT = "";
		String^ gDemandFinalYear = "";
		String^ gDemandMiddleYear = "";
		int gDemandComponent = 0;
		String^ gPotential = "";
		String^ gPotentialLUT = "";
		int gPotentialComponent = 0;
		int gAllocationComponent = 0;
		String^ gAllocation = "";
		String^ gAllocationLUT = "";
		String^ gAttrLUT = "";
		int gAttrTime = 0;
		int gDynTime = 0;

	private: System::Windows::Forms::TextBox^  tbDemand;
	private: System::Windows::Forms::Button^  bPotContinuous;
	private: System::Windows::Forms::Button^  bPotDiscrete;
	private: System::Windows::Forms::TextBox^  tbPotential;
	private: System::Windows::Forms::Label^  lPotential;
	private: System::Windows::Forms::TextBox^  tbAllocation;
	private: System::Windows::Forms::Button^  bAllocContinuous;
	private: System::Windows::Forms::Button^  bAllocDiscrete;
	private: System::Windows::Forms::Label^  lAllocation;
	private: System::Windows::Forms::TabPage^  tabPage5;
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
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::Label^  lFileMaker;
	private: System::Windows::Forms::Button^  bGerarArquivos;
	private: System::Windows::Forms::CheckBox^  cIsCoupled;
	private: System::Windows::Forms::Button^  bRun;
	private: System::Windows::Forms::Label^  lRunModel;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;

	public:
		bool access = false;
		bool lOpen = false;
		String^ lLanguage;
private: System::Windows::Forms::TabPage^  tabPage7;
private: System::Windows::Forms::CheckBox^  cDynamicVariables;
private: System::Windows::Forms::Label^  lAtualizaveis;
private: System::Windows::Forms::Button^  bDynamicSelect;
private: System::Windows::Forms::Label^  lDynamicConfirm;
private: System::Windows::Forms::Label^  lAnosVariaveis;
private: System::Windows::Forms::ListView^  lvYearsDynamic;
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
	private: System::Windows::Forms::TabPage^  tabPage1;
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
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  bSelectDatabase;
	private: System::Windows::Forms::Button^  bMySQL;
	private: System::Windows::Forms::Label^  lOu;

	private: System::Windows::Forms::Label^  lMySQL;

	private: System::Windows::Forms::Label^  lAccess;
	private: System::Windows::Forms::TextBox^  tCellArea;
	private: System::Windows::Forms::Label^  lCellArea;
	private: System::Windows::Forms::TextBox^  tThemeName;
	private: System::Windows::Forms::Label^  lThemeName;
	private: System::Windows::Forms::Label^  lSpacialDimensions;
	private: System::Windows::Forms::Label^  lSelectedBatabase;
	private: System::Windows::Forms::Label^  lDatabase;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  lLUNDShow;
	private: System::Windows::Forms::Button^  bLUNDManager;
	private: System::Windows::Forms::Label^  lLUND;
	private: System::Windows::Forms::Label^  lLUTShow;
	private: System::Windows::Forms::Button^  bLUTManager;
	private: System::Windows::Forms::Label^  lLUTMedium;
	private: System::Windows::Forms::Label^  lLUTLarge;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Button^  bD_CIThreeDM;
	private: System::Windows::Forms::Button^  bD_CITwoDM;
	private: System::Windows::Forms::Button^  bD_PCVINPE;
	private: System::Windows::Forms::Label^  lDemand;
	private: System::Windows::Forms::Label^  lComponentes;
	protected:

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
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
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
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tbSelectedBatabase = (gcnew System::Windows::Forms::TextBox());
			this->bSelectDatabase = (gcnew System::Windows::Forms::Button());
			this->bMySQL = (gcnew System::Windows::Forms::Button());
			this->lOu = (gcnew System::Windows::Forms::Label());
			this->lMySQL = (gcnew System::Windows::Forms::Label());
			this->lAccess = (gcnew System::Windows::Forms::Label());
			this->tCellArea = (gcnew System::Windows::Forms::TextBox());
			this->lCellArea = (gcnew System::Windows::Forms::Label());
			this->tThemeName = (gcnew System::Windows::Forms::TextBox());
			this->lThemeName = (gcnew System::Windows::Forms::Label());
			this->lSpacialDimensions = (gcnew System::Windows::Forms::Label());
			this->lSelectedBatabase = (gcnew System::Windows::Forms::Label());
			this->lDatabase = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->lLUNDShow = (gcnew System::Windows::Forms::Label());
			this->bLUNDManager = (gcnew System::Windows::Forms::Button());
			this->lLUND = (gcnew System::Windows::Forms::Label());
			this->lLUTShow = (gcnew System::Windows::Forms::Label());
			this->bLUTManager = (gcnew System::Windows::Forms::Button());
			this->lLUTMedium = (gcnew System::Windows::Forms::Label());
			this->lLUTLarge = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
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
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->cIsCoupled = (gcnew System::Windows::Forms::CheckBox());
			this->bSelectedAttr = (gcnew System::Windows::Forms::Button());
			this->lAttrToSave = (gcnew System::Windows::Forms::Label());
			this->bSelectedYears = (gcnew System::Windows::Forms::Button());
			this->lYearsToSave = (gcnew System::Windows::Forms::Label());
			this->lSaveAttr = (gcnew System::Windows::Forms::Label());
			this->lvSaveAttr = (gcnew System::Windows::Forms::ListView());
			this->lSelectYears = (gcnew System::Windows::Forms::Label());
			this->lvYearsToSave = (gcnew System::Windows::Forms::ListView());
			this->cSaveYearly = (gcnew System::Windows::Forms::CheckBox());
			this->lSalvar = (gcnew System::Windows::Forms::Label());
			this->tOutputTheme = (gcnew System::Windows::Forms::TextBox());
			this->lOutputTheme = (gcnew System::Windows::Forms::Label());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->bRun = (gcnew System::Windows::Forms::Button());
			this->lRunModel = (gcnew System::Windows::Forms::Label());
			this->bGerarArquivos = (gcnew System::Windows::Forms::Button());
			this->lFileMaker = (gcnew System::Windows::Forms::Label());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->lAtualizaveis = (gcnew System::Windows::Forms::Label());
			this->bDynamicSelect = (gcnew System::Windows::Forms::Button());
			this->lDynamicConfirm = (gcnew System::Windows::Forms::Label());
			this->lAnosVariaveis = (gcnew System::Windows::Forms::Label());
			this->lvYearsDynamic = (gcnew System::Windows::Forms::ListView());
			this->cDynamicVariables = (gcnew System::Windows::Forms::CheckBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->tNovoModelo->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->tabPage7->SuspendLayout();
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
			this->menuStrip1->Size = System::Drawing::Size(735, 24);
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
			this->tNovoModelo->Controls->Add(this->tabPage1);
			this->tNovoModelo->Controls->Add(this->tabPage2);
			this->tNovoModelo->Controls->Add(this->tabPage3);
			this->tNovoModelo->Controls->Add(this->tabPage4);
			this->tNovoModelo->Controls->Add(this->tabPage5);
			this->tNovoModelo->Controls->Add(this->tabPage6);
			this->tNovoModelo->Controls->Add(this->tabPage7);
			this->tNovoModelo->Location = System::Drawing::Point(12, 173);
			this->tNovoModelo->Name = L"tNovoModelo";
			this->tNovoModelo->SelectedIndex = 0;
			this->tNovoModelo->Size = System::Drawing::Size(711, 481);
			this->tNovoModelo->TabIndex = 18;
			this->tNovoModelo->SelectedIndexChanged += gcnew System::EventHandler(this, &NovoModelo::tNovoModelo_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->tEndTime);
			this->tabPage1->Controls->Add(this->lEndTime);
			this->tabPage1->Controls->Add(this->lDefinicoesModelo);
			this->tabPage1->Controls->Add(this->lArquivos);
			this->tabPage1->Controls->Add(this->tStartTime);
			this->tabPage1->Controls->Add(this->lStartTime);
			this->tabPage1->Controls->Add(this->tModelName);
			this->tabPage1->Controls->Add(this->lModelName);
			this->tabPage1->Controls->Add(this->lSelectedFolder);
			this->tabPage1->Controls->Add(this->bSelectFolder);
			this->tabPage1->Controls->Add(this->lDirProj);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(703, 455);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Definições do Modelo";
			this->tabPage1->UseVisualStyleBackColor = true;
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
			this->lDefinicoesModelo->Location = System::Drawing::Point(249, 171);
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
			this->lArquivos->Location = System::Drawing::Point(302, 26);
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
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->tbSelectedBatabase);
			this->tabPage2->Controls->Add(this->bSelectDatabase);
			this->tabPage2->Controls->Add(this->bMySQL);
			this->tabPage2->Controls->Add(this->lOu);
			this->tabPage2->Controls->Add(this->lMySQL);
			this->tabPage2->Controls->Add(this->lAccess);
			this->tabPage2->Controls->Add(this->tCellArea);
			this->tabPage2->Controls->Add(this->lCellArea);
			this->tabPage2->Controls->Add(this->tThemeName);
			this->tabPage2->Controls->Add(this->lThemeName);
			this->tabPage2->Controls->Add(this->lSpacialDimensions);
			this->tabPage2->Controls->Add(this->lSelectedBatabase);
			this->tabPage2->Controls->Add(this->lDatabase);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(703, 455);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Definições Espaciais";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tbSelectedBatabase
			// 
			this->tbSelectedBatabase->BackColor = System::Drawing::SystemColors::Control;
			this->tbSelectedBatabase->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSelectedBatabase->Location = System::Drawing::Point(19, 124);
			this->tbSelectedBatabase->Multiline = true;
			this->tbSelectedBatabase->Name = L"tbSelectedBatabase";
			this->tbSelectedBatabase->Size = System::Drawing::Size(496, 98);
			this->tbSelectedBatabase->TabIndex = 90;
			// 
			// bSelectDatabase
			// 
			this->bSelectDatabase->Location = System::Drawing::Point(302, 94);
			this->bSelectDatabase->Name = L"bSelectDatabase";
			this->bSelectDatabase->Size = System::Drawing::Size(75, 23);
			this->bSelectDatabase->TabIndex = 79;
			this->bSelectDatabase->Text = L"Selecionar";
			this->bSelectDatabase->UseVisualStyleBackColor = true;
			this->bSelectDatabase->Click += gcnew System::EventHandler(this, &NovoModelo::bSelectDatabase_Click);
			// 
			// bMySQL
			// 
			this->bMySQL->Location = System::Drawing::Point(440, 94);
			this->bMySQL->Name = L"bMySQL";
			this->bMySQL->Size = System::Drawing::Size(75, 23);
			this->bMySQL->TabIndex = 87;
			this->bMySQL->Text = L"Configurar";
			this->bMySQL->UseVisualStyleBackColor = true;
			this->bMySQL->Click += gcnew System::EventHandler(this, &NovoModelo::bMySQL_Click);
			// 
			// lOu
			// 
			this->lOu->AutoSize = true;
			this->lOu->Font = (gcnew System::Drawing::Font(L"Calibri", 8, System::Drawing::FontStyle::Bold));
			this->lOu->Location = System::Drawing::Point(399, 100);
			this->lOu->Name = L"lOu";
			this->lOu->Size = System::Drawing::Size(19, 13);
			this->lOu->TabIndex = 89;
			this->lOu->Text = L"ou";
			this->lOu->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lMySQL
			// 
			this->lMySQL->AutoSize = true;
			this->lMySQL->Font = (gcnew System::Drawing::Font(L"Calibri", 8, System::Drawing::FontStyle::Bold));
			this->lMySQL->Location = System::Drawing::Point(456, 78);
			this->lMySQL->Name = L"lMySQL";
			this->lMySQL->Size = System::Drawing::Size(40, 13);
			this->lMySQL->TabIndex = 88;
			this->lMySQL->Text = L"MySQL";
			this->lMySQL->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lAccess
			// 
			this->lAccess->AutoSize = true;
			this->lAccess->Font = (gcnew System::Drawing::Font(L"Calibri", 8, System::Drawing::FontStyle::Bold));
			this->lAccess->Location = System::Drawing::Point(322, 78);
			this->lAccess->Name = L"lAccess";
			this->lAccess->Size = System::Drawing::Size(38, 13);
			this->lAccess->TabIndex = 86;
			this->lAccess->Text = L"Access";
			this->lAccess->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tCellArea
			// 
			this->tCellArea->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tCellArea->Location = System::Drawing::Point(238, 284);
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
			this->tThemeName->Location = System::Drawing::Point(238, 241);
			this->tThemeName->Name = L"tThemeName";
			this->tThemeName->Size = System::Drawing::Size(194, 20);
			this->tThemeName->TabIndex = 83;
			this->tThemeName->Text = L"theme_name";
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
			this->lDatabase->Size = System::Drawing::Size(226, 23);
			this->lDatabase->TabIndex = 78;
			this->lDatabase->Text = L"Arquivo do Banco de Dados";
			this->lDatabase->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->lLUNDShow);
			this->tabPage3->Controls->Add(this->bLUNDManager);
			this->tabPage3->Controls->Add(this->lLUND);
			this->tabPage3->Controls->Add(this->lLUTShow);
			this->tabPage3->Controls->Add(this->bLUTManager);
			this->tabPage3->Controls->Add(this->lLUTMedium);
			this->tabPage3->Controls->Add(this->lLUTLarge);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(703, 455);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Tipos de Uso da Terra";
			this->tabPage3->UseVisualStyleBackColor = true;
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
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->tbAllocation);
			this->tabPage4->Controls->Add(this->bAllocContinuous);
			this->tabPage4->Controls->Add(this->bAllocDiscrete);
			this->tabPage4->Controls->Add(this->lAllocation);
			this->tabPage4->Controls->Add(this->bPotContinuous);
			this->tabPage4->Controls->Add(this->bPotDiscrete);
			this->tabPage4->Controls->Add(this->tbPotential);
			this->tabPage4->Controls->Add(this->lPotential);
			this->tabPage4->Controls->Add(this->tbDemand);
			this->tabPage4->Controls->Add(this->bD_CIThreeDM);
			this->tabPage4->Controls->Add(this->bD_CITwoDM);
			this->tabPage4->Controls->Add(this->bD_PCVINPE);
			this->tabPage4->Controls->Add(this->lDemand);
			this->tabPage4->Controls->Add(this->lComponentes);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(703, 455);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Componentes";
			this->tabPage4->UseVisualStyleBackColor = true;
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
			this->bD_CIThreeDM->Text = L"Compute Input Three Date Maps";
			this->bD_CIThreeDM->UseVisualStyleBackColor = true;
			this->bD_CIThreeDM->Click += gcnew System::EventHandler(this, &NovoModelo::bD_CIThreeDM_Click);
			// 
			// bD_CITwoDM
			// 
			this->bD_CITwoDM->Location = System::Drawing::Point(22, 190);
			this->bD_CITwoDM->Name = L"bD_CITwoDM";
			this->bD_CITwoDM->Size = System::Drawing::Size(171, 39);
			this->bD_CITwoDM->TabIndex = 78;
			this->bD_CITwoDM->Text = L"Compute Input Two Date Maps";
			this->bD_CITwoDM->UseVisualStyleBackColor = true;
			this->bD_CITwoDM->Click += gcnew System::EventHandler(this, &NovoModelo::bD_CITwoDM_Click);
			// 
			// bD_PCVINPE
			// 
			this->bD_PCVINPE->Location = System::Drawing::Point(22, 120);
			this->bD_PCVINPE->Name = L"bD_PCVINPE";
			this->bD_PCVINPE->Size = System::Drawing::Size(171, 39);
			this->bD_PCVINPE->TabIndex = 77;
			this->bD_PCVINPE->Text = L"Pre Computed Values INPE";
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
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->cIsCoupled);
			this->tabPage5->Controls->Add(this->bSelectedAttr);
			this->tabPage5->Controls->Add(this->lAttrToSave);
			this->tabPage5->Controls->Add(this->bSelectedYears);
			this->tabPage5->Controls->Add(this->lYearsToSave);
			this->tabPage5->Controls->Add(this->lSaveAttr);
			this->tabPage5->Controls->Add(this->lvSaveAttr);
			this->tabPage5->Controls->Add(this->lSelectYears);
			this->tabPage5->Controls->Add(this->lvYearsToSave);
			this->tabPage5->Controls->Add(this->cSaveYearly);
			this->tabPage5->Controls->Add(this->lSalvar);
			this->tabPage5->Controls->Add(this->tOutputTheme);
			this->tabPage5->Controls->Add(this->lOutputTheme);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(703, 455);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Salvar Parâmetros";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// cIsCoupled
			// 
			this->cIsCoupled->AutoSize = true;
			this->cIsCoupled->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsCoupled->Location = System::Drawing::Point(492, 76);
			this->cIsCoupled->Name = L"cIsCoupled";
			this->cIsCoupled->Size = System::Drawing::Size(107, 27);
			this->cIsCoupled->TabIndex = 96;
			this->cIsCoupled->Text = L"isCoupled";
			this->cIsCoupled->UseVisualStyleBackColor = true;
			this->cIsCoupled->Visible = false;
			// 
			// bSelectedAttr
			// 
			this->bSelectedAttr->Location = System::Drawing::Point(515, 382);
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
			this->lAttrToSave->Location = System::Drawing::Point(460, 427);
			this->lAttrToSave->Name = L"lAttrToSave";
			this->lAttrToSave->Size = System::Drawing::Size(0, 19);
			this->lAttrToSave->TabIndex = 94;
			// 
			// bSelectedYears
			// 
			this->bSelectedYears->Location = System::Drawing::Point(110, 382);
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
			this->lYearsToSave->Location = System::Drawing::Point(64, 427);
			this->lYearsToSave->Name = L"lYearsToSave";
			this->lYearsToSave->Size = System::Drawing::Size(0, 19);
			this->lYearsToSave->TabIndex = 92;
			// 
			// lSaveAttr
			// 
			this->lSaveAttr->AutoSize = true;
			this->lSaveAttr->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSaveAttr->Location = System::Drawing::Point(446, 134);
			this->lSaveAttr->Name = L"lSaveAttr";
			this->lSaveAttr->Size = System::Drawing::Size(206, 23);
			this->lSaveAttr->TabIndex = 91;
			this->lSaveAttr->Text = L"Atributos a serem Salvos";
			this->lSaveAttr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lvSaveAttr
			// 
			this->lvSaveAttr->Location = System::Drawing::Point(464, 163);
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
			this->lSelectYears->Location = System::Drawing::Point(67, 173);
			this->lSelectYears->Name = L"lSelectYears";
			this->lSelectYears->Size = System::Drawing::Size(171, 23);
			this->lSelectYears->TabIndex = 89;
			this->lSelectYears->Text = L"Anos a serem Salvos";
			this->lSelectYears->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lSelectYears->Visible = false;
			// 
			// lvYearsToSave
			// 
			this->lvYearsToSave->Location = System::Drawing::Point(66, 204);
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
			this->cSaveYearly->Location = System::Drawing::Point(68, 134);
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
			this->tOutputTheme->Location = System::Drawing::Point(267, 84);
			this->tOutputTheme->Name = L"tOutputTheme";
			this->tOutputTheme->Size = System::Drawing::Size(162, 20);
			this->tOutputTheme->TabIndex = 85;
			this->tOutputTheme->Text = L"LuccMe_Model";
			this->tOutputTheme->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tOutputTheme->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lOutputTheme
			// 
			this->lOutputTheme->AutoSize = true;
			this->lOutputTheme->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lOutputTheme->Location = System::Drawing::Point(61, 82);
			this->lOutputTheme->Name = L"lOutputTheme";
			this->lOutputTheme->Size = System::Drawing::Size(197, 23);
			this->lOutputTheme->TabIndex = 84;
			this->lOutputTheme->Text = L"Nome do Tema de Saída";
			this->lOutputTheme->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->bRun);
			this->tabPage6->Controls->Add(this->lRunModel);
			this->tabPage6->Controls->Add(this->bGerarArquivos);
			this->tabPage6->Controls->Add(this->lFileMaker);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(703, 455);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Gerar Arquivo";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// bRun
			// 
			this->bRun->Location = System::Drawing::Point(256, 260);
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
			this->lRunModel->Location = System::Drawing::Point(274, 207);
			this->lRunModel->Name = L"lRunModel";
			this->lRunModel->Size = System::Drawing::Size(151, 26);
			this->lRunModel->TabIndex = 90;
			this->lRunModel->Text = L"Rodar o Modelo";
			this->lRunModel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lRunModel->Visible = false;
			// 
			// bGerarArquivos
			// 
			this->bGerarArquivos->Location = System::Drawing::Point(256, 78);
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
			this->lFileMaker->Location = System::Drawing::Point(268, 26);
			this->lFileMaker->Name = L"lFileMaker";
			this->lFileMaker->Size = System::Drawing::Size(165, 26);
			this->lFileMaker->TabIndex = 87;
			this->lFileMaker->Text = L"Gerar os Arquivos";
			this->lFileMaker->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->lAtualizaveis);
			this->tabPage7->Controls->Add(this->bDynamicSelect);
			this->tabPage7->Controls->Add(this->lDynamicConfirm);
			this->tabPage7->Controls->Add(this->lAnosVariaveis);
			this->tabPage7->Controls->Add(this->lvYearsDynamic);
			this->tabPage7->Controls->Add(this->cDynamicVariables);
			this->tabPage7->Location = System::Drawing::Point(4, 22);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(703, 455);
			this->tabPage7->TabIndex = 6;
			this->tabPage7->Text = L"Recursos Avançados";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// lAtualizaveis
			// 
			this->lAtualizaveis->AutoSize = true;
			this->lAtualizaveis->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAtualizaveis->Location = System::Drawing::Point(19, 82);
			this->lAtualizaveis->Name = L"lAtualizaveis";
			this->lAtualizaveis->Size = System::Drawing::Size(168, 23);
			this->lAtualizaveis->TabIndex = 98;
			this->lAtualizaveis->Text = L"a serem Atualizadas";
			this->lAtualizaveis->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lAtualizaveis->Visible = false;
			// 
			// bDynamicSelect
			// 
			this->bDynamicSelect->Location = System::Drawing::Point(60, 286);
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
			this->lDynamicConfirm->Location = System::Drawing::Point(14, 331);
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
			this->lAnosVariaveis->Location = System::Drawing::Point(22, 60);
			this->lAnosVariaveis->Name = L"lAnosVariaveis";
			this->lAnosVariaveis->Size = System::Drawing::Size(163, 23);
			this->lAnosVariaveis->TabIndex = 95;
			this->lAnosVariaveis->Text = L"Anos com Variáveis";
			this->lAnosVariaveis->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lAnosVariaveis->Visible = false;
			// 
			// lvYearsDynamic
			// 
			this->lvYearsDynamic->Location = System::Drawing::Point(16, 108);
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
			this->cDynamicVariables->Location = System::Drawing::Point(16, 17);
			this->cDynamicVariables->Name = L"cDynamicVariables";
			this->cDynamicVariables->Size = System::Drawing::Size(186, 27);
			this->cDynamicVariables->TabIndex = 88;
			this->cDynamicVariables->Text = L"Variáveis Dinamicas";
			this->cDynamicVariables->UseVisualStyleBackColor = true;
			this->cDynamicVariables->CheckedChanged += gcnew System::EventHandler(this, &NovoModelo::cDynamicVariables_CheckedChanged);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 655);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(735, 22);
			this->statusStrip1->TabIndex = 19;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// NovoModelo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(735, 677);
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
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			this->tabPage7->ResumeLayout(false);
			this->tabPage7->PerformLayout();
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
	private: System::Void bMySQL_Click(System::Object^  sender, System::EventArgs^  e);
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
};
}

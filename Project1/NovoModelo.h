#pragma once

namespace CellFulfill {

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
		String^ gSShapeTitle = "";
		String^ gSShapeFilter = "";
		String^ gSAttributes = "";
		String^ gSFileFormatError = "";
		String^ gSFileFormatErrorTitle = "";
		String^ gSAttributesTitle = "";
		String^ gSAttributesFilter = "";
		String^ gSDeleteAttribute = "";
		String^ gSDeleteAttributeTitle = "";
		String^ gSFolder = "";
		String^ gSFolderTitle = "";
		String^ gSScriptName = "";
		String^ gSScriptNameTitle = "";
		String^ gSUnauthorized = "";
		String^ gSUnauthorizedTitle = "";
		String^ gSSuccessTitle = "";
		String^ gSSuccess = "";
		String^ gSFileMissing = "";
		String^ gSFileMissingTitle = "";
		String^ gSMFE = "";
		String^ gSMFETitle = "";
		String^ gSFE = "";
		String^ gSLimitFileAddress = "";
		String^ gSLimitFileAddressTitle = "";
		String^ gSLimitFileAddress2 = "";
		String^ gSLimitFileAddress2Title = "";
		String^ gSAOMissing = "";
		String^ gSAOMissingTitle = "";
		String^ gSCellSpaceName = "";
		String^ gSCellSpaceNameTitle = "";
		String^ gSCellSpaceResolution = "";
		String^ gSCellSpaceResolutionTitle = "";
		String^ gSScriptLoad = "";
		String^ gSScriptLoadTitle = "";
		String^ gSLuaFile = "";
		String^ gSEditing = "";
		String^ gSImportError = "";
		String^ gSImportErrorTitle = "";
		String^ gSFiles = "";
		String^ gSGeometry = "";
		String^ gSGeometryTitle = "";
		
		Collections::ArrayList^ attributeList = gcnew Collections::ArrayList();
		array<String^>^ rasterList = gcnew array<String^>(RASTERLIST);
		array<String^>^ polygonList = gcnew array<String^>(POLYGONLIST);
		array<String^>^ nonPolygonList = gcnew array<String^>(NONPOLYGONLIST);

	public:
		bool closing = false;
		bool forceWriting = false;
		bool runnable = false;
		bool lOpen = false;
		bool csExist = false;
		String^ lLanguage;
		array<String^>^ gParameters = gcnew array<String^>(PARAMETERSNUMBER);
	
	private: System::Windows::Forms::ComboBox^  cbOperation;
	private: System::Windows::Forms::RadioButton^  rbTrueOperation;
	private: System::Windows::Forms::RadioButton^  rbFalseOperation;
	private: System::Windows::Forms::Label^  lAreaOperation;
	private: System::Windows::Forms::TextBox^  tSelectOperation;
	private: System::Windows::Forms::Label^  lSelectOperation;
	private: System::Windows::Forms::TextBox^  tDefaultOperation;
	private: System::Windows::Forms::Label^  lDefaultOperation;
	private: System::Windows::Forms::Button^  bSaveOperation;
	private: System::Windows::Forms::TextBox^  tSelectedAttribute;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tpScript;
	private: System::Windows::Forms::TabPage^  tpCellularSpace;
	private: System::Windows::Forms::TabPage^  tpAttributeFill;
	private: System::Windows::Forms::TabPage^  tpMakeFiles;
	private: System::Windows::Forms::Label^  lFiles;
	private: System::Windows::Forms::Label^  lDirProj;
	private: System::Windows::Forms::TextBox^  tScriptName;
	private: System::Windows::Forms::Button^  bSelectFolder;
	private: System::Windows::Forms::Label^  lScriptName;
	private: System::Windows::Forms::Label^  lSelectedFolder;
	private: System::Windows::Forms::PictureBox^  pbLogo2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lScriptDefinition;
	private: System::Windows::Forms::Label^  lLimitFileAddress;
	private: System::Windows::Forms::Button^  bShape;
	private: System::Windows::Forms::Label^  lLimitFile;
	private: System::Windows::Forms::TextBox^  tCellSpaceResolution;
	private: System::Windows::Forms::Label^  lCellSpaceResolution;
	private: System::Windows::Forms::TextBox^  tCellSpaceName;
	private: System::Windows::Forms::Label^  lCellSpaceName;
	private: System::Windows::Forms::Button^  bDeleteAttribute;
	private: System::Windows::Forms::Button^  bAddAttribute;
	private: System::Windows::Forms::ListView^  lvAttributesToFill;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  arquivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  novoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ajudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cellFillToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  preferênciasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  idiomaToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::Button^  bRun;
	private: System::Windows::Forms::Label^  lRunScript;
	private: System::Windows::Forms::Button^  bFileMaker;
	private: System::Windows::Forms::Label^  lFileMaker;
	private: System::Windows::Forms::TextBox^  tOperationOut;
	private: System::Windows::Forms::Label^  lOperationOut;
	private: System::Windows::Forms::Label^  lOperationName;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::CheckBox^  cbUseCS;
	private: System::Windows::Forms::TextBox^  tResDummy;
	private: System::Windows::Forms::Label^  lX;
	private: System::Windows::Forms::Label^  lM;
	private: System::Windows::Forms::RadioButton^  rbPolygon;
	private: System::Windows::Forms::RadioButton^  rbDot;
	private: System::Windows::Forms::RadioButton^  rbLine;
	private: System::Windows::Forms::Label^  lGeometricRepresentation;
	private: System::Windows::Forms::GroupBox^  gbGeometricRepresentation;
	private: System::Windows::Forms::TextBox^  tDummyOperation;
	private: System::Windows::Forms::Label^  lDummyOperation;
	private: System::Windows::Forms::Panel^  pPixelReference;
	private: System::Windows::Forms::RadioButton^  rbOverlap;
	private: System::Windows::Forms::RadioButton^  rbCentroid;
	private: System::Windows::Forms::Label^  lPixelReference;

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
			this->cellFillToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tpScript = (gcnew System::Windows::Forms::TabPage());
			this->lScriptDefinition = (gcnew System::Windows::Forms::Label());
			this->lFiles = (gcnew System::Windows::Forms::Label());
			this->lDirProj = (gcnew System::Windows::Forms::Label());
			this->tScriptName = (gcnew System::Windows::Forms::TextBox());
			this->bSelectFolder = (gcnew System::Windows::Forms::Button());
			this->lScriptName = (gcnew System::Windows::Forms::Label());
			this->lSelectedFolder = (gcnew System::Windows::Forms::Label());
			this->tpCellularSpace = (gcnew System::Windows::Forms::TabPage());
			this->lM = (gcnew System::Windows::Forms::Label());
			this->tResDummy = (gcnew System::Windows::Forms::TextBox());
			this->lX = (gcnew System::Windows::Forms::Label());
			this->cbUseCS = (gcnew System::Windows::Forms::CheckBox());
			this->tCellSpaceResolution = (gcnew System::Windows::Forms::TextBox());
			this->lCellSpaceResolution = (gcnew System::Windows::Forms::Label());
			this->tCellSpaceName = (gcnew System::Windows::Forms::TextBox());
			this->lCellSpaceName = (gcnew System::Windows::Forms::Label());
			this->lLimitFileAddress = (gcnew System::Windows::Forms::Label());
			this->bShape = (gcnew System::Windows::Forms::Button());
			this->lLimitFile = (gcnew System::Windows::Forms::Label());
			this->tpAttributeFill = (gcnew System::Windows::Forms::TabPage());
			this->pPixelReference = (gcnew System::Windows::Forms::Panel());
			this->rbOverlap = (gcnew System::Windows::Forms::RadioButton());
			this->rbCentroid = (gcnew System::Windows::Forms::RadioButton());
			this->lPixelReference = (gcnew System::Windows::Forms::Label());
			this->tDummyOperation = (gcnew System::Windows::Forms::TextBox());
			this->lDummyOperation = (gcnew System::Windows::Forms::Label());
			this->gbGeometricRepresentation = (gcnew System::Windows::Forms::GroupBox());
			this->rbPolygon = (gcnew System::Windows::Forms::RadioButton());
			this->rbLine = (gcnew System::Windows::Forms::RadioButton());
			this->rbDot = (gcnew System::Windows::Forms::RadioButton());
			this->lGeometricRepresentation = (gcnew System::Windows::Forms::Label());
			this->lOperationName = (gcnew System::Windows::Forms::Label());
			this->tSelectedAttribute = (gcnew System::Windows::Forms::TextBox());
			this->bSaveOperation = (gcnew System::Windows::Forms::Button());
			this->tDefaultOperation = (gcnew System::Windows::Forms::TextBox());
			this->lDefaultOperation = (gcnew System::Windows::Forms::Label());
			this->rbTrueOperation = (gcnew System::Windows::Forms::RadioButton());
			this->rbFalseOperation = (gcnew System::Windows::Forms::RadioButton());
			this->lAreaOperation = (gcnew System::Windows::Forms::Label());
			this->tOperationOut = (gcnew System::Windows::Forms::TextBox());
			this->lOperationOut = (gcnew System::Windows::Forms::Label());
			this->tSelectOperation = (gcnew System::Windows::Forms::TextBox());
			this->lSelectOperation = (gcnew System::Windows::Forms::Label());
			this->cbOperation = (gcnew System::Windows::Forms::ComboBox());
			this->bDeleteAttribute = (gcnew System::Windows::Forms::Button());
			this->bAddAttribute = (gcnew System::Windows::Forms::Button());
			this->lvAttributesToFill = (gcnew System::Windows::Forms::ListView());
			this->tpMakeFiles = (gcnew System::Windows::Forms::TabPage());
			this->bRun = (gcnew System::Windows::Forms::Button());
			this->lRunScript = (gcnew System::Windows::Forms::Label());
			this->bFileMaker = (gcnew System::Windows::Forms::Button());
			this->lFileMaker = (gcnew System::Windows::Forms::Label());
			this->pbLogo2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tpScript->SuspendLayout();
			this->tpCellularSpace->SuspendLayout();
			this->tpAttributeFill->SuspendLayout();
			this->pPixelReference->SuspendLayout();
			this->gbGeometricRepresentation->SuspendLayout();
			this->tpMakeFiles->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo2))->BeginInit();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(287, 37);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(337, 134);
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
				this->cellFillToolStripMenuItem,
					this->sobreToolStripMenuItem
			});
			this->ajudaToolStripMenuItem->Name = L"ajudaToolStripMenuItem";
			this->ajudaToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->ajudaToolStripMenuItem->Text = L"Ajuda";
			// 
			// cellFillToolStripMenuItem
			// 
			this->cellFillToolStripMenuItem->Name = L"cellFillToolStripMenuItem";
			this->cellFillToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->cellFillToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->cellFillToolStripMenuItem->Text = L"CellFulfill";
			this->cellFillToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::CellFulfillToolStripMenuItem_Click);
			// 
			// sobreToolStripMenuItem
			// 
			this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			this->sobreToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->sobreToolStripMenuItem->Text = L"Sobre";
			this->sobreToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::sobreToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 655);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(745, 22);
			this->statusStrip1->TabIndex = 19;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(0, 17);
			// 
			// tabControl1
			// 
			this->tabControl1->AllowDrop = true;
			this->tabControl1->Controls->Add(this->tpScript);
			this->tabControl1->Controls->Add(this->tpCellularSpace);
			this->tabControl1->Controls->Add(this->tpAttributeFill);
			this->tabControl1->Controls->Add(this->tpMakeFiles);
			this->tabControl1->Location = System::Drawing::Point(12, 188);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(721, 454);
			this->tabControl1->TabIndex = 20;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &NovoModelo::tabControl1_SelectedIndexChanged);
			// 
			// tpScript
			// 
			this->tpScript->AutoScroll = true;
			this->tpScript->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tpScript->Controls->Add(this->lScriptDefinition);
			this->tpScript->Controls->Add(this->lFiles);
			this->tpScript->Controls->Add(this->lDirProj);
			this->tpScript->Controls->Add(this->tScriptName);
			this->tpScript->Controls->Add(this->bSelectFolder);
			this->tpScript->Controls->Add(this->lScriptName);
			this->tpScript->Controls->Add(this->lSelectedFolder);
			this->tpScript->Location = System::Drawing::Point(4, 22);
			this->tpScript->Name = L"tpScript";
			this->tpScript->Padding = System::Windows::Forms::Padding(3);
			this->tpScript->Size = System::Drawing::Size(713, 428);
			this->tpScript->TabIndex = 0;
			this->tpScript->Text = L"Definições do Script";
			this->tpScript->UseVisualStyleBackColor = true;
			// 
			// lScriptDefinition
			// 
			this->lScriptDefinition->AutoSize = true;
			this->lScriptDefinition->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lScriptDefinition->Location = System::Drawing::Point(254, 171);
			this->lScriptDefinition->Name = L"lScriptDefinition";
			this->lScriptDefinition->Size = System::Drawing::Size(184, 26);
			this->lScriptDefinition->TabIndex = 77;
			this->lScriptDefinition->Text = L"Definições do Script";
			this->lScriptDefinition->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lFiles
			// 
			this->lFiles->AutoSize = true;
			this->lFiles->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lFiles->Location = System::Drawing::Point(302, 19);
			this->lFiles->Name = L"lFiles";
			this->lFiles->Size = System::Drawing::Size(88, 26);
			this->lFiles->TabIndex = 76;
			this->lFiles->Text = L"Arquivos";
			this->lFiles->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lDirProj
			// 
			this->lDirProj->AutoSize = true;
			this->lDirProj->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDirProj->Location = System::Drawing::Point(21, 68);
			this->lDirProj->Name = L"lDirProj";
			this->lDirProj->Size = System::Drawing::Size(224, 23);
			this->lDirProj->TabIndex = 71;
			this->lDirProj->Text = L"Pasta para Salvar os Scripts";
			this->lDirProj->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tScriptName
			// 
			this->tScriptName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tScriptName->Location = System::Drawing::Point(247, 221);
			this->tScriptName->Name = L"tScriptName";
			this->tScriptName->Size = System::Drawing::Size(194, 20);
			this->tScriptName->TabIndex = 2;
			this->tScriptName->Text = L"cellfill";
			this->tScriptName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tScriptName->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// bSelectFolder
			// 
			this->bSelectFolder->Location = System::Drawing::Point(308, 68);
			this->bSelectFolder->Name = L"bSelectFolder";
			this->bSelectFolder->Size = System::Drawing::Size(75, 23);
			this->bSelectFolder->TabIndex = 1;
			this->bSelectFolder->Text = L"Selecionar";
			this->bSelectFolder->UseVisualStyleBackColor = true;
			this->bSelectFolder->Click += gcnew System::EventHandler(this, &NovoModelo::bSelectFolder_Click);
			// 
			// lScriptName
			// 
			this->lScriptName->AutoSize = true;
			this->lScriptName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lScriptName->Location = System::Drawing::Point(21, 220);
			this->lScriptName->Name = L"lScriptName";
			this->lScriptName->Size = System::Drawing::Size(132, 23);
			this->lScriptName->TabIndex = 74;
			this->lScriptName->Text = L"Nome do Script";
			this->lScriptName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lSelectedFolder
			// 
			this->lSelectedFolder->AutoSize = true;
			this->lSelectedFolder->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSelectedFolder->Location = System::Drawing::Point(27, 122);
			this->lSelectedFolder->Name = L"lSelectedFolder";
			this->lSelectedFolder->Size = System::Drawing::Size(0, 19);
			this->lSelectedFolder->TabIndex = 73;
			// 
			// tpCellularSpace
			// 
			this->tpCellularSpace->AutoScroll = true;
			this->tpCellularSpace->Controls->Add(this->lM);
			this->tpCellularSpace->Controls->Add(this->tResDummy);
			this->tpCellularSpace->Controls->Add(this->lX);
			this->tpCellularSpace->Controls->Add(this->cbUseCS);
			this->tpCellularSpace->Controls->Add(this->tCellSpaceResolution);
			this->tpCellularSpace->Controls->Add(this->lCellSpaceResolution);
			this->tpCellularSpace->Controls->Add(this->tCellSpaceName);
			this->tpCellularSpace->Controls->Add(this->lCellSpaceName);
			this->tpCellularSpace->Controls->Add(this->lLimitFileAddress);
			this->tpCellularSpace->Controls->Add(this->bShape);
			this->tpCellularSpace->Controls->Add(this->lLimitFile);
			this->tpCellularSpace->Location = System::Drawing::Point(4, 22);
			this->tpCellularSpace->Name = L"tpCellularSpace";
			this->tpCellularSpace->Padding = System::Windows::Forms::Padding(3);
			this->tpCellularSpace->Size = System::Drawing::Size(713, 428);
			this->tpCellularSpace->TabIndex = 1;
			this->tpCellularSpace->Text = L"Criando o Espaço Celular";
			this->tpCellularSpace->UseVisualStyleBackColor = true;
			// 
			// lM
			// 
			this->lM->AutoSize = true;
			this->lM->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lM->Location = System::Drawing::Point(465, 294);
			this->lM->Name = L"lM";
			this->lM->Size = System::Drawing::Size(65, 23);
			this->lM->TabIndex = 100;
			this->lM->Text = L"metros";
			this->lM->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tResDummy
			// 
			this->tResDummy->Enabled = false;
			this->tResDummy->ForeColor = System::Drawing::Color::Black;
			this->tResDummy->Location = System::Drawing::Point(373, 293);
			this->tResDummy->Name = L"tResDummy";
			this->tResDummy->Size = System::Drawing::Size(88, 20);
			this->tResDummy->TabIndex = 99;
			this->tResDummy->Text = L"5000";
			this->tResDummy->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lX
			// 
			this->lX->AutoSize = true;
			this->lX->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lX->Location = System::Drawing::Point(348, 293);
			this->lX->Name = L"lX";
			this->lX->Size = System::Drawing::Size(19, 23);
			this->lX->TabIndex = 98;
			this->lX->Text = L"x";
			this->lX->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cbUseCS
			// 
			this->cbUseCS->AutoSize = true;
			this->cbUseCS->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbUseCS->Location = System::Drawing::Point(12, 14);
			this->cbUseCS->Name = L"cbUseCS";
			this->cbUseCS->Size = System::Drawing::Size(263, 27);
			this->cbUseCS->TabIndex = 97;
			this->cbUseCS->Text = L"Usar Espaço Celular existente";
			this->cbUseCS->UseVisualStyleBackColor = true;
			this->cbUseCS->CheckedChanged += gcnew System::EventHandler(this, &NovoModelo::cbUseCS_CheckedChanged);
			// 
			// tCellSpaceResolution
			// 
			this->tCellSpaceResolution->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tCellSpaceResolution->Location = System::Drawing::Point(254, 293);
			this->tCellSpaceResolution->Name = L"tCellSpaceResolution";
			this->tCellSpaceResolution->Size = System::Drawing::Size(88, 20);
			this->tCellSpaceResolution->TabIndex = 5;
			this->tCellSpaceResolution->Text = L"5000";
			this->tCellSpaceResolution->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tCellSpaceResolution->TextChanged += gcnew System::EventHandler(this, &NovoModelo::tCellSpaceResolution_TextChanged);
			this->tCellSpaceResolution->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lCellSpaceResolution
			// 
			this->lCellSpaceResolution->AutoSize = true;
			this->lCellSpaceResolution->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lCellSpaceResolution->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lCellSpaceResolution->Location = System::Drawing::Point(278, 260);
			this->lCellSpaceResolution->Name = L"lCellSpaceResolution";
			this->lCellSpaceResolution->Size = System::Drawing::Size(158, 23);
			this->lCellSpaceResolution->TabIndex = 96;
			this->lCellSpaceResolution->Text = L"Resolução Espacial";
			this->lCellSpaceResolution->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tCellSpaceName
			// 
			this->tCellSpaceName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tCellSpaceName->Location = System::Drawing::Point(258, 209);
			this->tCellSpaceName->Name = L"tCellSpaceName";
			this->tCellSpaceName->Size = System::Drawing::Size(194, 20);
			this->tCellSpaceName->TabIndex = 4;
			this->tCellSpaceName->Text = L"cs_out";
			this->tCellSpaceName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tCellSpaceName->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lCellSpaceName
			// 
			this->lCellSpaceName->AutoSize = true;
			this->lCellSpaceName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lCellSpaceName->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lCellSpaceName->Location = System::Drawing::Point(220, 174);
			this->lCellSpaceName->Name = L"lCellSpaceName";
			this->lCellSpaceName->Size = System::Drawing::Size(270, 23);
			this->lCellSpaceName->TabIndex = 96;
			this->lCellSpaceName->Text = L"Nome do Saída do Espaço Celular";
			this->lCellSpaceName->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lLimitFileAddress
			// 
			this->lLimitFileAddress->AutoSize = true;
			this->lLimitFileAddress->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lLimitFileAddress->Location = System::Drawing::Point(357, 140);
			this->lLimitFileAddress->Name = L"lLimitFileAddress";
			this->lLimitFileAddress->Size = System::Drawing::Size(0, 19);
			this->lLimitFileAddress->TabIndex = 95;
			// 
			// bShape
			// 
			this->bShape->Location = System::Drawing::Point(318, 99);
			this->bShape->Name = L"bShape";
			this->bShape->Size = System::Drawing::Size(75, 23);
			this->bShape->TabIndex = 3;
			this->bShape->Text = L"Selecionar";
			this->bShape->UseVisualStyleBackColor = true;
			this->bShape->Click += gcnew System::EventHandler(this, &NovoModelo::bShape_Click);
			// 
			// lLimitFile
			// 
			this->lLimitFile->AutoSize = true;
			this->lLimitFile->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lLimitFile->Location = System::Drawing::Point(209, 63);
			this->lLimitFile->Name = L"lLimitFile";
			this->lLimitFile->Size = System::Drawing::Size(293, 23);
			this->lLimitFile->TabIndex = 93;
			this->lLimitFile->Text = L"Arquivo de Limite do Espaço Celular";
			this->lLimitFile->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tpAttributeFill
			// 
			this->tpAttributeFill->AllowDrop = true;
			this->tpAttributeFill->Controls->Add(this->pPixelReference);
			this->tpAttributeFill->Controls->Add(this->lPixelReference);
			this->tpAttributeFill->Controls->Add(this->tDummyOperation);
			this->tpAttributeFill->Controls->Add(this->lDummyOperation);
			this->tpAttributeFill->Controls->Add(this->gbGeometricRepresentation);
			this->tpAttributeFill->Controls->Add(this->lGeometricRepresentation);
			this->tpAttributeFill->Controls->Add(this->lOperationName);
			this->tpAttributeFill->Controls->Add(this->tSelectedAttribute);
			this->tpAttributeFill->Controls->Add(this->bSaveOperation);
			this->tpAttributeFill->Controls->Add(this->tDefaultOperation);
			this->tpAttributeFill->Controls->Add(this->lDefaultOperation);
			this->tpAttributeFill->Controls->Add(this->rbTrueOperation);
			this->tpAttributeFill->Controls->Add(this->rbFalseOperation);
			this->tpAttributeFill->Controls->Add(this->lAreaOperation);
			this->tpAttributeFill->Controls->Add(this->tOperationOut);
			this->tpAttributeFill->Controls->Add(this->lOperationOut);
			this->tpAttributeFill->Controls->Add(this->tSelectOperation);
			this->tpAttributeFill->Controls->Add(this->lSelectOperation);
			this->tpAttributeFill->Controls->Add(this->cbOperation);
			this->tpAttributeFill->Controls->Add(this->bDeleteAttribute);
			this->tpAttributeFill->Controls->Add(this->bAddAttribute);
			this->tpAttributeFill->Controls->Add(this->lvAttributesToFill);
			this->tpAttributeFill->Location = System::Drawing::Point(4, 22);
			this->tpAttributeFill->Name = L"tpAttributeFill";
			this->tpAttributeFill->Size = System::Drawing::Size(713, 428);
			this->tpAttributeFill->TabIndex = 2;
			this->tpAttributeFill->Text = L"Dados para Preenchimento";
			this->tpAttributeFill->UseVisualStyleBackColor = true;
			// 
			// pPixelReference
			// 
			this->pPixelReference->Controls->Add(this->rbOverlap);
			this->pPixelReference->Controls->Add(this->rbCentroid);
			this->pPixelReference->Location = System::Drawing::Point(498, 320);
			this->pPixelReference->Name = L"pPixelReference";
			this->pPixelReference->Size = System::Drawing::Size(131, 25);
			this->pPixelReference->TabIndex = 117;
			this->pPixelReference->Visible = false;
			// 
			// rbOverlap
			// 
			this->rbOverlap->AutoSize = true;
			this->rbOverlap->Location = System::Drawing::Point(69, 8);
			this->rbOverlap->Name = L"rbOverlap";
			this->rbOverlap->Size = System::Drawing::Size(62, 17);
			this->rbOverlap->TabIndex = 1;
			this->rbOverlap->Text = L"Overlap";
			this->rbOverlap->UseVisualStyleBackColor = true;
			// 
			// rbCentroid
			// 
			this->rbCentroid->AutoSize = true;
			this->rbCentroid->Checked = true;
			this->rbCentroid->Location = System::Drawing::Point(3, 8);
			this->rbCentroid->Name = L"rbCentroid";
			this->rbCentroid->Size = System::Drawing::Size(64, 17);
			this->rbCentroid->TabIndex = 0;
			this->rbCentroid->TabStop = true;
			this->rbCentroid->Text = L"Centroid";
			this->rbCentroid->UseVisualStyleBackColor = true;
			// 
			// lPixelReference
			// 
			this->lPixelReference->AutoSize = true;
			this->lPixelReference->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPixelReference->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lPixelReference->Location = System::Drawing::Point(378, 323);
			this->lPixelReference->Name = L"lPixelReference";
			this->lPixelReference->Size = System::Drawing::Size(96, 23);
			this->lPixelReference->TabIndex = 116;
			this->lPixelReference->Text = L"Referência";
			this->lPixelReference->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPixelReference->Visible = false;
			// 
			// tDummyOperation
			// 
			this->tDummyOperation->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tDummyOperation->Location = System::Drawing::Point(483, 290);
			this->tDummyOperation->Name = L"tDummyOperation";
			this->tDummyOperation->Size = System::Drawing::Size(151, 20);
			this->tDummyOperation->TabIndex = 114;
			this->tDummyOperation->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tDummyOperation->Visible = false;
			this->tDummyOperation->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lDummyOperation
			// 
			this->lDummyOperation->AutoSize = true;
			this->lDummyOperation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDummyOperation->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lDummyOperation->Location = System::Drawing::Point(360, 287);
			this->lDummyOperation->Name = L"lDummyOperation";
			this->lDummyOperation->Size = System::Drawing::Size(116, 23);
			this->lDummyOperation->TabIndex = 113;
			this->lDummyOperation->Text = L"Valor Dummy";
			this->lDummyOperation->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lDummyOperation->Visible = false;
			// 
			// gbGeometricRepresentation
			// 
			this->gbGeometricRepresentation->Controls->Add(this->rbPolygon);
			this->gbGeometricRepresentation->Controls->Add(this->rbLine);
			this->gbGeometricRepresentation->Controls->Add(this->rbDot);
			this->gbGeometricRepresentation->Location = System::Drawing::Point(324, 57);
			this->gbGeometricRepresentation->Name = L"gbGeometricRepresentation";
			this->gbGeometricRepresentation->Size = System::Drawing::Size(349, 37);
			this->gbGeometricRepresentation->TabIndex = 112;
			this->gbGeometricRepresentation->TabStop = false;
			this->gbGeometricRepresentation->Visible = false;
			// 
			// rbPolygon
			// 
			this->rbPolygon->AutoSize = true;
			this->rbPolygon->Location = System::Drawing::Point(27, 13);
			this->rbPolygon->Name = L"rbPolygon";
			this->rbPolygon->Size = System::Drawing::Size(68, 17);
			this->rbPolygon->TabIndex = 111;
			this->rbPolygon->TabStop = true;
			this->rbPolygon->Text = L"Polígono";
			this->rbPolygon->UseVisualStyleBackColor = true;
			this->rbPolygon->CheckedChanged += gcnew System::EventHandler(this, &NovoModelo::rbPolygon_CheckedChanged);
			// 
			// rbLine
			// 
			this->rbLine->AutoSize = true;
			this->rbLine->Location = System::Drawing::Point(153, 13);
			this->rbLine->Name = L"rbLine";
			this->rbLine->Size = System::Drawing::Size(51, 17);
			this->rbLine->TabIndex = 109;
			this->rbLine->TabStop = true;
			this->rbLine->Text = L"Linha";
			this->rbLine->UseVisualStyleBackColor = true;
			this->rbLine->CheckedChanged += gcnew System::EventHandler(this, &NovoModelo::rbLine_CheckedChanged);
			// 
			// rbDot
			// 
			this->rbDot->AutoSize = true;
			this->rbDot->Location = System::Drawing::Point(265, 13);
			this->rbDot->Name = L"rbDot";
			this->rbDot->Size = System::Drawing::Size(53, 17);
			this->rbDot->TabIndex = 110;
			this->rbDot->TabStop = true;
			this->rbDot->Text = L"Ponto";
			this->rbDot->UseVisualStyleBackColor = true;
			this->rbDot->CheckedChanged += gcnew System::EventHandler(this, &NovoModelo::rbDot_CheckedChanged);
			// 
			// lGeometricRepresentation
			// 
			this->lGeometricRepresentation->AutoSize = true;
			this->lGeometricRepresentation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lGeometricRepresentation->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lGeometricRepresentation->Location = System::Drawing::Point(374, 37);
			this->lGeometricRepresentation->Name = L"lGeometricRepresentation";
			this->lGeometricRepresentation->Size = System::Drawing::Size(226, 23);
			this->lGeometricRepresentation->TabIndex = 108;
			this->lGeometricRepresentation->Text = L"Representação Geométrica";
			this->lGeometricRepresentation->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lGeometricRepresentation->Visible = false;
			// 
			// lOperationName
			// 
			this->lOperationName->AutoSize = true;
			this->lOperationName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lOperationName->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lOperationName->Location = System::Drawing::Point(388, 105);
			this->lOperationName->Name = L"lOperationName";
			this->lOperationName->Size = System::Drawing::Size(205, 23);
			this->lOperationName->TabIndex = 107;
			this->lOperationName->Text = L"Selecione uma Operação";
			this->lOperationName->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lOperationName->Visible = false;
			// 
			// tSelectedAttribute
			// 
			this->tSelectedAttribute->Enabled = false;
			this->tSelectedAttribute->Location = System::Drawing::Point(14, 30);
			this->tSelectedAttribute->Name = L"tSelectedAttribute";
			this->tSelectedAttribute->Size = System::Drawing::Size(267, 20);
			this->tSelectedAttribute->TabIndex = 106;
			this->tSelectedAttribute->Visible = false;
			// 
			// bSaveOperation
			// 
			this->bSaveOperation->Location = System::Drawing::Point(456, 353);
			this->bSaveOperation->Name = L"bSaveOperation";
			this->bSaveOperation->Size = System::Drawing::Size(75, 23);
			this->bSaveOperation->TabIndex = 13;
			this->bSaveOperation->Text = L"Salvar";
			this->bSaveOperation->UseVisualStyleBackColor = true;
			this->bSaveOperation->Visible = false;
			this->bSaveOperation->Click += gcnew System::EventHandler(this, &NovoModelo::bSaveOperation_Click);
			// 
			// tDefaultOperation
			// 
			this->tDefaultOperation->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tDefaultOperation->Location = System::Drawing::Point(482, 253);
			this->tDefaultOperation->Name = L"tDefaultOperation";
			this->tDefaultOperation->Size = System::Drawing::Size(151, 20);
			this->tDefaultOperation->TabIndex = 11;
			this->tDefaultOperation->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tDefaultOperation->Visible = false;
			this->tDefaultOperation->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lDefaultOperation
			// 
			this->lDefaultOperation->AutoSize = true;
			this->lDefaultOperation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDefaultOperation->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lDefaultOperation->Location = System::Drawing::Point(360, 251);
			this->lDefaultOperation->Name = L"lDefaultOperation";
			this->lDefaultOperation->Size = System::Drawing::Size(114, 23);
			this->lDefaultOperation->TabIndex = 103;
			this->lDefaultOperation->Text = L"Valor Default";
			this->lDefaultOperation->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lDefaultOperation->Visible = false;
			// 
			// rbTrueOperation
			// 
			this->rbTrueOperation->AutoSize = true;
			this->rbTrueOperation->Location = System::Drawing::Point(534, 303);
			this->rbTrueOperation->Name = L"rbTrueOperation";
			this->rbTrueOperation->Size = System::Drawing::Size(47, 17);
			this->rbTrueOperation->TabIndex = 102;
			this->rbTrueOperation->Text = L"True";
			this->rbTrueOperation->UseVisualStyleBackColor = true;
			this->rbTrueOperation->Visible = false;
			// 
			// rbFalseOperation
			// 
			this->rbFalseOperation->AutoSize = true;
			this->rbFalseOperation->Checked = true;
			this->rbFalseOperation->Location = System::Drawing::Point(583, 303);
			this->rbFalseOperation->Name = L"rbFalseOperation";
			this->rbFalseOperation->Size = System::Drawing::Size(50, 17);
			this->rbFalseOperation->TabIndex = 12;
			this->rbFalseOperation->TabStop = true;
			this->rbFalseOperation->Text = L"False";
			this->rbFalseOperation->UseVisualStyleBackColor = true;
			this->rbFalseOperation->Visible = false;
			// 
			// lAreaOperation
			// 
			this->lAreaOperation->AutoSize = true;
			this->lAreaOperation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAreaOperation->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lAreaOperation->Location = System::Drawing::Point(320, 300);
			this->lAreaOperation->Name = L"lAreaOperation";
			this->lAreaOperation->Size = System::Drawing::Size(200, 23);
			this->lAreaOperation->TabIndex = 100;
			this->lAreaOperation->Text = L"Usar Geometria da Área";
			this->lAreaOperation->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lAreaOperation->Visible = false;
			// 
			// tOperationOut
			// 
			this->tOperationOut->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tOperationOut->Location = System::Drawing::Point(482, 178);
			this->tOperationOut->MaxLength = 10;
			this->tOperationOut->Name = L"tOperationOut";
			this->tOperationOut->Size = System::Drawing::Size(151, 20);
			this->tOperationOut->TabIndex = 9;
			this->tOperationOut->Text = L"use";
			this->tOperationOut->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tOperationOut->Visible = false;
			this->tOperationOut->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lOperationOut
			// 
			this->lOperationOut->AutoSize = true;
			this->lOperationOut->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lOperationOut->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lOperationOut->Location = System::Drawing::Point(328, 176);
			this->lOperationOut->Name = L"lOperationOut";
			this->lOperationOut->Size = System::Drawing::Size(147, 23);
			this->lOperationOut->TabIndex = 98;
			this->lOperationOut->Text = L"Atributo de Saída";
			this->lOperationOut->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lOperationOut->Visible = false;
			// 
			// tSelectOperation
			// 
			this->tSelectOperation->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tSelectOperation->Location = System::Drawing::Point(482, 215);
			this->tSelectOperation->Name = L"tSelectOperation";
			this->tSelectOperation->Size = System::Drawing::Size(151, 20);
			this->tSelectOperation->TabIndex = 10;
			this->tSelectOperation->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tSelectOperation->Visible = false;
			this->tSelectOperation->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lSelectOperation
			// 
			this->lSelectOperation->AutoSize = true;
			this->lSelectOperation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSelectOperation->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lSelectOperation->Location = System::Drawing::Point(309, 213);
			this->lSelectOperation->Name = L"lSelectOperation";
			this->lSelectOperation->Size = System::Drawing::Size(166, 23);
			this->lSelectOperation->TabIndex = 98;
			this->lSelectOperation->Text = L"Atributo de Entrada";
			this->lSelectOperation->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lSelectOperation->Visible = false;
			// 
			// cbOperation
			// 
			this->cbOperation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbOperation->Location = System::Drawing::Point(362, 131);
			this->cbOperation->Name = L"cbOperation";
			this->cbOperation->Size = System::Drawing::Size(246, 21);
			this->cbOperation->TabIndex = 8;
			this->cbOperation->Visible = false;
			this->cbOperation->SelectedIndexChanged += gcnew System::EventHandler(this, &NovoModelo::cbOperation_SelectedIndexChanged);
			// 
			// bDeleteAttribute
			// 
			this->bDeleteAttribute->Location = System::Drawing::Point(90, 395);
			this->bDeleteAttribute->Name = L"bDeleteAttribute";
			this->bDeleteAttribute->Size = System::Drawing::Size(66, 23);
			this->bDeleteAttribute->TabIndex = 2;
			this->bDeleteAttribute->Text = L"Remover";
			this->bDeleteAttribute->UseVisualStyleBackColor = true;
			this->bDeleteAttribute->Visible = false;
			this->bDeleteAttribute->Click += gcnew System::EventHandler(this, &NovoModelo::bDeleteAttribute_Click);
			// 
			// bAddAttribute
			// 
			this->bAddAttribute->Location = System::Drawing::Point(14, 395);
			this->bAddAttribute->Name = L"bAddAttribute";
			this->bAddAttribute->Size = System::Drawing::Size(32, 23);
			this->bAddAttribute->TabIndex = 7;
			this->bAddAttribute->Text = L"+";
			this->bAddAttribute->UseVisualStyleBackColor = true;
			this->bAddAttribute->Click += gcnew System::EventHandler(this, &NovoModelo::bAddAttribute_Click);
			// 
			// lvAttributesToFill
			// 
			this->lvAttributesToFill->AllowDrop = true;
			this->lvAttributesToFill->Location = System::Drawing::Point(14, 30);
			this->lvAttributesToFill->MultiSelect = false;
			this->lvAttributesToFill->Name = L"lvAttributesToFill";
			this->lvAttributesToFill->Size = System::Drawing::Size(267, 359);
			this->lvAttributesToFill->TabIndex = 6;
			this->lvAttributesToFill->UseCompatibleStateImageBehavior = false;
			this->lvAttributesToFill->SelectedIndexChanged += gcnew System::EventHandler(this, &NovoModelo::lvAttributesToFill_SelectedIndexChanged);
			this->lvAttributesToFill->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &NovoModelo::lvAttributesToFill_DragEnter);
			// 
			// tpMakeFiles
			// 
			this->tpMakeFiles->Controls->Add(this->bRun);
			this->tpMakeFiles->Controls->Add(this->lRunScript);
			this->tpMakeFiles->Controls->Add(this->bFileMaker);
			this->tpMakeFiles->Controls->Add(this->lFileMaker);
			this->tpMakeFiles->Location = System::Drawing::Point(4, 22);
			this->tpMakeFiles->Name = L"tpMakeFiles";
			this->tpMakeFiles->Size = System::Drawing::Size(713, 428);
			this->tpMakeFiles->TabIndex = 3;
			this->tpMakeFiles->Text = L"Gerar Arquivos";
			this->tpMakeFiles->UseVisualStyleBackColor = true;
			// 
			// bRun
			// 
			this->bRun->Location = System::Drawing::Point(264, 306);
			this->bRun->Name = L"bRun";
			this->bRun->Size = System::Drawing::Size(185, 47);
			this->bRun->TabIndex = 95;
			this->bRun->Text = L"Rodar Script";
			this->bRun->UseVisualStyleBackColor = true;
			this->bRun->Visible = false;
			this->bRun->Click += gcnew System::EventHandler(this, &NovoModelo::bRun_Click);
			// 
			// lRunScript
			// 
			this->lRunScript->AutoSize = true;
			this->lRunScript->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRunScript->Location = System::Drawing::Point(290, 259);
			this->lRunScript->Name = L"lRunScript";
			this->lRunScript->Size = System::Drawing::Size(133, 26);
			this->lRunScript->TabIndex = 94;
			this->lRunScript->Text = L"Rodar o Script";
			this->lRunScript->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lRunScript->Visible = false;
			// 
			// bFileMaker
			// 
			this->bFileMaker->Location = System::Drawing::Point(264, 124);
			this->bFileMaker->Name = L"bFileMaker";
			this->bFileMaker->Size = System::Drawing::Size(185, 47);
			this->bFileMaker->TabIndex = 93;
			this->bFileMaker->Text = L"Gerar Arquivos";
			this->bFileMaker->UseVisualStyleBackColor = true;
			this->bFileMaker->Click += gcnew System::EventHandler(this, &NovoModelo::bFileMaker_Click);
			// 
			// lFileMaker
			// 
			this->lFileMaker->AutoSize = true;
			this->lFileMaker->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lFileMaker->Location = System::Drawing::Point(289, 75);
			this->lFileMaker->Name = L"lFileMaker";
			this->lFileMaker->Size = System::Drawing::Size(149, 26);
			this->lFileMaker->TabIndex = 92;
			this->lFileMaker->Text = L"Gerar o Arquivo";
			this->lFileMaker->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pbLogo2
			// 
			this->pbLogo2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo2.Image")));
			this->pbLogo2->Location = System::Drawing::Point(144, 37);
			this->pbLogo2->Name = L"pbLogo2";
			this->pbLogo2->Size = System::Drawing::Size(136, 134);
			this->pbLogo2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo2->TabIndex = 21;
			this->pbLogo2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(282, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 26);
			this->label1->TabIndex = 22;
			this->label1->Text = L"&&";
			// 
			// NovoModelo
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(745, 677);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pbLogo2);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"NovoModelo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Criando um Novo Modelo";
			this->Load += gcnew System::EventHandler(this, &NovoModelo::NovoModelo_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tpScript->ResumeLayout(false);
			this->tpScript->PerformLayout();
			this->tpCellularSpace->ResumeLayout(false);
			this->tpCellularSpace->PerformLayout();
			this->tpAttributeFill->ResumeLayout(false);
			this->tpAttributeFill->PerformLayout();
			this->pPixelReference->ResumeLayout(false);
			this->pPixelReference->PerformLayout();
			this->gbGeometricRepresentation->ResumeLayout(false);
			this->gbGeometricRepresentation->PerformLayout();
			this->tpMakeFiles->ResumeLayout(false);
			this->tpMakeFiles->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkLanguage();
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CellFulfillToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void abrirToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void novoToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void sobreToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void sairToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void idiomaToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void bSelectFolder_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NovoModelo_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bShape_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tabControl1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lvAttributesToFill_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void lvAttributesToFill_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbOperation_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bAddAttribute_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Int32 polygonOperationToindex(String^ operation);
	private: System::Int32 nonPolygonOperationToindex(String^ operation);
	private: System::Int32 rasterOperationToindex(String^ operation);
	private: System::Void bSaveOperation_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Int32 attributeToindex();
	private: System::String^ polygonOperationToName(int operation);
	private: System::String^ nonPolygonOperationToName(int operation);
	private: System::String^ rasterOperationToName(int operation);
	private: System::Void operationVisualOFF();
	private: System::Void bDeleteAttribute_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bFileMaker_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bRun_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbUseCS_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tCellSpaceResolution_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void rbPolygon_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void rbLine_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void rbDot_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
};
}

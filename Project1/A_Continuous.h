#pragma once
#include "Function.h"

namespace LuccME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for A_Continuous
	/// </summary>
	public ref class A_Continuous : public System::Windows::Forms::Form
	{
	public:
		bool intialize = true;
	private: System::Windows::Forms::Label^  lMaxDiffHelp;
	private: System::Windows::Forms::TabControl^  tcRegions;
	private: System::Windows::Forms::TabPage^  tRegion1;
	private: System::Windows::Forms::DataGridView^  dgAllocationData;
	private: System::Windows::Forms::TabPage^  tRegion2;
	private: System::Windows::Forms::TabPage^  tRegion3;
	private: System::Windows::Forms::TabPage^  tRegion4;
	private: System::Windows::Forms::TabPage^  tRegion5;
	private: System::Windows::Forms::TabPage^  tRegion6;
	private: System::Windows::Forms::TabPage^  tRegion7;
	private: System::Windows::Forms::TabPage^  tRegion8;
	private: System::Windows::Forms::TabPage^  tRegion9;
	private: System::Windows::Forms::TabPage^  tRegion10;
	private: System::Windows::Forms::DataGridView^  dgAllocationData2;
	private: System::Windows::Forms::DataGridView^  dgAllocationData3;
	private: System::Windows::Forms::DataGridView^  dgAllocationData4;
	private: System::Windows::Forms::DataGridView^  dgAllocationData5;
	private: System::Windows::Forms::DataGridView^  dgAllocationData6;
	private: System::Windows::Forms::DataGridView^  dgAllocationData7;
	private: System::Windows::Forms::DataGridView^  dgAllocationData8;
	private: System::Windows::Forms::DataGridView^  dgAllocationData9;
	private: System::Windows::Forms::DataGridView^  dgAllocationData10;
	private: System::Windows::Forms::Button^  bDeleteRegression;
	private: System::Windows::Forms::CheckBox^  cbPotReg;
	public:
		cReturnAllocation^ lReturn;
		A_Continuous(cReturnAllocation^ pAllocation)
		{
			InitializeComponent();
			lReturn = pAllocation;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~A_Continuous()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tComplementarLU;
	protected:
	private: System::Windows::Forms::Label^  lComplementarLU;
	private: System::Windows::Forms::TextBox^  tMaxElasticity;

	private: System::Windows::Forms::Label^  lMaxElasticity;
	private: System::Windows::Forms::TextBox^  tMinElasticity;

	private: System::Windows::Forms::Label^  lMinElasticity;
	private: System::Windows::Forms::Label^  lAllocationData;

	private: System::Windows::Forms::TextBox^  tMaxDifference;
	private: System::Windows::Forms::Label^  lMaxDifference;
	private: System::Windows::Forms::TextBox^  tInitialElasticity;

	private: System::Windows::Forms::Label^  lInitialElasticity;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::TextBox^  tMaxIteration;
	private: System::Windows::Forms::Label^  lMaxIteration;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::TextBox^  tSaturationIndicator;
	private: System::Windows::Forms::Label^  lSaturationIndicator;
	private: System::Windows::Forms::TextBox^  tAttrProtection;
	private: System::Windows::Forms::Label^  lAttrProtection;
	private: System::Windows::Forms::Label^  lLegend;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(A_Continuous::typeid));
			this->tComplementarLU = (gcnew System::Windows::Forms::TextBox());
			this->lComplementarLU = (gcnew System::Windows::Forms::Label());
			this->tMaxElasticity = (gcnew System::Windows::Forms::TextBox());
			this->lMaxElasticity = (gcnew System::Windows::Forms::Label());
			this->tMinElasticity = (gcnew System::Windows::Forms::TextBox());
			this->lMinElasticity = (gcnew System::Windows::Forms::Label());
			this->lAllocationData = (gcnew System::Windows::Forms::Label());
			this->tMaxDifference = (gcnew System::Windows::Forms::TextBox());
			this->lMaxDifference = (gcnew System::Windows::Forms::Label());
			this->tInitialElasticity = (gcnew System::Windows::Forms::TextBox());
			this->lInitialElasticity = (gcnew System::Windows::Forms::Label());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->tMaxIteration = (gcnew System::Windows::Forms::TextBox());
			this->lMaxIteration = (gcnew System::Windows::Forms::Label());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->tSaturationIndicator = (gcnew System::Windows::Forms::TextBox());
			this->lSaturationIndicator = (gcnew System::Windows::Forms::Label());
			this->tAttrProtection = (gcnew System::Windows::Forms::TextBox());
			this->lAttrProtection = (gcnew System::Windows::Forms::Label());
			this->lLegend = (gcnew System::Windows::Forms::Label());
			this->lMaxDiffHelp = (gcnew System::Windows::Forms::Label());
			this->tcRegions = (gcnew System::Windows::Forms::TabControl());
			this->tRegion1 = (gcnew System::Windows::Forms::TabPage());
			this->dgAllocationData = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion2 = (gcnew System::Windows::Forms::TabPage());
			this->dgAllocationData2 = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion3 = (gcnew System::Windows::Forms::TabPage());
			this->dgAllocationData3 = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion4 = (gcnew System::Windows::Forms::TabPage());
			this->dgAllocationData4 = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion5 = (gcnew System::Windows::Forms::TabPage());
			this->dgAllocationData5 = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion6 = (gcnew System::Windows::Forms::TabPage());
			this->dgAllocationData6 = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion7 = (gcnew System::Windows::Forms::TabPage());
			this->dgAllocationData7 = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion8 = (gcnew System::Windows::Forms::TabPage());
			this->dgAllocationData8 = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion9 = (gcnew System::Windows::Forms::TabPage());
			this->dgAllocationData9 = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion10 = (gcnew System::Windows::Forms::TabPage());
			this->dgAllocationData10 = (gcnew System::Windows::Forms::DataGridView());
			this->bDeleteRegression = (gcnew System::Windows::Forms::Button());
			this->cbPotReg = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->tcRegions->SuspendLayout();
			this->tRegion1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData))->BeginInit();
			this->tRegion2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData2))->BeginInit();
			this->tRegion3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData3))->BeginInit();
			this->tRegion4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData4))->BeginInit();
			this->tRegion5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData5))->BeginInit();
			this->tRegion6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData6))->BeginInit();
			this->tRegion7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData7))->BeginInit();
			this->tRegion8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData8))->BeginInit();
			this->tRegion9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData9))->BeginInit();
			this->tRegion10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData10))->BeginInit();
			this->SuspendLayout();
			// 
			// tComplementarLU
			// 
			this->tComplementarLU->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tComplementarLU->Location = System::Drawing::Point(200, 248);
			this->tComplementarLU->Name = L"tComplementarLU";
			this->tComplementarLU->Size = System::Drawing::Size(183, 20);
			this->tComplementarLU->TabIndex = 7;
			this->tComplementarLU->Text = L"Floresta";
			this->tComplementarLU->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tComplementarLU->Enter += gcnew System::EventHandler(this, &A_Continuous::textBox_Enter);
			// 
			// lComplementarLU
			// 
			this->lComplementarLU->AutoSize = true;
			this->lComplementarLU->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lComplementarLU->Location = System::Drawing::Point(54, 247);
			this->lComplementarLU->Name = L"lComplementarLU";
			this->lComplementarLU->Size = System::Drawing::Size(146, 23);
			this->lComplementarLU->TabIndex = 126;
			this->lComplementarLU->Text = L"complementarLU";
			this->lComplementarLU->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tMaxElasticity
			// 
			this->tMaxElasticity->Enabled = false;
			this->tMaxElasticity->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxElasticity->Location = System::Drawing::Point(659, 250);
			this->tMaxElasticity->Name = L"tMaxElasticity";
			this->tMaxElasticity->Size = System::Drawing::Size(194, 20);
			this->tMaxElasticity->TabIndex = 6;
			this->tMaxElasticity->Text = L"1.5";
			this->tMaxElasticity->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxElasticity->Enter += gcnew System::EventHandler(this, &A_Continuous::textBox_Enter);
			// 
			// lMaxElasticity
			// 
			this->lMaxElasticity->AutoSize = true;
			this->lMaxElasticity->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxElasticity->Location = System::Drawing::Point(535, 248);
			this->lMaxElasticity->Name = L"lMaxElasticity";
			this->lMaxElasticity->Size = System::Drawing::Size(114, 23);
			this->lMaxElasticity->TabIndex = 124;
			this->lMaxElasticity->Text = L"maxElasticity";
			this->lMaxElasticity->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tMinElasticity
			// 
			this->tMinElasticity->Enabled = false;
			this->tMinElasticity->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinElasticity->Location = System::Drawing::Point(658, 220);
			this->tMinElasticity->Name = L"tMinElasticity";
			this->tMinElasticity->Size = System::Drawing::Size(194, 20);
			this->tMinElasticity->TabIndex = 5;
			this->tMinElasticity->Text = L"0.001";
			this->tMinElasticity->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinElasticity->Enter += gcnew System::EventHandler(this, &A_Continuous::textBox_Enter);
			// 
			// lMinElasticity
			// 
			this->lMinElasticity->AutoSize = true;
			this->lMinElasticity->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinElasticity->Location = System::Drawing::Point(538, 218);
			this->lMinElasticity->Name = L"lMinElasticity";
			this->lMinElasticity->Size = System::Drawing::Size(111, 23);
			this->lMinElasticity->TabIndex = 122;
			this->lMinElasticity->Text = L"minElasticity";
			this->lMinElasticity->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lAllocationData
			// 
			this->lAllocationData->AutoSize = true;
			this->lAllocationData->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAllocationData->Location = System::Drawing::Point(395, 338);
			this->lAllocationData->Name = L"lAllocationData";
			this->lAllocationData->Size = System::Drawing::Size(131, 23);
			this->lAllocationData->TabIndex = 120;
			this->lAllocationData->Text = L"Allocation Data";
			this->lAllocationData->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tMaxDifference
			// 
			this->tMaxDifference->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxDifference->Location = System::Drawing::Point(189, 187);
			this->tMaxDifference->Name = L"tMaxDifference";
			this->tMaxDifference->Size = System::Drawing::Size(194, 20);
			this->tMaxDifference->TabIndex = 2;
			this->tMaxDifference->Text = L"150";
			this->tMaxDifference->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxDifference->Enter += gcnew System::EventHandler(this, &A_Continuous::textBox_Enter);
			// 
			// lMaxDifference
			// 
			this->lMaxDifference->AutoSize = true;
			this->lMaxDifference->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxDifference->Location = System::Drawing::Point(54, 186);
			this->lMaxDifference->Name = L"lMaxDifference";
			this->lMaxDifference->Size = System::Drawing::Size(126, 23);
			this->lMaxDifference->TabIndex = 118;
			this->lMaxDifference->Text = L"maxDifference";
			this->lMaxDifference->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tInitialElasticity
			// 
			this->tInitialElasticity->Enabled = false;
			this->tInitialElasticity->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tInitialElasticity->Location = System::Drawing::Point(658, 190);
			this->tInitialElasticity->Name = L"tInitialElasticity";
			this->tInitialElasticity->Size = System::Drawing::Size(194, 20);
			this->tInitialElasticity->TabIndex = 4;
			this->tInitialElasticity->Text = L"0.1";
			this->tInitialElasticity->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tInitialElasticity->Enter += gcnew System::EventHandler(this, &A_Continuous::textBox_Enter);
			// 
			// lInitialElasticity
			// 
			this->lInitialElasticity->AutoSize = true;
			this->lInitialElasticity->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lInitialElasticity->Location = System::Drawing::Point(523, 188);
			this->lInitialElasticity->Name = L"lInitialElasticity";
			this->lInitialElasticity->Size = System::Drawing::Size(126, 23);
			this->lInitialElasticity->TabIndex = 116;
			this->lInitialElasticity->Text = L"initialElasticity";
			this->lInitialElasticity->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(424, 561);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 1;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &A_Continuous::bSalvar_Click);
			// 
			// tMaxIteration
			// 
			this->tMaxIteration->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxIteration->Location = System::Drawing::Point(189, 217);
			this->tMaxIteration->Name = L"tMaxIteration";
			this->tMaxIteration->Size = System::Drawing::Size(194, 20);
			this->tMaxIteration->TabIndex = 3;
			this->tMaxIteration->Text = L"1000";
			this->tMaxIteration->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxIteration->Enter += gcnew System::EventHandler(this, &A_Continuous::textBox_Enter);
			// 
			// lMaxIteration
			// 
			this->lMaxIteration->AutoSize = true;
			this->lMaxIteration->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxIteration->Location = System::Drawing::Point(54, 216);
			this->lMaxIteration->Name = L"lMaxIteration";
			this->lMaxIteration->Size = System::Drawing::Size(112, 23);
			this->lMaxIteration->TabIndex = 114;
			this->lMaxIteration->Text = L"maxIteration";
			this->lMaxIteration->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(260, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 111;
			this->pbLogo1->TabStop = false;
			// 
			// tSaturationIndicator
			// 
			this->tSaturationIndicator->Enabled = false;
			this->tSaturationIndicator->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tSaturationIndicator->Location = System::Drawing::Point(659, 280);
			this->tSaturationIndicator->Name = L"tSaturationIndicator";
			this->tSaturationIndicator->Size = System::Drawing::Size(194, 20);
			this->tSaturationIndicator->TabIndex = 8;
			this->tSaturationIndicator->Text = L"saturationLimiar";
			this->tSaturationIndicator->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tSaturationIndicator->Visible = false;
			this->tSaturationIndicator->Enter += gcnew System::EventHandler(this, &A_Continuous::textBox_Enter);
			// 
			// lSaturationIndicator
			// 
			this->lSaturationIndicator->AutoSize = true;
			this->lSaturationIndicator->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSaturationIndicator->Location = System::Drawing::Point(487, 280);
			this->lSaturationIndicator->Name = L"lSaturationIndicator";
			this->lSaturationIndicator->Size = System::Drawing::Size(162, 23);
			this->lSaturationIndicator->TabIndex = 128;
			this->lSaturationIndicator->Text = L"saturationIndicator";
			this->lSaturationIndicator->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lSaturationIndicator->Visible = false;
			// 
			// tAttrProtection
			// 
			this->tAttrProtection->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAttrProtection->Location = System::Drawing::Point(200, 279);
			this->tAttrProtection->Name = L"tAttrProtection";
			this->tAttrProtection->Size = System::Drawing::Size(183, 20);
			this->tAttrProtection->TabIndex = 9;
			this->tAttrProtection->Text = L"prot";
			this->tAttrProtection->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAttrProtection->Visible = false;
			this->tAttrProtection->Enter += gcnew System::EventHandler(this, &A_Continuous::textBox_Enter);
			// 
			// lAttrProtection
			// 
			this->lAttrProtection->AutoSize = true;
			this->lAttrProtection->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAttrProtection->Location = System::Drawing::Point(54, 278);
			this->lAttrProtection->Name = L"lAttrProtection";
			this->lAttrProtection->Size = System::Drawing::Size(121, 23);
			this->lAttrProtection->TabIndex = 130;
			this->lAttrProtection->Text = L"attrProtection";
			this->lAttrProtection->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lAttrProtection->Visible = false;
			// 
			// lLegend
			// 
			this->lLegend->AutoSize = true;
			this->lLegend->Location = System::Drawing::Point(21, 566);
			this->lLegend->Name = L"lLegend";
			this->lLegend->Size = System::Drawing::Size(227, 13);
			this->lLegend->TabIndex = 131;
			this->lLegend->Text = L"* -1 - Unidirecional, 0 - Bidirecional, 1 - Estático";
			// 
			// lMaxDiffHelp
			// 
			this->lMaxDiffHelp->AutoSize = true;
			this->lMaxDiffHelp->Font = (gcnew System::Drawing::Font(L"Calibri", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxDiffHelp->Location = System::Drawing::Point(249, 169);
			this->lMaxDiffHelp->Name = L"lMaxDiffHelp";
			this->lMaxDiffHelp->Size = System::Drawing::Size(75, 13);
			this->lMaxDiffHelp->TabIndex = 132;
			this->lMaxDiffHelp->Text = L"Valor Absoluto";
			this->lMaxDiffHelp->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tcRegions
			// 
			this->tcRegions->Controls->Add(this->tRegion1);
			this->tcRegions->Controls->Add(this->tRegion2);
			this->tcRegions->Controls->Add(this->tRegion3);
			this->tcRegions->Controls->Add(this->tRegion4);
			this->tcRegions->Controls->Add(this->tRegion5);
			this->tcRegions->Controls->Add(this->tRegion6);
			this->tcRegions->Controls->Add(this->tRegion7);
			this->tcRegions->Controls->Add(this->tRegion8);
			this->tcRegions->Controls->Add(this->tRegion9);
			this->tcRegions->Controls->Add(this->tRegion10);
			this->tcRegions->Location = System::Drawing::Point(8, 372);
			this->tcRegions->Name = L"tcRegions";
			this->tcRegions->SelectedIndex = 0;
			this->tcRegions->Size = System::Drawing::Size(908, 182);
			this->tcRegions->TabIndex = 133;
			this->tcRegions->SelectedIndexChanged += gcnew System::EventHandler(this, &A_Continuous::tcRegions_SelectedIndexChanged);
			// 
			// tRegion1
			// 
			this->tRegion1->Controls->Add(this->dgAllocationData);
			this->tRegion1->Location = System::Drawing::Point(4, 22);
			this->tRegion1->Name = L"tRegion1";
			this->tRegion1->Padding = System::Windows::Forms::Padding(3);
			this->tRegion1->Size = System::Drawing::Size(900, 156);
			this->tRegion1->TabIndex = 0;
			this->tRegion1->Text = L"Region 1";
			this->tRegion1->UseVisualStyleBackColor = true;
			// 
			// dgAllocationData
			// 
			this->dgAllocationData->AllowUserToAddRows = false;
			this->dgAllocationData->AllowUserToDeleteRows = false;
			this->dgAllocationData->AllowUserToResizeColumns = false;
			this->dgAllocationData->AllowUserToResizeRows = false;
			this->dgAllocationData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAllocationData->Location = System::Drawing::Point(9, 14);
			this->dgAllocationData->Name = L"dgAllocationData";
			this->dgAllocationData->RowHeadersWidth = 71;
			this->dgAllocationData->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAllocationData->Size = System::Drawing::Size(882, 129);
			this->dgAllocationData->TabIndex = 11;
			this->dgAllocationData->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &A_Continuous::dgAllocData_CellEnter);
			this->dgAllocationData->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_Continuous::dgAllocData_KeyDown);
			// 
			// tRegion2
			// 
			this->tRegion2->Controls->Add(this->dgAllocationData2);
			this->tRegion2->Location = System::Drawing::Point(4, 22);
			this->tRegion2->Name = L"tRegion2";
			this->tRegion2->Padding = System::Windows::Forms::Padding(3);
			this->tRegion2->Size = System::Drawing::Size(900, 156);
			this->tRegion2->TabIndex = 1;
			this->tRegion2->Text = L"+";
			this->tRegion2->UseVisualStyleBackColor = true;
			// 
			// dgAllocationData2
			// 
			this->dgAllocationData2->AllowUserToAddRows = false;
			this->dgAllocationData2->AllowUserToDeleteRows = false;
			this->dgAllocationData2->AllowUserToResizeColumns = false;
			this->dgAllocationData2->AllowUserToResizeRows = false;
			this->dgAllocationData2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAllocationData2->Location = System::Drawing::Point(9, 14);
			this->dgAllocationData2->Name = L"dgAllocationData2";
			this->dgAllocationData2->RowHeadersWidth = 71;
			this->dgAllocationData2->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAllocationData2->Size = System::Drawing::Size(882, 129);
			this->dgAllocationData2->TabIndex = 12;
			this->dgAllocationData2->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &A_Continuous::dgAllocData_CellEnter);
			this->dgAllocationData2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_Continuous::dgAllocData_KeyDown);
			// 
			// tRegion3
			// 
			this->tRegion3->Controls->Add(this->dgAllocationData3);
			this->tRegion3->Location = System::Drawing::Point(4, 22);
			this->tRegion3->Name = L"tRegion3";
			this->tRegion3->Size = System::Drawing::Size(900, 156);
			this->tRegion3->TabIndex = 2;
			this->tRegion3->Text = L"+";
			this->tRegion3->UseVisualStyleBackColor = true;
			// 
			// dgAllocationData3
			// 
			this->dgAllocationData3->AllowUserToAddRows = false;
			this->dgAllocationData3->AllowUserToDeleteRows = false;
			this->dgAllocationData3->AllowUserToResizeColumns = false;
			this->dgAllocationData3->AllowUserToResizeRows = false;
			this->dgAllocationData3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAllocationData3->Location = System::Drawing::Point(9, 14);
			this->dgAllocationData3->Name = L"dgAllocationData3";
			this->dgAllocationData3->RowHeadersWidth = 71;
			this->dgAllocationData3->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAllocationData3->Size = System::Drawing::Size(882, 129);
			this->dgAllocationData3->TabIndex = 12;
			this->dgAllocationData3->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &A_Continuous::dgAllocData_CellEnter);
			this->dgAllocationData3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_Continuous::dgAllocData_KeyDown);
			// 
			// tRegion4
			// 
			this->tRegion4->Controls->Add(this->dgAllocationData4);
			this->tRegion4->Location = System::Drawing::Point(4, 22);
			this->tRegion4->Name = L"tRegion4";
			this->tRegion4->Size = System::Drawing::Size(900, 156);
			this->tRegion4->TabIndex = 3;
			this->tRegion4->Text = L"+";
			this->tRegion4->UseVisualStyleBackColor = true;
			// 
			// dgAllocationData4
			// 
			this->dgAllocationData4->AllowUserToAddRows = false;
			this->dgAllocationData4->AllowUserToDeleteRows = false;
			this->dgAllocationData4->AllowUserToResizeColumns = false;
			this->dgAllocationData4->AllowUserToResizeRows = false;
			this->dgAllocationData4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAllocationData4->Location = System::Drawing::Point(9, 14);
			this->dgAllocationData4->Name = L"dgAllocationData4";
			this->dgAllocationData4->RowHeadersWidth = 71;
			this->dgAllocationData4->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAllocationData4->Size = System::Drawing::Size(882, 129);
			this->dgAllocationData4->TabIndex = 12;
			this->dgAllocationData4->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &A_Continuous::dgAllocData_CellEnter);
			this->dgAllocationData4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_Continuous::dgAllocData_KeyDown);
			// 
			// tRegion5
			// 
			this->tRegion5->Controls->Add(this->dgAllocationData5);
			this->tRegion5->Location = System::Drawing::Point(4, 22);
			this->tRegion5->Name = L"tRegion5";
			this->tRegion5->Size = System::Drawing::Size(900, 156);
			this->tRegion5->TabIndex = 4;
			this->tRegion5->Text = L"+";
			this->tRegion5->UseVisualStyleBackColor = true;
			// 
			// dgAllocationData5
			// 
			this->dgAllocationData5->AllowUserToAddRows = false;
			this->dgAllocationData5->AllowUserToDeleteRows = false;
			this->dgAllocationData5->AllowUserToResizeColumns = false;
			this->dgAllocationData5->AllowUserToResizeRows = false;
			this->dgAllocationData5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAllocationData5->Location = System::Drawing::Point(9, 14);
			this->dgAllocationData5->Name = L"dgAllocationData5";
			this->dgAllocationData5->RowHeadersWidth = 71;
			this->dgAllocationData5->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAllocationData5->Size = System::Drawing::Size(882, 129);
			this->dgAllocationData5->TabIndex = 12;
			this->dgAllocationData5->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &A_Continuous::dgAllocData_CellEnter);
			this->dgAllocationData5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_Continuous::dgAllocData_KeyDown);
			// 
			// tRegion6
			// 
			this->tRegion6->Controls->Add(this->dgAllocationData6);
			this->tRegion6->Location = System::Drawing::Point(4, 22);
			this->tRegion6->Name = L"tRegion6";
			this->tRegion6->Size = System::Drawing::Size(900, 156);
			this->tRegion6->TabIndex = 5;
			this->tRegion6->Text = L"+";
			this->tRegion6->UseVisualStyleBackColor = true;
			// 
			// dgAllocationData6
			// 
			this->dgAllocationData6->AllowUserToAddRows = false;
			this->dgAllocationData6->AllowUserToDeleteRows = false;
			this->dgAllocationData6->AllowUserToResizeColumns = false;
			this->dgAllocationData6->AllowUserToResizeRows = false;
			this->dgAllocationData6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAllocationData6->Location = System::Drawing::Point(9, 14);
			this->dgAllocationData6->Name = L"dgAllocationData6";
			this->dgAllocationData6->RowHeadersWidth = 71;
			this->dgAllocationData6->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAllocationData6->Size = System::Drawing::Size(882, 129);
			this->dgAllocationData6->TabIndex = 12;
			this->dgAllocationData6->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &A_Continuous::dgAllocData_CellEnter);
			this->dgAllocationData6->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_Continuous::dgAllocData_KeyDown);
			// 
			// tRegion7
			// 
			this->tRegion7->Controls->Add(this->dgAllocationData7);
			this->tRegion7->Location = System::Drawing::Point(4, 22);
			this->tRegion7->Name = L"tRegion7";
			this->tRegion7->Size = System::Drawing::Size(900, 156);
			this->tRegion7->TabIndex = 6;
			this->tRegion7->Text = L"+";
			this->tRegion7->UseVisualStyleBackColor = true;
			// 
			// dgAllocationData7
			// 
			this->dgAllocationData7->AllowUserToAddRows = false;
			this->dgAllocationData7->AllowUserToDeleteRows = false;
			this->dgAllocationData7->AllowUserToResizeColumns = false;
			this->dgAllocationData7->AllowUserToResizeRows = false;
			this->dgAllocationData7->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAllocationData7->Location = System::Drawing::Point(9, 14);
			this->dgAllocationData7->Name = L"dgAllocationData7";
			this->dgAllocationData7->RowHeadersWidth = 71;
			this->dgAllocationData7->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAllocationData7->Size = System::Drawing::Size(882, 129);
			this->dgAllocationData7->TabIndex = 12;
			this->dgAllocationData7->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &A_Continuous::dgAllocData_CellEnter);
			this->dgAllocationData7->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_Continuous::dgAllocData_KeyDown);
			// 
			// tRegion8
			// 
			this->tRegion8->Controls->Add(this->dgAllocationData8);
			this->tRegion8->Location = System::Drawing::Point(4, 22);
			this->tRegion8->Name = L"tRegion8";
			this->tRegion8->Size = System::Drawing::Size(900, 156);
			this->tRegion8->TabIndex = 7;
			this->tRegion8->Text = L"+";
			this->tRegion8->UseVisualStyleBackColor = true;
			// 
			// dgAllocationData8
			// 
			this->dgAllocationData8->AllowUserToAddRows = false;
			this->dgAllocationData8->AllowUserToDeleteRows = false;
			this->dgAllocationData8->AllowUserToResizeColumns = false;
			this->dgAllocationData8->AllowUserToResizeRows = false;
			this->dgAllocationData8->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAllocationData8->Location = System::Drawing::Point(9, 14);
			this->dgAllocationData8->Name = L"dgAllocationData8";
			this->dgAllocationData8->RowHeadersWidth = 71;
			this->dgAllocationData8->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAllocationData8->Size = System::Drawing::Size(882, 129);
			this->dgAllocationData8->TabIndex = 12;
			this->dgAllocationData8->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &A_Continuous::dgAllocData_CellEnter);
			this->dgAllocationData8->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_Continuous::dgAllocData_KeyDown);
			// 
			// tRegion9
			// 
			this->tRegion9->Controls->Add(this->dgAllocationData9);
			this->tRegion9->Location = System::Drawing::Point(4, 22);
			this->tRegion9->Name = L"tRegion9";
			this->tRegion9->Size = System::Drawing::Size(900, 156);
			this->tRegion9->TabIndex = 8;
			this->tRegion9->Text = L"+";
			this->tRegion9->UseVisualStyleBackColor = true;
			// 
			// dgAllocationData9
			// 
			this->dgAllocationData9->AllowUserToAddRows = false;
			this->dgAllocationData9->AllowUserToDeleteRows = false;
			this->dgAllocationData9->AllowUserToResizeColumns = false;
			this->dgAllocationData9->AllowUserToResizeRows = false;
			this->dgAllocationData9->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAllocationData9->Location = System::Drawing::Point(9, 14);
			this->dgAllocationData9->Name = L"dgAllocationData9";
			this->dgAllocationData9->RowHeadersWidth = 71;
			this->dgAllocationData9->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAllocationData9->Size = System::Drawing::Size(882, 129);
			this->dgAllocationData9->TabIndex = 12;
			this->dgAllocationData9->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &A_Continuous::dgAllocData_CellEnter);
			this->dgAllocationData9->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_Continuous::dgAllocData_KeyDown);
			// 
			// tRegion10
			// 
			this->tRegion10->Controls->Add(this->dgAllocationData10);
			this->tRegion10->Location = System::Drawing::Point(4, 22);
			this->tRegion10->Name = L"tRegion10";
			this->tRegion10->Size = System::Drawing::Size(900, 156);
			this->tRegion10->TabIndex = 9;
			this->tRegion10->Text = L"+";
			this->tRegion10->UseVisualStyleBackColor = true;
			// 
			// dgAllocationData10
			// 
			this->dgAllocationData10->AllowUserToAddRows = false;
			this->dgAllocationData10->AllowUserToDeleteRows = false;
			this->dgAllocationData10->AllowUserToResizeColumns = false;
			this->dgAllocationData10->AllowUserToResizeRows = false;
			this->dgAllocationData10->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAllocationData10->Location = System::Drawing::Point(9, 14);
			this->dgAllocationData10->Name = L"dgAllocationData10";
			this->dgAllocationData10->RowHeadersWidth = 71;
			this->dgAllocationData10->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAllocationData10->Size = System::Drawing::Size(882, 129);
			this->dgAllocationData10->TabIndex = 12;
			this->dgAllocationData10->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &A_Continuous::dgAllocData_CellEnter);
			this->dgAllocationData10->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_Continuous::dgAllocData_KeyDown);
			// 
			// bDeleteRegression
			// 
			this->bDeleteRegression->Location = System::Drawing::Point(888, 560);
			this->bDeleteRegression->Name = L"bDeleteRegression";
			this->bDeleteRegression->Size = System::Drawing::Size(24, 23);
			this->bDeleteRegression->TabIndex = 134;
			this->bDeleteRegression->Text = L"-";
			this->bDeleteRegression->UseVisualStyleBackColor = true;
			this->bDeleteRegression->Visible = false;
			this->bDeleteRegression->Click += gcnew System::EventHandler(this, &A_Continuous::bDeleteRegression_Click);
			// 
			// cbPotReg
			// 
			this->cbPotReg->AutoSize = true;
			this->cbPotReg->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbPotReg->Location = System::Drawing::Point(583, 367);
			this->cbPotReg->Name = L"cbPotReg";
			this->cbPotReg->Size = System::Drawing::Size(234, 27);
			this->cbPotReg->TabIndex = 135;
			this->cbPotReg->Text = L"Usar Regiões do Potencial";
			this->cbPotReg->UseVisualStyleBackColor = true;
			this->cbPotReg->Visible = false;
			// 
			// A_Continuous
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(923, 591);
			this->Controls->Add(this->cbPotReg);
			this->Controls->Add(this->bDeleteRegression);
			this->Controls->Add(this->tcRegions);
			this->Controls->Add(this->lMaxDiffHelp);
			this->Controls->Add(this->lLegend);
			this->Controls->Add(this->tAttrProtection);
			this->Controls->Add(this->lAttrProtection);
			this->Controls->Add(this->tSaturationIndicator);
			this->Controls->Add(this->lSaturationIndicator);
			this->Controls->Add(this->tComplementarLU);
			this->Controls->Add(this->lComplementarLU);
			this->Controls->Add(this->tMaxElasticity);
			this->Controls->Add(this->lMaxElasticity);
			this->Controls->Add(this->tMinElasticity);
			this->Controls->Add(this->lMinElasticity);
			this->Controls->Add(this->lAllocationData);
			this->Controls->Add(this->tMaxDifference);
			this->Controls->Add(this->lMaxDifference);
			this->Controls->Add(this->tInitialElasticity);
			this->Controls->Add(this->lInitialElasticity);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->tMaxIteration);
			this->Controls->Add(this->lMaxIteration);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"A_Continuous";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Alocação - Continuo";
			this->Shown += gcnew System::EventHandler(this, &A_Continuous::A_Continuous_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->tcRegions->ResumeLayout(false);
			this->tRegion1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData))->EndInit();
			this->tRegion2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData2))->EndInit();
			this->tRegion3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData3))->EndInit();
			this->tRegion4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData4))->EndInit();
			this->tRegion5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData5))->EndInit();
			this->tRegion6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData6))->EndInit();
			this->tRegion7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData7))->EndInit();
			this->tRegion8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData8))->EndInit();
			this->tRegion9->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData9))->EndInit();
			this->tRegion10->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData10))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void A_Continuous_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgView, bool fDelete);
	private: System::Void dgAllocData_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void dgAllocData_CellEnter(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void initializeAllocationData(DataGridView^ dgAllocData);
	private: System::Void setAllocationData(DataGridView^ dgAllocData, String^ allocData);
	private: System::Void tcRegions_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bDeleteRegression_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void moveData(DataGridView^ dgAlloc, DataGridView^ dgAlloc2);
	private: System::Void getAllocationData(DataGridView^ dgAlloc);
	};
}

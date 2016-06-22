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
	/// Summary for P_ContinuousR
	/// </summary>
	public ref class P_ContinuousR : public System::Windows::Forms::Form
	{
	private:
		String^ gSLUT = "";
		String^ gSValues = "";
		String^ gSEmptyComponent = "";
		String^ gSEmptyComponentTitle = "";
		String^ gSAttributes = "";

	public:
		cReturnPotential^ lReturn;
		array<String^>^ lTempBetas = gcnew array<String^>(50);
		P_ContinuousR(cReturnPotential^ pPotencial)
		{
			InitializeComponent();
			lReturn = pPotencial;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~P_ContinuousR()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ContextMenuStrip^  cMSP_continuous;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::TextBox^  tLUT;
	private: System::Windows::Forms::Button^  bAddBetas;
	private: System::Windows::Forms::ListView^  lvLUT;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::TabControl^  tcRegions;
	private: System::Windows::Forms::TabPage^  tRegion1;
	private: System::Windows::Forms::TabPage^  tRegion2;
	private: System::Windows::Forms::TabPage^  tRegion3;
	private: System::Windows::Forms::TabPage^  tRegion4;
	private: System::Windows::Forms::TabPage^  tRegion5;
	private: System::Windows::Forms::TabPage^  tRegion6;
	private: System::Windows::Forms::TabPage^  tRegion7;
	private: System::Windows::Forms::TabPage^  tRegion8;
	private: System::Windows::Forms::TabPage^  tRegion9;
	private: System::Windows::Forms::TabPage^  tRegion10;
	private: System::Windows::Forms::TextBox^  tMinReg;
	private: System::Windows::Forms::TextBox^  tMaxReg;
	private: System::Windows::Forms::CheckBox^  cIsLog;
	private: System::Windows::Forms::TextBox^  tRo;
	private: System::Windows::Forms::Label^  lRo;
	private: System::Windows::Forms::Label^  lBetas;
	private: System::Windows::Forms::DataGridView^  dgBetas;
	private: System::Windows::Forms::TextBox^  tConst;
	private: System::Windows::Forms::Label^  lConst;
	private: System::Windows::Forms::Label^  lMaxReg;
	private: System::Windows::Forms::Label^  lMinReg;
	private: System::Windows::Forms::Button^  bDeleteRegression;
	private: System::Windows::Forms::Label^  lConst2;
	private: System::Windows::Forms::CheckBox^  cIsLog2;
	private: System::Windows::Forms::Label^  lConst3;
	private: System::Windows::Forms::CheckBox^  cIsLog3;
	private: System::Windows::Forms::Label^  lConst4;
	private: System::Windows::Forms::CheckBox^  cIsLog4;
	private: System::Windows::Forms::Label^  lConst5;
	private: System::Windows::Forms::CheckBox^  cIsLog5;
	private: System::Windows::Forms::Label^  lConst6;
	private: System::Windows::Forms::CheckBox^  cIsLog6;
	private: System::Windows::Forms::Label^  lConst7;
	private: System::Windows::Forms::CheckBox^  cIsLog7;
	private: System::Windows::Forms::Label^  lConst8;
	private: System::Windows::Forms::CheckBox^  cIsLog8;
	private: System::Windows::Forms::Label^  lConst9;
	private: System::Windows::Forms::CheckBox^  cIsLog9;
	private: System::Windows::Forms::Label^  lConst10;
	private: System::Windows::Forms::CheckBox^  cIsLog10;
	private: System::Windows::Forms::TextBox^  tConst2;
	private: System::Windows::Forms::TextBox^  tConst3;
	private: System::Windows::Forms::TextBox^  tConst4;
	private: System::Windows::Forms::TextBox^  tConst5;
	private: System::Windows::Forms::TextBox^  tConst6;
	private: System::Windows::Forms::TextBox^  tConst7;
	private: System::Windows::Forms::TextBox^  tConst8;
	private: System::Windows::Forms::TextBox^  tConst9;
	private: System::Windows::Forms::TextBox^  tConst10;
	private: System::Windows::Forms::Label^  lBetas2;
	private: System::Windows::Forms::Label^  lBetas3;
	private: System::Windows::Forms::Label^  lBetas4;
	private: System::Windows::Forms::Label^  lBetas5;
	private: System::Windows::Forms::Label^  lBetas6;
	private: System::Windows::Forms::Label^  lBetas7;
	private: System::Windows::Forms::Label^  lBetas8;
	private: System::Windows::Forms::Label^  lBetas9;
	private: System::Windows::Forms::Label^  lBetas10;
	private: System::Windows::Forms::Label^  lMinReg2;
	private: System::Windows::Forms::DataGridView^  dgBetas2;
	private: System::Windows::Forms::Label^  lMinReg3;
	private: System::Windows::Forms::DataGridView^  dgBetas3;
	private: System::Windows::Forms::Label^  lMinReg4;
	private: System::Windows::Forms::DataGridView^  dgBetas4;
	private: System::Windows::Forms::Label^  lMinReg5;
	private: System::Windows::Forms::DataGridView^  dgBetas5;
	private: System::Windows::Forms::Label^  lMinReg6;
	private: System::Windows::Forms::DataGridView^  dgBetas6;
	private: System::Windows::Forms::Label^  lMinReg7;
	private: System::Windows::Forms::DataGridView^  dgBetas7;
	private: System::Windows::Forms::Label^  lMinReg8;
	private: System::Windows::Forms::DataGridView^  dgBetas8;
	private: System::Windows::Forms::Label^  lMinReg9;
	private: System::Windows::Forms::DataGridView^  dgBetas9;
	private: System::Windows::Forms::Label^  lMinReg10;
	private: System::Windows::Forms::DataGridView^  dgBetas10;
	private: System::Windows::Forms::Label^  lMaxReg2;
	private: System::Windows::Forms::Label^  lMaxReg3;
	private: System::Windows::Forms::Label^  lMaxReg4;
	private: System::Windows::Forms::Label^  lMaxReg5;
	private: System::Windows::Forms::Label^  lMaxReg6;
	private: System::Windows::Forms::Label^  lMaxReg7;
	private: System::Windows::Forms::Label^  lMaxReg8;
	private: System::Windows::Forms::Label^  lMaxReg9;
	private: System::Windows::Forms::Label^  lMaxReg10;
	private: System::Windows::Forms::TextBox^  tMinReg2;
	private: System::Windows::Forms::TextBox^  tMinReg3;
	private: System::Windows::Forms::TextBox^  tMinReg4;
	private: System::Windows::Forms::TextBox^  tMinReg5;
	private: System::Windows::Forms::TextBox^  tMinReg6;
	private: System::Windows::Forms::TextBox^  tMinReg7;
	private: System::Windows::Forms::TextBox^  tMinReg8;
	private: System::Windows::Forms::TextBox^  tMinReg9;
	private: System::Windows::Forms::TextBox^  tMinReg10;
	private: System::Windows::Forms::TextBox^  tMaxReg2;
	private: System::Windows::Forms::TextBox^  tMaxReg3;
	private: System::Windows::Forms::TextBox^  tMaxReg4;
	private: System::Windows::Forms::TextBox^  tMaxReg5;
	private: System::Windows::Forms::TextBox^  tMaxReg6;
	private: System::Windows::Forms::TextBox^  tMaxReg7;
	private: System::Windows::Forms::TextBox^  tMaxReg8;
	private: System::Windows::Forms::TextBox^  tMaxReg9;
	private: System::Windows::Forms::TextBox^  tMaxReg10;
	private: System::Windows::Forms::Label^  lRo2;
	private: System::Windows::Forms::Label^  lRo3;
	private: System::Windows::Forms::Label^  lRo4;
	private: System::Windows::Forms::Label^  lRo5;
	private: System::Windows::Forms::Label^  lRo6;
	private: System::Windows::Forms::Label^  lRo7;
	private: System::Windows::Forms::Label^  lRo8;
	private: System::Windows::Forms::Label^  lRo9;
	private: System::Windows::Forms::Label^  lRo10;
	private: System::Windows::Forms::TextBox^  tRo2;
	private: System::Windows::Forms::TextBox^  tRo3;
	private: System::Windows::Forms::TextBox^  tRo4;
	private: System::Windows::Forms::TextBox^  tRo5;
	private: System::Windows::Forms::TextBox^  tRo6;
	private: System::Windows::Forms::TextBox^  tRo7;
	private: System::Windows::Forms::TextBox^  tRo8;
	private: System::Windows::Forms::TextBox^  tRo9;
	private: System::Windows::Forms::TextBox^  tRo10;
private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(P_ContinuousR::typeid));
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->tLUT = (gcnew System::Windows::Forms::TextBox());
			this->bAddBetas = (gcnew System::Windows::Forms::Button());
			this->lvLUT = (gcnew System::Windows::Forms::ListView());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->tcRegions = (gcnew System::Windows::Forms::TabControl());
			this->tRegion1 = (gcnew System::Windows::Forms::TabPage());
			this->tMinReg = (gcnew System::Windows::Forms::TextBox());
			this->tMaxReg = (gcnew System::Windows::Forms::TextBox());
			this->cIsLog = (gcnew System::Windows::Forms::CheckBox());
			this->tRo = (gcnew System::Windows::Forms::TextBox());
			this->lRo = (gcnew System::Windows::Forms::Label());
			this->lBetas = (gcnew System::Windows::Forms::Label());
			this->dgBetas = (gcnew System::Windows::Forms::DataGridView());
			this->tConst = (gcnew System::Windows::Forms::TextBox());
			this->lConst = (gcnew System::Windows::Forms::Label());
			this->lMaxReg = (gcnew System::Windows::Forms::Label());
			this->lMinReg = (gcnew System::Windows::Forms::Label());
			this->tRegion2 = (gcnew System::Windows::Forms::TabPage());
			this->tMaxReg2 = (gcnew System::Windows::Forms::TextBox());
			this->tMinReg2 = (gcnew System::Windows::Forms::TextBox());
			this->tRo2 = (gcnew System::Windows::Forms::TextBox());
			this->lRo2 = (gcnew System::Windows::Forms::Label());
			this->dgBetas2 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas2 = (gcnew System::Windows::Forms::Label());
			this->tConst2 = (gcnew System::Windows::Forms::TextBox());
			this->lConst2 = (gcnew System::Windows::Forms::Label());
			this->cIsLog2 = (gcnew System::Windows::Forms::CheckBox());
			this->lMaxReg2 = (gcnew System::Windows::Forms::Label());
			this->lMinReg2 = (gcnew System::Windows::Forms::Label());
			this->tRegion3 = (gcnew System::Windows::Forms::TabPage());
			this->tMaxReg3 = (gcnew System::Windows::Forms::TextBox());
			this->tMinReg3 = (gcnew System::Windows::Forms::TextBox());
			this->tRo3 = (gcnew System::Windows::Forms::TextBox());
			this->lRo3 = (gcnew System::Windows::Forms::Label());
			this->dgBetas3 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas3 = (gcnew System::Windows::Forms::Label());
			this->tConst3 = (gcnew System::Windows::Forms::TextBox());
			this->lConst3 = (gcnew System::Windows::Forms::Label());
			this->cIsLog3 = (gcnew System::Windows::Forms::CheckBox());
			this->lMaxReg3 = (gcnew System::Windows::Forms::Label());
			this->lMinReg3 = (gcnew System::Windows::Forms::Label());
			this->tRegion4 = (gcnew System::Windows::Forms::TabPage());
			this->tMaxReg4 = (gcnew System::Windows::Forms::TextBox());
			this->tMinReg4 = (gcnew System::Windows::Forms::TextBox());
			this->tRo4 = (gcnew System::Windows::Forms::TextBox());
			this->lRo4 = (gcnew System::Windows::Forms::Label());
			this->dgBetas4 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas4 = (gcnew System::Windows::Forms::Label());
			this->tConst4 = (gcnew System::Windows::Forms::TextBox());
			this->lConst4 = (gcnew System::Windows::Forms::Label());
			this->cIsLog4 = (gcnew System::Windows::Forms::CheckBox());
			this->lMaxReg4 = (gcnew System::Windows::Forms::Label());
			this->lMinReg4 = (gcnew System::Windows::Forms::Label());
			this->tRegion5 = (gcnew System::Windows::Forms::TabPage());
			this->tMaxReg5 = (gcnew System::Windows::Forms::TextBox());
			this->tMinReg5 = (gcnew System::Windows::Forms::TextBox());
			this->tRo5 = (gcnew System::Windows::Forms::TextBox());
			this->lRo5 = (gcnew System::Windows::Forms::Label());
			this->dgBetas5 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas5 = (gcnew System::Windows::Forms::Label());
			this->tConst5 = (gcnew System::Windows::Forms::TextBox());
			this->lConst5 = (gcnew System::Windows::Forms::Label());
			this->cIsLog5 = (gcnew System::Windows::Forms::CheckBox());
			this->lMaxReg5 = (gcnew System::Windows::Forms::Label());
			this->lMinReg5 = (gcnew System::Windows::Forms::Label());
			this->tRegion6 = (gcnew System::Windows::Forms::TabPage());
			this->tMaxReg6 = (gcnew System::Windows::Forms::TextBox());
			this->tMinReg6 = (gcnew System::Windows::Forms::TextBox());
			this->tRo6 = (gcnew System::Windows::Forms::TextBox());
			this->lRo6 = (gcnew System::Windows::Forms::Label());
			this->dgBetas6 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas6 = (gcnew System::Windows::Forms::Label());
			this->tConst6 = (gcnew System::Windows::Forms::TextBox());
			this->lConst6 = (gcnew System::Windows::Forms::Label());
			this->cIsLog6 = (gcnew System::Windows::Forms::CheckBox());
			this->lMaxReg6 = (gcnew System::Windows::Forms::Label());
			this->lMinReg6 = (gcnew System::Windows::Forms::Label());
			this->tRegion7 = (gcnew System::Windows::Forms::TabPage());
			this->tMaxReg7 = (gcnew System::Windows::Forms::TextBox());
			this->tMinReg7 = (gcnew System::Windows::Forms::TextBox());
			this->tRo7 = (gcnew System::Windows::Forms::TextBox());
			this->lRo7 = (gcnew System::Windows::Forms::Label());
			this->dgBetas7 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas7 = (gcnew System::Windows::Forms::Label());
			this->tConst7 = (gcnew System::Windows::Forms::TextBox());
			this->lConst7 = (gcnew System::Windows::Forms::Label());
			this->cIsLog7 = (gcnew System::Windows::Forms::CheckBox());
			this->lMaxReg7 = (gcnew System::Windows::Forms::Label());
			this->lMinReg7 = (gcnew System::Windows::Forms::Label());
			this->tRegion8 = (gcnew System::Windows::Forms::TabPage());
			this->tMaxReg8 = (gcnew System::Windows::Forms::TextBox());
			this->tMinReg8 = (gcnew System::Windows::Forms::TextBox());
			this->tRo8 = (gcnew System::Windows::Forms::TextBox());
			this->lRo8 = (gcnew System::Windows::Forms::Label());
			this->dgBetas8 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas8 = (gcnew System::Windows::Forms::Label());
			this->tConst8 = (gcnew System::Windows::Forms::TextBox());
			this->lConst8 = (gcnew System::Windows::Forms::Label());
			this->cIsLog8 = (gcnew System::Windows::Forms::CheckBox());
			this->lMaxReg8 = (gcnew System::Windows::Forms::Label());
			this->lMinReg8 = (gcnew System::Windows::Forms::Label());
			this->tRegion9 = (gcnew System::Windows::Forms::TabPage());
			this->tMaxReg9 = (gcnew System::Windows::Forms::TextBox());
			this->tMinReg9 = (gcnew System::Windows::Forms::TextBox());
			this->tRo9 = (gcnew System::Windows::Forms::TextBox());
			this->lRo9 = (gcnew System::Windows::Forms::Label());
			this->dgBetas9 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas9 = (gcnew System::Windows::Forms::Label());
			this->tConst9 = (gcnew System::Windows::Forms::TextBox());
			this->lConst9 = (gcnew System::Windows::Forms::Label());
			this->cIsLog9 = (gcnew System::Windows::Forms::CheckBox());
			this->lMaxReg9 = (gcnew System::Windows::Forms::Label());
			this->lMinReg9 = (gcnew System::Windows::Forms::Label());
			this->tRegion10 = (gcnew System::Windows::Forms::TabPage());
			this->tMaxReg10 = (gcnew System::Windows::Forms::TextBox());
			this->tMinReg10 = (gcnew System::Windows::Forms::TextBox());
			this->tRo10 = (gcnew System::Windows::Forms::TextBox());
			this->lRo10 = (gcnew System::Windows::Forms::Label());
			this->dgBetas10 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas10 = (gcnew System::Windows::Forms::Label());
			this->tConst10 = (gcnew System::Windows::Forms::TextBox());
			this->lConst10 = (gcnew System::Windows::Forms::Label());
			this->cIsLog10 = (gcnew System::Windows::Forms::CheckBox());
			this->lMaxReg10 = (gcnew System::Windows::Forms::Label());
			this->lMinReg10 = (gcnew System::Windows::Forms::Label());
			this->bDeleteRegression = (gcnew System::Windows::Forms::Button());
			this->cMSP_continuous = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->tcRegions->SuspendLayout();
			this->tRegion1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas))->BeginInit();
			this->tRegion2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas2))->BeginInit();
			this->tRegion3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas3))->BeginInit();
			this->tRegion4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas4))->BeginInit();
			this->tRegion5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas5))->BeginInit();
			this->tRegion6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas6))->BeginInit();
			this->tRegion7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas7))->BeginInit();
			this->tRegion8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas8))->BeginInit();
			this->tRegion9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas9))->BeginInit();
			this->tRegion10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas10))->BeginInit();
			this->cMSP_continuous->SuspendLayout();
			this->SuspendLayout();
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(271, 555);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 79;
			this->bCancel->Text = L"Cancelar";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Visible = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &P_ContinuousR::bCancel_Click);
			// 
			// tLUT
			// 
			this->tLUT->ForeColor = System::Drawing::Color::Black;
			this->tLUT->Location = System::Drawing::Point(13, 158);
			this->tLUT->Name = L"tLUT";
			this->tLUT->Size = System::Drawing::Size(161, 20);
			this->tLUT->TabIndex = 82;
			this->tLUT->Visible = false;
			// 
			// bAddBetas
			// 
			this->bAddBetas->Location = System::Drawing::Point(375, 555);
			this->bAddBetas->Name = L"bAddBetas";
			this->bAddBetas->Size = System::Drawing::Size(75, 23);
			this->bAddBetas->TabIndex = 78;
			this->bAddBetas->Text = L"Adicionar";
			this->bAddBetas->UseVisualStyleBackColor = true;
			this->bAddBetas->Visible = false;
			this->bAddBetas->Click += gcnew System::EventHandler(this, &P_ContinuousR::bAddBetas_Click);
			// 
			// lvLUT
			// 
			this->lvLUT->Location = System::Drawing::Point(13, 157);
			this->lvLUT->MultiSelect = false;
			this->lvLUT->Name = L"lvLUT";
			this->lvLUT->Size = System::Drawing::Size(171, 390);
			this->lvLUT->TabIndex = 77;
			this->lvLUT->UseCompatibleStateImageBehavior = false;
			this->lvLUT->SelectedIndexChanged += gcnew System::EventHandler(this, &P_ContinuousR::lvLUT_SelectedIndexChanged);
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(238, 555);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 80;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &P_ContinuousR::bSalvar_Click);
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(92, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 81;
			this->pbLogo1->TabStop = false;
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
			this->tcRegions->Location = System::Drawing::Point(211, 158);
			this->tcRegions->Name = L"tcRegions";
			this->tcRegions->SelectedIndex = 0;
			this->tcRegions->Size = System::Drawing::Size(296, 389);
			this->tcRegions->TabIndex = 83;
			this->tcRegions->Visible = false;
			this->tcRegions->SelectedIndexChanged += gcnew System::EventHandler(this, &P_ContinuousR::tcRegions_SelectedIndexChanged);
			// 
			// tRegion1
			// 
			this->tRegion1->Controls->Add(this->tMinReg);
			this->tRegion1->Controls->Add(this->tMaxReg);
			this->tRegion1->Controls->Add(this->cIsLog);
			this->tRegion1->Controls->Add(this->tRo);
			this->tRegion1->Controls->Add(this->lRo);
			this->tRegion1->Controls->Add(this->lBetas);
			this->tRegion1->Controls->Add(this->dgBetas);
			this->tRegion1->Controls->Add(this->tConst);
			this->tRegion1->Controls->Add(this->lConst);
			this->tRegion1->Controls->Add(this->lMaxReg);
			this->tRegion1->Controls->Add(this->lMinReg);
			this->tRegion1->Location = System::Drawing::Point(4, 22);
			this->tRegion1->Name = L"tRegion1";
			this->tRegion1->Padding = System::Windows::Forms::Padding(3);
			this->tRegion1->Size = System::Drawing::Size(288, 363);
			this->tRegion1->TabIndex = 0;
			this->tRegion1->Text = L"Region 1";
			this->tRegion1->UseVisualStyleBackColor = true;
			// 
			// tMinReg
			// 
			this->tMinReg->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg->Location = System::Drawing::Point(70, 102);
			this->tMinReg->Name = L"tMinReg";
			this->tMinReg->Size = System::Drawing::Size(56, 20);
			this->tMinReg->TabIndex = 84;
			this->tMinReg->Text = L"0";
			this->tMinReg->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg->Visible = false;
			this->tMinReg->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tMaxReg
			// 
			this->tMaxReg->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg->Location = System::Drawing::Point(172, 102);
			this->tMaxReg->Name = L"tMaxReg";
			this->tMaxReg->Size = System::Drawing::Size(56, 20);
			this->tMaxReg->TabIndex = 85;
			this->tMaxReg->Text = L"1";
			this->tMaxReg->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg->Visible = false;
			this->tMaxReg->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// cIsLog
			// 
			this->cIsLog->AutoSize = true;
			this->cIsLog->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog->Location = System::Drawing::Point(34, 2);
			this->cIsLog->Name = L"cIsLog";
			this->cIsLog->Size = System::Drawing::Size(69, 27);
			this->cIsLog->TabIndex = 82;
			this->cIsLog->Text = L"isLog";
			this->cIsLog->UseVisualStyleBackColor = true;
			this->cIsLog->Visible = false;
			// 
			// tRo
			// 
			this->tRo->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo->Location = System::Drawing::Point(86, 141);
			this->tRo->Name = L"tRo";
			this->tRo->Size = System::Drawing::Size(161, 20);
			this->tRo->TabIndex = 86;
			this->tRo->Text = L"0.5";
			this->tRo->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo->Visible = false;
			this->tRo->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lRo
			// 
			this->lRo->AutoSize = true;
			this->lRo->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo->Location = System::Drawing::Point(53, 138);
			this->lRo->Name = L"lRo";
			this->lRo->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo->Size = System::Drawing::Size(27, 23);
			this->lRo->TabIndex = 91;
			this->lRo->Text = L"ro";
			this->lRo->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo->Visible = false;
			// 
			// lBetas
			// 
			this->lBetas->AutoSize = true;
			this->lBetas->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas->Location = System::Drawing::Point(117, 78);
			this->lBetas->Name = L"lBetas";
			this->lBetas->Size = System::Drawing::Size(55, 23);
			this->lBetas->TabIndex = 89;
			this->lBetas->Text = L"Betas";
			this->lBetas->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas->Visible = false;
			// 
			// dgBetas
			// 
			this->dgBetas->AllowUserToResizeColumns = false;
			this->dgBetas->AllowUserToResizeRows = false;
			this->dgBetas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas->ContextMenuStrip = this->cMSP_continuous;
			this->dgBetas->Location = System::Drawing::Point(20, 107);
			this->dgBetas->Name = L"dgBetas";
			this->dgBetas->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas->Size = System::Drawing::Size(245, 246);
			this->dgBetas->TabIndex = 87;
			this->dgBetas->Visible = false;
			this->dgBetas->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_ContinuousR::dgBetas_KeyDown);
			// 
			// tConst
			// 
			this->tConst->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst->Location = System::Drawing::Point(91, 44);
			this->tConst->Name = L"tConst";
			this->tConst->Size = System::Drawing::Size(161, 20);
			this->tConst->TabIndex = 83;
			this->tConst->Text = L"0.01";
			this->tConst->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst->Visible = false;
			this->tConst->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lConst
			// 
			this->lConst->AutoSize = true;
			this->lConst->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst->Location = System::Drawing::Point(30, 43);
			this->lConst->Name = L"lConst";
			this->lConst->Size = System::Drawing::Size(55, 23);
			this->lConst->TabIndex = 88;
			this->lConst->Text = L"Const";
			this->lConst->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst->Visible = false;
			// 
			// lMaxReg
			// 
			this->lMaxReg->AutoSize = true;
			this->lMaxReg->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg->Location = System::Drawing::Point(163, 77);
			this->lMaxReg->Name = L"lMaxReg";
			this->lMaxReg->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg->Size = System::Drawing::Size(73, 23);
			this->lMaxReg->TabIndex = 92;
			this->lMaxReg->Text = L"maxReg";
			this->lMaxReg->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg->Visible = false;
			// 
			// lMinReg
			// 
			this->lMinReg->AutoSize = true;
			this->lMinReg->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg->Location = System::Drawing::Point(61, 77);
			this->lMinReg->Name = L"lMinReg";
			this->lMinReg->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg->Size = System::Drawing::Size(70, 23);
			this->lMinReg->TabIndex = 90;
			this->lMinReg->Text = L"minReg";
			this->lMinReg->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg->Visible = false;
			// 
			// tRegion2
			// 
			this->tRegion2->Controls->Add(this->tMaxReg2);
			this->tRegion2->Controls->Add(this->tMinReg2);
			this->tRegion2->Controls->Add(this->tRo2);
			this->tRegion2->Controls->Add(this->lRo2);
			this->tRegion2->Controls->Add(this->dgBetas2);
			this->tRegion2->Controls->Add(this->lBetas2);
			this->tRegion2->Controls->Add(this->tConst2);
			this->tRegion2->Controls->Add(this->lConst2);
			this->tRegion2->Controls->Add(this->cIsLog2);
			this->tRegion2->Controls->Add(this->lMaxReg2);
			this->tRegion2->Controls->Add(this->lMinReg2);
			this->tRegion2->Location = System::Drawing::Point(4, 22);
			this->tRegion2->Name = L"tRegion2";
			this->tRegion2->Padding = System::Windows::Forms::Padding(3);
			this->tRegion2->Size = System::Drawing::Size(288, 363);
			this->tRegion2->TabIndex = 1;
			this->tRegion2->Text = L"+";
			this->tRegion2->UseVisualStyleBackColor = true;
			// 
			// tMaxReg2
			// 
			this->tMaxReg2->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg2->Location = System::Drawing::Point(172, 102);
			this->tMaxReg2->Name = L"tMaxReg2";
			this->tMaxReg2->Size = System::Drawing::Size(56, 20);
			this->tMaxReg2->TabIndex = 96;
			this->tMaxReg2->Text = L"1";
			this->tMaxReg2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg2->Visible = false;
			this->tMaxReg2->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tMinReg2
			// 
			this->tMinReg2->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg2->Location = System::Drawing::Point(70, 102);
			this->tMinReg2->Name = L"tMinReg2";
			this->tMinReg2->Size = System::Drawing::Size(56, 20);
			this->tMinReg2->TabIndex = 95;
			this->tMinReg2->Text = L"0";
			this->tMinReg2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg2->Visible = false;
			this->tMinReg2->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tRo2
			// 
			this->tRo2->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo2->Location = System::Drawing::Point(86, 141);
			this->tRo2->Name = L"tRo2";
			this->tRo2->Size = System::Drawing::Size(161, 20);
			this->tRo2->TabIndex = 98;
			this->tRo2->Text = L"0.5";
			this->tRo2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo2->Visible = false;
			this->tRo2->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lRo2
			// 
			this->lRo2->AutoSize = true;
			this->lRo2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo2->Location = System::Drawing::Point(53, 138);
			this->lRo2->Name = L"lRo2";
			this->lRo2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo2->Size = System::Drawing::Size(27, 23);
			this->lRo2->TabIndex = 97;
			this->lRo2->Text = L"ro";
			this->lRo2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo2->Visible = false;
			// 
			// dgBetas2
			// 
			this->dgBetas2->AllowUserToResizeColumns = false;
			this->dgBetas2->AllowUserToResizeRows = false;
			this->dgBetas2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas2->ContextMenuStrip = this->cMSP_continuous;
			this->dgBetas2->Location = System::Drawing::Point(20, 107);
			this->dgBetas2->Name = L"dgBetas2";
			this->dgBetas2->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas2->Size = System::Drawing::Size(245, 246);
			this->dgBetas2->TabIndex = 92;
			this->dgBetas2->Visible = false;
			this->dgBetas2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_ContinuousR::dgBetas_KeyDown);
			// 
			// lBetas2
			// 
			this->lBetas2->AutoSize = true;
			this->lBetas2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas2->Location = System::Drawing::Point(117, 78);
			this->lBetas2->Name = L"lBetas2";
			this->lBetas2->Size = System::Drawing::Size(55, 23);
			this->lBetas2->TabIndex = 91;
			this->lBetas2->Text = L"Betas";
			this->lBetas2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas2->Visible = false;
			// 
			// tConst2
			// 
			this->tConst2->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst2->Location = System::Drawing::Point(91, 44);
			this->tConst2->Name = L"tConst2";
			this->tConst2->Size = System::Drawing::Size(161, 20);
			this->tConst2->TabIndex = 90;
			this->tConst2->Text = L"0.01";
			this->tConst2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst2->Visible = false;
			this->tConst2->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lConst2
			// 
			this->lConst2->AutoSize = true;
			this->lConst2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst2->Location = System::Drawing::Point(30, 43);
			this->lConst2->Name = L"lConst2";
			this->lConst2->Size = System::Drawing::Size(55, 23);
			this->lConst2->TabIndex = 89;
			this->lConst2->Text = L"Const";
			this->lConst2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst2->Visible = false;
			// 
			// cIsLog2
			// 
			this->cIsLog2->AutoSize = true;
			this->cIsLog2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog2->Location = System::Drawing::Point(34, 2);
			this->cIsLog2->Name = L"cIsLog2";
			this->cIsLog2->Size = System::Drawing::Size(69, 27);
			this->cIsLog2->TabIndex = 83;
			this->cIsLog2->Text = L"isLog";
			this->cIsLog2->UseVisualStyleBackColor = true;
			this->cIsLog2->Visible = false;
			// 
			// lMaxReg2
			// 
			this->lMaxReg2->AutoSize = true;
			this->lMaxReg2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg2->Location = System::Drawing::Point(163, 77);
			this->lMaxReg2->Name = L"lMaxReg2";
			this->lMaxReg2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg2->Size = System::Drawing::Size(73, 23);
			this->lMaxReg2->TabIndex = 94;
			this->lMaxReg2->Text = L"maxReg";
			this->lMaxReg2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg2->Visible = false;
			// 
			// lMinReg2
			// 
			this->lMinReg2->AutoSize = true;
			this->lMinReg2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg2->Location = System::Drawing::Point(61, 77);
			this->lMinReg2->Name = L"lMinReg2";
			this->lMinReg2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg2->Size = System::Drawing::Size(70, 23);
			this->lMinReg2->TabIndex = 93;
			this->lMinReg2->Text = L"minReg";
			this->lMinReg2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg2->Visible = false;
			// 
			// tRegion3
			// 
			this->tRegion3->Controls->Add(this->tMaxReg3);
			this->tRegion3->Controls->Add(this->tMinReg3);
			this->tRegion3->Controls->Add(this->tRo3);
			this->tRegion3->Controls->Add(this->lRo3);
			this->tRegion3->Controls->Add(this->dgBetas3);
			this->tRegion3->Controls->Add(this->lBetas3);
			this->tRegion3->Controls->Add(this->tConst3);
			this->tRegion3->Controls->Add(this->lConst3);
			this->tRegion3->Controls->Add(this->cIsLog3);
			this->tRegion3->Controls->Add(this->lMaxReg3);
			this->tRegion3->Controls->Add(this->lMinReg3);
			this->tRegion3->Location = System::Drawing::Point(4, 22);
			this->tRegion3->Name = L"tRegion3";
			this->tRegion3->Size = System::Drawing::Size(288, 363);
			this->tRegion3->TabIndex = 2;
			this->tRegion3->Text = L"+";
			this->tRegion3->UseVisualStyleBackColor = true;
			// 
			// tMaxReg3
			// 
			this->tMaxReg3->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg3->Location = System::Drawing::Point(172, 102);
			this->tMaxReg3->Name = L"tMaxReg3";
			this->tMaxReg3->Size = System::Drawing::Size(56, 20);
			this->tMaxReg3->TabIndex = 96;
			this->tMaxReg3->Text = L"1";
			this->tMaxReg3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg3->Visible = false;
			this->tMaxReg3->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tMinReg3
			// 
			this->tMinReg3->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg3->Location = System::Drawing::Point(70, 102);
			this->tMinReg3->Name = L"tMinReg3";
			this->tMinReg3->Size = System::Drawing::Size(56, 20);
			this->tMinReg3->TabIndex = 95;
			this->tMinReg3->Text = L"0";
			this->tMinReg3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg3->Visible = false;
			this->tMinReg3->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tRo3
			// 
			this->tRo3->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo3->Location = System::Drawing::Point(86, 141);
			this->tRo3->Name = L"tRo3";
			this->tRo3->Size = System::Drawing::Size(161, 20);
			this->tRo3->TabIndex = 98;
			this->tRo3->Text = L"0.5";
			this->tRo3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo3->Visible = false;
			this->tRo3->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lRo3
			// 
			this->lRo3->AutoSize = true;
			this->lRo3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo3->Location = System::Drawing::Point(53, 138);
			this->lRo3->Name = L"lRo3";
			this->lRo3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo3->Size = System::Drawing::Size(27, 23);
			this->lRo3->TabIndex = 97;
			this->lRo3->Text = L"ro";
			this->lRo3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo3->Visible = false;
			// 
			// dgBetas3
			// 
			this->dgBetas3->AllowUserToResizeColumns = false;
			this->dgBetas3->AllowUserToResizeRows = false;
			this->dgBetas3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas3->ContextMenuStrip = this->cMSP_continuous;
			this->dgBetas3->Location = System::Drawing::Point(20, 107);
			this->dgBetas3->Name = L"dgBetas3";
			this->dgBetas3->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas3->Size = System::Drawing::Size(245, 246);
			this->dgBetas3->TabIndex = 92;
			this->dgBetas3->Visible = false;
			this->dgBetas3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_ContinuousR::dgBetas_KeyDown);
			// 
			// lBetas3
			// 
			this->lBetas3->AutoSize = true;
			this->lBetas3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas3->Location = System::Drawing::Point(117, 78);
			this->lBetas3->Name = L"lBetas3";
			this->lBetas3->Size = System::Drawing::Size(55, 23);
			this->lBetas3->TabIndex = 91;
			this->lBetas3->Text = L"Betas";
			this->lBetas3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas3->Visible = false;
			// 
			// tConst3
			// 
			this->tConst3->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst3->Location = System::Drawing::Point(91, 44);
			this->tConst3->Name = L"tConst3";
			this->tConst3->Size = System::Drawing::Size(161, 20);
			this->tConst3->TabIndex = 90;
			this->tConst3->Text = L"0.01";
			this->tConst3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst3->Visible = false;
			this->tConst3->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lConst3
			// 
			this->lConst3->AutoSize = true;
			this->lConst3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst3->Location = System::Drawing::Point(30, 43);
			this->lConst3->Name = L"lConst3";
			this->lConst3->Size = System::Drawing::Size(55, 23);
			this->lConst3->TabIndex = 89;
			this->lConst3->Text = L"Const";
			this->lConst3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst3->Visible = false;
			// 
			// cIsLog3
			// 
			this->cIsLog3->AutoSize = true;
			this->cIsLog3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog3->Location = System::Drawing::Point(34, 2);
			this->cIsLog3->Name = L"cIsLog3";
			this->cIsLog3->Size = System::Drawing::Size(69, 27);
			this->cIsLog3->TabIndex = 83;
			this->cIsLog3->Text = L"isLog";
			this->cIsLog3->UseVisualStyleBackColor = true;
			this->cIsLog3->Visible = false;
			// 
			// lMaxReg3
			// 
			this->lMaxReg3->AutoSize = true;
			this->lMaxReg3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg3->Location = System::Drawing::Point(163, 77);
			this->lMaxReg3->Name = L"lMaxReg3";
			this->lMaxReg3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg3->Size = System::Drawing::Size(73, 23);
			this->lMaxReg3->TabIndex = 94;
			this->lMaxReg3->Text = L"maxReg";
			this->lMaxReg3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg3->Visible = false;
			// 
			// lMinReg3
			// 
			this->lMinReg3->AutoSize = true;
			this->lMinReg3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg3->Location = System::Drawing::Point(61, 77);
			this->lMinReg3->Name = L"lMinReg3";
			this->lMinReg3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg3->Size = System::Drawing::Size(70, 23);
			this->lMinReg3->TabIndex = 93;
			this->lMinReg3->Text = L"minReg";
			this->lMinReg3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg3->Visible = false;
			// 
			// tRegion4
			// 
			this->tRegion4->Controls->Add(this->tMaxReg4);
			this->tRegion4->Controls->Add(this->tMinReg4);
			this->tRegion4->Controls->Add(this->tRo4);
			this->tRegion4->Controls->Add(this->lRo4);
			this->tRegion4->Controls->Add(this->dgBetas4);
			this->tRegion4->Controls->Add(this->lBetas4);
			this->tRegion4->Controls->Add(this->tConst4);
			this->tRegion4->Controls->Add(this->lConst4);
			this->tRegion4->Controls->Add(this->cIsLog4);
			this->tRegion4->Controls->Add(this->lMaxReg4);
			this->tRegion4->Controls->Add(this->lMinReg4);
			this->tRegion4->Location = System::Drawing::Point(4, 22);
			this->tRegion4->Name = L"tRegion4";
			this->tRegion4->Size = System::Drawing::Size(288, 363);
			this->tRegion4->TabIndex = 3;
			this->tRegion4->Text = L"+";
			this->tRegion4->UseVisualStyleBackColor = true;
			// 
			// tMaxReg4
			// 
			this->tMaxReg4->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg4->Location = System::Drawing::Point(172, 102);
			this->tMaxReg4->Name = L"tMaxReg4";
			this->tMaxReg4->Size = System::Drawing::Size(56, 20);
			this->tMaxReg4->TabIndex = 96;
			this->tMaxReg4->Text = L"1";
			this->tMaxReg4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg4->Visible = false;
			this->tMaxReg4->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tMinReg4
			// 
			this->tMinReg4->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg4->Location = System::Drawing::Point(70, 102);
			this->tMinReg4->Name = L"tMinReg4";
			this->tMinReg4->Size = System::Drawing::Size(56, 20);
			this->tMinReg4->TabIndex = 95;
			this->tMinReg4->Text = L"0";
			this->tMinReg4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg4->Visible = false;
			this->tMinReg4->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tRo4
			// 
			this->tRo4->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo4->Location = System::Drawing::Point(86, 141);
			this->tRo4->Name = L"tRo4";
			this->tRo4->Size = System::Drawing::Size(161, 20);
			this->tRo4->TabIndex = 98;
			this->tRo4->Text = L"0.5";
			this->tRo4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo4->Visible = false;
			this->tRo4->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lRo4
			// 
			this->lRo4->AutoSize = true;
			this->lRo4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo4->Location = System::Drawing::Point(53, 138);
			this->lRo4->Name = L"lRo4";
			this->lRo4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo4->Size = System::Drawing::Size(27, 23);
			this->lRo4->TabIndex = 97;
			this->lRo4->Text = L"ro";
			this->lRo4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo4->Visible = false;
			// 
			// dgBetas4
			// 
			this->dgBetas4->AllowUserToResizeColumns = false;
			this->dgBetas4->AllowUserToResizeRows = false;
			this->dgBetas4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas4->ContextMenuStrip = this->cMSP_continuous;
			this->dgBetas4->Location = System::Drawing::Point(20, 107);
			this->dgBetas4->Name = L"dgBetas4";
			this->dgBetas4->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas4->Size = System::Drawing::Size(245, 246);
			this->dgBetas4->TabIndex = 92;
			this->dgBetas4->Visible = false;
			this->dgBetas4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_ContinuousR::dgBetas_KeyDown);
			// 
			// lBetas4
			// 
			this->lBetas4->AutoSize = true;
			this->lBetas4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas4->Location = System::Drawing::Point(117, 78);
			this->lBetas4->Name = L"lBetas4";
			this->lBetas4->Size = System::Drawing::Size(55, 23);
			this->lBetas4->TabIndex = 91;
			this->lBetas4->Text = L"Betas";
			this->lBetas4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas4->Visible = false;
			// 
			// tConst4
			// 
			this->tConst4->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst4->Location = System::Drawing::Point(91, 44);
			this->tConst4->Name = L"tConst4";
			this->tConst4->Size = System::Drawing::Size(161, 20);
			this->tConst4->TabIndex = 90;
			this->tConst4->Text = L"0.01";
			this->tConst4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst4->Visible = false;
			this->tConst4->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lConst4
			// 
			this->lConst4->AutoSize = true;
			this->lConst4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst4->Location = System::Drawing::Point(30, 43);
			this->lConst4->Name = L"lConst4";
			this->lConst4->Size = System::Drawing::Size(55, 23);
			this->lConst4->TabIndex = 89;
			this->lConst4->Text = L"Const";
			this->lConst4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst4->Visible = false;
			// 
			// cIsLog4
			// 
			this->cIsLog4->AutoSize = true;
			this->cIsLog4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog4->Location = System::Drawing::Point(34, 2);
			this->cIsLog4->Name = L"cIsLog4";
			this->cIsLog4->Size = System::Drawing::Size(69, 27);
			this->cIsLog4->TabIndex = 83;
			this->cIsLog4->Text = L"isLog";
			this->cIsLog4->UseVisualStyleBackColor = true;
			this->cIsLog4->Visible = false;
			// 
			// lMaxReg4
			// 
			this->lMaxReg4->AutoSize = true;
			this->lMaxReg4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg4->Location = System::Drawing::Point(163, 77);
			this->lMaxReg4->Name = L"lMaxReg4";
			this->lMaxReg4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg4->Size = System::Drawing::Size(73, 23);
			this->lMaxReg4->TabIndex = 94;
			this->lMaxReg4->Text = L"maxReg";
			this->lMaxReg4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg4->Visible = false;
			// 
			// lMinReg4
			// 
			this->lMinReg4->AutoSize = true;
			this->lMinReg4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg4->Location = System::Drawing::Point(61, 77);
			this->lMinReg4->Name = L"lMinReg4";
			this->lMinReg4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg4->Size = System::Drawing::Size(70, 23);
			this->lMinReg4->TabIndex = 93;
			this->lMinReg4->Text = L"minReg";
			this->lMinReg4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg4->Visible = false;
			// 
			// tRegion5
			// 
			this->tRegion5->Controls->Add(this->tMaxReg5);
			this->tRegion5->Controls->Add(this->tMinReg5);
			this->tRegion5->Controls->Add(this->tRo5);
			this->tRegion5->Controls->Add(this->lRo5);
			this->tRegion5->Controls->Add(this->dgBetas5);
			this->tRegion5->Controls->Add(this->lBetas5);
			this->tRegion5->Controls->Add(this->tConst5);
			this->tRegion5->Controls->Add(this->lConst5);
			this->tRegion5->Controls->Add(this->cIsLog5);
			this->tRegion5->Controls->Add(this->lMaxReg5);
			this->tRegion5->Controls->Add(this->lMinReg5);
			this->tRegion5->Location = System::Drawing::Point(4, 22);
			this->tRegion5->Name = L"tRegion5";
			this->tRegion5->Size = System::Drawing::Size(288, 363);
			this->tRegion5->TabIndex = 4;
			this->tRegion5->Text = L"+";
			this->tRegion5->UseVisualStyleBackColor = true;
			// 
			// tMaxReg5
			// 
			this->tMaxReg5->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg5->Location = System::Drawing::Point(172, 102);
			this->tMaxReg5->Name = L"tMaxReg5";
			this->tMaxReg5->Size = System::Drawing::Size(56, 20);
			this->tMaxReg5->TabIndex = 96;
			this->tMaxReg5->Text = L"1";
			this->tMaxReg5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg5->Visible = false;
			this->tMaxReg5->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tMinReg5
			// 
			this->tMinReg5->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg5->Location = System::Drawing::Point(70, 102);
			this->tMinReg5->Name = L"tMinReg5";
			this->tMinReg5->Size = System::Drawing::Size(56, 20);
			this->tMinReg5->TabIndex = 95;
			this->tMinReg5->Text = L"0";
			this->tMinReg5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg5->Visible = false;
			this->tMinReg5->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tRo5
			// 
			this->tRo5->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo5->Location = System::Drawing::Point(86, 141);
			this->tRo5->Name = L"tRo5";
			this->tRo5->Size = System::Drawing::Size(161, 20);
			this->tRo5->TabIndex = 98;
			this->tRo5->Text = L"0.5";
			this->tRo5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo5->Visible = false;
			this->tRo5->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lRo5
			// 
			this->lRo5->AutoSize = true;
			this->lRo5->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo5->Location = System::Drawing::Point(53, 138);
			this->lRo5->Name = L"lRo5";
			this->lRo5->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo5->Size = System::Drawing::Size(27, 23);
			this->lRo5->TabIndex = 97;
			this->lRo5->Text = L"ro";
			this->lRo5->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo5->Visible = false;
			// 
			// dgBetas5
			// 
			this->dgBetas5->AllowUserToResizeColumns = false;
			this->dgBetas5->AllowUserToResizeRows = false;
			this->dgBetas5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas5->ContextMenuStrip = this->cMSP_continuous;
			this->dgBetas5->Location = System::Drawing::Point(20, 107);
			this->dgBetas5->Name = L"dgBetas5";
			this->dgBetas5->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas5->Size = System::Drawing::Size(245, 246);
			this->dgBetas5->TabIndex = 92;
			this->dgBetas5->Visible = false;
			this->dgBetas5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_ContinuousR::dgBetas_KeyDown);
			// 
			// lBetas5
			// 
			this->lBetas5->AutoSize = true;
			this->lBetas5->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas5->Location = System::Drawing::Point(117, 78);
			this->lBetas5->Name = L"lBetas5";
			this->lBetas5->Size = System::Drawing::Size(55, 23);
			this->lBetas5->TabIndex = 91;
			this->lBetas5->Text = L"Betas";
			this->lBetas5->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas5->Visible = false;
			// 
			// tConst5
			// 
			this->tConst5->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst5->Location = System::Drawing::Point(91, 44);
			this->tConst5->Name = L"tConst5";
			this->tConst5->Size = System::Drawing::Size(161, 20);
			this->tConst5->TabIndex = 90;
			this->tConst5->Text = L"0.01";
			this->tConst5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst5->Visible = false;
			this->tConst5->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lConst5
			// 
			this->lConst5->AutoSize = true;
			this->lConst5->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst5->Location = System::Drawing::Point(30, 43);
			this->lConst5->Name = L"lConst5";
			this->lConst5->Size = System::Drawing::Size(55, 23);
			this->lConst5->TabIndex = 89;
			this->lConst5->Text = L"Const";
			this->lConst5->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst5->Visible = false;
			// 
			// cIsLog5
			// 
			this->cIsLog5->AutoSize = true;
			this->cIsLog5->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog5->Location = System::Drawing::Point(34, 2);
			this->cIsLog5->Name = L"cIsLog5";
			this->cIsLog5->Size = System::Drawing::Size(69, 27);
			this->cIsLog5->TabIndex = 83;
			this->cIsLog5->Text = L"isLog";
			this->cIsLog5->UseVisualStyleBackColor = true;
			this->cIsLog5->Visible = false;
			// 
			// lMaxReg5
			// 
			this->lMaxReg5->AutoSize = true;
			this->lMaxReg5->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg5->Location = System::Drawing::Point(163, 77);
			this->lMaxReg5->Name = L"lMaxReg5";
			this->lMaxReg5->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg5->Size = System::Drawing::Size(73, 23);
			this->lMaxReg5->TabIndex = 94;
			this->lMaxReg5->Text = L"maxReg";
			this->lMaxReg5->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg5->Visible = false;
			// 
			// lMinReg5
			// 
			this->lMinReg5->AutoSize = true;
			this->lMinReg5->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg5->Location = System::Drawing::Point(61, 77);
			this->lMinReg5->Name = L"lMinReg5";
			this->lMinReg5->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg5->Size = System::Drawing::Size(70, 23);
			this->lMinReg5->TabIndex = 93;
			this->lMinReg5->Text = L"minReg";
			this->lMinReg5->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg5->Visible = false;
			// 
			// tRegion6
			// 
			this->tRegion6->Controls->Add(this->tMaxReg6);
			this->tRegion6->Controls->Add(this->tMinReg6);
			this->tRegion6->Controls->Add(this->tRo6);
			this->tRegion6->Controls->Add(this->lRo6);
			this->tRegion6->Controls->Add(this->dgBetas6);
			this->tRegion6->Controls->Add(this->lBetas6);
			this->tRegion6->Controls->Add(this->tConst6);
			this->tRegion6->Controls->Add(this->lConst6);
			this->tRegion6->Controls->Add(this->cIsLog6);
			this->tRegion6->Controls->Add(this->lMaxReg6);
			this->tRegion6->Controls->Add(this->lMinReg6);
			this->tRegion6->Location = System::Drawing::Point(4, 22);
			this->tRegion6->Name = L"tRegion6";
			this->tRegion6->Size = System::Drawing::Size(288, 363);
			this->tRegion6->TabIndex = 5;
			this->tRegion6->Text = L"+";
			this->tRegion6->UseVisualStyleBackColor = true;
			// 
			// tMaxReg6
			// 
			this->tMaxReg6->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg6->Location = System::Drawing::Point(172, 102);
			this->tMaxReg6->Name = L"tMaxReg6";
			this->tMaxReg6->Size = System::Drawing::Size(56, 20);
			this->tMaxReg6->TabIndex = 96;
			this->tMaxReg6->Text = L"1";
			this->tMaxReg6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg6->Visible = false;
			this->tMaxReg6->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tMinReg6
			// 
			this->tMinReg6->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg6->Location = System::Drawing::Point(70, 102);
			this->tMinReg6->Name = L"tMinReg6";
			this->tMinReg6->Size = System::Drawing::Size(56, 20);
			this->tMinReg6->TabIndex = 95;
			this->tMinReg6->Text = L"0";
			this->tMinReg6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg6->Visible = false;
			this->tMinReg6->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tRo6
			// 
			this->tRo6->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo6->Location = System::Drawing::Point(86, 141);
			this->tRo6->Name = L"tRo6";
			this->tRo6->Size = System::Drawing::Size(161, 20);
			this->tRo6->TabIndex = 98;
			this->tRo6->Text = L"0.5";
			this->tRo6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo6->Visible = false;
			this->tRo6->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lRo6
			// 
			this->lRo6->AutoSize = true;
			this->lRo6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo6->Location = System::Drawing::Point(53, 138);
			this->lRo6->Name = L"lRo6";
			this->lRo6->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo6->Size = System::Drawing::Size(27, 23);
			this->lRo6->TabIndex = 97;
			this->lRo6->Text = L"ro";
			this->lRo6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo6->Visible = false;
			// 
			// dgBetas6
			// 
			this->dgBetas6->AllowUserToResizeColumns = false;
			this->dgBetas6->AllowUserToResizeRows = false;
			this->dgBetas6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas6->ContextMenuStrip = this->cMSP_continuous;
			this->dgBetas6->Location = System::Drawing::Point(20, 107);
			this->dgBetas6->Name = L"dgBetas6";
			this->dgBetas6->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas6->Size = System::Drawing::Size(245, 246);
			this->dgBetas6->TabIndex = 92;
			this->dgBetas6->Visible = false;
			this->dgBetas6->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_ContinuousR::dgBetas_KeyDown);
			// 
			// lBetas6
			// 
			this->lBetas6->AutoSize = true;
			this->lBetas6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas6->Location = System::Drawing::Point(117, 78);
			this->lBetas6->Name = L"lBetas6";
			this->lBetas6->Size = System::Drawing::Size(55, 23);
			this->lBetas6->TabIndex = 91;
			this->lBetas6->Text = L"Betas";
			this->lBetas6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas6->Visible = false;
			// 
			// tConst6
			// 
			this->tConst6->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst6->Location = System::Drawing::Point(91, 44);
			this->tConst6->Name = L"tConst6";
			this->tConst6->Size = System::Drawing::Size(161, 20);
			this->tConst6->TabIndex = 90;
			this->tConst6->Text = L"0.01";
			this->tConst6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst6->Visible = false;
			this->tConst6->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lConst6
			// 
			this->lConst6->AutoSize = true;
			this->lConst6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst6->Location = System::Drawing::Point(30, 43);
			this->lConst6->Name = L"lConst6";
			this->lConst6->Size = System::Drawing::Size(55, 23);
			this->lConst6->TabIndex = 89;
			this->lConst6->Text = L"Const";
			this->lConst6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst6->Visible = false;
			// 
			// cIsLog6
			// 
			this->cIsLog6->AutoSize = true;
			this->cIsLog6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog6->Location = System::Drawing::Point(34, 2);
			this->cIsLog6->Name = L"cIsLog6";
			this->cIsLog6->Size = System::Drawing::Size(69, 27);
			this->cIsLog6->TabIndex = 83;
			this->cIsLog6->Text = L"isLog";
			this->cIsLog6->UseVisualStyleBackColor = true;
			this->cIsLog6->Visible = false;
			// 
			// lMaxReg6
			// 
			this->lMaxReg6->AutoSize = true;
			this->lMaxReg6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg6->Location = System::Drawing::Point(163, 77);
			this->lMaxReg6->Name = L"lMaxReg6";
			this->lMaxReg6->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg6->Size = System::Drawing::Size(73, 23);
			this->lMaxReg6->TabIndex = 94;
			this->lMaxReg6->Text = L"maxReg";
			this->lMaxReg6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg6->Visible = false;
			// 
			// lMinReg6
			// 
			this->lMinReg6->AutoSize = true;
			this->lMinReg6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg6->Location = System::Drawing::Point(61, 77);
			this->lMinReg6->Name = L"lMinReg6";
			this->lMinReg6->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg6->Size = System::Drawing::Size(70, 23);
			this->lMinReg6->TabIndex = 93;
			this->lMinReg6->Text = L"minReg";
			this->lMinReg6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg6->Visible = false;
			// 
			// tRegion7
			// 
			this->tRegion7->Controls->Add(this->tMaxReg7);
			this->tRegion7->Controls->Add(this->tMinReg7);
			this->tRegion7->Controls->Add(this->tRo7);
			this->tRegion7->Controls->Add(this->lRo7);
			this->tRegion7->Controls->Add(this->dgBetas7);
			this->tRegion7->Controls->Add(this->lBetas7);
			this->tRegion7->Controls->Add(this->tConst7);
			this->tRegion7->Controls->Add(this->lConst7);
			this->tRegion7->Controls->Add(this->cIsLog7);
			this->tRegion7->Controls->Add(this->lMaxReg7);
			this->tRegion7->Controls->Add(this->lMinReg7);
			this->tRegion7->Location = System::Drawing::Point(4, 22);
			this->tRegion7->Name = L"tRegion7";
			this->tRegion7->Size = System::Drawing::Size(288, 363);
			this->tRegion7->TabIndex = 6;
			this->tRegion7->Text = L"+";
			this->tRegion7->UseVisualStyleBackColor = true;
			// 
			// tMaxReg7
			// 
			this->tMaxReg7->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg7->Location = System::Drawing::Point(172, 102);
			this->tMaxReg7->Name = L"tMaxReg7";
			this->tMaxReg7->Size = System::Drawing::Size(56, 20);
			this->tMaxReg7->TabIndex = 96;
			this->tMaxReg7->Text = L"1";
			this->tMaxReg7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg7->Visible = false;
			this->tMaxReg7->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tMinReg7
			// 
			this->tMinReg7->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg7->Location = System::Drawing::Point(70, 102);
			this->tMinReg7->Name = L"tMinReg7";
			this->tMinReg7->Size = System::Drawing::Size(56, 20);
			this->tMinReg7->TabIndex = 95;
			this->tMinReg7->Text = L"0";
			this->tMinReg7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg7->Visible = false;
			this->tMinReg7->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tRo7
			// 
			this->tRo7->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo7->Location = System::Drawing::Point(86, 141);
			this->tRo7->Name = L"tRo7";
			this->tRo7->Size = System::Drawing::Size(161, 20);
			this->tRo7->TabIndex = 98;
			this->tRo7->Text = L"0.5";
			this->tRo7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo7->Visible = false;
			this->tRo7->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lRo7
			// 
			this->lRo7->AutoSize = true;
			this->lRo7->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo7->Location = System::Drawing::Point(53, 138);
			this->lRo7->Name = L"lRo7";
			this->lRo7->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo7->Size = System::Drawing::Size(27, 23);
			this->lRo7->TabIndex = 97;
			this->lRo7->Text = L"ro";
			this->lRo7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo7->Visible = false;
			// 
			// dgBetas7
			// 
			this->dgBetas7->AllowUserToResizeColumns = false;
			this->dgBetas7->AllowUserToResizeRows = false;
			this->dgBetas7->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas7->ContextMenuStrip = this->cMSP_continuous;
			this->dgBetas7->Location = System::Drawing::Point(20, 107);
			this->dgBetas7->Name = L"dgBetas7";
			this->dgBetas7->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas7->Size = System::Drawing::Size(245, 246);
			this->dgBetas7->TabIndex = 92;
			this->dgBetas7->Visible = false;
			this->dgBetas7->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_ContinuousR::dgBetas_KeyDown);
			// 
			// lBetas7
			// 
			this->lBetas7->AutoSize = true;
			this->lBetas7->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas7->Location = System::Drawing::Point(117, 78);
			this->lBetas7->Name = L"lBetas7";
			this->lBetas7->Size = System::Drawing::Size(55, 23);
			this->lBetas7->TabIndex = 91;
			this->lBetas7->Text = L"Betas";
			this->lBetas7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas7->Visible = false;
			// 
			// tConst7
			// 
			this->tConst7->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst7->Location = System::Drawing::Point(91, 44);
			this->tConst7->Name = L"tConst7";
			this->tConst7->Size = System::Drawing::Size(161, 20);
			this->tConst7->TabIndex = 90;
			this->tConst7->Text = L"0.01";
			this->tConst7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst7->Visible = false;
			this->tConst7->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lConst7
			// 
			this->lConst7->AutoSize = true;
			this->lConst7->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst7->Location = System::Drawing::Point(30, 43);
			this->lConst7->Name = L"lConst7";
			this->lConst7->Size = System::Drawing::Size(55, 23);
			this->lConst7->TabIndex = 89;
			this->lConst7->Text = L"Const";
			this->lConst7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst7->Visible = false;
			// 
			// cIsLog7
			// 
			this->cIsLog7->AutoSize = true;
			this->cIsLog7->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog7->Location = System::Drawing::Point(34, 2);
			this->cIsLog7->Name = L"cIsLog7";
			this->cIsLog7->Size = System::Drawing::Size(69, 27);
			this->cIsLog7->TabIndex = 83;
			this->cIsLog7->Text = L"isLog";
			this->cIsLog7->UseVisualStyleBackColor = true;
			this->cIsLog7->Visible = false;
			// 
			// lMaxReg7
			// 
			this->lMaxReg7->AutoSize = true;
			this->lMaxReg7->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg7->Location = System::Drawing::Point(163, 77);
			this->lMaxReg7->Name = L"lMaxReg7";
			this->lMaxReg7->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg7->Size = System::Drawing::Size(73, 23);
			this->lMaxReg7->TabIndex = 94;
			this->lMaxReg7->Text = L"maxReg";
			this->lMaxReg7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg7->Visible = false;
			// 
			// lMinReg7
			// 
			this->lMinReg7->AutoSize = true;
			this->lMinReg7->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg7->Location = System::Drawing::Point(61, 77);
			this->lMinReg7->Name = L"lMinReg7";
			this->lMinReg7->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg7->Size = System::Drawing::Size(70, 23);
			this->lMinReg7->TabIndex = 93;
			this->lMinReg7->Text = L"minReg";
			this->lMinReg7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg7->Visible = false;
			// 
			// tRegion8
			// 
			this->tRegion8->Controls->Add(this->tMaxReg8);
			this->tRegion8->Controls->Add(this->tMinReg8);
			this->tRegion8->Controls->Add(this->tRo8);
			this->tRegion8->Controls->Add(this->lRo8);
			this->tRegion8->Controls->Add(this->dgBetas8);
			this->tRegion8->Controls->Add(this->lBetas8);
			this->tRegion8->Controls->Add(this->tConst8);
			this->tRegion8->Controls->Add(this->lConst8);
			this->tRegion8->Controls->Add(this->cIsLog8);
			this->tRegion8->Controls->Add(this->lMaxReg8);
			this->tRegion8->Controls->Add(this->lMinReg8);
			this->tRegion8->Location = System::Drawing::Point(4, 22);
			this->tRegion8->Name = L"tRegion8";
			this->tRegion8->Size = System::Drawing::Size(288, 363);
			this->tRegion8->TabIndex = 7;
			this->tRegion8->Text = L"+";
			this->tRegion8->UseVisualStyleBackColor = true;
			// 
			// tMaxReg8
			// 
			this->tMaxReg8->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg8->Location = System::Drawing::Point(172, 102);
			this->tMaxReg8->Name = L"tMaxReg8";
			this->tMaxReg8->Size = System::Drawing::Size(56, 20);
			this->tMaxReg8->TabIndex = 96;
			this->tMaxReg8->Text = L"1";
			this->tMaxReg8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg8->Visible = false;
			this->tMaxReg8->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tMinReg8
			// 
			this->tMinReg8->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg8->Location = System::Drawing::Point(70, 102);
			this->tMinReg8->Name = L"tMinReg8";
			this->tMinReg8->Size = System::Drawing::Size(56, 20);
			this->tMinReg8->TabIndex = 95;
			this->tMinReg8->Text = L"0";
			this->tMinReg8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg8->Visible = false;
			this->tMinReg8->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tRo8
			// 
			this->tRo8->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo8->Location = System::Drawing::Point(86, 141);
			this->tRo8->Name = L"tRo8";
			this->tRo8->Size = System::Drawing::Size(161, 20);
			this->tRo8->TabIndex = 98;
			this->tRo8->Text = L"0.5";
			this->tRo8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo8->Visible = false;
			this->tRo8->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lRo8
			// 
			this->lRo8->AutoSize = true;
			this->lRo8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo8->Location = System::Drawing::Point(53, 138);
			this->lRo8->Name = L"lRo8";
			this->lRo8->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo8->Size = System::Drawing::Size(27, 23);
			this->lRo8->TabIndex = 97;
			this->lRo8->Text = L"ro";
			this->lRo8->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo8->Visible = false;
			// 
			// dgBetas8
			// 
			this->dgBetas8->AllowUserToResizeColumns = false;
			this->dgBetas8->AllowUserToResizeRows = false;
			this->dgBetas8->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas8->ContextMenuStrip = this->cMSP_continuous;
			this->dgBetas8->Location = System::Drawing::Point(20, 107);
			this->dgBetas8->Name = L"dgBetas8";
			this->dgBetas8->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas8->Size = System::Drawing::Size(245, 246);
			this->dgBetas8->TabIndex = 92;
			this->dgBetas8->Visible = false;
			this->dgBetas8->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_ContinuousR::dgBetas_KeyDown);
			// 
			// lBetas8
			// 
			this->lBetas8->AutoSize = true;
			this->lBetas8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas8->Location = System::Drawing::Point(117, 78);
			this->lBetas8->Name = L"lBetas8";
			this->lBetas8->Size = System::Drawing::Size(55, 23);
			this->lBetas8->TabIndex = 91;
			this->lBetas8->Text = L"Betas";
			this->lBetas8->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas8->Visible = false;
			// 
			// tConst8
			// 
			this->tConst8->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst8->Location = System::Drawing::Point(91, 44);
			this->tConst8->Name = L"tConst8";
			this->tConst8->Size = System::Drawing::Size(161, 20);
			this->tConst8->TabIndex = 90;
			this->tConst8->Text = L"0.01";
			this->tConst8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst8->Visible = false;
			this->tConst8->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lConst8
			// 
			this->lConst8->AutoSize = true;
			this->lConst8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst8->Location = System::Drawing::Point(30, 43);
			this->lConst8->Name = L"lConst8";
			this->lConst8->Size = System::Drawing::Size(55, 23);
			this->lConst8->TabIndex = 89;
			this->lConst8->Text = L"Const";
			this->lConst8->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst8->Visible = false;
			// 
			// cIsLog8
			// 
			this->cIsLog8->AutoSize = true;
			this->cIsLog8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog8->Location = System::Drawing::Point(34, 2);
			this->cIsLog8->Name = L"cIsLog8";
			this->cIsLog8->Size = System::Drawing::Size(69, 27);
			this->cIsLog8->TabIndex = 83;
			this->cIsLog8->Text = L"isLog";
			this->cIsLog8->UseVisualStyleBackColor = true;
			this->cIsLog8->Visible = false;
			// 
			// lMaxReg8
			// 
			this->lMaxReg8->AutoSize = true;
			this->lMaxReg8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg8->Location = System::Drawing::Point(163, 77);
			this->lMaxReg8->Name = L"lMaxReg8";
			this->lMaxReg8->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg8->Size = System::Drawing::Size(73, 23);
			this->lMaxReg8->TabIndex = 94;
			this->lMaxReg8->Text = L"maxReg";
			this->lMaxReg8->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg8->Visible = false;
			// 
			// lMinReg8
			// 
			this->lMinReg8->AutoSize = true;
			this->lMinReg8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg8->Location = System::Drawing::Point(61, 77);
			this->lMinReg8->Name = L"lMinReg8";
			this->lMinReg8->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg8->Size = System::Drawing::Size(70, 23);
			this->lMinReg8->TabIndex = 93;
			this->lMinReg8->Text = L"minReg";
			this->lMinReg8->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg8->Visible = false;
			// 
			// tRegion9
			// 
			this->tRegion9->Controls->Add(this->tMaxReg9);
			this->tRegion9->Controls->Add(this->tMinReg9);
			this->tRegion9->Controls->Add(this->tRo9);
			this->tRegion9->Controls->Add(this->lRo9);
			this->tRegion9->Controls->Add(this->dgBetas9);
			this->tRegion9->Controls->Add(this->lBetas9);
			this->tRegion9->Controls->Add(this->tConst9);
			this->tRegion9->Controls->Add(this->lConst9);
			this->tRegion9->Controls->Add(this->cIsLog9);
			this->tRegion9->Controls->Add(this->lMaxReg9);
			this->tRegion9->Controls->Add(this->lMinReg9);
			this->tRegion9->Location = System::Drawing::Point(4, 22);
			this->tRegion9->Name = L"tRegion9";
			this->tRegion9->Size = System::Drawing::Size(288, 363);
			this->tRegion9->TabIndex = 8;
			this->tRegion9->Text = L"+";
			this->tRegion9->UseVisualStyleBackColor = true;
			// 
			// tMaxReg9
			// 
			this->tMaxReg9->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg9->Location = System::Drawing::Point(172, 102);
			this->tMaxReg9->Name = L"tMaxReg9";
			this->tMaxReg9->Size = System::Drawing::Size(56, 20);
			this->tMaxReg9->TabIndex = 96;
			this->tMaxReg9->Text = L"1";
			this->tMaxReg9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg9->Visible = false;
			this->tMaxReg9->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tMinReg9
			// 
			this->tMinReg9->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg9->Location = System::Drawing::Point(70, 102);
			this->tMinReg9->Name = L"tMinReg9";
			this->tMinReg9->Size = System::Drawing::Size(56, 20);
			this->tMinReg9->TabIndex = 95;
			this->tMinReg9->Text = L"0";
			this->tMinReg9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg9->Visible = false;
			this->tMinReg9->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tRo9
			// 
			this->tRo9->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo9->Location = System::Drawing::Point(86, 141);
			this->tRo9->Name = L"tRo9";
			this->tRo9->Size = System::Drawing::Size(161, 20);
			this->tRo9->TabIndex = 98;
			this->tRo9->Text = L"0.5";
			this->tRo9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo9->Visible = false;
			this->tRo9->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lRo9
			// 
			this->lRo9->AutoSize = true;
			this->lRo9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo9->Location = System::Drawing::Point(53, 138);
			this->lRo9->Name = L"lRo9";
			this->lRo9->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo9->Size = System::Drawing::Size(27, 23);
			this->lRo9->TabIndex = 97;
			this->lRo9->Text = L"ro";
			this->lRo9->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo9->Visible = false;
			// 
			// dgBetas9
			// 
			this->dgBetas9->AllowUserToResizeColumns = false;
			this->dgBetas9->AllowUserToResizeRows = false;
			this->dgBetas9->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas9->ContextMenuStrip = this->cMSP_continuous;
			this->dgBetas9->Location = System::Drawing::Point(20, 107);
			this->dgBetas9->Name = L"dgBetas9";
			this->dgBetas9->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas9->Size = System::Drawing::Size(245, 246);
			this->dgBetas9->TabIndex = 92;
			this->dgBetas9->Visible = false;
			this->dgBetas9->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_ContinuousR::dgBetas_KeyDown);
			// 
			// lBetas9
			// 
			this->lBetas9->AutoSize = true;
			this->lBetas9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas9->Location = System::Drawing::Point(117, 78);
			this->lBetas9->Name = L"lBetas9";
			this->lBetas9->Size = System::Drawing::Size(55, 23);
			this->lBetas9->TabIndex = 91;
			this->lBetas9->Text = L"Betas";
			this->lBetas9->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas9->Visible = false;
			// 
			// tConst9
			// 
			this->tConst9->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst9->Location = System::Drawing::Point(91, 44);
			this->tConst9->Name = L"tConst9";
			this->tConst9->Size = System::Drawing::Size(161, 20);
			this->tConst9->TabIndex = 90;
			this->tConst9->Text = L"0.01";
			this->tConst9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst9->Visible = false;
			this->tConst9->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lConst9
			// 
			this->lConst9->AutoSize = true;
			this->lConst9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst9->Location = System::Drawing::Point(30, 43);
			this->lConst9->Name = L"lConst9";
			this->lConst9->Size = System::Drawing::Size(55, 23);
			this->lConst9->TabIndex = 89;
			this->lConst9->Text = L"Const";
			this->lConst9->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst9->Visible = false;
			// 
			// cIsLog9
			// 
			this->cIsLog9->AutoSize = true;
			this->cIsLog9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog9->Location = System::Drawing::Point(34, 2);
			this->cIsLog9->Name = L"cIsLog9";
			this->cIsLog9->Size = System::Drawing::Size(69, 27);
			this->cIsLog9->TabIndex = 83;
			this->cIsLog9->Text = L"isLog";
			this->cIsLog9->UseVisualStyleBackColor = true;
			this->cIsLog9->Visible = false;
			// 
			// lMaxReg9
			// 
			this->lMaxReg9->AutoSize = true;
			this->lMaxReg9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg9->Location = System::Drawing::Point(163, 77);
			this->lMaxReg9->Name = L"lMaxReg9";
			this->lMaxReg9->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg9->Size = System::Drawing::Size(73, 23);
			this->lMaxReg9->TabIndex = 94;
			this->lMaxReg9->Text = L"maxReg";
			this->lMaxReg9->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg9->Visible = false;
			// 
			// lMinReg9
			// 
			this->lMinReg9->AutoSize = true;
			this->lMinReg9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg9->Location = System::Drawing::Point(61, 77);
			this->lMinReg9->Name = L"lMinReg9";
			this->lMinReg9->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg9->Size = System::Drawing::Size(70, 23);
			this->lMinReg9->TabIndex = 93;
			this->lMinReg9->Text = L"minReg";
			this->lMinReg9->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg9->Visible = false;
			// 
			// tRegion10
			// 
			this->tRegion10->Controls->Add(this->tMaxReg10);
			this->tRegion10->Controls->Add(this->tMinReg10);
			this->tRegion10->Controls->Add(this->tRo10);
			this->tRegion10->Controls->Add(this->lRo10);
			this->tRegion10->Controls->Add(this->dgBetas10);
			this->tRegion10->Controls->Add(this->lBetas10);
			this->tRegion10->Controls->Add(this->tConst10);
			this->tRegion10->Controls->Add(this->lConst10);
			this->tRegion10->Controls->Add(this->cIsLog10);
			this->tRegion10->Controls->Add(this->lMaxReg10);
			this->tRegion10->Controls->Add(this->lMinReg10);
			this->tRegion10->Location = System::Drawing::Point(4, 22);
			this->tRegion10->Name = L"tRegion10";
			this->tRegion10->Size = System::Drawing::Size(288, 363);
			this->tRegion10->TabIndex = 9;
			this->tRegion10->Text = L"+";
			this->tRegion10->UseVisualStyleBackColor = true;
			// 
			// tMaxReg10
			// 
			this->tMaxReg10->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg10->Location = System::Drawing::Point(172, 102);
			this->tMaxReg10->Name = L"tMaxReg10";
			this->tMaxReg10->Size = System::Drawing::Size(56, 20);
			this->tMaxReg10->TabIndex = 96;
			this->tMaxReg10->Text = L"1";
			this->tMaxReg10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg10->Visible = false;
			this->tMaxReg10->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tMinReg10
			// 
			this->tMinReg10->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg10->Location = System::Drawing::Point(70, 102);
			this->tMinReg10->Name = L"tMinReg10";
			this->tMinReg10->Size = System::Drawing::Size(56, 20);
			this->tMinReg10->TabIndex = 95;
			this->tMinReg10->Text = L"0";
			this->tMinReg10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg10->Visible = false;
			this->tMinReg10->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// tRo10
			// 
			this->tRo10->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo10->Location = System::Drawing::Point(86, 141);
			this->tRo10->Name = L"tRo10";
			this->tRo10->Size = System::Drawing::Size(161, 20);
			this->tRo10->TabIndex = 98;
			this->tRo10->Text = L"0.5";
			this->tRo10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo10->Visible = false;
			this->tRo10->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lRo10
			// 
			this->lRo10->AutoSize = true;
			this->lRo10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo10->Location = System::Drawing::Point(53, 138);
			this->lRo10->Name = L"lRo10";
			this->lRo10->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo10->Size = System::Drawing::Size(27, 23);
			this->lRo10->TabIndex = 97;
			this->lRo10->Text = L"ro";
			this->lRo10->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo10->Visible = false;
			// 
			// dgBetas10
			// 
			this->dgBetas10->AllowUserToResizeColumns = false;
			this->dgBetas10->AllowUserToResizeRows = false;
			this->dgBetas10->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas10->ContextMenuStrip = this->cMSP_continuous;
			this->dgBetas10->Location = System::Drawing::Point(20, 107);
			this->dgBetas10->Name = L"dgBetas10";
			this->dgBetas10->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas10->Size = System::Drawing::Size(245, 246);
			this->dgBetas10->TabIndex = 92;
			this->dgBetas10->Visible = false;
			this->dgBetas10->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_ContinuousR::dgBetas_KeyDown);
			// 
			// lBetas10
			// 
			this->lBetas10->AutoSize = true;
			this->lBetas10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas10->Location = System::Drawing::Point(117, 78);
			this->lBetas10->Name = L"lBetas10";
			this->lBetas10->Size = System::Drawing::Size(55, 23);
			this->lBetas10->TabIndex = 91;
			this->lBetas10->Text = L"Betas";
			this->lBetas10->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas10->Visible = false;
			// 
			// tConst10
			// 
			this->tConst10->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst10->Location = System::Drawing::Point(91, 44);
			this->tConst10->Name = L"tConst10";
			this->tConst10->Size = System::Drawing::Size(161, 20);
			this->tConst10->TabIndex = 90;
			this->tConst10->Text = L"0.01";
			this->tConst10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst10->Visible = false;
			this->tConst10->Enter += gcnew System::EventHandler(this, &P_ContinuousR::textBox_Enter);
			// 
			// lConst10
			// 
			this->lConst10->AutoSize = true;
			this->lConst10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst10->Location = System::Drawing::Point(30, 43);
			this->lConst10->Name = L"lConst10";
			this->lConst10->Size = System::Drawing::Size(55, 23);
			this->lConst10->TabIndex = 89;
			this->lConst10->Text = L"Const";
			this->lConst10->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst10->Visible = false;
			// 
			// cIsLog10
			// 
			this->cIsLog10->AutoSize = true;
			this->cIsLog10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog10->Location = System::Drawing::Point(34, 2);
			this->cIsLog10->Name = L"cIsLog10";
			this->cIsLog10->Size = System::Drawing::Size(69, 27);
			this->cIsLog10->TabIndex = 83;
			this->cIsLog10->Text = L"isLog";
			this->cIsLog10->UseVisualStyleBackColor = true;
			this->cIsLog10->Visible = false;
			// 
			// lMaxReg10
			// 
			this->lMaxReg10->AutoSize = true;
			this->lMaxReg10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg10->Location = System::Drawing::Point(163, 77);
			this->lMaxReg10->Name = L"lMaxReg10";
			this->lMaxReg10->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg10->Size = System::Drawing::Size(73, 23);
			this->lMaxReg10->TabIndex = 94;
			this->lMaxReg10->Text = L"maxReg";
			this->lMaxReg10->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg10->Visible = false;
			// 
			// lMinReg10
			// 
			this->lMinReg10->AutoSize = true;
			this->lMinReg10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg10->Location = System::Drawing::Point(61, 77);
			this->lMinReg10->Name = L"lMinReg10";
			this->lMinReg10->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg10->Size = System::Drawing::Size(70, 23);
			this->lMinReg10->TabIndex = 93;
			this->lMinReg10->Text = L"minReg";
			this->lMinReg10->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg10->Visible = false;
			// 
			// bDeleteRegression
			// 
			this->bDeleteRegression->Location = System::Drawing::Point(510, 187);
			this->bDeleteRegression->Name = L"bDeleteRegression";
			this->bDeleteRegression->Size = System::Drawing::Size(24, 23);
			this->bDeleteRegression->TabIndex = 84;
			this->bDeleteRegression->Text = L"-";
			this->bDeleteRegression->UseVisualStyleBackColor = true;
			this->bDeleteRegression->Visible = false;
			this->bDeleteRegression->Click += gcnew System::EventHandler(this, &P_ContinuousR::bDeleteRegression_Click);
			// 
			// cMSP_continuous
			// 
			this->cMSP_continuous->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->copyToolStripMenuItem,
					this->pasteToolStripMenuItem
			});
			this->cMSP_continuous->Name = L"contextMenuStrip1";
			this->cMSP_continuous->Size = System::Drawing::Size(103, 48);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->copyToolStripMenuItem->Text = L"Copy";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &P_ContinuousR::copyToolStripMenuItem_Click);
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->pasteToolStripMenuItem->Text = L"Paste";
			this->pasteToolStripMenuItem->Click += gcnew System::EventHandler(this, &P_ContinuousR::pasteToolStripMenuItem_Click);
			// 
			// P_ContinuousR
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(543, 585);
			this->Controls->Add(this->bDeleteRegression);
			this->Controls->Add(this->tcRegions);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->tLUT);
			this->Controls->Add(this->bAddBetas);
			this->Controls->Add(this->lvLUT);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"P_ContinuousR";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"P_ContinuousR";
			this->Shown += gcnew System::EventHandler(this, &P_ContinuousR::P_ContinuousR_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->tcRegions->ResumeLayout(false);
			this->tRegion1->ResumeLayout(false);
			this->tRegion1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas))->EndInit();
			this->tRegion2->ResumeLayout(false);
			this->tRegion2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas2))->EndInit();
			this->tRegion3->ResumeLayout(false);
			this->tRegion3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas3))->EndInit();
			this->tRegion4->ResumeLayout(false);
			this->tRegion4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas4))->EndInit();
			this->tRegion5->ResumeLayout(false);
			this->tRegion5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas5))->EndInit();
			this->tRegion6->ResumeLayout(false);
			this->tRegion6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas6))->EndInit();
			this->tRegion7->ResumeLayout(false);
			this->tRegion7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas7))->EndInit();
			this->tRegion8->ResumeLayout(false);
			this->tRegion8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas8))->EndInit();
			this->tRegion9->ResumeLayout(false);
			this->tRegion9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas9))->EndInit();
			this->tRegion10->ResumeLayout(false);
			this->tRegion10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas10))->EndInit();
			this->cMSP_continuous->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void P_ContinuousR_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Int16 getRegionData(array<String^>^ lTempBetas, cReturnPotential^ lReturn, DataGridView^ dgBetas, CheckBox^ cIsLog, TextBox^ tConst, TextBox^ tMinReg, TextBox^ tMaxReg, TextBox^ tRo, int y, int z);
	private: System::Void tcRegions_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void setVisibleONorOFF(Label^ lBetas, DataGridView^ dgBetas, CheckBox^ cIsLog, Label^ lConst, TextBox^ tConst, Label^ lMinReg, TextBox^ tMinReg, Label^ lMaxReg, TextBox^ tMaxReg, Label^ lRo, TextBox^ tRo, bool status);
	private: System::Void bDeleteRegression_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void moveData(DataGridView^ dgBetas, CheckBox^ cIsLog, TextBox^ tConst, TextBox^ tMinReg, TextBox^ tMaxReg, TextBox^ tRo, DataGridView^ dgBetas2, CheckBox^ cIsLog2, TextBox^ tConst2, TextBox^ tMinReg2, TextBox^ tMaxReg2, TextBox^ tRo2);
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void initializeRegions();
	private: System::Void bAddBetas_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void setRegionData(DataGridView^ dgBetas, CheckBox^ cIsLog, TextBox^ tConst, TextBox^ tMinReg, TextBox^ tMaxReg, TextBox^ tRo, int i, int j);
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgView);
	private: System::Void dgBetas_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void CopyToClipboard(DataGridView^ dgView);
	private: System::Void PasteClipboardValue(DataGridView^ dgView);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Int16 countCaracter(String^ source, char caracter);
	private: System::Void spatialLagRegressionONOFF(bool status);
	private: System::Void copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	};
}

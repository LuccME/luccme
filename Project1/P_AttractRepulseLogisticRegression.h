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
	/// Summary for P_AttractRepulseLogisticRegression
	/// </summary>
	public ref class P_AttractRepulseLogisticRegression : public System::Windows::Forms::Form
	{
	private:
		String^ gSLUT = "";
		String^ gSValues = "";
		String^ gSEmptyComponent = "";
		String^ gSEmptyComponentTitle = "";
		String^ gSAttributes = "";
		String^ gSCells = "";
		String^ gSCellsTitle = "";

	public:
		cReturnPotential^ lReturn;
		array<String^>^ lTempBetas = gcnew array<String^>(50);
	private: System::Windows::Forms::Label^  lLegend;
	private: System::Windows::Forms::Label^  lLegend6;
	private: System::Windows::Forms::Label^  lLegend7;
	private: System::Windows::Forms::Label^  lLegend8;
	private: System::Windows::Forms::Label^  lLegend10;
	private: System::Windows::Forms::Label^  lLegend9;
	private: System::Windows::Forms::Label^  lLegend5;
	private: System::Windows::Forms::Label^  lLegend2;
	private: System::Windows::Forms::Label^  lLegend3;
	private: System::Windows::Forms::Label^  lLegend4;
	public:
		array<String^>^ lTempValues = gcnew array<String^>(50);
		P_AttractRepulseLogisticRegression(cReturnPotential^ pPotencial)
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
		~P_AttractRepulseLogisticRegression()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tPercNeighborsUse8;
	protected:
	private: System::Windows::Forms::Label^  lBetas7;
	private: System::Windows::Forms::TextBox^  tConst7;
	private: System::Windows::Forms::Label^  lConst7;
	private: System::Windows::Forms::TextBox^  tPercNeighborsUse6;
	private: System::Windows::Forms::Label^  lPercNeighborsUse6;
	private: System::Windows::Forms::TextBox^  tElasticy6;
	private: System::Windows::Forms::Label^  lElasticy6;
	private: System::Windows::Forms::DataGridView^  dgBetas6;
	private: System::Windows::Forms::Label^  lBetas6;
	private: System::Windows::Forms::TextBox^  tConst6;
	private: System::Windows::Forms::TextBox^  tElasticy7;
	private: System::Windows::Forms::Label^  lElasticy7;
	private: System::Windows::Forms::DataGridView^  dgBetas7;
	private: System::Windows::Forms::Label^  lConst6;
	private: System::Windows::Forms::TextBox^  tPercNeighborsUse7;
	private: System::Windows::Forms::TabPage^  tRegion6;
	private: System::Windows::Forms::TabPage^  tRegion7;
	private: System::Windows::Forms::Label^  lPercNeighborsUse7;
	private: System::Windows::Forms::TabPage^  tRegion8;
	private: System::Windows::Forms::Label^  lPercNeighborsUse8;
	private: System::Windows::Forms::TextBox^  tElasticy8;
	private: System::Windows::Forms::Label^  lElasticy8;
	private: System::Windows::Forms::DataGridView^  dgBetas8;
	private: System::Windows::Forms::Label^  lBetas8;
	private: System::Windows::Forms::TextBox^  tConst8;
	private: System::Windows::Forms::Label^  lConst8;
	private: System::Windows::Forms::TextBox^  tConst10;
	private: System::Windows::Forms::TextBox^  tPercNeighborsUse5;
	private: System::Windows::Forms::TextBox^  tElasticy5;
	private: System::Windows::Forms::TextBox^  tPercNeighborsUse10;
	private: System::Windows::Forms::Label^  lPercNeighborsUse10;
	private: System::Windows::Forms::TextBox^  tElasticy10;
	private: System::Windows::Forms::Label^  lElasticy10;
	private: System::Windows::Forms::DataGridView^  dgBetas10;
	private: System::Windows::Forms::Label^  lBetas10;
	private: System::Windows::Forms::Label^  lConst10;
	private: System::Windows::Forms::TextBox^  tPercNeighborsUse9;
	private: System::Windows::Forms::Label^  lPercNeighborsUse9;
	private: System::Windows::Forms::TextBox^  tElasticy9;
	private: System::Windows::Forms::Label^  lElasticy9;
	private: System::Windows::Forms::TabPage^  tRegion10;
	private: System::Windows::Forms::DataGridView^  dgBetas9;
	private: System::Windows::Forms::TextBox^  tConst9;
	private: System::Windows::Forms::Label^  lConst9;
	private: System::Windows::Forms::Label^  lPercNeighborsUse5;
	private: System::Windows::Forms::TabPage^  tRegion9;
	private: System::Windows::Forms::Label^  lBetas9;
	private: System::Windows::Forms::Label^  lElasticy5;
	private: System::Windows::Forms::TabPage^  tRegion5;
	private: System::Windows::Forms::DataGridView^  dgBetas5;
	private: System::Windows::Forms::Label^  lBetas5;
	private: System::Windows::Forms::TextBox^  tConst5;
	private: System::Windows::Forms::Label^  lConst5;
	private: System::Windows::Forms::TextBox^  tPercNeighborsUse2;
	private: System::Windows::Forms::Label^  lPercNeighborsUse2;
	private: System::Windows::Forms::TextBox^  tElasticy2;
	private: System::Windows::Forms::Label^  lElasticy2;
	private: System::Windows::Forms::TabPage^  tRegion2;
	private: System::Windows::Forms::DataGridView^  dgBetas2;
	private: System::Windows::Forms::Label^  lBetas2;
	private: System::Windows::Forms::TextBox^  tConst2;
	private: System::Windows::Forms::Label^  lConst2;
	private: System::Windows::Forms::TextBox^  tPercNeighborsUse;
	private: System::Windows::Forms::Label^  lPercNeighborsUse;
	private: System::Windows::Forms::TextBox^  tElasticy;
	private: System::Windows::Forms::TabControl^  tcRegions;
	private: System::Windows::Forms::TabPage^  tRegion1;
	private: System::Windows::Forms::Label^  lElasticy;
	private: System::Windows::Forms::DataGridView^  dgBetas;
	private: System::Windows::Forms::TextBox^  tConst;
	private: System::Windows::Forms::Label^  lConst;
	private: System::Windows::Forms::Label^  lBetas;
	private: System::Windows::Forms::TabPage^  tRegion3;
	private: System::Windows::Forms::TextBox^  tPercNeighborsUse3;
	private: System::Windows::Forms::Label^  lPercNeighborsUse3;
	private: System::Windows::Forms::TextBox^  tElasticy3;
	private: System::Windows::Forms::Label^  lElasticy3;
	private: System::Windows::Forms::DataGridView^  dgBetas3;
	private: System::Windows::Forms::Label^  lBetas3;
	private: System::Windows::Forms::TextBox^  tConst3;
	private: System::Windows::Forms::Label^  lConst3;
	private: System::Windows::Forms::TabPage^  tRegion4;
	private: System::Windows::Forms::TextBox^  tPercNeighborsUse4;
	private: System::Windows::Forms::Label^  lPercNeighborsUse4;
	private: System::Windows::Forms::TextBox^  tElasticy4;
	private: System::Windows::Forms::Label^  lElasticy4;
	private: System::Windows::Forms::DataGridView^  dgBetas4;
	private: System::Windows::Forms::Label^  lBetas4;
	private: System::Windows::Forms::TextBox^  tConst4;
	private: System::Windows::Forms::Label^  lConst4;
	private: System::Windows::Forms::Button^  bDeleteRegression;
	private: System::Windows::Forms::TextBox^  tLUT;
	private: System::Windows::Forms::Button^  bAddBetas;
	private: System::Windows::Forms::ListView^  lvLUT;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Button^  bCancel;
private: System::Windows::Forms::Label^  lAffinityMatrix;
private: System::Windows::Forms::DataGridView^  dgAffinityMatrix;
private: System::Windows::Forms::Label^  lAffinityMatrix6;
private: System::Windows::Forms::Label^  lAffinityMatrix7;
private: System::Windows::Forms::Label^  lAffinityMatrix8;
private: System::Windows::Forms::Label^  lAffinityMatrix10;



private: System::Windows::Forms::Label^  lAffinityMatrix9;

private: System::Windows::Forms::Label^  lAffinityMatrix5;
private: System::Windows::Forms::Label^  lAffinityMatrix2;
private: System::Windows::Forms::Label^  lAffinityMatrix3;
private: System::Windows::Forms::Label^  lAffinityMatrix4;
private: System::Windows::Forms::DataGridView^  dgAffinityMatrix6;
private: System::Windows::Forms::DataGridView^  dgAffinityMatrix7;
private: System::Windows::Forms::DataGridView^  dgAffinityMatrix8;
private: System::Windows::Forms::DataGridView^  dgAffinityMatrix10;
private: System::Windows::Forms::DataGridView^  dgAffinityMatrix9;
private: System::Windows::Forms::DataGridView^  dgAffinityMatrix5;
private: System::Windows::Forms::DataGridView^  dgAffinityMatrix2;
private: System::Windows::Forms::DataGridView^  dgAffinityMatrix3;
private: System::Windows::Forms::DataGridView^  dgAffinityMatrix4;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(P_AttractRepulseLogisticRegression::typeid));
			this->tPercNeighborsUse8 = (gcnew System::Windows::Forms::TextBox());
			this->lBetas7 = (gcnew System::Windows::Forms::Label());
			this->tConst7 = (gcnew System::Windows::Forms::TextBox());
			this->lConst7 = (gcnew System::Windows::Forms::Label());
			this->tPercNeighborsUse6 = (gcnew System::Windows::Forms::TextBox());
			this->lPercNeighborsUse6 = (gcnew System::Windows::Forms::Label());
			this->tElasticy6 = (gcnew System::Windows::Forms::TextBox());
			this->lElasticy6 = (gcnew System::Windows::Forms::Label());
			this->dgBetas6 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas6 = (gcnew System::Windows::Forms::Label());
			this->tConst6 = (gcnew System::Windows::Forms::TextBox());
			this->tElasticy7 = (gcnew System::Windows::Forms::TextBox());
			this->lElasticy7 = (gcnew System::Windows::Forms::Label());
			this->dgBetas7 = (gcnew System::Windows::Forms::DataGridView());
			this->lConst6 = (gcnew System::Windows::Forms::Label());
			this->tPercNeighborsUse7 = (gcnew System::Windows::Forms::TextBox());
			this->tRegion6 = (gcnew System::Windows::Forms::TabPage());
			this->lLegend6 = (gcnew System::Windows::Forms::Label());
			this->lAffinityMatrix6 = (gcnew System::Windows::Forms::Label());
			this->dgAffinityMatrix6 = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion7 = (gcnew System::Windows::Forms::TabPage());
			this->lLegend7 = (gcnew System::Windows::Forms::Label());
			this->lAffinityMatrix7 = (gcnew System::Windows::Forms::Label());
			this->lPercNeighborsUse7 = (gcnew System::Windows::Forms::Label());
			this->dgAffinityMatrix7 = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion8 = (gcnew System::Windows::Forms::TabPage());
			this->lLegend8 = (gcnew System::Windows::Forms::Label());
			this->lAffinityMatrix8 = (gcnew System::Windows::Forms::Label());
			this->lPercNeighborsUse8 = (gcnew System::Windows::Forms::Label());
			this->tElasticy8 = (gcnew System::Windows::Forms::TextBox());
			this->lElasticy8 = (gcnew System::Windows::Forms::Label());
			this->dgBetas8 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas8 = (gcnew System::Windows::Forms::Label());
			this->tConst8 = (gcnew System::Windows::Forms::TextBox());
			this->lConst8 = (gcnew System::Windows::Forms::Label());
			this->dgAffinityMatrix8 = (gcnew System::Windows::Forms::DataGridView());
			this->tConst10 = (gcnew System::Windows::Forms::TextBox());
			this->tPercNeighborsUse5 = (gcnew System::Windows::Forms::TextBox());
			this->tElasticy5 = (gcnew System::Windows::Forms::TextBox());
			this->tPercNeighborsUse10 = (gcnew System::Windows::Forms::TextBox());
			this->lPercNeighborsUse10 = (gcnew System::Windows::Forms::Label());
			this->tElasticy10 = (gcnew System::Windows::Forms::TextBox());
			this->lElasticy10 = (gcnew System::Windows::Forms::Label());
			this->dgBetas10 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas10 = (gcnew System::Windows::Forms::Label());
			this->lConst10 = (gcnew System::Windows::Forms::Label());
			this->tPercNeighborsUse9 = (gcnew System::Windows::Forms::TextBox());
			this->lPercNeighborsUse9 = (gcnew System::Windows::Forms::Label());
			this->tElasticy9 = (gcnew System::Windows::Forms::TextBox());
			this->lElasticy9 = (gcnew System::Windows::Forms::Label());
			this->tRegion10 = (gcnew System::Windows::Forms::TabPage());
			this->lLegend10 = (gcnew System::Windows::Forms::Label());
			this->lAffinityMatrix10 = (gcnew System::Windows::Forms::Label());
			this->dgAffinityMatrix10 = (gcnew System::Windows::Forms::DataGridView());
			this->dgBetas9 = (gcnew System::Windows::Forms::DataGridView());
			this->tConst9 = (gcnew System::Windows::Forms::TextBox());
			this->lConst9 = (gcnew System::Windows::Forms::Label());
			this->lPercNeighborsUse5 = (gcnew System::Windows::Forms::Label());
			this->tRegion9 = (gcnew System::Windows::Forms::TabPage());
			this->lLegend9 = (gcnew System::Windows::Forms::Label());
			this->lAffinityMatrix9 = (gcnew System::Windows::Forms::Label());
			this->lBetas9 = (gcnew System::Windows::Forms::Label());
			this->dgAffinityMatrix9 = (gcnew System::Windows::Forms::DataGridView());
			this->lElasticy5 = (gcnew System::Windows::Forms::Label());
			this->tRegion5 = (gcnew System::Windows::Forms::TabPage());
			this->lLegend5 = (gcnew System::Windows::Forms::Label());
			this->lAffinityMatrix5 = (gcnew System::Windows::Forms::Label());
			this->dgBetas5 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas5 = (gcnew System::Windows::Forms::Label());
			this->tConst5 = (gcnew System::Windows::Forms::TextBox());
			this->lConst5 = (gcnew System::Windows::Forms::Label());
			this->dgAffinityMatrix5 = (gcnew System::Windows::Forms::DataGridView());
			this->tPercNeighborsUse2 = (gcnew System::Windows::Forms::TextBox());
			this->lPercNeighborsUse2 = (gcnew System::Windows::Forms::Label());
			this->tElasticy2 = (gcnew System::Windows::Forms::TextBox());
			this->lElasticy2 = (gcnew System::Windows::Forms::Label());
			this->tRegion2 = (gcnew System::Windows::Forms::TabPage());
			this->lLegend2 = (gcnew System::Windows::Forms::Label());
			this->lAffinityMatrix2 = (gcnew System::Windows::Forms::Label());
			this->dgBetas2 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas2 = (gcnew System::Windows::Forms::Label());
			this->tConst2 = (gcnew System::Windows::Forms::TextBox());
			this->lConst2 = (gcnew System::Windows::Forms::Label());
			this->dgAffinityMatrix2 = (gcnew System::Windows::Forms::DataGridView());
			this->tPercNeighborsUse = (gcnew System::Windows::Forms::TextBox());
			this->lPercNeighborsUse = (gcnew System::Windows::Forms::Label());
			this->tElasticy = (gcnew System::Windows::Forms::TextBox());
			this->tcRegions = (gcnew System::Windows::Forms::TabControl());
			this->tRegion1 = (gcnew System::Windows::Forms::TabPage());
			this->lLegend = (gcnew System::Windows::Forms::Label());
			this->lAffinityMatrix = (gcnew System::Windows::Forms::Label());
			this->lElasticy = (gcnew System::Windows::Forms::Label());
			this->dgBetas = (gcnew System::Windows::Forms::DataGridView());
			this->tConst = (gcnew System::Windows::Forms::TextBox());
			this->lConst = (gcnew System::Windows::Forms::Label());
			this->lBetas = (gcnew System::Windows::Forms::Label());
			this->dgAffinityMatrix = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion3 = (gcnew System::Windows::Forms::TabPage());
			this->lLegend3 = (gcnew System::Windows::Forms::Label());
			this->lAffinityMatrix3 = (gcnew System::Windows::Forms::Label());
			this->tPercNeighborsUse3 = (gcnew System::Windows::Forms::TextBox());
			this->lPercNeighborsUse3 = (gcnew System::Windows::Forms::Label());
			this->tElasticy3 = (gcnew System::Windows::Forms::TextBox());
			this->lElasticy3 = (gcnew System::Windows::Forms::Label());
			this->dgBetas3 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas3 = (gcnew System::Windows::Forms::Label());
			this->tConst3 = (gcnew System::Windows::Forms::TextBox());
			this->lConst3 = (gcnew System::Windows::Forms::Label());
			this->dgAffinityMatrix3 = (gcnew System::Windows::Forms::DataGridView());
			this->tRegion4 = (gcnew System::Windows::Forms::TabPage());
			this->lLegend4 = (gcnew System::Windows::Forms::Label());
			this->lAffinityMatrix4 = (gcnew System::Windows::Forms::Label());
			this->tPercNeighborsUse4 = (gcnew System::Windows::Forms::TextBox());
			this->lPercNeighborsUse4 = (gcnew System::Windows::Forms::Label());
			this->tElasticy4 = (gcnew System::Windows::Forms::TextBox());
			this->lElasticy4 = (gcnew System::Windows::Forms::Label());
			this->dgBetas4 = (gcnew System::Windows::Forms::DataGridView());
			this->lBetas4 = (gcnew System::Windows::Forms::Label());
			this->tConst4 = (gcnew System::Windows::Forms::TextBox());
			this->lConst4 = (gcnew System::Windows::Forms::Label());
			this->dgAffinityMatrix4 = (gcnew System::Windows::Forms::DataGridView());
			this->bDeleteRegression = (gcnew System::Windows::Forms::Button());
			this->tLUT = (gcnew System::Windows::Forms::TextBox());
			this->bAddBetas = (gcnew System::Windows::Forms::Button());
			this->lvLUT = (gcnew System::Windows::Forms::ListView());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas7))->BeginInit();
			this->tRegion6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix6))->BeginInit();
			this->tRegion7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix7))->BeginInit();
			this->tRegion8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas10))->BeginInit();
			this->tRegion10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas9))->BeginInit();
			this->tRegion9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix9))->BeginInit();
			this->tRegion5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix5))->BeginInit();
			this->tRegion2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix2))->BeginInit();
			this->tcRegions->SuspendLayout();
			this->tRegion1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix))->BeginInit();
			this->tRegion3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix3))->BeginInit();
			this->tRegion4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// tPercNeighborsUse8
			// 
			this->tPercNeighborsUse8->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPercNeighborsUse8->Location = System::Drawing::Point(280, 82);
			this->tPercNeighborsUse8->Name = L"tPercNeighborsUse8";
			this->tPercNeighborsUse8->Size = System::Drawing::Size(72, 20);
			this->tPercNeighborsUse8->TabIndex = 96;
			this->tPercNeighborsUse8->Text = L"0.5";
			this->tPercNeighborsUse8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPercNeighborsUse8->Visible = false;
			this->tPercNeighborsUse8->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lBetas7
			// 
			this->lBetas7->AutoSize = true;
			this->lBetas7->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas7->Location = System::Drawing::Point(206, 116);
			this->lBetas7->Name = L"lBetas7";
			this->lBetas7->Size = System::Drawing::Size(69, 23);
			this->lBetas7->TabIndex = 91;
			this->lBetas7->Text = L"Fatores";
			this->lBetas7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas7->Visible = false;
			// 
			// tConst7
			// 
			this->tConst7->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst7->Location = System::Drawing::Point(191, 23);
			this->tConst7->Name = L"tConst7";
			this->tConst7->Size = System::Drawing::Size(161, 20);
			this->tConst7->TabIndex = 90;
			this->tConst7->Text = L"0.01";
			this->tConst7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst7->Visible = false;
			this->tConst7->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lConst7
			// 
			this->lConst7->AutoSize = true;
			this->lConst7->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst7->Location = System::Drawing::Point(130, 22);
			this->lConst7->Name = L"lConst7";
			this->lConst7->Size = System::Drawing::Size(55, 23);
			this->lConst7->TabIndex = 89;
			this->lConst7->Text = L"Const";
			this->lConst7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst7->Visible = false;
			// 
			// tPercNeighborsUse6
			// 
			this->tPercNeighborsUse6->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPercNeighborsUse6->Location = System::Drawing::Point(280, 82);
			this->tPercNeighborsUse6->Name = L"tPercNeighborsUse6";
			this->tPercNeighborsUse6->Size = System::Drawing::Size(72, 20);
			this->tPercNeighborsUse6->TabIndex = 96;
			this->tPercNeighborsUse6->Text = L"0.5";
			this->tPercNeighborsUse6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPercNeighborsUse6->Visible = false;
			this->tPercNeighborsUse6->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lPercNeighborsUse6
			// 
			this->lPercNeighborsUse6->AutoSize = true;
			this->lPercNeighborsUse6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPercNeighborsUse6->Location = System::Drawing::Point(108, 82);
			this->lPercNeighborsUse6->Name = L"lPercNeighborsUse6";
			this->lPercNeighborsUse6->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lPercNeighborsUse6->Size = System::Drawing::Size(157, 23);
			this->lPercNeighborsUse6->TabIndex = 95;
			this->lPercNeighborsUse6->Text = L"percNeighborsUse";
			this->lPercNeighborsUse6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPercNeighborsUse6->Visible = false;
			// 
			// tElasticy6
			// 
			this->tElasticy6->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tElasticy6->Location = System::Drawing::Point(191, 54);
			this->tElasticy6->Name = L"tElasticy6";
			this->tElasticy6->Size = System::Drawing::Size(161, 20);
			this->tElasticy6->TabIndex = 94;
			this->tElasticy6->Text = L"0.5";
			this->tElasticy6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tElasticy6->Visible = false;
			this->tElasticy6->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lElasticy6
			// 
			this->lElasticy6->AutoSize = true;
			this->lElasticy6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lElasticy6->Location = System::Drawing::Point(108, 52);
			this->lElasticy6->Name = L"lElasticy6";
			this->lElasticy6->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lElasticy6->Size = System::Drawing::Size(81, 23);
			this->lElasticy6->TabIndex = 93;
			this->lElasticy6->Text = L"Elasticity";
			this->lElasticy6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lElasticy6->Visible = false;
			// 
			// dgBetas6
			// 
			this->dgBetas6->AllowUserToResizeColumns = false;
			this->dgBetas6->AllowUserToResizeRows = false;
			this->dgBetas6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas6->Location = System::Drawing::Point(110, 147);
			this->dgBetas6->Name = L"dgBetas6";
			this->dgBetas6->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas6->Size = System::Drawing::Size(245, 209);
			this->dgBetas6->TabIndex = 1;
			this->dgBetas6->Visible = false;
			this->dgBetas6->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_AttractRepulseLogisticRegression::dgBetas_KeyDown);
			// 
			// lBetas6
			// 
			this->lBetas6->AutoSize = true;
			this->lBetas6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas6->Location = System::Drawing::Point(206, 116);
			this->lBetas6->Name = L"lBetas6";
			this->lBetas6->Size = System::Drawing::Size(69, 23);
			this->lBetas6->TabIndex = 91;
			this->lBetas6->Text = L"Fatores";
			this->lBetas6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas6->Visible = false;
			// 
			// tConst6
			// 
			this->tConst6->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst6->Location = System::Drawing::Point(191, 23);
			this->tConst6->Name = L"tConst6";
			this->tConst6->Size = System::Drawing::Size(161, 20);
			this->tConst6->TabIndex = 90;
			this->tConst6->Text = L"0.01";
			this->tConst6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst6->Visible = false;
			this->tConst6->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// tElasticy7
			// 
			this->tElasticy7->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tElasticy7->Location = System::Drawing::Point(191, 54);
			this->tElasticy7->Name = L"tElasticy7";
			this->tElasticy7->Size = System::Drawing::Size(161, 20);
			this->tElasticy7->TabIndex = 94;
			this->tElasticy7->Text = L"0.5";
			this->tElasticy7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tElasticy7->Visible = false;
			this->tElasticy7->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lElasticy7
			// 
			this->lElasticy7->AutoSize = true;
			this->lElasticy7->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lElasticy7->Location = System::Drawing::Point(108, 52);
			this->lElasticy7->Name = L"lElasticy7";
			this->lElasticy7->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lElasticy7->Size = System::Drawing::Size(81, 23);
			this->lElasticy7->TabIndex = 93;
			this->lElasticy7->Text = L"Elasticity";
			this->lElasticy7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lElasticy7->Visible = false;
			// 
			// dgBetas7
			// 
			this->dgBetas7->AllowUserToResizeColumns = false;
			this->dgBetas7->AllowUserToResizeRows = false;
			this->dgBetas7->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas7->Location = System::Drawing::Point(110, 147);
			this->dgBetas7->Name = L"dgBetas7";
			this->dgBetas7->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas7->Size = System::Drawing::Size(245, 209);
			this->dgBetas7->TabIndex = 1;
			this->dgBetas7->Visible = false;
			this->dgBetas7->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_AttractRepulseLogisticRegression::dgBetas_KeyDown);
			// 
			// lConst6
			// 
			this->lConst6->AutoSize = true;
			this->lConst6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst6->Location = System::Drawing::Point(130, 22);
			this->lConst6->Name = L"lConst6";
			this->lConst6->Size = System::Drawing::Size(55, 23);
			this->lConst6->TabIndex = 89;
			this->lConst6->Text = L"Const";
			this->lConst6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst6->Visible = false;
			// 
			// tPercNeighborsUse7
			// 
			this->tPercNeighborsUse7->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPercNeighborsUse7->Location = System::Drawing::Point(280, 82);
			this->tPercNeighborsUse7->Name = L"tPercNeighborsUse7";
			this->tPercNeighborsUse7->Size = System::Drawing::Size(72, 20);
			this->tPercNeighborsUse7->TabIndex = 96;
			this->tPercNeighborsUse7->Text = L"0.5";
			this->tPercNeighborsUse7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPercNeighborsUse7->Visible = false;
			this->tPercNeighborsUse7->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// tRegion6
			// 
			this->tRegion6->Controls->Add(this->lLegend6);
			this->tRegion6->Controls->Add(this->lAffinityMatrix6);
			this->tRegion6->Controls->Add(this->tPercNeighborsUse6);
			this->tRegion6->Controls->Add(this->lPercNeighborsUse6);
			this->tRegion6->Controls->Add(this->tElasticy6);
			this->tRegion6->Controls->Add(this->lElasticy6);
			this->tRegion6->Controls->Add(this->dgBetas6);
			this->tRegion6->Controls->Add(this->lBetas6);
			this->tRegion6->Controls->Add(this->tConst6);
			this->tRegion6->Controls->Add(this->lConst6);
			this->tRegion6->Controls->Add(this->dgAffinityMatrix6);
			this->tRegion6->Location = System::Drawing::Point(4, 22);
			this->tRegion6->Name = L"tRegion6";
			this->tRegion6->Size = System::Drawing::Size(492, 363);
			this->tRegion6->TabIndex = 5;
			this->tRegion6->Text = L"+";
			this->tRegion6->UseVisualStyleBackColor = true;
			// 
			// lLegend6
			// 
			this->lLegend6->AutoSize = true;
			this->lLegend6->Location = System::Drawing::Point(9, 315);
			this->lLegend6->Name = L"lLegend6";
			this->lLegend6->Size = System::Drawing::Size(29, 13);
			this->lLegend6->TabIndex = 100;
			this->lLegend6->Text = L"label";
			this->lLegend6->Visible = false;
			// 
			// lAffinityMatrix6
			// 
			this->lAffinityMatrix6->AutoSize = true;
			this->lAffinityMatrix6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAffinityMatrix6->Location = System::Drawing::Point(188, 57);
			this->lAffinityMatrix6->Name = L"lAffinityMatrix6";
			this->lAffinityMatrix6->Size = System::Drawing::Size(127, 23);
			this->lAffinityMatrix6->TabIndex = 98;
			this->lAffinityMatrix6->Text = L"Affinity Matrix";
			this->lAffinityMatrix6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// dgAffinityMatrix6
			// 
			this->dgAffinityMatrix6->AllowUserToAddRows = false;
			this->dgAffinityMatrix6->AllowUserToDeleteRows = false;
			this->dgAffinityMatrix6->AllowUserToResizeColumns = false;
			this->dgAffinityMatrix6->AllowUserToResizeRows = false;
			this->dgAffinityMatrix6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAffinityMatrix6->Location = System::Drawing::Point(9, 99);
			this->dgAffinityMatrix6->Name = L"dgAffinityMatrix6";
			this->dgAffinityMatrix6->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAffinityMatrix6->Size = System::Drawing::Size(475, 209);
			this->dgAffinityMatrix6->TabIndex = 99;
			// 
			// tRegion7
			// 
			this->tRegion7->Controls->Add(this->lLegend7);
			this->tRegion7->Controls->Add(this->lAffinityMatrix7);
			this->tRegion7->Controls->Add(this->tPercNeighborsUse7);
			this->tRegion7->Controls->Add(this->lPercNeighborsUse7);
			this->tRegion7->Controls->Add(this->tElasticy7);
			this->tRegion7->Controls->Add(this->lElasticy7);
			this->tRegion7->Controls->Add(this->dgBetas7);
			this->tRegion7->Controls->Add(this->lBetas7);
			this->tRegion7->Controls->Add(this->tConst7);
			this->tRegion7->Controls->Add(this->lConst7);
			this->tRegion7->Controls->Add(this->dgAffinityMatrix7);
			this->tRegion7->Location = System::Drawing::Point(4, 22);
			this->tRegion7->Name = L"tRegion7";
			this->tRegion7->Size = System::Drawing::Size(492, 363);
			this->tRegion7->TabIndex = 6;
			this->tRegion7->Text = L"+";
			this->tRegion7->UseVisualStyleBackColor = true;
			// 
			// lLegend7
			// 
			this->lLegend7->AutoSize = true;
			this->lLegend7->Location = System::Drawing::Point(9, 315);
			this->lLegend7->Name = L"lLegend7";
			this->lLegend7->Size = System::Drawing::Size(29, 13);
			this->lLegend7->TabIndex = 100;
			this->lLegend7->Text = L"label";
			this->lLegend7->Visible = false;
			// 
			// lAffinityMatrix7
			// 
			this->lAffinityMatrix7->AutoSize = true;
			this->lAffinityMatrix7->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAffinityMatrix7->Location = System::Drawing::Point(188, 57);
			this->lAffinityMatrix7->Name = L"lAffinityMatrix7";
			this->lAffinityMatrix7->Size = System::Drawing::Size(127, 23);
			this->lAffinityMatrix7->TabIndex = 98;
			this->lAffinityMatrix7->Text = L"Affinity Matrix";
			this->lAffinityMatrix7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lPercNeighborsUse7
			// 
			this->lPercNeighborsUse7->AutoSize = true;
			this->lPercNeighborsUse7->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPercNeighborsUse7->Location = System::Drawing::Point(108, 82);
			this->lPercNeighborsUse7->Name = L"lPercNeighborsUse7";
			this->lPercNeighborsUse7->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lPercNeighborsUse7->Size = System::Drawing::Size(157, 23);
			this->lPercNeighborsUse7->TabIndex = 95;
			this->lPercNeighborsUse7->Text = L"percNeighborsUse";
			this->lPercNeighborsUse7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPercNeighborsUse7->Visible = false;
			// 
			// dgAffinityMatrix7
			// 
			this->dgAffinityMatrix7->AllowUserToAddRows = false;
			this->dgAffinityMatrix7->AllowUserToDeleteRows = false;
			this->dgAffinityMatrix7->AllowUserToResizeColumns = false;
			this->dgAffinityMatrix7->AllowUserToResizeRows = false;
			this->dgAffinityMatrix7->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAffinityMatrix7->Location = System::Drawing::Point(9, 99);
			this->dgAffinityMatrix7->Name = L"dgAffinityMatrix7";
			this->dgAffinityMatrix7->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAffinityMatrix7->Size = System::Drawing::Size(475, 209);
			this->dgAffinityMatrix7->TabIndex = 99;
			// 
			// tRegion8
			// 
			this->tRegion8->Controls->Add(this->lLegend8);
			this->tRegion8->Controls->Add(this->lAffinityMatrix8);
			this->tRegion8->Controls->Add(this->tPercNeighborsUse8);
			this->tRegion8->Controls->Add(this->lPercNeighborsUse8);
			this->tRegion8->Controls->Add(this->tElasticy8);
			this->tRegion8->Controls->Add(this->lElasticy8);
			this->tRegion8->Controls->Add(this->dgBetas8);
			this->tRegion8->Controls->Add(this->lBetas8);
			this->tRegion8->Controls->Add(this->tConst8);
			this->tRegion8->Controls->Add(this->lConst8);
			this->tRegion8->Controls->Add(this->dgAffinityMatrix8);
			this->tRegion8->Location = System::Drawing::Point(4, 22);
			this->tRegion8->Name = L"tRegion8";
			this->tRegion8->Size = System::Drawing::Size(492, 363);
			this->tRegion8->TabIndex = 7;
			this->tRegion8->Text = L"+";
			this->tRegion8->UseVisualStyleBackColor = true;
			// 
			// lLegend8
			// 
			this->lLegend8->AutoSize = true;
			this->lLegend8->Location = System::Drawing::Point(9, 315);
			this->lLegend8->Name = L"lLegend8";
			this->lLegend8->Size = System::Drawing::Size(29, 13);
			this->lLegend8->TabIndex = 100;
			this->lLegend8->Text = L"label";
			this->lLegend8->Visible = false;
			// 
			// lAffinityMatrix8
			// 
			this->lAffinityMatrix8->AutoSize = true;
			this->lAffinityMatrix8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAffinityMatrix8->Location = System::Drawing::Point(188, 57);
			this->lAffinityMatrix8->Name = L"lAffinityMatrix8";
			this->lAffinityMatrix8->Size = System::Drawing::Size(127, 23);
			this->lAffinityMatrix8->TabIndex = 98;
			this->lAffinityMatrix8->Text = L"Affinity Matrix";
			this->lAffinityMatrix8->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lPercNeighborsUse8
			// 
			this->lPercNeighborsUse8->AutoSize = true;
			this->lPercNeighborsUse8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPercNeighborsUse8->Location = System::Drawing::Point(108, 82);
			this->lPercNeighborsUse8->Name = L"lPercNeighborsUse8";
			this->lPercNeighborsUse8->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lPercNeighborsUse8->Size = System::Drawing::Size(157, 23);
			this->lPercNeighborsUse8->TabIndex = 95;
			this->lPercNeighborsUse8->Text = L"percNeighborsUse";
			this->lPercNeighborsUse8->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPercNeighborsUse8->Visible = false;
			// 
			// tElasticy8
			// 
			this->tElasticy8->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tElasticy8->Location = System::Drawing::Point(191, 54);
			this->tElasticy8->Name = L"tElasticy8";
			this->tElasticy8->Size = System::Drawing::Size(161, 20);
			this->tElasticy8->TabIndex = 94;
			this->tElasticy8->Text = L"0.5";
			this->tElasticy8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tElasticy8->Visible = false;
			this->tElasticy8->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lElasticy8
			// 
			this->lElasticy8->AutoSize = true;
			this->lElasticy8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lElasticy8->Location = System::Drawing::Point(108, 52);
			this->lElasticy8->Name = L"lElasticy8";
			this->lElasticy8->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lElasticy8->Size = System::Drawing::Size(81, 23);
			this->lElasticy8->TabIndex = 93;
			this->lElasticy8->Text = L"Elasticity";
			this->lElasticy8->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lElasticy8->Visible = false;
			// 
			// dgBetas8
			// 
			this->dgBetas8->AllowUserToResizeColumns = false;
			this->dgBetas8->AllowUserToResizeRows = false;
			this->dgBetas8->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas8->Location = System::Drawing::Point(110, 147);
			this->dgBetas8->Name = L"dgBetas8";
			this->dgBetas8->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas8->Size = System::Drawing::Size(245, 209);
			this->dgBetas8->TabIndex = 1;
			this->dgBetas8->Visible = false;
			this->dgBetas8->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_AttractRepulseLogisticRegression::dgBetas_KeyDown);
			// 
			// lBetas8
			// 
			this->lBetas8->AutoSize = true;
			this->lBetas8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas8->Location = System::Drawing::Point(206, 116);
			this->lBetas8->Name = L"lBetas8";
			this->lBetas8->Size = System::Drawing::Size(69, 23);
			this->lBetas8->TabIndex = 91;
			this->lBetas8->Text = L"Fatores";
			this->lBetas8->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas8->Visible = false;
			// 
			// tConst8
			// 
			this->tConst8->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst8->Location = System::Drawing::Point(191, 23);
			this->tConst8->Name = L"tConst8";
			this->tConst8->Size = System::Drawing::Size(161, 20);
			this->tConst8->TabIndex = 90;
			this->tConst8->Text = L"0.01";
			this->tConst8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst8->Visible = false;
			this->tConst8->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lConst8
			// 
			this->lConst8->AutoSize = true;
			this->lConst8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst8->Location = System::Drawing::Point(130, 22);
			this->lConst8->Name = L"lConst8";
			this->lConst8->Size = System::Drawing::Size(55, 23);
			this->lConst8->TabIndex = 89;
			this->lConst8->Text = L"Const";
			this->lConst8->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst8->Visible = false;
			// 
			// dgAffinityMatrix8
			// 
			this->dgAffinityMatrix8->AllowUserToAddRows = false;
			this->dgAffinityMatrix8->AllowUserToDeleteRows = false;
			this->dgAffinityMatrix8->AllowUserToResizeColumns = false;
			this->dgAffinityMatrix8->AllowUserToResizeRows = false;
			this->dgAffinityMatrix8->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAffinityMatrix8->Location = System::Drawing::Point(9, 99);
			this->dgAffinityMatrix8->Name = L"dgAffinityMatrix8";
			this->dgAffinityMatrix8->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAffinityMatrix8->Size = System::Drawing::Size(475, 209);
			this->dgAffinityMatrix8->TabIndex = 99;
			// 
			// tConst10
			// 
			this->tConst10->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst10->Location = System::Drawing::Point(191, 23);
			this->tConst10->Name = L"tConst10";
			this->tConst10->Size = System::Drawing::Size(161, 20);
			this->tConst10->TabIndex = 90;
			this->tConst10->Text = L"0.01";
			this->tConst10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst10->Visible = false;
			this->tConst10->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// tPercNeighborsUse5
			// 
			this->tPercNeighborsUse5->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPercNeighborsUse5->Location = System::Drawing::Point(280, 82);
			this->tPercNeighborsUse5->Name = L"tPercNeighborsUse5";
			this->tPercNeighborsUse5->Size = System::Drawing::Size(72, 20);
			this->tPercNeighborsUse5->TabIndex = 96;
			this->tPercNeighborsUse5->Text = L"0.5";
			this->tPercNeighborsUse5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPercNeighborsUse5->Visible = false;
			this->tPercNeighborsUse5->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// tElasticy5
			// 
			this->tElasticy5->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tElasticy5->Location = System::Drawing::Point(191, 54);
			this->tElasticy5->Name = L"tElasticy5";
			this->tElasticy5->Size = System::Drawing::Size(161, 20);
			this->tElasticy5->TabIndex = 94;
			this->tElasticy5->Text = L"0.5";
			this->tElasticy5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tElasticy5->Visible = false;
			this->tElasticy5->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// tPercNeighborsUse10
			// 
			this->tPercNeighborsUse10->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPercNeighborsUse10->Location = System::Drawing::Point(280, 82);
			this->tPercNeighborsUse10->Name = L"tPercNeighborsUse10";
			this->tPercNeighborsUse10->Size = System::Drawing::Size(72, 20);
			this->tPercNeighborsUse10->TabIndex = 96;
			this->tPercNeighborsUse10->Text = L"0.5";
			this->tPercNeighborsUse10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPercNeighborsUse10->Visible = false;
			this->tPercNeighborsUse10->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lPercNeighborsUse10
			// 
			this->lPercNeighborsUse10->AutoSize = true;
			this->lPercNeighborsUse10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPercNeighborsUse10->Location = System::Drawing::Point(108, 82);
			this->lPercNeighborsUse10->Name = L"lPercNeighborsUse10";
			this->lPercNeighborsUse10->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lPercNeighborsUse10->Size = System::Drawing::Size(157, 23);
			this->lPercNeighborsUse10->TabIndex = 95;
			this->lPercNeighborsUse10->Text = L"percNeighborsUse";
			this->lPercNeighborsUse10->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPercNeighborsUse10->Visible = false;
			// 
			// tElasticy10
			// 
			this->tElasticy10->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tElasticy10->Location = System::Drawing::Point(191, 54);
			this->tElasticy10->Name = L"tElasticy10";
			this->tElasticy10->Size = System::Drawing::Size(161, 20);
			this->tElasticy10->TabIndex = 94;
			this->tElasticy10->Text = L"0.5";
			this->tElasticy10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tElasticy10->Visible = false;
			this->tElasticy10->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lElasticy10
			// 
			this->lElasticy10->AutoSize = true;
			this->lElasticy10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lElasticy10->Location = System::Drawing::Point(108, 52);
			this->lElasticy10->Name = L"lElasticy10";
			this->lElasticy10->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lElasticy10->Size = System::Drawing::Size(81, 23);
			this->lElasticy10->TabIndex = 93;
			this->lElasticy10->Text = L"Elasticity";
			this->lElasticy10->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lElasticy10->Visible = false;
			// 
			// dgBetas10
			// 
			this->dgBetas10->AllowUserToResizeColumns = false;
			this->dgBetas10->AllowUserToResizeRows = false;
			this->dgBetas10->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas10->Location = System::Drawing::Point(110, 147);
			this->dgBetas10->Name = L"dgBetas10";
			this->dgBetas10->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas10->Size = System::Drawing::Size(245, 209);
			this->dgBetas10->TabIndex = 1;
			this->dgBetas10->Visible = false;
			this->dgBetas10->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_AttractRepulseLogisticRegression::dgBetas_KeyDown);
			// 
			// lBetas10
			// 
			this->lBetas10->AutoSize = true;
			this->lBetas10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas10->Location = System::Drawing::Point(206, 116);
			this->lBetas10->Name = L"lBetas10";
			this->lBetas10->Size = System::Drawing::Size(69, 23);
			this->lBetas10->TabIndex = 91;
			this->lBetas10->Text = L"Fatores";
			this->lBetas10->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas10->Visible = false;
			// 
			// lConst10
			// 
			this->lConst10->AutoSize = true;
			this->lConst10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst10->Location = System::Drawing::Point(130, 22);
			this->lConst10->Name = L"lConst10";
			this->lConst10->Size = System::Drawing::Size(55, 23);
			this->lConst10->TabIndex = 89;
			this->lConst10->Text = L"Const";
			this->lConst10->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst10->Visible = false;
			// 
			// tPercNeighborsUse9
			// 
			this->tPercNeighborsUse9->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPercNeighborsUse9->Location = System::Drawing::Point(280, 82);
			this->tPercNeighborsUse9->Name = L"tPercNeighborsUse9";
			this->tPercNeighborsUse9->Size = System::Drawing::Size(72, 20);
			this->tPercNeighborsUse9->TabIndex = 96;
			this->tPercNeighborsUse9->Text = L"0.5";
			this->tPercNeighborsUse9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPercNeighborsUse9->Visible = false;
			this->tPercNeighborsUse9->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lPercNeighborsUse9
			// 
			this->lPercNeighborsUse9->AutoSize = true;
			this->lPercNeighborsUse9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPercNeighborsUse9->Location = System::Drawing::Point(108, 82);
			this->lPercNeighborsUse9->Name = L"lPercNeighborsUse9";
			this->lPercNeighborsUse9->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lPercNeighborsUse9->Size = System::Drawing::Size(157, 23);
			this->lPercNeighborsUse9->TabIndex = 95;
			this->lPercNeighborsUse9->Text = L"percNeighborsUse";
			this->lPercNeighborsUse9->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPercNeighborsUse9->Visible = false;
			// 
			// tElasticy9
			// 
			this->tElasticy9->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tElasticy9->Location = System::Drawing::Point(191, 54);
			this->tElasticy9->Name = L"tElasticy9";
			this->tElasticy9->Size = System::Drawing::Size(161, 20);
			this->tElasticy9->TabIndex = 94;
			this->tElasticy9->Text = L"0.5";
			this->tElasticy9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tElasticy9->Visible = false;
			this->tElasticy9->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lElasticy9
			// 
			this->lElasticy9->AutoSize = true;
			this->lElasticy9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lElasticy9->Location = System::Drawing::Point(108, 52);
			this->lElasticy9->Name = L"lElasticy9";
			this->lElasticy9->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lElasticy9->Size = System::Drawing::Size(81, 23);
			this->lElasticy9->TabIndex = 93;
			this->lElasticy9->Text = L"Elasticity";
			this->lElasticy9->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lElasticy9->Visible = false;
			// 
			// tRegion10
			// 
			this->tRegion10->Controls->Add(this->lLegend10);
			this->tRegion10->Controls->Add(this->lAffinityMatrix10);
			this->tRegion10->Controls->Add(this->tPercNeighborsUse10);
			this->tRegion10->Controls->Add(this->lPercNeighborsUse10);
			this->tRegion10->Controls->Add(this->tElasticy10);
			this->tRegion10->Controls->Add(this->lElasticy10);
			this->tRegion10->Controls->Add(this->dgBetas10);
			this->tRegion10->Controls->Add(this->lBetas10);
			this->tRegion10->Controls->Add(this->tConst10);
			this->tRegion10->Controls->Add(this->lConst10);
			this->tRegion10->Controls->Add(this->dgAffinityMatrix10);
			this->tRegion10->Location = System::Drawing::Point(4, 22);
			this->tRegion10->Name = L"tRegion10";
			this->tRegion10->Size = System::Drawing::Size(492, 363);
			this->tRegion10->TabIndex = 9;
			this->tRegion10->Text = L"+";
			this->tRegion10->UseVisualStyleBackColor = true;
			// 
			// lLegend10
			// 
			this->lLegend10->AutoSize = true;
			this->lLegend10->Location = System::Drawing::Point(9, 315);
			this->lLegend10->Name = L"lLegend10";
			this->lLegend10->Size = System::Drawing::Size(29, 13);
			this->lLegend10->TabIndex = 100;
			this->lLegend10->Text = L"label";
			this->lLegend10->Visible = false;
			// 
			// lAffinityMatrix10
			// 
			this->lAffinityMatrix10->AutoSize = true;
			this->lAffinityMatrix10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAffinityMatrix10->Location = System::Drawing::Point(188, 57);
			this->lAffinityMatrix10->Name = L"lAffinityMatrix10";
			this->lAffinityMatrix10->Size = System::Drawing::Size(127, 23);
			this->lAffinityMatrix10->TabIndex = 98;
			this->lAffinityMatrix10->Text = L"Affinity Matrix";
			this->lAffinityMatrix10->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// dgAffinityMatrix10
			// 
			this->dgAffinityMatrix10->AllowUserToAddRows = false;
			this->dgAffinityMatrix10->AllowUserToDeleteRows = false;
			this->dgAffinityMatrix10->AllowUserToResizeColumns = false;
			this->dgAffinityMatrix10->AllowUserToResizeRows = false;
			this->dgAffinityMatrix10->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAffinityMatrix10->Location = System::Drawing::Point(9, 99);
			this->dgAffinityMatrix10->Name = L"dgAffinityMatrix10";
			this->dgAffinityMatrix10->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAffinityMatrix10->Size = System::Drawing::Size(475, 209);
			this->dgAffinityMatrix10->TabIndex = 99;
			// 
			// dgBetas9
			// 
			this->dgBetas9->AllowUserToResizeColumns = false;
			this->dgBetas9->AllowUserToResizeRows = false;
			this->dgBetas9->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas9->Location = System::Drawing::Point(110, 147);
			this->dgBetas9->Name = L"dgBetas9";
			this->dgBetas9->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas9->Size = System::Drawing::Size(245, 209);
			this->dgBetas9->TabIndex = 1;
			this->dgBetas9->Visible = false;
			this->dgBetas9->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_AttractRepulseLogisticRegression::dgBetas_KeyDown);
			// 
			// tConst9
			// 
			this->tConst9->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst9->Location = System::Drawing::Point(191, 23);
			this->tConst9->Name = L"tConst9";
			this->tConst9->Size = System::Drawing::Size(161, 20);
			this->tConst9->TabIndex = 90;
			this->tConst9->Text = L"0.01";
			this->tConst9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst9->Visible = false;
			this->tConst9->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lConst9
			// 
			this->lConst9->AutoSize = true;
			this->lConst9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst9->Location = System::Drawing::Point(130, 22);
			this->lConst9->Name = L"lConst9";
			this->lConst9->Size = System::Drawing::Size(55, 23);
			this->lConst9->TabIndex = 89;
			this->lConst9->Text = L"Const";
			this->lConst9->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst9->Visible = false;
			// 
			// lPercNeighborsUse5
			// 
			this->lPercNeighborsUse5->AutoSize = true;
			this->lPercNeighborsUse5->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPercNeighborsUse5->Location = System::Drawing::Point(108, 82);
			this->lPercNeighborsUse5->Name = L"lPercNeighborsUse5";
			this->lPercNeighborsUse5->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lPercNeighborsUse5->Size = System::Drawing::Size(157, 23);
			this->lPercNeighborsUse5->TabIndex = 95;
			this->lPercNeighborsUse5->Text = L"percNeighborsUse";
			this->lPercNeighborsUse5->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPercNeighborsUse5->Visible = false;
			// 
			// tRegion9
			// 
			this->tRegion9->Controls->Add(this->lLegend9);
			this->tRegion9->Controls->Add(this->lAffinityMatrix9);
			this->tRegion9->Controls->Add(this->tPercNeighborsUse9);
			this->tRegion9->Controls->Add(this->lPercNeighborsUse9);
			this->tRegion9->Controls->Add(this->tElasticy9);
			this->tRegion9->Controls->Add(this->lElasticy9);
			this->tRegion9->Controls->Add(this->dgBetas9);
			this->tRegion9->Controls->Add(this->lBetas9);
			this->tRegion9->Controls->Add(this->tConst9);
			this->tRegion9->Controls->Add(this->lConst9);
			this->tRegion9->Controls->Add(this->dgAffinityMatrix9);
			this->tRegion9->Location = System::Drawing::Point(4, 22);
			this->tRegion9->Name = L"tRegion9";
			this->tRegion9->Size = System::Drawing::Size(492, 363);
			this->tRegion9->TabIndex = 8;
			this->tRegion9->Text = L"+";
			this->tRegion9->UseVisualStyleBackColor = true;
			// 
			// lLegend9
			// 
			this->lLegend9->AutoSize = true;
			this->lLegend9->Location = System::Drawing::Point(9, 315);
			this->lLegend9->Name = L"lLegend9";
			this->lLegend9->Size = System::Drawing::Size(29, 13);
			this->lLegend9->TabIndex = 100;
			this->lLegend9->Text = L"label";
			this->lLegend9->Visible = false;
			// 
			// lAffinityMatrix9
			// 
			this->lAffinityMatrix9->AutoSize = true;
			this->lAffinityMatrix9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAffinityMatrix9->Location = System::Drawing::Point(188, 57);
			this->lAffinityMatrix9->Name = L"lAffinityMatrix9";
			this->lAffinityMatrix9->Size = System::Drawing::Size(127, 23);
			this->lAffinityMatrix9->TabIndex = 98;
			this->lAffinityMatrix9->Text = L"Affinity Matrix";
			this->lAffinityMatrix9->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lBetas9
			// 
			this->lBetas9->AutoSize = true;
			this->lBetas9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas9->Location = System::Drawing::Point(206, 116);
			this->lBetas9->Name = L"lBetas9";
			this->lBetas9->Size = System::Drawing::Size(69, 23);
			this->lBetas9->TabIndex = 91;
			this->lBetas9->Text = L"Fatores";
			this->lBetas9->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas9->Visible = false;
			// 
			// dgAffinityMatrix9
			// 
			this->dgAffinityMatrix9->AllowUserToAddRows = false;
			this->dgAffinityMatrix9->AllowUserToDeleteRows = false;
			this->dgAffinityMatrix9->AllowUserToResizeColumns = false;
			this->dgAffinityMatrix9->AllowUserToResizeRows = false;
			this->dgAffinityMatrix9->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAffinityMatrix9->Location = System::Drawing::Point(9, 99);
			this->dgAffinityMatrix9->Name = L"dgAffinityMatrix9";
			this->dgAffinityMatrix9->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAffinityMatrix9->Size = System::Drawing::Size(475, 209);
			this->dgAffinityMatrix9->TabIndex = 99;
			// 
			// lElasticy5
			// 
			this->lElasticy5->AutoSize = true;
			this->lElasticy5->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lElasticy5->Location = System::Drawing::Point(108, 52);
			this->lElasticy5->Name = L"lElasticy5";
			this->lElasticy5->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lElasticy5->Size = System::Drawing::Size(81, 23);
			this->lElasticy5->TabIndex = 93;
			this->lElasticy5->Text = L"Elasticity";
			this->lElasticy5->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lElasticy5->Visible = false;
			// 
			// tRegion5
			// 
			this->tRegion5->Controls->Add(this->lLegend5);
			this->tRegion5->Controls->Add(this->lAffinityMatrix5);
			this->tRegion5->Controls->Add(this->tPercNeighborsUse5);
			this->tRegion5->Controls->Add(this->lPercNeighborsUse5);
			this->tRegion5->Controls->Add(this->tElasticy5);
			this->tRegion5->Controls->Add(this->lElasticy5);
			this->tRegion5->Controls->Add(this->dgBetas5);
			this->tRegion5->Controls->Add(this->lBetas5);
			this->tRegion5->Controls->Add(this->tConst5);
			this->tRegion5->Controls->Add(this->lConst5);
			this->tRegion5->Controls->Add(this->dgAffinityMatrix5);
			this->tRegion5->Location = System::Drawing::Point(4, 22);
			this->tRegion5->Name = L"tRegion5";
			this->tRegion5->Size = System::Drawing::Size(492, 363);
			this->tRegion5->TabIndex = 4;
			this->tRegion5->Text = L"+";
			this->tRegion5->UseVisualStyleBackColor = true;
			// 
			// lLegend5
			// 
			this->lLegend5->AutoSize = true;
			this->lLegend5->Location = System::Drawing::Point(9, 315);
			this->lLegend5->Name = L"lLegend5";
			this->lLegend5->Size = System::Drawing::Size(29, 13);
			this->lLegend5->TabIndex = 100;
			this->lLegend5->Text = L"label";
			this->lLegend5->Visible = false;
			// 
			// lAffinityMatrix5
			// 
			this->lAffinityMatrix5->AutoSize = true;
			this->lAffinityMatrix5->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAffinityMatrix5->Location = System::Drawing::Point(188, 57);
			this->lAffinityMatrix5->Name = L"lAffinityMatrix5";
			this->lAffinityMatrix5->Size = System::Drawing::Size(127, 23);
			this->lAffinityMatrix5->TabIndex = 98;
			this->lAffinityMatrix5->Text = L"Affinity Matrix";
			this->lAffinityMatrix5->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// dgBetas5
			// 
			this->dgBetas5->AllowUserToResizeColumns = false;
			this->dgBetas5->AllowUserToResizeRows = false;
			this->dgBetas5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas5->Location = System::Drawing::Point(110, 147);
			this->dgBetas5->Name = L"dgBetas5";
			this->dgBetas5->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas5->Size = System::Drawing::Size(245, 209);
			this->dgBetas5->TabIndex = 1;
			this->dgBetas5->Visible = false;
			this->dgBetas5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_AttractRepulseLogisticRegression::dgBetas_KeyDown);
			// 
			// lBetas5
			// 
			this->lBetas5->AutoSize = true;
			this->lBetas5->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas5->Location = System::Drawing::Point(206, 116);
			this->lBetas5->Name = L"lBetas5";
			this->lBetas5->Size = System::Drawing::Size(69, 23);
			this->lBetas5->TabIndex = 91;
			this->lBetas5->Text = L"Fatores";
			this->lBetas5->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas5->Visible = false;
			// 
			// tConst5
			// 
			this->tConst5->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst5->Location = System::Drawing::Point(191, 23);
			this->tConst5->Name = L"tConst5";
			this->tConst5->Size = System::Drawing::Size(161, 20);
			this->tConst5->TabIndex = 90;
			this->tConst5->Text = L"0.01";
			this->tConst5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst5->Visible = false;
			this->tConst5->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lConst5
			// 
			this->lConst5->AutoSize = true;
			this->lConst5->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst5->Location = System::Drawing::Point(130, 22);
			this->lConst5->Name = L"lConst5";
			this->lConst5->Size = System::Drawing::Size(55, 23);
			this->lConst5->TabIndex = 89;
			this->lConst5->Text = L"Const";
			this->lConst5->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst5->Visible = false;
			// 
			// dgAffinityMatrix5
			// 
			this->dgAffinityMatrix5->AllowUserToAddRows = false;
			this->dgAffinityMatrix5->AllowUserToDeleteRows = false;
			this->dgAffinityMatrix5->AllowUserToResizeColumns = false;
			this->dgAffinityMatrix5->AllowUserToResizeRows = false;
			this->dgAffinityMatrix5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAffinityMatrix5->Location = System::Drawing::Point(9, 99);
			this->dgAffinityMatrix5->Name = L"dgAffinityMatrix5";
			this->dgAffinityMatrix5->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAffinityMatrix5->Size = System::Drawing::Size(475, 209);
			this->dgAffinityMatrix5->TabIndex = 99;
			// 
			// tPercNeighborsUse2
			// 
			this->tPercNeighborsUse2->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPercNeighborsUse2->Location = System::Drawing::Point(280, 82);
			this->tPercNeighborsUse2->Name = L"tPercNeighborsUse2";
			this->tPercNeighborsUse2->Size = System::Drawing::Size(72, 20);
			this->tPercNeighborsUse2->TabIndex = 96;
			this->tPercNeighborsUse2->Text = L"0.5";
			this->tPercNeighborsUse2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPercNeighborsUse2->Visible = false;
			this->tPercNeighborsUse2->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lPercNeighborsUse2
			// 
			this->lPercNeighborsUse2->AutoSize = true;
			this->lPercNeighborsUse2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPercNeighborsUse2->Location = System::Drawing::Point(108, 82);
			this->lPercNeighborsUse2->Name = L"lPercNeighborsUse2";
			this->lPercNeighborsUse2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lPercNeighborsUse2->Size = System::Drawing::Size(157, 23);
			this->lPercNeighborsUse2->TabIndex = 95;
			this->lPercNeighborsUse2->Text = L"percNeighborsUse";
			this->lPercNeighborsUse2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPercNeighborsUse2->Visible = false;
			// 
			// tElasticy2
			// 
			this->tElasticy2->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tElasticy2->Location = System::Drawing::Point(191, 54);
			this->tElasticy2->Name = L"tElasticy2";
			this->tElasticy2->Size = System::Drawing::Size(161, 20);
			this->tElasticy2->TabIndex = 94;
			this->tElasticy2->Text = L"0.5";
			this->tElasticy2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tElasticy2->Visible = false;
			this->tElasticy2->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lElasticy2
			// 
			this->lElasticy2->AutoSize = true;
			this->lElasticy2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lElasticy2->Location = System::Drawing::Point(108, 52);
			this->lElasticy2->Name = L"lElasticy2";
			this->lElasticy2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lElasticy2->Size = System::Drawing::Size(81, 23);
			this->lElasticy2->TabIndex = 93;
			this->lElasticy2->Text = L"Elasticity";
			this->lElasticy2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lElasticy2->Visible = false;
			// 
			// tRegion2
			// 
			this->tRegion2->Controls->Add(this->lLegend2);
			this->tRegion2->Controls->Add(this->lAffinityMatrix2);
			this->tRegion2->Controls->Add(this->tPercNeighborsUse2);
			this->tRegion2->Controls->Add(this->lPercNeighborsUse2);
			this->tRegion2->Controls->Add(this->tElasticy2);
			this->tRegion2->Controls->Add(this->lElasticy2);
			this->tRegion2->Controls->Add(this->dgBetas2);
			this->tRegion2->Controls->Add(this->lBetas2);
			this->tRegion2->Controls->Add(this->tConst2);
			this->tRegion2->Controls->Add(this->lConst2);
			this->tRegion2->Controls->Add(this->dgAffinityMatrix2);
			this->tRegion2->Location = System::Drawing::Point(4, 22);
			this->tRegion2->Name = L"tRegion2";
			this->tRegion2->Padding = System::Windows::Forms::Padding(3);
			this->tRegion2->Size = System::Drawing::Size(492, 363);
			this->tRegion2->TabIndex = 1;
			this->tRegion2->Text = L"+";
			this->tRegion2->UseVisualStyleBackColor = true;
			// 
			// lLegend2
			// 
			this->lLegend2->AutoSize = true;
			this->lLegend2->Location = System::Drawing::Point(9, 315);
			this->lLegend2->Name = L"lLegend2";
			this->lLegend2->Size = System::Drawing::Size(29, 13);
			this->lLegend2->TabIndex = 100;
			this->lLegend2->Text = L"label";
			this->lLegend2->Visible = false;
			// 
			// lAffinityMatrix2
			// 
			this->lAffinityMatrix2->AutoSize = true;
			this->lAffinityMatrix2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAffinityMatrix2->Location = System::Drawing::Point(188, 57);
			this->lAffinityMatrix2->Name = L"lAffinityMatrix2";
			this->lAffinityMatrix2->Size = System::Drawing::Size(127, 23);
			this->lAffinityMatrix2->TabIndex = 98;
			this->lAffinityMatrix2->Text = L"Affinity Matrix";
			this->lAffinityMatrix2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// dgBetas2
			// 
			this->dgBetas2->AllowUserToResizeColumns = false;
			this->dgBetas2->AllowUserToResizeRows = false;
			this->dgBetas2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas2->Location = System::Drawing::Point(110, 147);
			this->dgBetas2->Name = L"dgBetas2";
			this->dgBetas2->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas2->Size = System::Drawing::Size(245, 209);
			this->dgBetas2->TabIndex = 92;
			this->dgBetas2->Visible = false;
			this->dgBetas2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_AttractRepulseLogisticRegression::dgBetas_KeyDown);
			// 
			// lBetas2
			// 
			this->lBetas2->AutoSize = true;
			this->lBetas2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas2->Location = System::Drawing::Point(206, 116);
			this->lBetas2->Name = L"lBetas2";
			this->lBetas2->Size = System::Drawing::Size(69, 23);
			this->lBetas2->TabIndex = 91;
			this->lBetas2->Text = L"Fatores";
			this->lBetas2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas2->Visible = false;
			// 
			// tConst2
			// 
			this->tConst2->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst2->Location = System::Drawing::Point(191, 23);
			this->tConst2->Name = L"tConst2";
			this->tConst2->Size = System::Drawing::Size(161, 20);
			this->tConst2->TabIndex = 90;
			this->tConst2->Text = L"0.01";
			this->tConst2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst2->Visible = false;
			this->tConst2->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lConst2
			// 
			this->lConst2->AutoSize = true;
			this->lConst2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst2->Location = System::Drawing::Point(130, 22);
			this->lConst2->Name = L"lConst2";
			this->lConst2->Size = System::Drawing::Size(55, 23);
			this->lConst2->TabIndex = 89;
			this->lConst2->Text = L"Const";
			this->lConst2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst2->Visible = false;
			// 
			// dgAffinityMatrix2
			// 
			this->dgAffinityMatrix2->AllowUserToAddRows = false;
			this->dgAffinityMatrix2->AllowUserToDeleteRows = false;
			this->dgAffinityMatrix2->AllowUserToResizeColumns = false;
			this->dgAffinityMatrix2->AllowUserToResizeRows = false;
			this->dgAffinityMatrix2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAffinityMatrix2->Location = System::Drawing::Point(9, 99);
			this->dgAffinityMatrix2->Name = L"dgAffinityMatrix2";
			this->dgAffinityMatrix2->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAffinityMatrix2->Size = System::Drawing::Size(475, 209);
			this->dgAffinityMatrix2->TabIndex = 99;
			// 
			// tPercNeighborsUse
			// 
			this->tPercNeighborsUse->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPercNeighborsUse->Location = System::Drawing::Point(280, 82);
			this->tPercNeighborsUse->Name = L"tPercNeighborsUse";
			this->tPercNeighborsUse->Size = System::Drawing::Size(72, 20);
			this->tPercNeighborsUse->TabIndex = 90;
			this->tPercNeighborsUse->Text = L"0.5";
			this->tPercNeighborsUse->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPercNeighborsUse->Visible = false;
			this->tPercNeighborsUse->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lPercNeighborsUse
			// 
			this->lPercNeighborsUse->AutoSize = true;
			this->lPercNeighborsUse->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPercNeighborsUse->Location = System::Drawing::Point(108, 82);
			this->lPercNeighborsUse->Name = L"lPercNeighborsUse";
			this->lPercNeighborsUse->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lPercNeighborsUse->Size = System::Drawing::Size(157, 23);
			this->lPercNeighborsUse->TabIndex = 92;
			this->lPercNeighborsUse->Text = L"percNeighborsUse";
			this->lPercNeighborsUse->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPercNeighborsUse->Visible = false;
			// 
			// tElasticy
			// 
			this->tElasticy->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tElasticy->Location = System::Drawing::Point(191, 54);
			this->tElasticy->Name = L"tElasticy";
			this->tElasticy->Size = System::Drawing::Size(161, 20);
			this->tElasticy->TabIndex = 89;
			this->tElasticy->Text = L"0.5";
			this->tElasticy->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tElasticy->Visible = false;
			this->tElasticy->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
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
			this->tcRegions->Location = System::Drawing::Point(191, 155);
			this->tcRegions->Name = L"tcRegions";
			this->tcRegions->SelectedIndex = 0;
			this->tcRegions->Size = System::Drawing::Size(500, 389);
			this->tcRegions->TabIndex = 1;
			this->tcRegions->Visible = false;
			this->tcRegions->SelectedIndexChanged += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::tcRegions_SelectedIndexChanged);
			// 
			// tRegion1
			// 
			this->tRegion1->Controls->Add(this->lLegend);
			this->tRegion1->Controls->Add(this->lAffinityMatrix);
			this->tRegion1->Controls->Add(this->tPercNeighborsUse);
			this->tRegion1->Controls->Add(this->lPercNeighborsUse);
			this->tRegion1->Controls->Add(this->tElasticy);
			this->tRegion1->Controls->Add(this->lElasticy);
			this->tRegion1->Controls->Add(this->dgBetas);
			this->tRegion1->Controls->Add(this->tConst);
			this->tRegion1->Controls->Add(this->lConst);
			this->tRegion1->Controls->Add(this->lBetas);
			this->tRegion1->Controls->Add(this->dgAffinityMatrix);
			this->tRegion1->Location = System::Drawing::Point(4, 22);
			this->tRegion1->Name = L"tRegion1";
			this->tRegion1->Padding = System::Windows::Forms::Padding(3);
			this->tRegion1->Size = System::Drawing::Size(492, 363);
			this->tRegion1->TabIndex = 0;
			this->tRegion1->Text = L"Region 1";
			this->tRegion1->UseVisualStyleBackColor = true;
			// 
			// lLegend
			// 
			this->lLegend->AutoSize = true;
			this->lLegend->Location = System::Drawing::Point(9, 315);
			this->lLegend->Name = L"lLegend";
			this->lLegend->Size = System::Drawing::Size(29, 13);
			this->lLegend->TabIndex = 98;
			this->lLegend->Text = L"label";
			this->lLegend->Visible = false;
			// 
			// lAffinityMatrix
			// 
			this->lAffinityMatrix->AutoSize = true;
			this->lAffinityMatrix->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAffinityMatrix->Location = System::Drawing::Point(188, 57);
			this->lAffinityMatrix->Name = L"lAffinityMatrix";
			this->lAffinityMatrix->Size = System::Drawing::Size(127, 23);
			this->lAffinityMatrix->TabIndex = 97;
			this->lAffinityMatrix->Text = L"Affinity Matrix";
			this->lAffinityMatrix->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lAffinityMatrix->Visible = false;
			// 
			// lElasticy
			// 
			this->lElasticy->AutoSize = true;
			this->lElasticy->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lElasticy->Location = System::Drawing::Point(108, 52);
			this->lElasticy->Name = L"lElasticy";
			this->lElasticy->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lElasticy->Size = System::Drawing::Size(81, 23);
			this->lElasticy->TabIndex = 91;
			this->lElasticy->Text = L"Elasticity";
			this->lElasticy->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lElasticy->Visible = false;
			// 
			// dgBetas
			// 
			this->dgBetas->AllowUserToResizeColumns = false;
			this->dgBetas->AllowUserToResizeRows = false;
			this->dgBetas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas->Location = System::Drawing::Point(110, 147);
			this->dgBetas->Name = L"dgBetas";
			this->dgBetas->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas->Size = System::Drawing::Size(245, 209);
			this->dgBetas->TabIndex = 1;
			this->dgBetas->Visible = false;
			this->dgBetas->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_AttractRepulseLogisticRegression::dgBetas_KeyDown);
			// 
			// tConst
			// 
			this->tConst->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst->Location = System::Drawing::Point(191, 23);
			this->tConst->Name = L"tConst";
			this->tConst->Size = System::Drawing::Size(161, 20);
			this->tConst->TabIndex = 83;
			this->tConst->Text = L"0.01";
			this->tConst->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst->Visible = false;
			this->tConst->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lConst
			// 
			this->lConst->AutoSize = true;
			this->lConst->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst->Location = System::Drawing::Point(130, 22);
			this->lConst->Name = L"lConst";
			this->lConst->Size = System::Drawing::Size(55, 23);
			this->lConst->TabIndex = 88;
			this->lConst->Text = L"Const";
			this->lConst->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst->Visible = false;
			// 
			// lBetas
			// 
			this->lBetas->AutoSize = true;
			this->lBetas->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas->Location = System::Drawing::Point(206, 116);
			this->lBetas->Name = L"lBetas";
			this->lBetas->Size = System::Drawing::Size(69, 23);
			this->lBetas->TabIndex = 93;
			this->lBetas->Text = L"Fatores";
			this->lBetas->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas->Visible = false;
			// 
			// dgAffinityMatrix
			// 
			this->dgAffinityMatrix->AllowUserToAddRows = false;
			this->dgAffinityMatrix->AllowUserToDeleteRows = false;
			this->dgAffinityMatrix->AllowUserToResizeColumns = false;
			this->dgAffinityMatrix->AllowUserToResizeRows = false;
			this->dgAffinityMatrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAffinityMatrix->Location = System::Drawing::Point(9, 99);
			this->dgAffinityMatrix->Name = L"dgAffinityMatrix";
			this->dgAffinityMatrix->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAffinityMatrix->Size = System::Drawing::Size(475, 209);
			this->dgAffinityMatrix->TabIndex = 96;
			this->dgAffinityMatrix->Visible = false;
			// 
			// tRegion3
			// 
			this->tRegion3->Controls->Add(this->lLegend3);
			this->tRegion3->Controls->Add(this->lAffinityMatrix3);
			this->tRegion3->Controls->Add(this->tPercNeighborsUse3);
			this->tRegion3->Controls->Add(this->lPercNeighborsUse3);
			this->tRegion3->Controls->Add(this->tElasticy3);
			this->tRegion3->Controls->Add(this->lElasticy3);
			this->tRegion3->Controls->Add(this->dgBetas3);
			this->tRegion3->Controls->Add(this->lBetas3);
			this->tRegion3->Controls->Add(this->tConst3);
			this->tRegion3->Controls->Add(this->lConst3);
			this->tRegion3->Controls->Add(this->dgAffinityMatrix3);
			this->tRegion3->Location = System::Drawing::Point(4, 22);
			this->tRegion3->Name = L"tRegion3";
			this->tRegion3->Size = System::Drawing::Size(492, 363);
			this->tRegion3->TabIndex = 2;
			this->tRegion3->Text = L"+";
			this->tRegion3->UseVisualStyleBackColor = true;
			// 
			// lLegend3
			// 
			this->lLegend3->AutoSize = true;
			this->lLegend3->Location = System::Drawing::Point(9, 315);
			this->lLegend3->Name = L"lLegend3";
			this->lLegend3->Size = System::Drawing::Size(29, 13);
			this->lLegend3->TabIndex = 100;
			this->lLegend3->Text = L"label";
			this->lLegend3->Visible = false;
			// 
			// lAffinityMatrix3
			// 
			this->lAffinityMatrix3->AutoSize = true;
			this->lAffinityMatrix3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAffinityMatrix3->Location = System::Drawing::Point(188, 57);
			this->lAffinityMatrix3->Name = L"lAffinityMatrix3";
			this->lAffinityMatrix3->Size = System::Drawing::Size(127, 23);
			this->lAffinityMatrix3->TabIndex = 98;
			this->lAffinityMatrix3->Text = L"Affinity Matrix";
			this->lAffinityMatrix3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tPercNeighborsUse3
			// 
			this->tPercNeighborsUse3->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPercNeighborsUse3->Location = System::Drawing::Point(280, 82);
			this->tPercNeighborsUse3->Name = L"tPercNeighborsUse3";
			this->tPercNeighborsUse3->Size = System::Drawing::Size(72, 20);
			this->tPercNeighborsUse3->TabIndex = 96;
			this->tPercNeighborsUse3->Text = L"0.5";
			this->tPercNeighborsUse3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPercNeighborsUse3->Visible = false;
			this->tPercNeighborsUse3->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lPercNeighborsUse3
			// 
			this->lPercNeighborsUse3->AutoSize = true;
			this->lPercNeighborsUse3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPercNeighborsUse3->Location = System::Drawing::Point(108, 82);
			this->lPercNeighborsUse3->Name = L"lPercNeighborsUse3";
			this->lPercNeighborsUse3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lPercNeighborsUse3->Size = System::Drawing::Size(157, 23);
			this->lPercNeighborsUse3->TabIndex = 95;
			this->lPercNeighborsUse3->Text = L"percNeighborsUse";
			this->lPercNeighborsUse3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPercNeighborsUse3->Visible = false;
			// 
			// tElasticy3
			// 
			this->tElasticy3->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tElasticy3->Location = System::Drawing::Point(191, 54);
			this->tElasticy3->Name = L"tElasticy3";
			this->tElasticy3->Size = System::Drawing::Size(161, 20);
			this->tElasticy3->TabIndex = 94;
			this->tElasticy3->Text = L"0.5";
			this->tElasticy3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tElasticy3->Visible = false;
			this->tElasticy3->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lElasticy3
			// 
			this->lElasticy3->AutoSize = true;
			this->lElasticy3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lElasticy3->Location = System::Drawing::Point(108, 52);
			this->lElasticy3->Name = L"lElasticy3";
			this->lElasticy3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lElasticy3->Size = System::Drawing::Size(81, 23);
			this->lElasticy3->TabIndex = 93;
			this->lElasticy3->Text = L"Elasticity";
			this->lElasticy3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lElasticy3->Visible = false;
			// 
			// dgBetas3
			// 
			this->dgBetas3->AllowUserToResizeColumns = false;
			this->dgBetas3->AllowUserToResizeRows = false;
			this->dgBetas3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas3->Location = System::Drawing::Point(110, 147);
			this->dgBetas3->Name = L"dgBetas3";
			this->dgBetas3->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas3->Size = System::Drawing::Size(245, 209);
			this->dgBetas3->TabIndex = 1;
			this->dgBetas3->Visible = false;
			this->dgBetas3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_AttractRepulseLogisticRegression::dgBetas_KeyDown);
			// 
			// lBetas3
			// 
			this->lBetas3->AutoSize = true;
			this->lBetas3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas3->Location = System::Drawing::Point(206, 116);
			this->lBetas3->Name = L"lBetas3";
			this->lBetas3->Size = System::Drawing::Size(69, 23);
			this->lBetas3->TabIndex = 91;
			this->lBetas3->Text = L"Fatores";
			this->lBetas3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas3->Visible = false;
			// 
			// tConst3
			// 
			this->tConst3->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst3->Location = System::Drawing::Point(191, 23);
			this->tConst3->Name = L"tConst3";
			this->tConst3->Size = System::Drawing::Size(161, 20);
			this->tConst3->TabIndex = 90;
			this->tConst3->Text = L"0.01";
			this->tConst3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst3->Visible = false;
			this->tConst3->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lConst3
			// 
			this->lConst3->AutoSize = true;
			this->lConst3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst3->Location = System::Drawing::Point(130, 22);
			this->lConst3->Name = L"lConst3";
			this->lConst3->Size = System::Drawing::Size(55, 23);
			this->lConst3->TabIndex = 89;
			this->lConst3->Text = L"Const";
			this->lConst3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst3->Visible = false;
			// 
			// dgAffinityMatrix3
			// 
			this->dgAffinityMatrix3->AllowUserToAddRows = false;
			this->dgAffinityMatrix3->AllowUserToDeleteRows = false;
			this->dgAffinityMatrix3->AllowUserToResizeColumns = false;
			this->dgAffinityMatrix3->AllowUserToResizeRows = false;
			this->dgAffinityMatrix3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAffinityMatrix3->Location = System::Drawing::Point(9, 99);
			this->dgAffinityMatrix3->Name = L"dgAffinityMatrix3";
			this->dgAffinityMatrix3->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAffinityMatrix3->Size = System::Drawing::Size(475, 209);
			this->dgAffinityMatrix3->TabIndex = 99;
			// 
			// tRegion4
			// 
			this->tRegion4->Controls->Add(this->lLegend4);
			this->tRegion4->Controls->Add(this->lAffinityMatrix4);
			this->tRegion4->Controls->Add(this->tPercNeighborsUse4);
			this->tRegion4->Controls->Add(this->lPercNeighborsUse4);
			this->tRegion4->Controls->Add(this->tElasticy4);
			this->tRegion4->Controls->Add(this->lElasticy4);
			this->tRegion4->Controls->Add(this->dgBetas4);
			this->tRegion4->Controls->Add(this->lBetas4);
			this->tRegion4->Controls->Add(this->tConst4);
			this->tRegion4->Controls->Add(this->lConst4);
			this->tRegion4->Controls->Add(this->dgAffinityMatrix4);
			this->tRegion4->Location = System::Drawing::Point(4, 22);
			this->tRegion4->Name = L"tRegion4";
			this->tRegion4->Size = System::Drawing::Size(492, 363);
			this->tRegion4->TabIndex = 3;
			this->tRegion4->Text = L"+";
			this->tRegion4->UseVisualStyleBackColor = true;
			// 
			// lLegend4
			// 
			this->lLegend4->AutoSize = true;
			this->lLegend4->Location = System::Drawing::Point(9, 315);
			this->lLegend4->Name = L"lLegend4";
			this->lLegend4->Size = System::Drawing::Size(29, 13);
			this->lLegend4->TabIndex = 100;
			this->lLegend4->Text = L"label";
			this->lLegend4->Visible = false;
			// 
			// lAffinityMatrix4
			// 
			this->lAffinityMatrix4->AutoSize = true;
			this->lAffinityMatrix4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAffinityMatrix4->Location = System::Drawing::Point(188, 57);
			this->lAffinityMatrix4->Name = L"lAffinityMatrix4";
			this->lAffinityMatrix4->Size = System::Drawing::Size(127, 23);
			this->lAffinityMatrix4->TabIndex = 98;
			this->lAffinityMatrix4->Text = L"Affinity Matrix";
			this->lAffinityMatrix4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tPercNeighborsUse4
			// 
			this->tPercNeighborsUse4->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPercNeighborsUse4->Location = System::Drawing::Point(280, 82);
			this->tPercNeighborsUse4->Name = L"tPercNeighborsUse4";
			this->tPercNeighborsUse4->Size = System::Drawing::Size(72, 20);
			this->tPercNeighborsUse4->TabIndex = 96;
			this->tPercNeighborsUse4->Text = L"0.5";
			this->tPercNeighborsUse4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPercNeighborsUse4->Visible = false;
			this->tPercNeighborsUse4->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lPercNeighborsUse4
			// 
			this->lPercNeighborsUse4->AutoSize = true;
			this->lPercNeighborsUse4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPercNeighborsUse4->Location = System::Drawing::Point(108, 82);
			this->lPercNeighborsUse4->Name = L"lPercNeighborsUse4";
			this->lPercNeighborsUse4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lPercNeighborsUse4->Size = System::Drawing::Size(157, 23);
			this->lPercNeighborsUse4->TabIndex = 95;
			this->lPercNeighborsUse4->Text = L"percNeighborsUse";
			this->lPercNeighborsUse4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPercNeighborsUse4->Visible = false;
			// 
			// tElasticy4
			// 
			this->tElasticy4->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tElasticy4->Location = System::Drawing::Point(191, 54);
			this->tElasticy4->Name = L"tElasticy4";
			this->tElasticy4->Size = System::Drawing::Size(161, 20);
			this->tElasticy4->TabIndex = 94;
			this->tElasticy4->Text = L"0.5";
			this->tElasticy4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tElasticy4->Visible = false;
			this->tElasticy4->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lElasticy4
			// 
			this->lElasticy4->AutoSize = true;
			this->lElasticy4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lElasticy4->Location = System::Drawing::Point(108, 52);
			this->lElasticy4->Name = L"lElasticy4";
			this->lElasticy4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lElasticy4->Size = System::Drawing::Size(81, 23);
			this->lElasticy4->TabIndex = 93;
			this->lElasticy4->Text = L"Elasticity";
			this->lElasticy4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lElasticy4->Visible = false;
			// 
			// dgBetas4
			// 
			this->dgBetas4->AllowUserToResizeColumns = false;
			this->dgBetas4->AllowUserToResizeRows = false;
			this->dgBetas4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas4->Location = System::Drawing::Point(110, 147);
			this->dgBetas4->Name = L"dgBetas4";
			this->dgBetas4->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas4->Size = System::Drawing::Size(245, 209);
			this->dgBetas4->TabIndex = 1;
			this->dgBetas4->Visible = false;
			this->dgBetas4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_AttractRepulseLogisticRegression::dgBetas_KeyDown);
			// 
			// lBetas4
			// 
			this->lBetas4->AutoSize = true;
			this->lBetas4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas4->Location = System::Drawing::Point(206, 116);
			this->lBetas4->Name = L"lBetas4";
			this->lBetas4->Size = System::Drawing::Size(69, 23);
			this->lBetas4->TabIndex = 91;
			this->lBetas4->Text = L"Fatores";
			this->lBetas4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas4->Visible = false;
			// 
			// tConst4
			// 
			this->tConst4->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst4->Location = System::Drawing::Point(191, 23);
			this->tConst4->Name = L"tConst4";
			this->tConst4->Size = System::Drawing::Size(161, 20);
			this->tConst4->TabIndex = 90;
			this->tConst4->Text = L"0.01";
			this->tConst4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst4->Visible = false;
			this->tConst4->Enter += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::textBox_Enter);
			// 
			// lConst4
			// 
			this->lConst4->AutoSize = true;
			this->lConst4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst4->Location = System::Drawing::Point(130, 22);
			this->lConst4->Name = L"lConst4";
			this->lConst4->Size = System::Drawing::Size(55, 23);
			this->lConst4->TabIndex = 89;
			this->lConst4->Text = L"Const";
			this->lConst4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst4->Visible = false;
			// 
			// dgAffinityMatrix4
			// 
			this->dgAffinityMatrix4->AllowUserToAddRows = false;
			this->dgAffinityMatrix4->AllowUserToDeleteRows = false;
			this->dgAffinityMatrix4->AllowUserToResizeColumns = false;
			this->dgAffinityMatrix4->AllowUserToResizeRows = false;
			this->dgAffinityMatrix4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAffinityMatrix4->Location = System::Drawing::Point(9, 99);
			this->dgAffinityMatrix4->Name = L"dgAffinityMatrix4";
			this->dgAffinityMatrix4->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAffinityMatrix4->Size = System::Drawing::Size(475, 209);
			this->dgAffinityMatrix4->TabIndex = 99;
			// 
			// bDeleteRegression
			// 
			this->bDeleteRegression->Location = System::Drawing::Point(700, 177);
			this->bDeleteRegression->Name = L"bDeleteRegression";
			this->bDeleteRegression->Size = System::Drawing::Size(24, 23);
			this->bDeleteRegression->TabIndex = 93;
			this->bDeleteRegression->Text = L"-";
			this->bDeleteRegression->UseVisualStyleBackColor = true;
			this->bDeleteRegression->Visible = false;
			this->bDeleteRegression->Click += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::bDeleteRegression_Click);
			// 
			// tLUT
			// 
			this->tLUT->ForeColor = System::Drawing::Color::Black;
			this->tLUT->Location = System::Drawing::Point(12, 155);
			this->tLUT->Name = L"tLUT";
			this->tLUT->Size = System::Drawing::Size(161, 20);
			this->tLUT->TabIndex = 92;
			this->tLUT->Visible = false;
			// 
			// bAddBetas
			// 
			this->bAddBetas->Location = System::Drawing::Point(614, 552);
			this->bAddBetas->Name = L"bAddBetas";
			this->bAddBetas->Size = System::Drawing::Size(71, 23);
			this->bAddBetas->TabIndex = 88;
			this->bAddBetas->Text = L"Adicionar";
			this->bAddBetas->UseVisualStyleBackColor = true;
			this->bAddBetas->Visible = false;
			this->bAddBetas->Click += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::bAddBetas_Click);
			// 
			// lvLUT
			// 
			this->lvLUT->Location = System::Drawing::Point(12, 154);
			this->lvLUT->MultiSelect = false;
			this->lvLUT->Name = L"lvLUT";
			this->lvLUT->Size = System::Drawing::Size(171, 390);
			this->lvLUT->TabIndex = 87;
			this->lvLUT->UseCompatibleStateImageBehavior = false;
			this->lvLUT->SelectedIndexChanged += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::lvLUT_SelectedIndexChanged);
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(332, 552);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 90;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::bSalvar_Click);
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(186, 9);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 91;
			this->pbLogo1->TabStop = false;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(510, 552);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(71, 23);
			this->bCancel->TabIndex = 89;
			this->bCancel->Text = L"Cancelar";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Visible = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::bCancel_Click);
			// 
			// P_AttractRepulseLogisticRegression
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(737, 585);
			this->Controls->Add(this->tcRegions);
			this->Controls->Add(this->bDeleteRegression);
			this->Controls->Add(this->tLUT);
			this->Controls->Add(this->bAddBetas);
			this->Controls->Add(this->lvLUT);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->pbLogo1);
			this->Controls->Add(this->bCancel);
			this->Name = L"P_AttractRepulseLogisticRegression";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"P_AttractRepulseLogisticRegression";
			this->Shown += gcnew System::EventHandler(this, &P_AttractRepulseLogisticRegression::P_AttractRepulseLogisticRegression_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas7))->EndInit();
			this->tRegion6->ResumeLayout(false);
			this->tRegion6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix6))->EndInit();
			this->tRegion7->ResumeLayout(false);
			this->tRegion7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix7))->EndInit();
			this->tRegion8->ResumeLayout(false);
			this->tRegion8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas10))->EndInit();
			this->tRegion10->ResumeLayout(false);
			this->tRegion10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas9))->EndInit();
			this->tRegion9->ResumeLayout(false);
			this->tRegion9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix9))->EndInit();
			this->tRegion5->ResumeLayout(false);
			this->tRegion5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix5))->EndInit();
			this->tRegion2->ResumeLayout(false);
			this->tRegion2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix2))->EndInit();
			this->tcRegions->ResumeLayout(false);
			this->tRegion1->ResumeLayout(false);
			this->tRegion1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix))->EndInit();
			this->tRegion3->ResumeLayout(false);
			this->tRegion3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix3))->EndInit();
			this->tRegion4->ResumeLayout(false);
			this->tRegion4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAffinityMatrix4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
		private: System::Int16 countCaracter(String^ source, char caracter);
		private: System::Void initializeRegions();
		private: System::Void setVisibleONorOFF(Label^ lBetas, DataGridView^ dgBetas, Label^ lConst, TextBox^ tConst, Label^ lElasticy, TextBox^ tElasticy, Label^ lPercNeighborsUse, TextBox^ tPercNeighborsUse, DataGridView^ dgAffinity, Label^ lAffinityMatrix, Label^ lLegend, bool status);
		private: System::Void LuccME::P_AttractRepulseLogisticRegression::setInitializeAffinity(DataGridView^ dgAffinity);
		private: System::Void moveData(DataGridView^ dgBetas, TextBox^ tConst, TextBox^ tElasticy, TextBox^ tPercNeighborsUse, DataGridView^ dgAffinity, DataGridView^ dgBetas2, TextBox^ tConst2, TextBox^ tElasticy2, TextBox^ tPercNeighborsUse2, DataGridView^ dgAffinity2);
		private: System::Int16 getRegionData(array<String^>^ lTempBetas, cReturnPotential^ lReturn, DataGridView^ dgBetas, TextBox^ tConst, TextBox^ tElasticy, TextBox^ tPercNeighborsUse, int i, int j);
		private: System::Void setRegionData(DataGridView^ dgBetas, TextBox^ tConst, TextBox^ tElasticy, TextBox^ tPercNeighborsUse, int i, int j);
		private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgView);
		private: System::Void dgBetas_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
		private: System::Void CopyToClipboard(DataGridView^ dgView);
		private: System::Void PasteClipboardValue(DataGridView^ dgView);
		private: System::Void P_AttractRepulseLogisticRegression_Shown(System::Object^  sender, System::EventArgs^  e);
		private: System::Void lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		private: System::Void tcRegions_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		private: System::Void LuccME::P_AttractRepulseLogisticRegression::getMatrixData(array<String^>^ lTempValues, DataGridView^ dgAffinity, int k);
		private: System::Void bDeleteRegression_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void bAddBetas_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Boolean setAffinityMatrixData(DataGridView^ dgAffinity, int k);
		private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	};
}

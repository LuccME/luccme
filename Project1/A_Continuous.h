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
	private: System::Windows::Forms::DataGridView^  dgAllocationData;
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
			this->dgAllocationData = (gcnew System::Windows::Forms::DataGridView());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// tComplementarLU
			// 
			this->tComplementarLU->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tComplementarLU->Location = System::Drawing::Point(199, 293);
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
			this->lComplementarLU->Location = System::Drawing::Point(47, 292);
			this->lComplementarLU->Name = L"lComplementarLU";
			this->lComplementarLU->Size = System::Drawing::Size(146, 23);
			this->lComplementarLU->TabIndex = 126;
			this->lComplementarLU->Text = L"complementarLU";
			this->lComplementarLU->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tMaxElasticity
			// 
			this->tMaxElasticity->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxElasticity->Location = System::Drawing::Point(638, 230);
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
			this->lMaxElasticity->Location = System::Drawing::Point(503, 228);
			this->lMaxElasticity->Name = L"lMaxElasticity";
			this->lMaxElasticity->Size = System::Drawing::Size(114, 23);
			this->lMaxElasticity->TabIndex = 124;
			this->lMaxElasticity->Text = L"maxElasticity";
			this->lMaxElasticity->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tMinElasticity
			// 
			this->tMinElasticity->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinElasticity->Location = System::Drawing::Point(637, 200);
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
			this->lMinElasticity->Location = System::Drawing::Point(502, 198);
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
			this->lAllocationData->Location = System::Drawing::Point(395, 370);
			this->lAllocationData->Name = L"lAllocationData";
			this->lAllocationData->Size = System::Drawing::Size(131, 23);
			this->lAllocationData->TabIndex = 120;
			this->lAllocationData->Text = L"Allocation Data";
			this->lAllocationData->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// dgAllocationData
			// 
			this->dgAllocationData->AllowUserToAddRows = false;
			this->dgAllocationData->AllowUserToDeleteRows = false;
			this->dgAllocationData->AllowUserToResizeColumns = false;
			this->dgAllocationData->AllowUserToResizeRows = false;
			this->dgAllocationData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAllocationData->Location = System::Drawing::Point(21, 415);
			this->dgAllocationData->Name = L"dgAllocationData";
			this->dgAllocationData->RowHeadersWidth = 71;
			this->dgAllocationData->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAllocationData->Size = System::Drawing::Size(882, 129);
			this->dgAllocationData->TabIndex = 10;
			this->dgAllocationData->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &A_Continuous::dgAllocationData_CellEnter);
			this->dgAllocationData->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_Continuous::dgAllocationData_KeyDown);
			// 
			// tMaxDifference
			// 
			this->tMaxDifference->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxDifference->Location = System::Drawing::Point(189, 188);
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
			this->lMaxDifference->Location = System::Drawing::Point(54, 187);
			this->lMaxDifference->Name = L"lMaxDifference";
			this->lMaxDifference->Size = System::Drawing::Size(126, 23);
			this->lMaxDifference->TabIndex = 118;
			this->lMaxDifference->Text = L"maxDifference";
			this->lMaxDifference->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tInitialElasticity
			// 
			this->tInitialElasticity->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tInitialElasticity->Location = System::Drawing::Point(637, 170);
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
			this->lInitialElasticity->Location = System::Drawing::Point(502, 168);
			this->lInitialElasticity->Name = L"lInitialElasticity";
			this->lInitialElasticity->Size = System::Drawing::Size(126, 23);
			this->lInitialElasticity->TabIndex = 116;
			this->lInitialElasticity->Text = L"initialElasticity";
			this->lInitialElasticity->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(424, 557);
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
			this->tMaxIteration->Location = System::Drawing::Point(188, 218);
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
			this->lMaxIteration->Location = System::Drawing::Point(54, 217);
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
			this->tSaturationIndicator->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tSaturationIndicator->Location = System::Drawing::Point(649, 294);
			this->tSaturationIndicator->Name = L"tSaturationIndicator";
			this->tSaturationIndicator->Size = System::Drawing::Size(183, 20);
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
			this->lSaturationIndicator->Location = System::Drawing::Point(484, 293);
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
			this->tAttrProtection->Location = System::Drawing::Point(649, 327);
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
			this->lAttrProtection->Location = System::Drawing::Point(500, 326);
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
			this->lLegend->Location = System::Drawing::Point(21, 557);
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
			this->lMaxDiffHelp->Location = System::Drawing::Point(249, 170);
			this->lMaxDiffHelp->Name = L"lMaxDiffHelp";
			this->lMaxDiffHelp->Size = System::Drawing::Size(75, 13);
			this->lMaxDiffHelp->TabIndex = 132;
			this->lMaxDiffHelp->Text = L"Valor Absoluto";
			this->lMaxDiffHelp->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// A_Continuous
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(923, 591);
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
			this->Controls->Add(this->dgAllocationData);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAllocationData))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void A_Continuous_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgView);
	private: System::Void dgAllocationData_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void dgAllocationData_CellEnter(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
};
}

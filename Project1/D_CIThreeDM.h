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
	/// Summary for D_CIThreeDM
	/// </summary>
	public ref class D_CIThreeDM : public System::Windows::Forms::Form
	{
	private:
		String^ gSCells = "";
		String^ gSCellsTitle = "";
		String^ gSDataMod = "";
		String^ gSExit = "";

	public:
		cReturnCIThreeMP^ lReturn;
		bool changed;
		bool close;
		bool managed;
		D_CIThreeDM(cReturnCIThreeMP^ pDemand)
		{
			InitializeComponent();
			this->lReturn = pDemand;
			changed = false;
			close = false;
			managed = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~D_CIThreeDM()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lLUTfI;
	protected:
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::DataGridView^  dgDemand;
	private: System::Windows::Forms::TextBox^  tFinalYear;
	private: System::Windows::Forms::Label^  lFinalYear;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::TextBox^  tMiddleYear;
	private: System::Windows::Forms::Label^  lMiddleYear;
	private: System::Windows::Forms::Label^  lYearInterpolation;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(D_CIThreeDM::typeid));
			this->lLUTfI = (gcnew System::Windows::Forms::Label());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->dgDemand = (gcnew System::Windows::Forms::DataGridView());
			this->tFinalYear = (gcnew System::Windows::Forms::TextBox());
			this->lFinalYear = (gcnew System::Windows::Forms::Label());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->tMiddleYear = (gcnew System::Windows::Forms::TextBox());
			this->lMiddleYear = (gcnew System::Windows::Forms::Label());
			this->lYearInterpolation = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDemand))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// lLUTfI
			// 
			this->lLUTfI->AutoSize = true;
			this->lLUTfI->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lLUTfI->Location = System::Drawing::Point(151, 297);
			this->lLUTfI->Name = L"lLUTfI";
			this->lLUTfI->Size = System::Drawing::Size(215, 23);
			this->lLUTfI->TabIndex = 54;
			this->lLUTfI->Text = L"Colunas para Interpolação";
			this->lLUTfI->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(214, 490);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 53;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &D_CIThreeDM::bSalvar_Click);
			// 
			// dgDemand
			// 
			this->dgDemand->AllowUserToAddRows = false;
			this->dgDemand->AllowUserToDeleteRows = false;
			this->dgDemand->AllowUserToResizeColumns = false;
			this->dgDemand->AllowUserToResizeRows = false;
			this->dgDemand->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgDemand->Location = System::Drawing::Point(54, 335);
			this->dgDemand->Name = L"dgDemand";
			this->dgDemand->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgDemand->Size = System::Drawing::Size(390, 135);
			this->dgDemand->TabIndex = 49;
			this->dgDemand->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &D_CIThreeDM::dgDemand_CellValueChanged);
			this->dgDemand->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &D_CIThreeDM::dgDemand_KeyDown);
			// 
			// tFinalYear
			// 
			this->tFinalYear->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tFinalYear->Location = System::Drawing::Point(254, 245);
			this->tFinalYear->Name = L"tFinalYear";
			this->tFinalYear->Size = System::Drawing::Size(161, 20);
			this->tFinalYear->TabIndex = 51;
			this->tFinalYear->Text = L"2000";
			this->tFinalYear->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tFinalYear->Enter += gcnew System::EventHandler(this, &D_CIThreeDM::textBox_Enter);
			// 
			// lFinalYear
			// 
			this->lFinalYear->AutoSize = true;
			this->lFinalYear->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lFinalYear->Location = System::Drawing::Point(88, 245);
			this->lFinalYear->Name = L"lFinalYear";
			this->lFinalYear->Size = System::Drawing::Size(48, 23);
			this->lFinalYear->TabIndex = 52;
			this->lFinalYear->Text = L"Final";
			this->lFinalYear->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(58, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 50;
			this->pbLogo1->TabStop = false;
			// 
			// tMiddleYear
			// 
			this->tMiddleYear->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMiddleYear->Location = System::Drawing::Point(254, 202);
			this->tMiddleYear->Name = L"tMiddleYear";
			this->tMiddleYear->Size = System::Drawing::Size(161, 20);
			this->tMiddleYear->TabIndex = 55;
			this->tMiddleYear->Text = L"2000";
			this->tMiddleYear->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMiddleYear->Enter += gcnew System::EventHandler(this, &D_CIThreeDM::textBox_Enter);
			// 
			// lMiddleYear
			// 
			this->lMiddleYear->AutoSize = true;
			this->lMiddleYear->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMiddleYear->Location = System::Drawing::Point(88, 200);
			this->lMiddleYear->Name = L"lMiddleYear";
			this->lMiddleYear->Size = System::Drawing::Size(120, 23);
			this->lMiddleYear->TabIndex = 56;
			this->lMiddleYear->Text = L"Intermediário";
			this->lMiddleYear->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lYearInterpolation
			// 
			this->lYearInterpolation->AutoSize = true;
			this->lYearInterpolation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lYearInterpolation->Location = System::Drawing::Point(155, 167);
			this->lYearInterpolation->Name = L"lYearInterpolation";
			this->lYearInterpolation->Size = System::Drawing::Size(198, 23);
			this->lYearInterpolation->TabIndex = 57;
			this->lYearInterpolation->Text = L"Anos para Interpolação:";
			this->lYearInterpolation->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// D_CIThreeDM
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->lYearInterpolation);
			this->Controls->Add(this->tMiddleYear);
			this->Controls->Add(this->lMiddleYear);
			this->Controls->Add(this->lLUTfI);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->dgDemand);
			this->Controls->Add(this->tFinalYear);
			this->Controls->Add(this->lFinalYear);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"D_CIThreeDM";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"D_CIThreeDM";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &D_CIThreeDM::D_CIThreeDM_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &D_CIThreeDM::D_CIThreeDM_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDemand))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void D_CIThreeDM_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void D_CIThreeDM_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void dgDemand_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgView);
	private: System::Void dgDemand_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};
}

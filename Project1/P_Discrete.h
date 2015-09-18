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
	/// Summary for P_Discrete
	/// </summary>
	public ref class P_Discrete : public System::Windows::Forms::Form
	{
	private:
		String^ gSLUT = "";
		String^ gSValues = "";
		String^ gSEmptyComponent = "";
		String^ gSEmptyComponentTitle = "";

	private: System::Windows::Forms::TextBox^  tLUT;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::TextBox^  tElasticy;

	private: System::Windows::Forms::Label^  lElasticy;
	private: System::Windows::Forms::TextBox^  tPercNeighborsUse;
	private: System::Windows::Forms::Label^  lPercNeighborsUse;


	public:
		cReturnPotential^ lReturn;
		array<String^>^ lTempBetas = gcnew array<String^>(50);
		P_Discrete(cReturnPotential^ pPotencial)
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
		~P_Discrete()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::Button^  bAddBetas;
	private: System::Windows::Forms::ListView^  lvLUT;
	private: System::Windows::Forms::TextBox^  tConst;
	private: System::Windows::Forms::Label^  lConst;
	private: System::Windows::Forms::Label^  lBetas;
	private: System::Windows::Forms::DataGridView^  dgBetas;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(P_Discrete::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->bAddBetas = (gcnew System::Windows::Forms::Button());
			this->lvLUT = (gcnew System::Windows::Forms::ListView());
			this->tConst = (gcnew System::Windows::Forms::TextBox());
			this->lConst = (gcnew System::Windows::Forms::Label());
			this->lBetas = (gcnew System::Windows::Forms::Label());
			this->dgBetas = (gcnew System::Windows::Forms::DataGridView());
			this->tLUT = (gcnew System::Windows::Forms::TextBox());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->tElasticy = (gcnew System::Windows::Forms::TextBox());
			this->lElasticy = (gcnew System::Windows::Forms::Label());
			this->tPercNeighborsUse = (gcnew System::Windows::Forms::TextBox());
			this->lPercNeighborsUse = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas))->BeginInit();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(58, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 16;
			this->pbLogo1->TabStop = false;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(221, 488);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 8;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &P_Discrete::bSalvar_Click);
			// 
			// bAddBetas
			// 
			this->bAddBetas->Location = System::Drawing::Point(367, 488);
			this->bAddBetas->Name = L"bAddBetas";
			this->bAddBetas->Size = System::Drawing::Size(75, 23);
			this->bAddBetas->TabIndex = 6;
			this->bAddBetas->Text = L"Adicionar";
			this->bAddBetas->UseVisualStyleBackColor = true;
			this->bAddBetas->Visible = false;
			this->bAddBetas->Click += gcnew System::EventHandler(this, &P_Discrete::bAddBetas_Click);
			// 
			// lvLUT
			// 
			this->lvLUT->Location = System::Drawing::Point(23, 168);
			this->lvLUT->MultiSelect = false;
			this->lvLUT->Name = L"lvLUT";
			this->lvLUT->Size = System::Drawing::Size(171, 291);
			this->lvLUT->TabIndex = 1;
			this->lvLUT->UseCompatibleStateImageBehavior = false;
			this->lvLUT->SelectedIndexChanged += gcnew System::EventHandler(this, &P_Discrete::lvLUT_SelectedIndexChanged);
			// 
			// tConst
			// 
			this->tConst->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst->Location = System::Drawing::Point(311, 172);
			this->tConst->Name = L"tConst";
			this->tConst->Size = System::Drawing::Size(161, 20);
			this->tConst->TabIndex = 2;
			this->tConst->Text = L"0.01";
			this->tConst->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst->Visible = false;
			this->tConst->Enter += gcnew System::EventHandler(this, &P_Discrete::textBox_Enter);
			// 
			// lConst
			// 
			this->lConst->AutoSize = true;
			this->lConst->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst->Location = System::Drawing::Point(252, 168);
			this->lConst->Name = L"lConst";
			this->lConst->Size = System::Drawing::Size(55, 23);
			this->lConst->TabIndex = 56;
			this->lConst->Text = L"Const";
			this->lConst->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst->Visible = false;
			// 
			// lBetas
			// 
			this->lBetas->AutoSize = true;
			this->lBetas->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas->Location = System::Drawing::Point(328, 214);
			this->lBetas->Name = L"lBetas";
			this->lBetas->Size = System::Drawing::Size(55, 23);
			this->lBetas->TabIndex = 58;
			this->lBetas->Text = L"Betas";
			this->lBetas->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas->Visible = false;
			// 
			// dgBetas
			// 
			this->dgBetas->AllowUserToResizeColumns = false;
			this->dgBetas->AllowUserToResizeRows = false;
			this->dgBetas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas->Location = System::Drawing::Point(231, 243);
			this->dgBetas->Name = L"dgBetas";
			this->dgBetas->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas->Size = System::Drawing::Size(245, 216);
			this->dgBetas->TabIndex = 5;
			this->dgBetas->Visible = false;
			this->dgBetas->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_Discrete::dgBetas_KeyDown);
			// 
			// tLUT
			// 
			this->tLUT->ForeColor = System::Drawing::Color::Black;
			this->tLUT->Location = System::Drawing::Point(23, 168);
			this->tLUT->Name = L"tLUT";
			this->tLUT->Size = System::Drawing::Size(161, 20);
			this->tLUT->TabIndex = 59;
			this->tLUT->Visible = false;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(263, 488);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 7;
			this->bCancel->Text = L"Cancelar";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Visible = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &P_Discrete::bCancel_Click);
			// 
			// tElasticy
			// 
			this->tElasticy->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tElasticy->Location = System::Drawing::Point(311, 214);
			this->tElasticy->Name = L"tElasticy";
			this->tElasticy->Size = System::Drawing::Size(161, 20);
			this->tElasticy->TabIndex = 3;
			this->tElasticy->Text = L"0.5";
			this->tElasticy->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tElasticy->Visible = false;
			this->tElasticy->Enter += gcnew System::EventHandler(this, &P_Discrete::textBox_Enter);
			// 
			// lElasticy
			// 
			this->lElasticy->AutoSize = true;
			this->lElasticy->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lElasticy->Location = System::Drawing::Point(228, 212);
			this->lElasticy->Name = L"lElasticy";
			this->lElasticy->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lElasticy->Size = System::Drawing::Size(81, 23);
			this->lElasticy->TabIndex = 62;
			this->lElasticy->Text = L"Elasticity";
			this->lElasticy->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lElasticy->Visible = false;
			// 
			// tPercNeighborsUse
			// 
			this->tPercNeighborsUse->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPercNeighborsUse->Location = System::Drawing::Point(400, 253);
			this->tPercNeighborsUse->Name = L"tPercNeighborsUse";
			this->tPercNeighborsUse->Size = System::Drawing::Size(72, 20);
			this->tPercNeighborsUse->TabIndex = 4;
			this->tPercNeighborsUse->Text = L"0.5";
			this->tPercNeighborsUse->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPercNeighborsUse->Visible = false;
			this->tPercNeighborsUse->Enter += gcnew System::EventHandler(this, &P_Discrete::textBox_Enter);
			// 
			// lPercNeighborsUse
			// 
			this->lPercNeighborsUse->AutoSize = true;
			this->lPercNeighborsUse->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPercNeighborsUse->Location = System::Drawing::Point(228, 253);
			this->lPercNeighborsUse->Name = L"lPercNeighborsUse";
			this->lPercNeighborsUse->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lPercNeighborsUse->Size = System::Drawing::Size(157, 23);
			this->lPercNeighborsUse->TabIndex = 64;
			this->lPercNeighborsUse->Text = L"percNeighborsUse";
			this->lPercNeighborsUse->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lPercNeighborsUse->Visible = false;
			// 
			// P_Discrete
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->tPercNeighborsUse);
			this->Controls->Add(this->lPercNeighborsUse);
			this->Controls->Add(this->tElasticy);
			this->Controls->Add(this->lElasticy);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->tLUT);
			this->Controls->Add(this->lBetas);
			this->Controls->Add(this->dgBetas);
			this->Controls->Add(this->tConst);
			this->Controls->Add(this->lConst);
			this->Controls->Add(this->bAddBetas);
			this->Controls->Add(this->lvLUT);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"P_Discrete";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pontencial - Discrete";
			this->Shown += gcnew System::EventHandler(this, &P_Discrete::P_Discrete_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void P_Discrete_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bAddBetas_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgView);
	private: System::Void dgBetas_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};
}

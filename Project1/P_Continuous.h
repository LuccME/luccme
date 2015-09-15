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
	/// Summary for P_Continuous
	/// </summary>
	public ref class P_Continuous : public System::Windows::Forms::Form
	{
	private:
		String^ gSLUT = "";
		String^ gSValues = "";
		String^ gSEmptyComponent = "";
		String^ gSEmptyComponentTitle = "";

	public:
		cReturnPotential^ lReturn;
		array<String^>^ lTempBetas = gcnew array<String^>(50);
		P_Continuous(cReturnPotential^ pPotencial)
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
		~P_Continuous()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tRo;
	private: System::Windows::Forms::Label^  lRo;
	private: System::Windows::Forms::TextBox^  tMinReg;
	private: System::Windows::Forms::Label^  lMinReg;
	private: System::Windows::Forms::TextBox^  tMaxReg;
	private: System::Windows::Forms::Label^  lMaxReg;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::TextBox^  tLUT;
	private: System::Windows::Forms::Label^  lBetas;
	private: System::Windows::Forms::DataGridView^  dgBetas;
	private: System::Windows::Forms::TextBox^  tConst;
	private: System::Windows::Forms::Label^  lConst;
	private: System::Windows::Forms::Button^  bAddBetas;
	private: System::Windows::Forms::ListView^  lvLUT;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::CheckBox^  cIsLog;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(P_Continuous::typeid));
			this->tRo = (gcnew System::Windows::Forms::TextBox());
			this->lRo = (gcnew System::Windows::Forms::Label());
			this->tMinReg = (gcnew System::Windows::Forms::TextBox());
			this->lMinReg = (gcnew System::Windows::Forms::Label());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->tLUT = (gcnew System::Windows::Forms::TextBox());
			this->lBetas = (gcnew System::Windows::Forms::Label());
			this->dgBetas = (gcnew System::Windows::Forms::DataGridView());
			this->tConst = (gcnew System::Windows::Forms::TextBox());
			this->lConst = (gcnew System::Windows::Forms::Label());
			this->bAddBetas = (gcnew System::Windows::Forms::Button());
			this->lvLUT = (gcnew System::Windows::Forms::ListView());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->cIsLog = (gcnew System::Windows::Forms::CheckBox());
			this->tMaxReg = (gcnew System::Windows::Forms::TextBox());
			this->lMaxReg = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// tRo
			// 
			this->tRo->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo->Location = System::Drawing::Point(300, 296);
			this->tRo->Name = L"tRo";
			this->tRo->Size = System::Drawing::Size(161, 20);
			this->tRo->TabIndex = 6;
			this->tRo->Text = L"0.5";
			this->tRo->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo->Visible = false;
			this->tRo->Enter += gcnew System::EventHandler(this, &P_Continuous::textBox_Enter);
			// 
			// lRo
			// 
			this->lRo->AutoSize = true;
			this->lRo->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo->Location = System::Drawing::Point(267, 293);
			this->lRo->Name = L"lRo";
			this->lRo->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo->Size = System::Drawing::Size(27, 23);
			this->lRo->TabIndex = 78;
			this->lRo->Text = L"ro";
			this->lRo->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo->Visible = false;
			// 
			// tMinReg
			// 
			this->tMinReg->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg->Location = System::Drawing::Point(279, 257);
			this->tMinReg->Name = L"tMinReg";
			this->tMinReg->Size = System::Drawing::Size(56, 20);
			this->tMinReg->TabIndex = 4;
			this->tMinReg->Text = L"0";
			this->tMinReg->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg->Visible = false;
			this->tMinReg->Enter += gcnew System::EventHandler(this, &P_Continuous::textBox_Enter);
			// 
			// lMinReg
			// 
			this->lMinReg->AutoSize = true;
			this->lMinReg->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg->Location = System::Drawing::Point(270, 232);
			this->lMinReg->Name = L"lMinReg";
			this->lMinReg->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg->Size = System::Drawing::Size(70, 23);
			this->lMinReg->TabIndex = 77;
			this->lMinReg->Text = L"minReg";
			this->lMinReg->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg->Visible = false;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(261, 526);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 9;
			this->bCancel->Text = L"Cancelar";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Visible = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &P_Continuous::bCancel_Click);
			// 
			// tLUT
			// 
			this->tLUT->ForeColor = System::Drawing::Color::Black;
			this->tLUT->Location = System::Drawing::Point(21, 158);
			this->tLUT->Name = L"tLUT";
			this->tLUT->Size = System::Drawing::Size(161, 20);
			this->tLUT->TabIndex = 76;
			this->tLUT->Visible = false;
			// 
			// lBetas
			// 
			this->lBetas->AutoSize = true;
			this->lBetas->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas->Location = System::Drawing::Point(326, 233);
			this->lBetas->Name = L"lBetas";
			this->lBetas->Size = System::Drawing::Size(55, 23);
			this->lBetas->TabIndex = 75;
			this->lBetas->Text = L"Betas";
			this->lBetas->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas->Visible = false;
			// 
			// dgBetas
			// 
			this->dgBetas->AllowUserToResizeColumns = false;
			this->dgBetas->AllowUserToResizeRows = false;
			this->dgBetas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas->Location = System::Drawing::Point(229, 262);
			this->dgBetas->Name = L"dgBetas";
			this->dgBetas->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas->Size = System::Drawing::Size(245, 246);
			this->dgBetas->TabIndex = 7;
			this->dgBetas->Visible = false;
			this->dgBetas->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_Continuous::dgBetas_KeyDown);
			// 
			// tConst
			// 
			this->tConst->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst->Location = System::Drawing::Point(300, 199);
			this->tConst->Name = L"tConst";
			this->tConst->Size = System::Drawing::Size(161, 20);
			this->tConst->TabIndex = 3;
			this->tConst->Text = L"0.01";
			this->tConst->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst->Visible = false;
			this->tConst->Enter += gcnew System::EventHandler(this, &P_Continuous::textBox_Enter);
			// 
			// lConst
			// 
			this->lConst->AutoSize = true;
			this->lConst->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst->Location = System::Drawing::Point(239, 198);
			this->lConst->Name = L"lConst";
			this->lConst->Size = System::Drawing::Size(55, 23);
			this->lConst->TabIndex = 74;
			this->lConst->Text = L"Const";
			this->lConst->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst->Visible = false;
			// 
			// bAddBetas
			// 
			this->bAddBetas->Location = System::Drawing::Point(365, 526);
			this->bAddBetas->Name = L"bAddBetas";
			this->bAddBetas->Size = System::Drawing::Size(75, 23);
			this->bAddBetas->TabIndex = 8;
			this->bAddBetas->Text = L"Adicionar";
			this->bAddBetas->UseVisualStyleBackColor = true;
			this->bAddBetas->Visible = false;
			this->bAddBetas->Click += gcnew System::EventHandler(this, &P_Continuous::bAddBetas_Click);
			// 
			// lvLUT
			// 
			this->lvLUT->Location = System::Drawing::Point(21, 157);
			this->lvLUT->MultiSelect = false;
			this->lvLUT->Name = L"lvLUT";
			this->lvLUT->Size = System::Drawing::Size(171, 351);
			this->lvLUT->TabIndex = 1;
			this->lvLUT->UseCompatibleStateImageBehavior = false;
			this->lvLUT->SelectedIndexChanged += gcnew System::EventHandler(this, &P_Continuous::lvLUT_SelectedIndexChanged);
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(219, 526);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 10;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &P_Continuous::bSalvar_Click);
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(58, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 73;
			this->pbLogo1->TabStop = false;
			// 
			// cIsLog
			// 
			this->cIsLog->AutoSize = true;
			this->cIsLog->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog->Location = System::Drawing::Point(243, 157);
			this->cIsLog->Name = L"cIsLog";
			this->cIsLog->Size = System::Drawing::Size(69, 27);
			this->cIsLog->TabIndex = 2;
			this->cIsLog->Text = L"isLog";
			this->cIsLog->UseVisualStyleBackColor = true;
			this->cIsLog->Visible = false;
			// 
			// tMaxReg
			// 
			this->tMaxReg->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg->Location = System::Drawing::Point(381, 257);
			this->tMaxReg->Name = L"tMaxReg";
			this->tMaxReg->Size = System::Drawing::Size(56, 20);
			this->tMaxReg->TabIndex = 5;
			this->tMaxReg->Text = L"1";
			this->tMaxReg->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg->Visible = false;
			this->tMaxReg->Enter += gcnew System::EventHandler(this, &P_Continuous::textBox_Enter);
			// 
			// lMaxReg
			// 
			this->lMaxReg->AutoSize = true;
			this->lMaxReg->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg->Location = System::Drawing::Point(372, 232);
			this->lMaxReg->Name = L"lMaxReg";
			this->lMaxReg->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg->Size = System::Drawing::Size(73, 23);
			this->lMaxReg->TabIndex = 81;
			this->lMaxReg->Text = L"maxReg";
			this->lMaxReg->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg->Visible = false;
			// 
			// P_Continuous
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 566);
			this->Controls->Add(this->tMinReg);
			this->Controls->Add(this->tMaxReg);
			this->Controls->Add(this->cIsLog);
			this->Controls->Add(this->tRo);
			this->Controls->Add(this->lRo);
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
			this->Controls->Add(this->lMaxReg);
			this->Controls->Add(this->lMinReg);
			this->Name = L"P_Continuous";
			this->Text = L"Potencial - Continuous";
			this->Shown += gcnew System::EventHandler(this, &P_Continuous::P_Continuous_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void P_Continuous_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bAddBetas_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgView);
	private: System::Void dgBetas_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
};
}

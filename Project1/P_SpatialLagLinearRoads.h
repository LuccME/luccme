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
	/// Summary for P_SpatialLagLinearRoads
	/// </summary>
	public ref class P_SpatialLagLinearRoads : public System::Windows::Forms::Form
	{
	private:
		String^ gSLUT = "";
		String^ gSValues = "";
		String^ gSAttributes = "";
		String^ gSEmptyComponent = "";
		String^ gSEmptyComponentTitle = "";

	public:
		cReturnPotential^ lReturn;
		array<String^>^ lTempBetas = gcnew array<String^>(50);
		array<String^>^ lTempBetasRM = gcnew array<String^>(50);
		array<String^>^ lTempAttributes = gcnew array<String^>(50);
		P_SpatialLagLinearRoads(cReturnPotential^ pPotencial)
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
		~P_SpatialLagLinearRoads()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tMinReg;
	protected:
	private: System::Windows::Forms::TextBox^  tMaxReg;
	private: System::Windows::Forms::CheckBox^  cIsLog;
	private: System::Windows::Forms::TextBox^  tRo;
	private: System::Windows::Forms::Label^  lRo;
	private: System::Windows::Forms::Button^  bCancel;
	private: System::Windows::Forms::TextBox^  tLUT;
	private: System::Windows::Forms::Label^  lBetas;
	private: System::Windows::Forms::DataGridView^  dgBetas;
	private: System::Windows::Forms::TextBox^  tConst;
	private: System::Windows::Forms::Label^  lConst;
	private: System::Windows::Forms::Button^  bAddData;
	private: System::Windows::Forms::ListView^  lvLUT;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Label^  lMaxReg;
	private: System::Windows::Forms::Label^  lMinReg;
	private: System::Windows::Forms::Button^  bRoadsModel;
	private: System::Windows::Forms::DataGridView^  dgBetasRM;

	private: System::Windows::Forms::Label^  lBetasRM;
	private: System::Windows::Forms::TextBox^  tConstRM;
	private: System::Windows::Forms::Label^  lConstRM;
	private: System::Windows::Forms::TextBox^  tChangeRM;
	private: System::Windows::Forms::Label^  lChangeRM;
	private: System::Windows::Forms::Label^  lAttributesRM;
	private: System::Windows::Forms::DataGridView^  dgAttr;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(P_SpatialLagLinearRoads::typeid));
			this->tMinReg = (gcnew System::Windows::Forms::TextBox());
			this->tMaxReg = (gcnew System::Windows::Forms::TextBox());
			this->cIsLog = (gcnew System::Windows::Forms::CheckBox());
			this->tRo = (gcnew System::Windows::Forms::TextBox());
			this->lRo = (gcnew System::Windows::Forms::Label());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->tLUT = (gcnew System::Windows::Forms::TextBox());
			this->lBetas = (gcnew System::Windows::Forms::Label());
			this->dgBetas = (gcnew System::Windows::Forms::DataGridView());
			this->tConst = (gcnew System::Windows::Forms::TextBox());
			this->lConst = (gcnew System::Windows::Forms::Label());
			this->bAddData = (gcnew System::Windows::Forms::Button());
			this->lvLUT = (gcnew System::Windows::Forms::ListView());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->lMaxReg = (gcnew System::Windows::Forms::Label());
			this->lMinReg = (gcnew System::Windows::Forms::Label());
			this->bRoadsModel = (gcnew System::Windows::Forms::Button());
			this->dgBetasRM = (gcnew System::Windows::Forms::DataGridView());
			this->lBetasRM = (gcnew System::Windows::Forms::Label());
			this->tConstRM = (gcnew System::Windows::Forms::TextBox());
			this->lConstRM = (gcnew System::Windows::Forms::Label());
			this->tChangeRM = (gcnew System::Windows::Forms::TextBox());
			this->lChangeRM = (gcnew System::Windows::Forms::Label());
			this->lAttributesRM = (gcnew System::Windows::Forms::Label());
			this->dgAttr = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetasRM))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAttr))->BeginInit();
			this->SuspendLayout();
			// 
			// tMinReg
			// 
			this->tMinReg->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMinReg->Location = System::Drawing::Point(276, 257);
			this->tMinReg->Name = L"tMinReg";
			this->tMinReg->Size = System::Drawing::Size(56, 20);
			this->tMinReg->TabIndex = 4;
			this->tMinReg->Text = L"0";
			this->tMinReg->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMinReg->Visible = false;
			this->tMinReg->Enter += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::textBox_Enter);
			// 
			// tMaxReg
			// 
			this->tMaxReg->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxReg->Location = System::Drawing::Point(378, 257);
			this->tMaxReg->Name = L"tMaxReg";
			this->tMaxReg->Size = System::Drawing::Size(56, 20);
			this->tMaxReg->TabIndex = 5;
			this->tMaxReg->Text = L"1";
			this->tMaxReg->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxReg->Visible = false;
			this->tMaxReg->Enter += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::textBox_Enter);
			// 
			// cIsLog
			// 
			this->cIsLog->AutoSize = true;
			this->cIsLog->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cIsLog->Location = System::Drawing::Point(240, 157);
			this->cIsLog->Name = L"cIsLog";
			this->cIsLog->Size = System::Drawing::Size(69, 27);
			this->cIsLog->TabIndex = 2;
			this->cIsLog->Text = L"isLog";
			this->cIsLog->UseVisualStyleBackColor = true;
			this->cIsLog->Visible = false;
			// 
			// tRo
			// 
			this->tRo->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tRo->Location = System::Drawing::Point(297, 296);
			this->tRo->Name = L"tRo";
			this->tRo->Size = System::Drawing::Size(161, 20);
			this->tRo->TabIndex = 6;
			this->tRo->Text = L"0.5";
			this->tRo->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tRo->Visible = false;
			this->tRo->Enter += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::textBox_Enter);
			// 
			// lRo
			// 
			this->lRo->AutoSize = true;
			this->lRo->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRo->Location = System::Drawing::Point(264, 293);
			this->lRo->Name = L"lRo";
			this->lRo->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lRo->Size = System::Drawing::Size(27, 23);
			this->lRo->TabIndex = 97;
			this->lRo->Text = L"ro";
			this->lRo->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lRo->Visible = false;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(226, 526);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 9;
			this->bCancel->Text = L"Cancelar";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Visible = false;
			this->bCancel->Click += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::bCancel_Click);
			// 
			// tLUT
			// 
			this->tLUT->ForeColor = System::Drawing::Color::Black;
			this->tLUT->Location = System::Drawing::Point(18, 158);
			this->tLUT->Name = L"tLUT";
			this->tLUT->Size = System::Drawing::Size(161, 20);
			this->tLUT->TabIndex = 95;
			this->tLUT->Visible = false;
			// 
			// lBetas
			// 
			this->lBetas->AutoSize = true;
			this->lBetas->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetas->Location = System::Drawing::Point(326, 333);
			this->lBetas->Name = L"lBetas";
			this->lBetas->Size = System::Drawing::Size(55, 23);
			this->lBetas->TabIndex = 94;
			this->lBetas->Text = L"Betas";
			this->lBetas->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lBetas->Visible = false;
			// 
			// dgBetas
			// 
			this->dgBetas->AllowUserToResizeColumns = false;
			this->dgBetas->AllowUserToResizeRows = false;
			this->dgBetas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetas->Location = System::Drawing::Point(226, 359);
			this->dgBetas->Name = L"dgBetas";
			this->dgBetas->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetas->Size = System::Drawing::Size(245, 149);
			this->dgBetas->TabIndex = 7;
			this->dgBetas->Visible = false;
			this->dgBetas->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_SpatialLagLinearRoads::dgBetas_KeyDown);
			// 
			// tConst
			// 
			this->tConst->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConst->Location = System::Drawing::Point(297, 199);
			this->tConst->Name = L"tConst";
			this->tConst->Size = System::Drawing::Size(161, 20);
			this->tConst->TabIndex = 3;
			this->tConst->Text = L"0.01";
			this->tConst->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConst->Visible = false;
			this->tConst->Enter += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::textBox_Enter);
			// 
			// lConst
			// 
			this->lConst->AutoSize = true;
			this->lConst->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConst->Location = System::Drawing::Point(236, 198);
			this->lConst->Name = L"lConst";
			this->lConst->Size = System::Drawing::Size(55, 23);
			this->lConst->TabIndex = 93;
			this->lConst->Text = L"Const";
			this->lConst->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConst->Visible = false;
			// 
			// bAddData
			// 
			this->bAddData->Location = System::Drawing::Point(635, 526);
			this->bAddData->Name = L"bAddData";
			this->bAddData->Size = System::Drawing::Size(120, 23);
			this->bAddData->TabIndex = 14;
			this->bAddData->Text = L"Adicionar Dados";
			this->bAddData->UseVisualStyleBackColor = true;
			this->bAddData->Visible = false;
			this->bAddData->Click += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::bAddData_Click);
			// 
			// lvLUT
			// 
			this->lvLUT->Location = System::Drawing::Point(18, 157);
			this->lvLUT->MultiSelect = false;
			this->lvLUT->Name = L"lvLUT";
			this->lvLUT->Size = System::Drawing::Size(171, 351);
			this->lvLUT->TabIndex = 1;
			this->lvLUT->UseCompatibleStateImageBehavior = false;
			this->lvLUT->SelectedIndexChanged += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::lvLUT_SelectedIndexChanged);
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(177, 526);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 15;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::bSalvar_Click);
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(58, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 92;
			this->pbLogo1->TabStop = false;
			// 
			// lMaxReg
			// 
			this->lMaxReg->AutoSize = true;
			this->lMaxReg->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxReg->Location = System::Drawing::Point(369, 232);
			this->lMaxReg->Name = L"lMaxReg";
			this->lMaxReg->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMaxReg->Size = System::Drawing::Size(73, 23);
			this->lMaxReg->TabIndex = 98;
			this->lMaxReg->Text = L"maxReg";
			this->lMaxReg->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMaxReg->Visible = false;
			// 
			// lMinReg
			// 
			this->lMinReg->AutoSize = true;
			this->lMinReg->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMinReg->Location = System::Drawing::Point(267, 232);
			this->lMinReg->Name = L"lMinReg";
			this->lMinReg->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lMinReg->Size = System::Drawing::Size(70, 23);
			this->lMinReg->TabIndex = 96;
			this->lMinReg->Text = L"minReg";
			this->lMinReg->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lMinReg->Visible = false;
			// 
			// bRoadsModel
			// 
			this->bRoadsModel->Location = System::Drawing::Point(378, 526);
			this->bRoadsModel->Name = L"bRoadsModel";
			this->bRoadsModel->Size = System::Drawing::Size(93, 23);
			this->bRoadsModel->TabIndex = 8;
			this->bRoadsModel->Text = L"RoadsModel >>";
			this->bRoadsModel->UseVisualStyleBackColor = true;
			this->bRoadsModel->Visible = false;
			this->bRoadsModel->Click += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::bRoadsModel_Click);
			// 
			// dgBetasRM
			// 
			this->dgBetasRM->AllowUserToResizeColumns = false;
			this->dgBetasRM->AllowUserToResizeRows = false;
			this->dgBetasRM->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgBetasRM->Location = System::Drawing::Point(567, 386);
			this->dgBetasRM->Name = L"dgBetasRM";
			this->dgBetasRM->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgBetasRM->Size = System::Drawing::Size(245, 122);
			this->dgBetasRM->TabIndex = 13;
			this->dgBetasRM->Visible = false;
			this->dgBetasRM->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_SpatialLagLinearRoads::dgBetasRM_KeyDown);
			// 
			// lBetasRM
			// 
			this->lBetasRM->AutoSize = true;
			this->lBetasRM->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lBetasRM->Location = System::Drawing::Point(614, 359);
			this->lBetasRM->Name = L"lBetasRM";
			this->lBetasRM->Size = System::Drawing::Size(163, 23);
			this->lBetasRM->TabIndex = 101;
			this->lBetasRM->Text = L"Roads Model Betas";
			this->lBetasRM->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lBetasRM->Visible = false;
			// 
			// tConstRM
			// 
			this->tConstRM->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tConstRM->Location = System::Drawing::Point(635, 280);
			this->tConstRM->Name = L"tConstRM";
			this->tConstRM->Size = System::Drawing::Size(161, 20);
			this->tConstRM->TabIndex = 11;
			this->tConstRM->Text = L"0.01";
			this->tConstRM->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tConstRM->Visible = false;
			this->tConstRM->Enter += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::textBox_Enter);
			// 
			// lConstRM
			// 
			this->lConstRM->AutoSize = true;
			this->lConstRM->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lConstRM->Location = System::Drawing::Point(574, 279);
			this->lConstRM->Name = L"lConstRM";
			this->lConstRM->Size = System::Drawing::Size(55, 23);
			this->lConstRM->TabIndex = 103;
			this->lConstRM->Text = L"Const";
			this->lConstRM->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lConstRM->Visible = false;
			// 
			// tChangeRM
			// 
			this->tChangeRM->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tChangeRM->Location = System::Drawing::Point(635, 319);
			this->tChangeRM->Name = L"tChangeRM";
			this->tChangeRM->Size = System::Drawing::Size(161, 20);
			this->tChangeRM->TabIndex = 12;
			this->tChangeRM->Text = L"-1.5";
			this->tChangeRM->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tChangeRM->Visible = false;
			this->tChangeRM->Enter += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::textBox_Enter);
			// 
			// lChangeRM
			// 
			this->lChangeRM->AutoSize = true;
			this->lChangeRM->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lChangeRM->Location = System::Drawing::Point(564, 318);
			this->lChangeRM->Name = L"lChangeRM";
			this->lChangeRM->Size = System::Drawing::Size(68, 23);
			this->lChangeRM->TabIndex = 105;
			this->lChangeRM->Text = L"Change";
			this->lChangeRM->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lChangeRM->Visible = false;
			// 
			// lAttributesRM
			// 
			this->lAttributesRM->AutoSize = true;
			this->lAttributesRM->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAttributesRM->Location = System::Drawing::Point(598, 156);
			this->lAttributesRM->Name = L"lAttributesRM";
			this->lAttributesRM->Size = System::Drawing::Size(198, 23);
			this->lAttributesRM->TabIndex = 107;
			this->lAttributesRM->Text = L"Roads Model Attributes";
			this->lAttributesRM->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lAttributesRM->Visible = false;
			// 
			// dgAttr
			// 
			this->dgAttr->AllowUserToResizeColumns = false;
			this->dgAttr->AllowUserToResizeRows = false;
			this->dgAttr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAttr->Location = System::Drawing::Point(568, 182);
			this->dgAttr->Name = L"dgAttr";
			this->dgAttr->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAttr->Size = System::Drawing::Size(245, 85);
			this->dgAttr->TabIndex = 10;
			this->dgAttr->Visible = false;
			this->dgAttr->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_SpatialLagLinearRoads::dgAttr_KeyDown);
			// 
			// P_SpatialLagLinearRoads
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(888, 566);
			this->Controls->Add(this->dgBetasRM);
			this->Controls->Add(this->dgBetas);
			this->Controls->Add(this->dgAttr);
			this->Controls->Add(this->tChangeRM);
			this->Controls->Add(this->lChangeRM);
			this->Controls->Add(this->tConstRM);
			this->Controls->Add(this->lConstRM);
			this->Controls->Add(this->bRoadsModel);
			this->Controls->Add(this->tMinReg);
			this->Controls->Add(this->tMaxReg);
			this->Controls->Add(this->cIsLog);
			this->Controls->Add(this->tRo);
			this->Controls->Add(this->lRo);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->tLUT);
			this->Controls->Add(this->tConst);
			this->Controls->Add(this->lConst);
			this->Controls->Add(this->bAddData);
			this->Controls->Add(this->lvLUT);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->pbLogo1);
			this->Controls->Add(this->lMaxReg);
			this->Controls->Add(this->lMinReg);
			this->Controls->Add(this->lAttributesRM);
			this->Controls->Add(this->lBetas);
			this->Controls->Add(this->lBetasRM);
			this->Name = L"P_SpatialLagLinearRoads";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Potencial - Spatial Lag Linear Roads";
			this->Shown += gcnew System::EventHandler(this, &P_SpatialLagLinearRoads::P_SpatialLagLinearRoads_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgBetasRM))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAttr))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void P_SpatialLagLinearRoads_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bRoadsModel_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bCancel_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bAddData_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgView);
	private: System::Void dgBetas_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void dgAttr_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void dgBetasRM_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};
}

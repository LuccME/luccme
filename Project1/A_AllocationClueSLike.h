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
	/// Summary for A_AllocationClueSLike
	/// </summary>
	public ref class A_AllocationClueSLike : public System::Windows::Forms::Form
	{
	public:
		cReturnAllocation^ lReturn;
		A_AllocationClueSLike(cReturnAllocation^ pAllocation)
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
		~A_AllocationClueSLike()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::TextBox^  tMaxIteration;
	private: System::Windows::Forms::Label^  lMaxIteration;
	private: System::Windows::Forms::TextBox^  tFactorInteration;
	private: System::Windows::Forms::Label^  lFactorInteration;
	private: System::Windows::Forms::TextBox^  tMaxDifference;

	private: System::Windows::Forms::Label^  lMaxDifference;
	private: System::Windows::Forms::Label^  lTransitionMatrix;
	private: System::Windows::Forms::DataGridView^  dgTransitionMatrix;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(A_AllocationClueSLike::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->tMaxIteration = (gcnew System::Windows::Forms::TextBox());
			this->lMaxIteration = (gcnew System::Windows::Forms::Label());
			this->tFactorInteration = (gcnew System::Windows::Forms::TextBox());
			this->lFactorInteration = (gcnew System::Windows::Forms::Label());
			this->tMaxDifference = (gcnew System::Windows::Forms::TextBox());
			this->lMaxDifference = (gcnew System::Windows::Forms::Label());
			this->lTransitionMatrix = (gcnew System::Windows::Forms::Label());
			this->dgTransitionMatrix = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgTransitionMatrix))->BeginInit();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(58, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 17;
			this->pbLogo1->TabStop = false;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(203, 496);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 87;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &A_AllocationClueSLike::bSalvar_Click);
			// 
			// tMaxIteration
			// 
			this->tMaxIteration->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxIteration->Location = System::Drawing::Point(207, 166);
			this->tMaxIteration->Name = L"tMaxIteration";
			this->tMaxIteration->Size = System::Drawing::Size(194, 20);
			this->tMaxIteration->TabIndex = 88;
			this->tMaxIteration->Text = L"1000";
			this->tMaxIteration->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxIteration->Enter += gcnew System::EventHandler(this, &A_AllocationClueSLike::textBox_Enter);
			// 
			// lMaxIteration
			// 
			this->lMaxIteration->AutoSize = true;
			this->lMaxIteration->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxIteration->Location = System::Drawing::Point(73, 163);
			this->lMaxIteration->Name = L"lMaxIteration";
			this->lMaxIteration->Size = System::Drawing::Size(112, 23);
			this->lMaxIteration->TabIndex = 89;
			this->lMaxIteration->Text = L"maxIteration";
			this->lMaxIteration->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tFactorInteration
			// 
			this->tFactorInteration->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tFactorInteration->Location = System::Drawing::Point(207, 210);
			this->tFactorInteration->Name = L"tFactorInteration";
			this->tFactorInteration->Size = System::Drawing::Size(194, 20);
			this->tFactorInteration->TabIndex = 90;
			this->tFactorInteration->Text = L"0.000001";
			this->tFactorInteration->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tFactorInteration->Enter += gcnew System::EventHandler(this, &A_AllocationClueSLike::textBox_Enter);
			// 
			// lFactorInteration
			// 
			this->lFactorInteration->AutoSize = true;
			this->lFactorInteration->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lFactorInteration->Location = System::Drawing::Point(72, 207);
			this->lFactorInteration->Name = L"lFactorInteration";
			this->lFactorInteration->Size = System::Drawing::Size(126, 23);
			this->lFactorInteration->TabIndex = 91;
			this->lFactorInteration->Text = L"factorIteration";
			this->lFactorInteration->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tMaxDifference
			// 
			this->tMaxDifference->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMaxDifference->Location = System::Drawing::Point(207, 252);
			this->tMaxDifference->Name = L"tMaxDifference";
			this->tMaxDifference->Size = System::Drawing::Size(194, 20);
			this->tMaxDifference->TabIndex = 92;
			this->tMaxDifference->Text = L"0.01";
			this->tMaxDifference->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMaxDifference->Enter += gcnew System::EventHandler(this, &A_AllocationClueSLike::textBox_Enter);
			// 
			// lMaxDifference
			// 
			this->lMaxDifference->AutoSize = true;
			this->lMaxDifference->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxDifference->Location = System::Drawing::Point(72, 251);
			this->lMaxDifference->Name = L"lMaxDifference";
			this->lMaxDifference->Size = System::Drawing::Size(126, 23);
			this->lMaxDifference->TabIndex = 93;
			this->lMaxDifference->Text = L"maxDifference";
			this->lMaxDifference->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lTransitionMatrix
			// 
			this->lTransitionMatrix->AutoSize = true;
			this->lTransitionMatrix->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lTransitionMatrix->Location = System::Drawing::Point(169, 305);
			this->lTransitionMatrix->Name = L"lTransitionMatrix";
			this->lTransitionMatrix->Size = System::Drawing::Size(146, 23);
			this->lTransitionMatrix->TabIndex = 95;
			this->lTransitionMatrix->Text = L"Transition Matrix";
			this->lTransitionMatrix->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// dgTransitionMatrix
			// 
			this->dgTransitionMatrix->AllowUserToAddRows = false;
			this->dgTransitionMatrix->AllowUserToDeleteRows = false;
			this->dgTransitionMatrix->AllowUserToResizeColumns = false;
			this->dgTransitionMatrix->AllowUserToResizeRows = false;
			this->dgTransitionMatrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgTransitionMatrix->Location = System::Drawing::Point(47, 341);
			this->dgTransitionMatrix->Name = L"dgTransitionMatrix";
			this->dgTransitionMatrix->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgTransitionMatrix->Size = System::Drawing::Size(390, 135);
			this->dgTransitionMatrix->TabIndex = 94;
			this->dgTransitionMatrix->CellValidating += gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &A_AllocationClueSLike::dgTransitionMatrix_CellValidating);
			this->dgTransitionMatrix->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &A_AllocationClueSLike::dgTransitionMatrix_KeyDown);
			// 
			// A_AllocationClueSLike
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->lTransitionMatrix);
			this->Controls->Add(this->dgTransitionMatrix);
			this->Controls->Add(this->tMaxDifference);
			this->Controls->Add(this->lMaxDifference);
			this->Controls->Add(this->tFactorInteration);
			this->Controls->Add(this->lFactorInteration);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->tMaxIteration);
			this->Controls->Add(this->lMaxIteration);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"A_AllocationClueSLike";
			this->Text = L"Alocação - Allocation ClueS Like";
			this->Shown += gcnew System::EventHandler(this, &A_AllocationClueSLike::A_AllocationClueSLike_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgTransitionMatrix))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void A_AllocationClueSLike_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void dgTransitionMatrix_CellValidating(System::Object^  sender, System::Windows::Forms::DataGridViewCellValidatingEventArgs^  e);
	private: System::Void dgTransitionMatrix_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgView);
};
}

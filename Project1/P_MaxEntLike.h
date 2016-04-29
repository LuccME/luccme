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
	/// Summary for P_MaxEntLike
	/// </summary>
	public ref class P_MaxEntLike : public System::Windows::Forms::Form
	{
	private:
		String^ gSAttributes = "";

	public:
		cReturnPotential^ lReturn;
		P_MaxEntLike(cReturnPotential^ pPotencial)
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
		~P_MaxEntLike()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::DataGridView^  dgAttrPerc;

	private: System::Windows::Forms::Label^  lAttrPerc;

	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::TextBox^  tUsePerc;
	private: System::Windows::Forms::Label^  lUsePerc;
	private: System::Windows::Forms::DataGridView^  dgAttrClass;
	private: System::Windows::Forms::Label^  lAttrClass;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(P_MaxEntLike::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->dgAttrPerc = (gcnew System::Windows::Forms::DataGridView());
			this->lAttrPerc = (gcnew System::Windows::Forms::Label());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->tUsePerc = (gcnew System::Windows::Forms::TextBox());
			this->lUsePerc = (gcnew System::Windows::Forms::Label());
			this->dgAttrClass = (gcnew System::Windows::Forms::DataGridView());
			this->lAttrClass = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAttrPerc))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAttrClass))->BeginInit();
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
			// dgAttrPerc
			// 
			this->dgAttrPerc->AllowUserToResizeColumns = false;
			this->dgAttrPerc->AllowUserToResizeRows = false;
			this->dgAttrPerc->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAttrPerc->Location = System::Drawing::Point(27, 240);
			this->dgAttrPerc->Name = L"dgAttrPerc";
			this->dgAttrPerc->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAttrPerc->Size = System::Drawing::Size(204, 242);
			this->dgAttrPerc->TabIndex = 108;
			this->dgAttrPerc->Visible = false;
			// 
			// lAttrPerc
			// 
			this->lAttrPerc->AutoSize = true;
			this->lAttrPerc->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAttrPerc->Location = System::Drawing::Point(38, 214);
			this->lAttrPerc->Name = L"lAttrPerc";
			this->lAttrPerc->Size = System::Drawing::Size(183, 23);
			this->lAttrPerc->TabIndex = 109;
			this->lAttrPerc->Text = L"Atributos Percentuais";
			this->lAttrPerc->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lAttrPerc->Visible = false;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(210, 500);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 110;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			// 
			// tUsePerc
			// 
			this->tUsePerc->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tUsePerc->Location = System::Drawing::Point(286, 175);
			this->tUsePerc->Name = L"tUsePerc";
			this->tUsePerc->Size = System::Drawing::Size(67, 20);
			this->tUsePerc->TabIndex = 111;
			this->tUsePerc->Text = L"75";
			this->tUsePerc->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tUsePerc->Visible = false;
			this->tUsePerc->Enter += gcnew System::EventHandler(this, &P_MaxEntLike::textBox_Enter);
			// 
			// lUsePerc
			// 
			this->lUsePerc->AutoSize = true;
			this->lUsePerc->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lUsePerc->Location = System::Drawing::Point(140, 173);
			this->lUsePerc->Name = L"lUsePerc";
			this->lUsePerc->Size = System::Drawing::Size(140, 23);
			this->lUsePerc->TabIndex = 112;
			this->lUsePerc->Text = L"% Uso por célula";
			this->lUsePerc->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lUsePerc->Visible = false;
			// 
			// dgAttrClass
			// 
			this->dgAttrClass->AllowUserToResizeColumns = false;
			this->dgAttrClass->AllowUserToResizeRows = false;
			this->dgAttrClass->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAttrClass->Location = System::Drawing::Point(265, 240);
			this->dgAttrClass->Name = L"dgAttrClass";
			this->dgAttrClass->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAttrClass->Size = System::Drawing::Size(204, 242);
			this->dgAttrClass->TabIndex = 113;
			this->dgAttrClass->Visible = false;
			// 
			// lAttrClass
			// 
			this->lAttrClass->AutoSize = true;
			this->lAttrClass->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAttrClass->Location = System::Drawing::Point(278, 214);
			this->lAttrClass->Name = L"lAttrClass";
			this->lAttrClass->Size = System::Drawing::Size(182, 23);
			this->lAttrClass->TabIndex = 114;
			this->lAttrClass->Text = L"Atributos Categóricos";
			this->lAttrClass->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lAttrClass->Visible = false;
			// 
			// P_MaxEntLike
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->lAttrClass);
			this->Controls->Add(this->dgAttrClass);
			this->Controls->Add(this->tUsePerc);
			this->Controls->Add(this->lUsePerc);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->dgAttrPerc);
			this->Controls->Add(this->lAttrPerc);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"P_MaxEntLike";
			this->Text = L"MaxEnt Like";
			this->Shown += gcnew System::EventHandler(this, &P_MaxEntLike::P_MaxEntLike_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAttrPerc))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAttrClass))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void P_MaxEntLike_Shown(System::Object^  sender, System::EventArgs^  e);
};
}

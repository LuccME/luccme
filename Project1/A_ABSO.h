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
	/// Summary for A_ABSO
	/// </summary>
	public ref class A_ABSO : public System::Windows::Forms::Form
	{
	public:
		cReturnAllocation^ lReturn;
		A_ABSO(cReturnAllocation^ pAllocation)
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
		~A_ABSO()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Label^  lMaxDifference;
	private: System::Windows::Forms::TextBox^  tMAxDifference;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::Label^  lMaxDiffHelp;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(A_ABSO::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->lMaxDifference = (gcnew System::Windows::Forms::Label());
			this->tMAxDifference = (gcnew System::Windows::Forms::TextBox());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->lMaxDiffHelp = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
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
			// lMaxDifference
			// 
			this->lMaxDifference->AutoSize = true;
			this->lMaxDifference->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxDifference->Location = System::Drawing::Point(64, 276);
			this->lMaxDifference->Name = L"lMaxDifference";
			this->lMaxDifference->Size = System::Drawing::Size(126, 23);
			this->lMaxDifference->TabIndex = 86;
			this->lMaxDifference->Text = L"maxDifference";
			this->lMaxDifference->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tMAxDifference
			// 
			this->tMAxDifference->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tMAxDifference->Location = System::Drawing::Point(227, 279);
			this->tMAxDifference->Name = L"tMAxDifference";
			this->tMAxDifference->Size = System::Drawing::Size(194, 20);
			this->tMAxDifference->TabIndex = 2;
			this->tMAxDifference->Text = L"150";
			this->tMAxDifference->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tMAxDifference->Enter += gcnew System::EventHandler(this, &A_ABSO::tMAxDifference_Enter);
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(203, 483);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 1;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &A_ABSO::bSalvar_Click);
			// 
			// lMaxDiffHelp
			// 
			this->lMaxDiffHelp->AutoSize = true;
			this->lMaxDiffHelp->Font = (gcnew System::Drawing::Font(L"Calibri", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMaxDiffHelp->Location = System::Drawing::Point(287, 302);
			this->lMaxDiffHelp->Name = L"lMaxDiffHelp";
			this->lMaxDiffHelp->Size = System::Drawing::Size(75, 13);
			this->lMaxDiffHelp->TabIndex = 121;
			this->lMaxDiffHelp->Text = L"Valor Absoluto";
			this->lMaxDiffHelp->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// A_ABSO
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->lMaxDiffHelp);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->tMAxDifference);
			this->Controls->Add(this->lMaxDifference);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"A_ABSO";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Allocation - Simple Ordering";
			this->Shown += gcnew System::EventHandler(this, &A_ABSO::A_ABSO_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void tMAxDifference_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void A_ABSO_Shown(System::Object^  sender, System::EventArgs^  e);
};
}

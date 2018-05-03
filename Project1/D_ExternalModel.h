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
	/// Summary for D_ExternalModel
	/// </summary>
	public ref class D_ExternalModel : public System::Windows::Forms::Form
	{
	private:
		String^ gSExternalFileTitle = "";
		String^ gSExternalFileFilter = "";

	public:
		cReturnExtModel^ lReturn;
		D_ExternalModel(cReturnExtModel^ pDemand)
		{
			InitializeComponent();
			lReturn = pDemand;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~D_ExternalModel()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::Button^  bFile;
	private: System::Windows::Forms::Label^  lFile;
	private: System::Windows::Forms::TextBox^  tbSelectedFile;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(D_ExternalModel::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->bFile = (gcnew System::Windows::Forms::Button());
			this->lFile = (gcnew System::Windows::Forms::Label());
			this->tbSelectedFile = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(56, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 17;
			this->pbLogo1->TabStop = false;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(202, 475);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 18;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &D_ExternalModel::bSalvar_Click);
			// 
			// bFile
			// 
			this->bFile->Location = System::Drawing::Point(202, 314);
			this->bFile->Name = L"bFile";
			this->bFile->Size = System::Drawing::Size(75, 23);
			this->bFile->TabIndex = 94;
			this->bFile->Text = L"Selecionar";
			this->bFile->UseVisualStyleBackColor = true;
			this->bFile->Click += gcnew System::EventHandler(this, &D_ExternalModel::bFile_Click);
			// 
			// lFile
			// 
			this->lFile->AutoSize = true;
			this->lFile->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lFile->Location = System::Drawing::Point(203, 238);
			this->lFile->Name = L"lFile";
			this->lFile->Size = System::Drawing::Size(73, 23);
			this->lFile->TabIndex = 93;
			this->lFile->Text = L"Arquivo";
			this->lFile->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tbSelectedFile
			// 
			this->tbSelectedFile->BackColor = System::Drawing::SystemColors::Window;
			this->tbSelectedFile->Location = System::Drawing::Point(56, 277);
			this->tbSelectedFile->Name = L"tbSelectedFile";
			this->tbSelectedFile->Size = System::Drawing::Size(367, 20);
			this->tbSelectedFile->TabIndex = 95;
			// 
			// D_ExternalModel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->tbSelectedFile);
			this->Controls->Add(this->bFile);
			this->Controls->Add(this->lFile);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"D_ExternalModel";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"D_ExternalModel";
			this->Shown += gcnew System::EventHandler(this, &D_ExternalModel::D_ExternalModel_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void D_ExternalModel_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bFile_Click(System::Object^  sender, System::EventArgs^  e);
};
}

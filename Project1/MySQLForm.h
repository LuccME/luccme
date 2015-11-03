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
	/// Summary for MySQLForm
	/// </summary>
	public ref class MySQLForm : public System::Windows::Forms::Form
	{
	public:
		cReturn^ lReturn;
		String^ aux;
		bool close;
		MySQLForm(cReturn^ pLUT)
		{
			InitializeComponent();
			this->lReturn = pLUT;
			aux = this->lReturn->Return;
			close = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MySQLForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::TextBox^  tHost;
	private: System::Windows::Forms::Label^  lHost;
	private: System::Windows::Forms::TextBox^  tUser;
	private: System::Windows::Forms::Label^  lUser;
	private: System::Windows::Forms::TextBox^  tPassword;
	private: System::Windows::Forms::Label^  lPassword;
	private: System::Windows::Forms::TextBox^  tDatabase;

	private: System::Windows::Forms::Label^  lDatabase;
	private: System::Windows::Forms::Button^  bSalvar;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MySQLForm::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->tHost = (gcnew System::Windows::Forms::TextBox());
			this->lHost = (gcnew System::Windows::Forms::Label());
			this->tUser = (gcnew System::Windows::Forms::TextBox());
			this->lUser = (gcnew System::Windows::Forms::Label());
			this->tPassword = (gcnew System::Windows::Forms::TextBox());
			this->lPassword = (gcnew System::Windows::Forms::Label());
			this->tDatabase = (gcnew System::Windows::Forms::TextBox());
			this->lDatabase = (gcnew System::Windows::Forms::Label());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
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
			this->pbLogo1->TabIndex = 42;
			this->pbLogo1->TabStop = false;
			// 
			// tHost
			// 
			this->tHost->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tHost->Location = System::Drawing::Point(216, 209);
			this->tHost->Name = L"tHost";
			this->tHost->Size = System::Drawing::Size(194, 20);
			this->tHost->TabIndex = 85;
			this->tHost->Text = L"localhost";
			this->tHost->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tHost->Enter += gcnew System::EventHandler(this, &MySQLForm::textBox_Enter);
			// 
			// lHost
			// 
			this->lHost->AutoSize = true;
			this->lHost->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lHost->Location = System::Drawing::Point(77, 207);
			this->lHost->Name = L"lHost";
			this->lHost->Size = System::Drawing::Size(47, 23);
			this->lHost->TabIndex = 1;
			this->lHost->Text = L"Host";
			this->lHost->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tUser
			// 
			this->tUser->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tUser->Location = System::Drawing::Point(216, 254);
			this->tUser->Name = L"tUser";
			this->tUser->Size = System::Drawing::Size(194, 20);
			this->tUser->TabIndex = 87;
			this->tUser->Text = L"root";
			this->tUser->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tUser->Enter += gcnew System::EventHandler(this, &MySQLForm::textBox_Enter);
			// 
			// lUser
			// 
			this->lUser->AutoSize = true;
			this->lUser->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lUser->Location = System::Drawing::Point(77, 252);
			this->lUser->Name = L"lUser";
			this->lUser->Size = System::Drawing::Size(71, 23);
			this->lUser->TabIndex = 86;
			this->lUser->Text = L"Usuário";
			this->lUser->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tPassword
			// 
			this->tPassword->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tPassword->Location = System::Drawing::Point(216, 299);
			this->tPassword->Name = L"tPassword";
			this->tPassword->Size = System::Drawing::Size(194, 20);
			this->tPassword->TabIndex = 89;
			this->tPassword->Text = L"rw1311";
			this->tPassword->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tPassword->Enter += gcnew System::EventHandler(this, &MySQLForm::textBox_Enter);
			// 
			// lPassword
			// 
			this->lPassword->AutoSize = true;
			this->lPassword->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPassword->Location = System::Drawing::Point(77, 297);
			this->lPassword->Name = L"lPassword";
			this->lPassword->Size = System::Drawing::Size(58, 23);
			this->lPassword->TabIndex = 88;
			this->lPassword->Text = L"Senha";
			this->lPassword->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tDatabase
			// 
			this->tDatabase->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tDatabase->Location = System::Drawing::Point(216, 344);
			this->tDatabase->Name = L"tDatabase";
			this->tDatabase->Size = System::Drawing::Size(194, 20);
			this->tDatabase->TabIndex = 91;
			this->tDatabase->Text = L"database";
			this->tDatabase->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tDatabase->Enter += gcnew System::EventHandler(this, &MySQLForm::textBox_Enter);
			// 
			// lDatabase
			// 
			this->lDatabase->AutoSize = true;
			this->lDatabase->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDatabase->Location = System::Drawing::Point(77, 342);
			this->lDatabase->Name = L"lDatabase";
			this->lDatabase->Size = System::Drawing::Size(135, 23);
			this->lDatabase->TabIndex = 90;
			this->lDatabase->Text = L"Banco de Dados";
			this->lDatabase->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(212, 444);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 1;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &MySQLForm::bSalvar_Click);
			// 
			// MySQLForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->tDatabase);
			this->Controls->Add(this->lDatabase);
			this->Controls->Add(this->tPassword);
			this->Controls->Add(this->lPassword);
			this->Controls->Add(this->tUser);
			this->Controls->Add(this->lUser);
			this->Controls->Add(this->tHost);
			this->Controls->Add(this->lHost);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"MySQLForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Configurando Banco de Dados MySQL";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MySQLForm::MySQLForm_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &MySQLForm::MySQLForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MySQLForm_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MySQLForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
};
}

#pragma once

namespace CellFulfill {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutForm
	/// </summary>
	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		String^ lLanguage;
		AboutForm(String^ pLanguage)
		{
			InitializeComponent();
			lLanguage = pLanguage;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^  pbLogo2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  lCopyright;
	private: System::Windows::Forms::Label^  lVersion;
	private: System::Windows::Forms::Label^  lProgram;
	private: System::Windows::Forms::Label^  lCompatible;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::LinkLabel^  linkLabel2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutForm::typeid));
			this->pbLogo2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->lCopyright = (gcnew System::Windows::Forms::Label());
			this->lVersion = (gcnew System::Windows::Forms::Label());
			this->lProgram = (gcnew System::Windows::Forms::Label());
			this->lCompatible = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo2))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// pbLogo2
			// 
			this->pbLogo2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pbLogo2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo2.Image")));
			this->pbLogo2->Location = System::Drawing::Point(115, 304);
			this->pbLogo2->Name = L"pbLogo2";
			this->pbLogo2->Size = System::Drawing::Size(166, 62);
			this->pbLogo2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo2->TabIndex = 13;
			this->pbLogo2->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(19, 156);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(355, 4);
			this->panel1->TabIndex = 15;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Location = System::Drawing::Point(-2, -2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(350, 4);
			this->panel2->TabIndex = 16;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Location = System::Drawing::Point(19, 284);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(355, 4);
			this->panel3->TabIndex = 16;
			// 
			// lCopyright
			// 
			this->lCopyright->AutoSize = true;
			this->lCopyright->Font = (gcnew System::Drawing::Font(L"Calibri", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lCopyright->Location = System::Drawing::Point(17, 236);
			this->lCopyright->Name = L"lCopyright";
			this->lCopyright->Size = System::Drawing::Size(275, 17);
			this->lCopyright->TabIndex = 17;
			this->lCopyright->Text = L"Copyright © 2015. Todos os direitos reservados.";
			// 
			// lVersion
			// 
			this->lVersion->AutoSize = true;
			this->lVersion->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->lVersion->Location = System::Drawing::Point(17, 216);
			this->lVersion->Name = L"lVersion";
			this->lVersion->Size = System::Drawing::Size(87, 22);
			this->lVersion->TabIndex = 18;
			this->lVersion->Text = L"Versão 2.0";
			// 
			// lProgram
			// 
			this->lProgram->AutoSize = true;
			this->lProgram->Font = (gcnew System::Drawing::Font(L"Calibri", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lProgram->Location = System::Drawing::Point(14, 160);
			this->lProgram->Name = L"lProgram";
			this->lProgram->Size = System::Drawing::Size(248, 21);
			this->lProgram->TabIndex = 19;
			this->lProgram->Text = L"Gerenciador de Modelos CellFulfill";
			// 
			// lCompatible
			// 
			this->lCompatible->AutoSize = true;
			this->lCompatible->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->lCompatible->Location = System::Drawing::Point(15, 182);
			this->lCompatible->Name = L"lCompatible";
			this->lCompatible->Size = System::Drawing::Size(177, 19);
			this->lCompatible->TabIndex = 21;
			this->lCompatible->Text = L"Compatível com CellFulfill";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(236, 268);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(135, 13);
			this->linkLabel1->TabIndex = 22;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"http://luccme.ccst.inpe.br/";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &AboutForm::linkLabel1_LinkClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(91, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 26);
			this->label1->TabIndex = 25;
			this->label1->Text = L"&&";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(14, 28);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(78, 102);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 24;
			this->pictureBox1->TabStop = false;
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(102, 29);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(279, 102);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 23;
			this->pbLogo1->TabStop = false;
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->Location = System::Drawing::Point(19, 268);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(181, 13);
			this->linkLabel2->TabIndex = 22;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"https://github.com/TerraME/terrame";
			this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &AboutForm::linkLabel2_LinkClicked);
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(393, 382);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pbLogo1);
			this->Controls->Add(this->linkLabel2);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->lCompatible);
			this->Controls->Add(this->lCopyright);
			this->Controls->Add(this->lVersion);
			this->Controls->Add(this->lProgram);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pbLogo2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AboutForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sobre";
			this->Load += gcnew System::EventHandler(this, &AboutForm::AboutForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo2))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AboutForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e);
	private: System::Void linkLabel2_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e);
};
}

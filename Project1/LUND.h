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
	/// Summary for LUND
	/// </summary>
	public ref class LUND : public System::Windows::Forms::Form
	{
	private:
		String^ gSLUT = "";
		String^ gSLUTMod = "";
		String^ gSExit = "";
	public:
		cReturn^ lReturn;
		String^ aux;
		bool close;
		LUND(cReturn^ pLUT)
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
		~LUND()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bSelect;
	protected:
	private: System::Windows::Forms::ListView^  lvLUT;
	private: System::Windows::Forms::PictureBox^  pbLogo1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LUND::typeid));
			this->bSelect = (gcnew System::Windows::Forms::Button());
			this->lvLUT = (gcnew System::Windows::Forms::ListView());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// bSelect
			// 
			this->bSelect->Location = System::Drawing::Point(202, 500);
			this->bSelect->Name = L"bSelect";
			this->bSelect->Size = System::Drawing::Size(75, 23);
			this->bSelect->TabIndex = 43;
			this->bSelect->Text = L"Selecionar";
			this->bSelect->UseVisualStyleBackColor = true;
			this->bSelect->Click += gcnew System::EventHandler(this, &LUND::bSelect_Click);
			// 
			// lvLUT
			// 
			this->lvLUT->Location = System::Drawing::Point(153, 189);
			this->lvLUT->MultiSelect = false;
			this->lvLUT->Name = L"lvLUT";
			this->lvLUT->Size = System::Drawing::Size(171, 291);
			this->lvLUT->TabIndex = 42;
			this->lvLUT->UseCompatibleStateImageBehavior = false;
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(62, 21);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 41;
			this->pbLogo1->TabStop = false;
			// 
			// LUND
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->bSelect);
			this->Controls->Add(this->lvLUT);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"LUND";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Land Use No Data";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LUND::LUND_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &LUND::LUND_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LUND_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSelect_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void LUND_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	};
}

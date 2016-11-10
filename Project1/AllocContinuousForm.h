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
	/// Summary for AllocContinuousForm
	/// </summary>
	public ref class AllocContinuousForm : public System::Windows::Forms::Form
	{
	private:
		String^ gSAlloMod = "";
		String^ gSAlloModTitle = "";
		String^ gSAlloc = "";

	public:
		cReturnAllocation^ lReturn;
		AllocContinuousForm(cReturnAllocation^ pAllocation)
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
		~AllocContinuousForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Button^  bACLSaturation;
	private: System::Windows::Forms::Button^  bAllocationCClueLike;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AllocContinuousForm::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bACLSaturation = (gcnew System::Windows::Forms::Button());
			this->bAllocationCClueLike = (gcnew System::Windows::Forms::Button());
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
			this->pbLogo1->TabIndex = 17;
			this->pbLogo1->TabStop = false;
			// 
			// bACLSaturation
			// 
			this->bACLSaturation->Location = System::Drawing::Point(155, 308);
			this->bACLSaturation->Name = L"bACLSaturation";
			this->bACLSaturation->Size = System::Drawing::Size(185, 39);
			this->bACLSaturation->TabIndex = 90;
			this->bACLSaturation->Text = L"Clue Like Saturation";
			this->bACLSaturation->UseVisualStyleBackColor = true;
			this->bACLSaturation->Click += gcnew System::EventHandler(this, &AllocContinuousForm::bACLSaturation_Click);
			// 
			// bAllocationCClueLike
			// 
			this->bAllocationCClueLike->Location = System::Drawing::Point(155, 205);
			this->bAllocationCClueLike->Name = L"bAllocationCClueLike";
			this->bAllocationCClueLike->Size = System::Drawing::Size(185, 39);
			this->bAllocationCClueLike->TabIndex = 89;
			this->bAllocationCClueLike->Text = L"Clue Like";
			this->bAllocationCClueLike->UseVisualStyleBackColor = true;
			this->bAllocationCClueLike->Click += gcnew System::EventHandler(this, &AllocContinuousForm::bAllocationCClueLike_Click);
			// 
			// AllocContinuousForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(495, 421);
			this->Controls->Add(this->bACLSaturation);
			this->Controls->Add(this->bAllocationCClueLike);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"AllocContinuousForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Alocação - Componentes Contínuos";
			this->Shown += gcnew System::EventHandler(this, &AllocContinuousForm::AllocContinuousForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bAllocationCClueLike_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bACLSaturation_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AllocContinuousForm_Shown(System::Object^  sender, System::EventArgs^  e);
};
}

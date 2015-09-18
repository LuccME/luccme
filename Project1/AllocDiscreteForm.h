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
	/// Summary for AllocDiscreteForm
	/// </summary>
	public ref class AllocDiscreteForm : public System::Windows::Forms::Form
	{
	private:
		String^ gSAlloMod = "";
		String^ gSAlloModTitle = "";

	public:
		cReturnAllocation^ lReturn;
		AllocDiscreteForm(cReturnAllocation^ pAllocation)
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
		~AllocDiscreteForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Button^  bAllocationClueSLike;
	private: System::Windows::Forms::Button^  bABSO;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AllocDiscreteForm::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bAllocationClueSLike = (gcnew System::Windows::Forms::Button());
			this->bABSO = (gcnew System::Windows::Forms::Button());
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
			// bAllocationClueSLike
			// 
			this->bAllocationClueSLike->Location = System::Drawing::Point(155, 297);
			this->bAllocationClueSLike->Name = L"bAllocationClueSLike";
			this->bAllocationClueSLike->Size = System::Drawing::Size(185, 39);
			this->bAllocationClueSLike->TabIndex = 88;
			this->bAllocationClueSLike->Text = L"Allocation ClueS Like";
			this->bAllocationClueSLike->UseVisualStyleBackColor = true;
			this->bAllocationClueSLike->Click += gcnew System::EventHandler(this, &AllocDiscreteForm::bAllocationClueSLike_Click);
			// 
			// bABSO
			// 
			this->bABSO->Location = System::Drawing::Point(155, 194);
			this->bABSO->Name = L"bABSO";
			this->bABSO->Size = System::Drawing::Size(185, 39);
			this->bABSO->TabIndex = 87;
			this->bABSO->Text = L"Allocation By Simple Ordering";
			this->bABSO->UseVisualStyleBackColor = true;
			this->bABSO->Click += gcnew System::EventHandler(this, &AllocDiscreteForm::bABSO_Click);
			// 
			// AllocDiscreteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 421);
			this->Controls->Add(this->bAllocationClueSLike);
			this->Controls->Add(this->bABSO);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"AllocDiscreteForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Alocação - Componentes Discretos";
			this->Shown += gcnew System::EventHandler(this, &AllocDiscreteForm::AllocDiscreteForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bABSO_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bAllocationClueSLike_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AllocDiscreteForm_Shown(System::Object^  sender, System::EventArgs^  e);
	};
}

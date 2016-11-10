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
	/// Summary for PotDiscreteForm
	/// </summary>
	public ref class PotDiscreteForm : public System::Windows::Forms::Form
	{
	private:
		String^ gSPotMod = "";
		String^ gSPotModTitle = "";
		String^ gSPot = "";
		String^ gSNSR = "";
		String^ gSNSRTitle = "";
	private: System::Windows::Forms::Button^  bMaxEntLike;
	private: System::Windows::Forms::Button^  bARLR;

	public:
		cReturnPotential^ lReturn;
		PotDiscreteForm(cReturnPotential^ pPotential)
		{
			InitializeComponent();
			lReturn = pPotential;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PotDiscreteForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Button^  bNeighSimpleRule;
	private: System::Windows::Forms::Button^  bNeighInverseDistanceRule;
	private: System::Windows::Forms::Button^  bInverseDistanceRule;
	private: System::Windows::Forms::Button^  bLogisticRegression;
	private: System::Windows::Forms::Button^  bNALR;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PotDiscreteForm::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bNeighSimpleRule = (gcnew System::Windows::Forms::Button());
			this->bNeighInverseDistanceRule = (gcnew System::Windows::Forms::Button());
			this->bInverseDistanceRule = (gcnew System::Windows::Forms::Button());
			this->bLogisticRegression = (gcnew System::Windows::Forms::Button());
			this->bNALR = (gcnew System::Windows::Forms::Button());
			this->bMaxEntLike = (gcnew System::Windows::Forms::Button());
			this->bARLR = (gcnew System::Windows::Forms::Button());
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
			this->pbLogo1->TabIndex = 15;
			this->pbLogo1->TabStop = false;
			// 
			// bNeighSimpleRule
			// 
			this->bNeighSimpleRule->Location = System::Drawing::Point(43, 226);
			this->bNeighSimpleRule->Name = L"bNeighSimpleRule";
			this->bNeighSimpleRule->Size = System::Drawing::Size(185, 39);
			this->bNeighSimpleRule->TabIndex = 85;
			this->bNeighSimpleRule->Text = L"Neigh Simple Rule";
			this->bNeighSimpleRule->UseVisualStyleBackColor = true;
			this->bNeighSimpleRule->Click += gcnew System::EventHandler(this, &PotDiscreteForm::bNeighSimpleRule_Click);
			// 
			// bNeighInverseDistanceRule
			// 
			this->bNeighInverseDistanceRule->Location = System::Drawing::Point(43, 317);
			this->bNeighInverseDistanceRule->Name = L"bNeighInverseDistanceRule";
			this->bNeighInverseDistanceRule->Size = System::Drawing::Size(185, 39);
			this->bNeighInverseDistanceRule->TabIndex = 86;
			this->bNeighInverseDistanceRule->Text = L"Neigh Inverse Distance Rule";
			this->bNeighInverseDistanceRule->UseVisualStyleBackColor = true;
			this->bNeighInverseDistanceRule->Click += gcnew System::EventHandler(this, &PotDiscreteForm::bNeighInverseDistanceRule_Click);
			// 
			// bInverseDistanceRule
			// 
			this->bInverseDistanceRule->Location = System::Drawing::Point(43, 408);
			this->bInverseDistanceRule->Name = L"bInverseDistanceRule";
			this->bInverseDistanceRule->Size = System::Drawing::Size(185, 39);
			this->bInverseDistanceRule->TabIndex = 87;
			this->bInverseDistanceRule->Text = L"Inverse Distance Rule";
			this->bInverseDistanceRule->UseVisualStyleBackColor = true;
			this->bInverseDistanceRule->Click += gcnew System::EventHandler(this, &PotDiscreteForm::bInverseDistanceRule_Click);
			// 
			// bLogisticRegression
			// 
			this->bLogisticRegression->Location = System::Drawing::Point(251, 226);
			this->bLogisticRegression->Name = L"bLogisticRegression";
			this->bLogisticRegression->Size = System::Drawing::Size(185, 39);
			this->bLogisticRegression->TabIndex = 88;
			this->bLogisticRegression->Text = L"Logistic Regression";
			this->bLogisticRegression->UseVisualStyleBackColor = true;
			this->bLogisticRegression->Click += gcnew System::EventHandler(this, &PotDiscreteForm::bLogisticRegression_Click);
			// 
			// bNALR
			// 
			this->bNALR->Location = System::Drawing::Point(251, 288);
			this->bNALR->Name = L"bNALR";
			this->bNALR->Size = System::Drawing::Size(185, 39);
			this->bNALR->TabIndex = 89;
			this->bNALR->Text = L"Logistic Regression Neigh Attraction ";
			this->bNALR->UseVisualStyleBackColor = true;
			this->bNALR->Click += gcnew System::EventHandler(this, &PotDiscreteForm::bNALR_Click);
			// 
			// bMaxEntLike
			// 
			this->bMaxEntLike->Location = System::Drawing::Point(251, 407);
			this->bMaxEntLike->Name = L"bMaxEntLike";
			this->bMaxEntLike->Size = System::Drawing::Size(185, 39);
			this->bMaxEntLike->TabIndex = 91;
			this->bMaxEntLike->Text = L"MaxEnt Like";
			this->bMaxEntLike->UseVisualStyleBackColor = true;
			this->bMaxEntLike->Click += gcnew System::EventHandler(this, &PotDiscreteForm::bMaxEntLike_Click);
			// 
			// bARLR
			// 
			this->bARLR->Location = System::Drawing::Point(251, 348);
			this->bARLR->Name = L"bARLR";
			this->bARLR->Size = System::Drawing::Size(185, 39);
			this->bARLR->TabIndex = 90;
			this->bARLR->Text = L"Logistic Regression Neigh Attract Repulsion";
			this->bARLR->UseVisualStyleBackColor = true;
			this->bARLR->Click += gcnew System::EventHandler(this, &PotDiscreteForm::bARLR_Click);
			// 
			// PotDiscreteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->bARLR);
			this->Controls->Add(this->bMaxEntLike);
			this->Controls->Add(this->bNALR);
			this->Controls->Add(this->bLogisticRegression);
			this->Controls->Add(this->bInverseDistanceRule);
			this->Controls->Add(this->bNeighInverseDistanceRule);
			this->Controls->Add(this->bNeighSimpleRule);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"PotDiscreteForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pontencial - Componentes Discretos";
			this->Shown += gcnew System::EventHandler(this, &PotDiscreteForm::PotDiscreteForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bNeighSimpleRule_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bNeighInverseDistanceRule_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bInverseDistanceRule_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bLogisticRegression_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bNALR_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PotDiscreteForm_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bMaxEntLike_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bARLR_Click(System::Object^  sender, System::EventArgs^  e);
	};
}

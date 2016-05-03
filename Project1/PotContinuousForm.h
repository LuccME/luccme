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
	/// Summary for PotContinuousForm
	/// </summary>
	public ref class PotContinuousForm : public System::Windows::Forms::Form
	{
	private:
		String^ gSPotMod = "";
		String^ gSPotModTitle = "";
		String^ gSPot = "";
	private: System::Windows::Forms::Button^  bMaxEntLike;



	public:
		cReturnPotential^ lReturn;
		PotContinuousForm(cReturnPotential^ pPotencial)
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
		~PotContinuousForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bSpatialLagLinearRoads;
	protected:

	protected:


	private: System::Windows::Forms::Button^  bSpatialLagRegression;

	private: System::Windows::Forms::Button^  bLinearRegression;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PotContinuousForm::typeid));
			this->bSpatialLagLinearRoads = (gcnew System::Windows::Forms::Button());
			this->bSpatialLagRegression = (gcnew System::Windows::Forms::Button());
			this->bLinearRegression = (gcnew System::Windows::Forms::Button());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bMaxEntLike = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// bSpatialLagLinearRoads
			// 
			this->bSpatialLagLinearRoads->Location = System::Drawing::Point(147, 360);
			this->bSpatialLagLinearRoads->Name = L"bSpatialLagLinearRoads";
			this->bSpatialLagLinearRoads->Size = System::Drawing::Size(185, 39);
			this->bSpatialLagLinearRoads->TabIndex = 93;
			this->bSpatialLagLinearRoads->Text = L"Spatial Lag Linear Roads";
			this->bSpatialLagLinearRoads->UseVisualStyleBackColor = true;
			this->bSpatialLagLinearRoads->Click += gcnew System::EventHandler(this, &PotContinuousForm::bSpatialLagLinearRoads_Click);
			// 
			// bSpatialLagRegression
			// 
			this->bSpatialLagRegression->Location = System::Drawing::Point(147, 271);
			this->bSpatialLagRegression->Name = L"bSpatialLagRegression";
			this->bSpatialLagRegression->Size = System::Drawing::Size(185, 39);
			this->bSpatialLagRegression->TabIndex = 92;
			this->bSpatialLagRegression->Text = L"Spatial Lag Regression";
			this->bSpatialLagRegression->UseVisualStyleBackColor = true;
			this->bSpatialLagRegression->Click += gcnew System::EventHandler(this, &PotContinuousForm::bSpatialLagRegression_Click);
			// 
			// bLinearRegression
			// 
			this->bLinearRegression->Location = System::Drawing::Point(147, 182);
			this->bLinearRegression->Name = L"bLinearRegression";
			this->bLinearRegression->Size = System::Drawing::Size(185, 39);
			this->bLinearRegression->TabIndex = 91;
			this->bLinearRegression->Text = L"Linear Regression";
			this->bLinearRegression->UseVisualStyleBackColor = true;
			this->bLinearRegression->Click += gcnew System::EventHandler(this, &PotContinuousForm::bLinearRegression_Click);
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(58, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 90;
			this->pbLogo1->TabStop = false;
			// 
			// bMaxEntLike
			// 
			this->bMaxEntLike->Location = System::Drawing::Point(147, 449);
			this->bMaxEntLike->Name = L"bMaxEntLike";
			this->bMaxEntLike->Size = System::Drawing::Size(185, 39);
			this->bMaxEntLike->TabIndex = 94;
			this->bMaxEntLike->Text = L"MaxEnt Like";
			this->bMaxEntLike->UseVisualStyleBackColor = true;
			this->bMaxEntLike->Click += gcnew System::EventHandler(this, &PotContinuousForm::bMaxEntLike_Click);
			// 
			// PotContinuousForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->bMaxEntLike);
			this->Controls->Add(this->bSpatialLagLinearRoads);
			this->Controls->Add(this->bSpatialLagRegression);
			this->Controls->Add(this->bLinearRegression);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"PotContinuousForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pontencial - Componentes Contínuos";
			this->Shown += gcnew System::EventHandler(this, &PotContinuousForm::PotContinuousForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bLinearRegression_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSpatialLagRegression_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSpatialLagLinearRoads_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PotContinuousForm_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bMaxEntLike_Click(System::Object^  sender, System::EventArgs^  e);
};
}

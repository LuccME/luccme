#pragma once

namespace LuccME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for P_ContinuousR
	/// </summary>
	public ref class P_ContinuousR : public System::Windows::Forms::Form
	{
	public:
		P_ContinuousR(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~P_ContinuousR()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bCancel;
	protected:
	private: System::Windows::Forms::TextBox^  tLUT;
	private: System::Windows::Forms::Button^  bAddBetas;
	private: System::Windows::Forms::ListView^  lvLUT;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::TabControl^  tcRegions;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(P_ContinuousR::typeid));
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->tLUT = (gcnew System::Windows::Forms::TextBox());
			this->bAddBetas = (gcnew System::Windows::Forms::Button());
			this->lvLUT = (gcnew System::Windows::Forms::ListView());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->tcRegions = (gcnew System::Windows::Forms::TabControl());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(261, 526);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 79;
			this->bCancel->Text = L"Cancelar";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Visible = false;
			// 
			// tLUT
			// 
			this->tLUT->ForeColor = System::Drawing::Color::Black;
			this->tLUT->Location = System::Drawing::Point(21, 158);
			this->tLUT->Name = L"tLUT";
			this->tLUT->Size = System::Drawing::Size(161, 20);
			this->tLUT->TabIndex = 82;
			this->tLUT->Visible = false;
			// 
			// bAddBetas
			// 
			this->bAddBetas->Location = System::Drawing::Point(365, 526);
			this->bAddBetas->Name = L"bAddBetas";
			this->bAddBetas->Size = System::Drawing::Size(75, 23);
			this->bAddBetas->TabIndex = 78;
			this->bAddBetas->Text = L"Adicionar";
			this->bAddBetas->UseVisualStyleBackColor = true;
			this->bAddBetas->Visible = false;
			// 
			// lvLUT
			// 
			this->lvLUT->Location = System::Drawing::Point(21, 157);
			this->lvLUT->MultiSelect = false;
			this->lvLUT->Name = L"lvLUT";
			this->lvLUT->Size = System::Drawing::Size(171, 351);
			this->lvLUT->TabIndex = 77;
			this->lvLUT->UseCompatibleStateImageBehavior = false;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(219, 526);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 80;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(58, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 81;
			this->pbLogo1->TabStop = false;
			// 
			// tcRegions
			// 
			this->tcRegions->Location = System::Drawing::Point(219, 158);
			this->tcRegions->Name = L"tcRegions";
			this->tcRegions->SelectedIndex = 0;
			this->tcRegions->Size = System::Drawing::Size(250, 350);
			this->tcRegions->TabIndex = 83;
			// 
			// P_ContinuousR
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(481, 565);
			this->Controls->Add(this->tcRegions);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->tLUT);
			this->Controls->Add(this->bAddBetas);
			this->Controls->Add(this->lvLUT);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"P_ContinuousR";
			this->Text = L"P_ContinuousR";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}

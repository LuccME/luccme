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
	/// Summary for D_PCVINPEForm
	/// </summary>
	public ref class D_PCVINPEForm : public System::Windows::Forms::Form
	{
	private:
		String^ gSYear = "";
		String^ gSCells = "";
		String^ gSCellsTitle = "";
		String^ gSDataMod = "";
		String^ gSExit = "";

	public:
		cReturnPCVINPE^ lReturn;
		bool changed;
		bool close;
		bool managed;
		D_PCVINPEForm(cReturnPCVINPE^ pDemand)
		{
			InitializeComponent();
			this->lReturn = pDemand;
			changed = false;
			close = false;
			managed = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~D_PCVINPEForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ContextMenuStrip^  cMSP_continuous;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Label^  lPCVINPE;
	private: System::Windows::Forms::DataGridView^  dgDemand;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(D_PCVINPEForm::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->lPCVINPE = (gcnew System::Windows::Forms::Label());
			this->dgDemand = (gcnew System::Windows::Forms::DataGridView());
			this->cMSP_continuous = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDemand))->BeginInit();
			this->cMSP_continuous->SuspendLayout();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(80, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 15;
			this->pbLogo1->TabStop = false;
			// 
			// lPCVINPE
			// 
			this->lPCVINPE->AutoSize = true;
			this->lPCVINPE->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPCVINPE->Location = System::Drawing::Point(197, 170);
			this->lPCVINPE->Name = L"lPCVINPE";
			this->lPCVINPE->Size = System::Drawing::Size(135, 23);
			this->lPCVINPE->TabIndex = 36;
			this->lPCVINPE->Text = L"Demanda Anual";
			this->lPCVINPE->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dgDemand
			// 
			this->dgDemand->AllowUserToAddRows = false;
			this->dgDemand->AllowUserToDeleteRows = false;
			this->dgDemand->AllowUserToResizeColumns = false;
			this->dgDemand->AllowUserToResizeRows = false;
			this->dgDemand->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgDemand->ContextMenuStrip = this->cMSP_continuous;
			this->dgDemand->Location = System::Drawing::Point(63, 210);
			this->dgDemand->Name = L"dgDemand";
			this->dgDemand->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgDemand->Size = System::Drawing::Size(407, 331);
			this->dgDemand->TabIndex = 38;
			this->dgDemand->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &D_PCVINPEForm::dgDemand_CellValueChanged);
			this->dgDemand->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &D_PCVINPEForm::dgDemand_KeyDown);
			// 
			// cMSP_continuous
			// 
			this->cMSP_continuous->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->copyToolStripMenuItem,
					this->pasteToolStripMenuItem
			});
			this->cMSP_continuous->Name = L"contextMenuStrip1";
			this->cMSP_continuous->Size = System::Drawing::Size(153, 70);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->copyToolStripMenuItem->Text = L"Copy";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &D_PCVINPEForm::copyToolStripMenuItem_Click);
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->pasteToolStripMenuItem->Text = L"Paste";
			this->pasteToolStripMenuItem->Click += gcnew System::EventHandler(this, &D_PCVINPEForm::pasteToolStripMenuItem_Click);
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(229, 572);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 41;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &D_PCVINPEForm::bSalvar_Click);
			// 
			// D_PCVINPEForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(524, 626);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->dgDemand);
			this->Controls->Add(this->lPCVINPE);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"D_PCVINPEForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Demanda - Pre Computed Values INPE";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &D_PCVINPEForm::D_PCVINPEForm_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &D_PCVINPEForm::D_PCVINPEForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDemand))->EndInit();
			this->cMSP_continuous->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void D_PCVINPEForm_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void D_PCVINPEForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void dgDemand_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void dgDemand_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void CopyToClipboard();
	private: System::Void PasteClipboardValue();
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(DataGridView^ dgView);
	private: System::Void copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
};
}

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
	/// Summary for P_MaxEntLike
	/// </summary>
	public ref class P_MaxEntLike : public System::Windows::Forms::Form
	{
	private:
		String^ gSAttributes = "";
		String^ gSEmptyUsePerc = "";
		String^ gSEmptyUsePercTitle = "";
		String^ gSEmptyDG = "";
		String^ gSEmptyDGTitle = ""; 
		String^ gSLUT = "";

	public:
		cReturnPotential^ lReturn;
		array<String^>^ lTempAttr = gcnew array<String^>(50);
		P_MaxEntLike(cReturnPotential^ pPotencial)
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
		~P_MaxEntLike()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ContextMenuStrip^  cMSP_continuous2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ContextMenuStrip^  cMSP_continuous;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  tLUT;
	private: System::Windows::Forms::ListView^  lvLUT;
	private: System::Windows::Forms::Button^  bAddBetas;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::DataGridView^  dgAttrPerc;
	private: System::Windows::Forms::Label^  lAttrPerc;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::TextBox^  tUsePerc;
	private: System::Windows::Forms::Label^  lUsePerc;
	private: System::Windows::Forms::DataGridView^  dgAttrClass;
	private: System::Windows::Forms::Label^  lAttrClass;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(P_MaxEntLike::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->dgAttrPerc = (gcnew System::Windows::Forms::DataGridView());
			this->cMSP_continuous = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lAttrPerc = (gcnew System::Windows::Forms::Label());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->tUsePerc = (gcnew System::Windows::Forms::TextBox());
			this->lUsePerc = (gcnew System::Windows::Forms::Label());
			this->dgAttrClass = (gcnew System::Windows::Forms::DataGridView());
			this->cMSP_continuous2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lAttrClass = (gcnew System::Windows::Forms::Label());
			this->tLUT = (gcnew System::Windows::Forms::TextBox());
			this->lvLUT = (gcnew System::Windows::Forms::ListView());
			this->bAddBetas = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAttrPerc))->BeginInit();
			this->cMSP_continuous->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAttrClass))->BeginInit();
			this->cMSP_continuous2->SuspendLayout();
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
			// dgAttrPerc
			// 
			this->dgAttrPerc->AllowUserToResizeColumns = false;
			this->dgAttrPerc->AllowUserToResizeRows = false;
			this->dgAttrPerc->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAttrPerc->ContextMenuStrip = this->cMSP_continuous;
			this->dgAttrPerc->Location = System::Drawing::Point(222, 229);
			this->dgAttrPerc->Name = L"dgAttrPerc";
			this->dgAttrPerc->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAttrPerc->Size = System::Drawing::Size(244, 184);
			this->dgAttrPerc->TabIndex = 108;
			this->dgAttrPerc->Visible = false;
			this->dgAttrPerc->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_MaxEntLike::dgAttr_KeyDown);
			// 
			// cMSP_continuous
			// 
			this->cMSP_continuous->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->copyToolStripMenuItem,
					this->pasteToolStripMenuItem
			});
			this->cMSP_continuous->Name = L"contextMenuStrip1";
			this->cMSP_continuous->Size = System::Drawing::Size(103, 48);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->copyToolStripMenuItem->Text = L"Copy";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &P_MaxEntLike::copyToolStripMenuItem_Click);
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->pasteToolStripMenuItem->Text = L"Paste";
			this->pasteToolStripMenuItem->Click += gcnew System::EventHandler(this, &P_MaxEntLike::pasteToolStripMenuItem_Click);
			// 
			// lAttrPerc
			// 
			this->lAttrPerc->AutoSize = true;
			this->lAttrPerc->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAttrPerc->Location = System::Drawing::Point(266, 203);
			this->lAttrPerc->Name = L"lAttrPerc";
			this->lAttrPerc->Size = System::Drawing::Size(155, 23);
			this->lAttrPerc->TabIndex = 109;
			this->lAttrPerc->Text = L"Attributes (Range)";
			this->lAttrPerc->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lAttrPerc->Visible = false;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(210, 648);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 110;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &P_MaxEntLike::bSalvar_Click);
			// 
			// tUsePerc
			// 
			this->tUsePerc->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tUsePerc->Location = System::Drawing::Point(308, 178);
			this->tUsePerc->Name = L"tUsePerc";
			this->tUsePerc->Size = System::Drawing::Size(67, 20);
			this->tUsePerc->TabIndex = 111;
			this->tUsePerc->Text = L"75";
			this->tUsePerc->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tUsePerc->Visible = false;
			this->tUsePerc->Enter += gcnew System::EventHandler(this, &P_MaxEntLike::textBox_Enter);
			// 
			// lUsePerc
			// 
			this->lUsePerc->AutoSize = true;
			this->lUsePerc->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lUsePerc->Location = System::Drawing::Point(210, 152);
			this->lUsePerc->Name = L"lUsePerc";
			this->lUsePerc->Size = System::Drawing::Size(270, 23);
			this->lUsePerc->TabIndex = 112;
			this->lUsePerc->Text = L"% Uso a ser considerado amostra";
			this->lUsePerc->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->lUsePerc->Visible = false;
			// 
			// dgAttrClass
			// 
			this->dgAttrClass->AllowUserToResizeColumns = false;
			this->dgAttrClass->AllowUserToResizeRows = false;
			this->dgAttrClass->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAttrClass->ContextMenuStrip = this->cMSP_continuous2;
			this->dgAttrClass->Location = System::Drawing::Point(222, 445);
			this->dgAttrClass->Name = L"dgAttrClass";
			this->dgAttrClass->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgAttrClass->Size = System::Drawing::Size(244, 184);
			this->dgAttrClass->TabIndex = 113;
			this->dgAttrClass->Visible = false;
			this->dgAttrClass->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &P_MaxEntLike::dgAttr_KeyDown);
			// 
			// cMSP_continuous2
			// 
			this->cMSP_continuous2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem1,
					this->toolStripMenuItem2
			});
			this->cMSP_continuous2->Name = L"contextMenuStrip1";
			this->cMSP_continuous2->Size = System::Drawing::Size(103, 48);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(102, 22);
			this->toolStripMenuItem1->Text = L"Copy";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &P_MaxEntLike::toolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(102, 22);
			this->toolStripMenuItem2->Text = L"Paste";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &P_MaxEntLike::toolStripMenuItem2_Click);
			// 
			// lAttrClass
			// 
			this->lAttrClass->AutoSize = true;
			this->lAttrClass->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAttrClass->Location = System::Drawing::Point(245, 419);
			this->lAttrClass->Name = L"lAttrClass";
			this->lAttrClass->Size = System::Drawing::Size(195, 23);
			this->lAttrClass->TabIndex = 114;
			this->lAttrClass->Text = L"Attributes (Categorical)";
			this->lAttrClass->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lAttrClass->Visible = false;
			// 
			// tLUT
			// 
			this->tLUT->ForeColor = System::Drawing::Color::Black;
			this->tLUT->Location = System::Drawing::Point(12, 154);
			this->tLUT->Name = L"tLUT";
			this->tLUT->Size = System::Drawing::Size(161, 20);
			this->tLUT->TabIndex = 116;
			this->tLUT->Visible = false;
			// 
			// lvLUT
			// 
			this->lvLUT->Location = System::Drawing::Point(12, 154);
			this->lvLUT->MultiSelect = false;
			this->lvLUT->Name = L"lvLUT";
			this->lvLUT->Size = System::Drawing::Size(171, 475);
			this->lvLUT->TabIndex = 115;
			this->lvLUT->UseCompatibleStateImageBehavior = false;
			this->lvLUT->SelectedIndexChanged += gcnew System::EventHandler(this, &P_MaxEntLike::lvLUT_SelectedIndexChanged);
			// 
			// bAddBetas
			// 
			this->bAddBetas->Location = System::Drawing::Point(308, 646);
			this->bAddBetas->Name = L"bAddBetas";
			this->bAddBetas->Size = System::Drawing::Size(75, 23);
			this->bAddBetas->TabIndex = 117;
			this->bAddBetas->Text = L"Adicionar";
			this->bAddBetas->UseVisualStyleBackColor = true;
			this->bAddBetas->Visible = false;
			this->bAddBetas->Click += gcnew System::EventHandler(this, &P_MaxEntLike::bAddBetas_Click);
			// 
			// P_MaxEntLike
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 677);
			this->Controls->Add(this->bAddBetas);
			this->Controls->Add(this->tLUT);
			this->Controls->Add(this->lvLUT);
			this->Controls->Add(this->lAttrClass);
			this->Controls->Add(this->dgAttrClass);
			this->Controls->Add(this->tUsePerc);
			this->Controls->Add(this->lUsePerc);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->dgAttrPerc);
			this->Controls->Add(this->lAttrPerc);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"P_MaxEntLike";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MaxEnt Like";
			this->Shown += gcnew System::EventHandler(this, &P_MaxEntLike::P_MaxEntLike_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAttrPerc))->EndInit();
			this->cMSP_continuous->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAttrClass))->EndInit();
			this->cMSP_continuous2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void P_MaxEntLike_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bAddBetas_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void setData(String^ dataSource); 
	private: System::Void initializeForm();
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgAttr);
	private: System::Void dgAttr_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void CopyToClipboard(DataGridView^ dgAttr);
	private: System::Void PasteClipboardValue(DataGridView^ dgAttr);
	private: System::Void copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e);
};
}

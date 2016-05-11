#include "stdafx.h"
#include "AllocContinuousForm.h"
#include "A_Continuous.h"

System::Void LuccME::AllocContinuousForm::AllocContinuousForm_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Allocation - Continuous Components";
		gSAlloMod = "Another Allocation Component was modified.\nThe potential values will be lost\nDo you want to proceed?";
		gSAlloModTitle = "Another Allocation Component was used";
		gSAlloc = "Allocation - ";
	}
	else {
		this->Text = "Alocação - Componentes Contínuos";
		gSAlloMod = "Outro componente de Alocação foi modificado anteriormente.\nOs valores de potencial serão apagados.\nDeseja continuar?";
		gSAlloModTitle = "Outro componente de Alocação já utilizado";
		gSAlloc = "Alocação - ";
	}
}


System::Void LuccME::AllocContinuousForm::bAllocationClueLike_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != ALLOCATIONCLUELIKE && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSAlloMod, gSAlloModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = ALLOCATIONCLUELIKE;
		A_Continuous^ allocationForm = gcnew A_Continuous(lReturn);
		allocationForm->Text = gSAlloc + "Allocation Clue Like";
		allocationForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		}
		this->Close();
	}
}

System::Void LuccME::AllocContinuousForm::bACLSaturation_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != ALLOCATIONCLUELIKESATURATION && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSAlloMod, gSAlloModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = ALLOCATIONCLUELIKESATURATION;
		A_Continuous^ allocationForm = gcnew A_Continuous(lReturn);
		allocationForm->Text = gSAlloc + "Allocation Clue Like Saturation";
		allocationForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		}
		this->Close();
	}
}

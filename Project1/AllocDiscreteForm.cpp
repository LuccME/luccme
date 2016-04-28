#include "stdafx.h"
#include "AllocDiscreteForm.h"
#include "A_ABSO.h"
#include "A_AllocationClueSLike.h"

System::Void LuccME::AllocDiscreteForm::AllocDiscreteForm_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Allocation - Discrete Components";
		gSAlloMod = "Another Allocation Component was modified.\nThe potential values will be lost\nDo you want to proceed?";
		gSAlloModTitle = "Another Allocation Component was used";
	}
	else {
		this->Text = "Alocação - Componentes Discretos";
		gSAlloMod = "Outro componente de Alocação foi modificado anteriormente.\nOs valores de potencial serão apagados.\nDeseja continuar?";
		gSAlloModTitle = "Outro componente de Alocação já utilizado";
	}
}

System::Void LuccME::AllocDiscreteForm::bABSO_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != ALLOCATIONBYSIMPLEORDERING && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSAlloMod, gSAlloModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = ALLOCATIONBYSIMPLEORDERING;
		A_ABSO^ allocationForm = gcnew A_ABSO(lReturn);
		allocationForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		}
		this->Close();
	}
}

System::Void LuccME::AllocDiscreteForm::bAllocationClueSLike_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != ALLOCATIONCLUESLIKE && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSAlloMod, gSAlloModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = ALLOCATIONCLUESLIKE;
		A_AllocationClueSLike^ allocationForm = gcnew A_AllocationClueSLike(lReturn);
		allocationForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		}
		this->Close();
	}
}


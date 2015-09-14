#include "stdafx.h"
#include "PotDiscreteForm.h"
#include "P_Discrete.h"

System::Void LuccME::PotDiscreteForm::PotDiscreteForm_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Pontential - Discrete Components";
		gSPotMod = "Another Potencial Component was modified.\nThe potential values will be lost\nDo you want to proceed?";
		gSPotModTitle = "Another Potential Component was used";
		gSPot = "Pontential - ";
	}
	else {
		this->Text = "Pontencial - Componentes Discretos";
		gSPotMod = "Outro componente de Potencial foi modificado anteriormente.\nOs valores de potencial serão apagados.\nDeseja continuar?";
		gSPotModTitle = "Outro componente de Potencial já utilizado";
		gSPot = "Pontencial - ";
	}
}

System::Void LuccME::PotDiscreteForm::bNeighSimpleRule_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != 1 && this->lReturn->Component != 0) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		
	}
	if (check) {
		lReturn->Return = "";
		lReturn->Component = 1;
		this->Close();
	}
}

System::Void LuccME::PotDiscreteForm::bNeighInverseDistanceRule_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != 2 && this->lReturn->Component != 0) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}

	}
	if (check) {
		P_Discrete^ potentialForm = gcnew P_Discrete(lReturn);
		potentialForm->Text = gSPot + "Neigh Inverse Distance Rule";
		potentialForm->ShowDialog();
		if (lReturn->Return != "") {
			lReturn->Component = 2;
		}
		this->Close();
	}
}

System::Void LuccME::PotDiscreteForm::bInverseDistanceRule_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != 3 && this->lReturn->Component != 0) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		P_Discrete^ potentialForm = gcnew P_Discrete(lReturn);
		potentialForm->Text = gSPot + "Inverse Distance Rule";
		potentialForm->ShowDialog();
		if (lReturn->Return != "") {
			lReturn->Component = 3;
		}
		this->Close();
	}
}

System::Void LuccME::PotDiscreteForm::bLogisticRegression_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != 4 && this->lReturn->Component != 0) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = 4;
		P_Discrete^ potentialForm = gcnew P_Discrete(lReturn);
		potentialForm->Text = gSPot + "Logistic Regression";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = 0;
		} 
		this->Close();
	}
}

System::Void LuccME::PotDiscreteForm::bNALR_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != 5 && this->lReturn->Component != 0) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = 5;
		P_Discrete^ potentialForm = gcnew P_Discrete(lReturn);
		potentialForm->Text = gSPot + "Neigh Attraction Logistic Regression";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = 0;
		}
		this->Close();
	}
}


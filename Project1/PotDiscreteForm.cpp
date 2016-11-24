#include "stdafx.h"
#include "PotDiscreteForm.h"
#include "P_DiscreteR.h"
#include "P_MaxEntLike.h"
#include "P_AttractRepulseLogisticRegression.h"

System::Void LuccME::PotDiscreteForm::PotDiscreteForm_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Pontential - Discrete Components";
		gSPotMod = "Another Potencial Component was modified.\nThe potential values will be lost\nDo you want to proceed?";
		gSPotModTitle = "Another Potential Component was used";
		gSPot = "Pontential - ";
		gSNSR = "This component does not have parameters. Do you want to select it?";
		gSNSRTitle = "Confirmation - Neigh Simple Rule";
	}
	else {
		this->Text = "Pontencial - Componentes Discretos";
		gSPotMod = "Outro componente de Potencial foi modificado anteriormente.\nOs valores de potencial serão apagados.\nDeseja continuar?";
		gSPotModTitle = "Outro componente de Potencial já utilizado";
		gSPot = "Pontencial - ";
		gSNSR = "Este componente não possui parâmetros. Deseja selecioná-lo?";
		gSNSRTitle = "Confirmação - Neigh Simple Rule";
	}
}

System::Void LuccME::PotDiscreteForm::bNeighSimpleRule_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (MessageBox::Show(gSNSR, gSNSRTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Question) == LuccME::DialogResult::No) {
		check = false;
	}

	if (this->lReturn->Component != POTENTIALDNEIGHSIMPLERULE && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		
	}

	if (check) {
		lReturn->Return = "";
		lReturn->Component = POTENTIALDNEIGHSIMPLERULE;
		this->Close();
	}
}

System::Void LuccME::PotDiscreteForm::bNeighInverseDistanceRule_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != POTENTIALDNEIGHINVERSEDISTANCERULE && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}

	}
	if (check) {
		P_DiscreteR^ potentialForm = gcnew P_DiscreteR(lReturn);
		potentialForm->MinimizeBox = false;
		potentialForm->MaximizeBox = false;
		potentialForm->ShowInTaskbar = false;
		potentialForm->Text = gSPot + "Neigh Inverse Distance Rule";
		potentialForm->ShowDialog();
		if (lReturn->Return != "") {
			lReturn->Component = POTENTIALDNEIGHINVERSEDISTANCERULE;
		}
		this->Close();
	}
}

System::Void LuccME::PotDiscreteForm::bInverseDistanceRule_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != POTENTIALDINVERSEDISTANCERULE && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		P_DiscreteR^ potentialForm = gcnew P_DiscreteR(lReturn);
		potentialForm->MinimizeBox = false;
		potentialForm->MaximizeBox = false;
		potentialForm->ShowInTaskbar = false;
		potentialForm->Text = gSPot + "Inverse Distance Rule";
		potentialForm->ShowDialog();
		if (lReturn->Return != "") {
			lReturn->Component = POTENTIALDINVERSEDISTANCERULE;
		}
		this->Close();
	}
}

System::Void LuccME::PotDiscreteForm::bLogisticRegression_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != POTENTIALDLOGISTICREGRESSION && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = POTENTIALDLOGISTICREGRESSION;
		P_DiscreteR^ potentialForm = gcnew P_DiscreteR(lReturn);
		potentialForm->MinimizeBox = false;
		potentialForm->MaximizeBox = false;
		potentialForm->ShowInTaskbar = false;
		potentialForm->Text = gSPot + "Logistic Regression";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		} 
		this->Close();
	}
}

System::Void LuccME::PotDiscreteForm::bNALR_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT;
		P_DiscreteR^ potentialForm = gcnew P_DiscreteR(lReturn);
		potentialForm->MinimizeBox = false;
		potentialForm->MaximizeBox = false;
		potentialForm->ShowInTaskbar = false;
		potentialForm->Text = gSPot + "Neigh Attraction Logistic Regression";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		}
		this->Close();
	}
}

System::Void LuccME::PotDiscreteForm::bMaxEntLike_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;
	if (this->lReturn->Component != POTENTIALDSAMPLEBASED && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = POTENTIALDSAMPLEBASED;
		P_MaxEntLike^ potentialForm = gcnew P_MaxEntLike(lReturn);
		potentialForm->MinimizeBox = false;
		potentialForm->MaximizeBox = false;
		potentialForm->ShowInTaskbar = false;
		potentialForm->Text = gSPot + "Sample Based - Discrete";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		}
		this->Close();
	}
}

System::Void LuccME::PotDiscreteForm::bARLR_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;
	if (this->lReturn->Component != POTENTIALDLOGISTICREGRESSIONNEIGHATTRACTREPULSION && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = POTENTIALDLOGISTICREGRESSIONNEIGHATTRACTREPULSION;
		P_AttractRepulseLogisticRegression^ potentialForm = gcnew P_AttractRepulseLogisticRegression(lReturn);
		potentialForm->MinimizeBox = false;
		potentialForm->MaximizeBox = false;
		potentialForm->ShowInTaskbar = false;
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		}
		this->Close();
	}
}

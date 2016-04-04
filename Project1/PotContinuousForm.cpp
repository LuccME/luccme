#include "stdafx.h"
#include "PotContinuousForm.h"
#include "P_Continuous.h"
#include "P_SpatialLagLinearRoads.h"
#include "P_ContinuousR.h"

System::Void LuccME::PotContinuousForm::PotContinuousForm_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Pontential - Continuous Components";
		gSPotMod = "Another Potencial Component was modified.\nThe potential values will be lost\nDo you want to proceed?";
		gSPotModTitle = "Another Potential Component was used";
		gSPot = "Pontential - ";
	}
	else {
		this->Text = "Pontencial - Componentes Contínuos";
		gSPotMod = "Outro componente de Potencial foi modificado anteriormente.\nOs valores de potencial serão apagados.\nDeseja continuar?";
		gSPotModTitle = "Outro componente de Potencial já utilizado";
		gSPot = "Pontencial - ";
	}
}

System::Void LuccME::PotContinuousForm::bLinearRegression_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != 6 && this->lReturn->Component != 0) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = 6;
		//P_Continuous^ potentialForm = gcnew P_Continuous(lReturn);

		P_ContinuousR^ potentialForm = gcnew P_ContinuousR(lReturn);

		potentialForm->Text = gSPot + "Linear Regression";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = 0;
		}
		this->Close();
	}
}

System::Void LuccME::PotContinuousForm::bSpatialLagRegression_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != 7 && this->lReturn->Component != 0) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = 7;
		P_Continuous^ potentialForm = gcnew P_Continuous(lReturn);
		potentialForm->Text = gSPot + "Spatial Lag Regression";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = 0;
		}
		this->Close();
	}
}

System::Void LuccME::PotContinuousForm::bSpatialLagLinearRoads_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != 8 && this->lReturn->Component != 0) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = 8;
		P_SpatialLagLinearRoads^ potentialForm = gcnew P_SpatialLagLinearRoads(lReturn);
		potentialForm->Text = gSPot + "Spatial Lag Linear Roads";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = 0;
		}
		this->Close();
	}
}

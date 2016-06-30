#include "stdafx.h"
#include "PotContinuousForm.h"
#include "P_SpatialLagLinearRoads.h"
#include "P_ContinuousR.h"
#include "P_MaxEntLike.h"

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
	if (this->lReturn->Component != LINEARREGRESSION && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = LINEARREGRESSION;
		P_ContinuousR^ potentialForm = gcnew P_ContinuousR(lReturn);
		potentialForm->MinimizeBox = false;
		potentialForm->MaximizeBox = false;
		potentialForm->ShowInTaskbar = false;
		potentialForm->Text = gSPot + "Linear Regression";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		}
		this->Close();
	}
}

System::Void LuccME::PotContinuousForm::bSpatialLagRegression_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != SPATIALLAGREGRESSION && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = SPATIALLAGREGRESSION;
		P_ContinuousR^ potentialForm = gcnew P_ContinuousR(lReturn);
		potentialForm->MinimizeBox = false;
		potentialForm->MaximizeBox = false;
		potentialForm->ShowInTaskbar = false;
		potentialForm->Text = gSPot + "Spatial Lag Regression";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		}
		this->Close();
	}
}

System::Void LuccME::PotContinuousForm::bSpatialLagLinearRoads_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool check = true;
	if (this->lReturn->Component != SPATIALLAGLINEARROADS && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = SPATIALLAGLINEARROADS;
		P_SpatialLagLinearRoads^ potentialForm = gcnew P_SpatialLagLinearRoads(lReturn);
		potentialForm->MinimizeBox = false;
		potentialForm->MaximizeBox = false;
		potentialForm->ShowInTaskbar = false;
		potentialForm->Text = gSPot + "Spatial Lag Linear Roads";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		}
		this->Close();
	}
}

System::Void LuccME::PotContinuousForm::bMaxEntLike_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;
	if (this->lReturn->Component != CMAXENTLIKE && this->lReturn->Component != NONE) {
		if (MessageBox::Show(gSPotMod, gSPotModTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == LuccME::DialogResult::No) {
			check = false;
		}
		else {
			lReturn->Return = "";
		}
	}
	if (check) {
		lReturn->Component = CMAXENTLIKE;
		P_MaxEntLike^ potentialForm = gcnew P_MaxEntLike(lReturn);
		potentialForm->MinimizeBox = false;
		potentialForm->MaximizeBox = false;
		potentialForm->ShowInTaskbar = false;
		potentialForm->Text = gSPot + "MaxEnt Like - Continuous";
		potentialForm->ShowDialog();
		if (lReturn->Return == "") {
			lReturn->Component = NONE;
		}
		this->Close();
	}
}
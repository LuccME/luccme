#include "stdafx.h"
#include "MySQLForm.h"

System::Void LuccME::MySQLForm::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void LuccME::MySQLForm::bSalvar_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	int check = 1;

	if (tHost->Text == "") {
		MessageBox::Show("O nome do Host deve ser preenchido.", "Erro - host em branco", MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = -1;
	}
	else if (tUser->Text == "") {
		MessageBox::Show("O nome do Usuário deve ser preenchido.", "Erro - usuário em branco", MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = -1;
	}
	else if (tPassword->Text == "") {
		MessageBox::Show("A Senha deve ser preenchida.", "Erro - senha em branco", MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = -1;
	}
	else if (tDatabase->Text == "") {
		MessageBox::Show("O nome do Banco de Dados deve ser preenchido.", "Erro - banco de dados em branco", MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = -1;
	}
	
	if (check != -1)
	{
		if (tHost->ForeColor != System::Drawing::Color::Black) {
			check = 0;
		}
		else if (tUser->ForeColor != System::Drawing::Color::Black) {
			check = 0;
		}
		else if (tPassword->ForeColor != System::Drawing::Color::Black) {
			check = 0;
		}
		else if (tDatabase->ForeColor != System::Drawing::Color::Black) {
			check = 0;
		}

		if (check == 0) {
			if (MessageBox::Show("Valores padrões serão utilizados.\nDeseja continuar?",
				"Salvando dados para acesso ao banco MySQL", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == LuccME::DialogResult::Yes) {
				check = 1;
			}
		}

		if (check == 1) {
			lReturn->Return = "";
			lReturn->Return += "\"";
			lReturn->Return += tHost->Text;
			lReturn->Return += "\",\"";
			lReturn->Return += tUser->Text;
			lReturn->Return += "\",\"";
			lReturn->Return += tPassword->Text;
			lReturn->Return += "\",\"";
			lReturn->Return += tDatabase->Text;
			lReturn->Return += "\"";
			close = true;
			this->Close();
		}
	}
}

System::Void LuccME::MySQLForm::MySQLForm_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Configuring MySQL database";
		bSalvar->Text = "Save";
		lUser->Text = "User";
		lPassword->Text = "Password";
		lDatabase->Text = "Database";
	}
	else {
		this->Text = "Configurando Banco de Dados MySQL";
		bSalvar->Text = "Salvar";
		lUser->Text = "Usuário";
		lPassword->Text = "Senha";
		lDatabase->Text = "Banco de Dados";
	}

	if (aux->Length > 0) {
		String^ temp = "";
		int count = 1;
		for (int i = 0; i < aux->Length; i++) {
			if (aux[i] != ',') {
				if (aux[i] != '\"') {
					temp += aux[i];
				}
			}
			else {
				switch (count) {
				case 1:
					tHost->Text = temp;
					tHost->ForeColor = System::Drawing::Color::Black;
					count++;
					break;
				case 2:
					tUser->Text = temp;
					tUser->ForeColor = System::Drawing::Color::Black;
					count++;
					break;
				case 3:
					tPassword->Text = temp;
					tPassword->ForeColor = System::Drawing::Color::Black;
					count++;
					break;
				default:
					break;
				}
				temp = "";
			}
		}

		if (temp != "") {
			tDatabase->Text = temp;
			tDatabase->ForeColor = System::Drawing::Color::Black;
		}
	}
}

System::Void LuccME::MySQLForm::MySQLForm_FormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e)
{
	if (!close) {
		this->lReturn->Return = "";
		int check = 1;

		if (tHost->Text == "") {
			MessageBox::Show("O nome do Host deve ser preenchido.", "Erro - host em branco", MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = -1;
		}
		else if (tUser->Text == "") {
			MessageBox::Show("O nome do Usuário deve ser preenchido.", "Erro - usuário em branco", MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = -1;
		}
		else if (tPassword->Text == "") {
			MessageBox::Show("A Senha deve ser preenchida.", "Erro - senha em branco", MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = -1;
		}
		else if (tDatabase->Text == "") {
			MessageBox::Show("O nome do Banco de Dados deve ser preenchido.", "Erro - banco de dados em branco", MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = -1;
		}

		if (check != -1)
		{
			if (tHost->ForeColor != System::Drawing::Color::Black) {
				check = 0;
			}
			else if (tUser->ForeColor != System::Drawing::Color::Black) {
				check = 0;
			}
			else if (tPassword->ForeColor != System::Drawing::Color::Black) {
				check = 0;
			}
			else if (tDatabase->ForeColor != System::Drawing::Color::Black) {
				check = 0;
			}

			if (check == 0) {
				if (MessageBox::Show("Valores padrões serão utilizados.\nDeseja continuar?",
					"Salvando dados para acesso ao banco MySQL", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == LuccME::DialogResult::Yes) {
					check = 1;
				}
			}

			if (check == 1) {
				lReturn->Return += "\"";
				lReturn->Return += tHost->Text;
				lReturn->Return += "\",\"";
				lReturn->Return += tUser->Text;
				lReturn->Return += "\",\"";
				lReturn->Return += tPassword->Text;
				lReturn->Return += "\",\"";
				lReturn->Return += tDatabase->Text;
				lReturn->Return += "\"";
				close = true;
				this->Close();
			}
		}

		if (aux != this->lReturn->Return) {
			if (MessageBox::Show("Os dados foram modificados, mas não foram salvos.\nOs dados serão perdidos.\nDeseja continuar?",
				"Saindo do Tipos de Uso da Terra ", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == LuccME::DialogResult::No) {
				e->Cancel = true;
			}
			else {
				this->lReturn->Return = aux;
			}
		}
	}
}

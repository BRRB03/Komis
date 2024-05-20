#pragma once
#include "DaneLogowania.h"
namespace Komis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Rejestracja
	/// </summary>
	public ref class Rejestracja : public System::Windows::Forms::Form
	{
	private:
		BazaLogin^ bazaL;
		

	public:
		Rejestracja(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			bazaL = gcnew BazaLogin();
			bool adminznaleziony = false;

			if (SprawdzAdmin() == false)
			{
				textBox1->ReadOnly = true;
				textBox1->Text = "admin";
				label4->Text = "Admin musi byæ utworzony jako pierwszy";
			}

		}

		bool SprawdzAdmin()
		{
			bazaL->WczytajZPliku();


			for each (String ^ rekord in bazaL->Dane)
			{
				array<String^>^ parts = rekord->Split('\t');
				String^ przechowanyLogin = parts[0];


				if (przechowanyLogin == "admin")
				{
					return true;
				}
			}

			return false;
		}


		bool SprawdzLogin()
		{
			bazaL->WczytajZPliku();


			for each (String ^ rekord in bazaL->Dane)
			{
				array<String^>^ parts = rekord->Split('\t');
				String^ przechowanyLogin = parts[0];
				

				if (przechowanyLogin->Equals(textBox1->Text))
				{
					return true;
				}
			}

			return false;
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Rejestracja()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label4;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(73, 235);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(242, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Zarejestruj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Rejestracja::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(51, 67);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(280, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(51, 119);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(280, 20);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(51, 170);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(280, 20);
			this->textBox3->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(48, 103);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Has³o";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(48, 154);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"PotwierdŸ has³o";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label4);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(382, 400);
			this->panel1->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(101, 51);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 0;
			// 
			// Rejestracja
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 400);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Rejestracja";
			this->Text = L"Rejestracja";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ login = textBox1->Text;
		String^ haslo = textBox2->Text;

		
		if (textBox2->Text == textBox3->Text)
		{
			if(SprawdzLogin() == false)
			{
				bazaL->DodajRekord(login, haslo);
				textBox1->Clear();
				textBox2->Clear();
				textBox3->Clear();
				MessageBox::Show("Utworzono u¿ytkownika: " + login, "Powiadomienie", MessageBoxButtons::OK, MessageBoxIcon::Question);
			}
			else
			{
				MessageBox::Show("Istnieje ju¿ taki u¿ytkownik", "Powiadomienie", MessageBoxButtons::OK, MessageBoxIcon::Question);
			}
		}
		else
		{
			MessageBox::Show("PotwierdŸ has³o", "Powiadomienie", MessageBoxButtons::OK, MessageBoxIcon::Question);
		}
	}
};
}

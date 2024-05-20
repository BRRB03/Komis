#pragma once
#include "DaneLogowania.h"

#include "Rejestracja.h"


namespace Komis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o UserLogin
	/// </summary>
	public ref class UserLogin : public System::Windows::Forms::Form
	{

	private:
		BazaLogin^ bazaL;

	public:
		UserLogin(void)
		{
			
			InitializeComponent();
			

			//
			//TODO: W tym miejscu dodaj kod konstruktora
			bazaL = gcnew BazaLogin();
			
			this->IsMdiContainer = true;
			panel1->Visible = false;

			

			//
		}

		bool SprawdzLogin()
		{
			bazaL->WczytajZPliku();
			

			for each (String ^ rekord in bazaL->Dane)
			{
				array<String^>^ parts = rekord->Split('\t');
				String^ przechowanyLogin = parts[0];
				String^ przechowaneHaslo = parts[1];

				if (przechowanyLogin->Equals(textBox1->Text) && przechowaneHaslo->Equals(textBox2->Text))
				{
					return true;
				}
			}

			return false;
		}
		String^ GetUser()
		{
			return textBox1->Text;
		}


	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~UserLogin()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;







	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserLogin::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(398, 173);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(140, 585);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 35);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Zarejestruj siê";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &UserLogin::button2_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(0, 179);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(398, 400);
			this->panel1->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(152, 473);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Wpisz login i has³o";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(58, 303);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Has³o";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(58, 243);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Login";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(61, 387);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(280, 35);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Zaloguj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UserLogin::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(61, 319);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(280, 20);
			this->textBox2->TabIndex = 8;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(61, 259);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(280, 20);
			this->textBox1->TabIndex = 7;
			// 
			// UserLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(398, 624);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"UserLogin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UserLogin";
			this->TopMost = true;
			this->TransparencyKey = System::Drawing::Color::White;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &UserLogin::UserLogin_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &UserLogin::UserLogin_FormClosed);
			this->Load += gcnew System::EventHandler(this, &UserLogin::UserLogin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UserLogin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Rejestracja^ rej = gcnew Rejestracja();
		if (button2->Text == "Wróæ")
		{
			button2->Text = "Zarejestruj siê";
			
			panel1->Visible = false;
			
			rej->Close();
		}
		else
		{
			button2->Text = "Wróæ";
			panel1->Visible = true;
			rej->TopLevel = false;
			panel1->Controls->Add(rej);
			rej->BringToFront();
			rej->Show();
		}
		
		

		
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	SprawdzLogin();
	if (SprawdzLogin() == true)
	{
		this->Close();

	}
	else
	{
		label3->ForeColor = Color::Red;
		label3->Text = "B³êdny login lub has³o";
	}
}
private: System::Void UserLogin_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	if (SprawdzLogin() == false) { Application::Exit(); }
}
private: System::Void UserLogin_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	

}
};
}

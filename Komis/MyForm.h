#pragma once
#include "Dodaj_pojazd.h"
#include "Klienci_form.h"
#include "Sprzedane.h"
#include "Moje_pojazdy.h"
#include "UserLogin.h"
#include "StatystykiAdmin.h"
#include "Statystyki.h"


namespace Komis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		String^ user;
		Moje_pojazdy^ m_p;
		Dodaj_pojazd^ d_p;
		Klienci_form^ kl;
		Sprzedane^ sp;

		Form^ currentForm = nullptr;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			this->IsMdiContainer = true;   
			
			UserLogin^ UL = gcnew UserLogin();
			UL->ShowDialog();
			UL->BringToFront();
			user = UL->GetUser();
			label2->Text = user;

			if (user != "admin")
			{
				button4->Visible = false;
			}
			
			
		}


	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelMenu;


	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Panel^ panelWys;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panelMenu = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panelWys = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panelMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panelWys->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panelMenu
			// 
			this->panelMenu->BackColor = System::Drawing::Color::FloralWhite;
			this->panelMenu->Controls->Add(this->button1);
			this->panelMenu->Controls->Add(this->pictureBox2);
			this->panelMenu->Controls->Add(this->label2);
			this->panelMenu->Controls->Add(this->button2);
			this->panelMenu->Controls->Add(this->button5);
			this->panelMenu->Controls->Add(this->button4);
			this->panelMenu->Controls->Add(this->button3);
			this->panelMenu->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelMenu->Location = System::Drawing::Point(0, 0);
			this->panelMenu->Name = L"panelMenu";
			this->panelMenu->Size = System::Drawing::Size(220, 897);
			this->panelMenu->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(0, 240);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(220, 60);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Statystyki";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 757);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(220, 116);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(0, 873);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 24);
			this->label2->TabIndex = 8;
			this->label2->Text = L"label2";
			// 
			// button2
			// 
			this->button2->Dock = System::Windows::Forms::DockStyle::Top;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(0, 180);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(220, 60);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Sprzedane";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// button5
			// 
			this->button5->Dock = System::Windows::Forms::DockStyle::Top;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button5->Location = System::Drawing::Point(0, 120);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(220, 60);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Klienci";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button4
			// 
			this->button4->Dock = System::Windows::Forms::DockStyle::Top;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button4->Location = System::Drawing::Point(0, 60);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(220, 60);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Zarz¹dzaj pojazdami";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Dock = System::Windows::Forms::DockStyle::Top;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button3->Location = System::Drawing::Point(0, 0);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(220, 60);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Moje pojazdy";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// panelWys
			// 
			this->panelWys->Controls->Add(this->pictureBox1);
			this->panelWys->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelWys->Location = System::Drawing::Point(220, 0);
			this->panelWys->Name = L"panelWys";
			this->panelWys->Size = System::Drawing::Size(1461, 897);
			this->panelWys->TabIndex = 1;
			this->panelWys->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panelWys_Paint);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(321, 225);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(803, 415);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1681, 897);
			this->Controls->Add(this->panelWys);
			this->Controls->Add(this->panelMenu);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->panelMenu->ResumeLayout(false);
			this->panelMenu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panelWys->ResumeLayout(false);
			this->panelWys->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panelWys_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentForm != nullptr && !currentForm->IsDisposed) {
		currentForm->Close();
	}
	
	if (m_p == nullptr || m_p->IsDisposed) {
		m_p = gcnew Moje_pojazdy(user);
		m_p->TopLevel = false;
		panelWys->Controls->Add(m_p);
	}
	m_p->BringToFront();
	m_p->Show();

	currentForm = m_p;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentForm != nullptr && !currentForm->IsDisposed) {
		currentForm->Close();
	}
	
	if (d_p == nullptr || d_p->IsDisposed) {
		d_p = gcnew Dodaj_pojazd(user);
		d_p->TopLevel = false;
		panelWys->Controls->Add(d_p);
	}
	d_p->BringToFront();
	d_p->Show();

	currentForm = d_p;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentForm != nullptr && !currentForm->IsDisposed) {
		currentForm->Close();
	}
	
	if (kl == nullptr || kl->IsDisposed) {
		kl = gcnew Klienci_form(user);
		kl->TopLevel = false;
		panelWys->Controls->Add(kl);
	}
	kl->BringToFront();
	kl->Show();

	currentForm = kl;
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (currentForm != nullptr && !currentForm->IsDisposed) {
		currentForm->Close();
	}
	
	if (sp != nullptr && !sp->IsDisposed) {
		sp->Close();
		delete sp;
	}

	sp = gcnew Sprzedane(user);
	sp->TopLevel = false;
	panelWys->Controls->Add(sp);

	sp->BringToFront();
	sp->Show();

	currentForm = sp;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (currentForm != nullptr && !currentForm->IsDisposed) {
		currentForm->Close();
	}
	
	if (user == "admin")
	{
		StatystykiAdmin^ SA = gcnew StatystykiAdmin();
		SA->TopLevel = false;
		panelWys->Controls->Add(SA);
		SA->BringToFront();
		SA->Show();
		currentForm = SA;
	}
	else
	{
		Statystyki^ SU = gcnew Statystyki(user);
		SU->TopLevel = false;
		panelWys->Controls->Add(SU);
		SU->BringToFront();
		SU->Show();
		currentForm = SU;
	}
}
};
}

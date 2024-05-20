#pragma once
#include"BazaDanych.h"
namespace Komis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Klienci_form
	/// </summary>
	public ref class Klienci_form : public System::Windows::Forms::Form
	{


	private:
		BazaKlienci^ bazak;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
		   String^ user;


	public:
		Klienci_form(void)
		{
			InitializeComponent();
			
		}

		Klienci_form(String^ u)
		{
			InitializeComponent();
			user = u;
			bazak = gcnew BazaKlienci();
			WczytajDaneDoDataGridView();
			
		}

	private:
		void WczytajDaneDoDataGridView()
		{
			bazak->WczytajZPliku();
			dataGridView1->Rows->Clear();

			for each (String ^ rekord in bazak->Dane)
			{
				array<String^>^ split = rekord->Split('\t');
				dataGridView1->Rows->Add(split);
			}
		}



	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Klienci_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:



	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Imie;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nazwisko;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nr_tel;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Usuwanie;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Imie = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nazwisko = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nr_tel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Usuwanie = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Imie, this->Nazwisko,
					this->Nr_tel, this->Usuwanie
			});
			this->dataGridView1->Location = System::Drawing::Point(79, 134);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(1278, 672);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Klienci_form::dataGridView1_CellContentClick);
			// 
			// Imie
			// 
			this->Imie->HeaderText = L"Imie";
			this->Imie->Name = L"Imie";
			this->Imie->ReadOnly = true;
			// 
			// Nazwisko
			// 
			this->Nazwisko->HeaderText = L"Nazwisko";
			this->Nazwisko->Name = L"Nazwisko";
			this->Nazwisko->ReadOnly = true;
			// 
			// Nr_tel
			// 
			this->Nr_tel->HeaderText = L"Numer telefonu";
			this->Nr_tel->Name = L"Nr_tel";
			this->Nr_tel->ReadOnly = true;
			// 
			// Usuwanie
			// 
			this->Usuwanie->HeaderText = L"Usuwanie";
			this->Usuwanie->Name = L"Usuwanie";
			this->Usuwanie->ReadOnly = true;
			this->Usuwanie->Text = L"Usuñ";
			this->Usuwanie->UseColumnTextForButtonValue = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(75, 67);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(204, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(382, 67);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(204, 20);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(674, 67);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(204, 20);
			this->textBox3->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(976, 67);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(146, 24);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Dodaj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Klienci_form::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(72, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Imie";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(379, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Nazwisko";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(671, 51);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Numer telefonu";
			// 
			// Klienci_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1445, 858);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Klienci_form";
			this->Text = L"Klienci_form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ imie = textBox1->Text;
		String^ nazwisko = textBox2->Text;
		String^ nr_tel = textBox3->Text;

		bazak->DodajRekord(imie, nazwisko, nr_tel);
		WczytajDaneDoDataGridView();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (dataGridView1->Columns[e->ColumnIndex]->Name == "Usuwanie")
	{
		if (MessageBox::Show("Czy jesteœ pewien ¿e chcesz usun¹æ tego klienta z bazy danych?", "Powiadomienie", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			dataGridView1->Rows[e->RowIndex]->Selected = true;
			int indeks = dataGridView1->SelectedRows[0]->Index;
			bazak->UsunRekord(indeks);
			WczytajDaneDoDataGridView();
		}
	}
}
};
}

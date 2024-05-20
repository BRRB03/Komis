#pragma once
#include "BazaDanych.h"
namespace Komis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Sprzedane
	/// </summary>
	public ref class Sprzedane : public System::Windows::Forms::Form
	{

	private:
		BazaSprzedane^ bazaS;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridViewImageColumn^ Zdjêcie;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Marka;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Model;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Rok;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Przebieg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cena_nabycia;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Imie;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nazwisko;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nr_tel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Sprzedano_za;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Sprzedawca;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Data;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Zysk;



































		   String^ user;

	public:
		Sprzedane(void)
		{
			InitializeComponent();
			
		}

		Sprzedane(String^ u)
		{
			InitializeComponent();
			user = u;
			bazaS = gcnew BazaSprzedane();
			WczytajDaneDoDataGridView();
		}

	private:
		void WczytajDaneDoDataGridView()
		{
			bazaS->WczytajZPliku();
			dataGridView1->Rows->Clear();

			for each (String ^ rekord in bazaS->Dane)
			{
				array<String^>^ split = rekord->Split('\t');
				String^ sciezkaObrazu = split[0];
				Image^ obraz = WczytajZdjecie(sciezkaObrazu);
				dataGridView1->Rows->Add(obraz, split[1], split[2], split[3], split[4], split[5], split[6], split[7], split[8], split[9], split[10], split[11], split[12]);
				ZyskZeSprzedazy();
			}
		}
		
		Image^ WczytajZdjecie(String^ ImagePath)
		{
			try
			{
				return Image::FromFile(Directory::GetCurrentDirectory() + ImagePath);
			}
			catch (Exception^ ex)
			{

				MessageBox::Show("B³¹d wczytywania obrazu: " + ex->Message, "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return nullptr;
			}
		}

		void ZyskZeSprzedazy()
		{
			int suma = 0;
			for each (DataGridViewRow ^ row in dataGridView1->Rows)
			{
				if (row->Cells["Zysk"]->Value != nullptr)
				{
					suma += Convert::ToInt32(row->Cells["Zysk"]->Value);
				}
			}

			label2->Text = Convert::ToString(suma);
		}


	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Sprzedane()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
























































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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Zdjêcie = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Marka = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Model = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rok = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Przebieg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cena_nabycia = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Imie = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nazwisko = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nr_tel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Sprzedano_za = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Sprzedawca = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Data = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Zysk = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(13) {
				this->Zdjêcie,
					this->Marka, this->Model, this->Rok, this->Przebieg, this->Cena_nabycia, this->Imie, this->Nazwisko, this->Nr_tel, this->Sprzedano_za,
					this->Sprzedawca, this->Data, this->Zysk
			});
			this->dataGridView1->Location = System::Drawing::Point(34, 30);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 100;
			this->dataGridView1->Size = System::Drawing::Size(1376, 753);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Sprzedane::dataGridView1_CellContentClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(1255, 803);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Zysk:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(1315, 803);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"brak";
			// 
			// Zdjêcie
			// 
			this->Zdjêcie->HeaderText = L"Zdjêcie";
			this->Zdjêcie->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Zdjêcie->Name = L"Zdjêcie";
			this->Zdjêcie->ReadOnly = true;
			// 
			// Marka
			// 
			this->Marka->HeaderText = L"Marka";
			this->Marka->Name = L"Marka";
			this->Marka->ReadOnly = true;
			// 
			// Model
			// 
			this->Model->HeaderText = L"Model";
			this->Model->Name = L"Model";
			this->Model->ReadOnly = true;
			// 
			// Rok
			// 
			this->Rok->HeaderText = L"Rok";
			this->Rok->Name = L"Rok";
			this->Rok->ReadOnly = true;
			// 
			// Przebieg
			// 
			this->Przebieg->HeaderText = L"Przebieg";
			this->Przebieg->Name = L"Przebieg";
			this->Przebieg->ReadOnly = true;
			// 
			// Cena_nabycia
			// 
			this->Cena_nabycia->HeaderText = L"Cena nabycia";
			this->Cena_nabycia->Name = L"Cena_nabycia";
			this->Cena_nabycia->ReadOnly = true;
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
			// Sprzedano_za
			// 
			this->Sprzedano_za->HeaderText = L"Sprzedano za";
			this->Sprzedano_za->Name = L"Sprzedano_za";
			this->Sprzedano_za->ReadOnly = true;
			// 
			// Sprzedawca
			// 
			this->Sprzedawca->HeaderText = L"Sprzedawca";
			this->Sprzedawca->Name = L"Sprzedawca";
			this->Sprzedawca->ReadOnly = true;
			// 
			// Data
			// 
			this->Data->HeaderText = L"Data";
			this->Data->Name = L"Data";
			this->Data->ReadOnly = true;
			// 
			// Zysk
			// 
			this->Zysk->HeaderText = L"Zysk";
			this->Zysk->Name = L"Zysk";
			this->Zysk->ReadOnly = true;
			// 
			// Sprzedane
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1445, 858);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Sprzedane";
			this->Text = L"Sprzedane";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (dataGridView1->Columns[e->ColumnIndex]->Name == "Usuwanie")
	{
		if (MessageBox::Show("Czy jesteœ pewien ¿e chcesz usun¹æ sprzedany samochód z bazy danych?", "Powiadomienie", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			dataGridView1->Rows[e->RowIndex]->Selected = true;
			int indeks = dataGridView1->SelectedRows[0]->Index;
			bazaS->UsunRekord(indeks);
			WczytajDaneDoDataGridView();
		}
	}
}
};
}

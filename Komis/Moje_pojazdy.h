#pragma once
#include "BazaDanych.h"
#include "Okno_sprzeda¿y.h"
namespace Komis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Moje_pojazdy
	/// </summary>
	public ref class Moje_pojazdy : public System::Windows::Forms::Form
	{




	private:
		BazaSamochody^ baza;
		String^ user;

	public:
		Moje_pojazdy(void)
		{
			InitializeComponent();
			
		}

		Moje_pojazdy(String^ u)
		{
			InitializeComponent();
			user = u;
			baza = gcnew BazaSamochody();
			WczytajDaneDoDataGridView();
			
		}
		
		

	private:
		void WczytajDaneDoDataGridView()
		{
			baza->WczytajZPliku();
			dataGridView1->Rows->Clear();

			for each (String ^ rekord in baza->Dane)
			{
				array<String^>^ split = rekord->Split('\t');
				String^ sciezkaObrazu = split[0];
				Image^ obraz = WczytajZdjecie(sciezkaObrazu);
				dataGridView1->Rows->Add(obraz, split[1], split[2], split[3], split[4], split[5], split[6]);
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
		





	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Moje_pojazdy()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;








	private: System::Windows::Forms::DataGridViewImageColumn^ Zdjêcie;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Marka;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Model;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Rok;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Przebieg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cena_nabycia;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cena;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Sprzedawanie;


















































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
			this->Zdjêcie = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Marka = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Model = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rok = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Przebieg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cena_nabycia = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cena = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Sprzedawanie = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Zdjêcie,
					this->Marka, this->Model, this->Rok, this->Przebieg, this->Cena_nabycia, this->Cena, this->Sprzedawanie
			});
			this->dataGridView1->Location = System::Drawing::Point(45, 36);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 100;
			this->dataGridView1->Size = System::Drawing::Size(1369, 805);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Moje_pojazdy::dataGridView1_CellContentClick);
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
			// Cena
			// 
			this->Cena->HeaderText = L"Cena";
			this->Cena->Name = L"Cena";
			this->Cena->ReadOnly = true;
			// 
			// Sprzedawanie
			// 
			this->Sprzedawanie->HeaderText = L"Sprzedawanie";
			this->Sprzedawanie->Name = L"Sprzedawanie";
			this->Sprzedawanie->ReadOnly = true;
			this->Sprzedawanie->Text = L"Sprzedaj";
			this->Sprzedawanie->UseColumnTextForButtonValue = true;
			// 
			// Moje_pojazdy
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1461, 897);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Moje_pojazdy";
			this->Text = L"Moje_pojazdy";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (dataGridView1->Columns[e->ColumnIndex]->Name == "Sprzedawanie")
		{
			dataGridView1->Rows[e->RowIndex]->Selected = true;
			Okno_sprzeda¿y^ OS = gcnew Okno_sprzeda¿y(dataGridView1->SelectedRows[0]->Index, user);
			OS->ShowDialog();
			if (OS->CzySprzedano == 1)
			{
				int indeks = dataGridView1->SelectedRows[0]->Index;
				baza->UsunRekord(indeks);
				WczytajDaneDoDataGridView();
			}
		}
	}
	};
}



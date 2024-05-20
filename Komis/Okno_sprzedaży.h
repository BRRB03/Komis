#pragma once
#include "BazaDanych.h"
#include "Sprzedane.h"


namespace Komis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Okno_sprzeda¿y
	/// </summary>
	public ref class Okno_sprzeda¿y : public System::Windows::Forms::Form
	{
	private:
		BazaKlienci^ bazaK;
		BazaSamochody^ bazaSam;
		BazaSprzedane^ bazaSprz;
		String^ user;
		int cena;
		int progmin;
		String^ data;

	private: System::Windows::Forms::DataGridView^ dataGridView1;



	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Imie;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nazwisko;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nr_tel;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Wybór;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;


	private: System::Windows::Forms::Label^ label13;



	

		   

	public:
		Okno_sprzeda¿y(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			
			
			//
		}

		Okno_sprzeda¿y(int indeks, String^ u)
		{
			InitializeComponent();
			DateTime today = DateTime::Now;
			data = today.ToString("yyyy-MM-dd");
			user = u;
			bazaSam = gcnew BazaSamochody();
			WczytajDane(indeks);
		
			
			bazaK = gcnew BazaKlienci();
			WczytajDaneDoDataGridView();

			bazaSprz = gcnew BazaSprzedane();

		}
		int CzySprzedano = 0;
		String^ sciezkaObrazu;
	private:
		void WczytajDane(int indeks)
		{
			bazaSam->WczytajZPliku();
			
			String^ rekord = bazaSam->Dane[indeks];
			array<String^>^ split = rekord->Split('\t');
			sciezkaObrazu = split[0];
			Image^ obraz = WczytajZdjecie(sciezkaObrazu);
			
			label2->Text = split[1];
			label4->Text = split[2];
			label6->Text = split[3];
			label8->Text = split[4];
			label9->Text = split[5];
			textBox1->Text = split[6];
			pictureBox1->Image = obraz;

			cena = Convert::ToInt32(split[6]);
			int procent = Convert::ToInt32(split[7]);
			
			progmin = cena - (cena * procent / 100);
			label15->Text = "(" + Convert::ToString(progmin) + " - " + split[6] + ")";
		}
	

	private:
		void WczytajDaneDoDataGridView()
		{
			bazaK->WczytajZPliku();
			dataGridView1->Rows->Clear();

			for each (String ^ rekord in bazaK->Dane)
			{
				array<String^>^ split = rekord->Split('\t');
				dataGridView1->Rows->Add(split);
			}
		}
		
		void DaneKlienta(String^ imie, String^ nazwisko)
		{
			label13->Text = imie + " " + nazwisko;
			
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
		~Okno_sprzeda¿y()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Imie = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nazwisko = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nr_tel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Wybór = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(374, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Marka:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(23, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(313, 259);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(507, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(374, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Model:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(507, 99);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(374, 139);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 20);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Rok:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(507, 139);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 20);
			this->label6->TabIndex = 7;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(374, 177);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(75, 20);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Przebieg:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(507, 177);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(51, 20);
			this->label8->TabIndex = 9;
			this->label8->Text = L"label8";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(507, 215);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(51, 20);
			this->label9->TabIndex = 11;
			this->label9->Text = L"label9";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(374, 215);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(109, 20);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Cena nabycia:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(19, 333);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(97, 20);
			this->label11->TabIndex = 12;
			this->label11->Text = L"Sprzedaj za:";
			this->label11->Click += gcnew System::EventHandler(this, &Okno_sprzeda¿y::label11_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(122, 335);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 13;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Okno_sprzeda¿y::textBox1_KeyPress);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Imie, this->Nazwisko,
					this->Nr_tel, this->Wybór
			});
			this->dataGridView1->Location = System::Drawing::Point(23, 404);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(790, 236);
			this->dataGridView1->TabIndex = 14;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Okno_sprzeda¿y::dataGridView1_CellContentClick);
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
			// Wybór
			// 
			this->Wybór->HeaderText = L"Wybór";
			this->Wybór->Name = L"Wybór";
			this->Wybór->ReadOnly = true;
			this->Wybór->Text = L"Wybierz";
			this->Wybór->UseColumnTextForButtonValue = true;
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(568, 333);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(187, 30);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Sprzedaj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Okno_sprzeda¿y::button1_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(296, 342);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(80, 13);
			this->label12->TabIndex = 16;
			this->label12->Text = L"Wybrany klient:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(382, 342);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(28, 13);
			this->label13->TabIndex = 17;
			this->label13->Text = L"brak";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(84, 374);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(43, 13);
			this->label14->TabIndex = 18;
			this->label14->Text = L"Zakres:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(122, 374);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(13, 13);
			this->label15->TabIndex = 19;
			this->label15->Text = L"0";
			// 
			// Okno_sprzeda¿y
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(832, 674);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Okno_sprzeda¿y";
			this->Text = L"Okno_sprzeda¿y";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
	}

//przycisk sprzedaj
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if ((user != "admin") && (Convert::ToInt32(textBox1->Text) > cena || Convert::ToInt32(textBox1->Text) < progmin))
	{
		MessageBox::Show("Podana cena nie mieœci siê w zakresie. Tylko admin ma mo¿liwoœæ wprowadzenia dowolnej ceny", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else
	{
		if (MessageBox::Show("Czy jesteœ pewien ¿e chcesz sprzedaæ ten samochód?", "Powiadomienie", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			int zysk = Convert::ToInt32(textBox1->Text) - Convert::ToInt32(label9->Text->ToString());

			bazaSprz->DodajRekord(sciezkaObrazu, label2->Text->ToString(), label4->Text->ToString(), label6->Text->ToString(), label8->Text->ToString(), label9->Text->ToString(), dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString(), dataGridView1->SelectedRows[0]->Cells[1]->Value->ToString(), dataGridView1->SelectedRows[0]->Cells[2]->Value->ToString(), textBox1->Text->ToString(), user, data, Convert::ToString(zysk));

			CzySprzedano = 1;
			this->Close();

		}
	}
	
}



//przycisk wyboru
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (dataGridView1->Columns[e->ColumnIndex]->Name == "Wybór")
	{
		dataGridView1->Rows[e->RowIndex]->Selected = true;
		DaneKlienta(dataGridView1->CurrentRow->Cells[0]->Value->ToString(), dataGridView1->CurrentRow->Cells[1]->Value->ToString());
		button1->Enabled = true;	
	}
}
private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
	{
		e->Handled = true;
	}
}
};
}

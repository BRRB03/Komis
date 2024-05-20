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
	/// Podsumowanie informacji o Dodaj_pojazd
	/// </summary>
	public ref class Dodaj_pojazd : public System::Windows::Forms::Form
	{
	private:
		BazaSamochody^ baza;
		String^ selectedFilePath;
		String^ destinationFolderPath;
	private: System::Windows::Forms::DataGridViewImageColumn^ Zdjêcie;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Marka;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Model;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Rok;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Przebieg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cena_nabycia;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cena;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Prog_rabatowy;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Usuwanie;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;

		   String^ user;
		   
	public:
		Dodaj_pojazd(void)
		{
			InitializeComponent();			
		}

		Dodaj_pojazd(String^ u)
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
				dataGridView1->Rows->Add(obraz, split[1], split[2], split[3], split[4], split[5], split[6], split[7]);
				
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
		~Dodaj_pojazd()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;

private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ label8;


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
			this->Prog_rabatowy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Usuwanie = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->Zdjêcie,
					this->Marka, this->Model, this->Rok, this->Przebieg, this->Cena_nabycia, this->Cena, this->Prog_rabatowy, this->Usuwanie
			});
			this->dataGridView1->Location = System::Drawing::Point(33, 168);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 100;
			this->dataGridView1->Size = System::Drawing::Size(1394, 667);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dodaj_pojazd::dataGridView1_CellContentClick);
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
			// Prog_rabatowy
			// 
			this->Prog_rabatowy->HeaderText = L"Próg rabatowy (%)";
			this->Prog_rabatowy->Name = L"Prog_rabatowy";
			this->Prog_rabatowy->ReadOnly = true;
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
			this->textBox1->Location = System::Drawing::Point(83, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(155, 20);
			this->textBox1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(80, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Marka";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(83, 80);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(155, 20);
			this->textBox2->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(80, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Model";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(83, 124);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(155, 20);
			this->textBox3->TabIndex = 8;
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Dodaj_pojazd::textBox3_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(80, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Rok";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(323, 38);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(155, 20);
			this->textBox4->TabIndex = 10;
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Dodaj_pojazd::textBox4_KeyPress);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(320, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Przebieg";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(323, 80);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(155, 20);
			this->textBox5->TabIndex = 12;
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Dodaj_pojazd::textBox5_KeyPress);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(320, 64);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Cena nabycia";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1277, 78);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 23);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Dodaj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Dodaj_pojazd::button1_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(323, 124);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(155, 20);
			this->textBox6->TabIndex = 16;
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Dodaj_pojazd::textBox6_KeyPress);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(320, 108);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Cena";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(564, 80);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(149, 23);
			this->button3->TabIndex = 17;
			this->button3->Text = L"Dodaj zdjêcie";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Dodaj_pojazd::button3_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(561, 131);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(89, 13);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Wybrane zdjêcie:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(656, 131);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(28, 13);
			this->label8->TabIndex = 19;
			this->label8->Text = L"brak";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(822, 76);
			this->trackBar1->Maximum = 25;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(254, 45);
			this->trackBar1->TabIndex = 20;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &Dodaj_pojazd::trackBar1_ValueChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(930, 59);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(95, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Próg rabatowy (%):";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(1031, 60);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 22;
			this->label10->Text = L"0";
			// 
			// Dodaj_pojazd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1461, 897);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Dodaj_pojazd";
			this->Text = L"Dodaj_pojazd";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//przycisk dodaj
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ marka = textBox1->Text;
		String^ model = textBox2->Text;
		String^ rok = textBox3->Text;
		String^ przebieg = textBox4->Text;
		String^ cena_nabycia = textBox5->Text;
		String^ cena = textBox6->Text;
		String^ prog = label10->Text;
	
		String^ obraz = "\\dane\\No_image.png";


		if (!String::IsNullOrEmpty(textBox1->Text) && !String::IsNullOrEmpty(textBox2->Text) && !String::IsNullOrEmpty(textBox3->Text) && !String::IsNullOrEmpty(textBox4->Text) && !String::IsNullOrEmpty(textBox5->Text) && !String::IsNullOrEmpty(textBox6->Text))
		{
			try
			{
				String^ nazwapliku = textBox1->Text + textBox2->Text + Path::GetExtension(selectedFilePath);
				String^ destinationFilePath = Path::Combine(destinationFolderPath, nazwapliku);
				File::Copy(selectedFilePath, destinationFilePath);

				MessageBox::Show("Plik zosta³ skopiowany do: " + destinationFilePath, "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);

				obraz = "\\dane\\" + nazwapliku;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("B³¹d podczas kopiowania pliku: " + ex->Message, "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			baza->DodajRekord(obraz, marka, model, rok, przebieg, cena_nabycia, cena, prog);
			textBox1->Clear();
			textBox2->Clear();
			textBox3->Clear();
			textBox4->Clear();
			textBox5->Clear();
			textBox6->Clear();
			WczytajDaneDoDataGridView();
		}
		else
		{
			MessageBox::Show("Wype³nij puste pola", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	

		 
	 
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (dataGridView1->Columns[e->ColumnIndex]->Name == "Usuwanie")
	{
		if (MessageBox::Show("Czy jesteœ pewien ¿e chcesz usun¹æ ten samochód z bazy danych?", "Powiadomienie", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			dataGridView1->Rows[e->RowIndex]->Selected = true;
			int indeks = dataGridView1->SelectedRows[0]->Index;
			baza->UsunRekord(indeks);
			WczytajDaneDoDataGridView();
		}
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
	openFileDialog->Filter = "Pliki obrazów (*.jpg;*.png;*.bmp)|*.jpg;*.png;*.bmp|Wszystkie pliki (*.*)|*.*";
	openFileDialog->Title = "Wybierz plik obrazu";

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		selectedFilePath = openFileDialog->FileName;
		destinationFolderPath = Directory::GetCurrentDirectory() + "\\dane";

		label8->Text = selectedFilePath;
	}
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	

}
private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
	{
		e->Handled = true;
	}
}

private: System::Void textBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
	{
		e->Handled = true;
	}
}
private: System::Void textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
	{
		e->Handled = true;
	}
}
private: System::Void textBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
	{
		e->Handled = true;
	}
}
private: System::Void trackBar1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	label10->Text = trackBar1->Value.ToString();
}
};
}


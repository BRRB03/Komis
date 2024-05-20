#pragma once
#include "BazaDanych.h"


namespace Komis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace System::Globalization;
	

	/// <summary>
	/// Podsumowanie informacji o StatystykiAdmin
	/// </summary>
	public ref class StatystykiAdmin : public System::Windows::Forms::Form
	{
	private:
		BazaSprzedane^ bazaS;

	public:
		StatystykiAdmin(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//

			bazaS = gcnew BazaSprzedane();
			
			WczytajDaneDoChart();
			WczytajDaneDoChart2();
			InicjalizujComboBoxRokow();
			InicjalizujComboBoxMiesiecy();
			WczytajDaneDoDataGridView();
		}

	private:

		void WczytajDaneDoDataGridView()
		{
			bazaS->WczytajZPliku();
			dataGridView1->Rows->Clear();

			String^ wybranyRok = comboBox1->SelectedItem != nullptr ? comboBox1->SelectedItem->ToString() : "";
			String^ wybranyMiesiac = comboBox2->SelectedItem != nullptr ? comboBox2->SelectedItem->ToString() : "";

			for each (String ^ rekord in bazaS->Dane)
			{
				array<String^>^ split = rekord->Split('\t');
				DateTime date = DateTime::ParseExact(split[11], "yyyy-MM-dd", CultureInfo::InvariantCulture);
				String^ rok = date.ToString("yyyy", CultureInfo::InvariantCulture);
				String^ miesiac = date.ToString("MM", CultureInfo::InvariantCulture);

				if ((String::IsNullOrEmpty(wybranyRok) || wybranyRok == rok) &&
					(String::IsNullOrEmpty(wybranyMiesiac) || wybranyMiesiac == miesiac))
				{
					dataGridView1->Rows->Add(split[1], split[2], split[3], split[4], split[5], split[6], split[7], split[8], split[9], split[10], split[11], split[12]);
				}
			}

			ZyskZeSprzedazy();
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
		
		void InicjalizujComboBoxRokow()
		{
			
			for each (String ^ rekord in bazaS->Dane)
			{
				array<String^>^ split = rekord->Split('\t');
				DateTime date = DateTime::ParseExact(split[11], "yyyy-MM-dd", CultureInfo::InvariantCulture);
				String^ rok = date.ToString("yyyy", CultureInfo::InvariantCulture);

				
				if (!comboBox1->Items->Contains(rok))
				{
					comboBox1->Items->Add(rok);
				}
			}
		}

		void WczytajDaneDoChart()
		{
			bazaS->WczytajZPliku();
			Dictionary<String^, int>^ monthAmounts = gcnew Dictionary<String^, int>();

			
			String^ wybranyRok = comboBox1->SelectedItem != nullptr ? comboBox1->SelectedItem->ToString() : "";

			for each (String ^ rekord in bazaS->Dane)
			{
				array<String^>^ split = rekord->Split('\t');
				DateTime date = DateTime::ParseExact(split[11], "yyyy-MM-dd", CultureInfo::InvariantCulture);
				String^ rokMiesiac = date.ToString("yyyy-MM", CultureInfo::InvariantCulture);

				
				if (String::IsNullOrEmpty(wybranyRok) || wybranyRok == date.ToString("yyyy", CultureInfo::InvariantCulture))
				{
					
					String^ amountString = split[12];
					int amount = Int32::Parse(amountString);

					
					if (monthAmounts->ContainsKey(rokMiesiac))
					{
						monthAmounts[rokMiesiac] += amount;
					}
					else
					{
						monthAmounts->Add(rokMiesiac, amount);
					}
				}
			}

			Series^ series = gcnew Series();
			series->ChartType = SeriesChartType::Column;

			SortedDictionary<String^, int>^ sortedMonthAmounts = gcnew SortedDictionary<String^, int>(monthAmounts);

			for each (KeyValuePair<String^, int> entry in sortedMonthAmounts)
			{
				series->Points->AddXY(entry.Key, entry.Value);
			}

			chart1->Series->Clear();  
			chart1->Series->Add(series);

			chart1->ChartAreas[0]->AxisX->MajorGrid->Enabled = false;
			chart1->ChartAreas[0]->AxisY->MajorGrid->Enabled = false;
			chart1->ChartAreas[0]->AxisX->Title = "Miesi¹c";
			chart1->ChartAreas[0]->AxisY->Title = "Kwota";
		}



		void InicjalizujComboBoxMiesiecy()
		{
			comboBox2->Items->Clear(); 

			
			String^ wybranyRok = comboBox1->SelectedItem != nullptr ? comboBox1->SelectedItem->ToString() : "";

			for each (String ^ rekord in bazaS->Dane)
			{
				array<String^>^ split = rekord->Split('\t');
				DateTime date = DateTime::ParseExact(split[11], "yyyy-MM-dd", CultureInfo::InvariantCulture);
				String^ rok = date.ToString("yyyy", CultureInfo::InvariantCulture);
				String^ miesiac = date.ToString("MM", CultureInfo::InvariantCulture);

				
				if (!comboBox2->Items->Contains(miesiac) && (String::IsNullOrEmpty(wybranyRok) || wybranyRok == rok))
				{
					comboBox2->Items->Add(miesiac);
				}
			}
		}

		void WczytajDaneDoChart2()
		{
			bazaS->WczytajZPliku();
			Dictionary<String^, int>^ monthAmounts = gcnew Dictionary<String^, int>();

			
			String^ wybranyRok = comboBox1->SelectedItem != nullptr ? comboBox1->SelectedItem->ToString() : "";
			
			String^ wybranyMiesiac = comboBox2->SelectedItem != nullptr ? comboBox2->SelectedItem->ToString() : "";

			for each (String ^ rekord in bazaS->Dane)
			{
				array<String^>^ split = rekord->Split('\t');
				DateTime date = DateTime::ParseExact(split[11], "yyyy-MM-dd", CultureInfo::InvariantCulture);

				
				if ((String::IsNullOrEmpty(wybranyRok) || wybranyRok == date.ToString("yyyy", CultureInfo::InvariantCulture)) &&
					(String::IsNullOrEmpty(wybranyMiesiac) || wybranyMiesiac == date.ToString("MM", CultureInfo::InvariantCulture)))
				{
					
					String^ amountString = split[12];
					int amount = Int32::Parse(amountString);

					
					if (monthAmounts->ContainsKey(split[10]))
					{
						monthAmounts[split[10]] += amount;
					}
					else
					{
						monthAmounts->Add(split[10], amount);
					}
				}
			}

			
			Series^ series = gcnew Series();
			series->ChartType = SeriesChartType::Column;

			
			for each(KeyValuePair<String^, int> entry in monthAmounts)
			{
				series->Points->AddXY(entry.Key, entry.Value);
			}

			
			chart2->Series->Clear();  
			chart2->Series->Add(series);

			chart2->ChartAreas[0]->AxisX->MajorGrid->Enabled = false;
			chart2->ChartAreas[0]->AxisY->MajorGrid->Enabled = false;
			chart2->ChartAreas[0]->AxisX->Title = "Pracownik";
			chart2->ChartAreas[0]->AxisY->Title = "Kwota";
		}




	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~StatystykiAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
private: System::Windows::Forms::ComboBox^ comboBox2;
private: System::Windows::Forms::DataGridView^ dataGridView1;
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
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label4;




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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(44, 32);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Wyniki";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(665, 377);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(588, 442);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &StatystykiAdmin::comboBox1_SelectedIndexChanged);
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(738, 32);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Wyniki";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(665, 377);
			this->chart2->TabIndex = 2;
			this->chart2->Text = L"chart2";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(738, 442);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 3;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &StatystykiAdmin::comboBox2_SelectedIndexChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(12) {
				this->Marka,
					this->Model, this->Rok, this->Przebieg, this->Cena_nabycia, this->Imie, this->Nazwisko, this->Nr_tel, this->Sprzedano_za, this->Sprzedawca,
					this->Data, this->Zysk
			});
			this->dataGridView1->Location = System::Drawing::Point(44, 493);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 40;
			this->dataGridView1->Size = System::Drawing::Size(1359, 313);
			this->dataGridView1->TabIndex = 4;
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(1333, 809);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 24);
			this->label2->TabIndex = 6;
			this->label2->Text = L"brak";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(1273, 809);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 24);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Zysk:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(585, 426);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Rok";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(735, 426);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Miesi¹c";
			// 
			// StatystykiAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1445, 858);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"StatystykiAdmin";
			this->Text = L"StatystykiAdmin";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		WczytajDaneDoChart();
		WczytajDaneDoChart2();
		InicjalizujComboBoxMiesiecy();
		WczytajDaneDoDataGridView();
		
	}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	WczytajDaneDoChart2();
	WczytajDaneDoDataGridView();
}
private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void printDocument1_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e) {
	
}
};
}

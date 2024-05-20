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
	/// Podsumowanie informacji o Statystyki
	/// </summary>
	public ref class Statystyki : public System::Windows::Forms::Form
	{
	private:
		BazaSprzedane^ bazaS;
	private: System::Windows::Forms::Label^ label1;
		   String^ user;

	public:
		Statystyki(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			

		}

		Statystyki(String^ u)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			bazaS = gcnew BazaSprzedane();
			user = u;

			WczytajDaneDoChart(user);
			InicjalizujComboBoxRokow();

		}

	private:
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

		void WczytajDaneDoChart(String^ selectedName)
		{
			bazaS->WczytajZPliku();
			Dictionary<String^, int>^ monthAmounts = gcnew Dictionary<String^, int>();

			String^ wybranyRok = comboBox1->SelectedItem != nullptr ? comboBox1->SelectedItem->ToString() : "";

			for each (String ^ rekord in bazaS->Dane)
			{
				array<String^>^ split = rekord->Split('\t');

				
				if (split[10] == selectedName)
				{
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

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Statystyki()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::ComboBox^ comboBox1;

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
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(53, 49);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(979, 729);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(1150, 363);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Statystyki::comboBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(1084, 192);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(257, 39);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Twoje statystyki";
			// 
			// Statystyki
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1445, 858);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Statystyki";
			this->Text = L"Statystyki";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		WczytajDaneDoChart(user);
	}
};
}

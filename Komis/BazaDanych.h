#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

generic <typename T>
public ref class BazaDanych
{
private:
    List<T>^ dane;
    String^ sciezkaPliku;

public:
    BazaDanych(String^ nazwaPliku)
    {
        dane = gcnew List<T>();
        String^ sciezkaProgramu = Directory::GetCurrentDirectory();
        sciezkaPliku = sciezkaProgramu + "\\dane\\" + nazwaPliku;
        WczytajZPliku();
    }

    void DodajRekord(T rekord)
    {
        dane->Add(rekord);
        ZapiszDoPliku();
    }

    void UsunRekord(int indeks)
    {
        if (indeks >= 0 && indeks < dane->Count)
        {
            dane->RemoveAt(indeks);
            ZapiszDoPliku();
        }
    }

    void WczytajZPliku()
    {
        if (File::Exists(sciezkaPliku))
        {
            dane->Clear();
            StreamReader^ sr = gcnew StreamReader(sciezkaPliku);

            while (!sr->EndOfStream)
            {
                String^ linia = sr->ReadLine();
                dane->Add(safe_cast<T>(linia));
            }

            sr->Close();
        }
    }

    property List<T>^ Dane
    {
        List<T>^ get() { return dane; }
    }

private:
    void ZapiszDoPliku()
    {
        StreamWriter^ sw = gcnew StreamWriter(sciezkaPliku);

        for each (T rekord in dane)
        {
            sw->WriteLine(rekord);
        }

        sw->Close();
    }
};

public ref class BazaSamochody : BazaDanych<String^>
{
public:
    BazaSamochody() : BazaDanych("samochody.txt") {}

    void DodajRekord(String^ ImagePath, String^ marka, String^ model, String^ rok, String^ przebieg, String^ cena_nabycia, String^ cena, String^ prog)
    {
        String^ rekord = ImagePath + "\t" + marka + "\t" + model + "\t" + rok + "\t" + przebieg + "\t" + cena_nabycia + "\t" + cena + "\t" + prog;
        BazaDanych::DodajRekord(rekord);
    }
};

public ref class BazaSprzedane : BazaDanych<String^>
{
public:
    BazaSprzedane() : BazaDanych("sprzedane.txt") {}

    void DodajRekord(String^ ImagePath, String^ marka, String^ model, String^ rok, String^ przebieg, String^ cenaN, String^ imie, String^ nazwisko, String^ numtel, String^ sprzed, String^ sprzedawca, String^ data, String^ zysk)
    {
        String^ rekord = ImagePath + "\t" + marka + "\t" + model + "\t" + rok + "\t" + przebieg + "\t" + cenaN + "\t" + imie + "\t" + nazwisko + "\t" + numtel + "\t" + sprzed + "\t" + sprzedawca + "\t" + data + "\t" + zysk;
        BazaDanych::DodajRekord(rekord);
    }
};

public ref class BazaKlienci : BazaDanych<String^>
{
public:
    BazaKlienci() : BazaDanych("klienci.txt") {}

    void DodajRekord(String^ imie, String^ nazwisko, String^ nr_tel)
    {
        String^ rekord = imie + "\t" + nazwisko + "\t" + nr_tel;
        BazaDanych::DodajRekord(rekord);
    }
};

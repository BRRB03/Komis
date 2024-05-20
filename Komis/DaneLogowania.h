#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

public ref class BazaLogin
{
private:
    List<String^>^ dane;

public:
    BazaLogin()
    {
        dane = gcnew List<String^>();
    }

    void DodajRekord(String^ login, String^ haslo)
    {
        String^ rekord = login + "\t" + haslo;
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
        String^ sciezkaProgramu = Directory::GetCurrentDirectory();
        String^ sciezkaPliku = sciezkaProgramu + "\\dane\\Loginy.txt";

        if (File::Exists(sciezkaPliku))
        {
            dane->Clear();
            StreamReader^ sr = gcnew StreamReader(sciezkaPliku);

            while (!sr->EndOfStream)
            {
                String^ linia = sr->ReadLine();
                dane->Add(linia);
            }

            sr->Close();
        }
    }

    property List<String^>^ Dane
    {
        List<String^>^ get() { return dane; }
    }

private:
    void ZapiszDoPliku()
    {
        String^ sciezkaProgramu = Directory::GetCurrentDirectory();
        String^ sciezkaPliku = sciezkaProgramu + "\\dane\\Loginy.txt";
        StreamWriter^ sw = gcnew StreamWriter(sciezkaPliku);

        for each (String ^ rekord in dane)
        {
            sw->WriteLine(rekord);
        }

        sw->Close();
    }
};
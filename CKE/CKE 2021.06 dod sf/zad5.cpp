#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int.
#define X first
#define Y second

using namespace std;
//ifstream input("./DANE/napisy.txt");
ofstream output("wyniki5.txt");
const int ilosc_dni_w_mies[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
const int ilosc_dni_w_mies_24[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
const int luty_dod_2024 = 1;
const int pocz_ilosc_row = 10;
const int koszt_zakupu = 800;
const int koszt_wyp = 30;
const int koszt_serwisu = 15;
const int koszt_pocz = (koszt_serwisu + koszt_zakupu) * pocz_ilosc_row;
// nieczymma wypozyczalnia sobota i niedziela
// serwis niedziela , wszystkie rowery 15zl za kazdy
const double wiosna_wsp_popytu = 0.5;
const double lato_wsp_popytu = 0.9;
const double jesien_wsp_popytu = 0.4;
const double zima_wsp_popytu = 0.2;
//zaokraglamy zawsze w dół

struct Czas
{
	int day;
	int weekday;
	int month;
	int year;

	void print()
	{
		output << day << "." << month << "." << year;
	}
};
enum Dzien_tyg
{
	nieok = 0, pon = 1, wt, sro, czw, ptk, sob, ndz
};

enum Miesiac
{
	sty = 1, lut, mar, kwi, maj, cze, lip, sie, wrz, paz, lis, gru
};
const string miesiace[12] = {"sty","lut","mar","kwi","maj","cze","lip","sie","wrz","paz","lis","gru"};
bool comp(const Czas &a, const Czas & b)
{
	if (a.day == b.day && a.month == b.month && a.year == b.year)
		return true;
	return false;
}
int znajdz(vector<Czas>& d, const Czas& data)
{
	auto it = d.begin();
	while (it != d.end())
	{
		if (comp(*it, data))
			return (it)-d.begin();
		it++;
	}
	return -1;
}
//Pory roku
const pair<Czas, Czas> zima = { Czas{21,Dzien_tyg::nieok,Miesiac::gru,-1},Czas{20,Dzien_tyg::nieok,Miesiac::mar,-1} };
const pair<Czas, Czas> wiosna = { Czas{21,Dzien_tyg::nieok,Miesiac::mar,-1},Czas{20,Dzien_tyg::nieok,Miesiac::cze,-1} };
const pair<Czas, Czas> lato = { Czas{21,Dzien_tyg::nieok,Miesiac::cze,-1},Czas{22,Dzien_tyg::nieok,Miesiac::wrz,-1} };
const pair<Czas, Czas> jesien = { Czas{23,Dzien_tyg::nieok,Miesiac::wrz,-1},Czas{20,Dzien_tyg::nieok,Miesiac::gru,-1} };
Czas dzien_pierw = { 1,Dzien_tyg::nieok, 1,2023 };



//symulacja od 1 stycznia 2023 do 31 grudnia 2024
//pierwsze 
vector<Czas> dni;
void tworz_tabele_dni()
{

	Czas data = { 1 ,Dzien_tyg::ndz,Miesiac::sty,2023 };
	dni.push_back(data);
	for (int i = 2; i <= 365; i++)
	{
		if (ilosc_dni_w_mies[data.month] == data.day)
		{
			data.month = data.month + 1;
			data.day = 1;
		}
		else
			data.day++;
		data.weekday = data.weekday == 7 ? 1 : data.weekday + 1;
		dni.push_back(data);
	}
	data = { 1 ,Dzien_tyg::pon,Miesiac::sty,2024 };
	dni.push_back(data);
	for (int i = 2; i <= 366; i++)
	{
		if (ilosc_dni_w_mies_24[data.month] == data.day)
		{
			data.month = data.month + 1;
			data.day = 1;
		}
		else
			data.day++;
		data.weekday = data.weekday == 7 ? 1 : data.weekday + 1;
		dni.push_back(data);
	}
	//for (auto w : dni)
		//w.print();
}
double dostan_wsp(Czas data)
{
	if ((data.day >= 21 && data.month == zima.first.month) || ((data.day <= 20 && data.month == zima.second.month) || data.month < zima.second.month))
	{
		return zima_wsp_popytu;
	}
	if (((data.day >= 21 && data.month == wiosna.first.month) || data.month > wiosna.first.month)
		&& ((data.day <= 20 && data.month == wiosna.second.month) || data.month < wiosna.second.month))
	{
		return wiosna_wsp_popytu;
	}
	if (((data.day >= 21 && data.month == lato.first.month) || data.month > lato.first.month)
		&& ((data.day <= 22 && data.month == lato.second.month) || data.month < lato.second.month))
	{
		return lato_wsp_popytu;
	}
	return jesien_wsp_popytu;
}

struct Tabela1
{
	//Wypozyczamy w dniu robocze
	int laczny_koszt = koszt_pocz;
	int laczny_zarobek = 0;
	int cena_wyp_plus = 0;
	int ilosc_row_plus = 0;
	//Nazwy kolumn

	vector<Czas> daty;
	vector<int> zarobki;
	vector<int> koszty;
	
	vector<int> tabela[3];
	void tworz(vector<Czas> &dni);
	void czysc() {
		daty.clear(); zarobki.clear(); koszty.clear();
		laczny_koszt = koszt_pocz; laczny_zarobek = 0;
	}
	void zakup_row(Czas dzien);
	int suma_kosztow(const Czas &a, const Czas&  b);//<a,b>
	int suma_zarobkow(const Czas& a, const Czas&  b);//<a,b>
	int dochod(const Czas& a, const Czas& b);//<a,b>

	void print();
};

void Tabela1::tworz(vector<Czas>& dni)
{

	daty.pb(dni[0]);
	koszty.pb(laczny_koszt);
	zarobki.pb(laczny_zarobek);

	for (int i=1;i<dni.size();i++)
	{
		daty.pb(dni[i]);
		koszty.pb(koszty[i-1]);
		zarobki.pb(zarobki[i-1]);
		if (dni[i].weekday == Dzien_tyg::sob)
		{
			continue;
		}
		else if (dni[i].weekday == Dzien_tyg::ndz)
		{
			laczny_koszt += (pocz_ilosc_row + ilosc_row_plus) * koszt_serwisu;
		}
		else
		{
			int wypozyczane_rowery =(double)(pocz_ilosc_row + ilosc_row_plus) * dostan_wsp(dni[i]);
			laczny_zarobek += (koszt_wyp+cena_wyp_plus) * wypozyczane_rowery;
		}
		koszty[i]=laczny_koszt;
		zarobki[i] = laczny_zarobek;
	}
}
void Tabela1::zakup_row(Czas dzien)
{
	int j = znajdz(daty, dzien);

	if ((3 * koszt_zakupu) <= dochod(dzien_pierw, dzien))
	{
		laczny_zarobek = suma_zarobkow(dzien_pierw, dzien);
		ilosc_row_plus += 3;
		koszty[j] += 3 * koszt_zakupu;
		laczny_koszt = koszty[j];
		laczny_zarobek = zarobki[j];
		for (int i = j+1; i < dni.size(); i++)
		{
			koszty[i]=koszty[i - 1];
			zarobki[i]=zarobki[i - 1];
			if (dni[i].weekday == Dzien_tyg::sob)
			{
				continue;
			}
			else if (dni[i].weekday == Dzien_tyg::ndz)
			{
				laczny_koszt += (pocz_ilosc_row + ilosc_row_plus) * koszt_serwisu;
			}
			else
			{
				int wypozyczane_rowery = (double)(pocz_ilosc_row+ ilosc_row_plus) * dostan_wsp(dni[i]);
				laczny_zarobek += (koszt_wyp + cena_wyp_plus) * wypozyczane_rowery;
			}
			koszty[i] = laczny_koszt;
			zarobki[i] = laczny_zarobek;
		}
	}
	
}
int Tabela1::suma_kosztow(const Czas& a, const Czas& b)
{
	int i = znajdz(daty,a);
	int j = znajdz(daty,b);
	if (i == 0)
	{
		return koszty[j];
	}
	return koszty[j] - koszty[i - 1];
}
int Tabela1::suma_zarobkow(const Czas & a,const Czas& b)
{
	int i = znajdz(daty, a );
	int j = znajdz(daty, b);
	if (i == 0)
	{
		return zarobki[j];
	}
	return zarobki[j] - zarobki[i - 1];
}
int Tabela1::dochod(const Czas& a, const Czas& b)
{
	return suma_zarobkow(a, b) - suma_kosztow(a, b);
}
void Tabela1::print()
{
	cout << " Daty \t   Koszty \t Zarobki\n ";
	for (int i = 0; i < dni.size(); i++)
	{
		daty[i].print(); cout <<"\t" << koszty[i] << "\t"  << zarobki[i] <<'\t'<< zarobki[i]- koszty[i]<< "\n";
	}
}
Tabela1 dane;
void zad5_1()
{
	output << "Zad5_1:\n";
	output << "Koszty: "<<dane.suma_kosztow(dzien_pierw, {31,Dzien_tyg::nieok, 12,2023})<<"\tPrzychody:" << dane.suma_zarobkow(dzien_pierw, { 31,Dzien_tyg::nieok, 12,2023 }) << "\t Koszty mniejsze od przychodwo po raz pierwszy:";
	int i = 0;
	while (dane.suma_kosztow(dzien_pierw, dane.daty[i+1])>= dane.suma_zarobkow(dzien_pierw, dane.daty[i+1]))
		i++;
	dane.daty[i+1].print();
	output << '\n';
	output << '\n';
}
void zad5_2()
{
	output << "Zad5_2:\n";
	for (int i = 1; i <= 12;i++)
	{
		output << "Miesiac: " << miesiace[i - 1] << ", Dochod:"<< dane.dochod({ 1,Dzien_tyg::nieok,i,2023 }, { ilosc_dni_w_mies[i],Dzien_tyg::nieok,i,2023 }) << "\n";
	}
	output << '\n';
}
void zad5_3()
{
	output << "Zad5_3:\n";

	while (dane.laczny_zarobek - dane.laczny_koszt < 100000)
	{
		dane.cena_wyp_plus++;
		dane.czysc();
		dane.tworz(dni);

	}
	output << "a)" << koszt_wyp+ dane.cena_wyp_plus << '\n';
	while (dane.laczny_zarobek - dane.laczny_koszt < 125000)
	{
		dane.cena_wyp_plus++;
		dane.czysc();
		dane.tworz(dni);
	}
	output << "b)" << koszt_wyp+dane.cena_wyp_plus << '\n';
	while (dane.laczny_zarobek - dane.laczny_koszt < 150000)
	{
		dane.cena_wyp_plus++;
		dane.czysc();
		dane.tworz(dni);
	}
	output << "c)" << koszt_wyp+dane.cena_wyp_plus << '\n';
	output << '\n';
	dane.cena_wyp_plus=0;
	dane.czysc();
	dane.tworz(dni);
}
void zad5_4()
{
	output << "Zad5_4:\n";
	for (int i = 1; i <= 12; i++)
	{
		Czas dzien = { ilosc_dni_w_mies[i] ,Dzien_tyg::nieok, i, 2023 };
		dane.zakup_row(dzien);
	}
	for (int i = 1; i <= 11; i++)
	{
		Czas dzien = { ilosc_dni_w_mies_24[i] ,Dzien_tyg::nieok, i, 2024 };
		dane.zakup_row(dzien);
	}
	output << "Przychody: " << dane.laczny_zarobek << "\tKoszty: " << dane.laczny_koszt;//suma_kosztow(dzien_pierw, { ilosc_dni_w_mies_24[12] ,Dzien_tyg::nieok, 12, 2024 });
}

int main()
{
	tworz_tabele_dni();
	dane.tworz(dni);
	//dane.print();
	zad5_1();
	zad5_2();
	zad5_3();
	zad5_4();
}
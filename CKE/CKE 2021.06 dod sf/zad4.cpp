#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int.
#define X first
#define Y second
using namespace std;
ifstream input("./DANE/napisy.txt");
ofstream output("wyniki4.txt");
const int N = 1000;
vector<string > vec;
void zad4_1()
{
	int counter = 0;
	for (auto w : vec)
	{
		for (int i = 0; i < w.size(); i++)
		{
			if ((int)(w[i] - '0') < 10)
				counter++;
		}
	}
	output << "Zad4.1:\n";
	output << counter << '\n';
}
void zad4_2()
{
	string wynik;
	int j = 0;
	for (int i = 19; i < 1000; i += 20)
	{
		wynik = wynik + vec[i][j];
		j++;
	}
	output << "Zad4.2:\n";
	output << wynik << '\n';
}
bool czy_palindrom(string a)
{
	string b = a;
	reverse(a.begin(), a.end());
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] != a[i])
			return 0;
	}
	return 1;
}

void zad4_3()
{
	string wynik;
	for (auto w : vec)
	{
		string p = w + w[0];
		string d = w[49] + w;
		if (czy_palindrom(p) )
		{
			//cout << p << " " << d << "\n";
			wynik = wynik + p[25];
		}
		 if ((czy_palindrom(d)))
		{
			wynik = wynik + d[25];
		}
	}

	output << "Zad4.3:\n";
	output << wynik << '\n';
}
void zad4_4()
{

	string wynik;
	for (auto w : vec)
	{
		deque<char> v1;
		for (int i = 0; i < w.size(); i++)
		{
			if ((int)(w[i] - '0') < 10)
				v1.pb(w[i]);
		}
		if (v1.size() % 2 == 1)
			v1.pop_back();
		string pom;
		for (int i = 0; i < v1.size(); i++)
		{
			if (pom.size() == 2)
				pom = "";
			pom += v1[i];
			if (pom.size() == 2)
			{
				int w = stoi(pom);
				if (w < 65 || w>90)
					continue;
				char k = (char)w;
				wynik += w;
			}
		}
		if (wynik.size() > 2 && wynik[wynik.size() - 1] == 'X' && wynik[wynik.size() - 2] == 'X' && wynik[wynik.size() - 3] == 'X')
			break;
	}
	output << "Zad4.4:\n";
	output << wynik << '\n';
}

int main()
{
	for (int i = 0; i < N; i++)
	{
		string a;
		input >> a;
		vec.pb(a);
	}
	zad4_1();
	zad4_2();
	zad4_3();
	zad4_4();
	return 0;
}
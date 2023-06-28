#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
#define pb push_back
const int ILOSC=50;
using namespace std;
struct Dane
{
	string kod;
	string miasto;
	pii vec[70]={};
	int ilosc_lokali=0;
};
vector<Dane> vec_danych;
ifstream input("./Dane_2103/galerie.txt");
ofstream output("wyniki4_1.txt");
map<string,int>  maper;

int main()
{
	for(int i=0;i<ILOSC;i++)
	{
		Dane d1;
		input>>d1.kod>>d1.miasto;
		bool checker=1;
		for(int j=0;j<70;j++)
		{	
			int a,b;
			input>>a>>b;
			if(checker && a==0)
			{
				checker=0;
				d1.ilosc_lokali=j;
			}	
			d1.vec[j]={a,b};
			
		}
		vec_danych.pb(d1);
		maper[d1.kod]++;
	}
	auto it=maper.begin();
	while(it!=maper.end())
	{
		output<<it->first<<" "<<it->second<<'\n';
		it++;
	}

	return 0;
}
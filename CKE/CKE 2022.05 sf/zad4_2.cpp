#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
#define X first
#define Y second
ifstream input("./Dane_2205/liczby.txt");
ofstream output("wyniki4.txt",ios_base::app);
vector<int> liczby;
int counter=0;

//od 10 do 10^5
//liczby czynnikow,rozne czynniki
pii max1={};pii max2={};
pii rozklad(int a)
{
	pii wynik={0,0};
	int b=a;
	vector<int> vec;
	for(int i=2;i<=sqrt(a);i++)
	{	
		if(b%i==0)
			wynik.Y++;
		while(b%i==0)
		{
			b/=i;
			wynik.X++;
		}
	}
	if(b>1){wynik.X++;wynik.Y++;}

	return wynik;
	
}

int main()
{

	output<<"zad 4.2\n";
	int firs=-1;
	for(int i=0;i<200;i++)
	{
		int x;
		input>>x;
		liczby.push_back(x);
		pii r=rozklad(x);
		if(r.X>max1.Y)
		{
			max1={x,r.X};
		}
		if(r.Y>max2.Y)
		{
			max2={x,r.Y};
		}
			
	}
	output<<max1.X<<" "<<max1.Y<<" "<<max2.X<<" "<<max2.Y<<'\n';
	return 0;
4
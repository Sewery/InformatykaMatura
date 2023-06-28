

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
constexpr int LICZBA_PLANSZ=125;
int arr[LICZBA_PLANSZ][8][8]={};
ofstream output("zadanie1_3.txt");
ifstream input("./Dane_2203/szachy.txt");
map<char,int> white_pieces;
map<char,int> black_pieces;

const vector<char> pieces={'p','w','s','g','h','k'};

bool checker(pair<int,int> wieza , pair<int,int> krol ,int plansza)
{
	bool check =false;
	//kolumna
	if(wieza.X==krol.X)
	{
		check =true;
		for(int i=min(wieza.Y,krol.Y)+1;i<max(wieza.Y,krol.Y);i++)
		{
			if(arr[plansza][wieza.X][i]!=(int)'.')
				check=false;
		}
	}
	if(wieza.Y==krol.Y)
	{
		check =true;
		for(int i=min(wieza.X,krol.X)+1;i<max(wieza.X,krol.X);i++)
		{
			if(arr[plansza][i][wieza.Y]!=(int)'.')
				check=false;
		}
	}
	return check;
}
int main()
{
	int Ww_kb=0;
	int wb_Kw=0;

	for(int i=0;i<LICZBA_PLANSZ;i++)
	{
		//cout<<i<<"PP";
		
		int white=0;
		int black=0;
		vector<pair<int,int>> wieze_b;
		pair<int,int> krol_b={-1,-1};
		vector<pair<int,int>> wieze_w;
		pair<int,int> krol_w={-1,-1};

		for(int j=0;j<8;j++)
		{
			for(int k=0;k<8;k++)
			{
				char pi;
				input>>pi;
				arr[i][j][k]=(int)pi;
				if(pi=='.')continue;
			
				if(isupper(pi))
				{	
					if(pi=='K')
						krol_w={j,k};
					if(pi=='W')
						wieze_w.pb({j,k});				
					pi=tolower(pi);
					white++;
				}else
				{
					if(pi=='k')
						krol_b={j,k};
					if(pi=='w')
						wieze_b.pb({j,k});
					black++;
				}
				
			}
		}
		bool check_w=false;
		bool check_b=false;
		if( krol_b.X!=-1)
		{
			for(auto wieza:wieze_w)
			{
				if(checker(wieza,krol_b,i))
					check_w=true;
			}
		}
		if( krol_w.X!=-1)
		{
			for(auto wieza:wieze_b)
			{
				if(checker(wieza,krol_w,i))
					check_b=true;
			}
		}
		Ww_kb+=check_w;
		wb_Kw+=check_b;

		
	}
	output<<Ww_kb<<" "<<wb_Kw;
	return 0;
}
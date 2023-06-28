#include <bits/stdc++.h>
using namespace std;
constexpr int LICZBA_PLANSZ=125;
int arr[LICZBA_PLANSZ][8][8]={};
ofstream output("zadanie1_2.txt");
ifstream input("./Dane_2203/szachy.txt");
map<char,int> white_pieces;
map<char,int> black_pieces;

const vector<char> pieces={'p','w','s','g','h','k'};
int main()
{
	int stan_rown=0;
	int naj_mniej_rown=INT_MAX;

	for(int i=0;i<LICZBA_PLANSZ;i++)
	{
		//cout<<i<<"PP";
		
		int white=0;
		int black=0;
		//Opróżniamy nasze mapy
		white_pieces=map<char,int>();
		black_pieces=map<char,int>();
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
					pi=tolower(pi);
					white_pieces[pi]++;
					white++;
				}else
				{
					black_pieces[pi]++;
					black++;
				}
				
			}
		}
		bool flag =1;
		if(white!=black)continue;
		for(auto piece:pieces)
		{
			if(white_pieces[piece]!=black_pieces[piece])
				flag=0;
		}		
		if(flag==1)
		{
			stan_rown++;
			naj_mniej_rown=min(white+black,naj_mniej_rown);
		}
		
	}
	output<<stan_rown<<" "<<naj_mniej_rown;
	return 0;
}


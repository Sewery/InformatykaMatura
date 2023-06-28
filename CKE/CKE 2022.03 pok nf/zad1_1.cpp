#include <bits/stdc++.h>
using namespace std;
constexpr int LICZBA_PLANSZ=125;
int arr[LICZBA_PLANSZ][8][8]={};
ofstream output("zadanie1_1.txt");
ifstream input("./Dane_2203/szachy.txt");
int main()
{
	int najw_lb_pust_kol_pl=0;
	int lb_pl_zpusta_kol=0;
	for(int i=0;i<LICZBA_PLANSZ;i++)
	{
		vector<int> v(8,0);
		for(int j=0;j<8;j++)
		{
			for(int k=0;k<8;k++)
			{
				char a;
				input>>a;
				arr[i][j][k]=(int)a;
				if(a!='.')
					v[k]++;
			}
		}
		int counter=0;
		for(int j=0;j<8;j++)
		{
			if(v[j]==0 && counter==0)
			{
				lb_pl_zpusta_kol++;
			}
			if(v[j]==0)
				counter++;
				
		}
		najw_lb_pust_kol_pl=max(najw_lb_pust_kol_pl,counter);
	}
	output<<lb_pl_zpusta_kol<<" "<<najw_lb_pust_kol_pl;
	return 0;
}
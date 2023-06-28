
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
constexpr int MAXER=200000;
ofstream output("wyniki3.txt",ios_base::app);
ifstream input("./Dane_2203/liczby.txt");
int arr[MAXER+10]={};
void sieve()
{
	for(int i=2;i*i<MAXER;i++)
	{
		if(arr[i]==0)
		for(int j=i*i;j<MAXER;j+=i)
		{
			arr[j]=1;
		}
	}
}
int main()
{
	int counter=0;
	sieve();
	output<<"\nZad 3_3:";
	for(int j=0;j< 1000;j++)
	for(int i=0;i<3;i++)
	{
		int k;
		input>>k;
		if(i==0 && arr[k]==0 )
			counter++;
	}
	output<<counter<<'\n';
	return 0;
}
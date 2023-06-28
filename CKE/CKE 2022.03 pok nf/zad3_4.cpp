
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
constexpr int MAXER=200000;
ofstream output("wyniki3.txt",ios_base::app);
ifstream input("./Dane_2203/liczby.txt");
int arr[MAXER+10]={};
int gcd1(int a, int b)
{
	if(b==0)return a;
	return gcd1(b,a%b);
}
int main()
{
	int counter=0;output<<"Zad 3_4:\n";
	for(int j=0;j< 1000;j++)
	{
		int a,b,c;
		input>>a>>b>>c;
		if(gcd(a,b)==1)
			counter++;
	}
	output<<counter<<'\n';
	return 0;
}
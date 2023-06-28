
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
ofstream output("wyniki3.txt",ios_base::app);
ifstream input("./Dane_2203/liczby.txt");
int alg(int a, int x ,int M)
{
	int w=1;
	if(x==0)
		return w;
	if(x%2==0)
	{
		w=alg(a,x/2,M);
		w=(w*w)%M;
	}
	
	else
	{	
		w=alg(a,x-1,M);
		w=(w*a)%M;
		
	}
	return w;
}
int main()
{
	int counter=0;
	output<<"Zad 3_5:\n";
	for(int i=0;i< 1000;i++)
	{
		int M,a,b;
		input>>M>>a>>b;
		for(int j=0;j<M;j++)
		{
			int r=alg(a,j,M);
			if(r==b)
			{
		
				counter++;break;
			}
		}
	}
	output<<counter;

	return 0;
}
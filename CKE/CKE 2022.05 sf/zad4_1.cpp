#include <bits/stdc++.h>
using namespace std;
ifstream input("./Dane_2205/liczby.txt");
ofstream output("wyniki4.txt",ios_base::app);
vector<int> liczby;
int counter=0;

//od 10 do 10^6

bool check(int a)
{
	int ost_c=a%10;
	int k=1;
	while((a/(int)pow(10,k+1)!=0))
	{
		k++;
	}
	return ost_c==(a/(int)pow(10,k));
}

int main()
{

	output<<"zad 4.1\n";
	int firs=-1;
	for(int i=0;i<200;i++)
	{
		int x;
		input>>x;
		liczby.push_back(x);
		if(check(x))
		{
			if(firs==-1)
				firs=x;
			counter++;
		}
			
	}
	output<<counter<<" "<<firs<<'\n';
	return 0;
}
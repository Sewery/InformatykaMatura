#include <iostream>
#include <fstream>

using namespace std;

int liczydlo(long long int n, int &rzad)
{long long int k=0;
while(n>0) k+=n%10, n/=10;
rzad++;
if(k<10)
    return k;
else
    liczydlo(k,rzad);
}

int main()
{unsigned long long int n,p;
int tab[10]={0};
ifstream plik;
ofstream wyjscie;
wyjscie.open("wyniki3_2.txt");
plik.open("liczby.txt");
while(!plik.eof())
{
int rzad=0;
plik>>n;
p=liczydlo(n,rzad);
if (rzad==3) tab[p]++;
}
for(int i=0;i<10;i++)
    if (tab[i]!=0)
        wyjscie<<"K"<<i<<"  "<<tab[i]<<endl;
return 0;
}


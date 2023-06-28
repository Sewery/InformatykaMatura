#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#define ll unsigned long long
#define pb push_back
using namespace std;
ifstream input("./Dane/liczby.txt");
ofstream output("wynik3_2.txt");
const int N=100;
vector<ll> vec;
ll K[10]={};
void wczytaj()
{
    for(int i=0;i<N;i++)
    {
        ll a;
        input>>a;
        vec.pb(a);
    }

}
//zwraca odpowiednio grupe i rzad
pair<ll,ll> liczydlo(ll a,ll rzad)
{
    if(a<=9)
    {
        return {a,rzad};
    }
    ll suma=0;
    while(a>0)
    {
        suma+=a%10;
        a/=10;
    }
    rzad+=1;
    a=suma;
    return liczydlo(a,rzad);
}
void zad()
{
    for(ll w: vec)
    {
        pair<ll,ll> wynik=liczydlo(w,(ll)0);
        if(wynik.second==(ll)3)
        {
            K[wynik.first]++;
        }
    }
    for(int i=1;i<=9;i++)
    {
        output<<"K"<<i<<": "<<K[i]<<'\n';
    }
}
int main()
{
    wczytaj();
    zad();
    return 0;
}

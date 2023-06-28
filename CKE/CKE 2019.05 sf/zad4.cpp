#include "bits/stdc++.h"
#define pb push_back
#define ll
#define pii pair<int,int>
using namespace std;
ifstream input("./Dane_PR/liczby.txt");
ofstream output("wynik4.txt");
const int N=500;
vector<int> vec;
vector<string> vec2;
int pot_3[100002]={};
int sil_h[10]={};

void wczytaj()
{
    for(int i=0;i<N;i++)
    {
        string x; input>>x;
        vec2.pb(x);
        cout<<x<<'\n';
        int y= stoi(x);
        vec.pb(y);
    }
    int k=1;
    while(k<100002)
    {
        pot_3[k]=1;
        k*=3;
    }
    sil_h[0]=1;
    for(int i=1;i<=9;i++)
    {
        sil_h[i]=sil_h[i-1]*i;
    }
}
void zad4_1()
{
    output<<"Zad4_1\n";
    int c=0;
    for(auto w: vec)
    {
        if(pot_3[w]==1)
            c++;
    }
    output<<c<<'\n';
}
void zad4_2()
{
    output<<"Zad4_2\n";
    int c=0;
    for(string w: vec2)
    {
        int k=stoi(w);
        int s=0;
        for(auto h:w)
        {
            s+=sil_h[h-'0'];
        }
        if(k==s)
           output<<k<<'\n';
    }
}
void zad4_3()
{
    output<<"Zad4_3\n";
    int max_dl=0;int pierw_c=0;int najw_dziel=0;
    deque<int> ciag;
    ciag.pb(vec[0]);
    int curr_nwd=vec[0];
     for(int i=1;i<vec.size();i++)
    {
        int g=gcd(curr_nwd,vec[i]);
        ciag.pb(vec[i]);
        if(g>1)
        {
            curr_nwd=g;
        }else{
            int nwd_pom=vec[i];
            int k=0;
            deque<int> nowy;
            nowy.push_front(vec[i]);
            while((i-k)>0 && gcd(nwd_pom,vec[i-k-1])!=1 )
            {
                nowy.push_front(vec[i-k-1]);
                nwd_pom=gcd(nwd_pom,vec[i-k-1]);
                k++;
            }
            ciag=nowy;
            curr_nwd=nwd_pom;
        }
        if(ciag.size()>max_dl)
        {
            max_dl=ciag.size();
            pierw_c=ciag.front();
            najw_dziel=curr_nwd;
        }
    }
    output<<"Najwieksza dlugosc:"<<max_dl<<" , Pierwsza liczba:"<<pierw_c<<" , Najwiekszy wspolny dzilenik:"<<najw_dziel<<'\n';
}
int main()
{
    wczytaj();
    zad4_1();
    zad4_2();
    zad4_3();
    return 0;
}

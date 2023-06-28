#include <bits/stdc++.h>
using namespace std;
#define pb push_back
ifstream input("./Dane/dane.txt");
ofstream output("wyniki1.txt");
const int N=2526;//zakres[0,10000]
const int M=10000;
vector<int> dane;
bool is_skreslona[M+1]={};
bool is_prime[M+1]={};

void sieve()
{
    //is_skreslona[0]=true;
    //is_prime[0]=true;
    for(int i=2;i<=sqrt(M)+1;i++)
    {
        if(is_prime[i]==0)
        {
            for(int j=i*i;j<=M;j+=i)
                is_prime[j]=1;
        }

    }
}
void skreslanie( int k)
{
    int licz=1;
    int ind=2;
    while(ind<=M)
    {
        if(is_skreslona[ind]==0)
        {
            licz++;
            if( (licz%k)==0)
            {
                licz=0;
                is_skreslona[ind]=1;
            }
        }


        ind++;
    }
}
void preprocess()
{
     sieve();
    for(int i=0;i<N;i++)
    {
        int a;
        input>>a;
        dane.pb(a);
    }
    int ind=3;
    skreslanie(2);
    while(ind<=M)
    {
        skreslanie(ind);
        ind++;
        while(ind<=M && is_skreslona[ind]==1)
        {
            ind++;
        }
    }
    for(int i=0;i<100;i++)
    {
        if( is_skreslona[i])
            cout<<i<<" ";
    }
}
void zad_1_1()
{
    int licznik=0;
    for(auto w:dane)
        if(is_skreslona[w]==0)
            licznik++;
    output<<"Zad 1_1:\n";
    output<<licznik<<"\n";
}
void zad_1_2()
{
    int licznik=0;int pierw_wyraz=0;
    int max_licznik=0, max_pier_wyraz=0;
    for(auto w:dane)
    {
          if(is_skreslona[w]==1)
          {
             if(licznik>max_licznik)
             {
                 max_licznik=licznik;
                 max_pier_wyraz=pierw_wyraz;
             }
             licznik=0;
             pierw_wyraz=0;
          }
          if(is_skreslona[w]==0 )
          {
              if( pierw_wyraz==0)
                    pierw_wyraz=w;
              licznik++;
          }
    }
     output<<"Zad 1_2:\n";
    output<<"Pierwszy wyraz:"<<max_pier_wyraz<<", najdluzszy ciag:"<< max_licznik<<"\n";
}
void zad_1_3()
{
     output<<"Zad 1_3:\n";
     int licznik=0;
     for(auto w:dane)
    {
        if(is_skreslona[w]==0 && is_prime[w]==0)
        {
            licznik++;
        }
    }
    output<<licznik<<"\n";
}
int main()
{
    preprocess();
    zad_1_1();
    zad_1_2();
    zad_1_3();
    return 0;
}

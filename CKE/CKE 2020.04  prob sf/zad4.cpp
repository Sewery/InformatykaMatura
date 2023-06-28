#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;
const int N=1000;
ifstream input("Dane_PR2/dane4.txt");
ofstream output("zadanie4.txt");
vector<int> vec;
map<int,int> krot_luka;
int luka[1001]={};
int sumer=0;
void wczytaj()
{
    for(int i=0;i<N;i++)
    {
        int a; input>>a;
        vec.pb(a);
        if(i!=0)
        {
            luka[i]=abs(vec[i-1]-vec[i]);
            krot_luka[abs(vec[i-1]-vec[i])]++;
        }
    }

}
void zad4_1()
{
    output<<"Zad 4_1\n";
    int maxer=0,miner=INT_MAX-2;
    luka[0]=-1;
    for(int i=1;i<1000;i++)
    {
        maxer=max( luka[i],maxer);
        miner=min(luka[i],miner);
    }
     output<<"Najwieksza "<<maxer<<", najmniejsza "<<miner<<'\n';
}
void zad4_2()
{
      output<<"Zad 4_2 \n";
        int npocz=-1,nkon=0,nluka=0,ndl=0;
        int pocz=-1,dl=0;
        for(int i=1;i<1000;i++)
        {
            if(luka[i]!=luka[i-1])
            {
                if(dl>ndl)
                {
                    npocz=pocz;
                    nkon=i-1;
                    nluka=luka[i-1];
                    ndl=dl;
                }
                pocz=i-1;
                dl=2;

            }else
            {
                dl++;
            }
        }
        if(dl>ndl)
        {
            npocz=pocz;
            nkon=999;
            nluka=luka[999];
            ndl=dl;
        }
    output<<"Dlugosc:"<<ndl<<" ,poczatek "<<vec[npocz]<<" ,koniec "<<vec[nkon]<<'\n';
}
void zad4_3()
{
      output<<"Zad 4_3 \n";
      int maxer=0;
      vector<int> luki;
      for(auto w:krot_luka)
      {
            if(w.Y>maxer)
            {
                luki.clear();
                luki.pb(w.X);
                maxer=w.Y;
            }else if(w.Y==maxer)
            {
                luki.pb(w.X);
            }
      }
        output<<"Max Krotnosc:"<<maxer<<" ,luki ";
        for(auto w:luki)
        {
            output<<w<<" ";
        }

}
int main()
{
    wczytaj();
    zad4_1();
    zad4_2();
    zad4_3();


    return 0;
}

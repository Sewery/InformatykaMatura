#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;
ifstream input("Dane_PR2/pary.txt");
ofstream output("wyniki4.txt");
vector<pair<int,string>> vec;
const int N=100;
bool is_prime[1000]={};//1-not  0-yes
vector<int> primes;

void sieve()
{
    for(int i=2;i<=sqrt(N)+2;i++)
    {
        if(is_prime[i]==0)
        {
            for(int j=i*i;j<=N;j+=i)
            {
                is_prime[j]=1;
            }
        }
    }
    for(int i=2;i<=N;i++)
    {
        if(is_prime[i]==0)
        {

            primes.pb(i);
        }

    }
}
void wczytaj()
{
    sieve();
    for(int i=0;i<N;i++)
    {
        string a; int b;
        input>>b>>a;
        vec.pb({b,a});
        //output<<b<<" "<<a<<'\n';
    }
}
void zad4_1()
{
    output<<"Zad4.1\n";
    for(auto p: vec)
    {
        int a=p.X;
        if(a%2==1)continue;
        for(auto w: primes)
        {
            if(is_prime[a-w]==0)
            {
                output<<a<<" "<<w<<" "<<a-w<<"\n";
                break;
            }
        }
    }
}
void zad4_2()
{
    output<<"Zad4.2\n";
     for(auto p: vec)
    {
            string a=p.Y;
            string maxer="";
            string pom;char w='0';
            for(auto c: a)
            {
                if(c!=w )
                {
                    if(maxer.size()<pom.size())
                        maxer=pom;
                    pom="";
                    w=c;
                }
                pom+=c;

            }
            if(maxer.size()<pom.size())
                    maxer=pom;
           output<<maxer<<" "<<maxer.size()<<'\n';

    }
}
void zad4_3()
{
    output<<"Zad4.3\n";
    vector<pair<int,string>> good;
    for(auto p: vec)
    {
       if(p.X==(p.Y.size()))
            good.pb(p);
    }
    string best=good[0].Y;
    for(auto p:good)
    {
        if(best.compare(p.Y)>0)
        {
            best=p.Y;
        }
    }
    output<<best.size()<<" "<<best;
}
int main()
{
    wczytaj();
    zad4_1();
    zad4_2();
    zad4_3();
    return 0;
}

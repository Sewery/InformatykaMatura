#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define ll long long
using namespace std;
ifstream input("./Dane_2105/DANE_2105/instrukcje.txt");
ofstream output("wyniki4.txt");
const int N =2000;
const string dop="DOPISZ";
const string us="USUN";
const string zm="ZMIEN";
const string prz="PRZESUN";
vector<pair<string,char>> ciag;
int maxer=-1;string max_ins;
string napis;
int liery_dop[200]={};
void wczytaj()
{
    int c=0;
    string bef="";
    for(int i=0;i<N;i++)
    {
        string a;char b;
        input>>a>>b;
        if(bef==a)
        {
            c++;
        }else{
            if(maxer<c)
            {
                maxer=c;
                max_ins=bef;
            }
            bef=a;
            c=1;
        }
        ciag.pb({a,b});
        if(a==dop)
        {
            liery_dop[b]++;
            napis=napis+b;
        }
        else if(a==zm)
        {
            napis[napis.length()-1]=b;
        }else if(a==us)
        {
            napis.erase(napis.end()-1,napis.end());
            // napis.erase(napis.length()-1);
        }else if(a==prz)
        {
            auto it = find(napis.begin(),napis.end(),b);
            *it= ((b+1)%('Z'+1))<'A'?'A':(b+1) ;
        }
    }
    if(maxer<c)
    {
        maxer=c;
        max_ins=bef;
    }
    cout<<napis;

}
void zad4_1(){
    output<<"Zad4_1\n";
    output<<napis.size()<<"\n";
}
void zad4_2(){
   output<<"Zad4_2\n";
   output<<"rodzaj instrukcji - "<<max_ins<<",d³ugoœæ ci¹gu - "<<maxer<<'\n';
}
void zad4_3(){
   output<<"Zad4_3\n";
   int litera=0;
   int ile=0;
   for(int i=0;i<200;i++)
   {
       if(ile< liery_dop[i])
       {
           ile= liery_dop[i];
           litera=i;
       }
   }
    output<<"litera- "<<(char)litera<<",dopisywana "<<ile<<" razy "<<'\n';
}
void zad4_4(){
   output<<"Zad4_4\n";
   output<<napis;
}
int main()
{
    wczytaj();
    zad4_1();
    zad4_2();
    zad4_3();
    zad4_4();
    return 0;

}

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1000;
ifstream input("Dane_PR/sygnaly.txt");
ofstream output("wyniki4.txt");
vector<string> dane;
bool czy_litera[1000][26]={};

void wczytaj()
{
    for(int i=0;i<N;i++)
    {
        string a;
        input>>a;
        dane.pb(a);
    }
}
void zad4_1()
{
    output<<"zad 4_1\n";
    string przes;
    for(int i=39;i<N;i+=40)
    {
        przes+=dane[i][9];
    }
    output<<przes<<"\n";
}
void zad4_2()
{
    output<<"zad 4_2\n";
    int max_liter=0;
    string max_slowo;
    for(int i=0;i<N;i++)
    {
        for(char a: dane[i])
        {
            czy_litera[i][a-'A']=1;
        }
        int l=0;
        for(int j=0;j<26;j++)
        {
            if(czy_litera[i][j])
                l++;
        }
        //cout<<l<<" ";
        if(l>max_liter)
        {
            max_liter=l;
            max_slowo=dane[i];
        }
    }
    output<<max_slowo<<" "<<max_liter<<'\n';
}
void zad4_3()
{
 output<<"zad 4_3\n";
    int licznik=0;
    vector<string> slowa;
    for(int i=0;i<N;i++)
    {

        for(int j=0;j<dane[i].size();j++)
        {
             for(int k=j+1;k<dane[i].size();k++)
             {
                 if(abs(dane[i][j]-dane[i][k])>10)
                 {
                     //cout<<"a";
                     goto koniec;
                 }
             }
        }
        slowa.pb(dane[i]);
        koniec:;
    }
    for(auto s: slowa)
    output<<s<<"\n";
}
int main()
{
    wczytaj();
     zad4_1();
     zad4_2();
     zad4_3();
    return 0;
}

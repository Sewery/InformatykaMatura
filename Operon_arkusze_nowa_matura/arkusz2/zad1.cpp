#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
using namespace std;

ifstream input("./Dane/dane.txt");
ofstream output("wyniki1.txt");
const int N=2246;
vector<int> dane;
vector<int> licz[10200];
//convert do danego systemu
bool comp(pair<int,int> a , pair<int,int> b)
{
    return a.X>b.X;
}
string convert(int a, int sys)
{
    string str="";
    while(a>0)
    {
        if((a%sys)<10)
            str=(char)((a%sys)+'0')+str;
        else
            str=(char)((a%sys)+'A'-10)+str;
        a/=sys;
    }
    return str;
}
bool is_pal(string a)
{
    string pom=a;
    reverse(pom.begin(),pom.end());
    return a.compare(pom)==0;
}
void wczytaj()
{
    for(int i=0;i<N;i++)
    {
        int a;
        input>>a;
        dane.pb(a);
    }
}
void zad1_1()
{
    output<<"Zad1_1\n";
    int c=0;
    for(auto d:dane)
    {
        string b=convert(d,2);
        if(is_pal(b)==true)
            c++;
    }
    output<<c<<"\n";

}
void zad1_2()
{
     output<<"Zad1_2\n";
         int c=0;
    for(auto d:dane)
    {
        string b=convert(d,16);
        if(is_pal(b)==true)
            c++;
    }
    output<<c<<"\n";

}
void zad1_3()
{
     output<<"Zad1_3\n";
     for(int i=2;i<=16;i++)
     {
        output<<"W systemie "<<i<<":";
        int c=0;
        for(auto d:dane)
        {
            string b=convert(d,i);
            if(is_pal(b)==true)
                c++;
        }
        output<<c<<"\n";
     }

}
void zad1_4()
{
     output<<"Zad1_4\n";
    vector<pair<int,int>> zes;
    for(auto d:dane)
    {
        int c=0;
        vector<int> dle;
        for(int i=2;i<=16;i++)
        {
            string b=convert(d,i);
            if(is_pal(b)==true)
            {
                c++;
                dle.pb(i);
            }

        }
        zes.push_back({c,d});
       licz[d]=dle;
    }
    sort(zes.begin(),zes.end(),comp);
    for(int i=0;i<3;i++)
    {
        output<<zes[i].Y<<" "<<zes[i].X<<" ";
        for(auto w:licz[zes[i].Y])
            output<<w<<" ";
        output<<'\n';
    }
}
int main()
{
    wczytaj();
    zad1_1();
    zad1_2();
    zad1_3();
    zad1_4();
    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
void zad6_1()
{
    ifstream input("./Dane_NOWA/dane_6_1.txt");
    ofstream output("wyniki_6_1.txt");
    const int N=100;
    int k=107%26;
    for(int i=0;i<N;i++)
    {
        string a;
        input>>a;
        for(int i=0;i<a.size();i++)
        {
            a[i]=(int)a[i]+k>90?(((int)a[i]+k)%90)+'A'-1:(int)a[i]+k;
        }
       // cout<<a;
        output<<a<<'\n';
    }
}
void zad6_2()
{
    ifstream input("./Dane_NOWA/dane_6_2.txt");
    ofstream output("wyniki_6_2.txt");
    vector<string> vec;
    const int N=3000;
        for(int i=0;i<N;i++)
    {
        string a;int k;
        input>>a>>k;
        k=k%26;
        for(int i=0;i<a.size();i++)
        {
            a[i]=(int)a[i]-k<65?(-(65-(int)a[i]+k))+'Z'+1:(int)a[i]-k;
        }
        //cout<<a;
        output<<a<<'\n';
    }
}
void zad6_3()
{
    ifstream input("./Dane_NOWA/dane_6_3.txt");
    ofstream output("wyniki_6_3.txt");
    vector<string> vec;
    const int N=3000;
    for(int i=0;i<N;i++)
    {
        string a,b;
        int k=0;
        input>>a>>b;
        if(a[0]>b[0])
        {
            k='Z'-(int)a[0]+((int)b[0]-'A')+1;
        }else
        {
           k=(int)b[0]-(int)a[0];
        }
        //cout<<k<<" r";
        for(int i=1;i<a.size();i++)
        {

            char c=(int)a[i]+k>90?(((int)a[i]+k)%90)+'A'-1:(int)a[i]+k;

            if(c!=b[i])
            {
               // cout<<"p";
               //cout<<c<<" "<<b[i]<<i<<a<<"||";
              output<<a<<'\n';
              break;
            }
        }
        //cout<<a;

    }
}
int main()
{
    zad6_1();
    zad6_2();
    zad6_3();
    return 0;
}

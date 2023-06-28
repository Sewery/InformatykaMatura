#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;
const int N=2001;
vector<int> vec;
ifstream input("dane/liczby.txt");
ofstream output("wyniki1.txt");
bool is_fun[2002]={};
bool is_prime(int a)
{
    if(a==1)
        return true;
    for(int i=2;i*i<=a+1;i++)
    {
        if(a%i==0)
        {
            return false;
        }
    }
    return true;
}
int policzkw(int k)
{
 int nowa=0;
    while(k>0)
    {
        int pom=k%10;
        nowa+=pom*pom;
        k/=10;
    }
    return nowa;
}
pair<bool,int> cykl(int k,int licz, set<int>& liczby)
{

    if(liczby.find(policzkw(k))!=liczby.end() )
    {
        liczby.insert(policzkw(k));
        return {0,licz};
    }
    if(k==1)
    {
        liczby.insert(k);
        return {1,licz};
    }
    liczby.insert(k);
    licz++;
    int nowa=0;
    while(k>0)
    {
        int pom=k%10;
        nowa+=pom*pom;
        k/=10;
    }
   // cout<<nowa<<" ";
    //cout<<"A";
    return cykl(nowa,licz,liczby);
}

void in()
{
    for(int i=0;i<N;i++)
    {

        int a; input>>a;
        vec.pb(a);
    }
}
void zad1_1()
{
    output<<"zad1_1\n";
    int maxer=0;
    vector<int> v1;
    for(int i=1;i<=1000;i++)
    {
       // cout<<'\n';
       // cout<<i<<" ";
        set<int> pomer;
        pair<bool,int> w=cykl(i,1,pomer);
        if(w.X && maxer<w.Y)
        {
            v1.clear();
            v1.pb(i);
            maxer=w.Y;
        }else if(w.X && maxer==w.Y)
        {
            v1.pb(i);
        }
    }
    output<<maxer<<" ";
    for(auto a:v1)
    {
        output<<a<<" ";
    }
    output<<'\n';
}
void zad1_2()
{
    output<<"zad1_2\n";
    int counter=0;
    int i=0;
    for(auto a:vec)
    {
         set<int> pomer;
        auto c=cykl(a,1,pomer);
        if(c.X)
        {
            is_fun[i]=1;
            counter++;
        }
        i++;
    }
    output<<counter<<'\n';
}
void zad1_3()
{
    output<<"zad1_3\n";
    vector<int> maxi;
    vector<int> curr;
    int i=0;
    for(;i<N;i++)
    {
        if(is_fun[i]==0  || (curr.size()!=0 && curr.back()>=vec[i]))
        {
            if(curr.size()>maxi.size())
            {
                maxi=curr;
            }
            curr.clear();
        }
        if(is_fun[i])
            curr.pb(vec[i]);


    }
    output<<maxi.size()<<" "<<maxi[0]<<" "<<maxi.back();
    output<<'\n';
}
void zad1_4()
{
      output<<"zad1_4\n";
    int counter=0;
    for(auto a:vec)
    {
        set<int> pomer;
        auto c=cykl(a,1,pomer);
        if(c.X && is_prime(a))
            counter++;
    }
    output<<counter<<'\n';
}
int main()
{
   // cout<<INT_MAX;
    in();
   // cykl(97,1,97);
    zad1_1();
    zad1_2();
    zad1_3();
    zad1_4();
    return 0;
}

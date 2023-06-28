#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll algo(ll a)
{
    ll suma=1;
    ll d=2;
    while(d*d<=a)
    {
        if(a%d==0)
        {
             suma+=d;
             if(d!=a/d)
                suma+=a/d;
        }

        d++;
    }
    return suma;
}

int main()
{
    int licz=0;
    while(licz<20)
    {
        for(int i=2;i<=100000;i++)
        {
            if(algo(algo(i))==i&& algo(i)!=i)
            {
                cout<<i<<" "<<algo(i)<<endl;
                licz++;
                i=algo(i);
            }
        }
    }

    return 0;
}

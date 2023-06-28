#include <bits/stdc++.h>
using namespace std;
const int N= 2e5 +2;
int sieve[N]={};
void erasto()
{
    for(int i=2;i*i<=(N-2);i++)
    {
        if(sieve[i])
            continue;
        for(int j=i*i;j<=(N-2);j+=i)
        {
            sieve[j]=1;
        }
    }
}


int main()
{
    erasto();
    vector<vector<int>> czworacze_zes;
    for(int i=1;i<=(N-2)-8;i++)
    {
        if(!sieve[i] && !sieve[i+2] && !sieve[i+6] && !sieve[i+8])
        {
            vector<int> vec={i,i+2,i+6,i+8};

            czworacze_zes.push_back(vec);
        }
    }
    for(int i=0;i<3;i++)
    {
        cout<<'\n';
        for(auto w: czworacze_zes[i])
        {
            cout<<w<<" ";
        }
    }
    return 0;
}

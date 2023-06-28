#include<bits/stdc++.h>
using namespace std;

int fibo(int k)
{
    if(k<3)
    {
        return 1;
    }else
    {
        return (fibo(k-1)+fibo(k-2))%26;
    }
}
void func(string a)
{
    string szyfr;
    for(int i=0;i<=a.size();i++)
    {
        if(a[i]>='A' && a[i]<='Z')
        {
            szyfr+=(char)(65+(((int)a[i] -65 + fibo(i+1))%26));
        }
    }
    cout<<szyfr<<" ";
}
int main()
{
    func("JANKOWALSKIPOZDRAWIA");
    func("NIEPRZYJACIELNADCHODZI");
}

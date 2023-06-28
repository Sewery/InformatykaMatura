#include <bits/stdc++.h>
using namespace std;
#define pb push_back
ofstream output("wyniki3_2.txt");
const int N=1e6;
const int sN=1e3;
string to_binary(int a)
{
    string binary;
    int i=0;
    while((1<<i)<=a)
    {
        if((1<<i)&a)
            binary+="1";
        else
            binary+="0";
            i++;
    }
    return binary;
}
bool check_if_palindrom(string a)
{
    for(int i=0;i<=(a.size()-1)/2;i++)
    {
        if(a[i]!=a[a.size()-i-1])
            return false;
    }
    return true;

}
int main()
{
    int licznik=0;
    for(int i=1;i<sN;i+)
    {
        string i_str=to_string(i);
        string b=to_binary(i);
        if(check_if_palindrom(i_str) && check_if_palindrom(b))
        {
            cout<<i<<" ";
            licznik+=i;
        }
        string w=i_str;
        reverse(w.begin(),w.end());
        if(i_str.size()==2)
        {
            for(int j=0;j<=9;j++)
            {
                string doub_i_str=i_str+char( j +'0')+w;
                int doub_i=stoi(doub_i_str);
                string doub_b=to_binary(doub_i);
                if(check_if_palindrom(doub_i_str) && check_if_palindrom(doub_b))
                {
                    cout<<doub_i<<" ";
                    licznik+=doub_i;
                }
            }
        }
        if(i_str.size()>=2)
        {
            string doub_i_str=i_str+w;
            int doub_i=stoi(doub_i_str);
            string doub_b=to_binary(doub_i);
            if(check_if_palindrom(doub_i_str) && check_if_palindrom(doub_b))
            {
                cout<<doub_i<<" ";
                licznik+=doub_i;
            }

        }


    }
    output<<"Zad3_2\n";
    output<<licznik;
    return 0;
}

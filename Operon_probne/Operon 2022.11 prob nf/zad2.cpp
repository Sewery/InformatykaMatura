#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
using namespace std;
ifstream input ("./Dane/genetyka.txt");

bool check(string a )
{
     //cout<<a<<" ";
    int s=a.size();
    if(s==1)
        return true;
    while(s!=1)
    {
        if(s%2==1)
            return false;
        s/=2;
    }
   // cout<<a<<"\n";
    while(a.size()!=1)
    {
        //int poc=a.size();
        string b;
        for(int i=0;i<a.size();i+=2)
        {
            string pom=a.substr(i,2);
            if(pom=="BD")
            {
                b+="A";
            }else if(pom=="CA" || pom=="CD" )
            {

                b+="B";
            }else if(pom=="DD" )
            {

                b+="C";
            }else if(pom=="BC" )
            {

                b+="D";
            }else
            {
                return false;
            }
        }
        a=b;

    }
    return true;
}
int main()
{
    int counter=0;
    for(int i=0;i<76;i++)
    {
        string a;input>>a;
        if(!check(a))
            counter++;
    }
    cout<<counter;
}

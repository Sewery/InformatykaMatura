#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include<utility>


int lustro(int a)
{ int b;
            b=0;
            while(a>0)
            {b=b*10+a%10;
             a=a/10;
            }
            return b;
}

bool pierwsza(int a)
{
    int i;
    if(a<2) return false;
    if(a%2==0)
         if(a==2) return true;
             else return false;
    i=3;
    while(i*i<=a)
       {if(a%i==0) return false;
         i++;}
    return true;
}

int NWD(int a, int b)
{int r;
while(b>0)
    {r=a%b;
    a=b;
    b=r;}

return a;
}


using namespace std;
int tab[10001]={0};
int main()
{ ifstream plik;
  ofstream wynik;
  set <pair <int,int> > wy;
 // pair <int,int> ap;
  int a,b,p;
  const int n=10001;
  plik.open("liczby.txt");
  wynik.open("wynik1.txt");
  while(!plik.eof())
  {plik>>a;
   tab[a]=1;
  }

  for(int i=10;i<n;i++)
    if(tab[i]==1 && i%10!=0)
           {a=i;
            tab[i]=2;
            b=lustro(i);
            if (tab[b]==1)
            {tab[b]=2;
              if(a>b) swap(a,b);
               wy.insert(make_pair(a,b));

            }
         }
        wynik<<"zadanie 4.1"<<endl;
        wynik<<wy.size()<<endl;
   /* set <pair <int,int> >::iterator it;
    for(it=wy.begin();it!=wy.end();it++)
        wynik<<it->first<<"  "<<it->second<<endl;*/

        wy.clear();
    for(int i=10;i<n;i++)
       if(tab[i]!=0)
       {    a=i;
            tab[i]=1;
            b=lustro(i);
            if (pierwsza(a) && pierwsza(b))
                 {if(a>b) swap(a,b);
                     wy.insert(make_pair(a,b));}
       }
wynik<<"zadanie 4.2"<<endl;
        wynik<<wy.size()<<endl;
    set <pair <int,int> >::iterator it;
    for(it=wy.begin();it!=wy.end();it++)
        wynik<<it->first<<"  "<<it->second<<endl;

   wy.clear();

wynik<<"zadanie 4.3"<<endl;

int z=0;

for(int i=10;i<n;i++)
       if(tab[i]!=0)
       {    a=i;
            b=a;
            while(b!=0)
            {
                a=a*10+b%10;
                b=b/10;
            }

           if(z==0) z=a;
               else
                 z=NWD(z,a);


       }
   wynik<<z<<endl;
wynik<<"zadanie 4.4"<<endl;
 int j;
 b=0;
 for(int i=10;i<n;i++)
       if(tab[i]!=0)
       {    a=i+lustro(i);
           j=0;z=1;
           while(j<a)
           {
               j+=z;
               z++;
           }
           if (j==a) {b++;}

       }

   wynik<<b<<endl;
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;


int main()
{ifstream plik;
plik.open("genetyka.txt");
char geny[5][3]={{'A','B','D'},{'B','C','A'},{'B','C','D'},{'C','D','D'},{'D','B','C'}};
string s,s1;

int dlugosc,i,bledy=0;
bool koniec;
while(!plik.eof())
{plik>>s;
dlugosc=s.size();
i=1;
while(i<dlugosc) i*=2;

if (i==dlugosc)
    {koniec=true;
        while(s.size()>1 and koniec)
           { s1=s;
             s="";
             for(int j=0;j<s1.size()-1;j+=2)
             {i=0;
              while((geny[i][1]!=s1[j] or geny[i][2]!=s1[j+1])and i<5)
              i++;

              if (i==5) koniec=false;
              else
                s+=geny[i][0];
             }
       if (!koniec) bledy++;
           }

    }
else bledy++;
}
cout<<bledy;
    return 0;
}

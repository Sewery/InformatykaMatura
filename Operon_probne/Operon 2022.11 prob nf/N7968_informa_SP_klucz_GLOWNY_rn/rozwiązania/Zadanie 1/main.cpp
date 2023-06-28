#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int system_to_decy(string s, int sys)
{
    int w=0,dl=s.size();
    for(int i=0; i<dl;i++)
        if(s[i]>='A')
            w=w*sys+int(s[i]-'A'+10);
        else
            w=w*sys+int(s[i]-'0');
    return w;
}

int czas_kwart(string s)
{
  int gg,mm,ss;
  string pom="";
  gg=int(s[0]-'A')*6;
  mm=int(s[6]-'A')*15;
  ss=int(s[12]-'A')*15;

  for(int i=1;i<5;i++)
    pom+=s[i];
  gg+=system_to_decy(pom,2);
  pom="";
   for(int i=7;i<11;i++)
    pom+=s[i];
  mm+=system_to_decy(pom,2);
  pom="";
   for(int i=13;i<17;i++)
    pom+=s[i];
  ss+=system_to_decy(pom,2);
  return gg*60*60+mm*60+ss;
}

int ile_wydobycie(string s)
{
    int w=int(s[0]-'A')*250;
    s.erase(0,1);
    w+=system_to_decy(s,2);

       return w;
}

string sys_to_bin(int liczba,int n)
{
    string w="";
    while(liczba)
    {
        w=char('0'+liczba%2)+w;
        liczba/=2;
    }
    while(w.size()<n)
        w='0'+w;
    return w;
}

string czas_fabr(string s)
{
    int gg,mm,ss;
    string pom="";
    pom+=s[0];
    pom+=s[1];

    gg=system_to_decy(pom,8);
    pom="";pom+=s[3],pom+=s[4];
    mm=system_to_decy(pom,8);
    pom="";pom+=s[6];pom+=s[7];
    ss=system_to_decy(pom,8);

   pom=char('A'+gg/6)+sys_to_bin(gg%6,4)+":"+char('A'+mm/15)+sys_to_bin(mm%15,4)+":"+char('A'+ss/15)+sys_to_bin(ss%15,4);
    //cout<<pom<<endl;
    return pom;
}

int main()
{
    ifstream wejscie;
    ofstream wyjscie;
    string s1,s2;
    wejscie.open("kopalnia.txt");
    wyjscie.open("wyniki1.txt");
    getline(wejscie,s1);

    int n=system_to_decy(s1,2); //ilosc elementow

    int czas_kopalnia[n], wydobycie[n]; //czas w sekundach od pó³nocy
    for(int i=0;i<n;i++)
    {
        wejscie>>s1>>s2;
        czas_kopalnia[i]=czas_kwart(s1);
        wydobycie[i]=ile_wydobycie(s2);
    }

    char pomiary[n];   //tablica pomiary przechowuje warosci W,P,B dla odpowiednich pomiarów
    int wlasciwe=1,mozliwe=0,bledne=0,testowy;
    pomiary[0]='W';

    for (int i=1;i<n;i++)
    { if(pomiary[i-1]=='W' or pomiary[i-1]=='P')
        testowy=wydobycie[i-1];
      if (abs(testowy-wydobycie[i])<=testowy/20)
              pomiary[i]='W',wlasciwe++;
       else
        if(abs(testowy-wydobycie[i])<=testowy/10)
               pomiary[i]='P',mozliwe++;
      else pomiary[i]='B',bledne++;

    }
    wyjscie<<"Zadanie 1.1"<<endl;
    wyjscie<<"Wlasciwe = "<<wlasciwe<<endl<<"Prawdopodobne = "<<mozliwe<<endl <<"Bledne = "<<bledne<<endl;

   int maxx=0,koniec;
    testowy=0;
    for(int i=0;i<n;i++)
        {if (pomiary[i]=='W')
                  testowy++;
         else
            testowy=0;
         if (testowy>maxx)
            maxx=testowy,koniec=i;
        }
        int czasy=czas_kopalnia[koniec]- czas_kopalnia[koniec-maxx+1];
        int gg,ss,mm;
        gg=czasy/(60*60);
        czasy-=gg*60*60;
        mm=czasy/60;
        ss=czasy-mm*60;
        wyjscie<<endl<<"Zasanie 1.2"<<endl;
    wyjscie<<maxx<<endl<<'0'<<gg<<":"<<mm<<":"<<'0'<<ss<<endl<<endl;

    wejscie.close();
    wejscie.open("fabryka.txt");
    wejscie>>s1;

    int produkcja;
    string czas;
wyjscie<<"Zadanie 1.3"<<endl;
wyjscie<<sys_to_bin(system_to_decy(s1,8),0)<<endl;
    for(int i=0;i<n;i++)
    {
        wejscie>>s1>>s2;
        produkcja=system_to_decy(s2,8);
        czas=czas_fabr(s1);
        wyjscie<<czas<<" "<<char('A'+produkcja/250)+sys_to_bin(produkcja%250,8)<<endl;


    }





    wyjscie.close();
    return 0;
}

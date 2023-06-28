#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
using namespace std;
//A=0 ,B=15.C=30,D=45
ofstream output("wyniki1.txt");
struct Czas
{
    int godz=0;int minuta=0; int sek=0;
};
vector<pair<Czas,int>> dane_fab;
vector<pair<Czas,int>> dane_kop;
int to_dec(string a , int rep)
{
    int wynik=0;
    int iloczyn=1;
    for(int i=a.size()-1;i>=0;i--)
    {
        wynik+=(a[i]-'0')*iloczyn;
        iloczyn*=rep;
    }
    return wynik;
}
string from_dec(int a , int rep)
{
    string wynik="";
    int i=1;
    while(a>0)
    {
        wynik= (char)(a%rep+'0') +wynik;
        a/=rep;
    }
    if(wynik.size()==0)
        return "0";
    return wynik;
}
void in()
{
    ifstream inp1("./Dane/fabryka.txt");
    string h;
    inp1>>h;
    int N=to_dec(h,8);
    //cout<<N<<" ";
    //dane_fab.resize(N);
    for(int i=0;i<N;i++)
    {
        string czas;
        inp1>>czas;
        string g=czas.substr(0,2);
        string m=czas.substr(3,2);
         string s=czas.substr(6,2);
         Czas t={to_dec(g,8),to_dec(m,8),to_dec(s,8)};
       // string m
       // cout<<g<<" ";
        string k;
        inp1>>k;
        dane_fab.pb({t,to_dec(k,8)});
    }
    ifstream inp2("./Dane/kopalnia.txt");
    string w;
    inp2>>w;
    N=to_dec(w,2);
    //dane_kop.resize(N);
    for(int i=0;i<N;i++)
    {
        //cout<<"SS";
        string czas;
        inp2>>czas;
        string g=czas.substr(1,4);
        string m=czas.substr(7,4);
         string s=czas.substr(13,4);
         //cout<<czas<<" "<<g<<" "<<m<<" "<<s<<"\n";
         Czas t={to_dec(g,2),to_dec(m,2),to_dec(s,2)};

         switch (czas[0]){
             case 'A':t.godz+=0;break;
             case 'B':t.godz+=6;break;
             case 'C':t.godz+=12;break;
             case 'D':t.godz+=18;break;
        }
          switch (czas[5]){
             case 'A':t.minuta+=0;break;
             case 'B':t.minuta+=15;break;
             case 'C':t.minuta+=30;break;
             case 'D':t.minuta+=45;break;

        }
          switch (czas[10]){
             case 'A':t.sek+=0;break;
             case 'B':t.sek+=15;break;
             case 'C':t.sek+=30;break;
             case 'D':t.sek+=45;break;
             default:t.godz+=0;break;
        }

      //  cout<<czas<<" "<<t.godz<<" "<<t.minuta<<" "<<t.sek<<"\n";
             // string m
       // cout<<g<<" ";
        string k;
         inp2>>k;
         int ilosc=to_dec(k.substr(1,k.size()-1),2);
          switch (k[0]){
             case 'A':ilosc+=0;break;
             case 'B':ilosc+=250;break;
             case 'C':ilosc+=500;break;
             case 'D':ilosc+=750;break;
        }

        dane_kop.pb({t,ilosc});

    }
  //  for(auto w: dane_kop)
      //  cout<<w.X.godz<<" "<<w.Y<<'\n';
   // for(auto w: dane_fab)
        //cout<<w.X.godz<<" "<<w.Y<<'\n';
}

void zad1_1()
{
    output<<"Zad1_1\n";
    int wla=1;
    int pra=0;
    int zly=0;
    int pop=dane_kop[0].Y;
    for(int i=1;i<dane_kop.size();i++)
    {
        int roz=dane_kop[i].Y-pop;
        double udzial=abs((double)roz/(double)pop);
       // cout<<udzial<<" ";
        if(udzial<=0.05)
        {
            wla++;
            pop=dane_kop[i].Y;
        }

        else if(udzial<=0.1)
        {
            pra++;
            pop=dane_kop[i].Y;
        }
        else
            zly++;

    }
    output<<"Pomiary wlasciwe: "<<wla<<", pomiary prawdopodobne: "<<pra<<" ,pomiary bledne:"<<zly<<'\n';
}
void zad1_2()
{
    output<<"Zad1_2\n";
    int m_dl=0;Czas m_pocz,m_kon;
    int dl=1;Czas pocz=dane_kop[0].X;
    pair<Czas,int> pop=dane_kop[0];
    for(int i=1;i<dane_kop.size();i++)
    {
        int roz=dane_kop[i].Y-pop.Y;
        double udzial=abs((double)roz/(double)pop.Y);
        if(udzial>0.05)
        {
            if(m_dl<dl)
            {
                m_dl=dl;
                m_pocz=pocz;
                m_kon=pop.X;

            }
            pocz=dane_kop[i].X;
            dl=0;
        }else
            dl++;
        if(udzial<=0.1)
            pop=dane_kop[i];
    }
    output<<"Dlugosc: "<<m_dl<<" ,Poczatek: "<<m_pocz.godz<<": "<<m_pocz.minuta<<": "<<m_pocz.sek<<" ,Koniec: "<<m_kon.godz<<": "<<m_kon.minuta<<": "<<m_kon.sek<<'\n';
}
void zad1_3()
{
    output<<"Zad1_3\n";
    output<<from_dec(dane_fab.size(),8)<<'\n';
    for(int i=0;i<dane_fab.size();i++)
    {
        Czas czas=dane_fab[i].X;
        //cout<<czas.godz<<" "<<czas.minuta<<" "<<czas.sek<<" "<<dane_fab[i].Y<<"\n";
        string czas2;
        if(czas.godz<6)
        {
            czas2+="A"+from_dec(czas.godz,2)+":";
        }else if(czas.godz<12)
        {
            czas.godz-=6;
            czas2+="B"+from_dec(czas.godz,2)+":";
        }else if(czas.godz<16)
        {
            czas.godz-=12;
            czas2+="C"+from_dec(czas.godz,2)+":";
        }else
        {
            czas.godz-=18;
            czas2+="D"+from_dec(czas.godz,2)+":";
        }

         if(czas.minuta<15)
        {
            czas2+="A"+from_dec(czas.minuta,2)+":";
        }else if(czas.minuta<30)
        {
            czas.minuta-=15;
            czas2+="B"+from_dec(czas.minuta,2)+":";
        }else if(czas.minuta<45)
        {
            czas.minuta-=30;
            czas2+="C"+from_dec(czas.minuta,2)+":";
        }else
        {
            czas.minuta-=45;
            czas2+="D"+from_dec(czas.minuta,2)+":";
        }

         if(czas.sek<15)
        {
            czas2+="A"+from_dec(czas.sek,2);
        }else if(czas.sek<30)
        {
            czas.sek-=15;
            czas2+="B"+from_dec(czas.sek,2);
        }else if(czas.sek<45)
        {
            czas.sek-=30;
            czas2+="C"+from_dec(czas.sek,2);
        }else
        {
            czas.sek-=45;
            czas2+="D"+from_dec(czas.sek,2);
        }
        int tony=dane_fab[i].Y;
        czas2+="   ";

        if(tony<250)
        {
            czas2+="A"+from_dec(tony,2);
        }else if(tony<500)
        {
            tony-=250;
            czas2+="B"+from_dec(tony,2);
        }else if(tony<750)
        {
            tony-=500;
            czas2+="C"+from_dec(tony,2);
        }else
        {
            tony-=750;
            czas2+="D"+from_dec(tony,2);
        }
        output<<czas2<<"\n";
    }
}
int main()
{
    in();
    zad1_1();
    zad1_2();
    zad1_3();
    return 0;
}

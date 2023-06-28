#include <bits/stdc++.h>
#define pb push_back
using namespace std;
ifstream input("./Dane_PR/dane.txt");
ofstream output("wyniki6.txt");
const int N=200;
const int M=320;//liczby z przedzia³u [0,255]
int obraz[N][M]={};

void in()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            input>>obraz[i][j];
           // cout<<obraz[i][j]<<" ";
        }
      // cout<<'\n';
    }
}
void zad6_1()
{
    output<<"Zad 6_1\n";
    int mini=INT_MAX;
    int maxi=-1;
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            mini=min(mini,obraz[i][j]);
            maxi=max(maxi,obraz[i][j]);
        }
    }
    output<<mini<<" "<<maxi<<"\n";
}
void zad6_2()
{
    output<<"Zad 6_2\n";
    int to_change=0;
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<M/2;j++)
        {
            if(obraz[i][j]!=obraz[i][M-j-1])
            {
                to_change++;
                break;
            }

        }
    }
    output<<to_change<<'\n';
}
void zad6_3()
{
    output<<"Zad 6_3\n";
    int counter=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(i>0 && abs(obraz[i-1][j]-obraz[i][j])>128)
            {
                  // cout<<obraz[i-1][j]<<" "<<obraz[i][j]<<" ";
                counter++; continue;
            }
             else if(j>0 && abs(obraz[i][j-1]-obraz[i][j])>128)
            {
                     // cout<<obraz[i][j-1]<<" "<<obraz[i][j]<<" ";
                counter++; continue;
            }
            else if(i<(N-1) && abs(obraz[i+1][j]-obraz[i][j])>128)
            {
                   //cout<<obraz[i+1][j]<<" "<<obraz[i][j]<<" ";
                counter++; continue;
            }
            else if(j<(M-1) && abs(obraz[i][j+1]-obraz[i][j])>128)
            {
                   // cout<<obraz[i][j+1]<<" "<<obraz[i][j]<<" ";
                counter++; continue;
            }
            //cout<<"|";
        }
    }
     output<<counter<<'\n';
}


void zad6_4()
{
    output<<"Zad 6_4\n";
    int m_dl=0;
    for(int j=0;j<M;j++)
    {
        int dl=0, wyraz=-1;
         for(int i=0;i<N;i++)
        {
            if(obraz[i][j]!=wyraz)
            {
                m_dl=max(dl,m_dl);
                wyraz=obraz[i][j];
                dl=0;
            }

            dl++;
        }
        m_dl=max(dl,m_dl);
    }
     output<<m_dl;

}
int main()
{
    in();
    zad6_1();
    zad6_2();
    zad6_3();
    zad6_4();
    return 0;
}

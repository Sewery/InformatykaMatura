#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool zamiana_i_test(int liczba, int system)
{ vector <char> licz;
  int k,i;
if(liczba==0) return true;
while(liczba>0)
{ k=liczba%system;
  liczba/=system;
  if(k<10) licz.push_back(char('0'+k));
  if(k>9) licz.push_back(char('A'+(k-10)));
}
k=licz.size()-1;
i=0;

while(licz[i]==licz[k]&&i<k) i++,k--;
return (i>=k);
}


bool binarne(unsigned n)
{
    unsigned mask{0};
    for(unsigned tmp{n}; tmp; tmp >>= 1)
            mask = (mask << 1) | (tmp & 1);
    return mask == n;
}



int main()
{
int i;
ifstream inplik;
ofstream ofplik;
inplik.open("dane.txt");
ofplik.open("wyniki1.txt");

vector <int> wejsciowe;

while(!inplik.eof())
     {inplik>>i;
      wejsciowe.push_back(i);}

inplik.close();

ofplik<<"Zadanie 1.1"<<endl;
i=0;
for(int k=0;k<wejsciowe.size();k++)
{
    if(wejsciowe[k]%2==1&&binarne(wejsciowe[k])) i++;
    if (wejsciowe[k]==0) i++;

}
ofplik<<i<<endl;

ofplik<<"Zadanie 1.2"<<endl;
i=0;
for(int k=0;k<wejsciowe.size();k++)
{
   if(zamiana_i_test(wejsciowe[k],16)) i++;

}

ofplik<<i<<endl;

ofplik<<"Zadanie 1.3"<<endl;
int tab[17]={0},p;
for(int k=0;k<wejsciowe.size();k++)
{  i=0;
   for(p=2;p<17;p++)
       if(zamiana_i_test(wejsciowe[k],p)) tab[p]++;
}

for(p=2;p<17;p++)
    ofplik<<p<<"  "<<tab[p]<<endl;


ofplik<<"Zadanie 1.4"<<endl;
int maxx[3]={0},ile[3]={0};

for(int k=0;k<wejsciowe.size();k++)
{
   i=0;
   for(int p=2;p<17;p++)
     if(zamiana_i_test(wejsciowe[k],p)) i++;
   if(i>ile[0])
      { ile[2]=ile[1],ile[1]=ile[0],ile[0]=i;
        maxx[2]=maxx[1],maxx[1]=maxx[0], maxx[0]=wejsciowe[k];
       }
   else
     if(i>ile[1])
        { ile[2]=ile[1],ile[1]=i;
        maxx[2]=maxx[1],maxx[1]=wejsciowe[k];}
     else
         if(i>ile[2])
        { ile[2]=i;
          maxx[2]=wejsciowe[k];}
}

for(i=0;i<3;i++)
{ofplik<<maxx[i]<<" "<<ile[i]<<" ";
 for(int p=2;p<17;p++)
   if(zamiana_i_test(maxx[i],p)) ofplik<<" "<<p;
ofplik<<endl;
}

ofplik.close();
    return 0;
}

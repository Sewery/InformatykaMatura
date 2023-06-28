#include <iostream>
#include <fstream>

using namespace std;


int nowy_palindrom(int liczba, bool symetria)
{int nowy=liczba;
    if (!symetria) liczba/=10;

    while(liczba)
         {nowy=nowy*10+liczba%10;
           liczba/=10;
         }
  return nowy;
}


bool is_palindrome(unsigned n)
{ //cout<<"***"<<n<<"****"<<endl;
    unsigned mask{0};
    //cout<<mask<<endl;
    for(unsigned tmp{n}; tmp; tmp >>= 1)
    {
        mask = (mask << 1) | (tmp & 1);
        //cout<<tmp<<" "<<mask<<endl;
    }
    return mask == n;
}
int main()
{  ofstream plik;
    plik.open("wyniki3_2.txt");
   int suma=0, pal_sym,pal_asym,ile=0;
   for(int n=1;n<1001;n++)
   {
       pal_sym=nowy_palindrom(n,true);
       pal_asym=nowy_palindrom(n,false);
       if (pal_sym%2==1 && is_palindrome(pal_sym))suma+=pal_sym;
       if (pal_asym%2==1 && is_palindrome(pal_asym))suma+=pal_asym;
   }

  plik<<suma<<endl;
  plik.close();
    return 0;
}

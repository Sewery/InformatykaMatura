#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("liczby.txt");
ofstream out("wyniki2_4.txt");

const int N = 250;
int liczby1[N];
int liczby2[N];

void czytaj()
{
    for (int i = 0; i < N; i++)
        in >> liczby1[i] >> liczby2[i];

    in.close();
}

// ile jest podciągów malejących, rosnących  i stałych 
void zadanie()
{
    int ile_ros = 0;
    int ile_mal = 0;

    for (int i = 2; i < N; i++)
    {
        if (liczby1[i-2] < liczby1[i-1] && liczby1[i-1] < liczby1[i])
            ile_ros++;
    }
    
    for (int i = 2; i < N; i++)
    {
        if (liczby1[i-2] > liczby1[i-1] && liczby1[i-1] > liczby1[i])
            ile_mal++;
    }

    out << "Liczba ciągów rosnących: " << ile_ros << endl;
    out << "Liczba ciągów malejacych: " << ile_mal << endl;
}

int main()
{
    czytaj();
    zadanie();
    
    out.close();

    return 0;
}
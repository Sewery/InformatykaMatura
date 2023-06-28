#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("liczby.txt");
ofstream out("wyniki2_3.txt");

const int N = 500;
string litery[N];
int liczby[N];

void czytaj()
{
    for (int i = 0; i < N; i++)
        in >> liczby[i];

    in.close();
}

bool czy_zero(int liczba)
{
    int temp = abs(liczba);
    while(temp > 0)
    {
        if (temp % 10 == 0)
            return false;
        temp /= 10;
    }
    return true;
}

// Suma liczb ujemnych i dodatnich, które nie zawierają w cyfry zero
void zadanie()
{
    long long suma_dodatnia = 0;
    long long suma_ujemna = 0;
    for (int i = 0; i < N; i++)
    {
        if (czy_zero(liczby[i]))
            if (liczby[i] < 0)
                suma_ujemna += liczby[i];
            if (liczby[i] > 0)
                suma_dodatnia += liczby[i];
    }

    out << "Suma liczb ujemnych: " << suma_ujemna << endl;
    out << "Suma liczb dodatnich: " << suma_dodatnia << endl;
    out << endl;
}

int main()
{
    czytaj();
    zadanie();
    out.close();

    return 0;
}
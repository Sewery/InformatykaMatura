#include <iostream>
#include <string>

using namespace std;

string zamiana(double liczba)
{
    string tekst = "0.";
    double k = 1;
    double temp = liczba;
    while (liczba != 0)
    {
        k *= 2;
        temp = liczba - 1.0 / k;
        if (temp >= 0)
        {
            liczba -= 1.0 / k;
            tekst += "1";
            temp = liczba;
        }
        else
            tekst += "0";
    }
    return tekst;
}


string zamiana2(double liczba)
{
    string tekst = "0.";
    double k = 1;
    int n = 15;
    double temp = liczba;
    while (liczba != 0 && n!=0)
    {
        k *= 2;
        temp = liczba - 1.0 / k;
        if (temp >= 0)
        {
            liczba -= 1.0 / k;
            tekst += "1";
            temp = liczba;
        }
        else
            tekst += "0";
        n--;
    }
    return tekst;
}

int main()
{
    cout << zamiana(0.4375) << endl;    
    cout << zamiana(0.75) << endl;
    cout << zamiana(0.625) << endl;
    cout << zamiana(0.65625) << endl;
    cout << zamiana(0.421875) << endl;
    cout << zamiana2(0.4375) << endl;
    cout << zamiana2(0.8) << endl;
    cout << zamiana(0.7) << endl;
    cout << zamiana2(0.7) << endl;

    return 0;
}
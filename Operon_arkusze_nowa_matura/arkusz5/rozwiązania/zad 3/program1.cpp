#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ifstream in("zwierzeta.txt");

const int N = 50;

struct zwierze
{
    string nazwa;
    short cechy[5];
};

zwierze zw[N];
vector<pair<double, string> > zwp(N);

void czytaj()
{
    for (int i = 0; i < N; i++)
    {
        in >> zw[i].nazwa;
        for (int j = 0; j < 5; j++)
        {
            in >> zw[i].cechy[j];
        }
    }

    in.close();
}

void zadanie1()
{
    cout << "3.1:\n";

    double minn = 1e+10;
    zwierze nz = {"nieznane zwierze", 1,3,2,2,3};

    for (int i = 0; i < N; i++)
    {
        double P = 0;
        for (int j = 0; j < 5; j++)
            P += pow(zw[i].cechy[j] - nz.cechy[j], 2.0);
        double podobne = sqrt(P);
        cout.precision(2);
        cout << fixed << zw[i].nazwa << " " << podobne << endl;
    }
}

int main()
{
    czytaj();
    zadanie1();

    return 0;
}
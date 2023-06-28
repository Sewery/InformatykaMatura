#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ifstream in("zwierzeta.txt");
ofstream out("wyniki3.txt");

const int N = 50;

struct zwierze
{
    string nazwa;
    short cechy[5];
};

zwierze zw[N];

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
vector<pair<double, string> > zwp;

void zadanie2()
{
    out << "3.2:\n";

    zwierze nz = {"nieznane zwierze", 1,3,2,2,3};

    double minn = 1e+10;
    for (int i = 0; i < N; i++)
    {
        double P = 0;
        for (int j = 0; j < 5; j++)
            P += pow(zw[i].cechy[j] - nz.cechy[j], 2.0);
        double podobne = sqrt(P);
        minn = min(minn, podobne);
        zwp.push_back(make_pair(podobne, zw[i].nazwa));
    }

    sort(zwp.begin(), zwp.end());
    out << "Podobne zwierze:\n";
    for (int i = 0; i < zwp.size(); i++)
    {
        if (zwp[i].first == minn)
            out << zwp[i].second << endl;
    }
    
    out << endl;
}

void zadanie3()
{
    out << "3.3:\n";

    multimap<string, string> rodzina_zw;
    for (int i = 0; i < N; i++)
    {
        string cechy = "";
        for (int j = 0; j < 5; j++)
            cechy += char(zw[i].cechy[j] + '0');
        rodzina_zw.insert(make_pair(cechy, zw[i].nazwa));
    }

    map<string, int> ile_w_rodzinie;
    for (auto el: rodzina_zw)
        ile_w_rodzinie[el.first]++;
    
    for (auto el: ile_w_rodzinie)
    {
        if (el.second > 1)
        {
            for (auto rz: rodzina_zw)
                if (el.first == rz.first)
                    out << rz.second << " ";
            out << endl;
        }
    }

}
    

int main()
{
    czytaj();
    zadanie2();
    zadanie3();

    return 0;
}
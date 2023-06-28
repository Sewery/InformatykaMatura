#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream in("liczby.txt");
ofstream out("wyniki2_5.txt");

const int N = 250;

int main()
{
    vector<pair<int, int> > nowe_przedzialy;
    vector<pair<int, int> > przedzialy(N);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        in >> a >> b;
        przedzialy[i] = make_pair(a, b);
    }
    sort(przedzialy.begin(), przedzialy.end());

    nowe_przedzialy.push_back(przedzialy[0]);
    int k = 0;
    for (int i = 1; i < N; i++)
    {
        int a, b;
        a = przedzialy[i].first;
        b = przedzialy[i].second;
        if (a >= nowe_przedzialy[k].first && a <= nowe_przedzialy[k].second 
            && b >= nowe_przedzialy[k].first && b <= nowe_przedzialy[k].second)
            continue;
        else if (a >= nowe_przedzialy[k].first && a <= nowe_przedzialy[k].second 
            && b >= nowe_przedzialy[k].second)
            nowe_przedzialy[k].second = b;
        else if (a <= nowe_przedzialy[k].first && b >= nowe_przedzialy[k].first 
            && b <= nowe_przedzialy[k].second)
            nowe_przedzialy[k].second = b;
        else if (a <= nowe_przedzialy[k].first && b >= nowe_przedzialy[k].second)
        {
            nowe_przedzialy[k].first = a;
            nowe_przedzialy[k].second = b;
        }
        else
        {
            nowe_przedzialy.push_back(make_pair(a, b));
            k++;
        } 
    }
    for (auto el: nowe_przedzialy)
        out << el.first << " " << el.second << endl;
    out << endl;

    return 0;
}
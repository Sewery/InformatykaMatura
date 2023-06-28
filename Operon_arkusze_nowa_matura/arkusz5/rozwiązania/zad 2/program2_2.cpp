#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int> > przedzialy(N);
    vector<pair<int, int> > nowe_przedzialy;
    
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
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
        if (a == nowe_przedzialy[k].second)
            nowe_przedzialy[k].second = b;
        else
        {
            nowe_przedzialy.push_back(make_pair(a, b));
            k++;
        } 
    }
    for (auto el: nowe_przedzialy)
        cout << el.first << " " << el.second << endl;
    
    return 0;
}

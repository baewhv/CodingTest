#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

struct Temp
{
    Temp(int pos) : pos(pos) { route.insert(pos); }
    int pos;
    unordered_set<int> route;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> link(n);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        link[l].push_back(r);
        link[r].push_back(l);
    }
    for (int i = 0; i < n; i++)
    {
        Temp here(i);
        stack<Temp> s;
        s.push(here);

        while (true)
        {
            if (s.empty()) break;

            here = s.top();
            s.pop();
            if (here.route.size() == 5)
            {
                cout << 1;
                return 0;
            }
            for (auto thereN :link[here.pos])
            {
                if (here.pos == thereN) continue;
                if (here.route.find(thereN) != here.route.end()) continue;
                Temp there = here;
                there.pos = thereN;
                there.route.insert(thereN);
                s.push(there);
            }
        }
    }
    cout << 0;
    return 0;
}
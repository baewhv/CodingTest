#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos
{
    Pos(int pos) : pos(pos) {}
    int pos = -1;
    int time = 0;
};

int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
    {
        cout << a - b;
        return 0;
    }
    queue<Pos> q;
    vector<int> best(b + 2, -1);
    Pos here(a);
    q.push(here);
    best[here.pos] = 0;
    while (true)
    {
        if (q.empty())break;
        here = q.front();
        q.pop();
        if (here.pos + 1 <= b && (best[here.pos + 1] == -1 || best[here.pos + 1] > here.time + 1))
        {
            Pos there = here;
            there.pos++;
            there.time++;
            best[there.pos] = there.time;
            q.push(there);
        }
        if (here.pos - 1 > 0 && (best[here.pos - 1] == -1 || best[here.pos - 1] > here.time + 1))
        {
            Pos there = here;
            there.pos--;
            there.time++;
            best[there.pos] = there.time;
            q.push(there);
        }
        if (here.pos * 2 <= b + 1 && (best[here.pos * 2] == -1 || best[here.pos * 2] > here.time + 1))
        {
            Pos there = here;
            there.pos *= 2;
            there.time++;
            best[there.pos] = there.time;
            q.push(there);
        }
    }
    cout << best[b];
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Pos
{
    Pos(int p) : pos(p) {}
    int pos = 0;
    int time = 0;
    bool operator<(const Pos& other) const
    {
        return time > other.time;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> best(100002, -1);
    if (n > k)
    {
        cout << n - k;
        return 0;
    }
    priority_queue<Pos> q;
    Pos here(n);
    q.push(n);
    while (true)
    {
        if (q.empty()) break;
        if (q.top().pos == k)
        {
            cout << q.top().time;
            return 0;
        }
        here = q.top();
        q.pop();
        if(here.pos -1 >= 0 && (best[here.pos-1] == -1 || best[here.pos-1] > here.time+1))
        {
            Pos there = here;
            there.pos--;
            there.time++;
            best[there.pos] = there.time;
            q.push(there);
        }
        if (here.pos + 1 <= 100000 && (best[here.pos + 1] == -1 || best[here.pos + 1] > here.time + 1))
        {
            Pos there = here;
            there.pos++;
            there.time++;
            best[there.pos] = there.time;
            q.push(there);
        }
        if (here.pos != 0 && here.pos * 2 <= k + 1 && (best[here.pos * 2] == -1 || best[here.pos * 2] > here.time))
        {
            Pos there = here;
            there.pos *= 2;
            best[there.pos] = there.time;
            q.push(there);
        }
    }
    return 0;
}
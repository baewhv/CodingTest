#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Pos
{
    Pos(int x, int y, int broken = 0) : x(x), y(y), broken(broken) {}
    int x = 0;
    int y = 0;
    int broken = 0;
    bool operator<(const Pos& other) const
    {
        return broken > other.broken;
    }
    Pos operator+(const Pos& other) const
    {
        return Pos(x + other.x, y + other.y, broken);
    }
};

int main()
{
    int x, y;
    cin >> x >> y;
    vector<string> map(y);
    vector<vector<int>> best(y, vector<int>(x, -1));
    Pos dir[4] = { Pos(0, 1), Pos(1, 0), Pos(0, -1), Pos(-1, 0) };
    for (int i = 0; i < y; i++)
    {
        cin >> map[i];
    }

    Pos here(0, 0);
    priority_queue<Pos> q;
    q.push(here);
    while (true)
    {
        if (q.empty()) break;
        if (q.top().x == x - 1 && q.top().y == y - 1)
        {
            cout << q.top().broken;
            return 0;
        }
        here = q.top();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Pos there = here + dir[i];
            if (there.x < 0 || there.x >= x || there.y < 0 || there.y >= y) continue;
            there.broken += map[there.y][there.x] == '1' ? 1 : 0;
            if (best[there.y][there.x] != -1 && best[there.y][there.x] <= there.broken)continue;
            best[there.y][there.x] = there.broken;
            q.push(there);
        }
    }


    return 0;
}
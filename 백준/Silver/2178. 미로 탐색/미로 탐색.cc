#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Pos
{
    Pos(int x, int y) :x(x), y(y) {}
    int x;
    int y;

    Pos operator+(Pos other)
    {
        return Pos(x + other.x, y + other.y);
    }
    bool operator==(Pos other)
    {
        return (x == other.x) && (y == other.y);
    }
};

int main()
{
    int y, x;
    cin >> y >> x;
    vector<string> map(y);
    vector<vector<Pos>> parent(y, vector<Pos>(x, Pos(-1, -1)));
    for (int i = 0; i < y; i++)
    {
        cin >> map[i];
    }
    Pos dir[4] = {
        Pos(0,1),
        Pos(0,-1),
        Pos(1,0),
        Pos(-1,0)
    };
    queue<Pos> q;
    Pos here(0, 0);
    q.push(here);
    parent[0][0] = here;
    while (true)
    {
        if (q.empty())break;
        here = q.front();
        q.pop();
        if (here == Pos(x - 1, y - 1)) break;
        for (int i = 0; i < 4; i++)
        {
            Pos there = here + dir[i];
            if (there.x < 0 || there.x >= x || there.y < 0 || there.y >= y) continue;
            if (map[there.y][there.x] == '0') continue;
            if (parent[there.y][there.x] == Pos(-1, -1))
            {
                parent[there.y][there.x] = here;
                q.push(there);
            }
        }
    }
    int temp = 1;
    while (true)
    {
        if (parent[here.y][here.x] == here) break;
        here = parent[here.y][here.x];
        temp++;
    }
    cout << temp;
    return 0;
}
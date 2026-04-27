#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


struct Pos
{
    Pos(int x, int y) : x(x), y(y) {}
    int x = -1;
    int y = -1;
    Pos operator+(Pos other)
    {
        Pos temp(x, y);
        temp.x += other.x;
        temp.y += other.y;
        return temp;
    }
};

void BFS(Pos here, vector<int>& count, vector<string>& apt, vector<vector<bool>>& visit)
{
    Pos route[4]
    {
        Pos(1,0),
        Pos(0,1),
        Pos(-1,0),
        Pos(0,-1)
    };
    queue<Pos> q;
    q.push(here);
    visit[here.y][here.x] = true;
    count[count.size() - 1]++;
    while (true)
    {
        if (q.empty()) break;
        here = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Pos there = here + route[i];
            if (there.x < 0 || there.x >= apt.size() || there.y < 0 || there.y >= apt.size() || apt[there.y][there.x] == '0' || visit[there.y][there.x]) continue;
            count[count.size() - 1]++;
            visit[there.y][there.x] = true;
            q.push(there);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> apt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> apt[i];
    }
    vector<vector<bool>> visit(n, vector<bool>(n, false));
    vector<int> count;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (visit[y][x] || apt[y][x] == '0') continue;
            count.push_back(0);
            BFS(Pos(x, y), count, apt, visit);
        }
    }
    sort(count.begin(), count.end());
    cout << count.size() << '\n';
    for (int c : count)
    {
        cout << c << '\n';
    }
    return 0;
}


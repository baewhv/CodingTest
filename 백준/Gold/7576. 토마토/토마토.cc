#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Tom
{
    Tom(int x, int y, int g = 0) : x(x), y(y), g(g){}
    int x = -1;
    int y = -1;
    int g = 0;
    bool operator<(const Tom other) const
    {
        return g > other.g;
    }
    Tom operator+(Tom other)
    {
        return Tom(x + other.x, y + other.y);
    }
};

int main()
{
    int m, n, count = 0, maxNum = 0, wall = 0;
    cin >> m >> n;
    vector<vector<int>> field(n, vector<int>(m));
    priority_queue<Tom> pq;
    Tom dir[4] = {
        Tom(1, 0),
        Tom(-1, 0),
        Tom(0, 1),
        Tom(0, -1)
    };
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> field[y][x];
            if (field[y][x] == 1)
            {
                pq.push(Tom(x, y, 1));
                count++;
            }
            else if (field[y][x] == -1) wall++;
        }
    }


    while (true)
    {
        if (pq.empty()) break;
        Tom here = pq.top();
        pq.pop();
        maxNum = max(maxNum, here.g);
        for (int i = 0; i < 4; i++)
        {
            Tom there = here + dir[i];
            if (there.x < 0 || there.x >= m || there.y < 0 || there.y >= n) continue;
            if (field[there.y][there.x] != 0) continue;
            field[there.y][there.x] = field[here.y][here.x] + 1;
            count++;
            there.g = field[there.y][there.x];
            pq.push(there);
        }
    }

    cout << (m * n - wall == count ? maxNum-1 : -1);

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Knight
{
    Knight(int x, int y) : x(x), y(y) {}
    int x = -1;
    int y = -1;
    int g = 0;
    float f = 0;
    bool operator<(const Knight other) const
    {
        return f > other.f;
    }
    bool operator==(const vector<int> other) const
    {
        return (x == other[0]) && (y == other[1]);
    }
    Knight operator+(int arr[])
    {
        return Knight(x + arr[0], y + arr[1]);
    }
};
float length(float x, float y)
{
    return sqrt((x * x) + (y * y));
}

int Func(int tile, vector<int>& start, vector<int>& end)
{
    vector<vector<int>> tiles(tile, vector<int>(tile, -1));
    Knight here(start[0], start[1]);
    priority_queue<Knight> pq;
    here.f = length(end[0] - here.x, end[1] - here.y);
    pq.push(here);
    tiles[here.x][here.y] = 0;

    int dir[8][2] = { {1,2},{2,1},{-1,2},{-2,1},{-1,-2},{-2,-1},{1,-2},{2,-1} };
    while (true)
    {
        if (pq.empty() || pq.top() == end) break;
        here = pq.top();
        pq.pop();
        for (int i = 0; i < 8; i++)
        {
            Knight there = here + dir[i];
            if (there.x < 0 || there.x >= tile || there.y < 0 || there.y >= tile) continue;
            if (tiles[there.x][there.y] != -1 && tiles[there.x][there.y] < here.g + 1) continue;
            there.g = here.g + 1;
            there.f = length(end[0] - there.x, end[1] - there.y) + there.g;
            tiles[there.x][there.y] = there.g; 
            pq.push(there);
        }
    }
    return tiles[end[0]][end[1]];
}

using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tile;
        vector<int> startPos(2);
        vector<int> endPos(2);
        cin >> tile >> startPos[0] >> startPos[1] >> endPos[0] >> endPos[1];

        cout << Func(tile, startPos, endPos) << '\n';
    }
    return 0;
}
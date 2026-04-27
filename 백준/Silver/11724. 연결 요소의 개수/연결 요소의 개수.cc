#include <iostream>
#include <queue>

using namespace std;

void BFS(int here,vector<bool>& visit,vector<vector<bool>>& map)
{
    queue<int> q;
    q.push(here);
    visit[here] = true;
    while(true)
    {
        if(q.empty()) break;
        here = q.front();
        q.pop();
        for(int there = 0; there < visit.size(); there++)
        {
            if(there != here && !visit[there] &&map[here][there])
            {
                q.push(there);
                visit[there] = true;
            }
                
        }
    }
}

int main()
{
    int n, m, answer = 0;
    cin >> n >> m;
    vector<vector<bool>> map(n, vector<bool>(n, false));
    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        map[l-1][r-1] = true;
        map[r-1][l-1] = true;
    }
    vector<bool> visit(n, false);
    for(int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            BFS(i, visit, map);
            answer++;
        }
    }
    cout << answer;
    return 0;
}
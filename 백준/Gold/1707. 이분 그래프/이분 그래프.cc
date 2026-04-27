#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int pos = -1;
    int color = -1;
    vector<int> connect;
};

int main()
{
    int k, edge, vertex, u, v;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> vertex >> edge;
        vector<Node> nodes(vertex + 1);
        for (int i = 1; i <= vertex; i++) nodes[i].pos = i + 1;
        for (int j = 0; j < edge; j++)
        {
            cin >> u >> v;
            nodes[u].connect.push_back(v);
            nodes[v].connect.push_back(u);
        }
        bool abort = false;
        for (int i = 1; i <= vertex; i++)
        {
            if (abort) break;
            if (nodes[i].color != -1) continue;
            int here = i;
            queue<int> q;
            nodes[here].color = 0;
            q.push(here);
            while (true)
            {
                if (abort || q.empty()) break;
                here = q.front();
                q.pop();
                for (int there = 0; there < nodes[here].connect.size(); there++)
                {
                    if (nodes[here].color == nodes[nodes[here].connect[there]].color)
                    {
                        abort = true;
                        break;
                    }
                    if (nodes[nodes[here].connect[there]].color != -1) continue;
                    nodes[nodes[here].connect[there]].color = nodes[here].color == 1 ? 0 : 1;
                    q.push(nodes[here].connect[there]);
                }
            }
        }

        if (abort) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }

    return 0;
}
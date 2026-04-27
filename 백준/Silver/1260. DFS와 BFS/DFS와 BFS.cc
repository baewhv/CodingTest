#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void DFS(int here, vector<int>& route, vector<vector<bool>>& map, vector<bool>& visit)
{
	route.push_back(here);
	visit[here] = true;
	for (int there = 0; there < visit.size(); there++)
	{
		if (!visit[there] && map[here][there])
		{
			DFS(there, route, map, visit);
		}
	}

}

int main()
{
	int n, m, here;
	cin >> n >> m >> here;
	vector<vector<bool>> map(n + 1, vector<bool>(n + 1, 0));
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		map[l][r] = true;
		map[r][l] = true;
	}
	vector<int> sRoute;
	vector<bool> sVisit(n + 1, false);
	//sVisit[sHere] = true;
	DFS(here, sRoute, map, sVisit);

	for (int i = 0; i < sRoute.size(); i++)
	{
		cout << sRoute[i];
		if (i != sRoute.size() - 1) cout << ' ';
	}
	cout << '\n';


	queue<int> q;
	vector<bool> qVisit(n + 1, false);
	vector<int> qRoute;
	q.push(here);
	qVisit[here] = true;

	while (true)
	{
		if (q.empty()) break;
		here = q.front();
		qRoute.push_back(here);
		q.pop();
		for (int there = 0; there < n + 1; there++)
		{
			if (!qVisit[there] && map[here][there])
			{
				qVisit[there] = true;
				q.push(there);
			}
		}
	}


	
	for (int i = 0; i < qRoute.size(); i++)
	{
		cout << qRoute[i];
		if (i != qRoute.size() - 1) cout << ' ';
	}


	return 0;
}
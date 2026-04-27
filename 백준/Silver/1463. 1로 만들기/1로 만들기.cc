#include <iostream>
#include <queue>

using namespace std;

struct N
{
	N(int n, int b) :n(n), best(b){}
	~N() {}
	int n;
	int best;
};


int main()
{
	int n;
	cin >> n;
	queue<N> q;
	N here(n, 0);
	q.push(here);

	while (true)
	{
		if (q.empty()) break;
		if (q.front().n == 1)
		{
			cout << q.front().best;
			return 0;
		}
		here = q.front();
		q.pop();

		if (here.n % 3 == 0)
			q.push(N(here.n / 3, here.best + 1));
		if (here.n % 2 == 0)
			q.push(N(here.n / 2, here.best + 1));
		q.push(N(here.n - 1, here.best + 1));
	}

	return 0;
}
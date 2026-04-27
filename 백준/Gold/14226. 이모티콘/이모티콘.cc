#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Chat
{
	Chat(int E) : E(E) {}
	Chat(int E, int C, int cnt) : E(E), C(C), cnt(cnt) {}
	int E = 0;
	int C = 0;
	int cnt = 0;
};

int main()
{
    int n;
    cin >> n;

    vector<int> best(n*2, 100000);

    queue<Chat> q;
    Chat here(1);
    q.push(here);
    while (true)
    {
        if (q.front().E == n)
        {
            cout << q.front().cnt;
            return 0;
        }
        if (q.empty()) break;
        here = q.front();
        q.pop();
        if (here.C != here.E) 
        {
            q.push(Chat(here.E, here.E, here.cnt + 1));
        }
        if (here.C != 0 && here.E + here.C < n * 2)
        {
            best[here.E + here.C] = here.cnt + 1;
            q.push(Chat(here.E + here.C, here.C, here.cnt + 1));
        }
        if (here.E - 1 != 0 && best[here.E - 1] > here.cnt + 1)
        {
            best[here.E - 1] = here.cnt + 1;
            q.push(Chat(here.E - 1, here.C, here.cnt + 1));
        }
    }

    return 0;
}
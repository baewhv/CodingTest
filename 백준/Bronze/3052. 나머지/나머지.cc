#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int temp;
    unordered_set<int> s;
    for(int i = 0; i < 10; i++)
    {
        cin >> temp;
        s.insert(temp%42);
    }
    cout << s.size();
    return 0;
}
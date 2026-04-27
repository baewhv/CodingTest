#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        unordered_set<char> s;

        for (int j = 0; j < temp.length(); j++)
        {
            if (j == 0)
            {
                s.insert(temp[j]);
            }
            else if (temp[j] == temp[j - 1]) continue;
            else if (temp[j] != temp[j - 1] && s.find(temp[j]) == s.end())
            {
                s.insert(temp[j]);
            }
            else
            {
                cnt--;
                break;
            }
        }
    }
    cout << cnt;

    return 0;
}
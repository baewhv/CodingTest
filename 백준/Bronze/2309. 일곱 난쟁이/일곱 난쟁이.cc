#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void func(int total, vector<int>& dwarf)
{
    for (int i = 0; i < 8; i++)
    {
        int temp = total - dwarf[i];
        for (int j = 1; j < 9; j++)
        {
            if (temp - dwarf[j] == 100)
            {
                dwarf.erase(dwarf.begin() + j);
                dwarf.erase(dwarf.begin() + i);
                return;
            }
        }
    }
}
int main()
{
    vector<int> dwarf;
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        int temp;
        cin >> temp;
        dwarf.push_back(temp);
        total += temp;
    }
    func(total, dwarf);
    sort(dwarf.begin(), dwarf.end());
    for (auto d : dwarf)
    {
        cout << d << '\n';
    }
    return 0;
}
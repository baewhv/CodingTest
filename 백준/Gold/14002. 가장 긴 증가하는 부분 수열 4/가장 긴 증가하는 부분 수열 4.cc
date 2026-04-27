#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void func(int l, int r, int target, int target_pos, vector<int>& num, vector<int>& rank)
{
    if (l == r)
    {
        if (target < num[l])
        {
            num[l] = target;
        }
        else if (target > num[l])
        {
            num.push_back(target);
            l++;
        }
        rank[target_pos] = l;
        return;
    }
    int mid = ((r - l) / 2) + l;
    if (target > num[mid])
        func(mid + 1, r, target, target_pos, num, rank);
    else if (target < num[mid])
        func(l, mid, target, target_pos, num, rank);
    else
        rank[target_pos] = mid;
}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> rank(n);
    vector<int> num;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
        if (num.empty()) num.push_back(temp);
        else func(0, num.size() - 1, temp, i, num, rank);
    }
    temp = num.size() - 1;
    cout << num.size() << '\n';
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (temp < 0) break;
        if (temp == rank[i])
        {
            num[temp] = arr[i];
            temp--;
        }
    }
    
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << ' ';
    }

    return 0;
}
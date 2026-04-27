#include <iostream>
#include <vector>
using namespace std;

void Input(int l, int r, int value, vector<int>& arr)
{
    if (l == r)
    {
        if (arr[l] > value)
        {
            if (l == 0)arr[0] = value;
            else arr[l] = value;
        }
        else if(arr[l] < value)
        {
            if (l == arr.size() - 1) arr.push_back(value);
            else arr[l + 1] = value;
        }
        return;
    }
    int mid = (r - l) / 2 + l;
    if (arr[mid] < value)
        Input(mid+1, r, value, arr);
    else if (arr[mid] > value)
        Input(l, mid, value, arr);
    else return;
}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (arr.empty())
        {
            arr.push_back(temp);
            continue;
        }
        else Input(0, arr.size() - 1, temp, arr);
    }
    cout << arr.size();

    return 0;
}
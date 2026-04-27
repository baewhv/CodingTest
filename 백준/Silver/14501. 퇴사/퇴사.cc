#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Date
{
    int time = 0;
    int pay = 0;
};

int func(int n, vector<Date>& arr, unordered_map<int, int>& map)
{
    if(n == arr.size() || n+arr[n].time > arr.size()) return 0;
    if(map.find(n) != map.end()) return map[n];
    map[n] = arr[n].pay;
    for(int i = n+arr[n].time; i < arr.size(); i++)
    {
        map[n] = max(map[n], arr[n].pay + func(i, arr, map));
    }
    return map[n];
}

int main()
{
    int n, maxNum = 0;
    cin >> n;
    unordered_map<int, int> map;
    vector<Date> arr;
    for(int i = 0; i < n; i++)
    {
        Date temp;
        cin >> temp.time >> temp.pay;
        arr.push_back(temp);
    }
    
    for(int i = 0; i < n; i++)
    {
        maxNum = max(maxNum, func(i,arr, map));
    }
    cout << maxNum;
    return 0;
}
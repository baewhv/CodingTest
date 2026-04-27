#include <iostream>
#include <vector>

using namespace std;
long long func(int n, int prev, vector<long long>& arr1, vector<long long>& arr0)
{
    if (n == 1) return 1;
    long long temp = 0;
    if (arr0[n] == 0) arr0[n] = func(n - 1, 0, arr1, arr0);
    temp += arr0[n];
    
    if (prev != 1)
    {
        if (arr1[n] == 0) arr1[n] = func(n - 1, 1, arr1, arr0);
        temp += arr1[n];
    }
    return temp;
}

int main()
{
    int n;
    vector<long long> arr1(91, 0);
    vector<long long> arr0(91, 0);
    cin >> n;
    cout << func(n, 1, arr1, arr0) << endl;

    return 0;
}
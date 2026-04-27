#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, temp;
    cin >> n;
    vector<int> num;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    
    cout << num[0] * num[num.size()-1];
    
    
    return 0;
}
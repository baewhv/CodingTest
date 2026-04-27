#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, left, right;
    cin >> n >> m;
    vector<int> basket(n);
    for(int i = 0; i < n; i++)
    {
        basket[i] = i+1;
    }
    
    for(int i = 0; i < m; i++)
    {
        cin>>left >> right;
        swap(basket[left-1], basket[right-1]);
    }
    
    for(int i = 0; i < n; i++)
    {
        cout << basket[i] << ' ';
    }
    
    
    return 0;
}
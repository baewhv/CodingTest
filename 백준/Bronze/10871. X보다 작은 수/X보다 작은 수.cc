#include <iostream>

using namespace std;

int main()
{
    int n, findNum , temp;
    cin >>n >> findNum;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(findNum > temp)
            cout << temp << ' ';
    }
    
}
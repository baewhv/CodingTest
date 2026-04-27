#include <iostream>

using namespace std;

int main()
{
    bool check[31] = {false};
    for(int i = 0; i < 28; i++)
    {
        int temp;
        cin >> temp;
        check[temp] = true;
    }
    
    for(int i = 1; i <= 30; i++)
    {
        if(!check[i])
        {
            cout << i;
            if(!check[0]) 
            {
                cout << '\n';
                check[0] = true;
            }
        }
        
    }
    return 0;
}
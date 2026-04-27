#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, count = 0;
    vector<vector<bool>> black(101, vector<bool>(101, false));
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                if(!black[y+j][k+x])
                {
                    black[y+j][k+x] = true;
                    count++;
                }
            }
        }
    }
    cout << count;
    
    
    return 0;
}
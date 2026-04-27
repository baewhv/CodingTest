#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> arr(col, vector<int>(row, 0));
    for(int n = 0; n < 2; n++)
    {
        for(int i = 0; i < col; i++)
        {
            for(int j = 0; j < row; j++)
            {
                if(n != 1) cin >> arr[i][j];
                else
                {
                    int temp;
                    cin >> temp;
                    cout << arr[i][j] + temp;
                    if(j != row -1) cout << ' ';
                }
            }
            if(n == 1) cout <<'\n';
        }
    }
    
    return 0;
    
}
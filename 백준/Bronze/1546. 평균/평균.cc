#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    float high = 0, avr = 0;
    cin >> n;
    vector<float> score(n);
    for(int i = 0; i < n; i++)
    {
        cin >> score[i];
        high = max(high, score[i]);
    }
    
    for(auto& s : score)
    {
        avr += (s / high) * 100;
    }
    cout << avr/n;
    
    
    
    return 0;
}
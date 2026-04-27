#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string temp;
    cin >> temp;
    vector<string> croa = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
    int cnt = 0;
    for (int i = 0; i < croa.size(); i)
    {
        auto found = temp.find(croa[i]);
        if (found != string::npos)
        {
            temp.replace(found, croa[i].length(), "_");
            cnt++;
        }
        else i++;
    }
    for (auto t : temp)
    {
        if (t != '_')
            cnt++;
    }
    
    cout << cnt;
    return 0;
}
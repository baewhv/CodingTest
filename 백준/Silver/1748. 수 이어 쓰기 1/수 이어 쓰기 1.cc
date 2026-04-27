#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int temp = (stoi(s) - pow(10, s.length() - 1) + 1) * s.length();
    for (int i = 1; i < s.length(); i++)
    {
        temp += ((pow(10, s.length() - i) - 1) - pow(10, s.length() - (i + 1)) + 1) * (s.length()-i);
    }
    cout << temp;

    return 0;
}
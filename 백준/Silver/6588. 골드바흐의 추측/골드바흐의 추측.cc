#include <iostream>
#include <vector>

using namespace std;

bool CheckPrime(int n, vector<int>& prime)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            prime[n] = 0;
            return false;
        }
    }
    prime[n] = 1;
    return true;
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> prime(1000001, -1);
    int temp;
    while (true)
    {
        cin >> temp;
        if (temp == 0) break;
        bool done = false;

        for (int i = 3; i < temp; i += 2)
        {
            if (prime[i] == 0) continue;
            if (prime[i] == 1 || CheckPrime(i, prime))
            {
                if (prime[temp - i] == 0) continue;
                if (prime[temp - i] == 1 || CheckPrime(temp - i, prime))
                {
                    cout << temp << " = " << i << " + " << temp - i << '\n';
                    done = true;
                    break;
                }
            }
        }
        if (!done)
            cout << "Goldbach's conjecture is wrong." << '\n';
    }


    return 0;
}
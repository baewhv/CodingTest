#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<long long> nums(1000001, 0);
	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 1; j * i < nums.size(); j++)
		{
			nums[i * j] += i;
		}
		nums[i] += nums[i - 1];
	}
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		cout << nums[m] << '\n';
	}

	return 0;
}
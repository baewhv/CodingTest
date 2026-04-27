#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int width, height, ans = 50 * 50;
	cin >> height >> width;
	vector<string> board(height);
	for (int i = 0; i < height; i++)
	{
		cin >> board[i];
	}
	for (int i = 0; i <= height - 8; i++)
	{
		for (int j = 0; j <= width - 8; j++)
		{
			int black = 0, white = 0;
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					int num = (k - i) * 8 + (l - j) + ((k - i) % 2 == 0 ? 0 : 1);
					if (num % 2 == 0) //짝수번째 //검정보드는 짝수에 검정 찍어야함 // 흰색보드는 짝수에 흰색 찍어야함.
					{
						if (board[k][l] == 'B') //
						{
							white++;
						}
						else
						{
							black++;
						}
					}
					else
					{
						if (board[k][l] == 'W') //검정 보드는 홀수에 흰색 찍어야함 // 흰색보드는 홀수에 검정 찍어야함.
						{
							white++;
						}
						else
						{
							black++;
						}
					}
				}
			}
			ans = min(ans, min(black, white));
		}
	}

	cout << ans << endl;
	return 0;
}
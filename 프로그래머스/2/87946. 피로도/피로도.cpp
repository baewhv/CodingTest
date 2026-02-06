#include <string>
#include <vector>
#include <queue>

using namespace std;

int Enter(int num, int k, vector<vector<int>>& d, vector<bool> visit)
{
    int total = 0;
    visit[num] = true;
    k -= d[num][1];
    for(int i = 0; i < d.size(); i++)
    {
        if(i == num || visit[i]) continue;
        if(k < d[i][0]) continue;
        
        total = max(total, Enter(i, k, d, visit));
    }
    return total + 1;
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visit(dungeons.size(), false);
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(k < dungeons[i][0]) continue;
        answer = max(answer, Enter(i, k, dungeons, visit));
    }
    
    return answer;
}
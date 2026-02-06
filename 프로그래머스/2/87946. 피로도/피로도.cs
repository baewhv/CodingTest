using System;

public class Solution {
    public int solution(int k, int[,] dungeons) {
        bool[] visit = new bool[dungeons.GetLength(0)];
        return FindDungeon(k, dungeons, 0, visit);
    }
    public int FindDungeon(int k, int[,] dungeons, int count, bool[] visit)
    {
        if(count >= dungeons.GetLength(0)) return count;
        int answer = count;
        for(int i = 0; i < dungeons.GetLength(0); i++)
        {
            if(visit[i]) continue;
            if(k - dungeons[i,0] < 0) continue;
            bool[] newVisit = new bool[dungeons.GetLength(0)];
            Array.Copy(visit, newVisit, dungeons.GetLength(0));
            newVisit[i] = true;
            int temp = FindDungeon(k-dungeons[i,1], dungeons, count + 1, newVisit);
            answer = answer > temp ? answer : temp;
        }
        return answer;
        
    }
}
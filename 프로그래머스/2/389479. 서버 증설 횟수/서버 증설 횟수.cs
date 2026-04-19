using System;

public class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        int[] servers = new int[1000];
        for(int i = 0; i < players.Length; i++)
        {
            int cap = GetServerCap(servers, i, m, k);
            if(cap <= players[i])
            {
                int addServer = (players[i]-cap) / m + 1;
                servers[i] = addServer;
                answer += addServer;
            }
        }
        return answer;
    }
    private int GetServerCap(int[] servers, int index, int m,int k)
    {
        int cap = m;
        for(int j = 1;j < k; j++)
        {
            if(index-j < 0) return cap;
            cap += servers[index-j] * m;
        }
        return cap;
    }
}
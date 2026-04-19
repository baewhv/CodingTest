using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] keymap, string[] targets) {
        
        int[] answer = new int[targets.Length];
        for(int i = 0;i < targets.Length; i++)
        {
            for(int j = 0; j < targets[i].Length; j++)
            {
                int result = BFS(keymap, targets[i][j]);
                if(result == -1) 
                {
                    answer[i] = -1;
                    break;
                }
                else
                    answer[i] += result;
                    
            }
        }
        return answer;
    }
    
    private int BFS(string[] keymap, char target)
    {
        Queue<(int col, int row)> q = new Queue<(int, int)>();
        (int col, int row) here = (0, 0);
        for(int i = 0; i < keymap.Length; i++)
        {
            q.Enqueue((i, 0));
        }
        while(true)
        {
            if(q.Count == 0) break;
            here = q.Dequeue();
            if(keymap[here.col][here.row] == target) return here.row +1;
            if(here.row+1 >= keymap[here.col].Length) continue;
            q.Enqueue((here.col, here.row+1));
        }
        return -1;
    }
}
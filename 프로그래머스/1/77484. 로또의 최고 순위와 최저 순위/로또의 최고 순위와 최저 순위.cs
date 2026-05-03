using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = {7,7};
        HashSet<int> s = new HashSet<int>(win_nums);
        for(int i = 0; i < lottos.Length; i++)
        {
            if(s.Contains(lottos[i]))
            {
                answer[0]--;
                answer[1]--;
            }
            if(lottos[i] == 0)
                answer[0]--;
        }
        
        answer[0] = answer[0] == 7 ? 6 : answer[0];
        answer[1] = answer[1] == 7 ? 6 : answer[1];
        
        return answer;
    }
}
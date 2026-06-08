using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<int> answer = new List<int>();
        int day = 0;
        for(int i = 0; i < progresses.Length; i++)
        {
            //현재 진행도에 금일 종료 기준 작업량을 더했을 때 완료되지 않는다면
            if(progresses[i] + speeds[i] * day < 100)
            {
                answer.Add(0);
                day = (100 - progresses[i]) / speeds[i];
                day += (100-progresses[i]) % speeds[i] != 0 ? 1 : 0;
                
            }
            answer[answer.Count-1]++;
        }
        return answer.ToArray();
    }
}
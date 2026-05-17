using System;

public class Solution {
    public int solution(int[] schedules, int[,] timelogs, int startday) {
        int answer = 0;
        
        for(int i = 0; i < schedules.Length; i++)
        {
            if(CheckDate(GetTime(schedules[i]),i, timelogs, startday-1))
                answer++;
        }

        return answer;
    }
    private bool CheckDate(int schedule, int index, int[,] timelog, int startDay)
    {
        for(int i = 0; i < timelog.GetLength(1); i++)
        {
            if(startDay != 5 && startDay != 6)   
            {       
                if(schedule + 10 < GetTime(timelog[index,i]))
                    return false;
            }
            startDay = (startDay + 1 + 7 ) % 7;
        }
        
        return true;
    }
    
    private int GetTime(int time)
    {
        int hour = time / 100;
        int minute = time % 100;
        return hour * 60 + minute;
    }
}
using System;
public class Solution {
    public string solution(int a, int b) {
        int[] day = new int[12]{31,29,31,30,31,30,31,31,30,31,30,31};
        string[] answer = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
        
        int days = 0;
        for(int i = 0; i < a-1; i++)
        {
            days += day[i];
        }
        return answer[(days + b) % 7];
    }
}
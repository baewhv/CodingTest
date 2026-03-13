using System;

public class Solution {
    public string solution(string[] cards1, string[] cards2, string[] goal) {
        int index1 = 0;
        int index2 = 0;
        int goalIndex = 0;
        while(true)
        {
            if(goalIndex >= goal.Length) return "Yes";
            
            if(index1 < cards1.Length && goal[goalIndex] == cards1[index1])
            {
                index1++;
                goalIndex++;
            }
            else if(index2 < cards2.Length && goal[goalIndex] == cards2[index2])
            {
                index2++;
                goalIndex++;
            }
            else
            {
                return "No";
            }
        }
    }
}
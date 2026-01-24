using System;

public class Solution {
    public int[] solution(int[] array, int[,] commands) {
        int[] answer = new int[commands.GetLength(0)];
        for(int i = 0; i < commands.GetLength(0); i++)
        {
            int[] temp = new int[commands[i,1] - commands[i,0]+1];
            Array.Copy(array, commands[i,0]-1, temp,0,commands[i,1] - commands[i,0]+1);
            Array.Sort(temp);
            answer[i] = temp[commands[i,2]-1];
        }
        return answer;
    }
}
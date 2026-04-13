using System;
using System.Collections.Generic;

public class Solution {
    Queue<int> process;
    public int solution(int[] priorities, int location) {
        int rotCount = 0;
        int answer = 1;
        process = new Queue<int>();
        for(int i = 0; i < priorities.Length; i++)
        {
            process.Enqueue(i);
        }
        
        while(true)
        {
            int HighP = FindHigh(priorities);
            if(ExecuteHigh(HighP, priorities) == location)
                return answer;
            else
                answer++;
        }
        return answer;
    }
    public int FindHigh(int[] arr)
    {
        int max = arr[0];
        for(int i = 0; i < arr.Length; i++)
        {
            if(max < arr[i])
                max = arr[i];
        }
        return max;
    }
    public int ExecuteHigh(int high, int[] arr)
    {
        while(true)
        {
            if(arr[process.Peek()] == high)
            {
                arr[process.Peek()] = -1;
                return process.Dequeue();
            }
            else
            {
                process.Enqueue(process.Dequeue());
            }
        }
    }
}

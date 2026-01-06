using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int num, int total) {
        int[] answer;
        Queue<int> q = new Queue<int>();
        int sum = 0;
        int pivot = 1000;
        while(true)
        {
            if(q.Count < num)
            {
                sum += pivot;
                q.Enqueue(pivot--);
            }
            else if(sum == total)
            {
                return GetArray(q);
            }
            else
            {
                sum -= q.Dequeue();
            }
        }
    }
    
    public int[] GetArray(Queue<int> q)
    {
        int[] arr = new int[q.Count];
        for(int i = q.Count-1; i >= 0; i--)
        {
            arr[i] = q.Dequeue();
        }
        return arr;
    }
}
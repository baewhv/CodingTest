using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[,] signals) {
        int answer = 0;
        List<int>[] signal = new List<int>[signals.GetLength(0)];
        
        for(int i = 0; i < signals.GetLength(0); i++)
        {
            signal[i] = new List<int>();
            for(int j = 0; j < signals.GetLength(1); j=j)
            {
                signals[i,j]--;
                signal[i].Add(j);
                if(signals[i,j] == 0) j++;
            }
        }
        while(true)
        {
            if(CheckYellow(signal, answer)) break;
            if(!CheckDivide(signal, answer+1)) return -1;
            answer++;
        }
        return answer+1;
    }
    private bool CheckYellow(List<int>[] signal, int point)
    {
        for(int i = 0; i < signal.Length; i++)
        {
            if(signal[i][(point + signal[i].Count) % signal[i].Count] != 1) return false;
        }
        return true;
    }
    private bool CheckDivide(List<int>[] signal, int point)
    {
        for(int i = 0; i < signal.Length; i++)
        {
            if(point % signal[i].Count != 0) return true;
        }
        return false;
    }
}
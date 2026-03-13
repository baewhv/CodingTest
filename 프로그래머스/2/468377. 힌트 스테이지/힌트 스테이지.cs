using System;

public class Solution {
    int answer = int.MaxValue;
    public int solution(int[,] cost, int[,] hint) {
        
        FindLowCost(cost, hint, 0, 0, new int[cost.GetLength(0)]);
        
        return answer;
    }
    
    private void FindLowCost(int[,] cost, int[,] hint, int pos, int total, int[] hintCount)
    {
        if(pos >= cost.GetLength(0))
        {
            answer = answer > total ? total : answer;
            return;
        }
        int calcPos = hintCount[pos] > hint.GetLength(0) ? hint.GetLength(0) : hintCount[pos];
        int discountCost = cost[pos, calcPos];
        
        int[] notBuyHint = new int[cost.GetLength(0)];
        Array.Copy(hintCount, notBuyHint, cost.GetLength(0));
        FindLowCost(cost,hint, pos+1, total + discountCost, notBuyHint);
        
        if(pos >= cost.GetLength(0) - 1) return;
        int[] buyHint = new int[cost.GetLength(0)];
        Array.Copy(hintCount, buyHint, cost.GetLength(0));
        
        for(int i = 1; i < hint.GetLength(1); i++)
        {
            buyHint[hint[pos,i]-1]++;
        }
        discountCost = cost[pos, calcPos];
        
        FindLowCost(cost,hint, pos+1, total + discountCost + hint[pos,0], buyHint);
                    
    }
    
}
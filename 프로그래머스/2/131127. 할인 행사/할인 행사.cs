using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[] want, int[] number, string[] discount) {
        Dictionary<string,int> wishList = new Dictionary<string, int>();
        for(int i = 0; i < want.Length; i++)
        {
            wishList[want[i]] = number[i];
        }
        int answer = 0;
        Queue<string> Combo = new Queue<string>();
        for(int i = 0; i <= discount.Length; i++)
        {
            if(Combo.Count == 10)
            {
                if(CheckWishList(wishList)) answer++;
                string temp = Combo.Dequeue();
                if(wishList.ContainsKey(temp))
                    wishList[temp]++;
            }
            if(i == discount.Length) break;
            Combo.Enqueue(discount[i]);
            if(wishList.ContainsKey(discount[i]))
                wishList[discount[i]]--;
                
        }
        return answer;
    }
    
    bool CheckWishList(Dictionary<string,int> wishList)
    {
        foreach(KeyValuePair<string, int> pair in wishList)
        {
            if(pair.Value > 0) return false;
        }
        return true;
    }
}
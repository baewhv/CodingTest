using System;
using System.Collections.Generic;

public class Solution {
    public bool solution(string s) {
        Stack<char> bracket = new Stack<char>();
        for(int i = 0; i < s.Length; i++)
        {
            if(s[i] == '(')
            {
                bracket.Push(s[i]);
            }
            else 
            {
                if(bracket.Count != 0 && bracket.Peek() == '(')
                {
                    bracket.Pop();
                }
                else return false;
                    
            }
        }
            
        if(bracket.Count != 0) return false;
        return true;
    }
}
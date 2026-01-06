using System;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string[] players, string[] callings) {
        Dictionary<string,int> table = new Dictionary<string,int>();
        for(int i = 0; i < players.Length; i++)
        {
            table[players[i]] = i;
        }
        
        for(int i = 0; i < callings.Length; i++)
        {
            string temp = players[table[callings[i]]-1];
            players[table[callings[i]]-1] = players[table[callings[i]]];
            players[table[callings[i]]] = temp;
            
            table[callings[i]]--;
            table[temp]++;
        }
        
        return players;
    }
}
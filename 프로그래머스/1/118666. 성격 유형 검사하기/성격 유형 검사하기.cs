using System;
using System.Collections.Generic;

public class Solution {
    public string solution(string[] survey, int[] choices) {
        Dictionary<string, int> PersonalType = new Dictionary<string, int>();
        PersonalType["RT"] = 0;
        PersonalType["CF"] = 0;
        PersonalType["JM"] = 0;
        PersonalType["AN"] = 0;
        for(int i =0; i < survey.Length; i++)
        {
            if(!PersonalType.ContainsKey(survey[i]))
            {
                survey[i] = $"{survey[i][1]}{survey[i][0]}";
                choices[i] = -(choices[i]-4) + 4;
            }
            choices[i] -= 4;
            PersonalType[survey[i]] += choices[i];
        }
        return $"{PersonalType["RT"] <= 0 ? "R" : "T"}{PersonalType["CF"] <= 0 ? "C" : "F"}{PersonalType["JM"] <= 0 ? "J" : "M"}{PersonalType["AN"] <= 0 ? "A" : "N"}";
    }
}
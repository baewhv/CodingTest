using System;

public class Solution {
    public int solution(string skill, string[] skill_trees) {
        int answer = 0;
        for(int i = 0; i < skill_trees.Length; i++)
        {
            int[] arr = new int[skill.Length];
            for(int j = 0; j < skill.Length; j++)
            {
                arr[j] = skill_trees[i].IndexOf(skill[j]);
            }
            if(CheckTree(arr))
                answer++;
        }
        return answer;
    }
    public bool CheckTree(int[] arr)
    {
        for(int i = 1; i < arr.Length; i++)
        {
            if(arr[0] == -1)
            {
                if(arr[i] >= 0) 
                    return false;
            }
            if(arr[i] != -1 && arr[0] > arr[i])
                return false;
            arr[0] = arr[i];
        }
        return true;
    }
}
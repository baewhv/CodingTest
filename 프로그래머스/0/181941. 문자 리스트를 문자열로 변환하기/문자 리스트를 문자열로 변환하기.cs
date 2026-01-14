using System;
using System.Text;

public class Solution {
    public string solution(string[] arr) {
        StringBuilder st = new StringBuilder(arr.Length+1);
        st.Length = arr.Length;
        for(int i = 0; i < arr.Length; i++)
        {
            st[i] = arr[i][0];
        }
        
        return st.ToString();
    }
}
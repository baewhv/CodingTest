using System;

public class Solution {
    public int solution(int a, int b) {
        return CirclePlus(a, b) >= (2 * a * b) ? CirclePlus(a, b) : (2 * a * b);
    }
    public int CirclePlus(int a, int b)
    {
        string aString = a.ToString();
        string bString = b.ToString();
        
        string temp = aString + bString;
        
        return int.Parse(temp);
    }
}
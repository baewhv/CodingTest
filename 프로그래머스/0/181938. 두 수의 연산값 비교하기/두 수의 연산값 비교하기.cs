using System;

public class Solution {
    public int solution(int a, int b) {
        return CirclePlus(a, b) >= (2 * a * b) ? CirclePlus(a, b) : (2 * a * b);
    }
    public int CirclePlus(int a, int b)
    {
        int temp = b;
        while(temp != 0)
        {
            temp /= 10;
            a *= 10;
        }
        
        return a + b;
    }
}
using System;

public class Solution {
    public int solution(int[] numbers) {
        //정렬
        Array.Sort(numbers);
        //양수곱
        int plusNum = numbers[numbers.Length-2] * numbers[numbers.Length-1];
        //음수곱
        int minusNum = numbers[0] * numbers[1];
        
        return plusNum > minusNum ? plusNum : minusNum;
    }
}
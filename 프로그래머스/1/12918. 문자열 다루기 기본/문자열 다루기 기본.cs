public class Solution {
    public bool solution(string s) {
        
        int temp;
        if(s.Length == 4 || s.Length == 6)
            return int.TryParse(s, out temp);
        else
            return false;
    }
}
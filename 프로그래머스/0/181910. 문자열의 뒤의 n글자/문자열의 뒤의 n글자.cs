using System;

public class Solution {
    public string solution(string my_string, int n) 
    {
        string answer;
        int cnt = my_string.Length - n;
        answer = my_string.Substring(cnt);
        return answer;
    }
}
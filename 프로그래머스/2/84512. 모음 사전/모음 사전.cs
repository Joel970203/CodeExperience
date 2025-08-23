using System;

public class Solution {
    int answer = 0;
    int count = 0;
    bool found = false;

    private void dfs(string target, string temp, string order)
    {
        if (temp.Length > 0)
        {
            count++;
            if (temp == target)
            {
                answer = count;
                found = true;
                return;
            }
        }

        if (temp.Length == 5 || found) return;

        foreach (char x in order)
        {
            dfs(target, temp + x, order);
            if (found) return; 
        }
    }

    public int solution(string word) 
    {
        string order = "AEIOU";
        dfs(word, "", order);
        return answer;
    }
}

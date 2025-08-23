using System;

public class Solution 
{
    private int answer;
    
    private void Dfs(int[] numbers, int target, int sum, int idx)
    {
        if(idx ==numbers.Length)
        {
            if(target == sum) 
            {
                answer++;
            }
            return;
        }
        
        Dfs(numbers,target,sum + numbers[idx],idx+1);
        Dfs(numbers,target,sum - numbers[idx],idx+1);
    }
    
    public int solution(int[] numbers, int target) 
    {
        answer = 0;
        Dfs(numbers,target,0,0);
        return answer;
    }
}
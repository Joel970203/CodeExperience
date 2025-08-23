using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] keymap, string[] targets) 
    {
        var dict = new Dictionary<char,int>();
        
        for(int i=0;i<keymap.Length;i++)
        {
            for(int j=0;j<keymap[i].Length;j++)
            {
                char c = keymap[i][j];
                if(dict.ContainsKey(c))
                {
                    if(dict[c] > j+1) dict[c] = j+1;
                }
                else dict[c] = j+1;
            }
        }
        
        int[] answer = new int[targets.Length];
        for(int i=0;i<targets.Length;i++)
        {
            int su = 0;
            for(int j=0;j<targets[i].Length;j++)
            {
                char c = targets[i][j];
                
                if(dict.ContainsKey(c))
                {
                    su += dict[c];
                }
                else 
                {
                    su = -1;
                    break;
                }
            }
            
            answer[i] = su;
        }
        
        return answer;
    }
}
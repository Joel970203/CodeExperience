using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string dirs) 
    {
        HashSet<(int a, int b, int c, int d)> visited = new HashSet<(int, int, int, int)>();

        int curY = 0,curX = 0;
        
        foreach(char dir in dirs)
        {
            int tempY = curY;
            int tempX = curX;
            
            if(dir == 'U') tempY++;
            else if(dir =='D') tempY--;
            else if(dir == 'R')tempX++;
            else if(dir == 'L')tempX--;
            
            if(tempY > 5 || tempY < -5 || tempX > 5 || tempX < -5) continue;
            
            visited.Add((tempY,tempX,curY,curX));
            visited.Add((curY,curX,tempY,tempX));
            
            curY = tempY;
            curX = tempX;
        }
        
        int answer = visited.Count / 2;
        return answer;
    }
}
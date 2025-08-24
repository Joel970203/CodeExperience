using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int m, int n, int startX, int startY, int[,] balls) 
    {
        List<int> arr = new List<int>();
        int cnt = balls.GetLength(0);
        for(int i=0;i<cnt;i++)
        {
            int minDist = int.MaxValue;
            int targetX = balls[i,0];
            int targetY = balls[i,1];

            if (!(startX == targetX && startY < targetY))
            {
                int dy = startY - (n*2 - targetY);
                int dx = startX - targetX;
                minDist = Math.Min(minDist,dx * dx + dy * dy);
            }
            
            if(!(startX == targetX && startY > targetY))
            {
                int dy = startY - (-targetY);
                int dx = startX - targetX;
                minDist = Math.Min(minDist,dx * dx + dy * dy);
            }
            
            if(!(startY == targetY && startX < targetX)) // 우측 
            {
                int dy = startY - targetY;
                int dx = startX - (2*m - targetX);
                minDist = Math.Min(minDist,dx * dx + dy * dy);
            }
            
            if(!(startY == targetY && startX > targetX)) // 좌측 
            {
                int dy = startY - targetY;
                int dx = startX - (-targetX);
                minDist = Math.Min(minDist,dx * dx + dy * dy);
            }
            
            arr.Add(minDist);

        }
        return arr.ToArray();
    }
}
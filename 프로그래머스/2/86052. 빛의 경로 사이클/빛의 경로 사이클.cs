using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(string[] grid) 
    {
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};
        
        int n = grid.Length;
        int m = grid[0].Length;
        
        bool[,,] graph = new bool[n,m,4];
        List<int> answer = new List<int>();
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                for(int k=0;k<4;++k)
                {
                    if(graph[i,j,k]) continue;
                    
                    int y = i;
                    int x = j;
                    int dir = k;
                    int cnt = 0;
                    
                    while(!graph[y,x,dir])
                    {
                        graph[y,x,dir] = true;
                        cnt++;
                        
                        int ny = (y+dy[dir]+n)%n;
                        int nx = (x+dx[dir]+m)%m;
                        
                        char p = grid[ny][nx];
                        if(p == 'R') dir = (dir + 1) % 4;
                        else if(p == 'L') dir = (dir+3) % 4;
                        
                        
                        x = nx;
                        y = ny;
                    }
                    
                    if(cnt > 0) answer.Add(cnt);
                }
            }
        }
        answer.Sort();
        return answer.ToArray();
    }
}
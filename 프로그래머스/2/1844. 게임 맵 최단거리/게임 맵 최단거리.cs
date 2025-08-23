using System;
using System.Collections.Generic;

class Solution
{
    public int solution(int[,] maps) 
    {
        int n = maps.GetLength(0); // 행
        int m = maps.GetLength(1); // 열

        int[] dx = { 1, -1, 0, 0 };
        int[] dy = { 0, 0, 1, -1 };

        bool[,] visited = new bool[n, m];
        Queue<(int y, int x, int cost)> q = new Queue<(int, int, int)>();

        q.Enqueue((0, 0, 1));
        visited[0, 0] = true;

        while (q.Count > 0)
        {
            var (curY, curX, curCost) = q.Dequeue();

            if (curY == n - 1 && curX == m - 1) return curCost;

            for (int i = 0; i < 4; i++)
            {
                int ny = curY + dy[i];
                int nx = curX + dx[i];

                if (ny >= 0 && nx >= 0 && ny < n && nx < m)
                {
                    if (!visited[ny, nx] && maps[ny, nx] == 1)
                    {
                        visited[ny, nx] = true;
                        q.Enqueue((ny, nx, curCost + 1));
                    }
                }
            }
        }

        return -1; // 도착 불가
    }
}

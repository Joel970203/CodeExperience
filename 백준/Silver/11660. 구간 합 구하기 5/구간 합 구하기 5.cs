using System;
using System.Text;

public class BOJ11660
{
    public static void Main()
    {
        string[] nm = Console.ReadLine().Split();
        int N = int.Parse(nm[0]);
        int M = int.Parse(nm[1]);

        int[,] arr = new int[N+1, N+1];     
        int[,] ps  = new int[N+1, N+1];     

        for (int i = 1; i <= N; i++)
        {
            string[] line = Console.ReadLine().Split();
            for (int j = 1; j <= N; j++)
            {
                arr[i,j] = int.Parse(line[j-1]);
                ps[i,j] = arr[i,j] + ps[i-1,j] + ps[i,j-1] - ps[i-1,j-1];
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int q = 0; q < M; q++)
        {
            string[] query = Console.ReadLine().Split();
            int x1 = int.Parse(query[0]);
            int y1 = int.Parse(query[1]);
            int x2 = int.Parse(query[2]);
            int y2 = int.Parse(query[3]);

            int sum = ps[x2,y2] - ps[x1-1,y2] - ps[x2,y1-1] + ps[x1-1,y1-1];
            sb.AppendLine(sum.ToString());
        }
        Console.Write(sb.ToString());
    }
}

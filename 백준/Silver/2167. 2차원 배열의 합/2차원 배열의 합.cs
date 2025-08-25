using System;
using System.Text;

public class BOJ2167
{
    public static void Main()
    {
        string[] temp = Console.ReadLine().Split();
        int N = int.Parse(temp[0]);
        int M = int.Parse(temp[1]);
        
        int[,] arr = new int[N+1,M+1];
        int[,] ps = new int[N+1,M+1];
        
        for (int i = 1; i <= N; i++)
        {
            string[] cur = Console.ReadLine().Split();
            for (int j = 1; j <= M; j++)
            {
                arr[i,j] = int.Parse(cur[j-1]);
                ps[i,j] = arr[i,j] + ps[i-1,j] + ps[i,j-1] - ps[i-1,j-1];
            }
        }
        
        int k = int.Parse(Console.ReadLine());   
        
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < k; i++)
        {
            string[] s = Console.ReadLine().Split();  
            int y1 = int.Parse(s[0]);
            int x1 = int.Parse(s[1]);
            int y2 = int.Parse(s[2]);
            int x2 = int.Parse(s[3]);
            
            int sum = ps[y2,x2] - ps[y1-1,x2] - ps[y2,x1-1] + ps[y1-1,x1-1];
            sb.AppendLine(sum.ToString());
        }
        
        Console.Write(sb.ToString());
    }
}

using System;
using System.Text;

public class BOJ
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        StringBuilder sb = new StringBuilder();
        
        for(int i =0;i<N;i++)
        {
            string[] txt = Console.ReadLine().Split();
            int M = int.Parse(txt[0]);
            double sum = 0;
            
            for(int j=1;j<=M;j++)
            {
                sum += int.Parse(txt[j]);
            }
            
            double avg = sum / M;
            int cnt = 0;
            for(int j=1;j<=M;j++)
            {
                int tmp = int.Parse(txt[j]);
                if(tmp > avg) cnt++;
            }
            
            double ans = (double)cnt / M * 100.0;
            
            sb.AppendLine($"{ans:F3}%");
            
        }
         Console.Write(sb.ToString());
    }
}
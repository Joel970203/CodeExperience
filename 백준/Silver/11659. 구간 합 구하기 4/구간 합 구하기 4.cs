using System;
using System.Text;
using System.Collections.Generic;

public class Program   // 클래스 이름 변경
{
    public static void Main()
    {
        string[] count = Console.ReadLine().Split();
        int N = int.Parse(count[0]);
        int M = int.Parse(count[1]);
        
        string[] nums = Console.ReadLine().Split();  // alpha → nums
        int[] arr = new int[N+1];
        int[] prefix = new int[N+1];
        
        for (int i = 1; i <= N; ++i)
        {
            arr[i] = int.Parse(nums[i-1]);
            prefix[i] = prefix[i-1] + arr[i];
        }
     
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < M; i++)
        {
            string[] query = Console.ReadLine().Split();
            int a = int.Parse(query[0]);
            int b = int.Parse(query[1]);
            
            int sum = prefix[b] - prefix[a-1];
            sb.AppendLine(sum.ToString());
        }
        
        Console.Write(sb.ToString());
    }
}

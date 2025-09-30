using System;
using System.Text;

public class BOJ15552
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        StringBuilder sb = new StringBuilder();
        
        for(int i=0;i<N;i++)
        {
            string[] input = Console.ReadLine().Split();
            int A = int.Parse(input[0]);
            int B = int.Parse(input[1]);
            sb.AppendLine((A+B).ToString());
        }
        
        Console.Write(sb.ToString());
    }
}
using System;
using System.Collections.Generic;
using System.Text;

public class BOJ2741
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        StringBuilder sb = new StringBuilder();
        
        for(int i=1;i<=N;i++)
        {
            sb.AppendLine(i.ToString());
        }
        
        Console.Write(sb.ToString());
    }
}
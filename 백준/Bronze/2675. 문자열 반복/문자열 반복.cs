using System;
using System.Text;

public class BOJ2675
{
    public static void Main()
    {
        int T = int.Parse(Console.ReadLine());
        
        for(int i=0;i<T;i++)
        {
            string[] input = Console.ReadLine().Split();
            int R = int.Parse(input[0]);
            string S = input[1];
            StringBuilder sb = new StringBuilder();
            foreach(char c in S)
            {
                for(int j=0;j<R;j++)
                {
                    sb.Append(c);
                }
            }
            
            Console.WriteLine(sb.ToString());
        }
    }
}
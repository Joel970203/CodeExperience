using System;
using System.Collections.Generic;
using System.Text;

public class BOJ10845
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        var q = new Queue<int>();
        var sb = new StringBuilder();
        int last = 0; // 가장 최근에 push된 값 (back용)

        for (int i = 0; i < N; i++)
        {
            string[] token = Console.ReadLine().Split();

            switch (token[0])
            {
                case "push":
                {
                    int x = int.Parse(token[1]);
                    q.Enqueue(x);
                    last = x;
                    break;
                }
                case "pop":
                {
                    sb.AppendLine(q.Count == 0 ? "-1" : q.Dequeue().ToString());
                    break;
                }
                case "size":
                {
                    sb.AppendLine(q.Count.ToString());
                    break;
                }
                case "empty":
                {
                    sb.AppendLine(q.Count == 0 ? "1" : "0");
                    break;
                }
                case "front":
                {
                    sb.AppendLine(q.Count == 0 ? "-1" : q.Peek().ToString());
                    break;
                }
                case "back":
                {
                    sb.AppendLine(q.Count == 0 ? "-1" : last.ToString());
                    break;
                }
            }
        }

        Console.Write(sb.ToString());
    }
}

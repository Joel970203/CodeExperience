using System;
using System.Collections.Generic;
using System.Text;

public class BOJ18258
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var q = new Queue<int>();
        var sb = new StringBuilder();
        int last = -1; 
        
        for (int i = 0; i < n; i++)
        {
            string[] tok = Console.ReadLine().Split();

            switch (tok[0])
            {
                case "push":
                    last = int.Parse(tok[1]);
                    q.Enqueue(last);
                    break;

                case "pop":
                    if (q.Count == 0) sb.AppendLine("-1");
                    else sb.AppendLine(q.Dequeue().ToString());
                    break;

                case "size":
                    sb.AppendLine(q.Count.ToString());
                    break;

                case "empty":
                    sb.AppendLine(q.Count == 0 ? "1" : "0");
                    break;

                case "front":
                    if (q.Count == 0) sb.AppendLine("-1");
                    else sb.AppendLine(q.Peek().ToString());
                    break;

                case "back":
                    if (q.Count == 0) sb.AppendLine("-1");
                    else sb.AppendLine(last.ToString());
                    break;
            }
        }

        Console.Write(sb.ToString());
    }
}

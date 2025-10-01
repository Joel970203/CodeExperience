using System;
using System.Collections.Generic;
using System.Text;

public class BOJ10866
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var dq = new LinkedList<int>();
        var sb = new StringBuilder();

        for (int i = 0; i < n; i++)
        {
            string[] t = Console.ReadLine().Split();

            switch (t[0])
            {
                case "push_front":
                {
                    int x = int.Parse(t[1]);
                    dq.AddFirst(x);
                    break;
                }
                case "push_back":
                {
                    int x = int.Parse(t[1]);
                    dq.AddLast(x);
                    break;
                }
                case "pop_front":
                {
                    if (dq.First is LinkedListNode<int> node)
                    {
                        sb.AppendLine(node.Value.ToString());
                        dq.RemoveFirst();
                    }
                    else sb.AppendLine("-1");
                    break;
                }
                case "pop_back":
                {
                    if (dq.Last is LinkedListNode<int> node)
                    {
                        sb.AppendLine(node.Value.ToString());
                        dq.RemoveLast();
                    }
                    else sb.AppendLine("-1");
                    break;
                }
                case "size":
                {
                    sb.AppendLine(dq.Count.ToString());
                    break;
                }
                case "empty":
                {
                    sb.AppendLine(dq.Count == 0 ? "1" : "0");
                    break;
                }
                case "front":
                {
                    if (dq.First is LinkedListNode<int> node)
                        sb.AppendLine(node.Value.ToString());
                    else
                        sb.AppendLine("-1");
                    break;
                }
                case "back":
                {
                    if (dq.Last is LinkedListNode<int> node)
                        sb.AppendLine(node.Value.ToString());
                    else
                        sb.AppendLine("-1");
                    break;
                }
            }
        }

        Console.Write(sb.ToString());
    }
}

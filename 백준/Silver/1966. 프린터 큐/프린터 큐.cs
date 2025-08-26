using System;
using System.Collections.Generic;
using System.Text;

public class BOJ1966
{
    public static void Main()
    {
        int T = int.Parse(Console.ReadLine());
        StringBuilder sb = new StringBuilder();

        for (int t = 0; t < T; t++)
        {
            string[] s = Console.ReadLine().Split();
            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);

            Queue<(int, int)> q = new Queue<(int, int)>();
            string[] arr = Console.ReadLine().Split();
            for (int i = 0; i < N; ++i)
            {
                int k = int.Parse(arr[i]);
                q.Enqueue((k, i));
            }

            int count = 0;
            while (q.Count > 0)
            {
                var (curVal, curIdx) = q.Dequeue();
                bool hasBigger = false;

                // 큐 복사해서 뒤에 더 큰 게 있는지 확인
                Queue<(int, int)> tmp = new Queue<(int, int)>(q);
                while (tmp.Count > 0)
                {
                    if (tmp.Peek().Item1 > curVal)
                    {
                        hasBigger = true;
                        break;
                    }
                    tmp.Dequeue();
                }

                if (hasBigger)
                {
                    q.Enqueue((curVal, curIdx));
                }
                else
                {
                    count++;
                    if (curIdx == M)
                    {
                        sb.AppendLine(count.ToString());
                        break;
                    }
                }
            }
        }

        Console.Write(sb.ToString());
    }
}

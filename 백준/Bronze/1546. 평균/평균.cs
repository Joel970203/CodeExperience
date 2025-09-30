using System;

public class BOJ1546
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        string[] arr = Console.ReadLine().Split();
        
        int max = int.MinValue;

        // 최대값 구하기
        for (int i = 0; i < N; i++)
        {
            int k = int.Parse(arr[i]);
            if (k > max)
            {
                max = k;
            }
        }

        double tot = 0; // double로 해야 소수점 정확
        for (int i = 0; i < N; i++)
        {
            double score = double.Parse(arr[i]);
            tot += score / max * 100.0;
        }

        double avg = tot / N;
        Console.WriteLine(avg);
    }
}

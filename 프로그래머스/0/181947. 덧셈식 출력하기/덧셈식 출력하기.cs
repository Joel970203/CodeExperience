using System;

public class Solution
{
    public static void Main()
    {
        // 한 줄로 두 정수를 입력받고 split으로 분리
        string[] parts = Console.ReadLine().Split(' ');

        int a = int.Parse(parts[0]);
        int b = int.Parse(parts[1]);

        int sum = a + b;

        // 원하는 형식 출력: "a + b = c"
        Console.WriteLine($"{a} + {b} = {sum}");
    }
}

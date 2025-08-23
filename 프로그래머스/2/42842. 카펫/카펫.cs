using System;

public class Solution
{
    public int[] solution(int brown, int yellow)
    {
        int total = brown + yellow;

        for (int w = 3; w <= brown / 2; w++)  // 가로
        {
            for (int h = 3; h <= w; h++)      // 세로 (항상 w >= h)
            {
                int boundary = (w + h - 2) * 2;
                int center = w * h - boundary;

                if (brown == boundary && yellow == center)
                    return new int[] { w, h };
            }
        }

        return null; // 실제로는 도달하지 않음
    }
}

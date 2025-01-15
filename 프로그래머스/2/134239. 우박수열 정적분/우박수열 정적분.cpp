#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<double> solution(int k, vector<vector<int>> ranges)
{
    vector<double> answer;
    vector<int> Collatz;
    Collatz.push_back(k);
    while (k != 1)
    {
        if (k % 2 == 0)
        {
            k /= 2;
        }
        else
        {
            k *= 3;
            k += 1;
        }
        Collatz.push_back(k);
    }

    int  n = Collatz.size() - 1;

    for (int i = 0; i < ranges.size(); i++)
    {
        double temp = 0.0;
        int head = ranges[i][0];
        int tail = n - abs(ranges[i][1]);

        if (head > tail || tail > n)
        {
            answer.push_back(-1.0);
            continue;
        }

        for (int j = head; j < tail; j++)
        {
            temp += (Collatz[j] + Collatz[j + 1]) / 2.0;
        }

        answer.push_back(temp);
    }

    return answer;
}


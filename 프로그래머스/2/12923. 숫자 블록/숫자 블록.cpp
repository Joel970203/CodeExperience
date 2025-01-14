#include <vector>
using namespace std;
const int MAX_VALUE = 10000000;

long long FindMaxDivisor(long long n)
{
    long long result = 1;

    for (long long i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) {
            result = i;

            if (n / i <= MAX_VALUE) 
            {
                result = n / i;
                break;
            }
        }
    }

    return result;
}

vector<int> solution(long long begin, long long end) 
{
    vector<int> answer;

    for (long long i = begin; i <= end; i++) 
    {
        if (i == 1) 
        {
            answer.emplace_back(0);
            continue;
        }
        answer.emplace_back(FindMaxDivisor(i));
    }

    return answer;
}
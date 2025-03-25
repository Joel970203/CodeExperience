#include <cmath>
#include <vector>
using namespace std;

long long solution(int k, int d)
{
    long long answer = 0;
    for (int x = 0; x <= d; x += k) 
    {
        int maxY = static_cast<int>(sqrt((long long)d * d - (long long)x * x));
        answer += (maxY / k) + 1;
    }
    return answer;
}

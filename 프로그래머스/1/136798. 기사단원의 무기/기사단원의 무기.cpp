#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) 
{
    int answer = 0;
    vector<int> factors(number + 1, 0);

    for (int i = 1; i <= number; i++) 
    {
        for (int j = i; j <= number; j += i) 
        {
            factors[j]++;
        }
    }

    for (int i = 1; i <= number; i++) 
    {
        if (factors[i] > limit) 
        {
            answer += power;
        } 
        else 
        {
            answer += factors[i];
        }
    }

    return answer;
}

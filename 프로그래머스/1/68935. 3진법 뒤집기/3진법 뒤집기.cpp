#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n)
{
    std::string ternary = "";
    while (n > 0) 
    {
        ternary += std::to_string(n % 3);
        n /= 3;
    }

    int decimal = 0;
    int power = 0;
    for (int i = ternary.size() - 1; i >= 0; i--) 
    {
        decimal += (ternary[i] - '0') * std::pow(3, power++);
    }

    return decimal;
}

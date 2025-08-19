#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int x=1; x<=r2; x++) 
    {
        long long yMax = floor(sqrt(1LL*r2*r2 - 1LL*x*x));
        long long yMin = ceil(sqrt(max(0LL, 1LL*r1*r1 - 1LL*x*x)));

        answer += (yMax - yMin + 1); 
    }
    return answer * 4;
}

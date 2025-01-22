#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a) 
    { 
        int extra = (n / a) * b; 
        answer += extra;
        n = (n % a) + extra;
    }
    return answer;
}
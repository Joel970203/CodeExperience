#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;

    string alpha = to_string(n);

    sort(alpha.begin(), alpha.end(), greater<>());

    answer = stoll(alpha);

    return answer;
}

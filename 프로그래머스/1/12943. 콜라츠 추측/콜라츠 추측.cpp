#include <string>
#include <vector>

using namespace std;

int Collatz(long long num, int cnt) {
    if (cnt > 500) {
        return -1; // 500번 초과 시 -1 반환
    }
    if (num == 1) {
        return cnt; // num이 1이 되면 작업 횟수 반환
    }
    if (num % 2 == 0) { // 짝수일 경우
        return Collatz(num / 2, cnt + 1);
    } else { // 홀수일 경우
        return Collatz(num * 3 + 1, cnt + 1);
    }
}

int solution(int num) {
    // 입력 값을 long long으로 변환하여 처리
    return Collatz(static_cast<long long>(num), 0);
}

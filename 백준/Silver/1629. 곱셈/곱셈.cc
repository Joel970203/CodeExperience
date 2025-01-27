#include <iostream>
using namespace std;

long long mod_exp(long long A, long long B, long long C) {
    long long result = 1;
    A = A % C;  // A가 C보다 크면 나머지를 먼저 취해서 최적화

    while (B > 0) {
        if (B % 2 == 1) {  // B가 홀수일 경우
            result = (result * A) % C;
        }
        A = (A * A) % C;  // A를 제곱
        B /= 2;  // B를 반으로 나눈다
    }

    return result;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    cout << mod_exp(A, B, C) << endl;
    
    return 0;
}
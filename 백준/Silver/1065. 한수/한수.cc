#include <iostream>

using namespace std;

// 함수: 한수인지 확인
bool isHansu(int num) {
    if (num < 100) {
        return true; // 1자리 및 2자리 숫자는 모두 한수
    }

    int hundreds = num / 100; // 백의 자리
    int tens = (num / 10) % 10; // 십의 자리
    int units = num % 10; // 일의 자리

    // 등차수열 확인: (백의 자리 - 십의 자리) == (십의 자리 - 일의 자리)
    return (hundreds - tens) == (tens - units);
}

int main() {
    int N;
    cin >> N;

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (isHansu(i)) {
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}
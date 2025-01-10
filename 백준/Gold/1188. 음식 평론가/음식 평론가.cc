#include <iostream>
using namespace std;

// 최대 공약수를 구하는 함수
int GCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N, M;
    cin >> N >> M;

    // 최대 공약수를 구하고 M에서 이를 빼서 결과를 출력
    cout << M - GCD(N, M) << endl;

    return 0;
}
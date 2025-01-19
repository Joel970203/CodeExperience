#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false; // 1 이하는 소수가 아님
    if (n == 2) return true;  // 2는 소수
    if (n % 2 == 0) return false; // 짝수는 소수가 아님

    for (int i = 3; i * i <= n; i += 2) { // 3부터 홀수만 검사
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (isPrime(arr[i])) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}

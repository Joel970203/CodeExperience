#include <iostream>
#include <vector>
#include <cmath> // 제곱근 사용을 위해 필요
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false; // 2보다 작은 수는 소수가 아님
    if (num == 2) return true;  // 2는 소수
    if (num % 2 == 0) return false; // 2를 제외한 짝수는 소수가 아님

    // 제곱근까지만 검사
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    fastio();
    int M, N;
    cin >> M >> N;

    for (int i = M; i <= N; i++)
    {
        if (isPrime(i)) {
            cout << i << endl;
        }
    }
}

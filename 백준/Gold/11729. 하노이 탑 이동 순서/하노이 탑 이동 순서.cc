#include <iostream>
using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << from << " " << to << "\n";  // 원판이 1개면 바로 이동
        return;
    }
    hanoi(n - 1, from, aux, to);  // (1) 작은 원판들을 보조 장대로 이동
    cout << from << " " << to << "\n";  // (2) 가장 큰 원판을 목표 장대로 이동
    hanoi(n - 1, aux, to, from);  // (3) 보조 장대에 있던 작은 원판들을 목표 장대로 이동
}


int main() {
    int N;
    cin >> N;
    cout << (1 << N) - 1 << "\n"; // 최소 이동 횟수: 2^N - 1
    hanoi(N, 1, 3, 2);
    return 0;
}



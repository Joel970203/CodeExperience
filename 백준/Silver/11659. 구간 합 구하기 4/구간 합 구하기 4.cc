#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  // C++ 표준 입출력과 C 표준 입출력 동기화를 비활성화
    cin.tie(NULL);  // cin과 cout의 묶음을 풀어서 입출력 성능 최적화

    int N, M;
    cin >> N >> M;

    vector<int> prefixSum(N + 1, 0);

    // 누적 합 계산
    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        prefixSum[i] = prefixSum[i - 1] + num;
    }

    // 구간 합 계산 및 출력
    for (int k = 0; k < M; ++k) {
        int i, j;
        cin >> i >> j;
        cout << prefixSum[j] - prefixSum[i - 1] << '\n';
    }

    return 0;
}
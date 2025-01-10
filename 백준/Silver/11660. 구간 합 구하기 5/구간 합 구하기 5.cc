#include <iostream>
#include <vector>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio();  // 입출력 성능 최적화

    int N, M;
    cin >> N >> M;

    vector<vector<int>> square(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> prefixSum(N + 1, vector<int>(N + 1, 0));

    // 입력 받으면서 누적 합 배열 계산
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> square[i][j];
            prefixSum[i][j] = square[i][j] 
                            + prefixSum[i - 1][j] 
                            + prefixSum[i][j - 1] 
                            - prefixSum[i - 1][j - 1];
        }
    }

    // 각 쿼리에 대한 결과 계산 및 출력
    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = prefixSum[x2][y2] 
                   - prefixSum[x1 - 1][y2] 
                   - prefixSum[x2][y1 - 1] 
                   + prefixSum[x1 - 1][y1 - 1];

        cout << result << '\n';
    }

    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int prev_max[3], prev_min[3];
    int cur_max[3], cur_min[3];

    // 첫 줄 입력
    cin >> prev_max[0] >> prev_max[1] >> prev_max[2];
    prev_min[0] = prev_max[0];
    prev_min[1] = prev_max[1];
    prev_min[2] = prev_max[2];

    for (int i = 1; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        // 최대값 DP
        cur_max[0] = a + max(prev_max[0], prev_max[1]);
        cur_max[1] = b + max({ prev_max[0], prev_max[1], prev_max[2] });
        cur_max[2] = c + max(prev_max[1], prev_max[2]);

        // 최소값 DP
        cur_min[0] = a + min(prev_min[0], prev_min[1]);
        cur_min[1] = b + min({ prev_min[0], prev_min[1], prev_min[2] });
        cur_min[2] = c + min(prev_min[1], prev_min[2]);

        // 현재 값을 이전 값으로 업데이트
        for (int j = 0; j < 3; j++) {
            prev_max[j] = cur_max[j];
            prev_min[j] = cur_min[j];
        }
    }

    int max_answer = max({ prev_max[0], prev_max[1], prev_max[2] });
    int min_answer = min({ prev_min[0], prev_min[1], prev_min[2] });

    cout << max_answer << " " << min_answer << "\n";
}

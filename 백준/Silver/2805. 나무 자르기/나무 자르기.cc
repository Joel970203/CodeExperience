#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M; // 나무의 수, 길이
    cin >> N >> M;
    vector<int> forest(N);

    // 나무 높이 입력 받기
    int max_height = 0;
    for (int i = 0; i < N; i++) {
        cin >> forest[i];
        if (forest[i] > max_height) {
            max_height = forest[i];
        }
    }

    int start = 0;
    int end = max_height;
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        long long total_wood = 0;

        // 현재 높이에서 자르고 나서 얻는 나무의 총 길이 계산
        for (int i = 0; i < N; i++) {
            if (forest[i] > mid) {
                total_wood += (forest[i] - mid);
            }
        }

        if (total_wood >= M) {
            // 현재 높이로 충분한 나무를 얻을 수 있으면, 높이를 더 높일 수 있는지 확인
            result = mid;
            start = mid + 1;
        }
        else {
            // 현재 높이로는 충분한 나무를 얻을 수 없으므로, 높이를 낮춰야 함
            end = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}

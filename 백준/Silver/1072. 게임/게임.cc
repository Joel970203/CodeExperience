#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long X, Y;
    cin >> X >> Y;

    int Z = static_cast<int>((Y * 100) / X); // 현재 승률 계산

    // 승률이 이미 99% 이상이면 더 이상 증가할 수 없으므로 -1 출력
    if (Z >= 99) {
        cout << -1 << endl;
        return 0;
    }

    long long left = 0;
    long long right = 1e9; // 충분히 큰 값으로 초기화
    long long result = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;
        int newZ = static_cast<int>(((Y + mid) * 100) / (X + mid)); // mid번 이겼을 때의 새로운 승률

        if (newZ > Z) {
            result = mid;
            right = mid - 1; // 더 작은 값을 찾기 위해 왼쪽 범위를 탐색
        } else {
            left = mid + 1; // 더 큰 값을 찾기 위해 오른쪽 범위를 탐색
        }
    }

    cout << result << endl;

    return 0;
}
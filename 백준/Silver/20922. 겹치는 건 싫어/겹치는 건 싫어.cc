#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<int> cnt(100001, 0); // arr 값 범위: 1~100000

    int ans = 0;
    int left = 0;
    for (int right = 0; right < N; right++) {
        cnt[arr[right]]++;

        // 만약 arr[right]가 K를 넘으면 → 조건 위반
        while (cnt[arr[right]] > K) {
            cnt[arr[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans << "\n";
}

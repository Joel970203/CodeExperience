#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<int> table(N * 2);
    for (int i = 0; i < N; i++) {
        table[i] = arr[i];
        table[N + i] = arr[i];
    }

    int count = 0;
    vector<int> sushi(d + 1, 0);

    // 초기 윈도우 [0..k-1]
    for (int i = 0; i < k; i++) {
        if (sushi[table[i]] == 0) count++; // 새 종류면 증가
        sushi[table[i]]++;                 // 빈도는 항상 증가
    }

    int ans = count + (sushi[c] == 0 ? 1 : 0);

    // 슬라이딩
    for (int left = 1; left < N; left++) {
        int remove = table[left - 1];
        int add = table[left + k - 1];

        // 왼쪽 제거
        sushi[remove]--;
        if (sushi[remove] == 0) count--;

        // 오른쪽 추가
        if (sushi[add] == 0) count++;
        sushi[add]++;

        // 쿠폰 포함 여부
        ans = max(ans, count + (sushi[c] == 0 ? 1 : 0));
    }

    cout << ans << "\n";
}

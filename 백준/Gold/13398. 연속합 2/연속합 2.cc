#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // n==1 특수 처리: 삭제는 선택사항 -> a[0] 그대로
    if (n == 1) 
    {
        cout << a[0] << "\n";
        return 0;
    }

    long long dp0 = a[0];          // i에서 끝나는, 삭제 0회
    long long dp1 = LLONG_MIN / 4;   // i에서 끝나는, 삭제 1회 (초기는 불가능 상태)
    long long ans = a[0];

    for (int i = 1; i < n; ++i)
    {
        long long next_dp1 = max(dp0, dp1 + a[i]);   // (i 삭제) vs (이전 삭제+현재 포함)
        long long next_dp0 = max(a[i], dp0 + a[i]);  // 삭제 없이 이어가거나 새로 시작

        dp0 = next_dp0;
        dp1 = next_dp1;
        ans = max(ans, max(dp0, dp1));
    }

    cout << ans << "\n";
    return 0;
}

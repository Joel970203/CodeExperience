#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    // 수열 입력 받기
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // dp[i]는 i번째까지의 최대 연속합
    vector<int> dp(n);
    dp[0] = arr[0];  // 첫 번째 값 초기화
    int max_sum = dp[0];  // 최대 합 초기화

    // Kadane's Algorithm 적용
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);  // 현재 값과 이전까지의 합 중 큰 값 선택
        max_sum = max(max_sum, dp[i]);  // 최대합 갱신
    }

    // 결과 출력
    cout << max_sum << endl;

    return 0;
}
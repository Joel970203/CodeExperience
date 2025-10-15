#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<int> cnt(100001, 0);

    int ans = 0;
    int left = 0;

    for (int right = 0; right < N; right++)
    {
        cnt[arr[right]]++;

        while (cnt[arr[right]] > K)
        {
            cnt[arr[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans;
}
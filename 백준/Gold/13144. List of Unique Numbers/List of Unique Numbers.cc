#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<bool> used(100001, false); // 값의 범위는 1~100000
    long long ans = 0;
    int left = 0;

    for (int right = 0; right < N; right++) 
    {
        while (used[arr[right]]) 
        {
            used[arr[left]] = false;
            left++;
        }
        used[arr[right]] = true;
        ans += (right - left + 1);
    }

    cout << ans << "\n";
}

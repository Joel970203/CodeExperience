#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    ll best = 3e18;
    ll ans[3];

    for (int i = 0; i < N - 2; i++) {
        int left = i + 1, right = N - 1;
        while (left < right) {
            ll sum = arr[i] + arr[left] + arr[right];
            if (llabs(sum) < best) {
                best = llabs(sum);
                ans[0] = arr[i];
                ans[1] = arr[left];
                ans[2] = arr[right];
            }
            if (sum < 0) left++;
            else right--;
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}

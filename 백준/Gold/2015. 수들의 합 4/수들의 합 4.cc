#include <iostream>
#include <unordered_map>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    long long ans = 0;
    long long psum = 0;
    unordered_map<long long, long long> freq;

    freq[0] = 1; // psum - K == 0 처리용

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        psum += x;

        // psum[r] - K 가 이전에 몇 번 있었는지 누적
        if (freq.find(psum - K) != freq.end())
            ans += freq[psum - K];

        freq[psum]++;
    }

    cout << ans << "\n";
}

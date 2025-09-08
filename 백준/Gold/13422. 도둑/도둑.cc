#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M, K;
        cin >> N >> M >> K;

        vector<int> village(N);
        for (int i = 0; i < N; i++)
            cin >> village[i];

        if (N == M) 
        {
            long long total = accumulate(village.begin(), village.end(), 0LL);
            cout << (total < K ? 1 : 0) << "\n";
            continue;
        }

        int answer = 0;
        long long sum = 0;

        for (int i = 0; i < M; i++)
            sum += village[i];
        if (sum < K) answer++;

        for (int i = 1; i < N; i++) {
            sum -= village[i - 1];
            sum += village[(i + M - 1) % N];
            if (sum < K) answer++;
        }

        cout << answer << "\n";
    }
}

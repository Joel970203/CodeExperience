#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewels(N);
    for (int i = 0; i < N; ++i) {
        cin >> jewels[i].first >> jewels[i].second;
    }

    vector<int> bags(K);
    for (int i = 0; i < K; i++) {
        cin >> bags[i]; 
    }

    sort(jewels.begin(), jewels.end()); 
    sort(bags.begin(), bags.end());     

    priority_queue<int> pq;
    long long ans = 0;
    int jewelIdx = 0;

    for (int i = 0; i < K; ++i)
    {
        while (jewelIdx < N && jewels[jewelIdx].first <= bags[i]) {
            pq.push(jewels[jewelIdx].second);
            jewelIdx++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << endl;
    return 0;
}
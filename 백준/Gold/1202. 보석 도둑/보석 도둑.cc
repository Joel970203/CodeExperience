#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio();

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewels(N);  // {무게, 가격}
    vector<int> bags(K);

    for (int i = 0; i < N; i++) 
    {
        cin >> jewels[i].first >> jewels[i].second;
    }

    for (int i = 0; i < K; i++)
    {
        cin >> bags[i];
    }

    sort(jewels.begin(), jewels.end());

    sort(bags.begin(), bags.end());

    priority_queue<int> pq; 
    long long maxValue = 0;
    int j = 0;

    for (int i = 0; i < K; i++) {
        // 가방에 담을 수 있는 보석들을 힙에 삽입
        while (j < N && jewels[j].first <= bags[i]) {
            pq.push(jewels[j].second);  
            j++;
        }

        if (!pq.empty()) {
            maxValue += pq.top();
            pq.pop();
        }
    }

    cout << maxValue << "\n";
    return 0;
}

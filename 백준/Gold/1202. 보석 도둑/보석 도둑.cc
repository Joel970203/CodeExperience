#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// 배낭문제가 아니다
// 가방은 여러개이고, 보석은 한개만 넣을수있음

int main()
{
    fastio();

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewels;  // 무게 가격 
    vector<int> bags(K);

    for (int i = 0; i < N; i++)
    {
        int M, V;
        cin >> M >> V;
        jewels.push_back({ M,V });
    }

    for (int i = 0; i < K; i++)
    {
        cin >> bags[i];
    }

    sort(jewels.begin(), jewels.end()); // 무게로 정렬 

    sort(bags.begin(), bags.end()); // 가방도 무게로 정렬 

    /*
    작은 가방부터, 하나씩 넣어본다.
    */

    priority_queue<int> pq;
    long long answer = 0;
    int j = 0;

    for (int i = 0; i < K; i++) 
    {
        while (j < N && jewels[j].first <= bags[i]) // 보석 넣을수있다면 
        {
            pq.push(jewels[j].second);
            j++;
        }

        if (!pq.empty()) 
        {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << "\n";
    return 0;
}

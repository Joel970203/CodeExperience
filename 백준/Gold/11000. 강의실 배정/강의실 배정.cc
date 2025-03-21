#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> classes(N);
    for (int i = 0; i < N; i++)
    {
        cin >> classes[i].first >> classes[i].second;
    }

    sort(classes.begin(), classes.end());

    priority_queue<int, vector<int>, greater<>> pq;

    pq.push(classes[0].second);

    for (int i = 1; i < N; i++)
    {
        int start = classes[i].first;
        int end = classes[i].second;

        if (pq.top() <= start)
        {
            pq.pop(); 
        }

        pq.push(end);
    }

    cout << pq.size() << '\n';
    return 0;
}

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100001;
vector<int> dist(MAX, MAX); // 각 위치까지의 최소 시간을 저장할 배열

void dijkstra(int start, int target) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({ 0,start });

    while (!pq.empty())
    {
        int currentTime = pq.top().first;
        int currentLoc = pq.top().second;
        pq.pop();

        if (currentLoc == target) {
            return;
        }

        int nextTime;


        if (currentLoc - 1 >= 0) {
            nextTime = currentTime + 1;
            if (nextTime < dist[currentLoc - 1]) {
                dist[currentLoc - 1] = nextTime;
                pq.push({ nextTime, currentLoc - 1 });
            }
        }

        if (currentLoc + 1 < MAX) {
            nextTime = currentTime + 1;
            if (nextTime < dist[currentLoc + 1]) {
                dist[currentLoc + 1] = nextTime;
                pq.push({ nextTime, currentLoc + 1 });
            }
        }

        if (currentLoc * 2 < MAX) {
            nextTime = currentTime; // 순간이동은 0초
            if (nextTime < dist[currentLoc * 2]) {
                dist[currentLoc * 2] = nextTime;
                pq.push({ nextTime, currentLoc * 2 });
            }
        }
    }

}

int main() {
    int N, K;
    cin >> N >> K;

    if (N == K) {
        cout << 0 << endl;
    }
    else {
        dijkstra(N, K);
        cout << dist[K] << endl;
    }

    return 0;
}
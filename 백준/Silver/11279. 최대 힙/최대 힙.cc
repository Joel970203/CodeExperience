#include <iostream>
#include <vector>
#include <queue>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main() {
    fastio();

    int N;
    cin >> N;

    priority_queue<int> pq; 

    vector<int> result;
    result.reserve(N); 

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (a == 0) {
            if (pq.empty()) result.push_back(0);
            else {
                result.push_back(pq.top());
                pq.pop();
            }
        }
        else {
            pq.push(a);
        }
    }

    for (int x : result) {
        cout << x << '\n';
    }
}

#include <iostream>
#include <queue>
#include <vector>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N;
priority_queue<int> maxHeap;  
priority_queue<int, vector<int>, greater<int>> minHeap; 

void makeHeap()
{
    int num;
    cin >> num;

    if (maxHeap.empty() || num <= maxHeap.top())
    {
        maxHeap.push(num);
    }
    else
    {
        minHeap.push(num);
    }

    if (maxHeap.size() > minHeap.size() + 1)
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if (minHeap.size() > maxHeap.size())
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }

    cout << maxHeap.top() << "\n";
}

int main()
{
    fastio();
    cin >> N;

    for (int i = 0; i < N; i++)  
    {
        makeHeap();
    }

    return 0;
}

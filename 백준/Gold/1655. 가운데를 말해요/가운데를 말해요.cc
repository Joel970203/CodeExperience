#include <iostream>
#include <queue>
using namespace std;

void findMedian(int N) 
{
    priority_queue<int> leftMaxHeap; // 최대 힙 (중간값 포함, 작은 수 저장)
    priority_queue<int, vector<int>, greater<int>> rightMinHeap; // 최소 힙 (큰 수 저장)

    int num;
    for (int i = 0; i < N; i++) 
    {
        cin >> num;

        // 최대 힙이 비었거나, num이 최대 힙의 top보다 작다면 최대 힙에 삽입
        if (leftMaxHeap.empty() || num <= leftMaxHeap.top()) {
            leftMaxHeap.push(num);
        }
        else {
            rightMinHeap.push(num);
        }

        // 균형 조정 (최대 힙 크기가 최소 힙 크기보다 2 이상 크면 조정)
        if (leftMaxHeap.size() > rightMinHeap.size() + 1) {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
        else if (rightMinHeap.size() > leftMaxHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }

        // 중간값 출력 (항상 최대 힙의 top이 중간값)
        cout << leftMaxHeap.top() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    findMedian(N);

    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    queue<int> q;
    for (int i = 1; i <= N; ++i)
        q.push(i);

    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;

        int size = q.size();
        int index = 1;
        while (q.front() != num) { // 원하는 원소를 만날 때까지 반복
            q.push(q.front()); // 왼쪽으로 이동하는 연산(2번 연산)
            q.pop();
            ++index;
        }
        // 왼쪽으로 이동하는 연산(2번 연산)과 오른쪽으로 이동하는 연산(3번 연산) 중 작은 횟수 선택
        cnt += min(index - 1, size - index + 1);
        q.pop(); // 원하는 원소를 제거
    }

    cout << cnt << endl;

    return 0;
}

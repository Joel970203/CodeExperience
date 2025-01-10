#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// B 배열에서 target보다 작은 원소의 개수를 이진 탐색으로 찾음
int countLessThan(const vector<int>& B, int target) {
    int left = 0, right = B.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (B[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N), B(M);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }

        // A와 B 배열을 오름차순으로 정렬
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int result = 0;

        // A의 각 원소에 대해 B에서 자신보다 작은 원소의 개수를 카운트
        for (int i = 0; i < N; i++) {
            result += countLessThan(B, A[i]);
        }

        cout << result << endl;
    }

    return 0;
}

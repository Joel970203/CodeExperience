#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N;

    vector<int> budget(N);
    for (int i = 0; i < N; i++) {
        cin >> budget[i];
    }

    cin >> M;

    int left = 0;
    int right = *max_element(budget.begin(), budget.end());
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int sum = 0;

        for (int i = 0; i < N; i++) {
            if (budget[i] > mid)
                sum += mid;
            else
                sum += budget[i];
        }

        if (sum <= M) {
            answer = mid;  
            left = mid + 1;
        }
        else {
            right = mid - 1;  
        }
    }

    cout << answer << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canMakeRopes(const vector<int>& rope, int length, int N) {
    int count = 0;
    for (int len : rope) {
        count += len / length;
    }
    return count >= N;
}

int main() {
    int K, N;
    cin >> K >> N;
    vector<int> rope(K);

    for (int i = 0; i < K; i++) {
        cin >> rope[i];
    }

    long long start = 1;
    long long end = *max_element(rope.begin(), rope.end());
    long long result = 0;

    while (start <= end) {
        long long mid = (start + end) / 2;

        if (canMakeRopes(rope, mid, N)) {
            result = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}

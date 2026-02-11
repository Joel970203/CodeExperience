#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> weights(N);
    for (int i = 0; i < N; i++) cin >> weights[i];

    sort(weights.begin(), weights.end());

    int target = 1;
    for (int i = 0; i < N; ++i)
    {
        if (target < weights[i]) break;

        target += weights[i];
    }

    cout << target << endl;
}
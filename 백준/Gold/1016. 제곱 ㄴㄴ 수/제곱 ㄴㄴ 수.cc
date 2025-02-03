#include <iostream>
#include <vector>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
    long long min, max;

    cin >> min >> max;

    vector<bool> is_square_free(max - min + 1, true);

    for (long long i = 2; i * i <= max; i++) {
        long long square = i * i;
        long long start = (min + square - 1) / square * square;

        for (long long j = start; j <= max; j += square) {
            is_square_free[j - min] = false;
        }
    }

    int cnt = 0;
    for (bool is_free : is_square_free) {
        if (is_free) cnt++;
    }

    cout << cnt << endl;
}

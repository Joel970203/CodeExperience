#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> fruits(N);

    for (int i = 0; i < N; ++i) {
        cin >> fruits[i];
    }

    unordered_map<int, int> fruit_count;
    int max_length = 0;
    int start = 0;

    for (int end = 0; end < N; ++end) {
        fruit_count[fruits[end]]++;

        while (fruit_count.size() > 2) {
            fruit_count[fruits[start]]--;
            if (fruit_count[fruits[start]] == 0) {
                fruit_count.erase(fruits[start]);
            }
            start++;
        }

        max_length = max(max_length, end - start + 1);
    }

    cout << max_length << endl;
    return 0;
}
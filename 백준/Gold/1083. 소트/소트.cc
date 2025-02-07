#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, S;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> S;

    for (int i = 0; i < N && S > 0; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < N && j - i <= S; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }

        if (maxIdx != i) {
            for (int j = maxIdx; j > i; j--) {
                swap(arr[j], arr[j - 1]);
                S--; 
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

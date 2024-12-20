#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N + 1, 0);  
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        A[i] += A[i - 1];  
    }
    
    int count = 0;
    int left = 0;
    
    for (int right = 1; right <= N; ++right) {
        while (left < right && A[right] - A[left] > M) {
            left++;
        }
        if (A[right] - A[left] == M) {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}
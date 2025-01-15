#include <iostream>
#include <vector>

using namespace std;

int T, K;
vector<int> dp0(41, -1); 
vector<int> dp1(41, -1); 

void fibonacci() {
    dp0[0] = 1; 
    dp1[0] = 0; 
    dp0[1] = 0; 
    dp1[1] = 1; 

    for (int i = 2; i <= 40; ++i) {
        dp0[i] = dp0[i - 1] + dp0[i - 2];
        dp1[i] = dp1[i - 1] + dp1[i - 2];
    }
}

int main() {
    cin >> T;

    fibonacci();

    while (T--) {
        cin >> K;
        cout << dp0[K] << " " << dp1[K] << endl;
    }

    return 0;
}
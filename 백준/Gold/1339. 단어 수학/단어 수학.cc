#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int res;
int alpha[26];

bool comp(string a, string b) {
    return a.length() > b.length();
}

int main(void) {
    int N;
    cin >> N;
    vector<string> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < v.size(); i++) {
        int pow = 1;
        for (int j = v[i].size() - 1; j >= 0; j--) {
            int val = v[i][j] - 'A';
            alpha[val] += pow;
            pow *= 10;
        }
    }
    sort(alpha, alpha + 26);

    int num = 9;
    for (int i = 25; i >= 0; i--) {
        if (!alpha[i]) break;
        res += (alpha[i] * num);
        num--;
    }
    cout << res << '\n';
    return 0;
}
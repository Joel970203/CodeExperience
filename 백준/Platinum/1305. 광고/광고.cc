#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPi(string& T) {
    int len = T.length();
    vector<int> pi(len, 0);
    int j = 0;
    for (int i = 1; i < len; i++) {
        while (j > 0 && T[i] != T[j])
            j = pi[j - 1];
        if (T[i] == T[j])
            pi[i] = ++j;
    }
    return pi;
}

int main() 
{
    int L;
    string T;
    cin >> L >> T;

    vector<int> pi = getPi(T);
    cout << L - pi[L - 1] << "\n";
}

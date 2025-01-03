#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<int>> ans(len1 + 1, vector<int>(len2 + 1, 0));

    // DP 테이블 계산
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                ans[i][j] = ans[i - 1][j - 1] + 1;
            }
            else {
                ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
            }
        }
    }

    // LCS 길이 출력
    cout << ans[len1][len2] << endl;

    // LCS 복원
    string lcs = "";
    int i = len1, j = len2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs += str1[i - 1]; // 공통 문자 추가
            i--;
            j--;
        }
        else if (ans[i - 1][j] > ans[i][j - 1]) {
            i--; // 위로 이동
        }
        else {
            j--; // 왼쪽으로 이동
        }
    }

    reverse(lcs.begin(), lcs.end());
    if (!lcs.empty()) {
        cout << lcs << endl;
    }

    return 0;
}
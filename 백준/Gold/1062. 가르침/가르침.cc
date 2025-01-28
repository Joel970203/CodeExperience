#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> words;
vector<bool> alphabet(26);
int N, K, maxWords = 0;

int countReadableWords() {
    int count = 0;
    for (const string& word : words) {
        bool readable = true;
        for (char c : word) {
            if (!alphabet[c - 'a']) {
                readable = false;
                break;
            }
        }
        if (readable) count++;
    }
    return count;
}

void dfs(int idx, int learned) {
    if (learned == K - 5) {  
        maxWords = max(maxWords, countReadableWords());
        return;
    }

    for (int i = idx; i < 26; i++) {
        if (!alphabet[i]) {
            alphabet[i] = true; 
            dfs(i + 1, learned + 1);
            alphabet[i] = false;
        }
    }
}

int main() {
    cin >> N >> K;

    if (K < 5) {  // 기본 필수 글자가 없으면 읽을 수 있는 단어가 없음
        cout << 0 << endl;
        return 0;
    }

    words.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
        words[i] = words[i].substr(4, words[i].size() - 8);  // "anta"와 "tica" 제거
    }

    // 필수 알파벳 "a, n, t, i, c"를 미리 배운 것으로 설정
    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['c' - 'a'] = true;

    dfs(0, 0);

    cout << maxWords << endl;
    return 0;
}

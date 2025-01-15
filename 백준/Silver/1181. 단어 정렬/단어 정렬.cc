#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 사용자 정의 비교 함수
bool compare(const string& a, const string& b) {
    if (a.length() == b.length()) {
        return a < b; // 길이가 같으면 사전 순으로 정렬
    }
    return a.length() < b.length(); // 길이가 짧은 것부터 정렬
}

int main() {
    int N;
    cin >> N;
    vector<string> words(N);

    // 단어 입력
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    // 먼저 사전 순으로 정렬하여 중복을 제거하기 쉽게 한다
    sort(words.begin(), words.end());

    // unique로 중복을 제거하고 끝 부분의 반복자를 얻는다
    auto last = unique(words.begin(), words.end());

    // 벡터의 크기를 중복이 제거된 범위로 줄인다
    words.erase(last, words.end());

    // 이제 길이에 따라 정렬한다
    sort(words.begin(), words.end(), compare);

    // 결과 출력
    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}
#include <vector>
#include <algorithm>  // sort 사용
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> cnt(3, 0);  

    int n = answers.size();
    
    for (int i = 0; i < n; i++) {
        if (answers[i] == (i % 5) + 1) {
            cnt[0]++;
        }
        
        int m2_pattern[] = {2, 1, 2, 3, 2, 4, 2, 5};
        if (answers[i] == m2_pattern[i % 8]) {
            cnt[1]++;
        }

        int m3_pattern[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        if (answers[i] == m3_pattern[i % 10]) {
            cnt[2]++;
        }
    }

    int maxScore = max({cnt[0], cnt[1], cnt[2]});

    for (int i = 0; i < 3; i++) {
        if (cnt[i] == maxScore)
            answer.push_back(i + 1);
    }

    return answer;
}

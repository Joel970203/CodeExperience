#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> used;

    for(int i = 0; i < words.size(); i++) {
        if(i > 0 && words[i][0] != words[i-1].back()) 
        {
            answer.push_back((i % n) + 1);      // 사람 번호 (1부터 시작)
            answer.push_back((i / n) + 1);      // 몇 번째 차례
            return answer;
        }

        // 중복 단어 사용
        if(used.count(words[i]))
        {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            return answer;
        }

        used.insert(words[i]);
    }

    return {0, 0};
}

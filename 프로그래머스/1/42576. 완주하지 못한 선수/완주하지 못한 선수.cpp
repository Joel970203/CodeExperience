#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";
    unordered_map<string,int> part;
    for (const auto& name : participant) {
        part[name]++;
    }
    
    for (const auto& name : completion) {
        part[name]--;
    }
    
    for (const auto& name : part) {
        if (name.second > 0) {  // 완주하지 못한 참가자 찾기
            answer = name.first;
            break;
        }
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(const pair<int, float>& a, const pair<int, float>& b) {
    if (a.second == b.second) {
        return a.first < b.first; 
    }
    return a.second > b.second; 
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, int> stage_count; 
    vector<pair<int, float>> failure_rate; 
    
    for (int stage : stages) {
        if (stage <= N) {
            stage_count[stage]++;
        }
    }
    
    float total_users = stages.size(); 
    for (int i = 1; i <= N; i++) {
        if (stage_count[i] > 0) {

            float fail_rate = stage_count[i] / total_users;
            failure_rate.push_back({i, fail_rate});
            total_users -= stage_count[i]; 
        } else {

            failure_rate.push_back({i, 0});
        }
    }
    
    sort(failure_rate.begin(), failure_rate.end(), cmp);
    
    for (const auto& stage : failure_rate) {
        answer.push_back(stage.first);
    }
    
    return answer;
}
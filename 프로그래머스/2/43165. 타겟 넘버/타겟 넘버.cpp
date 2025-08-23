#include <vector>
using namespace std;

int answer;

void dfs(const vector<int>& numbers, int idx, int sum, int target)
{
    if (idx == (int)numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    dfs(numbers, idx + 1, sum + numbers[idx], target);
    dfs(numbers, idx + 1, sum - numbers[idx], target);
}

int solution(vector<int> numbers, int target) {
    answer = 0;                
    dfs(numbers, 0, 0, target);
    return answer;
}

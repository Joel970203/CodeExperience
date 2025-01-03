#include <string>
#include <vector>

using namespace std;

int total = 0;

void DFS(vector<int> &numbers, int &target, int cnt, int idx)
{
    if(idx >= numbers.size())
    {
        if(cnt == target) total++;
        return;
    }
    DFS(numbers, target, cnt+numbers[idx], idx+1);
    DFS(numbers, target, cnt-numbers[idx], idx+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(numbers,target,numbers[0],1);
    DFS(numbers,target,-numbers[0],1);
    answer = total;
    return answer;
}
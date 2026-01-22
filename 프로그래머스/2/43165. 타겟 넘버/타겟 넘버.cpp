#include <string>
#include <vector>

using namespace std;

int answer = 0;

/*
모든 경우의수를 카운팅하는데, 재귀로 풀면될것 같다.
+/- 로 돌리면 될듯 
*/

void DFS(const vector<int> &arr,int target,int idx,int sum)
{
    if(idx+1 == (int)arr.size())
    {
        if(sum == target)  
        {
            answer++;
            return;
        }
        
        else return;
    }
    
    DFS(arr,target,idx+1,sum+arr[idx+1]);
    DFS(arr,target,idx+1,sum-arr[idx+1]);

    return;
}

int solution(vector<int> numbers, int target) 
{
    DFS(numbers,target,-1,0);
    return answer;
}
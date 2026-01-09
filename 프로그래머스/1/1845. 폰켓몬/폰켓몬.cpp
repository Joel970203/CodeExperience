#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


/*
n개의 선택지가 주어지고, 중복이 있음 
내가 가져갈수있는 최대 갯수는 n/2 개.
n/2개를 고를때, 종류가 최대인 방법?
결과적으로, 입력을 받을때, map으로 받아서 카운팅 
3 1 2 3 의 경우는 
3(2) 1(1) 2(1) 


3 3 3 2 2 4 
3(3) 2(2) 4(1) 

복잡하게 생각할거 없이, n/2 갯수보다 , 종류의 갯수가 많다면 n/2가 답이고 
n/2 갯수보다 , 종류의 갯수가 적다면 종류의 갯수가 답 아닌가 ? 


*/
int solution(vector<int> nums) 
{
    int maxNum = nums.size() / 2;
    int answer = 0;
    unordered_map<int,int> mp;
    
    for(int i=0;i<nums.size();++i)
    {
        int uniq = nums[i];
        mp[uniq]++;
    }
    
    answer = min(maxNum,(int)mp.size());
    return answer;
    
}
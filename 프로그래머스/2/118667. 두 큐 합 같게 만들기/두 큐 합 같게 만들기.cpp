#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long target = 0;
    long long sum1 = 0 ,sum2 = 0;
    vector<int> ans;
    
    for(int i=0;i<queue1.size();++i)
    {
        target += queue1[i];
        sum1 += queue1[i];
    }
        
    for(int i=0;i<queue2.size();++i)
    {
        target += queue2[i];
        sum2 += queue2[i];
    }
    
    target /= 2;
    
    if(sum1 > sum2)
    {
        for(int i=0;i<queue2.size();++i)
        {
            ans.push_back(queue2[i]);
        }
        
        for(int i=0;i<queue1.size();++i)
        {
            ans.push_back(queue1[i]);
        }
        
        int start = 0;
        int end = queue2.size();
        
        for(int j = end; j < queue1.size() + queue2.size(); ++j)
        {
            sum2 += ans[j];

            while(sum2 > target)
            {
                sum2 -= ans[start];
                start++;
                answer++;
            }     
            
            answer++;
            if(sum2 == target) return answer;
        }
        
        return -1;
    }
    
    else if (sum1 == sum2) return 0;
    
    else
    {
        for(int i=0;i<queue1.size();++i)
        {
            ans.push_back(queue1[i]);
        }
        
        for(int i=0;i<queue2.size();++i)
        {
            ans.push_back(queue2[i]);
        }
        
        int start = 0;
        int end = queue1.size();
        
        for(int j = end; j < queue1.size() + queue2.size(); ++j)
        {
            
            sum1 += ans[j];
            
            while(sum1 > target)
            {
                sum1 -= ans[start];
                start++;
                answer++;
            }
            
            answer++;
            if(sum1 == target) return answer;
        }
        
        return -1; 
    }
}
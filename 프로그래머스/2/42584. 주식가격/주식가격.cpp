#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
직관적으로는 stack을 사용해야할것 같은 감이 오는데 

stack에 1이 있다고 가정 
2가 들어오면 top하고 비교 
top 보다 크면 그냥 push

top보다 작으면? pop하고 그위치는 1
그리고 그 다음 top하고 비교, 작다면 while문 
크다면 멈춤 마지막 원소도 똑같이 비교하고, 끝났을떄 
pop연속으로 하면서 벡터 채우기 
*/

vector<int> solution(vector<int> prices) 
{
    int cnt = prices.size();
    vector<int> answer(cnt,0);
    stack<pair<int,int>> st;
    
    for(int i=0; i<cnt; ++i)
    {
        if(st.empty())
        {
            st.push({prices[i],i});
        }
        
        else
        {
            if(prices[i] >= st.top().first) // 안떨어진 경우 
            {
                st.push({prices[i],i});
            }
            
            else // 떨어진 경우 
            {
                while(!st.empty() &&prices[i] < st.top().first)
                {
                    int idx = st.top().second;
                    answer[idx] = i - idx;
                    st.pop();
                }
                st.push({prices[i],i});
            }
        }
    }
    
    
    int time = -1;
    while(!st.empty())
    {
        if(time == -1)
        {
            time = st.top().second;
        }
        
        int idx = st.top().second;
        answer[idx] = time - idx;
        st.pop();
    }
    
    return answer;
}
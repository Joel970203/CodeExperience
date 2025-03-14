#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) 
{
    int answer = 0;
    stack<int> st; 
    
    int index = 0;  
    int n = order.size();
    
    for (int i = 1; i <= n; i++) 
    { 
        if (i == order[index]) 
        { 
            answer++;
            index++;
        } 
        else 
        {  
            st.push(i);
        }

        while (!st.empty() && st.top() == order[index])
        {
            st.pop();
            answer++;
            index++;
        }
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    int n = prices.size();
    vector<int> answer(n);
    stack<int> st;

    for (int i = 0; i < n; ++i) 
    {
        while (!st.empty() && prices[st.top()] > prices[i])
        {
            int idx = st.top();
            st.pop();
            answer[idx] = i - idx;
        }
        st.push(i);
    }

    while (!st.empty()) 
    {
        int idx = st.top();
        st.pop();
        answer[idx] = n - 1 - idx;
    }

    return answer;
}

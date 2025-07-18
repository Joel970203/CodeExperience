#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    
    stack<char> st;
    if(s[0] != '(' || s[-1] == ')') return false;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(')
        {
            st.push(s[i]);
        }
        
        else
        {
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
            }
        }
    }
    
    if(st.empty()) answer = true;
    return answer;
}
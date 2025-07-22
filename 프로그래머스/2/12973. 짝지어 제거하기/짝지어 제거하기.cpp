#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    
    for(int i=0;i<s.length();i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
        }
        
        else
        {
            if(st.top() == s[i])
            {
                st.pop();
            }
            
            else
            {
                st.push(s[i]);
            }
        }
    }
    
    return st.empty();
}
#include <string>
#include <stack>
using namespace std;

// 올바른 괄호 문자열인지 확인
bool isValid(const string& p) 
{
    stack<char> st;
    for (char c : p) 
    {
        if (c == '(') 
        {
            st.push(c);
        } 
        
        else 
        {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

// 균형잡힌 문자열로 분리
pair<string, string> splitUV(const string& p)
{
    int open = 0, close = 0;
    for (size_t i = 0; i < p.length(); ++i)
    {
        if (p[i] == '(') 
            ++open;
        else 
            ++close;

        if (open == close) 
        {
            return {p.substr(0, i + 1), p.substr(i + 1)};
        }
    }
    return {p, ""};
}

string solution(string p) 
{
    if (p.empty()) return "";
    auto [u, v] = splitUV(p);
    
    if (isValid(u)) 
    {
        return u + solution(v); 
    } 
    
    else 
    {
        string result = "(" + solution(v) + ")";
        for (size_t i = 1; i < u.length() - 1; ++i) 
        {
            result += (u[i] == '(' ? ')' : '('); 
        }
        return result;
    }
}

#include <string>
#include <vector>
#include <stack>
#include <unordered_map>


using namespace std;

unordered_map <char,char> bracket = 
{
    {')','('},
    {']','['},
    {'}','{'}
};

bool isValid(int start,string &s)
{
     stack<char> st;
     int value = s.length();
    
     for(int i=0; i<value; ++i)
     {
         char tmp = s[(i+start)%value];
         
         if(bracket.count(tmp))
         {
             if(st.top() != bracket[tmp] || st.empty())
             {
                 return false;
             }
             st.pop();
         }
         
         else
         {
             st.push(tmp);
         }
     }
    
     return st.empty();
}

int solution(string s) 
{
    int answer = 0;
    for(int i=0;i<s.length();i++)
    {
        if(isValid(i,s)) answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(string number, int k) 
{
    string answer = ""; 
    vector<char> stack; 
    int toRemove = k;   

    for (char digit : number) 
    {
        while (!stack.empty() && toRemove > 0 && stack.back() < digit)
        {
            stack.pop_back();
            toRemove--;    
        }
        stack.push_back(digit); 
    }
   
    while (toRemove > 0) 
    {
        stack.pop_back();
        toRemove--;
    }
    
    for (char digit : stack) 
    {
        answer += digit;
    }

    return answer;
}

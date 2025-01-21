#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    for(int i=1;i<food.size();i++)
    {
        int su = food[i] / 2;
        
        for(int j=0;j<su;j++)
        {
            temp += to_string(i);
            answer += to_string(i);
        }
    }
    
    answer += '0';
    
    for(int i=temp.size()-1;i>=0;i--)
    {
        answer += temp[i];
    }
    
    return answer;
}
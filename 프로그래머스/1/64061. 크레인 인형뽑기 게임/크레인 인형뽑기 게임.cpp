#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    stack<int> st;
    for(int i=0;i<moves.size();i++)
    {
        int idx = moves[i] - 1; 
        for(int j=0;j<board.size();j++)
        {
            int value = board[j][idx];
            if(value == 0) continue;
            
            else
            {
                if(st.empty())
                {
                    st.push(value);
                }
                
                else
                {
                    if(st.top() == value)
                    {
                        st.pop();
                        answer += 2;
                    }
                    
                    else
                    {
                        st.push(value);
                    }
                }
                
                board[j][idx] = 0;
                break;
            }
        }
    }
    
    return answer;
}
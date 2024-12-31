#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int solution(string s) {
    string cmp;
    string next_cmp;
    stack<string> st;
    int minimum = 1e9;
    for (int i = 1; i < s.length() - 1; i++) // 1개 짜르는거부터, s.length()-1 개 까지 짤라보자.
    {
        int cnt = 1;
        string new_s = "";
        for (int j = 0; j < s.length(); j += i)
        {
            cmp = s.substr(j, i);

            if (st.empty()) // 아예 비어있는경우 
            {
                st.push(cmp);
            }
            
            else // 뭔가 있는 경우 
            {
                if (st.top() == cmp) // 전 문자와 같으면 cnt ++ 
                {
                    st.push(cmp);
                    cnt++;
                }

                else
                {
                    if (cnt > 1) // 전문자와 다른데, 전문자들이 겹쳐있던 애들인 경우 
                    {
                        string num = to_string(cnt);
                        new_s += num;
                        new_s += st.top();
                        while (!st.empty())
                        {
                            st.pop();
                        }
                        st.push(cmp);
                        cnt = 1;
                    }
                    else // 전문자와 다르고, 전 문자가 겹쳐있던 애들도 아닌경우 
                    {
                        new_s += st.top();
                        while (!st.empty())
                        {
                            st.pop();
                        }
                        st.push(cmp);
                    }
                }
            }
        }

        int su = 0;
        string q = st.top();
        while (!st.empty())
        {
            st.pop();
            su++;
        }
        string su2 = to_string(su);
        if (su > 1)
        {
            new_s += su2;
        }
        new_s += q;

        int k = new_s.length();
        minimum = min(minimum, k);
        
        

    }
    if(minimum == 1e9)
    {
        return 1;
    }
    return minimum;
}
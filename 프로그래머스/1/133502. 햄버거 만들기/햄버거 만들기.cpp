#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> st;

    for (int i = 0; i < ingredient.size(); i++) {
        st.push(ingredient[i]);

        if (st.size() >= 4) {
            int first = st.top(); st.pop();
            int second = st.top(); st.pop();
            int third = st.top(); st.pop();
            int fourth = st.top(); st.pop();

            if (fourth == 1 && third == 2 && second == 3 && first == 1) {
                answer++;
            } else {
                st.push(fourth);
                st.push(third);
                st.push(second);
                st.push(first);
            }
        }
    }

    return answer;
}

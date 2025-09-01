#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    stack<pair<int, int>> st;  // {height, count}
    long long answer = 0;

    for (int i = 0; i < N; i++) 
    {
        int h;
        cin >> h;
        int cnt = 1;

        // 자기보다 작은 애들 pop
        while (!st.empty() && st.top().first < h) 
        {
            answer += st.top().second;
            st.pop();
        }

        // 자기랑 같은 키
        if (!st.empty() && st.top().first == h) {
            int c = st.top().second;
            answer += c;   // 같은 키끼리 다 볼 수 있음
            st.pop();
            cnt += c;      // 묶어서 관리

            if (!st.empty()) answer++; // 뒤에 더 큰 애 하나는 또 볼 수 있음
        }
        else {
            if (!st.empty()) answer++; // 자기보다 큰 애 하나는 볼 수 있음
        }

        st.push({ h, cnt });
    }

    cout << answer << "\n";
}
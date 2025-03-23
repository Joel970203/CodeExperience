#include <iostream>
#include <vector>
#include <stack>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main() {
    fastio();
    int N;
    cin >> N;

    vector<int> heights(N);
    vector<int> answer(N, 0); 
    stack<pair<int, int>> st; 

    for (int i = 0; i < N; ++i) {
        cin >> heights[i];

        while (!st.empty() && st.top().first < heights[i]) 
        {
            st.pop(); 
        }

        if (!st.empty()) 
        {
            answer[i] = st.top().second; 
        }

        st.push({ heights[i], i + 1 }); 
    }

    for (int i = 0; i < N; ++i) 
    {
        cout << answer[i] << ' ';
    }

    return 0;
}

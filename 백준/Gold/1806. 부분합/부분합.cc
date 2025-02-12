#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main()
{
    fastio();
    int N, S;
    cin >> N >> S;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }

    int left = 0, right = 0;
    int sum = 0, minLength = N + 1; 


    while (right < N) 
    {
        sum += arr[right];  

        while (sum >= S)
        {  
            minLength = min(minLength, right - left + 1);
            sum -= arr[left];
            left++;
        }

        right++;  
    }

    // 최소 길이가 갱신되지 않았다면 (즉, 합 >= S를 만드는 것이 불가능하면) 0 출력
    cout << (minLength == N + 1 ? 0 : minLength) << '\n';
}

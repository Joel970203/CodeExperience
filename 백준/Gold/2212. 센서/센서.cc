#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<int> dif;
    for (int i = 0; i < N - 1; i++)
    {
        dif.push_back(arr[i + 1] - arr[i]);
    }

    sort(dif.begin(), dif.end(), greater<int>()); // 큰 간격부터 정렬

    int answer = arr[N - 1] - arr[0]; // 전체 길이
    for (int i = 0; i < K - 1 && i < dif.size(); i++) // 큰 간격 K-1개 제거
    {
        answer -= dif[i];
    }

    cout << answer << "\n";
}

#include <iostream>
#include <vector>
#include <algorithm>

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

bool my_bs(const vector<int>& arr, int num)
{
    int start = 0;
    int end = (int)arr.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == num) return true;
        else if (num > arr[mid]) start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

int main()
{
    fastio();

    int N, M;
    cin >> N;

    vector<int> arr;
    arr.reserve(N);

    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }

    sort(arr.begin(), arr.end());

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        cout << (my_bs(arr, k) ? 1 : 0) << '\n';
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> arr;

bool chk(int mid, int C)
{
    int cnt = 1;
    int last = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - last >= mid)
        {
            cnt++;
            last = arr[i];
        }
    }

    return cnt >= C;
}

int main() 
{
    int N, C;
    cin >> N >> C;

    arr.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = 1;
    int right = arr[N-1] - arr[0];
    int ans = 0;


    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (chk(mid, C))
        {
            ans = mid;
            left = mid + 1;
        }

        else right = mid - 1;
       
    }

    cout << ans;
    return 0;

}

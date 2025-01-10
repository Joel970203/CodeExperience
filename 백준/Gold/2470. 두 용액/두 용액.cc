#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> acid(N);
    for (int i = 0; i < N; i++)
    {
        cin >> acid[i];
    }

    sort(acid.begin(), acid.end());  

    int left = 0;
    int right = N - 1;
    long long closest_sum = acid[left] + acid[right];
    int best_left = left;
    int best_right = right;

    while (left < right)
    {
        long long current_sum = acid[left] + acid[right];

        if (abs(current_sum) < abs(closest_sum))
        {
            closest_sum = current_sum;
            best_left = left;
            best_right = right;
        }

        if (current_sum < 0)
        {
            left++;
        }
        else if (current_sum > 0)
        {
            right--;
        }
        else
        {
            // current_sum이 0인경우, 답.
            break;
        }
    }

    cout << acid[best_left] << " " << acid[best_right] << endl;

    return 0;
}
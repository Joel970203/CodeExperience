#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> number(N);

    for (int i = 0; i < N; i++)
    {
        cin >> number[i];
    }

    sort(number.begin(), number.end());  

    int count = 0;  

    for (int i = 0; i < N; i++)
    {
        long long current = number[i];
        int left = 0;
        int right = N - 1;

        while (left < right)
        {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }

            long long sum = number[left] + number[right];

            if (sum == current)
            {
                count++;
                break;
            }
            else if (sum < current)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    cout << count << endl;

    return 0;
}


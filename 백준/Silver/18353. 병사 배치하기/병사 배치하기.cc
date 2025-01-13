#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> soldiers(N);
    vector<int> lis; 

    for (int i = 0; i < N; i++)
    {
        cin >> soldiers[i];
    }

    for (int i = 0; i < N; i++) {
        if (lis.empty() || lis.back() > soldiers[i]) 
        {
            lis.push_back(soldiers[i]);
        }
 
        else {
            *upper_bound(lis.begin(), lis.end(), soldiers[i], greater<int>()) = soldiers[i];
        }
    }

    // 열외해야 하는 병사의 수 출력
    cout << N - lis.size() << endl;

    return 0;
}

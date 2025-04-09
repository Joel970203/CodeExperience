#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int value_max = 0;
vector<int> loose;
vector<int> happy;

void back_track(int hp, int joy, int idx)
{

    if (hp <= 0)
        return;

    value_max = max(value_max, joy);

    for (int i = idx; i < N; i++)
    {
        if (hp - loose[i] > 0)
        {
            back_track(hp - loose[i], joy + happy[i], i + 1);
        }
    }
}

int main()
{
    cin >> N;
    loose.resize(N);
    happy.resize(N);

    for (int i = 0; i < N; i++)
        cin >> loose[i];
    for (int i = 0; i < N; i++)
        cin >> happy[i];

    back_track(100, 0, 0);

    cout << value_max << endl;
    return 0;
}

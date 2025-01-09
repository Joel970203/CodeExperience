#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int k;
    cin >> k;

    vector<int> vec(k);
    vector<int> lis;

    for (int i = 0; i < k; i++) 
    {
        cin >> vec[i];
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (lis.empty() || lis.back() < vec[i]) 
        {
            lis.push_back(vec[i]);
        }
        else 
        {
            *lower_bound(lis.begin(), lis.end(), vec[i]) = vec[i];
        }
    }

    cout << lis.size() << endl;

    return 0;
}

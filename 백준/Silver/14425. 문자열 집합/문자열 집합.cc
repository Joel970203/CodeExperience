#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    int N, M;
    int ans = 0;
    cin >> N >> M;

    unordered_set<string> s;  
    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        s.insert(a);  
    }

    for (int i = 0; i < M; i++)
    {
        string a;
        cin >> a;
        if (s.find(a) != s.end()) 
        {
            ans++;  
        }
    }

    cout << ans << endl; 
    return 0;
}

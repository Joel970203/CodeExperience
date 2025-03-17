#include <iostream>
#include <set>

using namespace std;

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int k;
        cin >> k;

        multiset<int> pq; 

        while (k--) 
        {
            char op;
            int n;
            cin >> op >> n;

            if (op == 'I') 
            {
                pq.insert(n);
            }
            else if (op == 'D' && !pq.empty()) 
            {
                if (n == 1) 
                {  
                    auto it = prev(pq.end());
                    pq.erase(it);
                }
                else if (n == -1) 
                {  
                    pq.erase(pq.begin());
                }
            }
        }

        if (pq.empty()) 
        {
            cout << "EMPTY\n";
        }
        else 
        {
            cout << *pq.rbegin() << " " << *pq.begin() << "\n";
        }
    }

    return 0;
}

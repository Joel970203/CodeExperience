#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() 
{

    int T;
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;

        list<char> password;
        auto cursor = password.begin();

        for (char ch : s) 
        {
            if (ch == '<') 
            {
                if (cursor != password.begin())
                    --cursor;
            }
            else if (ch == '>') 
            {
                if (cursor != password.end())
                    ++cursor;
            }
            else if (ch == '-') 
            {
                if (cursor != password.begin())
                    cursor = password.erase(--cursor);
            }
            else
            {
                cursor = password.insert(cursor, ch);
                ++cursor;
            }
        }

        for (char c : password)
            cout << c;
        cout << '\n';
    }

    return 0;
}

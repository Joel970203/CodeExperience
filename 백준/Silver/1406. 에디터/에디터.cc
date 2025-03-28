#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    int m;
    cin >> str;
    cin >> m;

    list<char> editor(str.begin(), str.end());
    auto cursor = editor.end();

    while (m--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (cursor != editor.begin()) {
                --cursor;
            }
        }
        else if (cmd == 'D') {
            if (cursor != editor.end()) {
                ++cursor;
            }
        }
        else if (cmd == 'B') {
            if (cursor != editor.begin()) {
                cursor = editor.erase(--cursor);
            }
        }
        else if (cmd == 'P') {
            char ch;
            cin >> ch;
            editor.insert(cursor, ch);
        }
    }

    for (char ch : editor) {
        cout << ch;
    }
    cout << '\n';

    return 0;
}

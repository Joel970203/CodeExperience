#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct File 
{
    string head;
    int number;
    string original;
};

string toLower(string s)
{
    for (auto &c : s) c = tolower(c);
    return s;
}

bool compare(const File &a, const File &b)
{
    string headA = toLower(a.head);
    string headB = toLower(b.head);

    if (headA != headB)
        return headA < headB;

    if (a.number != b.number)
        return a.number < b.number;

    return false; // stable_sort 유지 → 원래 순서 보존
}

vector<string> solution(vector<string> files)
{
    vector<File> parsed;

    for (auto &f : files)
    {
        int i = 0, n = f.size();

        while (i < n && !isdigit(f[i])) i++;
        string head = f.substr(0, i);

        int j = i;
        while (j < n && isdigit(f[j]) && j - i < 5) j++;
        string numStr = f.substr(i, j - i);

        int num = stoi(numStr);

        parsed.push_back({ head, num, f });
    }

    stable_sort(parsed.begin(), parsed.end(), compare);

    vector<string> answer;
    for (auto &p : parsed)
        answer.push_back(p.original);

    return answer;
}

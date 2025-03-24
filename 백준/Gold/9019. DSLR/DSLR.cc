#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int D(int n) { return (n * 2) % 10000; }
int S(int n) { return n == 0 ? 9999 : n - 1; }
int L(int n) { return (n % 1000) * 10 + n / 1000; }
int R(int n) { return (n % 10) * 1000 + (n / 10); }

void BFS(int A, int B)
{
    vector<bool> visited(10000, false);
    vector<string> command(10000, "");
    queue<int> q;

    visited[A] = true;
    q.push(A);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == B)
        {
            cout << command[cur] << '\n';
            return;
        }

        int next;

        next = D(cur);
        if (!visited[next])
        {
            visited[next] = true;
            command[next] = command[cur] + "D";
            q.push(next);
        }

        next = S(cur);
        if (!visited[next])
        {
            visited[next] = true;
            command[next] = command[cur] + "S";
            q.push(next);
        }

        next = L(cur);
        if (!visited[next])
        {
            visited[next] = true;
            command[next] = command[cur] + "L";
            q.push(next);
        }

        next = R(cur);
        if (!visited[next])
        {
            visited[next] = true;
            command[next] = command[cur] + "R";
            q.push(next);
        }
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int A, B;
        cin >> A >> B;
        BFS(A, B);
    }

    return 0;
}

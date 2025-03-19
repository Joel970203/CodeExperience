#include <iostream>
#include <vector>

using namespace std;

vector<int> prime;
int N, cnt = 0;

bool isPrime(int N)
{
    if (N < 2) return false;
    if (N == 2 || N == 3) return true;
    if (N % 2 == 0 || N % 3 == 0) return false;
    for (int i = 5; i * i <= N; i += 6)
    {
        if (N % i == 0 || N % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

void getPrime(int N) 
{
    if (N >= 2) prime.push_back(2);
    if (N >= 3) prime.push_back(3);

    for (int i = 5; i <= N; i += 6)
    {
        if (isPrime(i)) prime.push_back(i);
        if (i + 2 <= N && isPrime(i + 2)) prime.push_back(i + 2);
    }
}

int main()
{
    cin >> N;
    getPrime(N);

    
    int start = 0;
    int end = 0;
    int sum = 0;
    if (isPrime(N) == true)
    {
        cnt++;
    }
    while (end < prime.size())
    {
        if (sum < N)
        {
            sum += prime[end];
            end++;
        }

        else if (sum > N)
        {
            sum -= prime[start];
            start++;
        }

        else
        {
            cnt++;
            sum -= prime[start];
            start++;
        }
    }
   
    cout << cnt << endl;
}

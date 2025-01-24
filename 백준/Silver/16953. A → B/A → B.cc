#include <iostream>
using namespace std;

int findMinOperations(long long A, long long B) {
    int operations = 0;

    while (B > A)
    {
        if (B % 10 == 1) {
            B /= 10;
        }
        else if (B % 2 == 0) 
        {
            B /= 2;
        }
        else 
        {
            return -1;
        }
        operations++;
    }

    return (B == A) ? operations + 1 : -1;
}

int main() {
    long long A, B;
    cin >> A >> B;

    int result = findMinOperations(A, B);
    cout << result << endl;

    return 0;
}

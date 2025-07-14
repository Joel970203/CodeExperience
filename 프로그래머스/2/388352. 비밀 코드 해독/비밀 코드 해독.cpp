#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int count = 0;

    vector<int> pool;
    for (int i = 1; i <= n; ++i) pool.push_back(i);

    vector<bool> mask(n, false);
    fill(mask.begin(), mask.begin() + 5, true);

    do {
        vector<int> candidate;
        for (int i = 0; i < n; ++i)
            if (mask[i]) candidate.push_back(pool[i]);

        bool valid = true;
        for (int i = 0; i < q.size(); ++i) {
            int matched = 0;
            for (int x : q[i]) {
                if (find(candidate.begin(), candidate.end(), x) != candidate.end())
                    ++matched;
            }
            if (matched != ans[i]) {
                valid = false;
                break;
            }
        }

        if (valid) ++count;

    } while (prev_permutation(mask.begin(), mask.end()));

    return count;
}

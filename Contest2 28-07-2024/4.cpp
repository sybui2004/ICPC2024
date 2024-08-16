#include <bits/stdc++.h>

using namespace std;

int main() {
    int D, N;
    cin >> D >> N;
    vector<int> passwords(N);
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        int bitmask = 0;
        for (int j = 0; j < D; ++j) {
            if (s[j] == '1') {
                bitmask |= (1 << j);
            }
        }
        passwords[i] = bitmask;
    }

    int total_states = (1 << D);
    vector<int> dp(total_states, INT_MAX);
    dp[0] = 0;

    for (int mask = 0; mask < total_states; ++mask) {
        if (dp[mask] == INT_MAX) continue;

        // Try pressing each button
        for (int i = 0; i < D; ++i) {
            int new_mask = mask | (1 << i);
            dp[new_mask] = min(dp[new_mask], dp[mask] + 1);
        }

        // Try pressing the RESET button
        dp[0] = min(dp[0], dp[mask] + 1);
    }

    // Find the minimum steps to cover all passwords
    int result = INT_MAX;
    for (int mask = 0; mask < total_states; ++mask) {
        bool all_covered = true;
        for (int password : passwords) {
            if ((mask & password) != password) {
                all_covered = false;
                break;
            }
        }
        if (all_covered) {
            result = min(result, dp[mask]);
        }
    }

    cout << result << endl;

    return 0;
}

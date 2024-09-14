#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5001;

vector<pair<int, int>> dp(MAXN);

void process()
{
    dp[0].first = 0;
    dp[0].second = 1;
    dp[1].first = 1;
    dp[1].second = 1;
    dp[2].first = 2;
    dp[2].second = 1;
    dp[3].first = 3;
    dp[3].second = 1;
    dp[4].first = 4;
    dp[4].second = 1;
    for (int i = 5; i < MAXN; i++)
    {
        dp[i].first = i;
        dp[i].second = 1;

        for (int j = sqrt(i); j >= 1; j--)
            if (i % j == 0 && dp[j].second == 1 && dp[i / j].second == 1)
            {
                if (dp[i].first > dp[j].first + dp[i / j].first + 2)
                    dp[i].first = dp[j].first + dp[i / j].first + 2;
            }
    }
    for (int i = 5; i < MAXN; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            if (dp[j].first + dp[i - j].first + 2 < dp[i].first)
            {
                dp[i].first = dp[j].first + dp[i - j].first + 2;
                dp[i].second = 0;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << dp[n].first << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    process();
    // cout << dp[25].second << " ";
    //  for (int i = 50; i <= 53; i++) cout << dp[i].second << " ";
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
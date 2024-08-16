#include <bits/stdc++.h>
#define ll long long
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define fi first
#define se second
const int MAXN = 200005;
ll dp[MAXN], h[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1; i < n; i++)
    {
        while (dq.size() > 1 &&
               (dp[dq[1]] + h[dq[1]] * h[dq[1]] - (dp[dq[0]] + h[dq[0]] * h[dq[0]])) <= 2ll * h[i] * (h[dq[1]] - h[dq[0]]))
        {
            dq.pop_front();
        }
        int j = dq.front();
        dp[i] = dp[j] + (h[i] - h[j]) * (h[i] - h[j]) + c;
        while (dq.size() > 1)
        {
            int k = dq.size();
            ll z = (dp[i] + h[i] * h[i]) - (dp[dq[k - 1]] + h[dq[k - 1]] * h[dq[k - 1]]);
            ll y = (dp[dq[k - 1]] + h[dq[k - 1]] * h[dq[k - 1]]) - (dp[dq[k - 2]] + h[dq[k - 2]] * h[dq[k - 2]]);
            if (z * (h[dq[k - 1]] - h[dq[k - 2]]) <= y * (h[i] - h[dq[k - 1]]))
                dq.pop_back();
            else
                break;
        }
        dq.push_back(i);
    }
    cout << dp[n-1] << "\n";
}
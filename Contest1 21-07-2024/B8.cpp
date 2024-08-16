#include <bits/stdc++.h>
#define ll long long
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define fi first
#define se second

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), count(1000005, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        count[a[i]]++;
    }

    int ans = 1;

    for (int i = 1000000; i >= 1; i--)
    {
        int sum = 0;
        for (int j = i; j <= 1000000; j += i)
            sum += count[j];

        if (sum > 1)
        {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)
#define vi vector<int>
#define vvi vector<vi>

vvi square(int n, int m, int k)
{
    vvi s(n, vi(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i + k <= n && j + k <= m)
            {
                s[i][j]++;
                if (i + k < n)
                    s[i + k][j]--;
                if (j + k < m)
                    s[i][j + k]--;
                if (i + k < n && j + k < m)
                    s[i + k][j + k]++;
            }

    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            s[i][j] += s[i][j - 1];
    for (int j = 0; j < m; j++)
        for (int i = 1; i < n; i++)
            s[i][j] += s[i - 1][j];
    return s;
}

ll process(vector<ll> a, int n, int m, int k)
{
    vvi s = square(n, m, k);
    sort(a.rbegin(), a.rend());

    ll ans = 0;
    vi hi;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            hi.push_back(s[i][j]);

    sort(hi.rbegin(), hi.rend());

    int index = 0;
    for (ll height : a)
    {
        if (index >= hi.size())
            break;
        ans += height * hi[index];
        ++index;
    }

    return ans;
}

void solve()
{
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<ll> a(w);
    for (ll &i : a)
        cin >> i;

    cout << process(a, n, m, k) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
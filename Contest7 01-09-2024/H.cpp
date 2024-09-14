#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int a[MAXN], b[MAXN], t[4 * MAXN];

void build(int v, int l, int r)
{
    if (l == r)
        t[v] = a[l];
    else
    {
        int tm = (l + r) >> 1;
        build(v << 1, l, tm);
        build(v << 1 | 1, tm + 1, r);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

long long get(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 1e9;
    if (tl == l && tr == r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return min(get(v << 1, tl, tm, l, min(r, tm)),
               get(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r));
}

void update(int v, int l, int r, int x)
{
    if (l == r)
        t[v] = 1e9;

    else
    {
        int tm = (l + r) >> 1;
        if (x <= tm)
            update(v << 1, l, tm, x);
        else
            update(v << 1 | 1, tm + 1, r, x);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
}

void solve()
{
    int n;
    cin >> n;
    map<int, set<int>> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]].insert(i);
    }

    for (int i = 0; i < n; i++)
        cin >> b[i];

    build(1, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (m[b[i]].size() == 0)
        {
            cout << "NO\n";
            return;
        }
        int pos = *m[b[i]].begin();
        if (b[i] <= get(1, 0, n - 1, 0, pos))
        {
            m[b[i]].erase(pos);
            update(1, 0, n - 1, pos);
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
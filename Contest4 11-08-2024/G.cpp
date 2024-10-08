#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)

ll MOD = 1e9 + 7;

struct matrix
{
    ll a[2][2];
    matrix()
    {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                a[i][j] = 0;
    }
    matrix operator+(matrix x)
    {
        matrix ans;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                ans.a[i][j] = (a[i][j] + x.a[i][j]) % MOD;
        return ans;
    }
    matrix operator*(matrix x)
    {
        matrix ans;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    ans.a[i][k] += a[i][j] * x.a[j][k];
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                ans.a[i][j] %= MOD;
        return ans;
    }
};

matrix pw(matrix a, ll b)
{
    matrix ans;
    for (int i = 0; i < 2; ++i)
        ans.a[i][i] = 1;
    while (b)
    {
        while (!(b & 1))
            b >>= 1, a = (a * a);
        --b;
        ans = ans * a;
    }
    return ans;
}

const int MAXN = 120000;
matrix bs;
matrix rmq[MAXN * 4];
matrix dd[MAXN * 4];
ll a[MAXN];

void build(int v, int tl, int tr)
{
    for (int i = 0; i < 2; ++i)
        dd[v].a[i][i] = 1;
    if (tl + 1 == tr)
    {
        rmq[v] = pw(bs, a[tl]);
        return;
    }
    int m = (tl + tr) >> 1;
    build(v * 2 + 1, tl, m);
    build(v * 2 + 2, m, tr);
    rmq[v] = rmq[v * 2 + 1] + rmq[v * 2 + 2];
}

void update(int v, int tl, int tr, int l, int r, matrix x)
{
    if (r <= tl || tr <= l)
        return;
    if (l <= tl && tr <= r)
    {
        dd[v] = dd[v] * x;
        rmq[v] = rmq[v] * x;
        return;
    }
    int m = (tl + tr) >> 1;
    update(v * 2 + 1, tl, m, l, r, x);
    update(v * 2 + 2, m, tr, l, r, x);
    rmq[v] = (rmq[v * 2 + 1] + rmq[v * 2 + 2]) * dd[v];
}

matrix query(int v, int tl, int tr, int l, int r)
{
    if (r <= tl || tr <= l)
        return matrix();
    if (l <= tl && tr <= r)
        return rmq[v];
    int m = (tl + tr) >> 1;
    return (query(v * 2 + 1, tl, m, l, r) + query(v * 2 + 2, m, tr, l, r)) * dd[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bs.a[0][0] = 1;
    bs.a[0][1] = 1;
    bs.a[1][0] = 1;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    build(0, 0, n);
    for (int i = 0; i < m; ++i)
    {
        int t, l, r;
        cin >> t >> l >> r;
        --l;
        if (t == 1)
        {
            ll x;
            cin >> x;
            matrix g = pw(bs, x);
            update(0, 0, n, l, r, g);
        }
        else
        {
            matrix a = query(0, 0, n, l, r);
            cout << a.a[1][0] << "\n";
        }
    }
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define fi first
#define se second

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int solve(int n, int st, int en, int u, int d)
{
    if (st == en)
        return 0;

    if (u == 0 && d == 0)
        return -1;

    if (u == 0)
    {
        if (st > en && (st - en) % d == 0)
            return (st - en) / d;
        return -1;
    }

    if (d == 0)
    {
        if (st < en && (en - st) % u == 0)
            return (en - st) / u;
        return -1;
    }

    int g = gcd(u, d);
    if ((en - st) % g != 0)
        return -1;

    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;

    q.push({st, 0});
    visited[st] = true;

    while (!q.empty())
    {
        int f = q.front().first;
        int presses = q.front().second;
        q.pop();

        int uf = f + u;
        int df = f - d;

        if (uf == en || df == en)
            return presses + 1;

        if (uf <= n && !visited[uf])
        {
            q.push({uf, presses + 1});
            visited[uf] = true;
        }

        if (df >= 1 && !visited[df])
        {
            q.push({df, presses + 1});
            visited[df] = true;
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, st, en, u, d;
    cin >> n >> st >> en >> u >> d;

    cout << solve(n, st, en, u, d) << "\n";
}
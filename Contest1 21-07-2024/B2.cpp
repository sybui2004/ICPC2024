#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
bool lucky(int n)
{
    while (n)
    {
        if (n % 10 != 7 && n % 10 != 4)
            return false;
        n /= 10;
    }
    return true;
}

int n;
vector<pii> graph[100100];
int cnt[100100], tree[100100], up[100100], l[100100], r[100100];
ll ans;


void root(int u, int p)
{
    tree[u] = 1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i].fi;
        if (v == p)
            graph[u].erase(graph[u].begin() + i);
    }
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i].fi;
        root(v, u);
        tree[u] += tree[v];
    }
}

void dfs1(int u)
{
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i].fi, w = graph[u][i].se;
        dfs1(v);
        if (w == 1)
            cnt[u] += tree[v];
        else
            cnt[u] += cnt[v];
    }
}

void dfs2(int u)
{
    ll total = cnt[u] + up[u];
    ans += (total * (total - 1));
    if (graph[u].empty())
        return;

    for (int i = 1; i < graph[u].size(); i++)
    {
        int v = graph[u][i].fi, w = graph[u][i].se;
        int pre = graph[u][i - 1].fi, cur = graph[u][i - 1].se;
        if (cur == 0)
            l[v] = l[pre] + cnt[pre];
        else
            l[v] = l[pre] + tree[pre];
    }

    for (int i = graph[u].size() - 2; i >= 0; i--)
    {
        int v = graph[u][i].fi, w = graph[u][i].se;
        int tmp = graph[u][i + 1].fi, val = graph[u][i + 1].se;
        if (val == 0)
            r[v] = r[tmp] + cnt[tmp];
        else
            r[v] = r[tmp] + tree[tmp];
    }

    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i].fi, w = graph[u][i].se;
        if (w == 1)
            up[v] = n - tree[v];
        else
            up[v] = up[u] + l[v] + r[v];
        dfs2(v);
    }
}

int main()
{
    cin >> n;
    int u, v, w;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        w = lucky(w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    root(1, -1);
    dfs1(1);
    dfs2(1);
    cout << ans;
}
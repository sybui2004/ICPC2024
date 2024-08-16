#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define all(v) v.begin(), v.end()

const int MAX = 200005;

int n, m;
vector<vi> adj;
vi p;
bool result[MAX];
bool removed[MAX];
int parent[MAX], size[MAX];

void init()
{
    for (int i = 0; i < MAX; ++i)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void solve()
{
    init();
    cin >> n >> m;
    adj.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    p.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    fill(removed, removed + n + 1, false);
    int components = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        int u = p[i];
        removed[u] = true;
        components++;

        for (int v : adj[u])
        {
            if (removed[v])
            {
                if (find(u) != find(v))
                {
                    Union(u, v);
                    components--;
                }
            }
        }

        result[i] = (components == 1);
    }

    for (int i = 0; i < n; i++)
    cout << (result[i] ? "YES" : "NO") << "\n";
}

int main()
{
    fast;
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

#define ll long long
#define vi vector<int>

struct State
{
    vi p;
    int steps;
};

bool isSorted(vi p)
{
    for (int i = 1; i < p.size(); ++i)
        if (p[i] < p[i - 1])
            return false;
    return true;
}

vi swap1(vi p)
{
    vi newp = p;
    for (int i = 0; i < p.size(); i += 2)
        swap(newp[i], newp[i + 1]);
    
    return newp;
}

vi swap2(const vi &p, int n)
{
    vi newp = p;
    for (int i = 0; i < n; i++)
        swap(newp[i], newp[i + n]);
    return newp;
}

int solve(int n, vi p)
{
    queue<State> q;
    set<vi> visited;

    q.push({p, 0});
    visited.insert(p);

    while (!q.empty())
    {
        State current = q.front();
        q.pop();

        if (isSorted(current.p))
            return current.steps;

        vi newp1 = swap1(current.p);
        if (visited.find(newp1) == visited.end())
        {
            q.push({newp1, current.steps + 1});
            visited.insert(newp1);
        }

        vi newp2 = swap2(current.p, n);
        if (visited.find(newp2) == visited.end())
        {
            q.push({newp2, current.steps + 1});
            visited.insert(newp2);
        }
    }

    return -1;
}

int main()
{
    fast
    int n;
    cin >> n;

    vi p(2 * n);
    for (int &i : p) cin >> i;

    cout << solve(n, p);

    return 0;
}

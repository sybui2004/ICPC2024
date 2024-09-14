#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

ll INF = LLONG_MAX;
ll X, Y;
vector<ll> LR(101010), UD(101010);
int n;
string s;

bool check(ll step)
{
    ll LR2 = LR[n] * (step / n) + LR[step % n];
    ll UD2 = UD[n] * (step / n) + UD[step % n];

    return (abs(X - LR2) + abs(Y - UD2) <= step);
}

void solve()
{
    ll x, y;

    cin >> x >> y;
    cin >> X >> Y;
    X -= x;
    Y -= y;
    cin >> n >> s;

    for (int i = 0; i < n; ++i)
    {
        LR[i + 1] = LR[i];
        UD[i + 1] = UD[i];
        if (s[i] == 'U')
            UD[i + 1]++;
        if (s[i] == 'D')
            UD[i + 1]--;
        if (s[i] == 'L')
            LR[i + 1]--;
        if (s[i] == 'R')
            LR[i + 1]++;
    }

    ll ret = (1LL << 50) - 1;
    if (!check(ret))
    {
        cout << "-1\n";
        return;
    }

    for (int i = 49; i >= 0; --i)
        if (check(ret - (1LL << i)))
            ret -= 1LL << i;

    cout << ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll powMod(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, kt;
    cin >> n >> kt;

    vector<int> a(n);
    int cntC = 0, cntL = 0;

    for (int &x : a)
    {
        cin >> x;
        if (x % 2)
            cntL++;
        else
            cntC++;
    }

    cout << (powMod(2, cntC) * powMod(2, cntL - 1)) % MOD;
    
    return 0;
}

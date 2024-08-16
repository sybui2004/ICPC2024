#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)

ll ans;
ll n;
vector<ll> x;
void binarySearch(ll left, ll right, ll val, ll h)
{
    ll mid = left + (right - left) / 2;

    if (h == 1 && x[mid] > val)
    {
        ans++;
        // cout << x[mid] << " ";
    }
    if (h == 0 && x[mid] < val)
    {
        ans++;
        // cout << x[mid] << " ";
    }

    if (mid + 1 <= right)
        binarySearch(mid + 1, right, x[mid], 1);
    if (left <= mid - 1)
        binarySearch(left, mid - 1, x[mid], 0);
}

void solve()
{
    ll m, a, c, x0;
    cin >> n >> m >> a >> c >> x0;

    x.resize(n);
    x[0] = (a * x0 + c) % m;
    for (ll i = 1; i < n; i++)
        x[i] = (((a%m)* (x[i - 1]%m))%m + c%m) % m;

    ans = 1;
    // for (ll i : x) cout << i << " ";
    binarySearch(0, n - 1, x[(n - 1) / 2], -1);

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
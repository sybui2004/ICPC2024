#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(vector<ll> a, int k)
{
    if (k == 0)
        return true;

    sort(a.rbegin(), a.rend());

    ll sum = 0;
    for (int i = 0; i < k; i++)
        sum += a[i];

    return sum >= 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);

    for (ll &i : a) cin >>i;

    for (ll &i : b) cin >> i;

    
    for (int i = 0; i < n; i++)
        a[i] -= b[i];    

    int left = 0, right = n, ans = 0;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (check(a, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    cout << ans;

    return 0;
}

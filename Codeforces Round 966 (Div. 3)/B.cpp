#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)

void solve()
{
    int n;
    cin >> n;
    vector <int> a(n);
    map <int, int> mp;
    
    int kt = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]] = 1;
        if (i > 0)
        {
            if (mp[a[i] - 1] == 0 && mp[a[i] + 1] == 0) kt = 1;
        }
    }

    if (kt == 1) cout << "NO\n";
    else cout << "YES\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
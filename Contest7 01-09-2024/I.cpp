#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        ll s = 0;
        vector<vector<ll>> a(m + 2, vector<ll> (n+2, 0));
        
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                if (a[i][j]) s++;
            }
        s *= 2;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                s += abs(a[i][j + 1] - a[i][j]);
                s += abs(a[i + 1][j] - a[i][j]);
            }
        }
        cout << s << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // cout << s;
    ll p1 = 0, p2 = 0;
    for (char i : s)
    {
        if (i == '+')
            p1++;
        else
            p2++;
    }
    // cout << p1 << " " << p2;

    int q;
    cin >> q;
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        ll tmp = b * (p2 - p1), res = a - b;
        if (res == 0 && tmp !=0)
        {
            cout << "NO\n";
            continue;
        }
        if (tmp == 0 && res == 0)
        {
            cout << "YES\n";
            continue;
        }
        if (tmp % res == 0)
        {
            tmp /= res;
            if ((tmp > 0 && tmp > p1)||(tmp < 0 && abs(tmp) > p2))
            {
                cout << "NO\n";
                continue;
            }else cout << "YES\n";
        }else cout << "NO\n";

        //cout << tmp << " " << res << "\n";
        // if (tmp % res == 0)
        //     cout << "YES\n";
        // else
        //     cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
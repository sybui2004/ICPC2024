#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

ll cp(ll n)
{
    ll b = sqrt(n);
    if (b * b == n)
        return b;
    return 0;
}
void solve()
{
    vector<pair<ll, ll>> v(3);
    for (pair<ll, ll> &i : v)
    {
        cin >> i.first >> i.second;
        if (i.first > i.second)
            swap(i.first, i.second);
    }
    sort(all(v), cmp);

    ll dt = 0;
    for (auto i : v)
        dt += i.first * i.second;
    ll check = cp(dt);
    if (check == 0)
    {
        cout << "0";
        return;
    }
    else
    {
        if (v[0].second == v[1].second && v[1].second == v[2].second && v[2].second == check)

            cout << v[0].second;

        else
        {
            if (v[2].second == check)
            {
                ll tmp = check - v[2].first;
                if (v[0].first + v[1].first == v[2].second && v[0].second == tmp && v[1].second == tmp)
                    cout << check;
                else
                    cout << "0";
            }
            else
                cout << "0";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
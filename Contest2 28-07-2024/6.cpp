#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int minElement = *min_element(a.begin(), a.end());
    int minPos = find(a.begin(), a.end(), minElement) - a.begin();

    int ans = 0;

    for (int i = minPos - 1; i >= 0;)
    {
        ans++;
        int pos = i;
        while (pos >= 0 && a[pos] == minElement)
            pos--;

        i = pos - (k - 1);
    }

    for (int i = minPos + 1; i < n;)
    {
        ans++;
        int pos = i;
        while (pos < n && a[pos] == minElement)
            pos++;

        i = pos + (k - 1);
    }

    cout << ans;
}

int main()
{
    fast
    solve();
    return 0;
}

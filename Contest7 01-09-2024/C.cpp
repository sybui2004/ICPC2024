#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> dd(1000001, 0);
vector<bool> visited(1000001, false);
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
    {
        cin >> i;
        dd[i]++;
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[a[i]])
            continue;
        if (dd[a[i]] == 1)
            ans++;
        for (int j = a[i]; j <= 1000000; j += a[i])
            visited[j] = true;
    }

    cout << ans;

    return 0;
}

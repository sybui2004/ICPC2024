#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    vector<int> l(k);

    for (int &i : l)
        cin >> i;

    unordered_map<int, int> freq;

    for (int i = 0; i < k; i++)
    {
        unordered_set<int> curSet;
        for (int j = 0; j < l[i]; j++)
        {
            int a;
            cin >> a;
            if (curSet.find(a) == curSet.end())
            {
                curSet.insert(a);
                freq[a]++;
            }
        }
    }

    int ans = INT_MAX;

    for (auto i : freq)
    {
        if (i.second == k)
            ans = min(ans, i.first);
    }

    if (ans == INT_MAX)
        cout << "NO";
    else
        cout << ans;

    return 0;
}

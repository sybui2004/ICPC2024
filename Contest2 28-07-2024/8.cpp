#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
void Try(int index, vector<int> &a, vector<bool> &used, int cur, unordered_map<int, vector<vector<bool>>> &s)
{
    if (index == a.size())
    {
        s[cur].push_back(used);
        return;
    }

    Try(index + 1, a, used, cur, s);

    used[index] = true;
    Try(index + 1, a, used, cur + a[index], s);
    used[index] = false;
}

int main()
{
    fast
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int, vector<vector<bool>>> s;
    vector<bool> used(n, false);
    Try(0, a, used, 0, s);

    set<int> result;
    for (auto p : s)
    {
        int sum = p.first;
        vector<vector<bool>> list = p.second;
        if (list.size() >= 2)
        {
            bool found = false;
            for (int i = 0; i < list.size() - 1 && !found; i++)
            {
                for (int j = i + 1; j < list.size(); j++)
                {
                    bool check = false;
                    for (int k = 0; k < n && !check; k++)
                    {
                        if (list[i][k] && list[j][k])
                        {
                            check = true;
                            break;
                        }
                    }
                    if (!check)
                    {
                        result.insert(sum);
                        found = true;
                        break;
                    }
                }
            }
        }
    }

    cout << result.size() << "\n";
    for (int sum : result)

        cout << sum << " ";

    return 0;
}

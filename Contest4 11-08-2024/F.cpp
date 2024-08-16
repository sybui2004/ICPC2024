#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)

void solve()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    map<string, int> m1, m2, m3;
    vector<string> v1(n1);
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> v1[i] >> x;
        m1[v1[i]] += x;
    }

    cin.ignore();
    for (int i = 0; i < n2; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        m2[s] += x;
    }
    cin.ignore();
    for (int i = 0; i < n3; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        m3[s] += x;
    }

    vector <string> ans;
    set<string> tmp;
    map<string, int> dd;
    for (string i : v1)
        if (m1[i] >= 20 && m2[i] >= 20 && m3[i] >= 20) 
        {
            ans.push_back(i);
            tmp.insert(i);
            dd[i] = 1;
        }

    cout << tmp.size() << " ";
    for (string i : ans)
        if (dd[i])
        {
            cout << i << " ";
            dd[i] = 0;
        }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
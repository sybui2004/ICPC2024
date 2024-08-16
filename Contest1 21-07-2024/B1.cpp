#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long

void solve() {
    string s;
    cin >> s;
    int m, a;
    cin >> m;
    int n = s.size();

    vector<int> count(n + 1, 0);
    
    while (m--) {
        cin >> a;
        count[a - 1]++;
        count[n - a + 1]--;
    }
    
    for (int i = 1; i < n; i++)
        count[i] += count[i - 1];
    
    
    for (int i = 0; i < n / 2; i++)
        if (count[i] % 2 != 0) 
            swap(s[i], s[n - i - 1]);
        

    cout << s;
}

int main() {
    fast;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

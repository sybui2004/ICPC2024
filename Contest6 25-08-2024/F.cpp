#include <bits/stdc++.h>
using namespace std;
#define ll long long

// chu kỳ Pisano
void solve()
{
    int b;
    cin >> b;
    int pre = 0, cur = 1, ans = 0;
    
    do {
        int temp = (pre + cur) % b;
        pre = cur;
        cur = temp;
        ans++;
    } while (pre != 0 || cur != 1);
    
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
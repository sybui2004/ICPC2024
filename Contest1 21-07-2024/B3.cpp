#include <bits/stdc++.h>
#define ll long long
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define fi first
#define se second

int n, cot[105], cheo1[105], cheo2[105], ans;
void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!cot[j] && !cheo1[i - j + n] && !cheo2[i + j - 1])
        {
            cot[j] = cheo1[i - j + n] = cheo2[i + j - 1] = 1;
            if (i == n)
                ans++;
            else
                Try(i + 1);
            cot[j] = cheo1[i - j + n] = cheo2[i + j - 1] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ans = 0;

    Try(1);
    cout << ans << "\n";
}
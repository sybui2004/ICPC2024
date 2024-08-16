#include <bits/stdc++.h>
#define ll long long
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define fi first
#define se second

vector<int> solve(vector<int> a, int n)
{
    vector<int> result(n, 0);

    vector<int> left(n), right(n);

    deque<int> dq;
    for (int i = 0; i < n; ++i)
    {
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();

        left[i] = dq.empty() ? i + 1 : i - dq.back();
        dq.push_back(i);
    }

    dq.clear();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!dq.empty() && a[dq.back()] > a[i])
            dq.pop_back();

        right[i] = dq.empty() ? n - i : dq.back() - i;
        dq.push_back(i);
    }

    vector<int> mi(n + 1, -1e9);
    for (int i = 0; i < n; ++i)
    {
        int length = left[i] + right[i] - 1;
        mi[length] = max(mi[length], a[i]);
    }

    for (int i = n - 1; i >= 1; --i)
        mi[i] = max(mi[i], mi[i + 1]);

    return vector<int>(mi.begin() + 1, mi.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<int> result = solve(a, n);
    for (int i = 0; i < n; ++i)
        cout << result[i] << " ";
    cout << "\n";

}

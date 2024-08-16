#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <climits>

const long long MAX = 2e16;
struct data {
    long long stt, u, v;
};
long long n, m;
std::vector<data> a, b;
long long dp[1005][1005][2];
/*
    dp[i][j][0] = min(dp[i - 1][j][0] + distance(a[i - 1], a[i]), dp[i - 1][j][1] + distance(b[j], a[i]));
    dp[i][j][1] = min(dp[i][j - 1][0] + distance(a[i], b[j]), dp[i][j - 1][1] + distance(b[j - 1], b[j]));
*/
long long distance(data x, data y)
{
    return (x.u - y.u) * (x.u - y.u) + (x.v - y.v) * (x.v - y.v);
}
int main()
{
    std::cin >> n >> m;
    a.resize(n + 1);
    b.resize(m + 1);
    for(int i = 1; i <= n; i++)
    {
        std::cin >> a[i].u >> a[i].v;
        a[i].stt = i;
    }
    for(int i = 1; i <= m; i++)
    {
        std::cin >> b[i].u >> b[i].v;
        b[i].stt = i;
    }
    dp[0][0][0] = MAX;
    dp[0][0][1] = MAX;
    dp[0][1][0] = MAX;
    dp[1][0][1] = MAX;
    for(int i = 2; i <= n; i++)
    {
        dp[i][0][0] = dp[i - 1][0][0] + distance(a[i], a[i - 1]);
        dp[i][0][1] = MAX;
        // std::cout << a[i].u << " + " << a[i].v << " " << a[i - 1].u << " + " << a[i - 1].v << " ==== " << distance(a[i], a[i - 1]) << std::endl; 
    }
    for(int j = 0; j <= m; j++)
    {
        dp[0][j][1] = MAX;
        dp[0][j][0] = MAX;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j][0] = std::min(dp[i - 1][j][0] + distance(a[i - 1], a[i]), dp[i - 1][j][1] + distance(b[j], a[i]));
            dp[i][j][1] = std::min(dp[i][j - 1][0] + distance(a[i], b[j]), dp[i][j - 1][1] + distance(b[j - 1], b[j]));
            // std::cout << "that: " << std::min(dp[i][j][0], dp[i][j][1]) << std::endl;
        }
    }
    std::cout << dp[n][m][0] << std::endl;
}
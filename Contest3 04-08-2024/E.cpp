#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <climits>
int main()
{
    int n; std::cin >> n;
    std::vector<int> a(n + 2), b(n + 2);
    for(int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        b[i] = a[i];
    }
    int res = 0;
    std::vector<int> ans;
    std::vector<int> maxLeft(n + 2), maxRight(n + 2);
    maxRight[n + 1] = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        maxLeft[i] = std::max(maxLeft[i - 1], a[i]);
    }
    for(int i = n; i >= 1; i--)
    {
        maxRight[i] = std::min(maxRight[i + 1], a[i]);
    }
    // for(int i = 1; i <= n; i++)
    // {
    //     std::cout << maxLeft[i] << " ";
    // }
    // std::cout << std::endl;
    // for(int i = 1; i <= n; i++)
    // {
    //     std::cout << maxRight[i] << " ";
    // }
    // std::cout << std::endl;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] >= maxLeft[i] && a[i] <= maxRight[i + 1])
        {
            res++;
            ans.push_back(a[i]);
        }
    }
    std::cout << res << " ";
    for(int i = 0; i < std::min(100, (int)ans.size()); i++)
    {
        std::cout << ans[i] << " ";
    }
}
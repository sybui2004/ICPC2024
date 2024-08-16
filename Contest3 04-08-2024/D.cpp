#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>
int main()
{
    int n, m; std::cin >> n >> m;
    long long* a = new long long[n + 1];
    long long* preArr = new long long[n + 1];
    for(int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        preArr[i] = preArr[i - 1] + a[i];
    }
    long long res = 0;
    for(int i = 1; i <= n; i++)
    {
        preArr[i] = preArr[i] % m;
    }
    std::map<long long, int> mp;
    mp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        res += mp[preArr[i]];
        mp[preArr[i]]++;
    }
    std::cout << res << std::endl;
    delete [] a;
    delete [] preArr;
}
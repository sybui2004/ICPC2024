#include <iostream>
#include <algorithm>
#include <map>
long long compareNumber = 0;
int n;
int res[12];
int data[3] = {0, 1, 2};
int ans = 0;
std::map<long long, int> mp;
void solve(int j)
{
    if(j > n + 1)
    {
        return;
    }
    long long use = 0;
    for(int i = 1; i < j; i++)
    {
        use = use * 10 + res[i];
    }
    if(use <= compareNumber && use > 0 && mp[use] == 0)
    {
        // std::cout << use << std::endl;
        ans++;
        mp[use]++;
    }
    for(int i = 1; i <= 2; i++)
    {
        res[j] = data[i];
        solve(j + 1);
    }
}
int main()
{
    std::string s; std::cin >> s;
    n = s.size();
    for(int i = 0; i < s.size(); i++)
    {
        compareNumber = compareNumber * 10 + s[i] - '0';
    }
    for(int i = 0; i <= 9; i++)
    {
        for(int j = i; j <= 9; j++)
        {
            data[1] = i;
            data[2] = j;
            solve(1);
        }
    }
    std::cout << ans << std::endl;
}
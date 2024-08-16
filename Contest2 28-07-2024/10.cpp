#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
int main()
{
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n + 1);
    std::map<int, int> mp;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        mp[a[i]]++;
    }
    std::deque<std::pair<int, int>> v;
    for(auto x: mp)
    {
        v.push_back(x);
    }
    std::sort(v.begin(), v.end(), [](std::pair<int, int> x, std::pair<int, int> y){
        if(x.second != y.second)
            return x.second > y.second;
        else 
            return x.first < y.first;
    });
    int check = v[0].second;
    while(v.size() && v.front().second == check)
    {
        v.pop_front();
    }
    v.size() ? std::cout << v.front().first << std::endl : std::cout << "NONE" << std::endl;
}
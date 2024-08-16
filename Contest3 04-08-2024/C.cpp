#include <iostream>
#include <math.h>


void solve()
{
    int n; std::cin >> n;
    std::string res = "No";
    for(int i = 0; i <= std::min(100, n / 7); i++)
    {
        int x = n - 7 * i;
        if(x % 4 == 0 && x / 4 <= 100)
        {
            res = "Yes";
            break;
        }
    }
    std::cout << res << std::endl;
}

int main()
{
    solve();
}
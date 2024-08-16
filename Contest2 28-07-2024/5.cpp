#include <iostream>


int main()
{
    int n; std::cin >> n;
    int a[n + 1];
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        while(a[i] > 0 && a[i] % 2 == 0)
        {
            a[i] = a[i] / 2;
            res++;
        }
    }
    std::cout << res << std::endl;
}
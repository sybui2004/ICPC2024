#include <bits/stdc++.h>
using namespace std;

long long n, res;
vector<string> str;
unordered_map<string, int> mcnt;
unordered_map<string, int> mp;

int main()
{
    scanf("%lld", &n);
    
    for (int i = 0; i < n; i++)
    {
        vector<int> v(5);
        for (int j = 0; j < 5; j++)
            scanf("%d", &v[j]);
        sort(v.begin(), v.end());

        for (int s = 1; s < 32; s++)
        {
            string h = "";
            int cnt = 0;
            for (int k = 0; k < 5; k++)
            {
                if (s & (1 << k))
                {
                    h = h + to_string(v[k]) + ",";
                    cnt++;
                }
            }
            mp[h]++;
            if (mp[h] == 2)
            {
                str.push_back(h);
            }
            mcnt[h] = cnt;
        }
    }


    for (string x : str)
    {
        string h = x;
        long long cnth = mp[h];
        if (cnth == 1)
            continue;
        long long r = cnth * (cnth - 1) / 2;
        if (mcnt[h] % 2 == 0)
            res -= r;
        else
            res += r;
    }

    printf("%lld\n", n * (n - 1) / 2 - res);
}
#include <bits/stdc++.h>
using namespace std;

void s() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int q;
        cin >> q;
        while (q--) {
            string s;
            cin >> s;
            if (s.size() != n) {
                cout << "NO\n";
                continue;
            }

            unordered_map<int, char> m1;
            unordered_map<char, int> m2;
            bool f = true;

            for (int i = 0; i < n; ++i) {
                int x = a[i];
                char c = s[i];

                if (m1.count(x) && m1[x] != c) {
                    f = false;
                    break;
                }
                if (m2.count(c) && m2[c] != x) {
                    f = false;
                    break;
                }

                m1[x] = c;
                m2[c] = x;
            }

            if (f) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    s();
    return 0;
}
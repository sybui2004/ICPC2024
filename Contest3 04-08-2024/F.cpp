#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct matran {
  ll X[2][2];
  matran operator*(const matran &b) const {
    matran c;
    c.X[0][0] = (X[0][0] * b.X[0][0] + X[0][1] * b.X[1][0]);
    c.X[0][1] = (X[0][0] * b.X[0][1] + X[0][1] * b.X[1][1]);
    c.X[1][0] = (X[1][0] * b.X[0][0] + X[1][1] * b.X[1][0]);
    c.X[1][1] = (X[1][0] * b.X[0][1] + X[1][1] * b.X[1][1]);
    return c;
  }
};

matran binpow(matran a, ll n, ll M) {
  if (n == 1) {
    return a;
  }
  matran tmp = binpow(a, n / 2, M);
  tmp = tmp * tmp;
  if (n % 2 == 1) {
    tmp = tmp * a;
  }
  tmp.X[0][0] %= M;
  tmp.X[0][1] %= M;
  tmp.X[1][0] %= M;
  tmp.X[1][1] %= M;
  return tmp;
}

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll fibonacci_mod(ll n, ll M) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  matran A;
  A.X[0][0] = 0;
  A.X[0][1] = 1;
  A.X[1][0] = 1;
  A.X[1][1] = 1;
  A = binpow(A, n - 1, M);
  return A.X[1][1] % M;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, M;
    cin >> a >> b >> M;
    ll g = gcd(a, b);
    cout << fibonacci_mod(g, M) << endl;
  }
  return 0;
}
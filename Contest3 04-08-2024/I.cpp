#include <bits/stdc++.h>
using namespace std;
int prime[1000001];

void sang() {
  for (int i = 0; i <= 10000000; i++) {
    prime[i] = 1;
  }
  prime[0] = prime[1] = 0;
  for (int i = 2; i * i <= 10000000; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= 10000000; j += i) {
        prime[j] = 0;
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  if(n == 4){
    cout << 1;
    return 0;
  }
  int f[n + 1] = {};
  f[0] = 1;
  f[1] = 1;
  int dem = 0;
  for (int i = 3; i < n - 3; i++) {
    if (f[n - i] == 0 && prime[i] == 1 && prime[n - i] == 1 && f[i] == 0 && i % 2 != 0) {
      dem++;
      f[i] = 1;
      f[n - i] = 1;
    }
  }
  cout << dem;
}
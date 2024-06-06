#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int a[N];
int prefix_xor[N];
int main() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    prefix_xor[i] = prefix_xor[i - 1] ^ a[i];
  }
  while (q--) {
    int l, r; cin >> l >> r;
    cout << (prefix_xor[r] ^ prefix_xor[l - 1]) << '\n';
  }
  return 0;
}

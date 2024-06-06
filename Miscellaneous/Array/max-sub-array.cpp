#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
     cin >> a[i];
  }
  long long max_subarray_sum = -1e18;
  long long sum = -1e18;
  for (int i = 0; i < n; i++) {
     sum = max((long long)a[i], a[i] + sum); // max subarray sum ending at index i
     max_subarray_sum = max(max_subarray_sum, sum);
  }
  cout << max_subarray_sum << '\n';
  return 0;
}

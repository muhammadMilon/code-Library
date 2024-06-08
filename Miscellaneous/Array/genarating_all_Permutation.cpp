#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[] = {1, 2, 3};
  int n = 3;
  sort(a, a + n);
  do {
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << '\n';
  } while (next_permutation(a, a + n));
  return 0;
}

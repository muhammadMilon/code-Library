#include<bits/stdc++.h>
#define ll long long int
#define faster() ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int sz = 1e5 + 5, mod = 1e9 + 7;

int main()
{
    faster();
    int n,m; cin >> n >> m;
    int s[n], t[m];
    for(int i = 0; i < n; i++){
       cin >> s[i];
    }
    for(int i = 0; i < m; i++){
       cin  >> t[i];
    }
    int i=0,j=0,f=0;
    while( i<n and j<m){
      if(t[j] == s[i]){
         j++;
      }
      i++;

      if(j==m){
         f=1;
         break;
      }
    }
    if(f==1){
      cout << "YES" << '\n';
    }
    else {
      cout << "NO" << '\n';
    }
    return 0;
}

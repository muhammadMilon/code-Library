#include<bits/stdc++.h>
#define ll long long int
#define faster() ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int sz = 1e5 + 5, mod = 1e9 + 7;

int main()
{
    faster();
    int n; cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll maxi = -1e9;
    ll sum = 0;
    for(int i = 0; i < n; i++){
       sum+=a[i];
       maxi = max(maxi,sum);
       if(sum < 0) sum=0;
    }
    cout << maxi <<'\n';
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int sz = 1e5 + 5, mod = 1e9 + 7;
ll modularExponentiation(ll base,ll power,ll mod)
{
    ll result=1;
    while(power>0)
        {
            if(power%2==1)
            {
                result=(result*base)%mod;
                power--;
            }
            else
            {
                base=(base*base)%mod;
                power/=2;
            }
        }
        return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
    {
        ll base,power;
        cin>>base>>power;
        cout<<modularExponentiation(base,power,mod)<<endl;
    }
	return 0;
}

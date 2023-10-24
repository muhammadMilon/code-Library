#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const int sz = 2e7 + 7, mod = 1e9 + 7;

long long a[sz],prime[sz];

void seive()
{
    ll k=1;
    for(ll i=4;i<=sz;i+=2)
    {
        a[i]=1;
    }

    for(ll i=3;i*i<=sz;i+=2)
    {
         if(a[i]==0)
         {
             for(ll j=i*2;j<=sz;j+=i)
             {
                 a[j]=1;
             }
         }
    }
    for(ll i=2;i<=sz;i++)
    {
        if(a[i]==0)
        {
           prime[k++]=i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);

    seive();

    ll n;
    cin>>n;

    cout<<prime[n]<<endl;

    return 0;
}

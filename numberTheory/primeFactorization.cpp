#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const int sz = 1e5 + 5, mod = 1e9 + 7;

void primeFactorization(int n)
{
    vector<int>primeFactor;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                primeFactor.push_back(i);
                n/=i;
            }
        }
    }
    if(n>1)
    {
          primeFactor.push_back(n);
    }
    cout<<"The Prime Factors of this number: ";
    for(int i=0;i<primeFactor.size();i++)
    {
        cout<<primeFactor[i]<<" ";
    }
    cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        primeFactorization(n);
    }

	return 0;
}

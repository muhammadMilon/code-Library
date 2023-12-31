#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const int sz = 1e5 + 5, mod = 1e9 + 7;

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
   return gcd(b,a%b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
    {
        int a;
	    string s;
	    cin>>a>>s;
        if(a==0) 
        {
            cout<<s<<endl;
            continue;
        }
        
        if(s=="0") 
        {
            cout<<a<<endl;
            continue;
        }
        
        int value=0;
        for(int i=0;i<s.size();i++)
        {
           value=(value*10 +(s[i]-'0'))%a;
        }
        cout<<gcd(a,value)<<endl;
     }


	return 0;
}
// https://www.codechef.com/problems/GCD2

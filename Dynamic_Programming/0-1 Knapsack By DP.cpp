#include<bits/stdc++.h>
using namespace std;

int knapsack(int n,vector<int>&val,vector<int>&wt,int W)
{
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int w=1;w<=W;w++)
        {
            if(wt[i-1]<=w)
            {
                dp[i][w]=max(dp[i-1][w],dp[i-1][w-wt[i-1]]+val[i-1]);
            }
            else
            {
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n;
    cin>>n;
    vector<int>val(n),wt(n);
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }

    int W;
    cin>>W;
    cout<<knapsack(n,val,wt,W)<<endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    int dp[n+1][m+1];

    for(int i=0; i<=n; i++) dp[i][m]=0;
    for(int i=0; i<=m; i++) dp[n][i]=0;

    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j]=1+dp[i+1][j+1];
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }

    cout << "Longest Common Subsequence: ";
    for(int i=0,j=0; i<n && j<m;)
    {
        if(dp[i][j] == dp[i+1][j+1] + 1)
        {
            cout<<s1[i];
            i++;
            j++;
        }
        else if(dp[i][j]== dp[i+1][j])
        {
                i++;
        }
        else
        {
                j++;
        }
    }
    cout<<endl<<"The length of LCS: "<<dp[0][0]<<endl;

    return 0;
}


//resource https://www.youtube.com/watch?v=wDhAHskAqs0

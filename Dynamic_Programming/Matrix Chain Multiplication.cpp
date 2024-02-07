#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={5,4,6,2,7};
    int n=sizeof(a)/sizeof(a[0]);
    int m[5][5]={0};
    int s[5][5]={0};
    int j,mini,q;

    for(int d=1;d<n-1;d++)
    {
        for(int i=1;i<n-d;i++)
        {
            j=i+d;
            mini=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+(a[i-1]*a[k]*a[j]);

                if(q<mini)
                {
                  mini=q;
                  s[i][j]=k;
                }
            }
            m[i][j]=mini;
        }
    }
    cout<<m[1][n-1]<<endl;
}

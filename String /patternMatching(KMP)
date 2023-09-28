#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void computeLSP(string pat,int n,int lsp[])
{
    int len=0;
    lsp[0]=0;
    int i=1;
    while(i<n)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lsp[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lsp[len-1];
            }
            else
            {
                lsp[i]=0;
                i++;
            }
        }
    }
}

void KMPsearch(string txt,string pat)
 {
     int m=txt.length(),n=pat.length();
     int lsp[n];
     computeLSP(pat,n,lsp);
     int i=0,j=0;
     while(i<m)
     {
         if(pat[j]==txt[i])
         {
             i++;
             j++;
         }
         if(j==n)
         {
             cout<<"The Pattern found at the position of"<<i-j<<endl;
             j=lsp[j-1];
         }
         else if(i<m && pat[j]!=txt[i])
         {
             if(j!=0)
             {
                 j=lsp[j-1];
             }
             else
             {
                 i++;
             }
         }
     }
 }
int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string txt,pat;
  cin>>txt>>pat;
  KMPsearch(txt,pat);

  return 0;
}

#include<bits/stdc++.h>
using namespace std;
set<int>st;
void countFector(int n)
{
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            int x=i;
            int y=n/i;
            st.insert(x);
            st.insert(y);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        countFector(n);
        cout<<st.size()<<endl;
        for(auto it:st) cout<<it<<" ";
        cout<<endl;
        st.clear();
    }
    return 0;
}

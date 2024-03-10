#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v,w;
};

bool cmp(node a,node b)
{
    return (a.v*b.w)>(b.v*a.w);
}

int f_knapsack(vector<node>&v,int w)
{
    sort(v.begin(),v.end(),cmp);

    int ans=0;
    for(const auto &i:v)
    {
        if(w>=i.w)
        {
            ans+=i.v;
            w-=i.w;
        }
        else
        {
            ans+=(i.v/i.w)*w;
            break;
        }
    }
    return ans;
}

int main()
{
    int n,w;
    cin>>n>>w; //number of item && total capecity of knapsack
    vector<node>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].v>>v[i].w;
    }
    cout<<f_knapsack(v,w)<<endl;

    return 0;
}

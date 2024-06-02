#include<bits/stdc++.h>
using namespace std;

bool check_Kth_bit(int x,int k){
    return (x>>k)&1;
}
void On_Bit_Check(int x){
    for(int k=0;k<32;k++){
        if(check_Kth_bit(x,k)){
            cout<<k<<' ';
        }
    }
    cout<<'\n';
}
int main(){
    int x;
    cin>>x;
    On_Bit_Check(x);
    return 0;
}

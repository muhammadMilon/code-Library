#include<bits/stdc++.h>
using namespace std;
int set_Kth_bit(int x,int k){
    return x |(1<<k);
}
int Unset_Kth_bit(int x,int k){
    return x &(~(1<<k));
}
int main(){
    cout<<set_Kth_bit(11,2)<<'\n'; //kTh bit on
    cout<<Unset_Kth_bit(15,2)<<'\n'; //kTh bit off
    return 0;
}

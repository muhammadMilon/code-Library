#include<bits/stdc++.h>
using namespace std;
bool check_Kth_bit(int x,int k){
    return (x>>k)&1;
}
int count_on_bits(int x){
    int cnt=0;
    for(int i=0;i<32;i++){
        if(check_Kth_bit(x,i)){
            cnt++;
        }
    }
    return cnt;
}
bool check_power_of_2(int x){
    return count_on_bits(x)==1;
}
int main(){
    if(check_power_of_2(17)){
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    return 0;
}

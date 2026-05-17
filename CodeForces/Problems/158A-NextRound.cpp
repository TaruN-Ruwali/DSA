#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;

    vector<int>nums(n);

    for (int i = 0; i < n; i++)cin>>nums[i];

    int passed_cnt=0;
    for(int i=0;i<n;i++){
        if(nums[i]>=nums[k-1] && nums[i]!=0)passed_cnt++;
    }

    cout<<passed_cnt<<"\n";
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {

        // Brute        time-O(n^3)     space- O(1)
        
        // int n=nums.size();
        // if(n==1){
        //     return nums[0];
        // }
        // int max=INT_MIN;;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int sum=0;
        //         for(int k=i;k<=j;k++){
        //             sum+=nums[k];

        //         }
        //         if(sum > max){
        //             max=sum;
        //         }
        //     }
        // }
        // return max;

        // Better           time- O(n^2)    space- O(1) 

        // int n=nums.size();
        // if(n==1){
        //     return nums[0];
        // }
        // int max=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){

        //         sum+=nums[j];

        //         if(sum > max){
        //             max=sum;
        //         }
        //     }
        // }
        // return max;

        // Optimal (Kadane's algo)

        // int max=INT_MIN;
        // int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     if(sum > max){
        //         max=sum;
        //     }
        //     if(sum < 0){
        //         sum=0;
        //     }
        // }
        // return max;

        // Follow up(Print index of such sub array)

        int max=INT_MIN;
        int sum=0;
        int start_index=-1, end_index=-1;
        for(int i=0;i<nums.size();i++){
            if(sum==0){
                start_index=i;
            }
            sum+=nums[i];
            if(sum > max){
                end_index=i;
                max=sum;
            }
            if(sum < 0){
                sum=0;
            }
        }
        cout<<start_index<<" "<<end_index<<endl;
        return max;
}

int main(){
    vector<int> nums = {2, 3, 5, -2, 7, -4};
    cout<<maxSubArray(nums)<<endl;
    return 0;
}
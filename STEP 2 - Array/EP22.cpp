#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {

        // Brute Force (Bubble Sort)        time-O(n^2)     space- O(1)

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]>nums[j]){
                    swap(nums[i],nums[j]);
                }
            }
        }

        // Better  (Counting Frequency)         time- O(n)  space- O(1)

        // int count0=0,count1=0,count2=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         count0++;
        //     }
        //     else if(nums[i]==1){
        //         count1++;
        //     }
        //     else{
        //         count2++;
        //     }
        // }
        
        // int i=0;
        // while(count0--){
        //     nums[i]=0;
        //     i++;
        // }
        // while(count1--){
        //     nums[i]=1;
        //     i++;
        // }
        // while(count2--){
        //     nums[i]=2;
        //     i++;
        // }

        // Optimal 
    }

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(auto it: nums){
        cout<<it<<" ";
    }
    return 0;
}
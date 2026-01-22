#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {

        // Brute Force      time- O(n^2)    dpace- O(1)
        // int max=0;
        // for(int i=0;i<nums.size();i++){
        //     int count=0;
        //     for(int j=0;j<nums.size();j++){
        //         if(nums[i]==nums[j]){
        //             count++;
        //         }
        //     }
        //     if(count > (nums.size()/2)){
        //         max=nums[i];;
        //     }
        // }
        // return max;
        
        // Better       time- O(n)  space- O(n)

        // unordered_map<int,int> mpp;
        // for(auto it: nums){
        //     mpp[it]++;
        //     if(mpp[it] > nums.size()/2){
        //         return it;
        //     }
        // }
        // return -1;

         // Optimal (Boyer Moore Voting Algo )   time- O(n)  space- O(1)

        int candidate=0;
        int count=0;

        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate=nums[i];
            }
            if(candidate==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;

    }

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    majorityElement(nums);
    
    return 0;
}
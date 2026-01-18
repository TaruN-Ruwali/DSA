#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        
        // Brute Force          time- O(n^2)    space- O(1)

        // for(int i=0;i < nums.size(); i++){
        //     for(int j=i+1; j < nums.size(); j++){
        //         if(nums[j] == (target-nums[i])){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};
        
 
        // Optimal (Hash Map approach)    time-O(n)   space- O(n)

        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int comp = target - nums[i];
            if(mpp.find(comp) != mpp.end()){
                return {mpp[comp],i};
            }
            mpp[nums[i]]=i;
        }

        return {};
 
    }

int main(){
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> p = twoSum(nums,target);
    cout<<p[0]<<" "<<p[1]<<endl;
    return 0;
}
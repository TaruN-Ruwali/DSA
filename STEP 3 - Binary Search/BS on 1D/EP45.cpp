#include<bits/stdc++.h>
using namespace std;
                    // Recursive Code

    // int bs(vector<int>& nums,int l,int h,int target){
    //     if(l>h)return -1;
    //     int mid = (l+h)/2;
    //     if(nums[mid]==target)return mid;
    //     else if(nums[mid]<target)return bs(nums,mid+1,h,target);
    //     return bs(nums,l,h-1,target);
    // }

        // Iterative Code

    int bs(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target)l=mid+1;
            else if(nums[mid]>target)h=mid-1;
        }
        return -1;
    }

int main(){
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17}; // sorted array
    int target = 6; // target element to search

    
    int ind = bs(a, target);

    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind << endl;

    return 0;
}
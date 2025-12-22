#include<bits/stdc++.h>
using namespace std;

void rotate1(vector<int>& nums){

    // Brute Force      time- (n)   space- O(n)
    /*
    create a dummy array and copy elements from 1th index to n-2th index
    at last place 0th index at n-1th index
    give dummy array
    */

    // Optimal      time- O(n)  space-(1)
    /*
    create a temp variable which stores the 1st element
    iterate to shift every element to left side 
    at last place this temp to the n-1th  index
    */

    int a=nums[0];
    for (int i = 0; i < nums.size()-1; i++)
    {
        nums[i]=nums[i+1];
    }
    nums[nums.size()-1]=a;

}

void rotate_k_left(vector<int>& nums, int k){
    vector<int> temp;
    for (int i = 0; i < k; i++)
    {
        temp[i]=nums[i];
    }
    for (int i = k; i < nums.size(); i++)
    {
        nums[i-k]=nums[i];
    }
    for (int i = nums.size()-k; i < nums.size(); i++)
    {
        nums[i]=temp[];
    }
    
}

int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    // rotate1(nums);
    rotate_k_left(nums,3);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    

    return 0;
}
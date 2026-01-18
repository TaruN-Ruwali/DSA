#include<bits/stdc++.h>
using namespace std;

int subarray_sum(vector<int>& nums , int k){

    // Brute Force              time- O(n^3)        space- O(1)
    /*
    Check Every Sub-array sum one by one
    1st loop for starting point of subarray
    2nd loop for ending point of sub array
    3rd loop for doing sum fron starting point to end point
    check if sum matches k , if yes check for longest length
    */
    // int max_len=0 ,sum;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i; j < nums.size(); j++)
    //     {   sum=0;
    //         for (int x = i; x <= j; x++)
    //         {
    //             sum+=nums[x];
    //         }
    //         if(sum == k && (j-i+1)>max_len){
    //             max_len = j-i+1;
    //         }
    //     }
    // }
    // return max_len;

    // Optimal:- (2 Pointer , Sliding Window)           Time- O(2n)     space- O(1)
    /*
    Make 2 pointers , start them from nums[0]
    add numbers in sum till sum doesn't become equal by increasing right pointer.
        for equal:- if len is bigger than  maxlen -> maxlen = len
        for bigger:- subtract the left element from sum and move the left pointer forward , 
    */

    int p1=0,p2=0,sum=nums[0],len=0;
    
    while (p1<nums.size())
    {
        while (p2<=p1 && sum > k)
        {
            sum-=nums[p2];
            p2++;
        }
        
        if (sum == k && (p1-p2+1) > len)
        {
            len = p1-p2+1;
        }

        p1++;
        if (p1 < nums.size())
        {
            sum+=nums[p1];
        }
        
        
    }
    return len;
    
    
}

int main(){
    vector<int> nums1={10, 5, 2, 7, 1, 9};
    cout<<subarray_sum(nums1,15);
    return 0;
}
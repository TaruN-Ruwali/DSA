#include<bits/stdc++.h>
using namespace std;

int largest(vector<int> nums){
     //Brute Force          time- O(nlogn) space- O(1)

    stable_sort(begin(nums),end(nums));
    return nums.back();

    // Optimal               time- O(n) space- O(1)

    int large=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]>large){
            large=nums[i];
        }
    }
    return large;
    
}

pair <int,int> second_largest(vector<int> nums){



    // Brute Force      time- O(nlogn) space- O(1)

    /*
    Sort the array in ascending order.
    The element at the second index (index 1) is the second smallest element.
    The element at the second index from the end (index length-2) is the second largest element.
    */

    // if (nums.size()<=1)
    // {
    //     return {-1,-1};
    // second
    

    // std:stable_sort(begin(nums),end(nums));
    // pair<firstnt,int> p={nums[1],nums[nums.size()-2]};
    // return p;

    //Better Approach           time- O(n) space- O(1)

    /*
    Perform a single traversal to find the smallest and largest elements in the array.
    After that, traverse the array again to find the element just greater than the smallest element (this will be the second smallest).
    Similarly, find the element just smaller than the largest element (this will be the second largest).
    */
    // int large=nums[0],small=nums[0];
    // for (int i = 1; i < nums.size(); i++)
    // {
    //     if (nums[i]>large)
    //     {
    //         large=nums[i];
    //     }
    //     if (nums[i]<small)
    //     {
    //         small=nums[i];
    //     } 
    // }

    // cout<<small<<" "<<large<<endl;
    
    // pair<int,int> s={nums[0],nums[0]};
    // for (int i = 1; i < nums.size(); i++)
    // {
    //     if (nums[i]<large && nums[i]>s.second)
    //     {
    //         s.second=nums[i];
    //     }
    //     else if (nums[i]>small && nums[i]<s.first)
    //     {
    //         s.first=nums[i];
    //     } 
        
    // }
    // return s;

    // Optimal         time- O(n) space- (1)

    /*
    We will need four variables: small, second_small, large, and second_large. Initialize small and second_small to INT_MAX, and large and second_large to INT_MIN.
    Second Smallest Algorithm:
        If the current element is smaller than 'small', update the values of second_small and small.
        Else if the current element is smaller than 'second_small', update the value of second_small.
        After traversing the array, the second smallest element will be stored in the variable second_small.
    Second Largest Algorithm:
        If the current element is larger than 'large', update the values of second_large and large.
        Else if the current element is larger than 'second_large', update the value of second_large.
        After traversing the array, the second largest element will be stored in the variable second_large.
    */
    int large,s_large,small,s_small;
    large=s_large=small=s_small=nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i]>large)
        {
            s_large=large;
            large=nums[i];
        }
        if (nums[i]<small)
        {
            s_small=small;
            small=nums[i];
        }
        
    }
    return {s_small,s_large};
}

bool issort(vector<int> nums){
    //Brute Force       time- O(n^2)  space- O(1)
    /*
    The idea is pretty simple here, We will start with the element at the 0th index, and will compare it with all of its future elements that are present in the array.
    If the picked element is smaller than or equal to all of its future values then we will move to the next Index/element until the whole array is traversed.
    If any of the picked elements is greater than its future elements, Then simply we will return False.
    If the size of the array is Zero or One i.e ( N = 0 or N = 1 ) or the entire array is traversed successfully then we will simply return True.
    */
    
    // Optimal Approach         time- O(n)   space- O(1)
    /*
    As we know that for a sorted array the previous of every element is smaller than or equal to its current element.
    So, Through this, we can conclude that if the previous element is smaller than or equal to the current element then. Then we can say that the two elements are sorted. If the condition is true for the entire array then the array is sorted.
    We will check every element with its previous element if the previous element is smaller than or equal to the current element then we will move to the next index.
    If the whole array is traversed successfully or the size of the given array is zero or one (i.e N = 0 or N = 1). Then we will return True else return False.
    */
    if (nums.size()==0 || nums.size()==1)
    {
        return true;
    }
    
    bool sort=true;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i-1]>nums[i])
        {
            return false;
        }
        
    }
    return true;
    
}

int main(){
    vector<int> nums={6,5,4,3,2};
    
    cout<<issort(nums)<<endl;
    return 0;
}
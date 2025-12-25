#include<bits/stdc++.h>
using namespace std;

int largest(vector<int>& nums){
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

pair <int,int> second_largest(vector<int>& nums){



    // Brute Force      time- O(nlogn) space- O(1)

    /*
    Sort the array in ascending order.
    The element at the second index (index 1) is the second smallest element.
    The element at the second index from the end (index length-2) is the second largest element.
    */

    if (nums.size()<=1)
    {
        return {-1,-1};
    }
    

    std:stable_sort(begin(nums),end(nums));
    pair<int,int> p={nums[1],nums[nums.size()-2]};
    return p;

    //Better Approach           time- O(2n) space- O(1)

    /*
    Perform a single traversal to find the smallest and largest elements in the array.
    After that, traverse the array again to find the element just greater than the smallest element (this will be the second smallest).
    Similarly, find the element just smaller than the largest element (this will be the second largest).
    */
    int large=nums[0],small=nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i]>large)
        {
            large=nums[i];
        }
        if (nums[i]<small)
        {
            small=nums[i];
        } 
    }

    cout<<small<<" "<<large<<endl;
    
    pair<int,int> s={nums[0],nums[0]};
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i]<large && nums[i]>s.second)
        {
            s.second=nums[i];
        }
        else if (nums[i]>small && nums[i]<s.first)
        {
            s.first=nums[i];
        } 
        
    }
    return s;

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
    large=small=nums[0];
    s_large=s_small=-1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i]>large)
        {
            s_large=large;
            large=nums[i];
        }
        else if (nums[i]<large && nums[i]>s_large)
        {
            s_large=nums[i];
        }
        if (nums[i]<small)
        {
            s_small=small;
            small=nums[i];
        }
        else if (nums[i]>small && nums[i]<s_small)
        {
            s_small=nums[i];
        }
        
    }
    return {s_small,s_large};
}

bool issort(vector<int>& nums){
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

int removeduplicate(vector<int>& nums){

    // Brute Force              time- O(nlogn + n)  space- O(n)

    set<int> seen;
    for (int i = 0; i < nums.size(); i++)
    {
        seen.insert(nums[i]);   //insert takes time- logn
    }
    int j=0;
    for (auto i : seen )
    {
        nums[j]=i;
        j++;
    }
    
    return j;

    // Optimal   (Two pointer approach)       time-O(n)    space-O(1)

    /*
    Take 2 pointers p1,p2 . Place p1 at 0th index which will alwys be part of unique array.
    start a loop of p2 from 1 to nums.size() 
    compare the elements nums[p1] & nums[p2]
    if not equal - replace nums[p1+1] position with nums[p2] and shift p1 i.e. p1++
    if equal - skip
    at last return p1+1
    */

    int p1=0;
    
    for (int p2 = 1; p2 < nums.size(); p2++)
    {
        
        if (nums[p1]!=nums[p2])
        {
            nums[p1+1]=nums[p2];
            p1++;
        }

        
    }
    
    return p1+1;
}


int main(){
    vector<int> nums={1,1,2,2,2,3,3};
    int j=removeduplicate(nums);
    for (int i = 0; i < j; i++)
    {
        cout<<nums[i]<<" "<<endl;
    }
    
    
    return 0;
}
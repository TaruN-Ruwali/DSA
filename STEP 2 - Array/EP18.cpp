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

void rotate_k_left(vector<int>& nums, int k){//incomplete

    // Brute Force              time- O(3n)  space- O(n)

    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i]=nums[i];
    }
    for (int i = k; i < nums.size(); i++)
    {
        nums[i-k]=nums[i];
    }
    for (int i = 0; i < k; i++)
    {
        nums[nums.size()-k+i]=temp[i];
    }
    
}

void rotate_k_right(vector<int>& nums, int k){//incomplete
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i]=nums[i];
    }
    for (int i = k; i < nums.size(); i++)
    {
        nums[i-k]=nums[i];
    }
    for (int i = 0; i < k; i++)
    {
        nums[nums.size()-k+i]=temp[i];
    }
    
}

void movezeros(vector<int>& nums){

    // Brute Force              time- O(n)      space- O(n)

    // int temp[nums.size()]={0};
    // int k=0;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i]!=0)
    //     {
    //         temp[k]=nums[i];
    //         k++;
    //     }
        
    // }
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     nums[i]=temp[i];
    // }


    // Optimal      time- O(n)      space- O(1)
    /*
    we will use 2 pointer approach.
    1st pointer will point towards the 0th index.
    2nd pointer will traverse and find the non zero elements .
    adn when found one it will swap the 1st pointer with 2nd adn increase position of 1st.
    */

    int p1=-1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i]==0)
        {
            p1=i;
            break;
        }
        
    }
    
    for (int p2 = 1; p2 < nums.size(); p2++)
    {
        if (nums[p2]!=0)
        {
            nums[p1]=nums[p2];
            nums[p2]=0;
            p1++;
        }
        
    }
    

}

int Linear_search(vector<int>& nums,int target){
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i]==target)
        {
            return i;
        }
        
    }
    return -1;
    
}

void unin(vector<int>& nums1, vector<int>& nums2){
    set<int> st;
    for (int i = 0; i < nums1.size(); i++)
    {
        st.insert(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        st.insert(nums2[i]);
    }
    int j=0;
    nums1[nums1.size()+nums2.size()];
    for (auto i : st)
    {
        nums1[j]=i;
        j++;
    }
    
 
}
int main(){
    vector<int> nums1={1,2,3,4,5,6,7,8,9,10};
    vector<int> nums2={2,3,4,4,5,11,12};
    // rotate1(nums);
    // rotate_k_left(nums,2);
    // movezeros(nums);
    // cout<<Linear_search(nums,13);
    unin(nums1,nums2);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout<<nums1[i]<<" ";
    }
    

    return 0;
}
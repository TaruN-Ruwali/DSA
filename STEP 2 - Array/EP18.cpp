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

    // Brute Force              time- O(3n=n)  space- O(n)
    
    k=k%nums.size(); 
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

    // Optimal          time- O(n)      space-O(1)

    /*
    Use reversal algo.
    reverse first k elements
    reverse remaining elements(k to end)
    at last reverse whole array(begin to end)
    */
    
    int n=nums.size();
    if (k<0)
    {
        cout<<"Invalid Rotation"<<endl;
        return;
    }
    
    k=k%n;
    if (k==0)
    {
        return;
    }
    
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    reverse(nums.begin(),nums.end());
    
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

    int temp[nums.size()]={0};
    int k=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i]!=0)
        {
            temp[k]=nums[i];
            k++;
        }
        
    }
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i]=temp[i];
    }


    // Optimal      time- O(n)      space- O(1)
    /*
    we will use 2 pointer approach.
    1st pointer will point towards the 0th index.
    2nd pointer will traverse and find the non zero elements .
    and when found one it will swap the 1st pointer with 2nd and increase position of 1st.
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
            swap(nums[p1],nums[p2]);
            // nums[p2]=0;
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

vector<int> unin(vector<int>& nums1, vector<int>& nums2){

    // Brute Force              time- O(n1logn + n2logn) + O(n1+n2)         space- O(n1+n2) + O(n1+n2)//only used for returning result
    /*
    Insert both arrays in set(stores unique element)
    return an union array with all elements
    */
    // set<int> st;
    // for (int i = 0; i < nums1.size(); i++)
    // {
    //     st.insert(nums1[i]);
    // }

    // for (int i = 0; i < nums2.size(); i++)
    // {
    //     st.insert(nums2[i]);
    // }
    // int unin[st.size()],j=0;
    // for (auto i : st )
    // {
    //     unin[j]=i;
    //     j++;
    // }
    
    // for (int i = 0; i < st.size(); i++)
    // {
    //     cout<<unin[i]<<" ";
    // }

    // // Optimal (2 pointer )         time- O(n1+n2)      space- O(n1+n2)//only to return not solve
    
    // int n1=nums1.size();
    // int n2=nums2.size();
    // int i=0,j=0;
    // vector<int> unionarr;
    // while (i < n1 && j < n2)
    // {
    //     if (nums1[i] <= nums2[j])
    //     {
    //         if (unionarr.size()==0 || unionarr.back() != nums1[i])    
    //         {
    //             unionarr.push_back(nums1[i]);
    //         }
    //         i++;
          
    //     }
    //     else
    //     {
    //         if (unionarr.size()==0 || unionarr.back() != nums2[j])    
    //         {
    //             unionarr.push_back(nums2[j]);
    //         }
    //         j++; 

    //     }
    // }

    // while (j < n2)
    // {
    //         if (unionarr.size()==0 || unionarr.back() != nums2[j])    
    //         {
    //             unionarr.push_back(nums2[j]);
    //         }
    //         j++;   
    // }

    // while (i < n1)
    // {
    //         if (unionarr.size()==0 || unionarr.back() != nums1[i])    
    //         {
    //             unionarr.push_back(nums1[i]);
    //         }
    //         i++;   
    // }
    // for (int i = 0; i < unionarr.size(); i++)
    // {
    //     cout<<unionarr[i]<<" ";
    // }
    
    // return unionarr;
}

int missing_no(vector<int>& nums){
    // Brute Force          time-   O(n^2)     space-  O(1)

    // int n=nums.size();
    // for (int i = 0; i < n; i++)   
    // {
    //     bool found=false;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (nums[j]==i)
    //         {
    //             found=true;
    //             break;
    //         }    
    //     }
    //     if (found==false)
    //     {
    //         return i;
    //     }
    // }  

    // Optimal (Sum of n natural no.s)      time- O(n)      space- O(1)

    // int n=nums.size();
    // int expected_sum=(n*(n+1))/2;
    // int actual_sum=0;
    // for (int i = 0; i < n; i++)
    // {
    //     actual_sum+=nums[i];
    // }
    // return (expected_sum-actual_sum);

    // Optimal  (XOR Operator)      time- O(n)      space- O(1)

    int n=nums.size();
    int xor_op=0;
    for (int i = 1; i <= n; i++)
    {
        xor_op=xor_op^i;
    }
    for (int i = 0; i < n; i++)
    {
        xor_op=xor_op^nums[i];
    }

    return xor_op;    
}

int max_consecutive_ones(vector<int>& nums){
    int max=0,j=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i]==1)
        {
            j++;
        }
        else
        {
            j=0;
        }
        if (j > max)
        {
            max = j;
        }
        
    }
    return max;
}

int main(){
    vector<int> nums1={9,6,4,2,3,5,7,0,1};
    // vector<int> nums2={2,3,4,4,5};

    // rotate1(nums);

    // rotate_k_left(nums1,20001);

    // movezeros(nums);

    // cout<<Linear_search(nums,13);

    // unin(nums1,nums2);

    // for (int i = 0; i < nums1.size(); i++)
    // {
    //     cout<<nums1[i]<<" ";
    // }

    cout<<missing_no(nums1)<<endl;
    
    // cout<<max_consecutive_ones(nums1)<<endl;
    

    return 0;
}
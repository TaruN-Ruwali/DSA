#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& nums){

    // Brute Force              time- O(n^2)        space- O(n) [for returning]

    /*
    In this brute force approach, we start by checking all the elements from the start of the array to the end to determine if an element is greater than all the elements to its right (i.e., the leader).
    We use nested loops for this:
    The outer loop checks each element in the array to see if it is a leader.
    The inner loop checks if there is any element to the right that is greater than the element being currently processed by the outer loop.
    Begin by initializing the outer loop pointer at the start element and set it as the current leader.
    If any element traversed is found to be greater than the current leader, the element is not considered a leader, and the outer loop pointer is incremented by 1, setting the next element as the current leader.
    If no other element to the right is greater than the current element, it is added to the answer array as a leader element.
*/
    // int n = nums.size();
    // vector<int> result;
    // for (int i = 0; i < n; i++)
    // {
    //     bool leader = true;
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if (nums[i] < nums[j])
    //         {
    //             leader = false;
    //         } 
    //     }

    //     if(leader==true){
    //         result.push_back(nums[i]);
    //     }
        
    // }
    // return result;

    // Optimal Solution                 time-O()        space- O()

    /*
    Enter last element in result array.
    start loop from (n-2)th element till 0th, max = nums[n-1].
    if(nums[i] > max) , enter nums[i] in result array and max = nums[i].
    at last reverse the whole array and give back.
    */

    int n=nums.size();

    vector<int> result;
    result.push_back(nums[n-1]);
    int max=nums[n-1];

    for (int i = n-2; i >= 0; i--)
    {
        if(nums[i] > max){
            result.push_back(nums[i]);
            max = nums[i];
        }
    }

    reverse(result.begin(),result.end());

    return result;
    

    
}

int main(){
    
    vector<int> nums = {10, 22, 12, 3, 0, 6};

    vector<int> ans = leaders(nums);

    cout << "Leaders in the array are: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
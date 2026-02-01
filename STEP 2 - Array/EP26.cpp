#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {

        // Brute        time- O(n+n/2)     space- O(n+n/2)
        
        // int n=nums.size();
        // int p=0,n1=0;
        // int positive[n/2], negative[n/2];
        // for(int i=0;i<n;i++){
        //     if(nums[i] > 0){
        //         positive[p]=nums[i];
        //         p++;
        //     }
        //     else{
        //         negative[n1]=nums[i];
        //         n1++;
        //     }
        // }
        // p=0,n1=0;
        // for(int i=0;i<n;i++){
        //     if((i%2)==0){
        //         nums[i]=positive[p];
        //         p++;
        //     }
        //     else{
        //         nums[i]=negative[n1];
        //         n1++;
        //     }
        // }
        // return nums;

        // Optimal      time- (n)    space- (1)

        int n=nums.size();
        vector<int> result(n);
        int positive = 0, negative = 1;
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                result[positive] = nums[i];
                positive = positive +2;
            }
            else{
                result[negative] = nums[i];
                negative = negative + 2;
            }
        }
        return result;

    }

int main(){
    // Initialize the input array
    vector<int> A = {1, 2, -4, -5};

    // Call the rearrange function
    vector<int> result = rearrangeArray(A);

    // Print the rearranged array
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
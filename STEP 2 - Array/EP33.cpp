#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {

        // Brute (Will give TLE)        Time-O(n^3)     Space-O(1)

        // int n = nums.size();
        // int sum=0,count=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         sum=0;
        //         for(int l=i;l<=j;l++){
        //             sum+=nums[l];
        //         }
        //         if(sum==k){
        //             count++;
        //         }

        //     }
        // }
        // return count;

        // Better               time-O(n^2)     space-O(1)

        int n = nums.size();
        int sum=0,count=0;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k)count++;
            }
        }
        return count;
    }

int main(){
    // Input array
    vector<int> arr = {3, 1, 2, 4};

    // Target sum
    int k = 6;

    int result = subarraySum(arr, k);

    // Print the count of subarrays
    cout << "The number of subarrays is: " << result << "\n";
    return 0;
}
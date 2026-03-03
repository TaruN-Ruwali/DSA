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

        // int n = nums.size();
        // int sum=0,count=0;
        // for(int i=0;i<n;i++){
        //     sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==k)count++;
        //     }
        // }
        // return count;

        // Optimal (Pre-fix)        time-O()       space-O(n)

        int n = nums.size();

        // Map to store frequency of prefix sums
        unordered_map<int, int> prefixSumCount;

        // Initialize prefix sum and count of subarrays
        int prefixSum = 0;
        int count = 0;

        // Base case: prefix sum 0 has occurred once
        prefixSumCount[0] = 1;

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            // Add current element to prefix sum
            prefixSum += nums[i];

            // Calculate the prefix sum that needs to be removed
            int remove = prefixSum - k;

            // If this prefix sum has been seen before,
            // add its count to the result
            if (prefixSumCount.find(remove) != prefixSumCount.end()) {
                count += prefixSumCount[remove];
            }

            // Update the frequency of the current prefix sum
            prefixSumCount[prefixSum]++;
        }

        // Return the total count of subarrays
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
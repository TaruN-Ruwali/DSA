#include<bits/stdc++.h>
using namespace std;


int longestConsecutive(vector<int>& nums) {

            // Brute Approach       time-O(nlogn)       space- O(n)

    //    sort(nums.begin(),nums.end());
       
    //    int n = nums.size();
    //    if(n == 0)return 0;
       
    //    int count=1;
    //    int max_count=1;
       
    //    for(int i=0;i<n-1;i++){
    //         if(nums[i]+1 == nums[i+1]){
    //             count++;
    //         }
    //         else if(nums[i] == nums[i+1]){
    //             continue;
    //         }
    //         else{
    //             count=1;
    //         }
    //         max_count = max(count,max_count);
            
    //    } 
    //    return max_count;

        // Optimal

        int n = nums.size();
        if(n==0)return 0;

        unordered_set<int> st;
        int max_count=1;

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int count=1;
                int x=it;

                while(st.find(x+1) != st.end()){
                    count++;
                    x++;
                }
                max_count = max(count , max_count);
            }
        }
        return max_count;

    }

int main(){
    vector<int> a = {100, 4, 200, 1, 3, 2};


    int ans = longestConsecutive(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
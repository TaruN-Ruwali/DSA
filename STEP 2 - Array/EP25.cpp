#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {

        // Brute (time limit exceded)       time-O(n^2)     space-O(1)

        // int max;
        // for(int i=0;i<prices.size()-1;i++){
        //     for(int j=i+1;j<prices.size();j++){
        //         if((prices[j]-prices[i]) > max){
        //             max=prices[j]-prices[i];
        //         }
        //     }
        // }
        // if(max<0){
        //     return 0;
        // }
        // return max;

        // Optimal      time- O(n)      space- (1)

        int max_profit=0,min=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min){
                min=prices[i];
            }
            if((prices[i]-min) > max_profit){
                max_profit = prices[i] - min;
            }
        }
        
        return max_profit;
    }

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices) << endl;
    return 0;
}
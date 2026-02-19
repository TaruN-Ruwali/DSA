#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {

        // Brute        time-O(n^2)     space- O(n^2)

        // int n = matrix.size();
        // if(n==1){
        //     return;
        // }
        // int temp =n;
        // vector<vector<int>> rotate(n,vector<int> (n));
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++){
        //         rotate[j][temp-1]=matrix[i][j];
        //     }
        //     temp--;
        // }
        // matrix = rotate;

        // Optimal          time-O(n^2)     space-O(1)

        int n = matrix.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j>i){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
     
    }

int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate(matrix);

    // Print rotated matrix
    for (auto row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
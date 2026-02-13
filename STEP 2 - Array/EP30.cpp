#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {

        // Brute (will give TLE)        time- O(m*n*(m+n))  space- O(1)

        // int r = matrix.size();
        // int c = matrix[0].size();

        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         if(matrix[i][j] == 0){
        //             for(int k=0;k<r;k++){
        //                 if(matrix[k][j] != 0){
        //                     matrix[k][j]=-1;
        //                 }
        //             }

        //             for(int k=0;k<c;k++){
        //                 if(matrix[i][k] != 0){
        //                     matrix[i][k]=-1;
        //                 }
        //             }
        //         }
        //     }
        // }

        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         if(matrix[i][j]==-1){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }
        
    }

int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    
    setZeroes(matrix);
    
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
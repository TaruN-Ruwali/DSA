#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> matrix(5,vector<int>(5));
    pair<int,int> point;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>matrix[i][j];
            if (matrix[i][j]!=0)
            {
                point={i+1,j+1};
            } 
        }
    }

    int moves = abs(point.first-3) + abs(point.second - 3);
    cout<<moves<<"\n";
    
    return 0;
}
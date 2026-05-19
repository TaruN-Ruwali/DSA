#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;

    vector<int> arr;

    for(auto it:s){
        if(it!='+')arr.push_back(int(it));
    }
    sort(arr.begin(),arr.end());

    string ans="";

    for(int i=0;i<arr.size()-1;i++){
        ans+=arr[i];
        ans+='+';
    }
    ans+=arr[arr.size()-1];

    cout<<ans;

    return 0;
}
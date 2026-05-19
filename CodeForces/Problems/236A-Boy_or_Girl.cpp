#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    unordered_map<char,int> freq;

    for (int i = 0; i < s.size(); i++)freq[s[i]]++;
    
    if(freq.size()%2==0)cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    while (n--)
    {
        string s;cin>>s;
        int l=s.size();
        
        if (l>10)
        {
            cout<<s[0];
            cout<<l-2;
            cout<<s[l-1]<<"\n";
        }
        else{
            cout<<s<<"\n";
        }
    }
    
    return 0;
}
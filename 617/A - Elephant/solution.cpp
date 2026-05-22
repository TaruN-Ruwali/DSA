#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int x;cin>>x;
    int ans,step=0;
    int i=5;
    while(x>0)
    {
        ans=x/i;
        step+=ans;
        x-=i*ans;
        i--;
    }
    cout<<step<<"
";
    
    return 0;
}
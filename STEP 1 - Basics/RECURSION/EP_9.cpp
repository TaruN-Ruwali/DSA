// #include<iostream>
// using namespace std;

// int sum =0;

// void print(int n){
//     if (n ==0)
//     {
//         cout<<"The sum is :"<<sum;
//         return;
//     }
    
//     sum+=n;
//     n--;
//     print(n);
// }


// int main(){
//     int n;
//     cout<<"Enter range:";
//     cin>>n;
    
//     print(n);
//     return 0;
// }

                                        //Print numbers 1-N using Backtrack

// #include<iostream>
// using namespace std;

// void print(int n){
//     if (n==0)   
//     {
//         return;
//     }
//     print(n-1);
//     cout<<n<<endl;
    
// }

// int main(){
//     int n;
//     cout<<"Enter Range:";
//     cin>>n;
//     print(n);
//     return 0;
// }

                                        //Print numbers N-1 using Backtrack

#include<iostream>
using namespace std;

void print(int i,int n){
    if(n==0){
        return ;
    }
    print(i+1,n-1);
    cout<<i;
}

int main(){
    int n,i=1;
    cout<<"Enter range:";
    cin>>n;
    print(i,n);
    return 0;
}
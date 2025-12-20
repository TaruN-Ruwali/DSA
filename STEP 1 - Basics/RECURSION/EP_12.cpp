                    // Fibonacci Series using Recursion

#include<iostream>
using namespace std;

// int fibonacci(int n){
//     if (n<=1)
//     {
//         return n;
//     }
//     int l=fibonacci(n-1);
//     int sl=fibonacci(n-2);
    
//     return l+sl;
// }

int fibonacci(int n){
    if (n<=1)
    {
        return n;
    }
    int l=fibonacci(n-1);
    int sl=fibonacci(n-2);

    return sl+l;
    
}

int main(){
    int n;
    cout<<"Enter range:-";
    cin>>n;
    n=fibonacci(n);
    return 0;
}
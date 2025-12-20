                    // Sum of N number using recursion back track

// #include<iostream>
// using namespace std;

// int sum(int n){
//     if (n==0)
//     {
//         return 0;
//     }
//     return n+sum(n-1);

// }

// int main(){
//     int n;
//     cout<<"Enter Number:";
//     cin>>n;
//     n=sum(n);
//     cout<<"The sum is:"<<n<<endl;
//     return 0;
// }

                            // Factorial of a given number N using backtrack

#include<iostream>
using namespace std;

int fact(int n){
    if (n==1)
    {
        return 1;
    }
    return n*fact(n-1);
    
}

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    n=fact(n);
    cout<<"The factorial is :"<<n<<endl;
    return 0;
}
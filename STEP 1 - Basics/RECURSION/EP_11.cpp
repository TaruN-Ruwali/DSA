                                //Reverse an array with recursion

// #include<iostream>
// using namespace std;

// void rev(int n,int *arr,int i){
//     if (i==n/2)
//     {
//         return;
//     }
//     int temp;
//     temp=arr[i];
//     arr[i]=arr[n-1-i];
//     arr[n-1-i]=temp;
//     rev(n,arr,i+1);
    
// }

// void arrin(int n,int *arr){
//     for (int i = 0; i < n; i++)
//     {
//         cout<<"Enter element "<<i+1<<":";
//         cin>>arr[i];
//     }
    
// }

// void arrout(int n,int *arr){
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<endl;
//     }
    
// }

// int main(){
//     int n,arr[20];
//     cout<<"Enter range:";
//     cin>>n;
//     arrin(n,arr);
//     rev(n,arr,0);
//     arrout(n,arr);

//     return 0;
// }

                                            //Checking Palindrome using recursion

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;


// bool isPalindrome(int i,string &s){
//     if (i>=s.size()/2)
//     {
//         return true;
//     }
    
//     if (s[i] != s[s.size() -1 -i])
//     {
//         return false;
//     }
//     return isPalindrome(i+1,s);
    
    
// }

// int main(){
//     string s;
//     cout<<"Enter string:";
//     cin>>s;
//     if (isPalindrome(0,s)==true)
//     {
//         cout<<"The string is Palindrome";
//     }
//     else{
//         cout<<"The string is not a Palindrome";
//     }
    
//     return 0;
// }



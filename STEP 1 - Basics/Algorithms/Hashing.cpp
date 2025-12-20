                                    // Counting frequency of int array


// #include<iostream>
// using namespace std;

// int main(){
//     int arr[25]={1,2,3,2,1,4,5,3,2,3,4,2,3,4,5,2,1};
//     int hash[6]={0};

//     for (int i = 0; i < 17; i++)
//     {
//         hash[arr[i]]+=1;
//     }

//     cout<<hash[1]<<endl;
//     cout<<hash[2]<<endl;
//     cout<<hash[3]<<endl;
//     cout<<hash[4]<<endl;
//     cout<<hash[5]<<endl;
    

//     return 0;
// }

                        // Find the highest/lowest frequency of a char in string

// #include<iostream>
// using namespace std;

// int main(){
//     string s;
//     int hash[26]={0},i=0;
//     cin>>s;

//     while (s[i]!='\0')  // instead of while loop you can also use for like => (int i=0;i<s.size();i++)
//     {
//         hash[s[i]-'a']+=1;
//         i++;
//     }

//     for (int i = 0; i < 26; i++)
//     {
//         cout<<char(i+'a')<<hash[i]<<endl;
//     }
    
    
//     return 0;
// }


                                                // Hash Mapping

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    //cout<<endl<<mpp[1];     //Inside the [] bracket is the number whoose frequency is to be found.

    for(int i=0;i<n;i++)
    {
        cout<<endl<<mpp[i];     //This loop will iterate through the map and show you that the map is stored in a sorted manner.
    }    
    
    //Alternative approach to iterate

    for(auto i:mpp){
        cout<<endl<<i.first<<"->"<<i.second<<endl; //Every map has key,value pair here i.first is key,i.second is value
    }
    
    return 0;
}
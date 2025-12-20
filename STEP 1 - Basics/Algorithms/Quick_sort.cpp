#include<bits/stdc++.h>
using namespace std;

int f(int* arr,int low,int high);
int f(int* arr,int low,int high){
    int pivot=arr[low];
    int i=low,j=high;
    while (i<j)
    {
        while (i<=high-1 && arr[i]<= pivot)
        {
            i++;
        }
        while (j>=low+1 && arr[j]> pivot)
        {
            j--;
        }
        if (i<j)
        {
            swap(arr[i],arr[j]);
        }
        
    }
    swap(arr[low],arr[j]);
    
    return j;
}

void qs(int* arr,int low,int high);
void qs(int* arr,int low,int high){
    if (low<high)
    {
        int part=f(arr,low,high);
        qs(arr,low,part-1);
        
        qs(arr,part+1,high);
    }
   
    
}

int main(){
    int n,low,high;
    cout<<"Enter range:-";
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    
    qs(arr,0,n-1);
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
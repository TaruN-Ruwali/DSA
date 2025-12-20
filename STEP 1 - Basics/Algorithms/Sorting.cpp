

#include<bits/stdc++.h>
using namespace std;

void selection_sort(int* arr,int n){
    for (int i = 0; i < n-2; i++)
    {
        int min=i;
        for (int j = i; j < n-1; j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;
                
            } 
        }
        int temp;           //Can also use swap function:- swap(arr[i],arr[min]);
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;   
    }
}

void bubble_sort(int* arr, int n){//Bubble sort
    for (int i = 0; i < n-1; i++)
    {
        int swap=0;
        for (int j = 0; j < n-i-1; j++)
        {
            
            if (arr[j]>arr[j+1])
            {
                swap=1;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        if (swap==0)
        {
            return;
        }
        
    }

}

void insertion_sort(int* arr, int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j > 0; j--)
        {
            if (arr[j-1]>arr[j])
            {
                swap(arr[j-1],arr[j]);
            }
            
        }
        
    }
    
}

int main(){
    int n;
    cout<<"Enter range:-";
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    insertion_sort(arr,n);
    

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}


                        // Sum of all even elements of array

// #include <stdio.h>

// int evensum(int *arr,int n){
//     int sum=0;
//     for (int i = 1; i < n; i+=2)
//     {
//         sum+=arr[i];
//     }
//     return sum;
// }

// int main(){
//     int arr[20],n;
//     printf("Enter range:");
//     scanf("%d",&n);

//     for (int i = 0; i < n; i++)
//     {
//         printf("Enter %d element:",i+1);
//         scanf("%d",&arr[i]);
//     }
    
//     n=evensum(arr,n);
//     printf("The sum of even Elements:%d",n);
//     return 0;
// }

                                    // Union of 2 arrays

// #include <stdio.h>

// int main(){
//     int arr1[40],arr2[20],n1,n2;
//     printf("Enter range1:-");
//     scanf("%d",&n1);
//     printf("Enter range2:-");
//     scanf("%d",&n2);

//     printf("Enter array1:");
//     for (int i = 0; i < n1; i++)
//     {
//         scanf("%d",&arr1[i]);
//     }
//     printf("Enter array2:");
//     for (int i = 0; i < n2; i++)
//     {
//         scanf("%d",&arr2[i]);
//     }
    
//     for (int i = 0; i < n1; i++)
//     {
//         printf("%d ",arr1[i]);
//     }
//     for (int i = 0; i < n2; i++)
//     {
//         int flag=0;
//         for (int j = 0; j < n1; j++)
//         {
//             if (arr2[i]==arr1[j])
//             {
//                 flag++;
//                 break;
//             }
            
//         }

//         if (flag==0)
//         {
//             printf("%d ",arr2[i]);
//         }

//     }
//     return 0;
// }

                                        // Intersection of 2 array

// #include <stdio.h>

// int main(){
//     int arr1[40],arr2[40],n1,n2;

//     printf("Enter range 1:-");
//     scanf("%d",&n1);
//     printf("Enter range 2:-");
//     scanf("%d",&n2);

//     printf("Enter array 1:-");
//     for (int i = 0; i < n1; i++)
//     {
//         scanf("%d",&arr1[i]);
//     }

//     printf("Enter array2:");
//     for (int i = 0; i < n2; i++)
//     {
//         scanf("%d",&arr2[i]);
//     }

//     for (int i = 0; i < n1; i++)
//     {
//         for (int j = 0; j < n2; j++)
//         {
//             if (arr1[i]==arr2[j])
//             {
//                 printf("%d ",arr1[i]);
//             }
            
//         }
        
//     }

//     return 0;
// }

                                                // Reverse array

// #include <stdio.h>

// int main(){
//     int arr[40],n;

//     printf("Enter range:-");
//     scanf("%d",&n);

//     printf("Enter array:");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",&arr[i]);
//     }

//     for (int i = n-1; i >= 0; i--)
//     {
//         printf("%d ",arr[i]);
//     }
    
    
//     return 0;
// }

                                        // Max element of an array

// #include <stdio.h>

// int main(){
//     int arr[40],n;

//     printf("Enter range:-");
//     scanf("%d",&n);

//     printf("Enter array:\n");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",&arr[i]);
//     }

//     int max= arr[0];

//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i]>max)
//         {
//             max=arr[i];
//         }
        
//     }

//     printf("Max :- %d",max);
    
    
//     return 0;
// }

                                                // Dynamic Array

// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     int *arr,n;

//     printf("Enter size:-");
//     scanf("%d",&n);

//     arr=(int*)malloc(n*(sizeof(int)));

//     if (arr == NULL)    
//     {
//         printf("Memory allocation failed");
//         return 0;
//     }

//     printf("Enter array:-\n");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",&arr[i]);
//     }
    
//     printf("Dyanmic array:-\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ",arr[i]);
//     }

//     free(arr);
    

//     return 0;
// }

                                            // Stack using array

// #include <stdio.h>
// int stack[100],top = -1;

// void push(int n){
//     if (top == 99)
//     {
//         printf("Stack Overflow\n");
//     }
//     else{
//         top++;
//         stack[top]=n;
//         printf("Element pushed!!!\n");
//     }
// }

// void pop(){
//     if (top == -1)
//     {
//         printf("Stack is Empty\n");
//     }
//     else{
//         printf("%d Popped",stack[top]);
//         // stack[top] = NULL;
//         top--;
//     }
    
// }

// void display(){
//     for (int i = 0; i <= top; i++)
//     {
//         printf("%d ",stack[i]);
//     }
    
// }


// int main(){
//     int n,c;

//     while (1)
//     {
        // printf("\t\t\tMENU\n\n1.Push\n2.Pop\n3.Dispaly\n4.Exit\n");
        // scanf("%d",&c);
        // if (c == 1)
        // {
        //     printf("Enter element:-");
        //     scanf("%d",&n);
        //     push(n);
        // }
        // if (c == 2)
        // {
        //     pop();
        // }
        // if (c == 3)
        // {
        //     display();
        // }
        // if (c == 4)
        // {
        //     return 0;
        // }
        
//     }
    
// }

                                            // Queue using array

#include <stdio.h>

int queue[100],front=-1,rear=-1;

void add(int n){
    if (front == -1 && rear == -1)  
    {
        front++;
        rear++;
        queue[rear] = n;
    }
    else if (rear == 99)
    {
        printf("Queue is Full\n");
    }
    else{
        rear++;
        queue[rear] = n;
    }
 
}

void delete(){
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else{
        front++;
    }
    
}

void display(){
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else{
        for (int i = front; i <= rear; i++)
        {
            printf("%d ",queue[i]);
        }
        
    }
}

int main(){
    int n,c;

    while (1)
    {
        printf("\t\t\tMENU\n\n1.Add\n2.Delete\n3.Dispaly\n4.Exit\n");
        scanf("%d",&c);
        if (c == 1)
        {
            printf("Enter element:-");
            scanf("%d",&n);
            add(n);
        }
        if (c == 2)
        {
            delete();
        }
        if (c == 3)
        {
            display();
        }
        if (c == 4)
        {
            return 0;
        }
    }
    
    return 0;
}

#include<iostream>
using namespace std;

void p1(int n){
        for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
        {
            cout<<"*";
        }
       cout<<endl;
    }
}

void p2(int n){
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            cout<<" *";
        }
        cout<<endl;
    }
}

void p3(int n){
        for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<j;
        }
        cout<<endl;   
    }
}

void p4(int n){
        for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<i;
        }
        cout<<endl;   
    }
}

void p5(int n){
        for (int i = 1; i <=n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void p6(int n){
        for (int i = n; i >=1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
}

void p7(int n){
        for (int i = 1; i <= n; i++)
    {
        for (int j = n-i; j > 0; j--)
        {
            cout<<" ";
        }
        for (int k = (2*i)-1; k > 0; k--)
        {
            cout<<"*";
        }
        cout<<endl;
        
    }
}

void p8(int n){
        for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            cout<<" ";
        }
        for (int k = (2*n)-1; k > 2*i; k--)
        {
            cout<<"*";
        }
        cout<<endl;
        
    }
}

void p9(int n){
        for (int i = 1; i <= n; i++)
    {
        for (int j = n-i; j > 0; j--)
        {
            cout<<" ";
        }
        for (int k = (2*i)-1; k > 0; k--)
        {
            cout<<"*";
        }
        
        cout<<endl;
        
    }

      for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            cout<<" ";
        }
        for (int k = (2*n)-1; k > 2*i; k--)
        {
            cout<<"*";
        }
        
        cout<<endl;
        
    }
}

void p10(int n){
      for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
        
    }
}

void p11(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if((i+j)%2!=0){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
        cout<<"\n";
    }
}

void p12(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<j;
        }
        for (int k = 2*i; k < (2*n); k++)
        {
            cout<<" ";
        }
        for (int l = i; l >=1; l--)
        {
            cout<<l;
        }
        cout<<endl;
        
    }
    
}

void p13(int n){
    int a=1;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }
    
}

void p14(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<char(65+j);
        }
        cout<<endl;
    }
    
}

void p15(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            cout<<char(65+j);
        }
        cout<<endl;
    }
    
}

void p16(int n){
    // int c=65;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<char(65+i);
        }
        cout<<endl;
    }
    
}

void p17(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            cout<<" ";
        }
        char ch='A';
        for (int k = 0; k < (2*i)+1; k++)
        {
            cout<<ch;
            if ( k < ((i*2)+1)/2)
            {
                ch++;
            }
            else{
                ch--;
            }
            
        }
        cout<<endl;
        
    }
    
}

void p18(int n){
    for (int i = 0; i < n; i++)
    {
        char ch='E';
        for (char ch = 'E'-i; ch <= 'E' ; ch++)
        {
            cout<<ch;
        }
        cout<<endl;
    }
    
}

void p19(int n){}

void p20(int n){}

void p21(int n){}

void p22(int n){}



int main(){
    int n;
    cin>>n;
    p18(n);
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    char ch;
    string s;
    cout<<"Enter String:";
    cin>>s;

    cout<<s<<endl;
    cout<<"Enter character to remove:";
    cin>>ch;

    int i=0;
    while (s[i]!='\0')
    {
        if (ch==s[i])
        {
            while (s[i]!='\0')
            {
                s[i]==s[i+1];
                i++;
            }
            break;
        }
        i++;    
    }

    cout<<s<<endl;
    
    return 0;
}
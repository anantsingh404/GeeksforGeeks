//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
         int n=s.length();
        int lenn=1;
        int start=0;
        int end=0;
        int i=0;
        while(i<n)
        {
            int flag=i;
            int temp=i;
            while(flag>=0 && temp<n)
            {
                if(s[flag]==s[temp])
                {
                    if(lenn<temp-flag+1)
                    {
                       lenn=temp-flag+1;
                        start=flag;
                        end=temp;
                        //cout<<lenn<<endl;
                    }
                    
                }
                else
                    {
                        break;
                    }
                --flag;
                ++temp;
            }
            ++i;
        }
        int j=0;
        while(j<n-1)
        {
            int flag=j;
            int temp=j+1;
            while(flag>=0 && temp<n)
            {
                if(s[flag]==s[temp])
                {
                    if(lenn<temp-flag+1)
                    {
                        lenn=temp-flag+1;
                        start=flag;
                        end=temp;
                    }
                   
                }
                 else
                    {
                        break;
                    }
                --flag;
                ++temp;
            }
            ++j;
        }
        //cout<<lenn<<endl;
        return s.substr(start,lenn);// code here 
    }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
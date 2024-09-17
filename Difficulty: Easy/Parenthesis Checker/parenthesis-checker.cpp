//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        stack<char>st;
        int i=0;
        int n=s.size();
        while(i<n)
        {
          //  char x=s[i];
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(s[i]==')' && st.top()=='(')
            {
                st.pop();
            }
             else if(s[i]=='}' && st.top()=='{')
            {
                st.pop();
            }
             else if(s[i]==']' && st.top()=='[')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
            
           i++; 
            
        }
        if(st.empty())
        {
            return true;
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
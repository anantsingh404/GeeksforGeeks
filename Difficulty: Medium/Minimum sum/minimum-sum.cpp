//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        string s1="";
        string s2="";
        for(int i=0;i<arr.size();i++)
        {
            if(i%2==0)
            {   
                s1.push_back(arr[i]);
            }
            else
            {
                s2.push_back(arr[i]);
            }
        }
        
        string res="";
        int x=s1.size();
        int y=s2.size();
        int i=x-1;
        int j=y-1;
        int carry=0;
        while(i>=0 && j>=0)
        {
            int p=s1[i]+s2[j]+carry;
            carry=p/10;
            p=p%10;
            res.push_back(p+'0');
             i--;
             j--;
           
            
        }
        while(i>=0)
        {
           int p=s1[i]+carry;
            carry=p/10;
            p=p%10;
            res.push_back(p+'0');
             i--;
              
        }
         while(j>=0)
        {
            int p=s2[j]+carry;
            carry=p/10;
            p=p%10;
            res.push_back(p+'0');
             
             j--;
           
            
        }
        while(carry>0)
        {
           
            int p=carry%10;
            carry=p/10;
            res.push_back(p+'0');
            
             
            
        }
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size();i++)
        {
            if(res[i]!='0')
            {
                res=res.substr(i,res.size()-i);
                break;
            }
        }
        if(res[0]=='0')
        {
            return "0";
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
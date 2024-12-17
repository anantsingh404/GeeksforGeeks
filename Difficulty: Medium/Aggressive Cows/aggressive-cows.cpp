//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool Check(int mid,vector<int>&stalls,int k)
  {
      int n=stalls.size();
      int count=1;
      int i=1;
      int start=stalls[0];
      while(i<n)
      {
          if(stalls[i]-start>=mid)
          {
              ++count;
              start=stalls[i];
          }
          i++;
      }
      return count>=k;
      
  }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int maxi=stalls[n-1]-stalls[0];
       
      int mini=1;
      int ans=0;
      while(mini<=maxi)
      {
          int  mid=(mini+maxi)/2;
          if(Check(mid,stalls,k))
          {
              ans=mid;
              mini=mid+1;
          }
          else{
            maxi=mid-1; 
          }
      }return ans;
      
      
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
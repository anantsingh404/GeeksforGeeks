//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n=arr.size();
       multiset<int>st;
       int flag=false;
       st.insert(arr[n-1]);
       for(int i=n-2;i>=0;i--)
       {
           auto itr=st.upper_bound(arr[i]);
           if(itr!=st.end())
           {    int x=arr[i];
          // cout<<x<<endl;
           
               arr[i]=*itr;
             //  cout<<(*itr)<<endl;
               st.erase(itr);
               st.insert(x);
               int j=i+1;
               for(int it:st)
               { 
                   arr[j++]=(it);
               }
                flag=true;
               break;
              
               
           }
           else
           {  // cout<<arr[i]<<endl;
               st.insert(arr[i]);
           }
       }
       if(flag==false){
       reverse(arr.begin(),arr.end());
       }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
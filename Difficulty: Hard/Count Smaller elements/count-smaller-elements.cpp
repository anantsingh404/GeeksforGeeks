//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
          vector<int> v, ans;
          int n=arr.size();

     ans.push_back(0);

     v.push_back(arr[n-1]);

     for(int i=n-2; i>=0; --i){

 auto ind = lower_bound(v.begin(), v.end(),arr[i]);      

      if(ind != v.end()){

         int dis = distance(v.begin(), ind);

         v.insert(v.begin()+dis,arr[i]); 

         ans.push_back(dis);           

      }else{

          ans.push_back(v.size());

          v.push_back(arr[i]);

      }  }  

     reverse(ans.begin(), ans.end());

      return ans;
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
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
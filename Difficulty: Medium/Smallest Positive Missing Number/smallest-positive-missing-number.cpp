//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<0)
            {
                arr[i]=0;
            }
        }
        for(int i=0;i<arr.size();i++)
        {  
            int x=arr[i]%(10000000);
            if(x>0 && x<=n)
            {   if(arr[x-1]<1e7){
                arr[x-1]+=1e7;
            }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]<1e7)
            {
                return i+1;
            }
        }
        return n+1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends
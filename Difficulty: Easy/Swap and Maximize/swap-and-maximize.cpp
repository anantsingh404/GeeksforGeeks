//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        long long sum=0;
        sort(arr.begin(),arr.end());
        vector<int>temp;
        int j=0;
        int k=n-1;
        for(int i=0;i<n;i++)
        {   if(i%2==0){
            temp.push_back(arr[j]);
            j++;
        }
        else{
            temp.push_back(arr[k]);
            --k;
        }
        }
        arr=temp;
        for(int i=0;i<arr.size()-1;i++)
        {
            sum+=abs(arr[i]-arr[i+1]);
        }
        
        if(arr.size()>1)
        {
            sum+=abs(arr[0]-arr[arr.size()-1]);
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
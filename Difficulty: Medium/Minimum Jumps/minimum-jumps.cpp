//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int n=arr.size();
         int current=0;
       int max=0;
       int jump=0;
       if(n==1)
       {
           return 0;
       }
       
       for(int i=0;i<n-1;i++){
           
           if(i+arr[i]>max){
               
               max=i+arr[i];
           }
           
           if(i==current){
               
               jump++;
               current=max;
           }
           
           if(current>=n-1){
               
               return jump;
           }
           
       }

       return -1;// 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
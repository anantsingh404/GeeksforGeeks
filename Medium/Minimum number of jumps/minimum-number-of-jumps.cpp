//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
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

       return -1;// Your code here
    }
};


// { Driver Code Starts.


  // } Driver Code Ends

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
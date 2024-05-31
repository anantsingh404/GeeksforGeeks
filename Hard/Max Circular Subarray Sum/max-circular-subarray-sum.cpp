//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadane(int arr[],int n)
    {
        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            maxi=max(maxi,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
    }
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int x=kadane(arr,num);
        int sum=accumulate(arr,arr+num,0);
        int maxi=*max_element(arr,arr+num);
        if(maxi<0)
        {
            return maxi;
        }
        for(int i=0;i<num;i++)
        {
            arr[i]=-1*arr[i];
        }
        int y=kadane(arr,num);
        return max(x,sum+y);
        
    }
};


//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
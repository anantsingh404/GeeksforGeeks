//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool check(vector<int>&a,int mid,int n,int m)
    {
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum+a[i]>mid)
            {
                count++;
                sum=a[i];
            }
            else
            {
                sum+=a[i];
            }
        }
        if(sum>0)
        {
            ++count;
        }
        return count<=m;
    }
    //Function to find minimum number of pages.
    int findPages(vector<int>&a, int m) 
    {
        //code here
        int n=a.size();
        int high=accumulate(a.begin(),a.end(),0);
        
        int low=*max_element(a.begin(),a.end());
        if(n<m)
        {
            return -1;
        }
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(a,mid,n,m))
            {   ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
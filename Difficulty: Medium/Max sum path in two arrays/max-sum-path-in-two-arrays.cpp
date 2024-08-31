//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int sum1=0;
        int sum2=0;
        int n1=arr1.size();
        int n2=arr2.size();
        int i=n1-1;
        int j=n2-1;
        while(i>=0 && j>=0)
        {
            if(arr1[i]>arr2[j])
            {
                sum1+=arr1[i];
                i--;
            }
            if(arr1[i]<arr2[j])
            {
                sum2+=arr2[j];
                j--;
            }
            if(arr1[i]==arr2[j])
            {
                if(sum1>sum2)
                {
                    sum1+=arr1[i];
                    sum2=sum1;
                }
                else
                {
                    sum2+=arr2[j];
                    sum1=sum2;
                }
                i--;
                j--;
            }
            
        }
        while(i>=0)
        {
            sum1+=arr1[i];
            i--;
        }
        while(j>=0)
        {
            sum2+=arr2[j];
            j--;
        }
        return max(sum1,sum2);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        vector<int>ans;
        int i=0;
        int j=0;
        int n=a.size();
        int m=b.size();
        while(i<n && j<m)
        {
            if(a[i]<b[j])
            {
                if(ans.empty())
                {
                    ans.push_back(a[i]);
                }
                else if(ans.back()<a[i])
                {
                  ans.push_back(a[i]);  
                }
                i++;
            }
            else  if(a[i]>b[j])
            {
                if(ans.empty())
                {
                    ans.push_back(b[j]);
                }
                else if(ans.back()<b[j])
                {
                  ans.push_back(b[j]);  
                }
                j++;
            }
            else
            {
                 if(ans.empty())
                {
                    ans.push_back(b[j]);
                }
                else if(ans.back()<b[j])
                {
                  ans.push_back(b[j]);  
                }
                j++;
                i++;
            }
        }
        while(i<n)
        {
            if(ans.back()<a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
         while(j<m)
        {
            if(ans.back()<b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
        return (int)ans.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> a;
        vector<int> b;

        string input;
        // For a
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // For b
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.findUnion(a, b) << endl;
        cout << '~' << endl;
    }

    return 0;
}
// } Driver Code Ends
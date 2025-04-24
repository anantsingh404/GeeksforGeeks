//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int count=1;
        int maj=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]!=maj)
            {
                --count;
                if(count==0)
                {
                    maj=arr[i];
                    count=1;
                }
            }
            else
            {++count;}
        }
        int c=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==maj)
            {
                ++c;
            }
        }
        if(c>(arr.size()/2))
        {
            return maj;
        }
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
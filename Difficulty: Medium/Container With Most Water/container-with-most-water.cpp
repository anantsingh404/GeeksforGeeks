//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &A) {
        // code here
         int lef=0;
         int len=A.size();
    int rite=len-1;
   long long final=0;
    long long watt=0;
    while(lef<rite){
        watt=min(A[lef],A[rite])*(rite-lef);
        final=max(final,watt);
        A[lef]<A[rite]?lef++:rite--;
        }
        return final;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
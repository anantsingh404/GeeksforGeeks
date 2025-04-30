//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        if(n==1)
        {
            return {1};
        }
         if(n==2)
        {
            return {1,1};
        }
        queue<int>q;
        q.push(1);
        q.push(2);
        q.push(1);
        int sum=3;
        while(!q.empty())
        {
           if(sum==n)
           {
               break;
           }
           int m=q.size();
           int back=0;
           int x=0;
           for(int i=0;i<m;i++)
           {
               int x=q.front();
               q.pop();
              
               
                   q.push(x+back);
                   back=x;
                   
               
               
           }
           q.push(back);
           ++sum;
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
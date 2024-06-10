//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &aa, vector<int> &bb) {
        // code here
          vector<pair<int, int>> diff;

    for (int i = 0; i < n; i++)
    {
        diff.push_back({abs(aa[i] - bb[i]), i});
    }

    sort(diff.rbegin(), diff.rend());

   
        long long ans=0;
       
       
        int a=0;
        int b=0;
        for(auto itr:diff)
        { int i=itr.second;
            if(a>=x)
        {
           ans+=bb[i];
                ++b; 
        }
         else if(b>=y)
        {
           ans+=aa[i];
            
                ++a;
              
        }
            
           else if(aa[i]>bb[i])
            {
               ans+=aa[i];
             
               ++a;
            }
            else if(bb[i]>=aa[i])
            {
                ans+=bb[i];
                ++b;
            }
           
        
        }
       
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends
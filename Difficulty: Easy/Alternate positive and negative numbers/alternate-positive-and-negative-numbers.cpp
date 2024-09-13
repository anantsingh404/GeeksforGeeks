//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
     
      int m=arr.size();
       vector<int>pos,neg;
       for(int i=0;i<m;i++)
       {
           if(arr[i]>=0)
           {
               pos.push_back(arr[i]);
           }
           else
           {
              neg.push_back(arr[i]); 
           }
           
       }
       int p=0;
       int n=0;
       int i=0;
       while(i<m)
       {
           if(i%2==0)
           {
               if(p<pos.size())
               {
                   arr[i]=pos[p];
                   p++;
               }
               else
               {
                   arr[i]=neg[n];
                   ++n;
               }
           }
           else
           {
               if(n<neg.size())
               {
                   arr[i]=neg[n];
                   n++;
               }
               else
               {
                   arr[i]=pos[p];
                   ++p;
               }
           }
           i++;
       }
       
       
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
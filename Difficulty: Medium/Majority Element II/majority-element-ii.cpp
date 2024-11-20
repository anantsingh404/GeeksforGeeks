//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
            int n=nums.size();
       int count1=0;
       int maj1=INT_MAX;
       int count2=0;
       int maj2=INT_MAX;
       //int n=nums.size();
       for(int i=0;i<n;i++)
       {
           if(nums[i]==maj1)
           {
               ++count1;
           }
           else if(nums[i]==maj2)
           {
               ++count2;
           }
           else if(count1==0)
           {
            maj1=nums[i];
            ++count1;
           }
           else if(count2==0)
           {
               maj2=nums[i];
               ++count2;
           }
           else 
           {
               --count1;
               --count2;
           }
       }
       int c1=0;
       int c2=0;
       for(int i=0;i<n;i++)
       {
           if(maj1==nums[i])
           {
               ++c1;
           }
           else if(maj2==nums[i])
           {
               ++c2;
           }
           else
           {
               continue;
           }
       }
       vector<int>ans;
       if(c1>n/3)
       {
           ans.push_back(maj1);
       }
       if(c2>n/3)
       {
           ans.push_back(maj2);
       }
       sort(ans.begin(),ans.end());
       if(ans.empty())
       {
           return {};
       }
       return ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
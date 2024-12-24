//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findSubString(string& str) {
        // Your code goes here
          unordered_map<char,int>mp;
        for(auto &it:str){
            mp[it]++;
        }
        int total=mp.size();
        mp.clear(); 
        int i=0,j=0,minlen=INT_MAX;
        int n=str.size();
        while(j<n){
            mp[str[j]]++;
            while(mp.size()==total){
                minlen=min(minlen,j-i+1);
               mp[str[i]]--;
               if(mp[str[i]]==0)mp.erase(str[i]);
                i++;
            }
            
            j++;
        }   
        return minlen;
    }
};

//{ Driver Code Starts.
//   Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
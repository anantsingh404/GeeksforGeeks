class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        int maxi=arr[0][1];
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++)
        {if(arr[i][0]<maxi)
        {
            return false;
        }
        maxi=max(maxi,arr[i][1]);
        }
        return true;
    }
};
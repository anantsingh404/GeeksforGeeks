class Solution {
  public:
    vector<int> smallestDiff(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        // code here.
        vector<int>ans;int n=arr1.size();
        int i=0,j=0,k=0;
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        sort(arr3.begin(),arr3.end());
        int mindiff=INT_MAX;
        while(i<n and j<n and k<n){
            int mini=min({arr1[i],arr2[j],arr3[k]});
            int maxx=max({arr1[i],arr2[j],arr3[k]});
            int diff=maxx-mini;
            if(diff<mindiff){
                mindiff=diff;
                ans={arr1[i],arr2[j],arr3[k]};
            }
            if(mini==arr1[i]){
                i++;
            }
            else if(mini==arr2[j]){
                j++;
            }
            else{
                k++;
            }
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
     
    }
};
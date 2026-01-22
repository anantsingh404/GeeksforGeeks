class Solution {
  public:
  vector<int>getpse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>getnse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        
        return ans;
    }
    int sumofminimum(vector<int>&arr){
        int n=arr.size();
        vector<int>nse=getnse(arr);
        vector<int>pse=getpse(arr);
        int sum=0;
        for(int i=0;i<n;i++){
            int right=i-pse[i];
            int left=nse[i]-i;
            sum+=(left*right*arr[i]);
        }
        return sum;
    }
    vector<int>getnge(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>getpge(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
     int sumofmaximum(vector<int>&arr){
        int n=arr.size();
        vector<int>nge=getnge(arr);
        vector<int>pge=getpge(arr);
        int sum=0;
        for(int i=0;i<n;i++){
            int left=i-pge[i];
            int right=nge[i]-i;
            sum+=(left*right*arr[i]);
        }
        return sum;
    }
    int subarrayRanges(vector<int>& arr) {
        // code here
         return sumofmaximum(arr)-sumofminimum(arr);
        
    }
};
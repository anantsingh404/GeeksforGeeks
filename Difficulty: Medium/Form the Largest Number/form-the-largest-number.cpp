class Solution {
  public:
 static bool cmp(string a,string b)
	{
	    return a+b>b+a;
	}
    string findLargest(vector<int> &a) {
        // code here
        int n=a.size();
        vector<string>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back(to_string(a[i]));
        }
        
        sort(arr.begin(),arr.end(),cmp);
        string ans="";
        for(int i=n-1;i>=0;i--)
        {   
            ans=arr[i]+ans;
        }
        string res="";
        int i=0;
        while(i<ans.size()-1 && ans[i]=='0')
        {
            i++;
        }
        res=ans.substr(i,ans.size()-i);
        return res;
        
    }
};
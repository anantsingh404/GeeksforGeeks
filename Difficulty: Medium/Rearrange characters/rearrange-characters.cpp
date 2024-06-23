//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    struct cmp {
    bool operator()(const std::pair<char, int>& a, const std::pair<char, int>& b) const {
        // Define your comparison logic here
        if(a.second==b.second)
        {
            return a.first<b.first;
        }
        return a.second > b.second; // for example, to prioritize by the second element of the pair
    }
};
    string rearrangeString(string str)
    {
        //code here
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        int n=str.size();
        for(int i=0;i<str.size();i++)
        {
            mp[str[i]]++;
            
        }
        for(auto itr:mp)
        {
            pq.push({itr.second,itr.first});
        }
        string ans;
        while(pq.size()>1)
        {
            pair<int,char>p1=pq.top();
            pq.pop();
            pair<int,char>p2=pq.top();
            pq.pop();
           // cout<<p1.second<<endl;
           // cout<<p2.second<<endl;
            ans.push_back(p1.second);
            ans.push_back(p2.second);
            if(p1.first-1>0)
            {
                pq.push({p1.first-1,p1.second});
            }
            if(p2.first-1>0)
            {
                pq.push({p2.first-1,p2.second});
            }
        }
        if(!pq.empty())
        {   if(pq.top().first>1)
        {
            return "-1";
        }
            if(ans.back()==pq.top().second)
            {
                return "-1";
            }
            else
            {
                ans.push_back(pq.top().second);
                return ans;
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends
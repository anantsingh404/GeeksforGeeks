//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string s, int n)
    {
        // your code here
        int v=0,c=0;
        if(n==1) return s;
        vector<int> vec1(26,0),vec2(26,0);
        for(int i=0;i<n;i++){
            if(s[i]=='a') vec1[s[i]-'a']++;
            else if(s[i]=='e') vec1[s[i]-'a']++;
            else if(s[i]=='i') vec1[s[i]-'a']++;
            else if(s[i]=='o') vec1[s[i]-'a']++;
            else if(s[i]=='u') vec1[s[i]-'a']++;
            else{
                 vec2[s[i]-'a']++;
                 c++;
            }
        }
        v=n-c;
        if(abs(v-c)>1) return "-1";
        int idx=0,cnt;
        if(c>v){
            for(int i=0;i<26;i++){
            cnt=vec2[i];
            while(cnt--){
                s[idx]=i+'a';
                idx+=2;
            }
        }
        idx=1;
        for(int i=0;i<26;i++){
            cnt=vec1[i];
            while(cnt--){
                s[idx]=i+'a';
                idx+=2;
                if(idx>=n) i=26;
            }
          }  
        }
        else{
            for(int i=0;i<26;i++){
            cnt=vec1[i];
            while(cnt--){
                s[idx]=i+'a';
                idx+=2;
                if(idx>=n) i=26;
            }
        }
        idx=1;
        for(int i=0;i<26;i++){
            cnt=vec2[i];
            while(cnt--){
                s[idx]=i+'a';
                idx+=2;
            }
          }
        }
        if(c==v && s[0]-s[1]>0){
            for(int i=0;i<n;i+=2){
                char tmp=s[i];
                s[i]=s[i+1];
                s[i+1]=tmp;
            }
        }
       return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
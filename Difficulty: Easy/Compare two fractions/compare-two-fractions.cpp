//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        int i=0;
        int a=0;
        int x=0;
        int y=0;
        while(str[i]!='/')
        {
            a=a*10+(str[i]-'0');
            i++;
        }
        i++;
        int b=0;
        while(str[i]!=',')
        {
            b=b*10+(str[i]-'0');
            i++;
        }
        x=i;
        i++;
        i++;
        y=i;
        int c=0;
        while(str[i]!='/')
        {
            c=c*10+(str[i]-'0');
            i++;
        }
        i++;
        int d=0;
        while(i<str.size())
        {
            d=d*10+(str[i]-'0');
            i++;
        }
        
        double flag1=(double)a/b;
        double flag2=(double)c/d;
        if(flag1>flag2)
        {
          return str.substr(0,x) ; 
        }
        if(flag1<flag2)
        {
            return str.substr(y,str.size()-y);
        }
        return "equal";
    }
    
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends
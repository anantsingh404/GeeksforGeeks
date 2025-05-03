//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/
 vector<int>prime;
        int s=1e6;
        bool x=true;
       
class Solution {
  public:
    Node *primeList(Node *head) {
        // code here
       if(x)
       {
          vector<int>p(s,0);
        for(int i=2;i<s;i++)
        {
            if(p[i]==0)
            {
                prime.push_back(i);
                for(long long x=1ll*i*i;x<s;x+=i)
                {
                    p[x]=1;
                }
            }
        }
        x=false;
       }
        Node * res=head;
        while(res)
        {
            int x=res->val;
            int ans=0;
            int ans1=-1e2;
            int it=lower_bound(prime.begin(),prime.end(),x)-prime.begin();
            if(it!=prime.size())
            {
               ans=prime[it]; 
            }
            if(it>0)
            {
                ans1=prime[--it];
            }
            if(x-ans1<=ans-x)
            {
                res->val=ans1;
            }
            else
            {
                res->val=ans;
            }
            res=res->next;
            
        }
        return head;
        
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
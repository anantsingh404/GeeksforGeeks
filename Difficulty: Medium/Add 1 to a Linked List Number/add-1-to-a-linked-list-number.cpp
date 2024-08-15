//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node * reverse(Node * head)
    {
        Node * prev=NULL;
        Node * cur=head;
        while(cur)
        {
            Node* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node * temp=reverse(head);
        Node * flag=temp;
        int carry=1;
        Node * prev=NULL;
        while(flag)
        {
            if(flag->data>=9)
            {  int x=flag->data+carry;
                flag->data=(x)%10;
                carry=x/10;
                prev=flag;
                flag=flag->next;
                
            }
            else
            {
               int x=flag->data+carry;
               carry=x/10;
               flag->data=x;
               prev=flag;
               flag=flag->next;
            }
        }
        if(carry>=1)
        {
            Node * x=new Node(carry);
            prev->next=x;
        }
        Node * temp1=reverse(temp);
        return temp1;
        
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
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
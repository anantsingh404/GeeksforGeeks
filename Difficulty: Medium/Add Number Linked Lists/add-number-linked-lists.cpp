//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
         Node* prev1 = NULL;
    Node* next = NULL;
    while (num1) {
        next = num1->next;
        num1->next = prev1;
        prev1 = num1;
        num1 = next;
    }

    // Reverse the second linked list
    Node* prev2 = NULL;
    while (num2) {
        next = num2->next;
        num2->next = prev2;
        prev2 = num2;
        num2 = next;
    }

    // Add the two reversed linked lists
    int carry = 0;
    Node* head = NULL;
    Node* p = NULL;
    while (prev1 || prev2 || carry) {
        int sum = carry;
        if (prev1) {
            sum += prev1->data;
            prev1 = prev1->next;
        }
        if (prev2) {
            sum += prev2->data;
            prev2 = prev2->next;
        }

        Node* nn = new Node(sum % 10);
        if (!head) {
            head = nn;
            p = nn;
        } else {
            p->next = nn;
            p = nn;
        }
        carry = sum / 10;
    }

    // Reverse the result linked list to get the correct order
    Node* result = NULL;
    while (head) {
        next = head->next;
        head->next = result;
        result = head;
        head = next;
    }
    while(result->data==0 && result->next)
    {
      result=result->next;  
    }

    return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
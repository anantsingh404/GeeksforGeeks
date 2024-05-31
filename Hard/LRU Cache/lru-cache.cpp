//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
  struct dll {
        int key;
        int val;
        dll* prev;
        dll* next;
        dll(int x, int y) : key(x), val(y), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    int cnt;
    dll* head;
    dll* tail;
    std::unordered_map<int, dll*> mp;

    void addToFront(dll* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(dll* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int cap) : capacity(cap), cnt(0) {
        head = new dll(-1, -1);
        tail = new dll(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int GET(int key) {
        if (mp.find(key) != mp.end()) {
            dll* node = mp[key];
            int value = node->val;
            removeNode(node);
            addToFront(node);
            return value;
        }
        return -1;
    }

    void SET(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key already exists, update the value, move to front.
            dll* node = mp[key];
            node->val = value;
            removeNode(node);
            addToFront(node);
        } else {
            // Key doesn't exist.
            if (cnt == capacity) {
                // Cache is full, remove the LRU node (tail).
                mp.erase(tail->prev->key);
                removeNode(tail->prev);
                cnt--;
            }
            // Add the new node to the front.
            dll* newNode = new dll(key, value);
            addToFront(newNode);
            mp[key] = newNode;
            cnt++;
        }
    }
    
           
    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  public:
  int s=0;
  deque<int>q;
  unordered_map<int,int>mp;
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        s=cap;
        
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(mp[key]<1)
        {
            return -1;
        }
        else{
            vector<int>vp;
            while(q.back()!=key)
            {
                vp.push_back(q.back());
                q.pop_back();
            }
            q.pop_back();
            reverse(vp.begin(),vp.end());
            for(int i=0;i<vp.size();i++)
            {
                q.push_back(vp[i]);
            }
            q.push_back(key);
        return mp[key];
        }
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(mp[key])
        {
           vector<int>vp;
            while(q.back()!=key)
            {
                vp.push_back(q.back());
                q.pop_back();
            }
            q.pop_back();
            reverse(vp.begin(),vp.end());
            for(int i=0;i<vp.size();i++)
            {
                q.push_back(vp[i]);
            }
            q.push_back(key); 
            mp[key]=value;
        }
        else if(s==q.size())
        {   int x=q.front();
            q.pop_front();
            mp.erase(x);
            q.push_back(key);
            mp[key]=value;
            
            
        }
        else
        {
           q.push_back(key);
            mp[key]=value; 
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
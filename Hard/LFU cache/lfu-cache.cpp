//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class LFUCache {
public:
int cap,minfreq=0,cursize=0;
unordered_map<int,list<int>>freqlist;
unordered_map<int,list<int>::iterator>keynode;
unordered_map<int,pair<int,int>>frequency;
    LFUCache(int capacity) {
       cap=capacity;
        minfreq=0;
        cursize=0;  
    }
    
    int get(int key) {
         if(keynode.find(key)==keynode.end())
        {
            return -1;
        }
        int keyfreq=frequency[key].first;
        freqlist[keyfreq].erase(keynode[key]);
        frequency[key].first++;
        freqlist[frequency[key].first].push_front(key);
        keynode[key]=freqlist[frequency[key].first].begin();
        if(freqlist[minfreq].size()==0)
        {
            minfreq++;
        }
        return frequency[key].second;
    }
    
    void put(int key, int value) {
        if(cap<=0)
        {
            return;
        }
        if(keynode.find(key)!=keynode.end())
        {
            frequency[key].second=value;
            get(key);
            return;
        }
        if(cursize==cap)
        {
            int minfreqback=freqlist[minfreq].back();
            keynode.erase(minfreqback);
            frequency.erase(key);
            freqlist[minfreq].pop_back();
            cursize--;
        }
        cursize++;
        minfreq=1;
        freqlist[minfreq].push_front(key);
        keynode[key]=freqlist[minfreq].begin();
        frequency[key].first=1,frequency[key].second=value;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


//{ Driver Code Starts.

int main(){
    int t = 1;
    cin >> t;

    while(t--){
        int capacity; cin >> capacity;
        LFUCache* obj = new LFUCache(capacity);

        int runs; cin >> runs;
        for(int i = 0;i<runs;i++){
            int s; cin >> s;
            if(s==1){
                int key; cin >> key;
                int param_1 = obj->get(key);
                cout << param_1 << endl;
            }else{
                int key,value;
                cin >> key >> value;
                obj->put(key,value);
            }
            
            
            
        }
        


    }
}

// } Driver Code Ends
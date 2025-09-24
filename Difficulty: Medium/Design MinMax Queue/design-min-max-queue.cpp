class SpecialQueue {

  public:
    queue<int>q;
    priority_queue<int>pqmax;
    priority_queue<int,vector<int>,greater<int>>pqmin;
    unordered_map<int,int>mp;
    
    void enqueue(int x) {
        // Insert element into the queue
        mp[x]++;
        q.push(x);
        pqmin.push(x);
        pqmax.push(x);
    }

    void dequeue() {
        // Remove element from the queue
        int x=q.front();
         --mp[x];
        q.pop();
       
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        while(!pqmin.empty() && mp[pqmin.top()]==0)
        {
            pqmin.pop();
        }return pqmin.top();
    }

    int getMax() {
        // Get maximum element
         while(!pqmax.empty() && mp[pqmax.top()]==0)
        {
            pqmax.pop();
        }return pqmax.top();
    }
};
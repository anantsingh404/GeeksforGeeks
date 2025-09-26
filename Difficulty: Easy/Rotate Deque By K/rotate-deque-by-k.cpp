class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        if(type==1)
        {
            int n=k;
            while(n--)
            {
                int x=dq.back();
                dq.pop_back();
                dq.push_front(x);
            }
        } 
        if(type==2)
        {
            int n=k;
            while(n--)
            {
                int x=dq.front();
                dq.pop_front();
                dq.push_back(x);
            }
        }
    }
};
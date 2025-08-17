int p;
class Solution {
  public:
  
  static bool cmp(int a,int b)
  {   
      return abs(a-p)<abs(b-p);
      
  }
    void rearrange(vector<int> &arr, int x) {
        // code here
        p=x;
        stable_sort(arr.begin(),arr.end(),cmp);
        
        
    }
};
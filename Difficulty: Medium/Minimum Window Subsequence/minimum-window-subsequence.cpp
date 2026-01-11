class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
              int n=s1.size(), m=s2.size();
      string ans="";
      int minL = INT_MAX;
      
      for(int i=0; i<n; i++){
        if(s1[i] == s2[0]){
          int j=i, k=0;
          
          while(j<n && k<m){
            if(s1[j] == s2[k]) k++;
            if(k==m)
              break;
            j++;  
          }
          
          //found
          if(k==m){
            int ji=j;
            k--;
            while(ji>=i && k>=0){
              if(s1[ji] == s2[k]) k--;
              if(k<0)
                break;
              ji--;    
            }
            
            int curL = j-ji+1;
            if(minL > curL){
              minL = curL;
              ans = s1.substr(ji, curL);
            }
            
          }
          
          
        }      
      }
      
      return ans;
    }
};

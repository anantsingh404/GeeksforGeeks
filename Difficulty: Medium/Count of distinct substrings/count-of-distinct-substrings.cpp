class trie {
public:
    trie* temp[26];
    
    
    trie() {
        for (int i = 0; i < 26; i++) {
            temp[i] = NULL;
        }
        
    }
};
class Solution {
  public:
    int countSubs(string& s) 
    {
        trie * root=new trie();
        int ans=0;
        for(int i=0;i<s.size();i++)
        {  
            trie * flag=root;
            for(int j=i;j<s.size();j++)
            {
                if(flag->temp[s[j]-'a']==NULL)
                {
                    flag->temp[s[j]-'a']=new trie();
                    ++ans;
                }
                flag=flag->temp[s[j]-'a'];
            }
        }
        return ans;
    }
};
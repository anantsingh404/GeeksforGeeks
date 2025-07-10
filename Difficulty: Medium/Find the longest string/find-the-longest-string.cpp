const int maxi = 26;

class trie
{
public:
    vector<trie *> child;
    int exist;

    trie() : child(maxi, nullptr), exist(0) { }
};
trie * root;

class Solution {
  public:
    void insert(string &word)
    {
      trie * flag=root;
      for(int i=0;i<word.size();i++)
      {
          int x=word[i]-'a';
          if(flag->child[x]==NULL)
          {
              trie * temp=new trie();
              flag->child[x]=temp;
              flag=flag->child[x];
              
          }
          else
          {
              flag=flag->child[x];
          }
      }
      flag->exist=1;
    }
    bool check(string &word)
    {
      trie *flag=root;
      for(int i=0;i<word.size();i++)
      {
          int x=word[i]-'a';
          if(flag->child[x]==NULL)
          {
            return false;  
          }
          
          else
          {
              flag=flag->child[x];
              if(flag->exist<1)
              {
                  return false;
              }
          }
         
      }
      return true;
    }
    string longestString(vector<string> &words) {
        // code here
        sort(words.begin(),words.end());
        root=new trie();
        for(int i=0;i<words.size();i++)
        {
            insert(words[i]);
        }
        string ans="";
        int maxii=0;
        for(int i=0;i<words.size();i++)
        {
          
          
         
             
              if(check(words[i])==false)
              {
                  continue;
              }
        
          
          if(words[i].size()>maxii)
          {
              ans=words[i];
              maxii=words[i].size();
          }
          
        }
        return ans;
        
        
    }
};
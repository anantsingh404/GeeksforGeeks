class dll{
    public:
    int data;
    dll * left;
    dll * right;
    dll(int x)
    {
        left=NULL;
        right=NULL;
        data=x;
    }
};
class LRUCache {
  public:
       int cap;
    unordered_map<int,dll *>mp;
    unordered_map<int,int>mp1;
    dll * end=NULL;
    dll * first=NULL;

    LRUCache(int ca) {
        cap = ca;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            dll * temp = mp[key];
            dll * x = new dll(key);

            // unlink temp
            if(temp == first) {
                first = temp->right;
            }
            if(temp == end) {
                end = temp->left;
            }
            if(temp->left) {
                temp->left->right = temp->right;
            }
            if(temp->right) {
                temp->right->left = temp->left;
            }

            delete temp; // IMPORTANT

            // insert x at end
            if(end)
            {
                end->right = x;
                x->left = end;
                end = x;
            }
            else
            {
                end = x;
                first = x;
            }

            mp[key] = end;     // update map
            return mp1[key];
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value) {

        if(mp.find(key)!=mp.end())
        {
            dll * temp = mp[key];
            dll * x = new dll(key);

            // unlink temp
            if(temp == first) {
                first = temp->right;
            }
            if(temp == end) {
                end = temp->left;
            }
            if(temp->left) {
                temp->left->right = temp->right;
            }
            if(temp->right) {
                temp->right->left = temp->left;
            }

            delete temp;

            // add new node at end
            if(end)
            {
                end->right = x;
                x->left = end;
                end = x;
            }
            else
            {
                end = x;
                first = x;
            }

            mp[key] = end;
            mp1[key] = value;
        }
        else
        {
            // if full → remove LRU (first)
            if(cap == 0)
            {
                dll * x = first;

                mp.erase(x->data);

                first = x->right;
                if(first) first->left = NULL;
                else end = NULL;    // list empty now

                delete x;
                cap++;
            }

            // insert new node
            dll * x = new dll(key);

            if(end)
            {
                end->right = x;
                x->left = end;
                end = x;
            }
            else
            {
                first = x;
                end = x;
            }

            mp[key] = end;
            mp1[key] = value;

            cap--;
        }
    }

};
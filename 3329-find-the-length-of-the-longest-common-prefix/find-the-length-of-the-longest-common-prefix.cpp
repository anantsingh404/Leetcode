class trienode{
    public:
    trienode * child[10];
    trienode()
    {
        for(auto &a :child)
        {
            a=nullptr;
        }
    }
};
class Solution {
    int ans=0;
    trienode* root;
public:
Solution() {
        root = new trienode();
    }
     void insert(string s) {
        trienode *p = root;
        for (auto &a : s) {
            int i = a - '0';
            if (!p->child[i])
            { p->child[i] = new trienode();
           
            }
             p = p->child[i];
        }
    }
bool search(string key,int count)
    {
        trienode *p=root;
        for(auto &a: key)
        {
          int i=a-'0';
          if(!p->child[i])
          {
            return false;
          }
          else
          {
            ++count;
            ans=max(ans,count);
            p=p->child[i];
          }


        }
        return true;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        for(int i=0;i<n;i++)
        {
            string x=to_string(arr1[i]);
            insert(x);

        }
        for(int i=0;i<m;i++)
        {   string x=to_string(arr2[i]);
            search(x,0);
        }
        return ans;
    }
};
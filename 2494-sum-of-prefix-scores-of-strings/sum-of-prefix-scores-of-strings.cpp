struct  t{
    struct t *arr[26];
    int count;
    bool leaf;
    t() {
        for (int i = 0; i < 26; i++) {
            arr[i] = NULL;
        }
        leaf = false;
        count=0;
    }
};


class Solution {
    private:
    t *x;
public:
   Solution(){
    x=new t();
   }
   void insert(string &word)
   {
     int curr = 0; 
     //int count=0;
        t* node = x; 
        for (int i = 0; i < word.length(); i++) {
            curr = word[i] - 'a';
            if(node->arr[curr] == NULL) node->arr[curr] = new t();
            node = node->arr[curr];
            node->count++;
        }
        node->leaf = true; 
   }
   int search(string word) {
        int curr = 0; 
        int sum=0;
        t* node = x; 
        for (int i = 0; i < word.length(); i++) {
            curr = word[i] - 'a'; 
            if(node->arr[curr] == NULL)
            {
                break;
            } 

            node = node->arr[curr];
            sum+=node->count;
        }
        return sum;  
    }
    vector<int> sumPrefixScores(vector<string>& words) {
      for(int i=0;i<words.size();i++)
      {
        insert(words[i]);
      }
      vector<int>ans;
      for(int i=0;i<words.size();i++)
      {
        int x=search(words[i]);
        ans.push_back(x);
      }
      return ans;
    }
};
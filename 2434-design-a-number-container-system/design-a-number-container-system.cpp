class NumberContainers {
public:
unordered_map<int,set<int>>mp;
unordered_map<int,int>idx;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idx[index]<1)
        {
            idx[index]=number;
            mp[number].insert(index);
            
        }
        else if(idx[index]>0)
        {
            if(idx[index]==number)
            {
                return;
            }
            else
            {
               int x=idx[index];
               mp[x].erase(index);
               if(mp[x].empty())
               {
                mp.erase(x);
               }
                idx[index]=number;
            mp[number].insert(index);
            return ;

            }
        }
    }
    
    int find(int number) {
      if(mp.find(number)!=mp.end())
      {
        return *mp[number].begin();
      } 
      return -1; 
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
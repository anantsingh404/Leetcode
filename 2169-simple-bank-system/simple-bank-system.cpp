class Bank {
public:
vector<long long>af;
    Bank(vector<long long>& balance) {
      af=balance;  
    }
    
    bool transfer(int a1, int a2, long long m) {
       if(a1>=1 && a1<=af.size() && a2>=1 && a2<=af.size() && m>=0 && m<=af[a1-1])
       {
          af[a1-1]-=m;
          af[a2-1]+=m;
          return true;
       }
       else
       {
        return false;
       } 
    }
    
    bool deposit(int a, long long m) {
        if(a>=1 && a<=af.size() && m>=0)
        {
            af[a-1]+=m;
           return true;
        }
       
            return false;
        
    }
    
    bool withdraw(int a, long long m) {
       if(a>=1 && a<=af.size() && m<=af[a-1])
       {
        af[a-1]-=m;
        return true;
       } 
       else{
        return false;
       }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
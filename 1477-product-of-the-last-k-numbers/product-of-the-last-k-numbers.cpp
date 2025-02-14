class ProductOfNumbers {
public:
stack<int>st;
long long prod=0;
unordered_map<long long ,long long>mp;
int zi=0;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        st.push(num);
        if(num==0)
        {
            prod=0;
            zi=st.size();
            mp.clear();
        }
        else
        {   if(prod==0){
            prod=1;
        }
            prod=prod*num;
            mp[st.size()]=prod;
        }

    }
    
    int getProduct(int k) {
       if(zi>0 && zi>st.size()-k)
       {
        return 0;
       }
       if(mp[st.size()-k]>0)
       {
  return prod/mp[st.size()-k];
       }
       return prod;
     

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
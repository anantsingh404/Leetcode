class CustomStack {
public:
vector<int>temp;
int flag;
int dpp;
    CustomStack(int maxSize) {
        flag=maxSize;
        dpp=maxSize;
    }
    
    void push(int x) {
        if(flag>0)
        {
            temp.push_back(x);
            --flag;
        }

    }
    
    int pop() {
        if(!temp.empty())
        {   int x=temp.back();
        ++flag;
            temp.pop_back();
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int n=temp.size();
       for(int i=0;i<min(dpp-flag,k);i++)
       {
        temp[i]+=val;
       } 
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
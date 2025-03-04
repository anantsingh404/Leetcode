class Solution {
public:
    bool checkPowersOfThree(int n) {
        set<int>st;
       while(n)
       {
        int x=0;
        while(n>=
        pow(3,x))
        {
            ++x;
        }
        --x;
        if(x>=0 && st.find(x)==st.end())
        {
            n-=pow(3,x);
            st.insert(x);
        }
        else
        {
            return false;
        }
       }
       return true; 
    }
};
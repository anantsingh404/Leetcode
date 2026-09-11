class Solution {
public:
    int totalNumbers(vector<int>&d) {
     
    int n =d.size();
    set<int>st;
    for (int i =0;i < n;i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            for (int k = 0; k < n; k++) 
            {
                if (i!=j && j!=k && i!= k) 
                {
                    int flag =d[i]*100+d[j]*10+d[k];
                    if (d[i] != 0 &&d[k] % 2 == 0) 
                    {
                       st.insert(flag);
                    }
                }
            }
        }
    }
    int m=st.size();
    return m;
        
    }
};
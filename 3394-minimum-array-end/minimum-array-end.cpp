typedef long long ll;
class Solution {
public:
    long long minEnd(int nn, int xx) {
      ll ans = 0, bit;
        --nn; 
        
        vector<int> a(64, 0);
        vector<int> b(64, 0);
        
        ll x = xx; 
        ll n = nn;
        
        for(int i=0; i<64; ++i)
        {
            bit = (x>>i)&1;
            a[i] = bit;
            
            bit = (n>>i)&1;
            b[i] = bit;
        }
        
        int pa = 0, pb = 0;
        
        while(pa < 63)
        { 
            while(a[pa] != 0 && pa<63)
                ++pa;
            
            a[pa] = b[pb];   
            ++pa; ++pb;    
        }
        
    
        for(int i=0; i<64; ++i) 
            if(a[i] == 1)
                ans+=pow(2, i);
        
        return ans;   
    }
};
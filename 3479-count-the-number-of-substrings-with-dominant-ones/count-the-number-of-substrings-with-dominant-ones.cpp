class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0, len=s.length();
        vector<int> prefix(len, 0);

        for(int i=0 ; i<len ; i++)
            prefix[i] += s[i]=='1' ? (i==0 ? 1 : prefix[i-1]+1) : (i==0 ? 0 : prefix[i-1]);
        
        for(int i=0 ; i<len ; i++) {
            for(int j=i ; j<len ; j++) {
                int ones = prefix[j] - (i==0 ? 0 : prefix[i-1]);
                int zeros = (j-i+1) - ones;

                if(ones >= zeros*zeros)
                {
                    ans++;
                    int k = sqrt(ones);

                    if(k > zeros)
                    ans += (j+(k-zeros) >= len ? (len-j-1) : (k-zeros));

                    j += (k-zeros);
                }
                else
                j += (zeros*zeros - ones - 1);


                if(zeros*zeros>(len-i-zeros))
                {
                    break;
                }
            }

        }

        return ans; 
    }
};
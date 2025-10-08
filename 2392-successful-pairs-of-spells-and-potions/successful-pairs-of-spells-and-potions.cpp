class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long su) {
       sort(p.begin(),p.end());
       for(int i=0;i<s.size();i++)
       {
        long long x=su/s[i];
        if(su%s[i]!=0){
            ++x;
        }
        int idx=lower_bound(p.begin(),p.end(),x)-p.begin();
        //cout<<idx<<endl;
        if(p.size()-idx>0)
        {
            s[i]=p.size()-idx;
        }
        else
        {
            s[i]=0;
        }
       }
       return s;
        
    }
};
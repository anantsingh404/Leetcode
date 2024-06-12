class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
     unordered_map<int,vector<int>> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        int ans = nums.size(),x = 0;
        for(auto &k: mp){
            x = k.second[0];
            int y =nums.size()-k.second.back()-1; 
            x += y;
            x = (x+1)/2;
            for(int i = 0; i < k.second.size()-1; i++){
                x = max(x,(k.second[i+1]-k.second[i])/2);
            }
            ans = min(ans,x);
        }
        return ans;
    }
};
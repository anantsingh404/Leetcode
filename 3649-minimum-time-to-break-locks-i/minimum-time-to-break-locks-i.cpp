class Solution {
public:
int m;
int n;
int res;

int check(vector<int>&comb)
{
  int x=1;
  int i=0;
  int sum=0;
  while(i<n)
  {
    sum+=ceil((double)comb[i]/x);
    x+=m;
    i++;
  } 
  return sum; 
}
void generateCombinations(vector<int>& arr, vector<int>& combination, int n,vector<int>&vis) {
    
    if (combination.size() == n) {
        int x=check(combination);
        
            res=min(res,x);
          //  cout<<res<<endl;
        
       
        return;
    }

    
    for (int i = 0; i < arr.size(); i++) {
        if(vis[i]==0){
            vis[i]=1;
        combination.push_back(arr[i]);
        generateCombinations(arr, combination, n,vis); 
        combination.pop_back();
        vis[i]=0;
        }
    }
}
    int findMinimumTime(vector<int>& strength, int k) {
        m=k;
       n=strength.size();
       res=INT_MAX;
       vector<int>combination;
       vector<int>vis(n,0);
     generateCombinations(strength,combination,n,vis);
     return res;
    }
};
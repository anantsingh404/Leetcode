class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
       for(int i=0;i<n;i++)
       {
        if(i-k>=0)
        {
            energy[i]=max(energy[i-k]+energy[i],energy[i]);
        }
       }
       int maxi=INT_MIN;
       for(int i=n-1;i>=max(0,n-k);i--)
       {
        maxi=max(maxi,energy[i]);
       }return maxi;
    }
};
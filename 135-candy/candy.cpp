class Solution {
public:
    int candy(vector<int>& rating) {
         int n=rating.size();
        int candyy=n;
        int i=1;
        while(i<n)
        {
            if(rating[i]==rating[i-1])
            {
                i++;
                continue;
            }
            int peak=0;
            while(rating[i]>rating[i-1])
            {   ++peak;
                candyy+=peak;
                i++;
                if(i==n)
                {
                    return candyy;
                }
            }
            int valley=0;
            while(i<n && rating[i]<rating[i-1])
            {
                valley++;
                candyy+=valley;
                i++;

            }
            candyy-=min(peak,valley);
        }
        return candyy;
    }
};
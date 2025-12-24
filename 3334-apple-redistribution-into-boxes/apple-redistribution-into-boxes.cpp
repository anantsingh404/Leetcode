class Solution {
public:
    int minimumBoxes(vector<int>& arr, vector<int>& cap) {

long long sum=accumulate(arr.begin(),arr.end(),1ll*0);
sort(cap.begin(),cap.end());int j=cap.size()-1;
while(j>=0 && sum>0)
{
    sum-=cap[j--];
}
return cap.size()-(j+1);

    }
};
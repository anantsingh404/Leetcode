class Solution {
public:
    bool check(string x)
    {
        int sum1=0;
        int sum2=0;
        int i=0;
        int j=x.size()-1;
        while(i<j)
        {
            sum1=sum1+(x[i]-'0');
            sum2=sum2+(x[j]-'0');
            i++;
            j--;
        }
        return sum1==sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++)
        {
            string x=to_string(i);
            if(x.size()%2==0)
            {
                if(check(x))
                {
                    ++count;
                }
            }
        }
        return count;
    }
};
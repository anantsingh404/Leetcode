class Solution {
public:
    int countCollisions(string dir) {
        
    char x = dir[0];
    int n = dir.size();
    int count = 0;
    int countr=0;
    if(x=='R')
    {++countr;}
    for(int i = 1; i < n; i++) {

        if(dir[i] == 'L' && x == 'R')
        {
            count += 2;
            count+=max(0,countr-1);
            countr=0;
            x = 'S';
        }
        else if(dir[i] == 'L' && x == 'S')
        {
            count += 1;
            x = 'S';
        }
        else if(dir[i] == 'S' && x == 'R')
        {
            count += (countr);
            countr=0;
            x = 'S';
        }
        else if(dir[i] == 'R')
        {
           ++countr;
           x=dir[i];
        }
        else
        {
            x = dir[i];
        }
       // cout<<count<<endl;
    }

    return count;
}
};
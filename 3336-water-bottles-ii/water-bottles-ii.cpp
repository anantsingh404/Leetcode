class Solution {
public:
    int maxBottlesDrunk(int nb, int ne) {
          int drinkbottle=0;
        int emptybottle=0;
        while(nb>0)
        {
            drinkbottle+=nb;
            //int flag=nb;
        
            emptybottle=nb+emptybottle;
            nb=0;
            if(emptybottle>=ne)
            {
                nb++;
                emptybottle-=ne;
                ++ne;
            }
        }
        return drinkbottle;
    }
};
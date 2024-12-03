class Solution {
public:
    int lastRemaining(int n) 
    {
        bool left=true;
        int remaining=n,current=1,increment=1;
        while(remaining>1)
        {
            if(left || remaining%2==1)
            {
                current+=increment;
            }
            remaining/=2;
            left=!left;
            increment*=2;
        }
        return current;
    }
};

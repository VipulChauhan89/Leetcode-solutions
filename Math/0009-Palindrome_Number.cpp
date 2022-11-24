class Solution {
public:
    bool isPalindrome(int x) 
    {
        unsigned int num=x,sum=0;
        if(x<0)
        {
            return false;
        }
        while(x!=0)
        {
            sum=sum*10+x%10;
            x/=10;
        }
        return (sum==num)?true:false;
    }
};

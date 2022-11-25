class Solution {
public:
    int tribonacci(int n) 
    {
        if(n<2)
        {
            return n;
        }
        int prev=0,current=1,next=1;
        for(int i=3;i<=n;i++)
        {
            int temp=prev+current+next;
            prev=current;
            current=next;
            next=temp;
        }
        return next;
    }
};

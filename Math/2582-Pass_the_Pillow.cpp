class Solution {
public:
    int passThePillow(int n,int time)
    {
        int num=2*n-2,x=time%num;
        return ((x<n)?x:num-x)+1;
    }
};

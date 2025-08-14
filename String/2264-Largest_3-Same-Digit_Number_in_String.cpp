class Solution {
public:
    string largestGoodInteger(string num)
    {
        int count=0;
        char prev='0',mxD=' ';
        for(auto &i:num)
        {
            if(i==prev)
            {
                count++;
            }
            else 
            {
                count=1;
            }
            if(count==3)
            {
                mxD=max(mxD,i);
            }
            prev=i;
        }
        return ((mxD==' ')?"":string(3,mxD));
    }
};

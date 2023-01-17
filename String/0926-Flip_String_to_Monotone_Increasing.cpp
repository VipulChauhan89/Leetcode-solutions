class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int count_o=0,count_f=0;
        for(auto i:s)
        {
            if(i=='0')
            {
                count_f++;
                count_f=min(count_f,count_o);
            }
            else
            {
                count_o++;
            }
        }
        return count_f;
    }
};

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        vector<double> current(1,poured);
        for(int i=0;i<query_row;i++)
        {
            vector<double> next(i+2,0.0);
            for(int j=0;j<current.size();j++)
            {
                double overflow=(current[j]-1.0)/2.0;
                if(overflow>0.0)
                {
                    next[j]+=overflow;
                    next[j+1]+=overflow;
                }
            }
            current=next;
        }
        return min(1.0,current[query_glass]);
    }
};

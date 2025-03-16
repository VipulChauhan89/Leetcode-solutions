class Solution {
public:
    bool can_repair(vector<int> &ranks,int cars,long long time)
    {
        long long total=0;
        for(auto i:ranks)
        {
            total+=sqrt(time/i);
            if(total>=cars)
            {
                return true;
            }
        }
        return false;
    }
    long long repairCars(vector<int> &ranks,int cars) 
    {
        long long l=1,r=(long long)*min_element(ranks.begin(),ranks.end())*cars*cars;
        while(l<r)
        {
            long long mid=(l+r)/2;
            if(can_repair(ranks,cars,mid))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};

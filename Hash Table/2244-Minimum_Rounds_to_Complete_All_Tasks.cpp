class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        int count=0;
        unordered_map<int,int> m;
        for(auto i:tasks)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            if(i.second==1)
            {
                return -1;
            }
            count+=i.second/3+((i.second%3==0)?0:1);
        }
        return count;
    }
};

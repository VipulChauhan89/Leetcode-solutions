class Solution {
public:
    int numRabbits(vector<int> &answers) 
    {
        int total=0;
        unordered_map<int,int> m;
        for(auto &i:answers)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            total+=ceil((double)i.second/(i.first+1))*(i.first+1);
        }
        return total;
    }
};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        if(n==1 && trust.size()==0)
        {
            return n;
        }
        unordered_map<int,int> m;
        for(auto &i:trust)
        {
            m[i[0]]=-1;
            m[i[1]]++;
        }
        for(auto i:m)
        {
            if(i.second==n-1)
            {
                return i.first;
            }
        }
        return -1;
    }
};

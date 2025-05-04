class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) 
    {
        unordered_map<int,int> m;
        int count=0;
        for(auto &i:dominoes)
        {
            int a=i[0],b=i[1];
            int x=((a>b)?((a*(a-1)/2)+b-1):((b*(b-1)/2)+a-1));
            count+=m[x];
            m[x]++;
        }
        return count; 
    }
};

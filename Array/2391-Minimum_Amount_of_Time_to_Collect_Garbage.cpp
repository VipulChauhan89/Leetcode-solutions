class Solution {
public:
    int garbageCollection(vector<string> &garbage,vector<int> &travel) 
    {
        vector<int> prefixSum(travel.size()+1,0);
        prefixSum[1]=travel[0];
        for(int i=1;i<travel.size();i++)
        {
            prefixSum[i+1]=prefixSum[i]+travel[i];
        }
        unordered_map<char,int> garbageLastPos,garbageCount;
        for(int i=0;i<garbage.size();i++)
        {
            for(auto c:garbage[i])
            {
                garbageLastPos[c]=i;
                garbageCount[c]++;
            }
        }
        vector<char> garbageTypes = {'M','P','G'};
        int ans=0;
        for(char c:garbageTypes)
        {
            if(garbageCount[c])
            {
                ans+=prefixSum[garbageLastPos[c]]+garbageCount[c];
            }
        }
        return ans;
    }
};

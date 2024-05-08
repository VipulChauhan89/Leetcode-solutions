class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &score) 
    {
        vector<int> s=score;
        sort(s.begin(),s.end(),greater<int>());
        vector<string> med={"Gold Medal","Silver Medal","Bronze Medal"},ans;
        unordered_map<int,string> rk;
        for(int i=0;i<s.size();i++)
        {
            if(i<3)
            {
                rk[s[i]]=med[i];
            }
            else
            {
                rk[s[i]]=to_string(i+1);
            }
        }
        for(auto i:score)
        {
            ans.push_back(rk[i]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> wordSubsets(vector<string> &words1,vector<string> &words2) 
    {
        vector<string> ans;
        unordered_map<char,int> m1;
        for(auto &i:words2)
        {
            unordered_map<char,int> m2;
            for(auto &j:i)
            {
                m2[j]++;
                m1[j]=max(m2[j],m1[j]);
            }
        }
        for(auto &i:words1)
        {
            bool nt=true;
            for(auto &j:m1)
            {
                int c=count(i.begin(),i.end(),j.first);
                if(c<j.second)
                {
                    nt=false;
                    break;
                }
            }
            if(nt)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

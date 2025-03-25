class Solution {
public:
    bool checkValidCuts(int n,vector<vector<int>> &rectangles) {
        vector<pair<int,int>> e;
        for(auto &i:rectangles) 
        {
            e.push_back({i[0],1});
            e.push_back({i[2],-1});
        }
        sort(e.begin(),e.end());
        int active=0,sections=0;
        for(auto &i:e) 
        {
            active+=i.second;
            if(active==0)
            {
                sections++;
            } 
        }
        if(sections>=3)
        {
            return true;
        } 
        e.clear();
        for(auto &i:rectangles) 
        {
            e.push_back({i[1],1});
            e.push_back({i[3],-1});
        }
        sort(e.begin(),e.end());
        active=0;
        sections=0;
        for(auto &i:e) 
        {
            active+=i.second;
            if(active==0)
            {
                sections++;
            } 
        }
        return sections>=3;
    }
};

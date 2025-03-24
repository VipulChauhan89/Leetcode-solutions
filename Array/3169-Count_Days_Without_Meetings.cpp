class Solution {
public:
    int countDays(int days,vector<vector<int>> &meetings) 
    {
        vector<vector<int>> merged;
        int count=0;
        sort(meetings.begin(),meetings.end());
        for(auto &i:meetings)
        {
            if(merged.empty() || i[0]>merged.back()[1])
            {
                merged.push_back(i);
            }
            else
            {
                merged.back()[1]=max(merged.back()[1],i[1]);
            }
        }
        for(auto &i:merged)
        {
            count+=(i[1]-i[0]+1);
        }
        return days-count;
    }
};

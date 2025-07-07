class Solution {
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> mnHp;
        int day=0,index=0,n=events.size(),ans=0;
        while(!mnHp.empty() || index<n)
        {
            if(mnHp.empty())
            {
                day=events[index][0];
            }
            while(index<n && events[index][0]<=day)
            {
                mnHp.push(events[index][1]);
                index++;
            }
            mnHp.pop();
            ans++;
            day++;
            while(!mnHp.empty() && mnHp.top()<day)
            {
                mnHp.pop();
            }
        }
        return ans;
    }
};

class Solution {
public:
    int matchPlayersAndTrainers(vector<int> &players,vector<int> &trainers)
    {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int ans=0,j=0,n=trainers.size();
        for(auto &i:players)
        {
            while(j<n && i>trainers[j])
            {
                j++;
            }
            if(j<n)
            {
                j++;
                ans++;
            }
        }
        return ans;
    }
};

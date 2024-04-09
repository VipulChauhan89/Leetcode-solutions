class Solution {
public:
    int timeRequiredToBuy(vector<int> &tickets,int k) 
    {
        int ans=0;
        for(int i=0;i<tickets.size();i++)
        {
            ans+=(i<=k)?min(tickets[i],tickets[k]):min(tickets[i],tickets[k]-1);
        }
        return ans;
    }
};

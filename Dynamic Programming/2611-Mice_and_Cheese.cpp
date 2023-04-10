class Solution {
public:
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        return (a.first-a.second)>(b.first-b.second);
    }
    int miceAndCheese(vector<int> &reward1,vector<int> &reward2,int k) 
    {
        int n=reward1.size();
        vector<pair<int,int>> cheese(n);
        for(int i=0;i<n;i++) 
        {
            cheese[i]=make_pair(reward1[i],reward2[i]);
        }
        sort(cheese.begin(),cheese.end(),comp);
        int total_reward1=0,total_reward2=0;
        for(int i=0;i<k;i++) 
        {
            total_reward1+=cheese[i].first;
        }
        for(int i=k;i<n;i++) 
        {
            total_reward2+=cheese[i].second;
        }
        return total_reward1+total_reward2;
    }
};
